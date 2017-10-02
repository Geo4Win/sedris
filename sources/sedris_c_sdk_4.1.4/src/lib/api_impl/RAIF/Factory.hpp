// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        Factory.hpp
//
// PROGRAMMERS: Jesse Campos (SAIC)
//
// DESCRIPTION:  Class header for Factory class.  This class instantiates
//        object references and objects.  It is an abstract class
//        that all implementations will derive from.
//
//
// - API spec. 4.1
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#ifndef _SE_FACTORY_HPP_INCLUDED
#define _SE_FACTORY_HPP_INCLUDED

#include "se_insert_types.h"

#include "se_STL_includes.h"
#include "RAIFTypes.hpp"

class ObjectReference;
class ObjRefInfo;

class FACTORY
{
  public:

    virtual SE_Boolean     ValidEncoding( SE_Encoding encoding )=0;

    virtual SE_Status_Code GetEncoding( SE_Encoding *encoding )=0;

    virtual SE_Integer_Unsigned RecommendHashTableSize(void)=0;

    virtual SE_Status_Code OpenTransmittal( const string &file_name,
                                            SE_Access_Mode access_mode,
                                            RAIFImplTransmittal &xmittal )=0;

    virtual SE_Status_Code DefragTransmittal( RAIFImplTransmittal xmittal,
                                             bool verbose )=0;
    virtual SE_Status_Code RenameTransmittal( RAIFImplTransmittal xmittal,
                                            const string &new_file_name )=0;
    virtual SE_Status_Code FlushTransmittal( RAIFImplTransmittal xmittal )=0;

    virtual SE_Status_Code CloseTransmittal( RAIFImplTransmittal xmittal )=0;

    virtual SE_Integer_Unsigned NumOfOpenTransmittals(void)=0;

    virtual SE_Status_Code GetUniqueTransmittalId( RAIFImplTransmittal xmittal,
                                            string &id )=0;

    virtual SE_Access_Mode GetAccessMode( RAIFImplTransmittal xmittal )=0;

    virtual SE_Status_Code GetTransmittalFile( RAIFImplTransmittal xmittal,
                                            string &file_name )=0;

    virtual SE_Status_Code GetTransmittalURN( RAIFImplTransmittal xmittal,
                                            string &xmittal_urn )=0;

    virtual SE_Status_Code SetTransmittalURN( RAIFImplTransmittal xmittal,
                                            const string &xmittal_urn )=0;

    virtual SE_Status_Code GetPubObjectList( RAIFImplTransmittal xmittal,
                                        SE_Integer_Unsigned &num_objects,
                                        ObjRefInfo **obj_list_data=NULL )=0;

    virtual SE_Status_Code GetRefTransmittalList( RAIFImplTransmittal xmittal,
                                        SE_Integer_Unsigned &num_xmittals,
                                        string *trans_list_data=NULL )=0;

    virtual SE_Status_Code ResolveTransmittalURN( const string &xmittal_urn,
                                            string &file_name )=0;

    virtual SE_Boolean SameTransmittal( RAIFImplTransmittal trans_a,
                                        RAIFImplTransmittal trans_b )=0;

    virtual SE_Status_Code GetRootObject(RAIFImplTransmittal   xmittal,
                                         ObjRefInfo          *&ori)=0;

    virtual SE_Status_Code SetRootObject(RAIFImplTransmittal xmittal,
                                        ObjRefInfo &ori )=0;

    virtual SE_Status_Code ResolveObject(const string      &xmittal_urn,
                                         const string      &obj_label,
                                               ObjRefInfo *&ori )=0;

    virtual SE_Status_Code ResolveObject( ObjRefInfo &ori )=0;

    virtual SE_Boolean IsPublished( ObjRefInfo &ori )=0;

    virtual SE_Status_Code CreateTransmittalObject(RAIFImplTransmittal xmittal,
                                                   SE_DRM_Class   tag,
                                                   ObjRefInfo   *&ori )=0;

    virtual SE_Status_Code RemoveTransmittalObject( RAIFImplTransmittal xmittal,
                                            ObjectReference *objref )=0;

    virtual SE_Status_Code GetTransmittalFromObject( ObjRefInfo &ori,
                                            RAIFImplTransmittal &xmittal )=0;

    virtual SE_Status_Code PublishObject( ObjRefInfo &ori,
                                        const string &label )=0;

    virtual SE_Status_Code UnpublishObject( ObjRefInfo &ori,
                                        const string &label )=0;

    virtual SE_Status_Code GetPubLabels( ObjRefInfo &ori,
                                        SE_Integer_Unsigned &num_labels,
                                        string *label_list_data=NULL )=0;

    virtual SE_Status_Code GetObjectIDString( ObjRefInfo &ori,
                                            string &id_string )=0;

    virtual SE_Status_Code GetObjRefFromIDString(RAIFImplTransmittal xmittal,
                                           const string      &id_string,
                                                 ObjRefInfo *&ori )=0;

    virtual SE_Status_Code GetObjectReference(ObjRefInfo       &ori,
                                              ObjectReference *&objref)=0;

    // Bulk data methods

    virtual SE_Integer_Unsigned
            GetDataTableDataValueSize( SE_Data_Table_Data_Value_Type vt )=0;

    virtual SE_Status_Code GetDataTableData( ObjectReference *objref,
                   const SE_Data_Table_Sub_Extent  *extents_ptr,
                         SE_Integer_Positive        element_count,
                   const SE_Integer_Positive        tpd_indices[],
                         SE_Data_Table_Data        *data_out )=0;

    virtual SE_Status_Code PutDataTableData( ObjectReference *objref,
                   const SE_Data_Table_Sub_Extent  *extents_ptr,
                         SE_Integer_Unsigned    element_count,
                   const SE_Integer_Positive    tpd_indices[],
                   const SE_Data_Table_Data    *data_in )=0;

    virtual SE_Status_Code GetImageData( ObjectReference *objref,
                         SE_Short_Integer_Unsigned mip_level,
                   const SE_Data_Table_Sub_Extent *img_extents,
                   const SE_Image_Data      *data_out )=0;

    virtual SE_Status_Code PutImageData( ObjectReference *objref,
                         SE_Short_Integer_Unsigned mip_level,
                   const SE_Data_Table_Sub_Extent *img_extents,
                   const SE_Image_Data      *data_in )=0;

    virtual SE_Status_Code GetMeshFaceTableData( ObjectReference *objref,
                         SE_Integer_Positive  start_face,
                         SE_Integer_Positive  num_faces,
                   const SE_Integer_Unsigned *mft_data_out,
                   const SE_Integer_Unsigned *adj_face_tbl_data_out )=0;

    virtual SE_Status_Code PutMeshFaceTableData( ObjectReference *objref,
                         SE_Integer_Positive  start_face,
                         SE_Integer_Positive  num_faces,
                   const SE_Integer_Unsigned *mft_data_in,
                   const SE_Integer_Unsigned *adj_face_tbl_data_in )=0;

    // Error handling methods
    virtual       void    FlushErrorDescription(void)=0;
    virtual const string &GetErrorDescription(void)=0;

  protected:
    inline FACTORY() {}
    inline virtual ~FACTORY() {}
};

#endif
