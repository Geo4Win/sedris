// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        FileMngr.cpp
//
// PROGRAMMERS: Gregory Hull
//
// DESCRIPTION: Class implementation for
//
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

// - STF spec. 4.1

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#include "STF_FileMngr.hpp"
#include "STF_XmtlMngr.hpp"

#include <sys/stat.h>
#include <string.h>
#include <errno.h>

using namespace STF_NAMESPACE;


// file access flags for open()
//
#if defined(_WIN32) || defined(WIN32)
const int  WRITE_MODE = O_RDWR | O_CREAT | O_BINARY;
const int  READ_MODE  = O_RDONLY | O_BINARY;
#else
const int  WRITE_MODE = O_RDWR | O_CREAT;
const int  READ_MODE  = O_RDONLY;
#endif

SE_Integer_Unsigned   STF_FileMngr::VFileTblSize=0;
VFile**               STF_FileMngr::VFileTbl=NULL;

SE_Integer_Unsigned   STF_FileMngr::maxOpenFiles=0;
SE_Integer_Unsigned   STF_FileMngr::newestFile=0;
SE_Integer_Unsigned   STF_FileMngr::openVFileTblSize=0;
VFile**               STF_FileMngr::openVFileTbl=NULL;

static STF_FileMngr *theFileMngr=NULL;

STF_FileMngr *
STF_FileMngr::CreateFileMngr(void)
{
    // if the FileMngr hasn't been created then create it.
    //
    if (theFileMngr == NULL)
    {
        theFileMngr = new STF_FileMngr( );
    }
    return theFileMngr;
}

void
STF_FileMngr::DestroyFileMngr(void)
{
    if (theFileMngr != NULL)
    {
        delete theFileMngr;
        theFileMngr = NULL;
    }
}

STF_FileMngr::STF_FileMngr(void)
{
    VFileTblSize=0;
    VFileTbl=NULL;

    newestFile=0;
    openVFileTblSize=0;
    maxOpenFiles = STF_XmtlMngr::GetMaxOpenFiles();

    openVFileTbl = (VFile **)malloc( sizeof(VFile*)*maxOpenFiles );

    for (unsigned int f=0 ; f< maxOpenFiles ; f++)
    {
        openVFileTbl[f] = NULL;
    }
}

STF_FileMngr::~STF_FileMngr()
{
    free( openVFileTbl );

    for (unsigned int i=0 ; i<VFileTblSize ; i++)
    {
        delete VFileTbl[i];
    }
    free( VFileTbl );
}

bool
STF_FileMngr::ChangeFileName( FileID fid, const string &new_fname )
{
    // if the file is open, close it
    //
    bool opened=false;
    VFile *vfile=VFileTbl[fid];

    if (vfile->fd != -1)
    {
        // the openVFileTbl will have an entry for this VFile but since we
        // are going to reopen it we will just leave it alone.
        //
        opened = true;
        close( vfile->fd );
        vfile->fd = -1;
    }

    if (rename( vfile->fileName.c_str(), new_fname.c_str() ) != 0)
    {
        fprintf(stderr, "rename(): Error renaming %s to %s!\n",
                vfile->fileName.c_str(), new_fname.c_str());
        return false;
    }
    vfile->fileName = new_fname;

    //
    // if the file was opened then reopen it and seek back to the
    // original position
    //
    if (opened)
    {
        vfile->fd = open( vfile->fileName.c_str(), vfile->mode, 0666 );

        if (vfile->fd == -1)
        {
            fprintf(stderr, "STF: (re)open error on \"%s\": %s\n",
                   vfile->fileName.c_str(), strerror(errno));
            return false;
        }
        off_t seek_offset = lseek( vfile->fd, vfile->fd_pos, SEEK_SET );

        if (seek_offset != vfile->fd_pos)
        {
            fprintf(stderr, "STF: lseek returned %d seeking offset %d\n",
                                    (int)seek_offset, vfile->fd_pos );
        }
    }
    return true;
}

// loop through all the open files and close them
//
void
STF_FileMngr::CloseFiles(void)
{
    for (unsigned int f=0 ; f< openVFileTblSize ; f++)
    {
        if (openVFileTbl[f]->fd != -1)
        {
            close( openVFileTbl[f]->fd );
            openVFileTbl[f]->fd = -1;
            openVFileTbl[f]->fd_pos = 0;
            openVFileTbl[f] = NULL;
        }
    }
    openVFileTblSize = 0;
}

bool
STF_FileMngr::OpenFile( VFile *vfile )
{
    // if the max number of open files has been reached then close
    // one of the other files.
    //
    int oldestFile = (newestFile+1)%maxOpenFiles;

    if (openVFileTblSize == maxOpenFiles)
    {
        //  close the oldest file
        //  (the oldest file must still be open)
        //
        if (openVFileTbl[oldestFile]->fd != -1)
        {
            close( openVFileTbl[oldestFile]->fd );
            openVFileTbl[oldestFile]->fd = -1;
            openVFileTbl[oldestFile]->fd_pos = 0;
            openVFileTbl[oldestFile] = NULL;
        }
    }
    else
    {
        openVFileTblSize++;
    }

    //  open the file.
    //
    vfile->fd = open( vfile->fileName.c_str(), vfile->mode, 0666 );

    if (vfile->fd == -1)
    {
        fprintf(stderr, "STF: open error on \"%s\": %s\n",
            vfile->fileName.c_str(), strerror(errno));
        return false;
    }
    vfile->fd_pos = 0;

    // add the new opened file to the table
    //
    openVFileTbl[oldestFile] = vfile;
    newestFile = oldestFile;

    return true;
}


SE_Integer
STF_FileMngr::Read( FileID file, SE_Integer_Unsigned size,
                    SE_Integer_Unsigned offset, void *buf )
{
    SE_Integer bytes_read=0;

    if (file >= VFileTblSize)
    {
        // $$$ err msg
        fprintf(stderr, "STF_FileMngr::Read:ID %d is not in the virtual file table.\n", file );
        return bytes_read;
    }
    VFile *vfile=VFileTbl[file];

    if (vfile->fd == -1)
    {
        OpenFile( vfile );
    }

    if (vfile->fd != -1)
    {
        off_t seek_offset = lseek( vfile->fd, offset, SEEK_SET );
        if (seek_offset != offset)
        {
            fprintf(stderr, "STF_FileMngr::Read: lseek returned %d seeking offset %d\n",
                    (int)seek_offset, offset);
        }
        bytes_read = read( vfile->fd, buf, size );

        if (bytes_read == -1)
        {
            // $$$ err msg
            fprintf(stderr, "STF_FileMngr::Read: read() error on \"%s\": %s\n",
                    vfile->fileName.c_str(), strerror(errno));
        }
    }
    return bytes_read;
}

SE_Integer
STF_FileMngr::Write( FileID file, SE_Integer_Unsigned size,
                     SE_Integer_Unsigned offset, void *buf )
{
    SE_Integer bytes_written=-1;

    if (file >= VFileTblSize)
    {
        // $$$ err msg
        //
        fprintf(stderr, "STF_FileMngr::Write: ID %d is not in the virtual file table.\n", file);
        return bytes_written;
    }
    VFile *vfile=VFileTbl[file];

    if (vfile->fd == -1)
    {
        OpenFile( vfile );
    }

    if (vfile->fd != -1)
    {
        off_t seek_offset = lseek( vfile->fd, offset, SEEK_SET );

        if (seek_offset != offset)
        {
            fprintf(stderr, "STF_FileMngr::Write: lseek returned %d seeking offset %d\n",
                    (int)seek_offset, offset);
        }
        bytes_written = write( vfile->fd, buf, size );

        if (bytes_written == -1)
        {
            // $$$ err msg
            fprintf(stderr, "STF_FileMngr::Write: write() error on \"%s\": %s\n",
                    vfile->fileName.c_str(), strerror(errno));
        }
    }
    return bytes_written;
}

void
STF_FileMngr::UnregisterFile( FileID id )
{
    if (id == FILE_IDX_NOT_SET)
    {
        fprintf(stderr, "Error - STF_FileMngr::UnregisterFile() index not set\n");
        return;
    }

    if (VFileTbl[id]->fd != -1)
    {
        close( VFileTbl[id]->fd );
        VFileTbl[id]->fd = -1;
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
FileID
STF_FileMngr::RegisterFile( const string &fName, SE_Access_Mode accessMode )
{
    VFile *vfile = NULL;

    // search for this file in the file table
    //
    for (unsigned int f=0 ; f<VFileTblSize ; f++)
    {
        vfile = VFileTbl[f];

        if (fName == vfile->fileName)
        {
            // first check to make sure the file hasn't been closed since
            // it was initially opened, if so, reopen it with the requested
            // mode and return
            if (vfile->fd == -1)
            {
                vfile->fd = open( vfile->fileName.c_str(), vfile->mode, 0666 );

                if (vfile->fd == -1)
                {
                    fprintf(stderr, "STF_FileMngr::RegisterFile: open error on \"%s\": %s\n",
                             vfile->fileName.c_str(), strerror(errno));
                }
                vfile->fd_pos = 0;
                return f;
            }
// next check that the mode is the same on the current opened file and change
// it if it is different
            else if (( accessMode == SE_AM_READ_ONLY && vfile->mode == READ_MODE ) ||
                    ( accessMode != SE_AM_READ_ONLY && vfile->mode == WRITE_MODE ))
            {
                return f;
            }
            else
            {
                vfile->mode = (accessMode == SE_AM_READ_ONLY ? READ_MODE : WRITE_MODE);

                // if this file is in the openFilesTbl then
                // close it and open it with the new mode
                //
                if (vfile->fd != -1)
                {
                    close( vfile->fd );

                    vfile->fd = open( vfile->fileName.c_str(), vfile->mode, 0666 );

                    if (vfile->fd == -1)
                    {
                        fprintf(stderr, "STF_FileMngr::RegisterFile: open error on \"%s\": %s\n",
                                vfile->fileName.c_str(), strerror(errno));
                    }
                    vfile->fd_pos = 0;
                }
                return f;
            }
        }
    }
    VFileTblSize++;
    VFileTbl = (VFile**)realloc( VFileTbl, sizeof(VFile*)*VFileTblSize );

    VFileTbl[VFileTblSize-1] = new VFile( fName,
                              (accessMode == SE_AM_READ_ONLY ? READ_MODE : WRITE_MODE) );

    return VFileTblSize-1;
}

bool
STF_FileMngr::TruncateFile( FileID file, SE_Integer_Unsigned size )
{
    if (file >= VFileTblSize)
    {
        // $$$ error message
        fprintf(stderr,
            "STF_FileMngr::TruncateFile:ID %d is not in the virtual file table.\n", file);
        return false;
    }
    VFile *vfile=VFileTbl[file];
    struct stat file_stats;
    int rsts;

    // get the current size of the file
    //
    if (vfile->fd == -1)
    {
        if (stat( vfile->fileName.c_str(), &file_stats ) == -1)
        {
            fprintf(stderr, "STF_FileMngr::TruncateFile: stat error on file %s\n",
                    vfile->fileName.c_str());
            return false;
        }
    }
    else
    {
        if (fstat( vfile->fd, &file_stats ) == -1)
        {
            fprintf(stderr, "STF_FileMngr::TruncateFile: fstat error on file %s\n",
                   vfile->fileName.c_str());
            return false;
        }
    }

    if ((SE_Integer_Unsigned)file_stats.st_size <= size)
    {
        return true;
    }

#ifndef WIN32
    if (vfile->fd == -1)
    {
        rsts=truncate( vfile->fileName.c_str(), size );
    }
    else
    {
        rsts=ftruncate( vfile->fd, size );
    }
#else
    if (vfile->fd == -1)
    {
        OpenFile( vfile );
    }
    rsts = chsize( vfile->fd, size );
#endif

    return (rsts == 0 ? true : false);
}
