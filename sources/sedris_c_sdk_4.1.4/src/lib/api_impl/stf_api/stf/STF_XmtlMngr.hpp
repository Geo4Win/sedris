// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_XmtlMngr.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_XmtlMngr
//    this is a singleton class which manages the other stf_xmtls and
//    the block cache.
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

#ifndef STF_XMTL_MNGR_HPP_INCLUDED
#define STF_XMTL_MNGR_HPP_INCLUDED

#include "stf_core.hpp"
#include "XFBO.hpp"

namespace STF_NAMESPACE {

class STF_Xmtl;
class STF_File;

// the urn_lookup_map is a mechanism to store urn locations so that
// urns need only be resolved once.
//
class URN_MapEntry
{
public:
    URN_MapEntry()
        : xmtlIndx(XMTL_INDX_NOT_SET)
    {
    }

    URN_MapEntry( const string &loc, XmtlIndxType xmtl_indx )
        : location(loc), xmtlIndx(xmtl_indx)
    {
    }

    string location;
    XmtlIndxType xmtlIndx;
};

typedef map < XMTL_URN, URN_MapEntry > URN_Map;

//
// Note: ALL non-static methods of this class are pure-virtual methods
//       of the FACTORY class.
//
class STF_XmtlMngr : public FACTORY
{
public:
    static STF_XmtlMngr *CreateXmtlMngr(void);

    static void DestroyXmtlMngr(void);

    // FACTORY - start
    virtual SE_Boolean     ValidEncoding( SE_Encoding encoding );

    virtual SE_Status_Code GetEncoding( SE_Encoding *encoding );

    virtual SE_Integer_Unsigned RecommendHashTableSize(void)
    {
        return hashTblSize;
    }

    virtual SE_Status_Code OpenTransmittal( const string &file_name,
                                            SE_Access_Mode access_mode,
                                            RAIFImplTransmittal &xmittal );

    virtual SE_Status_Code DefragTransmittal(RAIFImplTransmittal xmittal,
                                             bool                verbose );
    virtual SE_Status_Code RenameTransmittal(RAIFImplTransmittal xmittal,
                                             const string &new_file_name );
    virtual SE_Status_Code FlushTransmittal( RAIFImplTransmittal xmittal );

    virtual SE_Status_Code CloseTransmittal( RAIFImplTransmittal xmittal );

    virtual SE_Integer_Unsigned NumOfOpenTransmittals(void);

    virtual SE_Status_Code GetUniqueTransmittalId( RAIFImplTransmittal xmittal,
                                            string &id );

    virtual SE_Access_Mode GetAccessMode( RAIFImplTransmittal xmittal );

    virtual SE_Status_Code GetTransmittalFile(RAIFImplTransmittal  xmittal,
                                              string              &file_name );

    virtual SE_Status_Code GetTransmittalURN( RAIFImplTransmittal xmittal,
                                            string &xmittal_urn );

    virtual SE_Status_Code SetTransmittalURN( RAIFImplTransmittal xmittal,
                                            const string &xmittal_urn );

    virtual SE_Status_Code GetPubObjectList( RAIFImplTransmittal xmittal,
                                        SE_Integer_Unsigned &num_objects,
                                        ObjRefInfo **obj_list_data=NULL );

    virtual SE_Status_Code GetRefTransmittalList( RAIFImplTransmittal xmittal,
                                        SE_Integer_Unsigned &num_xmittals,
                                        string *trans_list_data=NULL );

    virtual SE_Status_Code ResolveTransmittalURN( const string &xmittal_urn,
                                            string &file_name );

    virtual SE_Boolean SameTransmittal( RAIFImplTransmittal trans_a,
                                        RAIFImplTransmittal trans_b );

    virtual SE_Status_Code GetRootObject(RAIFImplTransmittal   xmittal,
                                         ObjRefInfo          *&ori);

    virtual SE_Status_Code SetRootObject(RAIFImplTransmittal xmittal,
                                        ObjRefInfo &ori );

    virtual SE_Status_Code ResolveObject(const string      &xmittal_urn,
                                         const string      &obj_label,
                                               ObjRefInfo *&ori);

    virtual SE_Status_Code ResolveObject( ObjRefInfo &ori );

    virtual SE_Boolean IsPublished( ObjRefInfo &ori );

    virtual SE_Status_Code CreateTransmittalObject( RAIFImplTransmittal xmittal,
                                            SE_DRM_Class tag,
                                            ObjRefInfo *&ori );

    virtual SE_Status_Code RemoveTransmittalObject( RAIFImplTransmittal xmittal,
                                            ObjectReference *objref );

    virtual SE_Status_Code GetTransmittalFromObject( ObjRefInfo &ori,
                                            RAIFImplTransmittal &xmittal );

    virtual SE_Status_Code PublishObject( ObjRefInfo &ori,
                                        const string &label );

    virtual SE_Status_Code UnpublishObject( ObjRefInfo &ori,
                                        const string &label );

    virtual SE_Status_Code GetPubLabels( ObjRefInfo &ori,
                                        SE_Integer_Unsigned &num_labels,
                                        string *label_list_data=NULL );

    virtual SE_Status_Code GetObjectIDString( ObjRefInfo &ori,
                                            string &id_string );

    virtual SE_Status_Code GetObjRefFromIDString( RAIFImplTransmittal xmittal,
                                            const string      &id_string,
                                                  ObjRefInfo *&ori );

    virtual SE_Status_Code GetObjectReference(ObjRefInfo       &ori,
                                              ObjectReference *&objref);

    // Bulk data methods

    virtual SE_Integer_Unsigned
            GetDataTableDataValueSize( SE_Data_Table_Data_Value_Type vt );

    virtual SE_Status_Code GetDataTableData( ObjectReference *objref,
                   const SE_Data_Table_Sub_Extent  *extents_ptr,
                         SE_Integer_Positive        element_count,
                   const SE_Integer_Positive        tpd_indices[],
                         SE_Data_Table_Data        *data_out );

    virtual SE_Status_Code PutDataTableData( ObjectReference *objref,
                   const SE_Data_Table_Sub_Extent  *extents_ptr,
                         SE_Integer_Unsigned    element_count,
                   const SE_Integer_Positive    tpd_indices[],
                   const SE_Data_Table_Data    *data_in );

    virtual SE_Status_Code GetImageData( ObjectReference *objref,
                         SE_Short_Integer_Unsigned mip_level,
                   const SE_Data_Table_Sub_Extent *img_extents,
                   const SE_Image_Data      *data_out );

    virtual SE_Status_Code PutImageData( ObjectReference *objref,
                         SE_Short_Integer_Unsigned mip_level,
                   const SE_Data_Table_Sub_Extent *img_extents,
                   const SE_Image_Data      *data_in );

    virtual SE_Status_Code GetMeshFaceTableData( ObjectReference *objref,
                         SE_Integer_Positive  start_face,
                         SE_Integer_Positive  num_faces,
                   const SE_Integer_Unsigned *mft_data_out,
                   const SE_Integer_Unsigned *adj_face_tbl_data_out );

    virtual SE_Status_Code PutMeshFaceTableData( ObjectReference *objref,
                         SE_Integer_Positive  start_face,
                         SE_Integer_Positive  num_faces,
                   const SE_Integer_Unsigned *mft_data_in,
                   const SE_Integer_Unsigned *adj_face_tbl_data_in );

    // Error handling methods
    virtual void   FlushErrorDescription(void)
    {
        errorDescription = "";
    }
    virtual const string &GetErrorDescription(void)
    {
        return errorDescription;
    }

    // FACTORY - end

    static SE_Status_Code ResolveObject( const XFBO &from_xfbo, XFBO &xfbo );

    static MachineArchType GetEndian(void)  { return endian; }
    static void SetEndian( MachineArchType e ) { endian = e; }

    static int GetMaxOpenFiles(void) { return maxOpenFiles; }
    static int GetFileSizeThreshold(void) { return fileSizeThreshold; }
    static int GetBulkDataBlockSize(void) { return bulkDataBlockSize; }
    static SE_Integer_Unsigned GetDTDValueSize( SE_Data_Table_Data_Value_Type vt );

    static STF_File    *GetFile( XmtlIndxType xmtl, MFTIndxType file );
    static STF_File    *GetFile( XFBO &xfbo );
    static STF_Xmtl    *GetXmtl( XmtlIndxType xmtlIndx );
    static STF_Xmtl    *GetXmtl( XFBO &xfbo );
    static STF_Xmtl    *GetXmtl( RAIFImplTransmittal xmittal );
    static ITRIndxType  GetITRindx( XmtlIndxType xmtlIndx, const XFBO &to_xfbo );

    static bool IsXmtlEditable( XmtlIndxType xmtlIndx );

    static bool ReserveObject( XFBO &xfbo, XmtlIndxType xmtlIndx=currXmtl,
                                    SE_Short_Integer_Unsigned objType=0,
                                    bool isConverterMode = false );

    static ObjRefInfo *GetDummyORI(void);

    // Error handling methods
    static void AddErrorDescription(const string &err_descr_str)
    {
        errorDescription += err_descr_str;
    }

protected:
    STF_XmtlMngr();
    virtual ~STF_XmtlMngr();

    static SE_Status_Code InternalOpenTransmittal( const string &file_name,
                                                         SE_Access_Mode access_mode,
                                                         STF_Xmtl * &xmittal,
                                                         bool internal_xmtl=false);

    static SE_Status_Code ResolveObject( XFBO &xfbo, STF_Xmtl *from_xmtl=NULL );

    static bool ResolveURN( const XMTL_URN &xmtl_urn,
                            string &xmtl_loc, STF_Xmtl *from_xmtl=NULL );

    static XmtlIndxType GetXmtlIndx( const XMTL_URN &xmtl_urn );

    static MachineArchType endian;
    static SE_Integer_Unsigned hashTblSize;
    static XFBO dmy_ori[10]; // used by GetObjectFromID to return an ori

    static vector <STF_Xmtl*> XmtlList;
    static vector <string> XmtlNameList;  // also indexed by xmtlIndx
    static XmtlIndxType currXmtl;   // the last opened writeable xmtl

    // keeps track of which urns have been resolved.
    //
    static URN_Map urn_lookup_map;
    static string SedrisResPaths;

    static SE_Integer           maxOpenFiles;
    static SE_Integer_Unsigned  fileSizeThreshold;
    static SE_Integer_Unsigned  bulkDataBlockSize;

    // Error handling methods
    static string               errorDescription;
};

} // STF_NAMESPACE

#endif // STF_XMTL_MNGR_HPP_INCLUDED
