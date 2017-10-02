// SEDRIS Level 0 Read API
//
// FILE       : se_write0.cpp
//
// PROGRAMMERS: Jesse Campos (SAIC)
//
// DESCRIPTION: The Level 0 Write API functions
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

#include "se_write0.h"
#include "ErrorHandling.hpp"
#include "RAIFTypes.hpp"
#include "ObjectReference.hpp"
#include "SE_API_Object.hpp"
#include "se_extract_types.h"
#include "RAIFManager.hpp"

// The following section of code implements all of the functions
// declared in se_write0.h.

extern "C" {

// This function returns true if the link object is valid for the tags
// pased in i.e. if no link object is required thent it should be null,
// otherwise it needs to match.

static SE_Boolean
CheckAssociationLink
(
    SE_Api_Object *link_object,
    SE_DRM_Class   from_tag,
    SE_DRM_Class   to_tag
)
{
    const SE_Requirement *link_req=NULL;
          SE_Boolean      result = SE_TRUE;

   // if the function fails, return false.
    if (SE_GetAssociateOfType(from_tag, to_tag,
                              &link_req) != SE_DRM_STAT_CODE_SUCCESS)
    {
        err_handler->add_err_descr( "SE_GetAssociateOfType error",
                                     SE_STATCODE_INACTIONABLE_FAILURE);
        result = SE_FALSE;
    }

   // if there should be no link class, but a link object was passed in, return
   // false
    else if (link_req->drm_link_class == SE_CLS_DRM_NULL)
    {
        if (VALID_SHAREABLE(link_object))
        {
            err_handler->add_err_descr("This associate relationship does not need "\
              "a link object. Pass NULL for the link object",
              SE_STATCODE_INACTIONABLE_FAILURE);
            result = SE_FALSE;
        }
    }
    else
    {
        // A link object is required but it does not exist or does not match the tag
        if (!VALID_SHAREABLE(link_object))
        {
            err_handler->add_err_descr("This associate relationship needs "\
              "a link object that has not been supplied.",
              SE_STATCODE_INACTIONABLE_FAILURE );
            result = SE_FALSE;
        }
        else if (!SE_IsA[link_object->tag()][link_req->drm_link_class])
        {
            err_handler->add_err_descr("The link object supplied for "\
               "this associate relationship is not a valid DRM class "\
               "for this relationship.",
               SE_STATCODE_INACTIONABLE_FAILURE);
            result = SE_FALSE;
        }
    }
    return result;
}



  // This function returns true if the link object is valid for the tags
  // pased in i.e. if no link object is required thent it should be null,
  // otherwise it needs to match.

static SE_Boolean
CheckComponentLink
(
    SE_Api_Object *link_object,
    SE_DRM_Class aggr_tag,
    SE_DRM_Class comp_tag
)
{
    const SE_Requirement *link_req=NULL;

   // if the function fails, return false.

    if (SE_GetComponentOfType( aggr_tag, comp_tag,
                              &link_req ) != SE_DRM_STAT_CODE_SUCCESS )
    {
        return SE_FALSE;
    }

    // if there should be no link class, but a link object was passed in, return
    // false
    if(link_req->drm_link_class == SE_CLS_DRM_NULL)
    {
        if(VALID_SHAREABLE(link_object))
        {
            err_handler->add_err_descr("This Component relationship does not take "\
              "a link object. Pass NULL for the link object",
              SE_STATCODE_INACTIONABLE_FAILURE );
            return SE_FALSE;
        }
    }
    else
    {
        // A link object is required but it does not exist or does not match the tag
        if(!VALID_SHAREABLE(link_object))
        {
            err_handler->add_err_descr( "This Component relationship needs "\
              "a link object which has not been supplied.",
              SE_STATCODE_INACTIONABLE_FAILURE );
            return SE_FALSE;
        }
        else if(!SE_IsA[link_object->tag()][link_req->drm_link_class])
        {
            err_handler->add_err_descr("The link object supplied for this "\
               "component relationship is not a valid DRM class for this relationship.",
               SE_STATCODE_INACTIONABLE_FAILURE );
            return SE_FALSE;
        }
    }
    return SE_TRUE;
}


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_AddAssociateRelationship
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_AddAssociateRelationship
(
    SE_Object  from_obj_in,
    SE_Object  to_obj_in,
    SE_Object  link_obj_in,
    SE_Boolean make_two_way
)
{
    SE_Api_Object *from_obj=(SE_Api_Object*)from_obj_in;
    SE_Api_Object *to_obj=(SE_Api_Object*)to_obj_in;
    SE_Api_Object *link_obj=(SE_Api_Object*)link_obj_in;

    // don't pass link_object since it is allowed to be NULL
    if (begin_API_Call(SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP,
                       from_obj, to_obj) == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (to_obj->IsRemoved())
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "To Object", SE_STATCODE_DELETED_OBJECT );
    }
    else if (link_obj && link_obj->IsRemoved())
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Link Object", SE_STATCODE_DELETED_OBJECT );
    }
    else if ((from_obj->IsResolved() != SE_TRUE) &&
             (to_obj->IsResolved() != SE_TRUE))
    {
        err_handler->add_err_descr(ERR_DESCR_UNRESOLVED_START_OBJECT,
            "to object and from object are both unresolved",
            SE_STATCODE_UNRESOLVED_INPUT_OBJECT);
    }
    else if ((link_obj && (link_obj->IsResolved() != SE_TRUE)) &&
             ((from_obj->IsResolved() == SE_TRUE) &&
              (to_obj->IsResolved() == SE_TRUE)))
    {
        err_handler->add_err_descr(ERR_DESCR_UNRESOLVED_START_OBJECT,
            "link object is non-NULL and unresolved but "\
            "to object and from object are both resolved",
            SE_STATCODE_UNRESOLVED_INPUT_OBJECT);
    }
    else if (from_obj->IsResolved() && to_obj->IsResolved() &&
             SE_IsLegalAssociate(from_obj->tag(), to_obj->tag()) == SE_FALSE)
    {
        err_handler->add_err_descr( "This is not a legal DRM Associate "\
                      "Relationship ", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if (!(from_obj->IsResolved() && to_obj->IsResolved()) ||
             CheckAssociationLink(link_obj, from_obj->tag(), to_obj->tag()) == SE_TRUE)
    {
        err_handler->set_status_code(
             raif_mngr->AddRelationship(from_obj, to_obj, link_obj,
                          make_two_way, REF_REL_ASSOCIATION ) );
    }
    return end_API_Call( SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP);
} // end SE_AddAssociate


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_AddComponentRelationship
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_AddComponentRelationship
(
    SE_Object aggr_obj_in,
    SE_Object comp_obj_in,
    SE_Object link_obj_in
)
{
    SE_Api_Object *aggr_obj=(SE_Api_Object*)aggr_obj_in;
    SE_Api_Object *comp_obj=(SE_Api_Object*)comp_obj_in;
    SE_Api_Object *link_obj=(SE_Api_Object*)link_obj_in;

    // don't pass link_object since it is allowed to be NULL
    if (begin_API_Call( SE_APIFN_ADD_COMPONENT_RELATIONSHIP,
                            aggr_obj, comp_obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (comp_obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Component Object", SE_STATCODE_DELETED_OBJECT );
    }
    else if (link_obj && link_obj->IsRemoved())
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Link Object", SE_STATCODE_DELETED_OBJECT );
    }
    else if (comp_obj->IsResolved() && aggr_obj->IsResolved() &&
             SE_IsLegalComponent(comp_obj->tag(), aggr_obj->tag() ) == SE_FALSE )
    {
        err_handler->add_err_descr( "This is not a Legal DRM Component "
                     "Relationship", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!(comp_obj->IsResolved() && aggr_obj->IsResolved()) ||
               CheckComponentLink( link_obj, aggr_obj->tag(), comp_obj->tag() ) == SE_TRUE )
    {
        err_handler->set_status_code(
             raif_mngr->AddRelationship(aggr_obj, comp_obj,
                            link_obj, SE_TRUE, REF_REL_COMPONENT) );
    }
    return end_API_Call(SE_APIFN_ADD_COMPONENT_RELATIONSHIP);
} // end SE_AddComponentRelationship


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AllocDataTableData
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_AllocDataTableData
(
          SE_Object                   object_in,
    const SE_Data_Table_Sub_Extent   *extents_ptr,
          SE_Integer_Positive         element_count,
    const SE_Integer_Positive         tbl_prop_descr_indices[],
          SE_Store                    store_in,
          SE_Data_Table_Data        **data_out_ptr
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;
    SE_Api_Store  *store=(SE_Api_Store*)store_in;

    if (begin_API_Call( SE_APIFN_ALLOC_DATA_TABLE_DATA,
                            obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (!SE_IsA[obj->tag()][SE_CLS_DRM_DATA_TABLE])
    {
       err_handler->add_err_descr( "This object is not a Data Table",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!extents_ptr || !tbl_prop_descr_indices)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                     "Sub Extents or TPD Indices", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!data_out_ptr )
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                     "Data Table Data", SE_STATCODE_INACTIONABLE_FAILURE );
    }
//$$$ how to set the error description from the read0 lib???

    else if (SE_ValidDataTableSignature( element_count,
                     tbl_prop_descr_indices ) != SE_STATCODE_SUCCESS)
    {
       err_handler->add_err_descr( "Invalid Data Table Signature",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_CellCountForSubExtent(extents_ptr) == 0 )
    {
       err_handler->add_err_descr( "The cell count for this Sub Extents is "
                              "zero", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->AllocDataTableData( obj,
              extents_ptr,  element_count, tbl_prop_descr_indices,
              store, data_out_ptr, SE_APIFN_ALLOC_DATA_TABLE_DATA ) );
    }
    return end_API_Call( SE_APIFN_ALLOC_DATA_TABLE_DATA );
} /* end SE_AllocDataTableData */


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_CreateObject
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_CreateObject
(
    SE_Transmittal trans_in,
    SE_DRM_Class  new_object_tag,
    SE_Object     *new_object_out_ptr
)
{
    SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if (begin_API_Call( SE_APIFN_CREATE_OBJECT,
                    NO_OBJECT_PARAM, trans ) == SE_RETCOD_FAILURE )
    {
        return SE_RETCOD_FAILURE;
    }

    if (!new_object_out_ptr)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                     "New Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!SE_ValidDRMClass(new_object_tag) ||
              (new_object_tag == SE_CLS_DRM_NULL))
    {
       err_handler->add_err_descr( "Invalid DRM Class", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_IsAbstractClass(new_object_tag) )
    {
       err_handler->add_err_descr( "This is an Abstract DRM Class. "
                    "It cannot be created", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                raif_mngr->CreateObject( trans, new_object_tag,
                             (SE_Api_Object**)new_object_out_ptr) );
    }
    return end_API_Call(SE_APIFN_CREATE_OBJECT);
} // end SE_CreateObject


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_PublishObject
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_PublishObject
(
          SE_Object  object_in,
    const SE_String *label_in
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call(SE_APIFN_PUBLISH_OBJECT, obj) == SE_RETCOD_FAILURE)
    {
      return SE_RETCOD_FAILURE;
    }

    if (!label_in || !label_in->length || !label_in->characters)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                     "Object Label", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_IsPublishable[obj->tag()] != SE_TRUE)
    {
       err_handler->add_err_descr( "This DRM class is not Publishable",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidObjectLabel(label_in) != SE_TRUE)
    {
       err_handler->add_err_descr( "This is not a valid Object Label.",
                                   SE_STATCODE_INVALID_OBJECT_LABEL );
    }
    else
    {
        err_handler->set_status_code(raif_mngr->PublishObject(obj, label_in));
    }
    return end_API_Call(SE_APIFN_PUBLISH_OBJECT);
} // end SE_PublishObject


//----------------------------------------------------------------------------
//
// FUNCTION: SE_PutMeshFaceTableData
//
//----------------------------------------------------------------------------
SE_Return_Code
SE_PutMeshFaceTableData
(
          SE_Object            mesh_face_table_object,
          SE_Boolean           put_adjacent_face_table_data,
          SE_Integer_Positive  start_face,     // 1-based
          SE_Integer_Positive  num_faces,
    const SE_Integer_Unsigned *mesh_face_table_data,
    const SE_Integer_Unsigned *adjacent_face_table_data
)
{
SE_Api_Object *mft_obj=(SE_Api_Object*)mesh_face_table_object;

    if (begin_API_Call( SE_APIFN_PUT_MESH_FACE_TABLE_DATA,
                        mft_obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (mft_obj->tag() != SE_CLS_DRM_MESH_FACE_TABLE )
    {
       err_handler->add_err_descr( "This object is not a <Mesh Face Table>.",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (mesh_face_table_data == NULL )
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
               "mesh_face_table_data", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (put_adjacent_face_table_data == SE_TRUE &&
             adjacent_face_table_data == NULL )
    {
       err_handler->add_err_descr( "Parameter put_adjacent_face_table_data "
           "is TRUE but the parameter adjacent_face_table_data is NULL\n",
                                    SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (put_adjacent_face_table_data == SE_FALSE &&
             adjacent_face_table_data != NULL )
    {
       err_handler->add_err_descr( "Parameter put_adjacent_face_table_data "
           "is FALSE but the parameter adjacent_face_table_data is not NULL\n",
                                    SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (start_face == 0 )

    {
       err_handler->add_err_descr( "Parameter start_face cannot be zero. "
           "This is a 1-based index.\n", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->PutMeshFaceTableData( mft_obj, start_face-1, num_faces,
                             mesh_face_table_data, adjacent_face_table_data) );
    }
    return end_API_Call(SE_APIFN_PUT_MESH_FACE_TABLE_DATA);
}


//----------------------------------------------------------------------------
//
// FUNCTION: SE_PutDataTableData
//
//----------------------------------------------------------------------------
SE_Return_Code
SE_PutDataTableData
(
          SE_Object                  object_in,
    const SE_Data_Table_Sub_Extent  *extents_ptr,
          SE_Integer_Positive    element_count,
    const SE_Integer_Positive    tbl_prop_descr_indices[],
    const SE_Data_Table_Data    *data_in_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call( SE_APIFN_PUT_DATA_TABLE_DATA,
                            obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if ( !SE_IsA[obj->tag()][SE_CLS_DRM_DATA_TABLE])
    {
       err_handler->add_err_descr( "This object is not a Data Table",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!extents_ptr || !tbl_prop_descr_indices || !data_in_ptr )
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                     "Sub Extents or TPD Indices", SE_STATCODE_INACTIONABLE_FAILURE );
    }
// $$$ how to set the error description from the read0 lib???
//
    else if (SE_ValidDataTableSignature( element_count,
                tbl_prop_descr_indices ) != SE_STATCODE_SUCCESS)
    {
       err_handler->add_err_descr( "Invalid Data Table Signature",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_CellCountForSubExtent(extents_ptr) == 0 )
    {
       err_handler->add_err_descr( "The cell count for this Sub Extents is "
                              "zero", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->PutDataTableData( obj, extents_ptr,
                   element_count, tbl_prop_descr_indices, data_in_ptr) );
    }
    return end_API_Call(SE_APIFN_PUT_DATA_TABLE_DATA);
} // end SE_PutDataTableData


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_PutFields
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_PutFields
(
    SE_Object     object_in,
    SE_FIELDS_PTR fields
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call( SE_APIFN_PUT_FIELDS,
                            obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (!fields)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                          "Fields Pointer", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if(fields->tag != obj->tag() )
    {
       err_handler->add_err_descr( "The tag in the Fields pointer must match "
       "the DRM Class of the object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->PutFields(obj, fields) );
    }
    return end_API_Call(SE_APIFN_PUT_FIELDS);
} // end SE_PutFields


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_PutImageData
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_PutImageData
(
          SE_Object                   object_in,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
    const SE_Image_Data              *data_in_ptr
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call( SE_APIFN_PUT_IMAGE_DATA,
                        obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (obj->tag() != SE_CLS_DRM_IMAGE)
    {
        err_handler->add_err_descr( "This object is not an Image",
                                    SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!start_texel)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                           "start texel", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!stop_texel)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                           "stop texel", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!data_in_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                           "Image Data", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->PutImageData( obj, start_texel, stop_texel,
                mip_level, data_in_ptr) );
    }
    return end_API_Call(SE_APIFN_PUT_IMAGE_DATA);
} // end SE_PutImageData


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_GetUnresolvedObjectFromPublishedLabel
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_GetUnresolvedObjectFromPublishedLabel
(
    const SE_URN      *trans_name,
    const SE_String   *obj_label,
          SE_Encoding  encoding,
          SE_Object   *obj_out_p
)
{
    if (begin_API_Call(SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL)
        == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (obj_out_p ) *obj_out_p = NULL;

    if (!obj_out_p )
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                   "Unresolved Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!trans_name || !obj_label )
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
           "Transmittal Name or Object Label", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!SE_ValidTransmittalName(trans_name))
    {
       err_handler->add_err_descr( "Invalid Transmittal Name",
                 SE_STATCODE_INVALID_TRANSMITTAL_NAME );
    }
    else if (!SE_ValidObjectLabel(obj_label))
    {
       err_handler->add_err_descr( "Invalid Object Label",
                         SE_STATCODE_INVALID_OBJECT_LABEL );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetUnresolvedObjectFromPublishedLabel(
                          trans_name, obj_label,
                          (SE_Api_Object**)obj_out_p) );
    }
    return end_API_Call(
               SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL );
} // end SE_GetUnresolvedObjectFromPublishedLabel


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_RemoveAssociateRelationship
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_RemoveAssociateRelationship
(
    SE_Object  from_obj_in,
    SE_Object  to_obj_in,
    SE_Object  link_obj_in,
    SE_Boolean remove_two_way
)
{
SE_Api_Object *from_obj=(SE_Api_Object*)from_obj_in;
SE_Api_Object   *to_obj=(SE_Api_Object*)to_obj_in;
SE_Api_Object *link_obj=(SE_Api_Object*)link_obj_in;

    if (begin_API_Call( SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP,
                       from_obj, to_obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if ( !VALID_LINK_OBJECT(link_obj))
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                   "Link Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (to_obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "To Object", SE_STATCODE_DELETED_OBJECT );
    }
    else if (link_obj && link_obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Link Object", SE_STATCODE_DELETED_OBJECT );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->RemoveRelationship(from_obj, to_obj, link_obj,
                       remove_two_way, REF_REL_ASSOCIATION ) );
    }
    return end_API_Call( SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP );
} // end SE_RemoveAssociateRelationship


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_RemoveComponentRelationship
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_RemoveComponentRelationship
(
    SE_Object  aggr_obj_in,
    SE_Object  comp_obj_in,
    SE_Object  link_obj_in
)
{
SE_Api_Object *aggr_obj=(SE_Api_Object*)aggr_obj_in;
SE_Api_Object *comp_obj=(SE_Api_Object*)comp_obj_in;
SE_Api_Object *link_obj=(SE_Api_Object*)link_obj_in;

    if (begin_API_Call( SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP,
                       aggr_obj, comp_obj ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (!VALID_LINK_OBJECT(link_obj))
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                   "Link Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (comp_obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Component Object", SE_STATCODE_DELETED_OBJECT );
    }
    else if (link_obj && link_obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Link Object", SE_STATCODE_DELETED_OBJECT );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->RemoveRelationship( aggr_obj, comp_obj, link_obj,
                                       SE_TRUE, REF_REL_COMPONENT ) );
    }
    return end_API_Call(SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP);
} // end SE_RemoveComponentRelationship



//-----------------------------------------------------------------------------
//
// FUNCTION: SE_RemoveFromTransmittal
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_RemoveFromTransmittal
(
   SE_Object       object_in,
   SE_Transmittal  trans_in
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if (begin_API_Call( SE_APIFN_REMOVE_FROM_TRANSMITTAL,
                            obj, trans ) == SE_RETCOD_FAILURE )
    {
      return SE_RETCOD_FAILURE;
    }

    if (obj->num_of_components() ||
        obj->num_of_associations() ||
        obj->num_of_aggregates() )
    {
        char error_msg[400];

        sprintf(error_msg, "This object still has existing relationships.\n"\
           "The object cannot be removed until all relationships have been "\
           "removed. There are %u components, %u aggregates, and "
           "%u associates.", obj->num_of_components(),
           obj->num_of_aggregates(), obj->num_of_associations() );

        err_handler->add_err_descr(error_msg, SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->RemoveFromTransmittal(trans, obj) );
    }
    return end_API_Call(SE_APIFN_REMOVE_FROM_TRANSMITTAL);
} // end SE_RemoveFromTransmittal


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_SetRootObject
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_SetRootObject
(
    SE_Transmittal  trans_in,
    SE_Object       new_root_obj_in,
    SE_Object      *old_root_obj_out_ptr
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;
SE_Api_Object *new_root_obj=(SE_Api_Object*)new_root_obj_in;

    if (begin_API_Call( SE_APIFN_SET_ROOT_OBJECT,
                  new_root_obj, trans ) == SE_RETCOD_FAILURE )
    {
        return SE_RETCOD_FAILURE;
    }

    if (old_root_obj_out_ptr) *old_root_obj_out_ptr = NULL;

    err_handler->set_status_code( raif_mngr->SetRoot(trans, new_root_obj,
                    (SE_Api_Object**)old_root_obj_out_ptr ) );

    return end_API_Call( SE_APIFN_SET_ROOT_OBJECT );
} /* end SE_SetRootObject */



//-----------------------------------------------------------------------------
//
// FUNCTION: SE_SetTransmittalName
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_SetTransmittalName
(
          SE_Transmittal  trans_in,
    const SE_URN         *trans_name
)
{
    SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if (begin_API_Call(SE_APIFN_SET_TRANSMITTAL_NAME,
                  NO_OBJECT_PARAM, trans) == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (!trans_name)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                     "Transmittal Name", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!SE_ValidTransmittalName( trans_name))
    {
       err_handler->add_err_descr( "Invalid Transmittal Name",
                       SE_STATCODE_INVALID_TRANSMITTAL_NAME );
    }
    else
    {
       err_handler->set_status_code(
           raif_mngr->SetTransmittalName( trans, trans_name ) );
    }
    return end_API_Call(SE_APIFN_SET_TRANSMITTAL_NAME );
} // end SE_SetTransmittalName


//-----------------------------------------------------------------------------
//
// FUNCTION: SE_UnpublishObject
//
//-----------------------------------------------------------------------------
SE_Return_Code
SE_UnpublishObject
(
          SE_Object  object_in,
    const SE_String *label_in
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call(SE_APIFN_UNPUBLISH_OBJECT, obj) == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (!label_in)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                      "Object Label", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidString(label_in, SE_FALSE, NULL) != SE_TRUE)
    {
        err_handler->add_err_descr( "failed SE_ValidString",
                                    SE_STATCODE_INVALID_OBJECT_LABEL);
    }
    else
    {
       err_handler->set_status_code(raif_mngr->UnpublishObject(obj, label_in));
    }
    return end_API_Call( SE_APIFN_UNPUBLISH_OBJECT );
} // end SE_UnpublishObject


} // End of extern "C" section
