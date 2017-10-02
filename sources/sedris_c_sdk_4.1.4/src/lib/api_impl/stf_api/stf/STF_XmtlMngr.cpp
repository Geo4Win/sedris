// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_XmtlMngr.cpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class implementation for the base class STF_XmtlMngr
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

#include "STF_XmtlMngr.hpp"
#include "STF_Xmtl.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_FileMngr.hpp"

#include "STF_DataTable.hpp"
#include "STF_MFTData.hpp"
#include "STF_Image.hpp"

#include "STF_FieldMngr.hpp"

#include "URN_Resolver.hpp"

using namespace STF_NAMESPACE;


static STF_XmtlMngr *theXmtlMngr=NULL;

XmtlIndxType            STF_XmtlMngr::currXmtl=0;
vector<STF_Xmtl*>       STF_XmtlMngr::XmtlList;
vector<string>          STF_XmtlMngr::XmtlNameList;
SE_Integer_Unsigned     STF_XmtlMngr::hashTblSize=SMALL_HASH_TABLE_SIZE;
MachineArchType         STF_XmtlMngr::endian=MACHINE_ENDIAN;
XFBO                    STF_XmtlMngr::dmy_ori[];
URN_Map                 STF_XmtlMngr::urn_lookup_map;
string                  STF_XmtlMngr::SedrisResPaths;
SE_Integer              STF_XmtlMngr::maxOpenFiles;
SE_Integer_Unsigned     STF_XmtlMngr::fileSizeThreshold;
SE_Integer_Unsigned     STF_XmtlMngr::bulkDataBlockSize;
string                  STF_XmtlMngr::errorDescription;


STF_XmtlMngr *
STF_XmtlMngr::CreateXmtlMngr()
{
    if (theXmtlMngr == NULL)
    {
        theXmtlMngr = new STF_XmtlMngr();
    }
    return theXmtlMngr;
}

void
STF_XmtlMngr::DestroyXmtlMngr()
{
    if (theXmtlMngr != NULL)
    {
        delete theXmtlMngr;
        theXmtlMngr = NULL;
    }
}

//-----------------------------------------------------------------------------
// this should be made private so that it can only be called by
// OpenRootFactory
//
// This function initializes Environment Variables to be used for processing.
//  if the Memory Model is set it will be initially set to the Memory Model
//  defaults, defined in stf_core.hpp.  If individual environment variables are
//  set, the memory model defaults will be overwritten with the new value.
//  Defaut memory model will be small, and the Hash Table Size is the same
//  amount as the RAIFManager::Max_Open_Objects, defined in RAIFManager.hpp
//
//-----------------------------------------------------------------------------
STF_XmtlMngr::STF_XmtlMngr()
{
    // default to small memory model
    //
    SE_Integer_Unsigned blk_tbl_size;
    blk_tbl_size = SMALL_BLOCK_CACHE_SIZE;
    hashTblSize  = SMALL_HASH_TABLE_SIZE;
    maxOpenFiles = SMALL_MAX_OPEN_FILES;
    fileSizeThreshold = FILE_SIZE_THRESHOLD;
    bulkDataBlockSize = NOMINAL_BULK_DATA_BLK_SIZE; // 100000
    SedrisResPaths = ".";
    char *chp=NULL;

    chp = getenv( SE_API_MEMORY_MODEL );
    if (chp && *chp)
    {
        if (!strcmp( chp, "LARGE"))
        {
            //set large mem model defaults
            hashTblSize  = LARGE_HASH_TABLE_SIZE;
            blk_tbl_size = LARGE_BLOCK_CACHE_SIZE;
            maxOpenFiles = LARGE_MAX_OPEN_FILES;
        }
        else if (!strcmp( chp, "MEDIUM"))
        {
            hashTblSize  = MED_HASH_TABLE_SIZE;
            blk_tbl_size = MED_BLOCK_CACHE_SIZE;
            maxOpenFiles = MED_MAX_OPEN_FILES;
        }
        else if (!strcmp( chp, "SMALL"))
        {
            hashTblSize  = SMALL_HASH_TABLE_SIZE;
            blk_tbl_size = SMALL_BLOCK_CACHE_SIZE;
            maxOpenFiles = SMALL_MAX_OPEN_FILES;
        }
        else
        {
            fprintf(stderr,
                "STF: Unrecoqnized Value for %s environment variable.\n"
                "Must be SMALL, MED, or LARGE. Defaulting to SMALL.\n",
                SE_API_MEMORY_MODEL);
        }
    }

    //  set the hash table size to

    chp = getenv( SE_STF_BLOCK_CACHE_SIZE );
    if (chp && *chp)
    {
        blk_tbl_size = atoi(chp);
        fprintf(stderr, "STF: Setting the STF Block Cache Size to %u from "\
            "Environment Variable %s\n", atoi(chp), SE_STF_BLOCK_CACHE_SIZE);
    }

    chp = getenv( SE_RAIF_MAX_OBJECT_CACHE_SIZE );
    if (chp && *chp)
    {
        hashTblSize = atoi(chp);
        fprintf(stderr, "STF: Setting the Hash Table Size to %u from "\
            "Environment Variable %s\n", atoi(chp), SE_RAIF_MAX_OBJECT_CACHE_SIZE);
    }

    chp = getenv( SE_STF_MAX_OPEN_FILES );
    if (chp && *chp)
    {
        maxOpenFiles = atoi(chp);
        fprintf(stderr, "STF: Setting the Max Open Files to %u from "\
            "Environment Variable %s\n", atoi(chp), SE_STF_MAX_OPEN_FILES);
    }

    chp = getenv( SE_STF_FILE_SIZE_THRESHOLD );
    if (chp && *chp)
    {
        fileSizeThreshold = atol(chp);
        fprintf(stderr, "STF: Setting the File Size Threshold to %u from "
            "Environment Variable %s\n", atol(chp),
            SE_STF_FILE_SIZE_THRESHOLD);
    }

    chp = getenv( SE_STF_BULK_DATA_BLOCK_SIZE );
    if (chp && *chp)
    {
        bulkDataBlockSize = atol(chp);
        fprintf(stderr, "STF: Setting the Size for Bulk Data (Image, Data Table "
            "Data and Mesh Face Table Data) to %d from the "
            "Environment Variable %s\n", atol(chp),
            SE_STF_BULK_DATA_BLOCK_SIZE);
    }

    chp = getenv( URN_RESOLVE_ENV );
    if (chp && *chp)
    {
        fprintf(stderr, "STF: Setting the URN Resolver path to %s from the "
            "Environment Variable %s\n", chp, URN_RESOLVE_ENV);

        SedrisResPaths = chp;
    }

    // determine the Endian for the current machine. This will be used
    // for xmtls that are being created.
    //
    STF_XmtlMngr::endian = MACHINE_ENDIAN;

    // create the file manager and the block manager.
    //
    STF_FileMngr::CreateFileMngr();
    STF_BlockMngr::CreateBlockMngr(blk_tbl_size);
    STF_FieldMngr::CreateFieldMngr();
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
STF_XmtlMngr::~STF_XmtlMngr()
{
    for (XmtlIndxType x=0 ; x < XmtlList.size() ; x++)
    {
        if (XmtlList[x] != NULL)
            CloseTransmittal((RAIFImplTransmittal)(x + 1));
    }
    XmtlList.clear();
    XmtlNameList.clear();
    urn_lookup_map.clear();

    STF_BlockMngr::DestroyBlockMngr();
    STF_FileMngr::DestroyFileMngr();
    STF_FieldMngr::DestroyFieldMngr();
}

SE_Status_Code
STF_XmtlMngr::GetEncoding( SE_Encoding *encoding )
{
    if (!encoding)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    *encoding = SE_ENCODING_STF;
    return SE_STATCODE_SUCCESS;
}

SE_Boolean
STF_XmtlMngr::ValidEncoding( SE_Encoding encoding )
{
    return(encoding == SE_ENCODING_STF ? SE_TRUE : SE_FALSE);
}

SE_Boolean
STF_XmtlMngr::SameTransmittal
(
    RAIFImplTransmittal trans_a,
    RAIFImplTransmittal trans_b
)
{
    return (trans_a != trans_b? SE_FALSE : SE_TRUE);
}

SE_Status_Code
STF_XmtlMngr::OpenTransmittal
(
    const string              &file_name,
          SE_Access_Mode       access_mode,
          RAIFImplTransmittal &xmittal
)
{
    STF_Xmtl *tmp_xmtl;
    SE_Status_Code sts;

    sts = InternalOpenTransmittal(file_name, access_mode, tmp_xmtl, false);

    if (sts == SE_STATCODE_SUCCESS)
        xmittal = (RAIFImplTransmittal)(tmp_xmtl->GetXmtlIndx() + 1);

    return sts;
}

SE_Status_Code
STF_XmtlMngr::InternalOpenTransmittal
(
    const string         &file_name,
          SE_Access_Mode  access_mode,
          STF_Xmtl      *&xmittal,
          bool            internal_xmtl
)
{
    XmtlIndxType xmtlNum;
    STF_Xmtl *xmtl = NULL;
    string abs_path = FileUtils::GetAbsolutePath(file_name);

    if (SE_ValidAccessMode(access_mode) != SE_TRUE)
        return SE_STATCODE_INVALID_ACCESS_MODE;
    else if (abs_path.empty())
    {
        fprintf(stderr, "STF: can't get absolute path for \"%s\"\n",
                file_name.c_str());
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    // first see if this xmtl has been opened before (possibly while
    // crossing an ITR reference, we may need to change the access mode)
    //
    for (xmtlNum=0; xmtlNum < XmtlList.size(); xmtlNum++)
    {
        // if this transmittal has been opened before
        //
        if (XmtlNameList[xmtlNum] == abs_path)
        {
            xmtl = XmtlList[xmtlNum];

            if (xmtl == NULL)
            {
                // if it has been closed then we will reopen it further down
                break;
            }
            else if (!internal_xmtl && !xmtl->IsInternal())
            {
                // if it is not an internal open we return FAILURE
                // $$$ set err msg
                fprintf(stderr, "STF: \"%s\" is already opened\n",
                        file_name.c_str());
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
            else
            {
                // we opened it internal, close it and reopen further down
                //
                CreateXmtlMngr()->CloseTransmittal((RAIFImplTransmittal)(xmtlNum + 1));
                break;
            }
        }
    }

    // create an STF_Xmtl and add it to the list
    //
    xmtl = new STF_Xmtl( xmtlNum, access_mode, file_name, internal_xmtl );

    if (xmtlNum == XmtlList.size())
    {
        // never opened
        XmtlList.push_back(xmtl);
        XmtlNameList.push_back(xmtl->GetAbsolutePath());
    }
    else
    {
        // this is a previously opened and closed transmittal
        // and we already have the name and index in the list
        XmtlList[xmtlNum] = xmtl;
    }

    if (!xmtl->Init())
    {
        delete xmtl;
        XmtlList[xmtlNum] = NULL;
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    // add the transmittal to the URN_map
    if (!xmtl->GetXmtlURN().empty())
    {
        URN_MapEntry map_entry(file_name, xmtlNum);

        urn_lookup_map[xmtl->GetXmtlURN()] = map_entry;
    }

    if (access_mode == SE_AM_CREATE || access_mode == SE_AM_UPDATE)
    {
        currXmtl = xmtlNum;
    }
    xmittal = xmtl;
    return SE_STATCODE_SUCCESS;
}

SE_Integer_Unsigned
STF_XmtlMngr::NumOfOpenTransmittals()
{
    SE_Integer_Unsigned num_xmtls=0;

    for (XmtlIndxType i=0; i < XmtlList.size(); i++)
    {
        if (XmtlList[i] != NULL)
        {
            num_xmtls++;
        }
    }
    return num_xmtls;
}

SE_Status_Code
STF_XmtlMngr::DefragTransmittal
(
    RAIFImplTransmittal xmittal,
    bool                verbose
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    return (xmtl->DefragTransmittal(verbose) ?
            SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);
}

SE_Status_Code
STF_XmtlMngr::RenameTransmittal
(
          RAIFImplTransmittal  xmittal,
    const string              &new_file_name
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    return (xmtl->RenameTransmittal(new_file_name) ?
            SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);
}


SE_Status_Code
STF_XmtlMngr::FlushTransmittal( RAIFImplTransmittal xmittal )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
    {
        fprintf(stderr, "STF:FlushXmtl: xmtl is not in the XmtlList\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return (xmtl->Flush() ? SE_STATCODE_SUCCESS :
                            SE_STATCODE_INACTIONABLE_FAILURE);
}

// delete the xmtl and mark its index with NULL.
//
SE_Status_Code
STF_XmtlMngr::CloseTransmittal( RAIFImplTransmittal xmittal )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    XmtlIndxType xmtlNum = xmtl->GetXmtlIndx();

    // delete all the blocks in the cache that belong to this transmittal.
    // This is so the destructor for the blocks will be called.
    // Delete the xmtl from the xmtl list
    //
    STF_BlockMngr::FreeBlocks( xmtlNum, MFT_INDX_NOT_SET );

    delete xmtl;
    XmtlList[xmtlNum] = NULL;

    // leave the XmtlName in the XmtlNameList so we can reopen this
    // xmtl again and give it the same indx.

    return SE_STATCODE_SUCCESS;
}

// the first of 3 GetXmtl methods. Use this for xfbos
// that may be unresolved.
//
STF_Xmtl *
STF_XmtlMngr::GetXmtl( XFBO &xfbo )
{
    if (xfbo.IsResolved())
        return GetXmtl(xfbo.GetXmtlIndx());

    XmtlIndxType xmtl_indx = GetXmtlIndx(xfbo.GetXmtlURN());

    if (xmtl_indx == XMTL_INDX_NOT_SET)
    {
        // URN hasn't been opened, so try to resolve it
        XFBO rslvd_xfbo(xfbo);

        ResolveObject(rslvd_xfbo);
        xmtl_indx = rslvd_xfbo.GetXmtlIndx();
    }
    return GetXmtl(xmtl_indx);
}

STF_Xmtl *
STF_XmtlMngr::GetXmtl( XmtlIndxType xmtlNum )
{
    if (xmtlNum == XMTL_INDX_NOT_SET)
    {
        fprintf(stderr, "STF: GetXmtl: index not set. returning NULL\n");
        return NULL;
    }
    else if (xmtlNum >= XmtlList.size())
    {
        fprintf(stderr, "STF: GetXmtl: xmtlNum %d is out of range. returning NULL\n",
                xmtlNum);
        return NULL;
    }
    else
        return XmtlList[xmtlNum];
}

STF_Xmtl *
STF_XmtlMngr::GetXmtl( RAIFImplTransmittal xmittal )
{
    return GetXmtl((XmtlIndxType)(size_t)xmittal - 1);
}

XmtlIndxType
STF_XmtlMngr::GetXmtlIndx( const XMTL_URN &xmtl_urn )
{
    XmtlIndxType xmtl_indx = XMTL_INDX_NOT_SET;

    // first do a fast check in the URN map
    URN_Map::iterator urn_iterator = urn_lookup_map.find(xmtl_urn);

    if (urn_iterator != urn_lookup_map.end())
    {
        xmtl_indx = (*urn_iterator).second.xmtlIndx; // may/may not be set
    }

    // now check to see if we already have the transmittal opened
    for (unsigned int x=0;
        xmtl_indx == XMTL_INDX_NOT_SET && x < XmtlList.size();
        x++)
    {
        if ((XmtlList[x] != NULL) &&
            (XmtlList[x]->GetXmtlURN() == xmtl_urn))
        {
            xmtl_indx = x;
        }
    }
    return xmtl_indx;
}

bool
STF_XmtlMngr::IsXmtlEditable( XmtlIndxType xmtlIndx )
{
    STF_Xmtl *xmtl = GetXmtl(xmtlIndx);

    if (xmtl)
        return xmtl->IsEditable();
    else
        return false;
}

STF_File *
STF_XmtlMngr::GetFile( XFBO &xfbo )
{
    return GetFile( xfbo.GetXmtlIndx(), xfbo.GetMFTIndx() );
}

STF_File *
STF_XmtlMngr::GetFile( XmtlIndxType xmtl, MFTIndxType file )
{
    return GetXmtl( xmtl )->GetFile( file );
}

SE_Status_Code
STF_XmtlMngr::GetTransmittalFromObject( ObjRefInfo &ori, RAIFImplTransmittal &xmittal )
{
    XFBO &xfbo = (XFBO &)ori;

    if (!ori.IsResolved())
        return SE_STATCODE_UNRESOLVED_INPUT_OBJECT;

    xmittal = (RAIFImplTransmittal)(xfbo.GetXmtlIndx() + 1);

    return SE_STATCODE_SUCCESS;
}


SE_Status_Code
STF_XmtlMngr::GetTransmittalFile( RAIFImplTransmittal xmittal,
                                 string &file_name )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    file_name = xmtl->GetAbsolutePath(); //xmtl->GetOriginalPath();

    return (file_name.empty() ? SE_STATCODE_INACTIONABLE_FAILURE
        : SE_STATCODE_SUCCESS);
}

SE_Status_Code
STF_XmtlMngr::GetTransmittalURN( RAIFImplTransmittal xmittal,
                                 string &xmittal_urn )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    xmittal_urn = xmtl->GetXmtlURN();

    return SE_STATCODE_SUCCESS;
}

// (RAIF checks the Access mode)
//
SE_Status_Code
STF_XmtlMngr::SetTransmittalURN( RAIFImplTransmittal xmittal,
                                const string &xmittal_urn )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
    {
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (xmittal_urn.length() >= MAX_XMTL_URN_LEN)
    {
        fprintf(stderr, "Error - URN length must be less than %d characters\n",
                MAX_XMTL_URN_LEN);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        xmtl->SetXmtlURN(XMTL_URN(xmittal_urn));
        return SE_STATCODE_SUCCESS;
    }
}

SE_Status_Code
STF_XmtlMngr::GetUniqueTransmittalId( RAIFImplTransmittal xmittal,
                                      string &id )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);
    SE_GUID guid;

    if (!xmtl || !xmtl->GetGUID((SE_Byte_Unsigned *)&guid))
        return SE_STATCODE_INACTIONABLE_FAILURE;

    char tmp[(SE_GUID_SIZE*2)+10];

    GUID_Print((SE_Byte_Unsigned *)guid, tmp);
    id = tmp;

    return SE_STATCODE_SUCCESS;
}

// make an STF_Object object from the ori object
//
SE_Status_Code
STF_XmtlMngr::GetObjectReference
(
     ObjRefInfo       &ori,
     ObjectReference *&objref
)
{
    STF_Object *stf_obj = new STF_Object( *(XFBO *)&ori);

    // Load in the association counts for this object. Wait to load the
    // fields til they ask for them.
    //
    if (stf_obj->IsResolved())
    {
        stf_obj->LoadObjHdr();
    }
    objref = (ObjectReference*)stf_obj;

    return SE_STATCODE_SUCCESS;
}

bool
STF_XmtlMngr::ReserveObject
(
    XFBO                      &xfbo,
    XmtlIndxType               xmtlIndx,
    SE_Short_Integer_Unsigned  objType,
    bool                       isConverterMode
)
{
    STF_Xmtl *stf_xmtl = GetXmtl( xmtlIndx );

    if (!stf_xmtl || !stf_xmtl->ReserveObject(xfbo, objType, isConverterMode))
    {
        return false;
    }
    return true;
}

SE_Status_Code
STF_XmtlMngr::CreateTransmittalObject
(
    RAIFImplTransmittal   xmittal,
    SE_DRM_Class          tag,
    ObjRefInfo          *&ori
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
    {
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!xmtl->IsEditable())
    {
// $$$ set error msg
        return SE_STATCODE_INVALID_ACCESS_MODE;
    }
    XFBO xfbo;

    if (!ReserveObject(xfbo, xmtl->GetXmtlIndx(), tag))
    {
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        xfbo.SetObjType(tag);

        XFBO *t_ori = (XFBO *)GetDummyORI();
        *t_ori = xfbo;
        ori = (ObjRefInfo *)t_ori;
        return SE_STATCODE_SUCCESS;
    }
}

// this can't use a resolving transmittal name as the default rsl name
// since this is an api call.
//
SE_Status_Code
STF_XmtlMngr::ResolveTransmittalURN
(
    const string &xmittal_urn,
          string &file_name
)
{
    return (ResolveURN(XMTL_URN(xmittal_urn), file_name) ?
            SE_STATCODE_SUCCESS : SE_STATCODE_UNRESOLVED_TRANSMITTAL);
}

bool
STF_XmtlMngr::ResolveURN
(
    const XMTL_URN &xmtl_urn,
          string   &xmtl_loc,
          STF_Xmtl *from_xmtl
)
{
    string file_path, file_name, rsl_file;

    xmtl_loc = "";

    if (from_xmtl)
    {
        // first try using the passed-in transmittal's path and file name
        file_path = FileUtils::GetPathOnly(from_xmtl->GetAbsolutePath());
        file_name = FileUtils::GetFileOnlyNoExt(from_xmtl->GetAbsolutePath());
        rsl_file = FileUtils::CombinePaths(file_path, file_name);
        rsl_file += ".rsl";

        xmtl_loc = UrnResolver::Resolve(xmtl_urn, URN_CURR_VERSION,
                                    rsl_file);

        if (xmtl_loc.empty())
        {
            // Now try using the default SEDRIS RSL file in the
            // transmittal's path
            rsl_file = FileUtils::CombinePaths(file_path, URN_SEDRIS_FILE);

            xmtl_loc = UrnResolver::Resolve(xmtl_urn,
                                            URN_CURR_VERSION, rsl_file);
        }
    }

    // try by creating rsl files from all the open transmittals,
    // by forming the resolver file name through the combination of
    // the transmittal's absolute path and the transmittal root file
    // name with ".rsl" appended (without the ".stf" part).
    for (unsigned int x=0; xmtl_loc.empty() && x < XmtlList.size(); x++)
    {
        STF_Xmtl *xmtl = XmtlList[x];

        if (!xmtl || xmtl->IsInternal())
            continue;

        file_path = FileUtils::GetPathOnly(xmtl->GetAbsolutePath());
        file_name = FileUtils::GetFileOnlyNoExt(xmtl->GetAbsolutePath());
        rsl_file = FileUtils::CombinePaths(file_path, file_name);
        rsl_file += ".rsl";

        xmtl_loc = UrnResolver::Resolve(xmtl_urn,
                                            URN_CURR_VERSION, rsl_file);

        if (xmtl_loc.empty())
        {
            rsl_file = FileUtils::CombinePaths(file_path, URN_SEDRIS_FILE);

            xmtl_loc = UrnResolver::Resolve(xmtl_urn,
                                            URN_CURR_VERSION, rsl_file);
        }

        if (!xmtl_loc.empty())
            break;
    }

    if (xmtl_loc.empty() && !SedrisResPaths.empty())
    {
        // try by using the default "sedris.rsl" filename and looking
        // through the environment-provided resolver paths.

        xmtl_loc = UrnResolver::ResolvePaths(xmtl_urn, URN_CURR_VERSION,
                                        URN_SEDRIS_FILE, SedrisResPaths);
    }

    if (!xmtl_loc.empty())
        xmtl_loc = FileUtils::PurgeFileProtocol(xmtl_loc);

    return !xmtl_loc.empty();
}

SE_Status_Code
STF_XmtlMngr::ResolveObject
(
    XFBO     &xfbo,
    STF_Xmtl *from_xmtl
)
{
    if (xfbo.IsResolved())
        return SE_STATCODE_SUCCESS;

    XMTL_URN xmtl_urn = xfbo.GetXmtlURN();

    // first see if the transmittal is already opened
    XmtlIndxType  xmtl_indx = GetXmtlIndx(xmtl_urn);
    STF_Xmtl     *xmtl = NULL;

    if ((xmtl_indx == XMTL_INDX_NOT_SET) ||
        ((xmtl=GetXmtl(xmtl_indx)) == NULL))
    {
        // not opened, try to resolve and open internally
        string xmtl_fname;

        if (!ResolveURN(xmtl_urn, xmtl_fname, from_xmtl))
            return SE_STATCODE_UNRESOLVED_TRANSMITTAL;

        // by default internally opened transmittals are opened read-only,
        // but if the user laters asks for the same transmittal to be
        // opened in a different mode we will re-open it.
        SE_Status_Code sts = InternalOpenTransmittal(xmtl_fname,
                                            SE_AM_READ_ONLY, xmtl, true);

        if (sts != SE_STATCODE_SUCCESS)
            return sts;
    }

    // use the object label to look up the xfbo in the pub obj list
    //
    if (xmtl != NULL)
    {
        XFBO pub_obj;

        if (xmtl->GetPublishedObjRef(xfbo.GetObjLabel(), pub_obj))
        {
            // create an STF_Object to get the type
            //
            STF_Object itr_obj(pub_obj);

            pub_obj.SetObjType(itr_obj.GetObjType());
            xfbo = pub_obj;
        }
        else
        {
            fprintf(stderr, "STF: Invalid ITR Reference: "\
                "xmtl %s does not have a published object %s.\n",
                xmtl_urn.c_str(), xfbo.GetObjLabel().c_str());
        }
    }
    return (xfbo.IsResolved()? SE_STATCODE_SUCCESS
                : SE_STATCODE_INACTIONABLE_FAILURE);
}

SE_Status_Code
STF_XmtlMngr::ResolveObject( const XFBO &from_xfbo, XFBO &xfbo )
{
    STF_Xmtl *xmtl = GetXmtl(from_xfbo.GetXmtlIndx());

    return (xmtl ? ResolveObject(xfbo, xmtl)
                : SE_STATCODE_INACTIONABLE_FAILURE);
}

SE_Status_Code
STF_XmtlMngr::ResolveObject
(
    const string      &xmittal_name,
    const string      &obj_label,
          ObjRefInfo *&ori
)
{
    XFBO xfbo(xmittal_name, obj_label);
    SE_Status_Code sts = ResolveObject(xfbo);

    if (sts == SE_STATCODE_SUCCESS && xfbo.IsResolved())
    {
        XFBO *t_ori = (XFBO *)GetDummyORI();
        *t_ori = xfbo;
        ori = (ObjRefInfo *)t_ori;
    }
    else
        ori = NULL;

    return sts;
}

SE_Status_Code
STF_XmtlMngr::ResolveObject( ObjRefInfo &ori )
{
    XFBO &xfbo = (XFBO &)ori;

    return ResolveObject(xfbo);
}

SE_Status_Code
STF_XmtlMngr::GetObjectIDString( ObjRefInfo &ori, string &id_string )
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    XFBO &xfbo = (XFBO &)ori;

    if (xfbo.IsResolved())
    {
        STF_Xmtl *xmtl = GetXmtl( xfbo );

        if (xmtl)
        {
            char tmp_object_id_string[1000];

            sprintf(tmp_object_id_string, "%s:%d,%d,%d",
                    UrnResolver::MangleUrn(xmtl->GetXmtlURN()).c_str(),
                    xfbo.GetMFTIndx(), xfbo.GetBlkIndx(), xfbo.GetObjIndx());

            id_string = tmp_object_id_string;
        }
        else
        {
            fprintf(stderr, "STF: GetIDForObject:"\
                    "can't get xmtl for obj_ref\n" );
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    else
    {
        status = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
    }
    return status;
}

// this method sets the ori to point to static memory within this class
// if the caller wants to save the ori, he needs to copy it.
//
SE_Status_Code
STF_XmtlMngr::GetObjRefFromIDString
(
          RAIFImplTransmittal   xmittal,
    const string               &id_string,
          ObjRefInfo          *&ori
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
    {
        fprintf(stderr, "STF: GetObjRefFromIDString: Invalid xmtl\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (id_string.length() >= RAIF_MAX_OBJ_ID_STRING_SIZE)
    {
        fprintf(stderr, "STF: GetObjRefFromIDString: Object ID too long\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    SE_Integer_Unsigned findx, bindx, oindx;
    XmtlIndxType xindx = xmtl->GetXmtlIndx();

    // The ID looks like " xmtl name:fileIndex,blockIndex,objectIndex"
    // We will first grab a copy of the string to work with.
    // Then we will go to the last colon and get the numbers
    // Then put in the null character and read the xmittal name.
    //
    char tmp_object_id_string[RAIF_MAX_OBJ_ID_STRING_SIZE + 1];
    char *temp_id=tmp_object_id_string, *temp_char;

    strcpy(temp_id, id_string.c_str());

    temp_char = strrchr(temp_id,':');

    // if there is no : delimiter then fail
    //
    if (temp_char == NULL)
    {
        fprintf(stderr, "STF: GetObjRefFromIDString: invalid object ID \"%s\" "
            "(missing ':')\n", id_string.c_str());
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if (sscanf(temp_char, ":%u,%u,%u", &findx, &bindx, &oindx ) != 3)
    {
        fprintf(stderr, "STF: GetObjRefFromIDString: invalid object ID \"%s\" "
            "(can't read all indices)\n", id_string.c_str());
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    *temp_char = '\0';

    // $$$ should decode the URN part, when we start encoding it
    // if a urn is given in the object id, then check it against
    // the transmittal
    // (temp_id is now the transmittal urn portion of the id)
    //
    if (temp_char != temp_id)
    {
        if (!(UrnResolver::MangleUrn(xmtl->GetXmtlURN()) == temp_id))
        {
            fprintf(stderr,"STF: GetObjRefFromIDString: Object ID \"%s\" "
                "is not for transmittal with URN \"%s\"\n",
                id_string.c_str(), xmtl->GetXmtlURN().c_str());

            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    // validate all the indices
    //
    if (findx >= xmtl->GetNumberOfFiles())
    {
        fprintf(stderr, "STF: GetObjRefFromIDString: invalid object ID \"%s\" "
            "(bad file index = %u)\n", id_string.c_str(), findx);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    STF_Block *blk = STF_BlockMngr::FetchBlock(xindx, findx, bindx);

    if (blk == NULL)
    {
        fprintf(stderr, "STF: GetObjRefFromIDString:"
            "Invalid block index %u from ObjectID %s.\n",
            oindx, id_string.c_str() );
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (oindx >= blk->GetNumObjects())
    {
        fprintf(stderr, "STF: GetObjRefFromIDString:"
            "Invalid object index %u from ObjectID %s.\n",
            oindx, id_string.c_str() );
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (blk->IsObjectDeleted(oindx))
    {
        fprintf(stderr, "STF: GetObjRefFromIDString: invalid object ID \"%s\" "
            "(object is deleted)\n", id_string.c_str());
        return SE_STATCODE_DELETED_OBJECT;
    }
    // return a pointer to static memory
    //
    XFBO *t_ori = (XFBO *)GetDummyORI();

    t_ori->SetXmtlIndx((XmtlIndxType)xindx);
    t_ori->SetMFTIndx((MFTIndxType)findx);
    t_ori->SetBlkIndx((BlkIndxType)bindx);
    t_ori->SetObjIndx((ObjIndxType)oindx);
    t_ori->SetObjType(OBJ_TYPE_NOT_SET);

    ori = (ObjRefInfo *)t_ori;

    return SE_STATCODE_SUCCESS;
}

SE_Integer_Unsigned
STF_XmtlMngr::GetDTDValueSize( SE_Data_Table_Data_Value_Type vt )
{
   switch (vt)
   {
       case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT :
            return sizeof(EDCS_Long_Float);
       case SE_DTDATAVALTYP_LONG_FLOAT :
            return sizeof(EDCS_Long_Float_Value);
       case SE_DTDATAVALTYP_SINGLE_INTEGER :
            return sizeof(EDCS_Integer);
       case SE_DTDATAVALTYP_INTEGER :
            return sizeof(EDCS_Integer_Value);
       case SE_DTDATAVALTYP_SINGLE_COUNT :
       case SE_DTDATAVALTYP_INDEX :
            return sizeof(EDCS_Count);
       case SE_DTDATAVALTYP_COUNT :
            return sizeof(EDCS_Count_Value);
       case SE_DTDATAVALTYP_STRING :
       case SE_DTDATAVALTYP_CONSTRAINED_STRING :
       case SE_DTDATAVALTYP_KEY :
            return sizeof(EDCS_String);
       case SE_DTDATAVALTYP_ENUMERATION :
            return sizeof(EDCS_Enumerant_Code);
       case SE_DTDATAVALTYP_BOOLEAN :
            return sizeof(EDCS_Boolean);
       case SE_DTDATAVALTYP_INDEX_CODE :
            return sizeof(SE_Integer_Unsigned);
   }
   return 0;
}

SE_Integer_Unsigned
STF_XmtlMngr::GetDataTableDataValueSize( SE_Data_Table_Data_Value_Type vt )
{
    return GetDTDValueSize( vt );
}

SE_Status_Code
STF_XmtlMngr::GetMeshFaceTableData( ObjectReference *objref,
                            SE_Integer_Positive  start_face,
                            SE_Integer_Positive  num_faces,
                      const SE_Integer_Unsigned *mft_data_out,
                      const SE_Integer_Unsigned *adj_face_tbl_data_out )
{
    STF_Object *obj = (STF_Object*)objref;

    if (!obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_MFTData mftDataObj(obj);

    SE_Status_Code sts = mftDataObj.GetMFTData( SE_FALSE, start_face,
                                                num_faces, mft_data_out );

    if (sts == SE_STATCODE_SUCCESS)
    {
        if (adj_face_tbl_data_out != NULL)
        {
            sts = mftDataObj.GetMFTData( SE_TRUE, start_face, num_faces,
                                        adj_face_tbl_data_out );
        }
    }
    return sts;
}

SE_Status_Code
STF_XmtlMngr::PutMeshFaceTableData( ObjectReference *objref,
                            SE_Integer_Positive  start_face,
                            SE_Integer_Positive  num_faces,
                      const SE_Integer_Unsigned *mft_data_in,
                      const SE_Integer_Unsigned *adj_face_tbl_data_in )
{
    STF_Object *obj = (STF_Object*)objref;

    if (!obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!IsXmtlEditable(obj->GetXmtlIndx()) )
        return SE_STATCODE_INVALID_ACCESS_MODE;

    STF_MFTData mftDataObj(obj);

    SE_Status_Code sts = mftDataObj.PutMFTData( SE_FALSE, start_face,
                                                num_faces, mft_data_in );

    if (sts == SE_STATCODE_SUCCESS)
    {
        if (adj_face_tbl_data_in != NULL)
        {
            sts = mftDataObj.PutMFTData( SE_TRUE, start_face, num_faces,
                                        adj_face_tbl_data_in );
        }
    }
    return sts;
}

SE_Status_Code
STF_XmtlMngr::GetDataTableData( ObjectReference *objref,
                const SE_Data_Table_Sub_Extent  *extents_ptr,
                      SE_Integer_Positive element_count,
                const SE_Integer_Positive tpd_indices[],
                      SE_Data_Table_Data    *data_out )
{
    STF_Object *obj = (STF_Object*)objref;

    if (!obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_DataTable dataTblObj((STF_Object*)objref);

    SE_Status_Code sts = dataTblObj.GetData( extents_ptr,
                            element_count, tpd_indices, data_out );
    return sts;
}

SE_Status_Code
STF_XmtlMngr::PutDataTableData( ObjectReference *objref,
                const SE_Data_Table_Sub_Extent  *extents_ptr,
                      SE_Integer_Unsigned element_count,
                const SE_Integer_Positive tpd_indices[],
                const SE_Data_Table_Data    *data_in )
{
    STF_Object *obj = (STF_Object*)objref;

    if (!obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!IsXmtlEditable(obj->GetXmtlIndx()))
        return SE_STATCODE_INVALID_ACCESS_MODE;

    STF_DataTable dataTblObj(obj);

    SE_Status_Code sts = dataTblObj.PutData( extents_ptr,
        element_count, tpd_indices, data_in );

    return sts;
}

SE_Status_Code
STF_XmtlMngr::GetImageData
(
          ObjectReference           *objref,
          SE_Short_Integer_Unsigned  mip_level,
    const SE_Data_Table_Sub_Extent  *img_extents,
    const SE_Image_Data             *data_out
)
{
    STF_Object *obj = (STF_Object*)objref;

    if (!obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_Image imgObj(obj);

    return imgObj.GetImageData(mip_level, img_extents, data_out);
}

SE_Status_Code
STF_XmtlMngr::PutImageData
(
          ObjectReference           *objref,
          SE_Short_Integer_Unsigned  mip_level,
    const SE_Data_Table_Sub_Extent  *img_extents,
    const SE_Image_Data             *data_in
)
{
    STF_Object *obj = (STF_Object*)objref;

    if (!obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!IsXmtlEditable(obj->GetXmtlIndx()))
        return SE_STATCODE_INVALID_ACCESS_MODE;

    STF_Image imgObj(obj);

    return imgObj.PutImageData(mip_level, img_extents, data_in);
}

// methods to get and set the root object reference information
// (RAIF checks the Access mode)
//
SE_Status_Code
STF_XmtlMngr::SetRootObject( RAIFImplTransmittal xmittal, ObjRefInfo &ori )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);
    XFBO &xfbo = (XFBO &) ori;

    if (!xmtl || xmtl->GetXmtlIndx() != xfbo.GetXmtlIndx())
    {
        // $$$ set err msg
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if (!xmtl->IsEditable())
        return SE_STATCODE_INVALID_ACCESS_MODE;
    else if (!xmtl->SetRootObject(xfbo) )
        return SE_STATCODE_INACTIONABLE_FAILURE;

    return SE_STATCODE_SUCCESS;
}

// This returns a pointer to memory within the STF_Xmtl. This
// should NOT be freed.
//
SE_Status_Code
STF_XmtlMngr::GetRootObject
(
    RAIFImplTransmittal   xmittal,
    ObjRefInfo          *&ori
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    if (xmtl->GetRootObject().CheckIndxs() )
    {
        ori = (ObjRefInfo *)&(xmtl->GetRootObject());
        return SE_STATCODE_SUCCESS;
    }
    else
    {
        ori = NULL;
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
}

SE_Access_Mode
STF_XmtlMngr::GetAccessMode( RAIFImplTransmittal xmittal )
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_AM_READ_ONLY;

    return xmtl->GetXmtlAccess();
}

SE_Status_Code
STF_XmtlMngr::RemoveTransmittalObject
(
    RAIFImplTransmittal  xmittal,
    ObjectReference     *objref
)
{
    // Here we must pass-in an ObjectReference as opposed an ObjRefInfo
    // because the object must have been already loaded into memory, and
    // we want to modify only one version of it.
    STF_Object *stf_obj = (STF_Object *)objref;
    STF_Xmtl   *xmtl = GetXmtl(xmittal);

    if (!xmtl || !stf_obj)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!xmtl->IsEditable())
        return SE_STATCODE_INVALID_ACCESS_MODE;
    else if (!stf_obj->CheckIndxs())
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (xmtl->GetXmtlIndx() != stf_obj->GetXmtlIndx())
    {
        fprintf(stderr, "STF_XmtlMngr::RemoveTransmittalObject: "\
          "object does not belong to the transmittal passed in\n");
        fflush(stderr);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    ObjIndxType    obj_indx = stf_obj->GetObjIndx();
    STF_Block     *blk = STF_BlockMngr::FetchBlock(stf_obj);
    SE_Status_Code sts = SE_STATCODE_SUCCESS;

    if (!blk)
    {
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_IsA[stf_obj->GetObjType()][SE_CLS_DRM_DATA_TABLE])
    {
        STF_DataTable dataTblObj(stf_obj);

        sts = dataTblObj.RemoveDataTableData();
    }
    else if (SE_IsA[stf_obj->GetObjType()][SE_CLS_DRM_IMAGE])
    {
        STF_Image imgObj(stf_obj);

        sts = imgObj.RemoveImageData();
    }
    else if (SE_IsA[stf_obj->GetObjType()][SE_CLS_DRM_MESH_FACE_TABLE])
    {
        STF_MFTData mftObj(stf_obj);

        sts = mftObj.RemoveMFTData();
    }

    if (sts == SE_STATCODE_SUCCESS)
        blk->RemoveObject(obj_indx);

    return sts;
}

SE_Status_Code
STF_XmtlMngr::PublishObject( ObjRefInfo &ori, const string &label )
{
    // $$$ what if this label has already been used to publish an object?
    //
    XFBO &xfbo = (XFBO &)ori;

    if (!xfbo.CheckIndxs() || label.empty())
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_Xmtl *xmtl = GetXmtl(xfbo.GetXmtlIndx());

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!xmtl->IsEditable() )
        return SE_STATCODE_INVALID_ACCESS_MODE;
    else
        return (xmtl->PublishObject( xfbo, label ) ? SE_STATCODE_SUCCESS :
            SE_STATCODE_INACTIONABLE_FAILURE );
}

SE_Status_Code
STF_XmtlMngr::UnpublishObject( ObjRefInfo &ori, const string &label )
{
    XFBO &xfbo = (XFBO &)ori;

    if (!xfbo.CheckIndxs())
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_Xmtl *xmtl = GetXmtl(xfbo.GetXmtlIndx());

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!xmtl->IsEditable())
        return SE_STATCODE_INVALID_ACCESS_MODE;
    else
        return (xmtl->UnpublishObject( xfbo, label ) ?
            SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);
}

SE_Boolean
STF_XmtlMngr::IsPublished( ObjRefInfo &ori )
{
   SE_Integer_Unsigned num_labels = 0;

   GetPubLabels(ori, num_labels);

   return (num_labels > 0? SE_TRUE : SE_FALSE);
}

SE_Status_Code
STF_XmtlMngr::GetPubLabels
(
    ObjRefInfo          &ori,
    SE_Integer_Unsigned &num_labels,
    string              *label_list_data
)
{
    XFBO &xfbo = (XFBO &)ori;

    STF_Xmtl *xmtl = GetXmtl(xfbo.GetXmtlIndx());

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!xmtl->GetLabelsForPubObj(xfbo, num_labels, label_list_data))
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else
        return SE_STATCODE_SUCCESS;
}

SE_Status_Code
STF_XmtlMngr::GetPubObjectList
(
    RAIFImplTransmittal   xmittal,
    SE_Integer_Unsigned  &num_objects,
    ObjRefInfo          **obj_list_data
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!xmtl->GetPublishedObjects(num_objects, (XFBO**)obj_list_data))
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else
        return SE_STATCODE_SUCCESS;
}

// trans_list_data points to a contiguous memory which is large enough
// for num_xmittal urns of size MAX_URN_SIZE
//
SE_Status_Code
STF_XmtlMngr::GetRefTransmittalList
(
    RAIFImplTransmittal  xmittal,
    SE_Integer_Unsigned &num_xmittals,
    string              *trans_list_data
)
{
    STF_Xmtl *xmtl = GetXmtl(xmittal);

    if (!xmtl)
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else if (!xmtl->GetRefdXmtlList(num_xmittals, trans_list_data))
        return SE_STATCODE_INACTIONABLE_FAILURE;
    else
        return SE_STATCODE_SUCCESS;
}

// return the index into the itr ref obj list of the referenced obj.
// It is assumed that the refd xmtl urn and the object label in the
// to_xfbo have already been set.

// create entries in the refd obj and refd xmtls lists if neccessary.
//
ITRIndxType
STF_XmtlMngr::GetITRindx( XmtlIndxType xmtlIndx, const XFBO &to_xfbo )
{
    XmtlIndxType refd_xmtl_indx;                // indx into the refd xmtl list
    ITRIndxType  itr_indx=ITR_INDX_NOT_SET;     // indx into itr refd obj list

    STF_Xmtl *from_xmtl = GetXmtl( xmtlIndx );

    if (!from_xmtl) return ITR_INDX_NOT_SET;

    // get the object label and the urn name for the transmittal.
    //
    // (if the object has been resolved then we assume that its
    //  RefdXmtlName and Object Label's are both valid. unresolved objects
    //  should only exist with a xmtl name/obj label.)
    //
    XMTL_URN xmtl_urn = to_xfbo.GetXmtlURN();
    string obj_label = to_xfbo.GetObjLabel();

    if (xmtl_urn.empty() || obj_label.empty())
        return ITR_INDX_NOT_SET;

    // if the xmtl is not in the refd xmtl list then this will add it.
    //
    refd_xmtl_indx = from_xmtl->GetRefdXmtlIndx( xmtl_urn );

    // if obj_label is not in the itr refd obj list then this will add it.
    //
    itr_indx = from_xmtl->GetITRindx( obj_label, refd_xmtl_indx );

    return itr_indx;
}

ObjRefInfo *
STF_XmtlMngr::GetDummyORI()
{
    static unsigned int i=0;

    return (ObjRefInfo *)&dmy_ori[(++i)%10];
}
