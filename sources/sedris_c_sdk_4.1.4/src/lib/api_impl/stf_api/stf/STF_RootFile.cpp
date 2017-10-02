// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_RootFile.cpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class implementation for the base class STF_RootFile
//   The root file no longer contains object data. This is simple
// a place for static data about the transmital. It is read once
// upon initialization and then written out upon closure.
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

#ifdef _WIN32
#pragma warning( disable : 4786 )
#endif

#include <sys/stat.h>
#include <sys/types.h>

#ifndef WIN32
#include <unistd.h>
#endif

#include "STF_RootFile.hpp"
#include "STF_RawBuffer.hpp"
#include "STF_Xmtl.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_FileMngr.hpp"
#include "STF_File.hpp"

using namespace STF_NAMESPACE;


//-----------------------------------------------------------------------------
// Constructor for the STF_RootFile.
//
//-----------------------------------------------------------------------------
STF_RootFile::STF_RootFile( const string &file_name )
: xmtl(NULL), fileId(FILE_IDX_NOT_SET),
  modified(false),
  xmtl_state_bits(0)
{
    if (!file_name.empty())
        fullPath = FileUtils::GetAbsolutePath(file_name);
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
STF_RootFile::~STF_RootFile()
{
}

bool STF_RootFile::InitRootFile()
{
    if (fullPath.empty())
        return false;

    SE_Access_Mode access = xmtl->GetXmtlAccess();

    fileId = STF_FileMngr::RegisterFile(fullPath, access);

    major_vers = CURRENT_MAJOR_VERSION;
    minor_vers = CURRENT_MINOR_VERSION;
    sftwr_vers = CURRENT_SFTWR_VERSION;

    modified = true;

    return true;
}


string
STF_RootFile::MakeDataFileName
(
          SE_Integer_Unsigned  file_indx,
    const string              &base_name
) const
{
    std::string ret(base_name);

    char buff[20];
    sprintf(buff, "_%05d.stf", file_indx);
    ret += buff;

    return ret;
}


string
STF_RootFile::GetDataFilePath( SE_Integer_Unsigned file_indx, bool with_path )
{
    std::string ret;

    if (file_indx < MasterFileList.size())
        ret = MasterFileList[file_indx];
    else
    {
        // need to make it
        ret = MakeDataFileName(file_indx,
                            FileUtils::GetFileOnlyNoExt(GetFilePath()));
    }

    if (with_path)
        ret = FileUtils::CombinePaths(FileUtils::GetPathOnly(GetFilePath()),
                                        ret);

    return ret;
}


bool
STF_RootFile::Rename( const string &new_file_name )
{
    // we can only rename the file part only, no path changes
    if (!FileUtils::GetPathOnly(new_file_name).empty())
    {
        fprintf(stderr, "Error - the new transmittal name \"%s\" is invalid,"
                " can't have a path\n", new_file_name.c_str());
        return false;
    }
    else if (FileUtils::GetFileExt(new_file_name).empty())
    {
        fprintf(stderr, "Error - the new transmittal name \"%s\" is invalid,"
                " missing file extension\n", new_file_name.c_str());
        return false;
    }

    // get the new file path by combining previous path and new name
    string oriPath = FileUtils::GetPathOnly(fullPath);
    string newBaseName = FileUtils::GetFileOnlyNoExt(new_file_name);
    string dataFName;

    for (SE_Integer_Unsigned i=0; i < GetNumberOfFiles(); i++)
    {
        STF_File *file = xmtl->GetFile(i);

        if (file == NULL)
        {
            fprintf(stderr,
                    "Error - STF_RootFile::Rename couldn't get file %d\n", i);
            return false;
        }
        dataFName = MakeDataFileName(i, newBaseName);
        file->ChangeFileName(FileUtils::CombinePaths(oriPath, dataFName));
        MasterFileList[i] = dataFName;
    }
    modified = true;
    fullPath = FileUtils::CombinePaths(oriPath, new_file_name);
    return STF_FileMngr::ChangeFileName(fileId, fullPath);
}


//-----------------------------------------------------------------------------
// return true on success; false on failure
//-----------------------------------------------------------------------------
bool STF_RootFile::LoadRootFile( )
{
    STF_RawBuffer *buf;
    offset_type   offset=0;    // used as a file offset and a buffer offset.
    bool          sts=true;
    int           fsize=0;
    SE_Byte_Unsigned magic_num;
    MachineArchType endian;
    struct stat file_info;

    if (stat(fullPath.c_str(), &file_info) != 0)
    {
        fprintf(stderr, "Error - can't open root file \"%s\"\n",
                fullPath.c_str());
        return false;
    }
    else if (file_info.st_size < ROOT_END_HEADER_POS)
    {
        fprintf(stderr, "Error - invalid root file size \"%s\"\n",
                fullPath.c_str());
        return false;
    }
    fsize = file_info.st_size;

    SE_Access_Mode access = xmtl->GetXmtlAccess();
    fileId = STF_FileMngr::RegisterFile( fullPath, access );

    // create an STF_RawBuffer to use to read in the file.
    // (if the endian-ness hasn't been established then guess LITTLE_ENDIAN
    //  and then change it if we are wrong.)
    //
    if (xmtl->GetEndian() == STF_UNKNOWN_ENDIAN)
        endian = STF_LITTLE_ENDIAN;
    else
        endian = xmtl->GetEndian();

    buf = new STF_RawBuffer( fileId, access, endian );
    if (buf->ReadBuffer( fsize, offset ) != fsize)
        return false;

    magic_num = buf->GetUInt8( ROOT_MAGIC_NUM_POS );

    if (magic_num == FILE_MAGIC_NUMBER)
    {
        fprintf(stderr,
                "Error - not an STF root file (this is a data file)\n");
        delete buf;
        return false;
    }
    else if (magic_num != ROOT_MAGIC_NUMBER)
    {
        fprintf(stderr,
                "Error - not an STF root file (magic number is 0x%02x)\n",
            magic_num);
        delete buf;
        return false;
    }

    // if we made a guess at the endian, then verify it
    if (xmtl->GetEndian() == STF_UNKNOWN_ENDIAN)
    {
        MachineArchType stored_endian = (MachineArchType)
            buf->GetUInt8( ROOT_ENDIAN_POS );

        if (stored_endian == endian)
        {
            // guess was correct
            xmtl->SetEndian( endian );
        }
        else
        {
            // wrong guess, update
            delete buf;
            endian = STF_BIG_ENDIAN;
            buf = new STF_RawBuffer( fileId, access, endian );
            buf->ReadBuffer( fsize, offset );

            stored_endian = (MachineArchType)buf->GetUInt8( ROOT_ENDIAN_POS );

            if (stored_endian == endian)
            {
                xmtl->SetEndian( endian );
            }
            else
            {
                fprintf(stderr,"Error - invalid endian found in root file.\n");
                delete buf;
                return false;
            }
        }
    }

    // read the file into memory.
    //
    major_vers = buf->GetUInt8( ROOT_MAJOR_VERS_POS );
    minor_vers = buf->GetUInt8( ROOT_MINOR_VERS_POS );

    if (major_vers != CURRENT_MAJOR_VERSION ||
        minor_vers != CURRENT_MINOR_VERSION)
    {
        fprintf(stderr, "Error - incompatible STF file version\n");
        delete buf;
        return false;
    }
    buf->GetStdString( ROOT_SFTWR_VERS_POS, sftwr_vers );

    rootObj.SetXmtlIndx( xmtl->GetXmtlIndx() );
    rootObj.SetMFTIndx( buf->GetUInt16(ROOT_OBJ_FILE_NUM_POS) );
    rootObj.SetBlkIndx( buf->GetUInt16(ROOT_OBJ_BLK_NUM_POS) );
    rootObj.SetObjIndx( buf->GetUInt8(ROOT_OBJ_OBJ_NUM_POS) );

    SE_Integer_Unsigned mft_size   = buf->GetUInt32(ROOT_MFT_SIZE_POS);
    SE_Integer_Unsigned mft_offset = buf->GetUInt32(ROOT_MFT_OFFSET_POS);

    SE_Integer_Unsigned rxt_size   = buf->GetUInt32(ROOT_RXT_SIZE_POS);
    SE_Integer_Unsigned rxt_offset = buf->GetUInt32(ROOT_RXT_OFFSET_POS);

    SE_Integer_Unsigned rot_size   = buf->GetUInt32(ROOT_ROT_SIZE_POS);
    SE_Integer_Unsigned rot_offset = buf->GetUInt32(ROOT_ROT_OFFSET_POS);

    SE_Integer_Unsigned pot_size   = buf->GetUInt32(ROOT_POT_SIZE_POS);
    SE_Integer_Unsigned pot_offset = buf->GetUInt32(ROOT_POT_OFFSET_POS);

    // sanity checks on the root file
    if (rxt_size > MAX_NUM_REFD_XMTLS)
    {
        fprintf(stderr,
                "Error - invalid number of Refd Xmtls (%u)\n", rxt_size);
    }
    else if (rot_size > MAX_NUM_ITR_OBJS)
    {
        fprintf(stderr,
                "Error - invalid number of ITR Refd objects (%u)\n", rot_size);
    }
    else if (pot_size > MAX_NUM_PUB_OBJS)
    {
        fprintf(stderr,
          "Error - invalid number of published objects (%u)\n", pot_size);
    }
    buf->GetMem( ROOT_GUID_POS, guid, SE_GUID_SIZE );
    guid[SE_GUID_SIZE] = '\0';

    XMTL_URN xmtl_urn;

    if (buf->GetStdString(ROOT_XMTL_URN_POS, xmtl_urn) > MAX_XMTL_URN_LEN)
    {
        fprintf(stderr, "Error - invalid URN string read in root file\n");
        sts = false;
    }
    else
        xmtl->SetXmtlURN( xmtl_urn, true );

    if (sts)
        sts = LoadMFL( buf, mft_size, mft_offset );

    if (sts)
        sts = LoadRefdXmtlList( buf, rxt_size, rxt_offset );

    if (sts)
        sts = LoadITRRefdObjList( buf, rot_size, rot_offset );

    if (sts)
        sts = LoadPubObjectMap( buf, pot_size, pot_offset );

    delete buf;
    return sts;
}


//-----------------------------------------------------------------------------
// the offset should be positioned at the beginning of the list of files
// for this transmittal.
// return 1 on success; 0 on failure
//-----------------------------------------------------------------------------
bool STF_RootFile::LoadMFL( STF_RawBuffer *buf, SE_Integer_Unsigned num_files,
                           offset_type offset )
{
    string entry;

    for (SE_Integer_Unsigned i=0; i < num_files; i++)
    {
        // read the null terminated filename without a path
        offset += buf->GetStdString(offset, entry) + 1;

        if (entry.length() > MAX_FILENAME_LEN)
        {
            fprintf(stderr,
              "Error - invalid STF filename read in root file\n");
            return false;
        }
        MasterFileList.push_back( entry );
    }
    return true;
}

//-----------------------------------------------------------------------------
// read in the list of transmittals referenced from this transmittal.
// the offset should be positioned on the size of this list.
//-----------------------------------------------------------------------------
bool
STF_RootFile::LoadRefdXmtlList( STF_RawBuffer *buf,
                SE_Integer_Unsigned num_xmtls, offset_type offset )
{
    XMTL_URN urn;

    for (SE_Integer_Unsigned i=0; i < num_xmtls; i++)
    {
        offset += buf->GetStdString(offset, urn) + 1;

        if (urn.length() > MAX_XMTL_URN_LEN)
        {
            fprintf(stderr, "STF: invalid referenced transmittal URN length\n");
            return false;
        }
        RefdXmtlList.push_back( urn );
    }
    return true;
}

//-----------------------------------------------------------------------------
// read in the list of inter-transmittal referenced objects.
// the offset should be positioned on the size of this list.
//-----------------------------------------------------------------------------
bool
STF_RootFile::LoadITRRefdObjList( STF_RawBuffer  *buf,
                  SE_Integer_Unsigned num_objs, offset_type offset )
{
    for (SE_Integer_Unsigned i=0; i < num_objs; i++)
    {
        SE_Integer_Unsigned bce_val;
        ITR_Refd_Obj itr_obj;

        offset += buf->GetOCE8Unsigned(offset, bce_val);
        itr_obj.refXmtlIndx = (ITRIndxType)bce_val;

        offset += buf->GetStdString(offset, itr_obj.objLabel) + 1;
        ITRRefdObjList.push_back( itr_obj );  // copy itr_obj
    }
    return true;
}

//-----------------------------------------------------------------------------
// read in the list published objects.
// the offset should be positioned on the size of this list.
//-----------------------------------------------------------------------------
bool
STF_RootFile::LoadPubObjectMap( STF_RawBuffer *buf,
                 SE_Integer_Unsigned num_objs, offset_type offset )
{
    Published_Object pub_obj;

    pub_obj.xfbo.SetXmtlIndx( xmtl->GetXmtlIndx());

    for (SE_Integer_Unsigned i=0; i < num_objs; i++)
    {
        offset += buf->GetStdString(offset, pub_obj.label) + 1;

        pub_obj.xfbo.SetMFTIndx((MFTIndxType)buf->GetUInt16(offset));
        offset += 2;

        pub_obj.xfbo.SetBlkIndx((BlkIndxType)buf->GetUInt16(offset));
        offset += 2;

        pub_obj.xfbo.SetObjIndx(buf->GetUInt8(offset));
        offset += 1;

        PubObjectMap[pub_obj.label] = pub_obj;

        if (!pub_obj.xfbo.CheckIndxs())
        {
            fprintf(stderr,
                    "STF: Invalid published object in the root file.\n");
            return false;
        }
    }
    return true;
}

// return whether or not the filename was in the list
//
bool
STF_RootFile::UpdateDataFileList( const string &file_name )
{
    // if the filename is not in the MFL then add a new entry
    string file_only(FileUtils::GetFileOnly(file_name));
    MASTER_FILE_LIST::iterator iter;

    for (iter=MasterFileList.begin(); iter != MasterFileList.end(); ++iter)
    {
        if ((*iter) == file_only)
            return false;
    }
    modified = true;
    MasterFileList.push_back( file_only );
    return true;
}

bool
STF_RootFile::Write()
{
    SE_Access_Mode      access;
    MachineArchType     endian;
    SE_Integer_Unsigned len;
    offset_type hdr_offset=0, tbl_offset=0;

    STF_RawBuffer    *raw_buf;
    SE_Byte_Unsigned *data_buf;

    MASTER_FILE_LIST::iterator  MFL_iter;
    REFD_XMTL_LIST::iterator    RXL_iter;
    ITR_REFD_OBJ_LIST::iterator ROL_iter;
    PUB_OBJ_MAP::iterator       POL_iter;
    SE_Integer_Unsigned  mft_size, rxt_size, rot_size, pot_size;

    if (!modified)
    {
        return false;
    }
    access = xmtl->GetXmtlAccess();
    endian = xmtl->GetEndian();

    // Create a RawBuffer to write the data for us.
    //
    // this memory will be used by the rest of the
    //
    data_buf = new SE_Byte_Unsigned[ROOT_END_HEADER_POS];
    raw_buf = new STF_RawBuffer( fileId, access, endian, data_buf );

    // write out the header stuff
    //
    raw_buf->PutUInt8( ROOT_MAGIC_NUM_POS, ROOT_MAGIC_NUMBER );
    raw_buf->PutUInt8( ROOT_ENDIAN_POS, xmtl->GetEndian() );
    raw_buf->PutUInt8( ROOT_MAJOR_VERS_POS, major_vers );
    raw_buf->PutUInt8( ROOT_MINOR_VERS_POS, minor_vers );
    raw_buf->PutStdString( ROOT_SFTWR_VERS_POS, sftwr_vers,
        SFTWR_VERS_STRING_LEN );
    raw_buf->PutUInt16( ROOT_OBJ_FILE_NUM_POS, rootObj.GetMFTIndx() );
    raw_buf->PutUInt16( ROOT_OBJ_BLK_NUM_POS, rootObj.GetBlkIndx() );
    raw_buf->PutUInt8( ROOT_OBJ_OBJ_NUM_POS, rootObj.GetObjIndx() );

    CalcRootListSizes( mft_size, rxt_size, rot_size, pot_size );

    hdr_offset = ROOT_END_HEADER_POS;
    raw_buf->PutUInt32( ROOT_MFT_SIZE_POS, MasterFileList.size() );
    raw_buf->PutUInt32( ROOT_MFT_OFFSET_POS, hdr_offset );
    hdr_offset += mft_size;

    raw_buf->PutUInt32( ROOT_RXT_SIZE_POS, RefdXmtlList.size() );
    raw_buf->PutUInt32( ROOT_RXT_OFFSET_POS, hdr_offset );
    hdr_offset += rxt_size;

    raw_buf->PutUInt32( ROOT_ROT_SIZE_POS, ITRRefdObjList.size() );
    raw_buf->PutUInt32( ROOT_ROT_OFFSET_POS, hdr_offset );
    hdr_offset += rot_size;

    raw_buf->PutUInt32( ROOT_POT_SIZE_POS, PubObjectMap.size() );
    raw_buf->PutUInt32( ROOT_POT_OFFSET_POS, hdr_offset );
    hdr_offset += pot_size;

    raw_buf->PutMem( ROOT_GUID_POS, guid, SE_GUID_SIZE );

    raw_buf->PutStdString( ROOT_XMTL_URN_POS, xmtl->GetXmtlURN(),
                            MAX_XMTL_URN_LEN );
    raw_buf->PutStdString( ROOT_FILE_NAME_POS, FileUtils::GetFileOnly(fullPath),
                            MAX_FILENAME_LEN );

    raw_buf->WriteBuffer( ROOT_END_HEADER_POS, 0 );
    delete raw_buf;
    delete[] data_buf;

    STF_FileMngr::TruncateFile(fileId, hdr_offset);

    hdr_offset = ROOT_END_HEADER_POS;

    // write out the Master File List
    //
    data_buf = new SE_Byte_Unsigned[mft_size];
    raw_buf = new STF_RawBuffer( fileId, access, endian, data_buf );

    for (tbl_offset = 0, MFL_iter = MasterFileList.begin();
        MFL_iter != MasterFileList.end(); MFL_iter++)
    {
        len = (*MFL_iter).length() + 1;
        raw_buf->PutStdString( tbl_offset, (*MFL_iter), len );
        tbl_offset += len;
    }
    raw_buf->WriteBuffer( mft_size, hdr_offset );
    delete raw_buf;
    delete[] data_buf;
    hdr_offset += mft_size;

    if (rxt_size)
    {
        // write out the Referenced transmittal list
        //
        data_buf = new SE_Byte_Unsigned[rxt_size];
        raw_buf = new STF_RawBuffer( fileId, access, endian, data_buf );

        for (tbl_offset = 0, RXL_iter = RefdXmtlList.begin();
            RXL_iter != RefdXmtlList.end(); RXL_iter++)
        {
            len = (*RXL_iter).length() + 1;
            raw_buf->PutStdString( tbl_offset, *RXL_iter, len );
            tbl_offset += len;
        }
        raw_buf->WriteBuffer( rxt_size, hdr_offset );
        delete raw_buf;
        delete[] data_buf;
        hdr_offset += rxt_size;
    }

    if (rot_size)
    {
        // write out the Referenced object list
        //
        data_buf = new SE_Byte_Unsigned[rot_size];
        raw_buf = new STF_RawBuffer( fileId, access, endian, data_buf );

        for (tbl_offset = 0, ROL_iter = ITRRefdObjList.begin();
            ROL_iter != ITRRefdObjList.end(); ROL_iter++)
        {
            SE_Integer_Unsigned bce_val = (*ROL_iter).refXmtlIndx;

            len = raw_buf->PutOCE8Unsigned( tbl_offset, bce_val );
            tbl_offset += len;

            len = (*ROL_iter).objLabel.length() + 1;
            raw_buf->PutStdString( tbl_offset, (*ROL_iter).objLabel, len );
            tbl_offset += len;
        }
        raw_buf->WriteBuffer( rot_size, hdr_offset );
        delete raw_buf;
        delete[] data_buf;
        hdr_offset += rot_size;
    }

    if (pot_size)
    {
        // write out the Published object list
        //
        data_buf = new SE_Byte_Unsigned[pot_size];
        raw_buf = new STF_RawBuffer( fileId, access, endian, data_buf );

        for (tbl_offset = 0, POL_iter  = PubObjectMap.begin();
        POL_iter != PubObjectMap.end(); POL_iter++)
        {
            len = (*POL_iter).second.label.length() + 1;
            raw_buf->PutStdString( tbl_offset, (*POL_iter).second.label, len );
            tbl_offset += len;
            raw_buf->PutUInt16( tbl_offset, (*POL_iter).second.xfbo.GetMFTIndx() );
            tbl_offset += 2;
            raw_buf->PutUInt16( tbl_offset, (*POL_iter).second.xfbo.GetBlkIndx() );
            tbl_offset += 2;
            raw_buf->PutUInt8(  tbl_offset, (*POL_iter).second.xfbo.GetObjIndx() );
            tbl_offset += 1;
        }
        raw_buf->WriteBuffer( pot_size, hdr_offset );
        delete raw_buf;
        delete[] data_buf;
        hdr_offset += pot_size;
    }
    return true;
}

void
STF_RootFile::CalcRootListSizes( SE_Integer_Unsigned &mft_size, SE_Integer_Unsigned &rxt_size,
                                 SE_Integer_Unsigned &rot_size, SE_Integer_Unsigned &pot_size )
{
    MASTER_FILE_LIST::iterator  MFL_iter;
    REFD_XMTL_LIST::iterator    RXL_iter;
    ITR_REFD_OBJ_LIST::iterator ROL_iter;
    PUB_OBJ_MAP::iterator       POL_iter;

    mft_size = 0;
    rxt_size = 0;
    rot_size = 0;
    pot_size = 0;

//
    for (MFL_iter =  MasterFileList.begin() ;
         MFL_iter != MasterFileList.end() ; MFL_iter++)
    {
        mft_size += (*MFL_iter).length() + 1;
    }

    for (RXL_iter =  RefdXmtlList.begin() ;
         RXL_iter != RefdXmtlList.end() ; RXL_iter++)
    {
        rxt_size += (*RXL_iter).length() + 1;
    }

    for (ROL_iter =  ITRRefdObjList.begin() ;
         ROL_iter != ITRRefdObjList.end() ; ROL_iter++)
    {
        rot_size += (*ROL_iter).getSize();
    }

    for (POL_iter =  PubObjectMap.begin() ;
         POL_iter != PubObjectMap.end() ; POL_iter++)
    {
        pot_size += (*POL_iter).second.getSize();
    }
}


// get the indx into the refd xmtl list of the given xmtl urn
// if not in the list then add it.
//
XmtlIndxType
STF_RootFile::GetRefdXmtlIndx( const XMTL_URN &xmtl_urn )
{
    XmtlIndxType i;

    for (i=0 ; i<RefdXmtlList.size() ; i++)
    {
        if (RefdXmtlList[i] == xmtl_urn)
        {
            return i;
        }
    }
    RefdXmtlList.push_back( xmtl_urn );
    return i;
}

bool
STF_RootFile::GetRefdXmtlList
(
    SE_Integer_Unsigned &num_xmittals,
    string *trans_list_data
)
{
    if (!trans_list_data)
    {
        num_xmittals = RefdXmtlList.size();
        return true;
    }
    else if (num_xmittals < RefdXmtlList.size())
        return false;

    for (SE_Integer_Unsigned x=0; x < RefdXmtlList.size(); x++)
    {
        trans_list_data[x] = RefdXmtlList[x];
    }
    return true;
}

// Get the index into the refd obj list for this obj label and xmtl.
// Add the object to the list if neccessary.
//
ITRIndxType
STF_RootFile::GetITRindx( const string &obj_label,
                          XmtlIndxType refd_xmtl_indx )
{
    ITRIndxType i;
    for (i=0 ; i<ITRRefdObjList.size() ; i++)
    {
        if (( ITRRefdObjList[i].objLabel == obj_label) &&
            ( ITRRefdObjList[i].refXmtlIndx == refd_xmtl_indx))
        {
            return i;
        }
    }
    // allocate an entry for the new ITR ref in the list
    // (note: the ITR_Refd_Obj will allocate a new object label.)
    //
    ITR_Refd_Obj itr_refd_obj( refd_xmtl_indx, obj_label );
    ITRRefdObjList.push_back( itr_refd_obj );

    return i;
}

bool
STF_RootFile::GetITRobjRef
(
    ITRIndxType itr_obj_ref,
    XMTL_URN &xmtl_urn,
    string &obj_label
)
{
    if (itr_obj_ref >= ITRRefdObjList.size())
    {
        fprintf(stderr,
                "STF: STF_RootFile::GetITRobjRef() invalid ITR object index "
                "%d (%d)\n", itr_obj_ref, ITRRefdObjList.size());
        return false;
    }
    xmtl_urn = RefdXmtlList[ITRRefdObjList[itr_obj_ref].refXmtlIndx];
    obj_label = ITRRefdObjList[itr_obj_ref].objLabel;
    return true;
}

// get the xfbo for the given object label in the published
// object list.
//
bool
STF_RootFile::GetPublishedObjRef( const string &obj_label, XFBO &itr_xfbo )
{
    PUB_OBJ_MAP::iterator iter;

    for (iter=PubObjectMap.begin() ; iter!=PubObjectMap.end() ; iter++)
    {
        if ((*iter).first == obj_label)
        {
            itr_xfbo = (*iter).second.xfbo;
            return true;
        }
    }
    return false;
}

// Get the list of labels for the given object reference in the published
// object list.
//
bool
STF_RootFile::GetLabelsForPubObj
(
    const XFBO &itr_xfbo,
    SE_Integer_Unsigned &num_labels,
    string *obj_labels
)
{
    PUB_OBJ_MAP::iterator iter;
    SE_Integer_Unsigned match_count=0;

    for (iter=PubObjectMap.begin() ; iter!=PubObjectMap.end() ; iter++)
    {
        if ((*iter).second.xfbo == itr_xfbo)
        {
            if (obj_labels &&
                match_count < num_labels)
            {
                obj_labels[match_count] = (*iter).first;
            }
            match_count++;
        }
    }

    if (!obj_labels)
        num_labels = match_count;

    return true;
}

// return the number of objects in the list or -1 on error.
// create a list of the object references and/or a list of
// the object labels.
bool
STF_RootFile::GetPublishedObjects
(
    SE_Integer_Unsigned &num_objects,
    XFBO **objref_list
)
{
    if (!objref_list)
    {
        num_objects = PubObjectMap.size();
        return true;
    }
    else if (num_objects < PubObjectMap.size())
        return false;

    SE_Integer_Unsigned num_objs = PubObjectMap.size();
    SE_Integer_Unsigned i;
    PUB_OBJ_MAP::iterator iter;

    for (iter=PubObjectMap.begin(), i=0; iter!=PubObjectMap.end(); ++iter, ++i)
    {
        objref_list[i] = new XFBO((*iter).second.xfbo);
    }
    return true;
}

// add an entry in the published object list.
//
bool
STF_RootFile::PublishObject( XFBO &xfbo, const string &label )
{
    modified = true;

    Published_Object pub_obj( xfbo, label );

    PubObjectMap[label] = pub_obj;
    return true;
}

bool
STF_RootFile::UnpublishObject( XFBO &xfbo )
{
    bool ret = false;
    PUB_OBJ_MAP::iterator iter=PubObjectMap.begin();

    while (iter != PubObjectMap.end())
    {
        if ((*iter).second.xfbo == xfbo)
        {
            modified = true;
            PubObjectMap.erase( iter++ );
            ret = true;
        }
        else
            ++iter;
    }
    return ret;
}

bool
STF_RootFile::UnpublishObject( XFBO &xfbo, const string &label )
{
    bool ret = false;
    PUB_OBJ_MAP::iterator iter = PubObjectMap.find(label);

    if (iter != PubObjectMap.end() && (*iter).second.xfbo == xfbo)
    {
        PubObjectMap.erase(iter);
        ret = true;
    }
    return ret;
}

void
STF_RootFile::Dump( FILE* fp, bool verbose )
{
    SE_Integer_Unsigned i;

    fprintf(fp, "Version = %d.%d\n", major_vers, minor_vers );
    fprintf(fp, "SW Version = %s\n", sftwr_vers.c_str());
    fprintf(fp, "Data files = %d\n", MasterFileList.size() );
    for (i=0 ; verbose && i < MasterFileList.size() ; i++ )
        fprintf(fp, "    %s\n", MasterFileList[i].c_str() );

    fprintf(fp, "Referenced transmittals = %d\n", RefdXmtlList.size() );
    for (i=0 ; verbose && i < RefdXmtlList.size() ; i++ )
        fprintf(fp, "    %u = %s\n", i, RefdXmtlList[i].c_str());

    fprintf(fp, "Referenced ITR objects = %d\n", ITRRefdObjList.size() );
    for (i=0 ; verbose && i < ITRRefdObjList.size() ; i++ )
        fprintf(fp, " %5d = %s\n", ITRRefdObjList[i].refXmtlIndx,
                ITRRefdObjList[i].objLabel.c_str());

    fprintf(fp, "Published objects = %d\n", PubObjectMap.size() );

    for (PUB_OBJ_MAP::iterator iter = PubObjectMap.begin();
          verbose && iter != PubObjectMap.end();
          iter++)
    {
        fprintf(fp, "    %s = ", (*iter).second.label.c_str());
        (*iter).second.xfbo.Print(fp);
        fprintf(fp, "\n");
    }
}
