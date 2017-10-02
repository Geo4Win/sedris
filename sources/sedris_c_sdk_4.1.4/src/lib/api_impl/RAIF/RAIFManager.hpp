// SEDRIS Reference API Implementation Framework
//
// FILE:        RAIFManager.hpp
//
// PROGRAMMERS: Jesse Campos (SAIC)
//
// DESCRIPTION: Class header for RAIF Manager class.  This class manages the
//              RAIF resources such as symbolic references, objects, and
//              object references.
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

#ifndef _SE_RAIF_MANAGER_HPP_INCLUDED
#define _SE_RAIF_MANAGER_HPP_INCLUDED

#include "HashTable.hpp"
#include "Factory.hpp"
#include "ErrorHandling.hpp"
#include "raif_srm_utils.h"

class SE_Api_Object;
class SE_Api_Store;
class SE_SearchFilter;
class SE_SearchBoundary;

class SE_Api_Transmittal;
class SE_Api_Iterator;
class ObjRefInfo;
class ObjectReference;
class SE_InternalObject;
class SE_Context;

#define begin_API_Call RAIFManager::begin_API_Function
#define end_API_Call   RAIFManager::end_API_Function

#define NO_OBJECT_PARAM ((SE_Api_Object *)999)
#define NO_PARAM        ((SE_Shareable*)998)


// RAIFManager Notes:
// * All callers of methods returning an SE_InternalObject* should
// call SAFE_RELEASE() on the returned pointer when no longer needed.
//

class RAIFManager
{
    // THERE IS NO FUNCTION BY THIS NAME SO DON'T TRY TO CALL IT.
    // It is here to shut up the GNU compiler warnings.

    friend void fair_weather(void);

  public:
    //
    // These functions are used to create the singleton RAIF Manager object.
    // if the Manager has not been instantiated they will be called from
    // SE_SetColorModel, SE_SetSRFInfo
    //
    // These functions are always called when Close and Open Transmittal are
    // called.
    //
    static SE_Return_Code begin_API_Function( SE_API_Function fctn,
                    SE_Api_Object *object=NO_OBJECT_PARAM,
                    SE_Shareable  *param1=NO_PARAM,
                    SE_Shareable  *param2=NO_PARAM );

    static SE_Return_Code end_API_Function( SE_API_Function fctn );

    static void Start(void);
    static void Stop(void);

    inline FACTORY *GetFactory(void) { return _factory; };

    SE_Status_Code GetRootObject(SE_Api_Transmittal *trans, SE_InternalObject *&root_obj);

    // This table will be created only after the first OpenTransmittal is
    // called. This is to allow the API implementation to better determine
    // the proper size of the hash table.

    inline void CreateHashTable(void)
       { _hash_table = new HASH_TABLE(GetFactory()->RecommendHashTableSize()); }

    // Creates or returns from cache. Don't forget to release the returned
    // object when no longer needed.
    SE_InternalObject *ReturnInternalObject(ObjRefInfo *ORI);


    // This method clears the entry for this ORI, but does not delete the OR,
    // or Internal Object.

    void ClearObject(ObjRefInfo *ORI);

    // This method cycles through the hash table and deletes all the object
    // references and all internal objects with a reference count of 1
    // belonging to the transmittal passed in.
    //
    void CleanTransmittalObjects( RAIFImplTransmittal transmittal);

    SE_Boolean ResolveTransmittalName(const char * xmittal_name,
                                            char **xmittal_location);

    // This method will free all internal objects with a reference count of 1
    // and its object reference.
    //
    void CleanUnusedObjects(void);

    // Methods for direct API calls start with read then go to write.

    SE_Status_Code DefragTransmittal( SE_Api_Transmittal *trans, int verbose);
    SE_Status_Code RenameTransmittal( SE_Api_Transmittal *trans,
                                      char *to_fname );

    SE_Status_Code FlushTransmittal(SE_Api_Transmittal *trans);

    SE_Status_Code CloseTransmittal(SE_Api_Transmittal *transmittal);

    SE_Status_Code CreateSearchFilter(const SE_Search_Rule   rules[],
                                      SE_SearchFilter  **filter_out);

    SE_Status_Code CreateSpatialSearchBoundary(
                       const SE_Search_Bounds         *search_bounds_ptr,
                             SE_Search_Bounds_Closure  search_bounds_closure,
                             SE_Search_Type            search_quality,
                             SE_Object_Inclusion       inclusion_choice,
                             SE_Search_Dimension  search_dimension,
                             SE_SearchBoundary       **search_boundary_out_ptr);

    SE_Status_Code CreateStore( SE_Api_Store **new_store );

    SE_Status_Code DetermineSpatialInclusion( SE_Api_Object  *object_in,
                        const SE_Search_Bounds         *search_bounds_ptr,
                        SE_Search_Bounds_Closure  search_bounds_closure,
                        SE_Search_Type         search_quality,
                        SE_Search_Dimension       search_dimension,
                        SE_Boolean              *object_fully_included,
                        SE_Boolean           *object_partly_included,
                        SE_Boolean         *object_surrounds_spatial_bounds);

    SE_Status_Code GetLastFunctionStatus(SE_Api_Store   *store,
                                         SE_Status_Code *last_fnct_sts,
                                         SE_String      *error_descr);

    SE_Status_Code GetPackedHierarchy( SE_Api_Object  *root_object,
                        SE_Boolean             directly_attach_table_components,
                        SE_Boolean             process_inheritance,
                        SE_Integer_Unsigned    hierarchy_depth,
                        SE_ITR_Behaviour       itr_bhvr,
                        SE_Api_Store          *store,
                        SE_Packed_Hierarchy   *hierarchy_out_ptr);

    SE_Status_Code GetRemPackedHierarchiesList(
          SE_Api_Iterator *iter, SE_Integer_Unsigned hierarchy_depth,
          SE_Remaining_Packed_Hierarchies_List *remaining_hierarchies_out_ptr);

    SE_Status_Code GetUniqueTransmittalId(SE_Api_Transmittal *xmittal,
                                          SE_Api_Store *store,
                                          SE_String    *id);

    SE_Status_Code FreeIterator( SE_Api_Iterator *iter );

    SE_Status_Code FreeObject( SE_Api_Object *obj );

    SE_Status_Code FreePackedHierarchy(SE_Packed_Hierarchy *hierarchy);

    SE_Status_Code FreeRemainingObjectsList(
                      SE_Remaining_Objects_List *remaining_objects_to_free);

    SE_Status_Code FreeRemainingPackedHierarchiesList(
                      SE_Remaining_Packed_Hierarchies_List *to_free);

    SE_Status_Code FreeFilter( SE_SearchFilter *filter );

    SE_Status_Code FreeSpatialSearchBoundary(SE_SearchBoundary *to_free);

    SE_Status_Code FreeStore( SE_Api_Store *store );

    SE_Status_Code FreeTransmittal( SE_Api_Transmittal *trans );

    SE_Status_Code GetColorModel(SE_Api_Transmittal *transmittal,
                                 SE_Colour_Model    *color_model);

    SE_Status_Code GetContextTransformation(SE_Api_Object  *object_in,
                             SRM_Matrix_4x4 *matrix_out_ptr);

    SE_Status_Code GetMeshFaceTableData(SE_Api_Object *mft_obj,
                       SE_Integer_Positive   start_face,
                       SE_Integer_Positive   num_faces,
                       SE_Api_Store         *store,
                       SE_Integer_Unsigned **mft_data,
                       SE_Integer_Unsigned **adj_face_tbl_data);

    SE_Status_Code SE_AllocDataTableData( SE_Api_Object *data_table,
                 const SE_Data_Table_Sub_Extent   *extents_ptr,
                       SE_Integer_Positive         element_count,
                 const SE_Integer_Positive         tpd_indices[],
                       SE_Api_Store               *store_in,
                       SE_Data_Table_Data        **data_out_ptr );

    SE_Status_Code AllocDataTableData( SE_Api_Object *data_table,
                 const SE_Data_Table_Sub_Extent   *extents_ptr,
                       SE_Integer_Positive         element_count,
                 const SE_Integer_Positive         tpd_indices[],
                       SE_Api_Store               *store_in,
                       SE_Data_Table_Data        **data_out_ptr,
                       SE_API_Function     api_funct );

    SE_Status_Code GetDataTableData(SE_Api_Object    *data_table,
            const SE_Data_Table_Sub_Extent       *extents,
                  SE_Integer_Positive                    element_count,
            const SE_Integer_Positive                      tpd_indices[],
                  SE_Api_Store                *store_in,
                  SE_Data_Table_Data    **data_out);

    SE_Status_Code GetFields( SE_Api_Object *obj,
                              SE_Api_Store  *store_in,
                              SE_FIELDS_PTR *fields_out);

    SE_Status_Code GetImageData(SE_Api_Object              *image,
                       const SE_Image_Texel_Location_3D *start_texel,
                       const SE_Image_Texel_Location_3D *stop_texel,
                             SE_Short_Integer_Unsigned   mip_level,
                             SE_Api_Store               *store_in,
                             SE_Image_Data              *data_out);

    SE_Status_Code GetEncoding( SE_Api_Object *obj,
                                SE_Encoding   *encoding );

    SE_Status_Code GetNthRelationship(SE_Api_Object    *obj,
                                       SE_Integer_Unsigned  n,
                                       SE_DRM_Class     type,
                                       SE_ITR_Behaviour itr_bhvr,
                                       RAIF_REL_ENUM    rel_type,
                                       SE_Api_Object  **obj_out,
                                       SE_Api_Object  **link_out);

    SE_Status_Code GetObjectFromIDString( SE_Api_Transmittal *transmittal,
                                    const SE_String      *id_string,
                                          SE_Api_Object **object_out_ptr );

    SE_Status_Code GetObjectIDString(SE_Api_Object *object_in,
                                     SE_Api_Store  *store_in,
                                     SE_String     *id_string);

    SE_Status_Code GetPublishedLabels(SE_Api_Object   *obj,
                                      SE_Api_Store    *store_in,
                                      SE_Integer_Unsigned   *count,
                                      SE_String **label_list_out);

    SE_Status_Code GetPublishedObjectList(
                       SE_Api_Transmittal    *transmittal_in,
                       SE_Api_Store          *store_in,
                       SE_Integer_Unsigned   *count,
                       SE_Api_Object       ***published_object_list_out);

    SE_Status_Code GetReferencedTransmittalList( SE_Api_Transmittal   *trans,
                            SE_Api_Store         *store_in,
                            SE_Integer_Unsigned  *count,
                            SE_URN              **transmittal_name_list_out);

    SE_Integer_Unsigned GetObjRefCount( SE_Api_Object *object_in );

    SE_Status_Code GetRelationCounts(SE_Api_Object *object,
                                     SE_ITR_Behaviour     itr_bhvr,
                                     SE_Integer_Unsigned *num_comp_out_ptr,
                                     SE_Integer_Unsigned *num_agg_out_ptr,
                                     SE_Integer_Unsigned *num_assoc_out_ptr);

    SE_Status_Code GetRoot( SE_Api_Transmittal *trans, SE_Api_Object **obj );

    SE_Status_Code GetTransmittalFromObject(SE_Api_Object       *obj,
                                            SE_Api_Transmittal  **trans_out);

    SE_Status_Code GetTransmittalLocation(SE_Api_Transmittal*  transmittal_in,
                                          SE_Api_Store        *store_in,
                                          SE_URL *file_location_out);

    SE_Status_Code GetTransmittalName(SE_Api_Transmittal *transmittal_in,
                                      SE_Api_Store       *store_in,
                                      SE_URN             *name_out);

    SE_Status_Code GetTransmittalVersionInfo(SE_Api_Transmittal* trans,
                        SE_Short_Integer_Positive *major_DRM_version_out,
                        SE_Byte_Unsigned          *minor_DRM_version_out,
                        char                      *interim_DRM_version_out,
                        SE_Short_Integer_Positive *major_EDCS_version_out,
                        SE_Byte_Unsigned          *minor_EDCS_version_out,
                        char                      *interim_EDCS_version_out,
                        SE_Short_Integer_Positive *major_SRM_version_out,
                        SE_Byte_Unsigned          *minor_SRM_version_out,
                        char                      *interim_SRM_version_out);

    SE_Status_Code  CountRelationships(SE_Api_Object     *obj,
                        SE_Integer_Unsigned  *count_out,
                        RAIF_REL_ENUM     rel_type,
                        SE_DRM_Class      type=SE_CLS_DRM_NULL,
                        SE_ITR_Behaviour  itr_bhvr=SE_ITRBEH_IGNORE);

    SE_Status_Code CreateAggrIterator(SE_Api_Object      *start_object,
                                       SE_SearchFilter   *filter,
                                       SE_ITR_Behaviour   itr_bhvr,
                                       SE_Api_Iterator  **iterator_out);


    SE_Status_Code CreateAssocIterator(SE_Api_Object        *start_object,
                                          SE_SearchFilter   *filter,
                                          SE_ITR_Behaviour   itr_bhvr,
                                          SE_Api_Iterator   **iterator_out);

    SE_Status_Code CreateCompIterator(SE_Api_Object           *start_object,
                                       SE_SearchBoundary      *boundary,
                                       SE_SearchFilter        *filter,
                                       SE_Boolean              attach_tables,
                                       SE_Boolean              do_inheritance,
                                       SE_Boolean              do_transforms,
                                       SE_Boolean              do_follow_mis,
                                       SE_Boolean              do_clinks,
                        const SE_Hierarchy_Select_Parameters *select_params_ptr,
                        const SE_Hierarchy_Order_Parameters  *order_params_ptr,
                                       SE_Traversal_Order trav_pattern,
                                       SE_ITR_Behaviour   itr_bhvr,
                                       SE_Api_Iterator  **iterator_out);

    SE_Status_Code CreateInheritedCompIterator( SE_Api_Object *start_object,
                                        SE_SearchFilter   *filter,
                                        SE_Boolean         attach_tables,
                                        SE_ITR_Behaviour   itr_bhvr,
                                        SE_Api_Iterator  **iterator_out);

    SE_Status_Code IsObjectPublished( SE_Api_Object *obj,
                                           SE_Boolean *bool_ptr );

    SE_Status_Code ObjectsAreSame(SE_Api_Object *obj1,
                                  SE_Api_Object *obj2, SE_Boolean *bool_ptr);

    SE_Status_Code OpenTransmittalByLocation(const SE_URL *file,
                                         SE_Encoding   encoding,
                                         SE_Access_Mode  access_mode,
                                         SE_Api_Transmittal*       *trans_out);

    SE_Status_Code OpenTransmittalByName(const SE_URN *name,
                                         SE_Encoding     encoding,
                                         SE_Access_Mode access_mode,
                                         SE_Api_Transmittal*     *trans_out);

    SE_Status_Code ResolveObject( SE_Api_Object *obj );

    SE_Status_Code ResolveTransmittalName(const SE_URN *trans_name_in,
                                                SE_Api_Store    *store_in,
                                            SE_URL *file_loc_out);

    SE_Status_Code SetColorModel(SE_Colour_Model new_color_model);

    SE_Status_Code TransmittalsAreSame( SE_Api_Transmittal* trans1,
                                         SE_Api_Transmittal* trans2,
                                         SE_Boolean *bool_ptr);

    SE_Status_Code AddRelationship( SE_Api_Object     *from_obj,
                                      SE_Api_Object     *to_obj,
                                      SE_Api_Object     *link_obj,
                                      SE_Boolean     is_two_way,
                                      RAIF_REL_ENUM  rel_type);

    SE_Status_Code CreateObject( SE_Api_Transmittal* trans,
                                      SE_DRM_Class tag, SE_Api_Object **obj );

    SE_Status_Code PublishObject(SE_Api_Object  *obj,
                                 const SE_String *label_in);

    SE_Status_Code PutMeshFaceTableData(SE_Api_Object *mft_obj,
                       SE_Integer_Positive  start_face,
                       SE_Integer_Positive  num_faces,
                 const SE_Integer_Unsigned *mft_data,
                 const SE_Integer_Unsigned *adj_face_tbl_data);

    SE_Status_Code PutDataTableData(SE_Api_Object  *data_table,
            const SE_Data_Table_Sub_Extent  *extents,
                  SE_Integer_Positive        element_count,
            const SE_Integer_Positive        tpd_indices[],
            const SE_Data_Table_Data        *data_in);

    SE_Status_Code PutFields(SE_Api_Object     *obj, SE_FIELDS_PTR  fields_in);

    SE_Status_Code PutImageData(SE_Api_Object       *image,
                 const SE_Image_Texel_Location_3D *start_texel,
                 const SE_Image_Texel_Location_3D *stop_texel,
                       SE_Short_Integer_Unsigned   mip_level,
                 const SE_Image_Data              *data_in);

    SE_Status_Code GetUnresolvedObjectFromPublishedLabel(
                                            const SE_URN    *transmittal_name,
                                            const SE_String *object_label,
                                            SE_Api_Object  **object_out);

    SE_Status_Code RemoveRelationship(SE_Api_Object     *from_obj,
                                       SE_Api_Object     *to_obj,
                                       SE_Api_Object     *link_obj,
                                       SE_Boolean     is_two_way,
                                       RAIF_REL_ENUM  rel_type);

    SE_Status_Code RemoveFromTransmittal(SE_Api_Transmittal* trans,
                                              SE_Api_Object      *obj);

    SE_Status_Code SetRoot(SE_Api_Transmittal*  trans,
                            SE_Api_Object       *obj,
                            SE_Api_Object      **old_root);

    SE_Status_Code SetTransmittalName(SE_Api_Transmittal*  transmittal_in,
                                      const SE_URN *new_name);

    SE_Status_Code UnpublishObject(SE_Api_Object  *obj,
                                   const SE_String *label_in);

    SE_Boolean ValidHierarchy(SE_Packed_Hierarchy *hierarchy);

  // These functions deal with the global context issues.

    SE_Status_Code SetToSRFInfo( SE_SRF_Context_Info *new_SRF_info);

    inline SE_SRF_Context_Info * GetToSRFInfo(void){ return _to_srf_info; }

    inline SE_Boolean UseDefaultSRFInfo(void){ return _to_srf_info ? SE_FALSE : SE_TRUE; }

    RAIF_SRF_Wrapper* GetToSRF(void);

    SE_Status_Code GetToSRFInfoForObject( SE_Api_Object *obj,
                                          SE_SRF_Context_Info  *SRF_info_out);

    SE_Status_Code SetToColorModel(SE_Colour_Model new_color_model);
    inline SE_Colour_Model  GetToColorModel(void){ return _to_color_model;}

// Called from SE_Api_Object.cpp
//
    SE_Context *UpdateContext(SE_Context *old_context,
                              SE_InternalObject *aggregate,
                              SE_InternalObject *component,
                              SE_InternalObject *link_obj = NULL);

  // Generate the context needed for an object.
  //
  // Called from within the Component Iterator.cpp
  //
  // 1) If the agg_context is Null & no flags are set, it will return NULL
  // 2) If the agg_context is not NULL, and the flags differ,
  //       it will create a new context
  // 3) if the agg_context is not NULL, and the flags do not differ,
  //       it will increment the count of
  //    the agg_context and return it.
  //
    SE_Context *GenerateContext(SE_Api_Object *start_obj,
                                SE_Boolean inherit,
                                SE_Boolean transform,
                                SE_Boolean evaluate,
                                SE_Boolean attach,
                                SE_Boolean follow,
                                SE_Boolean force_context_creation = SE_FALSE );

    inline void add_err_descr(const char *msg )
    {
        _err_handler->add_err_descr( msg );
    }


    SE_Integer_Unsigned _open_int_objects;

    static SE_Integer_Unsigned _open_transmittals;

    static SE_Integer_Unsigned _max_open_objects;// moved from top of class dfn

  private:
    // This is an interesting part of this class.  Both the constructor and
    // destructor are private.  Thus the "general public" can't directly
    // create one. It can only be done through the static functions that are
    // part of the implementation.

    RAIFManager();
    virtual ~RAIFManager();

    // this object manages the last status code, the error description
    // and the error callbacks

    static ErrorHandler *_err_handler;

    // The hash table stores the object references in all transmittals.
    // It gets created when the first SE_OpenTransmittalXX call is made.

    HASH_TABLE *_hash_table;

    // The factory is what creates objects and object references.  This is
    // created within the constructor of the RAIFManager.

    FACTORY *_factory;

  // These are used for the global values of coverting to srf or to color
  // model.  Since these work for the entire API it will be stored by
  // the single RAIF Manager.

    SE_Colour_Model _to_color_model;
    RAIF_SRF_Wrapper _to_srf;
    SE_SRF_Context_Info * _to_srf_info;

    static SE_Integer_Unsigned _times_started;

  // number of "things" that RAIF has created
    SE_Integer_Unsigned  _opened_transmittals_cnt;
    SE_Integer_Unsigned  _created_transmittals_cnt;
    SE_Integer_Unsigned  _created_objects_cnt;
    SE_Integer_Unsigned  _created_filters_cnt;
    SE_Integer_Unsigned  _created_iterators_cnt;
    SE_Integer_Unsigned  _created_stores_cnt;
    SE_Integer_Unsigned  _created_bounds_cnt;

// methods for validating data tables
//
    SE_Status_Code get_dt_element_type( SE_InternalObject *data_table,
                   const  SE_Integer_Positive  tpd_index,
                          SE_Data_Table_Data_Value_Type   *value_type_ptr );

    SE_Status_Code check_dt_sub_extent( SE_InternalObject  *int_obj,
                          const SE_Data_Table_Sub_Extent *extents_ptr );

    SE_Integer_Unsigned GetSizeForImage(SE_InternalObject   *image,
                          const SE_Image_Texel_Location_3D *start_texel,
                          const SE_Image_Texel_Location_3D *stop_texel);

};


class SE_Api_Transmittal : public SE_Shareable
{
public:
    inline SE_Api_Transmittal(RAIFManager  *my_raif,
                   RAIFImplTransmittal impl_trans,
                   SE_Boolean user_opened)
    : SE_Shareable( my_raif )
    {
      _impl_transmittal = impl_trans;
      _user_opened      = user_opened;
    }

    inline SE_Api_Transmittal(const SE_Api_Transmittal &old_transmittal):SE_Shareable(old_transmittal.raif_mngr())
    { _impl_transmittal = old_transmittal._impl_transmittal;}

    inline virtual ~SE_Api_Transmittal(){ }

    inline SE_Boolean WasUserOpened(void){ return _user_opened;}

    inline RAIFImplTransmittal GetImplTransmittal(void){ return _impl_transmittal; }

protected:
    RAIFImplTransmittal _impl_transmittal;
    SE_Boolean        _user_opened;
};

#endif
