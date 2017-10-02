// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Xmtl.cpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class implementation for the base class STF_Xmtl
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


#include "STF_Xmtl.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_FileMngr.hpp"
#include "STF_File.hpp"

using namespace STF_NAMESPACE;

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
STF_Xmtl::STF_Xmtl
(
          XmtlIndxType    xmtlNum,
          SE_Access_Mode  Access,
    const string         &file_name,
          bool            open_internally
)
: rootFile(file_name),
    xmtlIndx(xmtlNum),
    xmtlAccess(Access),
    currFileIndx(MFT_INDX_NOT_SET),
    bulkDataFileIndx(MFT_INDX_NOT_SET),
    internal_xmtl(open_internally)
{
    rootFile.SetXmtl(this);
    originalPath = file_name;
    xmtlModified = (xmtlAccess == SE_AM_CREATE);
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
STF_Xmtl::~STF_Xmtl()
{
    Flush();

    if (rootFile.IsLoaded())
        STF_FileMngr::UnregisterFile(rootFile.GetFileId());

    for (MFTIndxType i=0; i < MFT.size(); i++)
    {
        delete MFT[i];
    }

    MFT.clear();
}

bool
STF_Xmtl::Flush()
{
    if (xmtlIndx == XMTL_INDX_NOT_SET)
        return true;

    STF_BlockMngr::FlushBlocks(xmtlIndx);

    if (xmtlAccess != SE_AM_CREATE && xmtlAccess != SE_AM_UPDATE)
        return true;

    if (xmtlModified && rootFile.IsLoaded())
    {
        SE_GUID guid;

        GUID_Create(guid);
        rootFile.SetGUID(guid);

        rootFile.Write();
    }

    for (MFTIndxType i=0; i < MFT.size(); i++)
    {
        if (MFT[i] != NULL)
            MFT[i]->Write();
    }

    return true;
}


// this may create an STF_File which must be done with
// an already-created xmtl.
//
bool STF_Xmtl::Init()
{
    // If xmtlAccess is not creat, then we have to load the MFT.
    //
    if (xmtlAccess == SE_AM_CREATE)
    {
        // set the endian-ness for the transmittal to that of the manager.
        //
        endian = STF_XmtlMngr::GetEndian();
        currFileIndx = MFT_INDX_NOT_SET;
        bulkDataFileIndx = MFT_INDX_NOT_SET;

        rootFile.InitRootFile();
    }
    else
    {
        // set the endian-ness to unknown (this will be determined later from the
        // rootfile.)
        //
        endian = STF_UNKNOWN_ENDIAN;

        if (!rootFile.LoadRootFile())
        {
            xmtlIndx = XMTL_INDX_NOT_SET;  // this is checked after creation
        }
        else
        {
            if (!LoadMFT())
            {
                xmtlIndx = XMTL_INDX_NOT_SET;
            }
            else
            {
    /* $$$ Part 3 is missing the File Type flag
                if (xmtlAccess == RDWR)
                {
    // set currFileIndx and (maybe) bulkDataFileIndx
    //
    // (Note: this code may not set bulkDataFileIndx. This will cause a new
    // bulkDataFile to get created in the event that new images or data tables
    // are added to the xmtl. The only minor drawback is that potentially usable
    // space in an 'earlier' bulkData file will not be filled, but this is not a
    // big deal. This is intentional since it would require loading all the
    // STF_File's in the MFT which can be too costly in some real-world use cases.
    // (The code was previously modified to not do this.)
    //   Also note that in most cases the bulkDatafile will be the last one in the
    // xmtl and in this case bulkDataFileIndx will get set.
    //
                    int f = MFT.size();
                    STF_File *file=NULL;

                    while (--f >= 0 && currFileIndx == MFT_INDX_NOT_SET)
                    {
                        file = GetFile(f);

                        if (file && file->GetFileType() == OBJECT_DATA_FILE_TYPE)
                        {
                            currFileIndx = f;
                        }
                        else if (bulkDataFileIndx == MFT_INDX_NOT_SET &&
                            file && file->GetFileType() == BULK_DATA_FILE_TYPE)
                        {
                            bulkDataFileIndx = f;
                        }
                    }
                }
    */
                currFileIndx = (MFT.size() > 0? MFT.size() - 1 : MFT_INDX_NOT_SET);
            }
        }
    }
    return (xmtlIndx != XMTL_INDX_NOT_SET);
}

// if the file has not already been created in the MFT then create it and
// add it to the MFT.
// create the full filename with the basename and then
// get the fileId from the FileMngr
//
STF_File *
STF_Xmtl::GetFile( MFTIndxType findx )
{
    if (findx < 0 || findx > MFT.size())
    {
        return NULL;
    }
    else if (MFT[findx] != NULL)
    {
        return MFT[findx];
    }
    string full_path = rootFile.GetDataFilePath(findx);
    FileID fileID = STF_FileMngr::RegisterFile(full_path, xmtlAccess);
    STF_File *file = new STF_File(full_path, fileID, xmtlIndx, findx, false);

    if (!file->Load())
    {
        STF_FileMngr::UnregisterFile(fileID);
        delete file;
        file = NULL;
    }
    else
        MFT[findx] = file;

    return file;
}


//-----------------------------------------------------------------------------
// create an STF_File for each file in the Master File List stored in
// the root file.
//-----------------------------------------------------------------------------
bool
STF_Xmtl::LoadMFT( )
{
    string file_path;

    // if there are entries in the MFT then
    // print a warning
    //
    if (MFT.size() != 0)
    {
        fprintf( stderr, "Can't load MFT. MFT already has entries\n");
        return false;
    }

    // get MFT info in header, number of files, and
    // the version of the transmittal.
    //
    for (SE_Integer_Unsigned i=0; i < rootFile.GetNumberOfFiles(); ++i)
    {
        FILE *fp = NULL;

        file_path = rootFile.GetDataFilePath(i);

        if ((fp = fopen(file_path.c_str(), "r")) == NULL)
        {
            printf("STF: Can't load Master File Table. File %s not found\n",
                file_path.c_str());
            return false;
        }
        else
        {
            fclose(fp);
        }
        MFT.push_back( NULL); // will be initialized later
    }
    return true;
}

// create a new STF_File in the MFT for writing and return its
// index into the MFT
//
STF_File *
STF_Xmtl::CreateFile( void )
{
    STF_File *file;
    FileID   fileID;

    // create the new filename
    //
    MFTIndxType  newFileIndx = MFT.size();

    string file_path(rootFile.GetDataFilePath(newFileIndx));

    // create a new stf file and add it to the MFT
    //
    fileID = STF_FileMngr::RegisterFile( file_path, xmtlAccess);
    file = new STF_File( file_path, fileID, xmtlIndx, newFileIndx, true);

    MFT.push_back( file );

    // keep the MFL list in the root file up to date
    //
    rootFile.UpdateDataFileList(file_path);

    return file;
}

// create space in the transmittal for an object with initial size
//
bool
STF_Xmtl::ReserveObject( XFBO &xfbo, SE_Short_Integer_Unsigned objType,
    bool isConverterMode )
{
    STF_File    *stfFile =NULL;
    MFTIndxType  nextFileIndx = currFileIndx;

    if (nextFileIndx == MFT_INDX_NOT_SET)
    {
        stfFile = CreateFile();
        nextFileIndx = stfFile->GetFileIndx();
    }
    else if (xfbo.GetMFTIndx() != MFT_INDX_NOT_SET
          && xfbo.GetMFTIndx() != nextFileIndx)
    {
        stfFile = CreateFile();
        nextFileIndx = stfFile->GetFileIndx();

        if (xfbo.GetMFTIndx() != nextFileIndx)
            fprintf(stderr, "STF Error: sanity check: new file request %d "
                "is not for next one (%d)\n", xfbo.GetMFTIndx(), nextFileIndx);
    }
    else
    {
        stfFile = GetFile(nextFileIndx);
    }
    BlkIndxType blk = xfbo.GetBlkIndx();
    ObjIndxType obj = xfbo.GetObjIndx();

    // if there is room in the current file then allocate the space, set
    // the obj ref and return true
    //
    if (stfFile->ReserveObject(objType, blk, obj, isConverterMode))
    {
        xfbo.SetXmtlIndx( this->xmtlIndx); // set the xmtlIndx first
        // to indicate that it is resolved
        xfbo.SetMFTIndx( nextFileIndx );
        xfbo.SetBlkIndx( blk );
        xfbo.SetObjIndx( obj );
        xfbo.SetObjType( objType );
    }
    //
    // else create a new stf file and allocate space in it.
    //
    else
    {
        stfFile = CreateFile();
        nextFileIndx = stfFile->GetFileIndx();

        if (stfFile->ReserveObject(objType, blk, obj))
        {
            xfbo.SetXmtlIndx( this->xmtlIndx ); // set the xmtlIndx first
            // to indicate that it is resolved
            xfbo.SetMFTIndx( nextFileIndx );
            xfbo.SetBlkIndx( blk );
            xfbo.SetObjIndx( obj );
            xfbo.SetObjType( objType );
        }
        else
        {
            fprintf(stderr, "Unable to allocate space in new file %d,%d.\n",
                xmtlIndx, nextFileIndx);
            return false;
        }
    }

    /* $$$ Part 3 is missing the File Type flag
    if (objType < SE_DRM_CLASS_UBOUND)
    {
        currFileIndx = nextFileIndx;
    }
    else
    {
        bulkDataFileIndx = nextFileIndx;
    }
    */
    currFileIndx = nextFileIndx;

    return true;
}

// get the indx into the refd xmtl list of the given xmtl urn and
// add it if not there
//
XmtlIndxType
STF_Xmtl::GetRefdXmtlIndx( const XMTL_URN &xmtl_urn )
{
    return rootFile.GetRefdXmtlIndx( xmtl_urn );
}

ITRIndxType
STF_Xmtl::GetITRindx( const string &obj_label, XmtlIndxType refd_xmtl_indx )
{
    return rootFile.GetITRindx( obj_label, refd_xmtl_indx );
}

void
STF_Xmtl::Dump( FILE* fp, int verbose )
{
    fprintf(fp, "Endian = ");

    if (GetEndian() == STF_LITTLE_ENDIAN)
        fprintf(fp, "Little\n");
    else if (GetEndian() == STF_BIG_ENDIAN)
        fprintf(fp, "Big\n");
    else
        fprintf(fp, "Unknown\n");

    rootFile.Dump(fp, verbose);
}

bool
STF_Xmtl::DefragTransmittal( bool verbose )
{
    int bytes_freed=0;

    for (SE_Integer_Unsigned f=0; f < rootFile.GetNumberOfFiles() ; f++)
    {
        STF_File *file=GetFile(f);

        if (file == NULL)
        {
            fprintf(stderr,
              "Error - STF_Xmtl::DefragTransmittal : couldn't get file %d\n",
              f);
            return false;
        }

        if (verbose)
        {
            printf("File %d has %d fragmented bytes\n", f,
                   file->GetFragmentation());
        }
        bytes_freed += file->DefragBlocks();
    }

    if (verbose)
        printf("Defragmentation freed %d bytes\n", bytes_freed);

    return true;
}


bool STF_Xmtl::RenameTransmittal( const string &file_name )
{
    // get the path, filename and base of the filename
    //
    SetXmtlModified();

    if (!rootFile.Rename(file_name))
        return false;

    rootFile.Write();
    originalPath = FileUtils::CombinePaths(
        FileUtils::GetPathOnly(originalPath), file_name);

    return true;
}
