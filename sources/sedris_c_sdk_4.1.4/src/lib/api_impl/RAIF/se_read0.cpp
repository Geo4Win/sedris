// SEDRIS Level 0 Read API
//
// FILE       : se_read0.cpp
//
// PROGRAMMERS:  Jesse Campos (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: The Level 0 API functions
//
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

#include "sedris.h"
#include "drm.h"
#include "SE_API_Object.hpp"
#include "SE_ComponentIterator.hpp"
#include "SE_AggregateIterator.hpp"
#include "SE_AssociationIterator.hpp"
#include "SE_InheritedComponentIterator.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_SearchBoundary.hpp"
#include "SE_Context.hpp"
#include "se_search_support.hpp"
#include "ErrorHandling.hpp"
#include "SE_Store.hpp"
#include "RAIFManager.hpp"


// The following section of code implements all of the functions
// declared in se_read0.h.

extern "C" {
/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetLastFunctionStatus
 *
 *   This function is intended to provide the user of the SEDRIS API additional
 *   information regarding a failed function call to the SEDRIS API. This
 *   function can be called immediately after a non-successful API call to
 *   get a verbose description of why the SEDRIs function failed.
 *
 *   The contents of the error description may be over-written by the next
 *   SEDRIS API call.
 *
 *
 * PARAMETERS:
 *
 *   error_description - a pointer to a character array. The API creates the
 *     memory and sets the contents of it. This pointer may be overwritten by
 *     the next call to the API.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters provided were set to the
 *     appropriate values, if valid parameters were passed in, and the
 *     relationship between the object and the boundary was determined.
 *
 *   SE_STAT_CODE_NULL_REQUIRED_PARAMETER - and none of the output parameters
 *     are modified, if error_description is NULL
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and none of the output parameters are
 *     modified, if there is no valid error message for the last
 *     API Function called
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetLastFunctionStatus
(
    SE_Store        store_in,
    SE_Status_Code *last_fnct_sts,
    SE_String      *err_descr
)
{
   SE_Api_Store *store=(SE_Api_Store*)store_in;

// can't call begin_API_Call here since it resets the error description
//
    RAIFManager::Start();

    if( last_fnct_sts == NULL)
    {
       fprintf(stderr, "Null Status_Code passed to SE_GetLastFunctionStatus.\n");
       return SE_RETCOD_FAILURE;
    }

   // the store may be null but only if err_descr is null also
   //
    if (store == NULL)
    {
       if (err_descr != NULL)
       {
          fprintf(stderr,
                 "SE_GetLastFunctionStatus: NULL Store passed in with a"\
                 "non-NULL error_descr arg.\n");
          return SE_RETCOD_FAILURE;
       }
    }
    else if (!VALID_SHAREABLE(store))
    {
       fprintf(stderr, "invalid Store passed to SE_GetLastFunctionStatus.\n");
       return SE_RETCOD_FAILURE;
    }
    SE_Status_Code sts;

    sts = raif_mngr->GetLastFunctionStatus( store, last_fnct_sts, err_descr );

    err_handler->flush_err_descr();

    err_handler->set_status_code( sts );

    return SE_RETCOD_SUCCESS;
} /* end SE_GetLastFunctionStatus */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneObjectHandle
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_CloneObjectHandle
(
    SE_Object  object_in,
    SE_Object *new_object_ptr
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call(SE_APIFN_CLONE_OBJECT_HANDLE, obj) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (!new_object_ptr)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_OUTPUT_PARAM,
            "New Object", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else
    {
        *new_object_ptr = (SE_Api_Object *) obj->clone();

        if( *new_object_ptr )
            err_handler->set_status_code( SE_STATCODE_SUCCESS );
        else
            err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                        "", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    return end_API_Call(SE_APIFN_CLONE_OBJECT_HANDLE);
} /* end SE_CloneObjectHandle */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloseTransmittal
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_CloseTransmittal
(
    SE_Transmittal trans_in
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if( begin_API_Call( SE_APIFN_CLOSE_TRANSMITTAL )
                              == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

// $$$ if begin_API_Call can handle this then remove here
//
    if (!VALID_SHAREABLE(trans))
    {
        err_handler->add_err_descr( ERR_DESCR_INVALID_OR_NULL_TRANSMITTAL,
                                    "", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
       err_handler->set_status_code(raif_mngr->CloseTransmittal(trans));
    }

    SE_Return_Code ret_code = end_API_Call(
                                      SE_APIFN_CLOSE_TRANSMITTAL );
    RAIFManager::Stop();

    return ret_code;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateSearchFilter
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_CreateSearchFilter
(
          SE_Encoding             encoding,
    const SE_Search_Rule    rules[],
          SE_Search_Filter *search_filter_out_ptr
)
{
    if( begin_API_Call( SE_APIFN_CREATE_SEARCH_FILTER )
                              == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( !search_filter_out_ptr )
    {
       err_handler->add_err_descr
       (
           ERR_DESCR_NULL_OUTPUT_PARAM,
           "search_filter", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if( !rules )
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_INPUT_PARAM,
            "search rules", SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else if (SE_ValidSearchRule(rules, SE_FALSE, NULL) == SE_FALSE)
    {
       err_handler->add_err_descr( "Invalid Search Rules",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
       *search_filter_out_ptr = NULL;
    }
    else
    {
       err_handler->set_status_code(raif_mngr->CreateSearchFilter(rules,
                       (SE_SearchFilter **)search_filter_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_CREATE_SEARCH_FILTER);
}


/*
 *-----------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateSpatialSearchBoundary
 *
 *-----------------------------------------------------------------------
 */
SE_Return_Code
SE_CreateSpatialSearchBoundary
(
          SE_Encoding               encoding,
    const SE_Search_Bounds         *search_bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type            search_quality,
          SE_Object_Inclusion       inclusion_choice,
          SE_Search_Dimension       search_dimension,
          SE_Search_Boundary       *search_boundary_out_ptr
)
{
    if (begin_API_Call(SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY)
                              == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (!search_boundary_out_ptr)
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_OUTPUT_PARAM,
                                   "search boundary", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if (!search_bounds_ptr)
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "search bounds", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if (!SE_ValidSearchBoundsClosure( search_bounds_closure))
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Bounds Closure",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if (!SE_ValidSearchType(search_quality))
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Type",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if (!SE_ValidObjectInclusion(inclusion_choice))
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "Object Inclusion",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if (!SE_ValidSearchDimension(search_dimension))
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Dimension",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->CreateSpatialSearchBoundary(search_bounds_ptr,
                      search_bounds_closure, search_quality,
                      inclusion_choice, search_dimension,
                      (SE_SearchBoundary**)search_boundary_out_ptr));
    }
    return end_API_Call(SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateStore
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_CreateStore
(
     SE_Encoding   encoding,
     SE_Store     *new_store_ptr
)
{
    if( begin_API_Call( SE_APIFN_CREATE_STORE )
                              == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!new_store_ptr)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                  "store", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        *new_store_ptr = NULL;
        err_handler->set_status_code(
             raif_mngr->CreateStore((SE_Api_Store**)new_store_ptr) );
    }
    return end_API_Call(SE_APIFN_CREATE_STORE);
} /* end SE_CreateStore */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_DetermineSpatialInclusion
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_DetermineSpatialInclusion
(
          SE_Object                 object_in,
    const SE_Search_Bounds         *search_bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type            search_quality,
          SE_Search_Dimension       search_dimension,
          SE_Boolean               *object_fully_included,
          SE_Boolean               *object_partly_included,
          SE_Boolean               *object_surrounds_spatial_bounds
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;
    SE_Boolean     obj_fully_incl=SE_FALSE;
    SE_Boolean     obj_partly_incl=SE_FALSE;
    SE_Boolean     obj_surrounds_spatial_bounds=SE_FALSE;

    if (begin_API_Call(SE_APIFN_DETERMINE_SPATIAL_INCLUSION, obj)
           == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (!object_fully_included && !object_partly_included &&
        !object_surrounds_spatial_bounds)
    {
         err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
            "Fully Included, Partly Included and Surrounds Spatial Bounds.",
             SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if (!search_bounds_ptr)
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "search bounds", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if (!SE_ValidSearchBoundsClosure(search_bounds_closure))
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Bounds Closure",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if (!SE_ValidSearchType(search_quality))
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Type", SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if (!SE_ValidSearchDimension(search_dimension))
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Dimension", SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
        err_handler->set_status_code(
               raif_mngr->DetermineSpatialInclusion( obj,
                    search_bounds_ptr, search_bounds_closure,
                    search_quality, search_dimension,
                    &obj_fully_incl, &obj_partly_incl,
                    &obj_surrounds_spatial_bounds));
    }
    if( object_fully_included )
       *object_fully_included = obj_fully_incl;

    if( object_partly_included )
       *object_partly_included = obj_partly_incl;

    if( object_surrounds_spatial_bounds )
       *object_surrounds_spatial_bounds = obj_surrounds_spatial_bounds;

    return end_API_Call(SE_APIFN_DETERMINE_SPATIAL_INCLUSION);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPackedHierarchy
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetPackedHierarchy
(
    SE_Object              object_in,
    SE_Boolean             directly_attach_table_components,
    SE_Boolean             process_inheritance,
    SE_Integer_Unsigned    hierarchy_depth,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Store               store_in,
    SE_Packed_Hierarchy   *hierarchy_out_ptr
)
{
    SE_Api_Object *root_obj=(SE_Api_Object*)object_in;
    SE_Api_Store  *store=(SE_Api_Store*)store_in;

    if (begin_API_Call(SE_APIFN_GET_PACKED_HIERARCHY, root_obj) ==
        SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

   if (!hierarchy_out_ptr)
   {
      err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                  "", SE_STATCODE_INACTIONABLE_FAILURE );
   }
   else if (SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE)
   {
       err_handler->add_err_descr("Invalid ITR Behaviour",
                                  SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
   }
   else
   {
       err_handler->set_status_code(
           raif_mngr->GetPackedHierarchy( root_obj,
                                      directly_attach_table_components,
                                      process_inheritance,
                                      hierarchy_depth,
                                      itr_bhvr,
                                      store,
                                      hierarchy_out_ptr ) );
   }
   return end_API_Call(SE_APIFN_GET_PACKED_HIERARCHY);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRemainingPackedHierarchies
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetRemainingPackedHierarchiesList
(
    SE_Iterator                           iterator_in,
    SE_Integer_Unsigned                   hierarchy_depth,
    SE_Remaining_Packed_Hierarchies_List *remaining_hierarchies_out_ptr
)
{
SE_Api_Iterator *iterator=(SE_Api_Iterator *)iterator_in;

   if (begin_API_Call(SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST,
             NO_OBJECT_PARAM, iterator)  == SE_RETCOD_FAILURE)
   {
      return SE_RETCOD_FAILURE;
   }

   if (!remaining_hierarchies_out_ptr)
   {
      err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                   "Remaining Packed Hierarchies List", SE_STATCODE_INACTIONABLE_FAILURE );
   }
// $$$ move to begin_API_Call...
   else if (!VALID_SHAREABLE(iterator))
   {
      remaining_hierarchies_out_ptr->hierarchy_count = 0;
      remaining_hierarchies_out_ptr->hierarchy_list  = NULL;
      err_handler->set_status_code( SE_STATCODE_INACTIONABLE_FAILURE );
   }
   else
   {
      err_handler->set_status_code(
             raif_mngr->GetRemPackedHierarchiesList(iterator,
                          hierarchy_depth, remaining_hierarchies_out_ptr ) );
   }
   return end_API_Call(
             SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST );
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeIterator
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_FreeIterator
(
    SE_Iterator iterator_in
)
{
   SE_Api_Iterator *iterator=(SE_Api_Iterator *)iterator_in;

   if( begin_API_Call( SE_APIFN_FREE_ITERATOR,
             NO_OBJECT_PARAM, iterator )  == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }
   err_handler->set_status_code( raif_mngr->FreeIterator( iterator ) );

   return end_API_Call(SE_APIFN_FREE_ITERATOR);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeObject
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_FreeObject
(
    SE_Object object_in
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

   if( begin_API_Call( SE_APIFN_FREE_OBJECT,
                    NO_OBJECT_PARAM, obj)  == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }
   err_handler->set_status_code( raif_mngr->FreeObject(obj) );

   return end_API_Call(SE_APIFN_FREE_OBJECT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreePackedHierarchy
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_FreePackedHierarchy
(
    SE_Packed_Hierarchy *to_free
)
{
   if( begin_API_Call( SE_APIFN_FREE_PACKED_HIERARCHY )
                           == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }

   if( !to_free )
   {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                  "Packed Hierarchy", SE_STATCODE_INACTIONABLE_FAILURE );
   }
   else
   {
       err_handler->set_status_code(
          raif_mngr->FreePackedHierarchy(to_free) );
   }
    return end_API_Call(SE_APIFN_FREE_PACKED_HIERARCHY);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeRemainingObjectsList
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_FreeRemainingObjectsList
(
   SE_Remaining_Objects_List *rem_objs_list
)
{
   if( begin_API_Call( SE_APIFN_FREE_REMAINING_OBJECTS_LIST )
                           == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }

   if( !rem_objs_list )
   {
       err_handler->add_err_descr
       (
           ERR_DESCR_NULL_INPUT_PARAM,
           "Remaining Objects List", SE_STATCODE_INACTIONABLE_FAILURE );
   }
   else if (rem_objs_list->object_count == 0 &&
            (rem_objs_list->remaining_objects_list ||
             rem_objs_list->remaining_link_objects_list) )
   {
       err_handler->add_err_descr
       (
           ERR_DESCR_NULL_INPUT_PARAM,
           "Remaining Objects List", SE_STATCODE_INACTIONABLE_FAILURE);
       err_handler->add_err_descr( "The number objects is 0 but "
              "either the object list or the link object list is not NULL" );
   }
   else if (rem_objs_list->object_count != 0 &&
            (rem_objs_list->remaining_objects_list == NULL ||
             rem_objs_list->remaining_link_objects_list == NULL))
   {
       err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                    "Remaining Objects List", SE_STATCODE_INACTIONABLE_FAILURE );
       err_handler->add_err_descr( "The number objects is > 0 but "
              "either the object list or the link object list is NULL" );
   }
   else
   {
       err_handler->set_status_code(
            raif_mngr->FreeRemainingObjectsList(rem_objs_list) );
   }
   return end_API_Call(SE_APIFN_FREE_REMAINING_OBJECTS_LIST);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeRemainingPackedHierarchiesList
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_FreeRemainingPackedHierarchiesList
(
    SE_Remaining_Packed_Hierarchies_List *to_free
)
{
   if( begin_API_Call(
             SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST )
                           == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }

   if (!to_free)
   {
      err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
           "Remaining Packed Hierarchies List is NULL", SE_STATCODE_INACTIONABLE_FAILURE );
   }
   else if( to_free->hierarchy_count > 0 &&
            to_free->hierarchy_list == NULL )
   {
      err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
           "Remaining Packed Hierarchies List is NULL", SE_STATCODE_INACTIONABLE_FAILURE );
      err_handler->add_err_descr( "The hierarchy count is > 0 but the "
                                  "hierarchy list is NULL" );
   }
   else if( to_free->hierarchy_count == 0 &&
            to_free->hierarchy_list != NULL )
   {
      err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
           "Remaining Packed Hierarchies List is NULL", SE_STATCODE_INACTIONABLE_FAILURE );
      err_handler->add_err_descr( "The hierarchy count is 0 but the "
                                  "hierarchy list is Not NULL" );
   }
   else
   {
       err_handler->set_status_code(
          raif_mngr->FreeRemainingPackedHierarchiesList(to_free) );
   }
   return end_API_Call(
                 SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSearchFilter
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_FreeSearchFilter
(
    SE_Search_Filter filter_in
)
{
SE_SearchFilter *filter=(SE_SearchFilter *)filter_in;

   if( begin_API_Call( SE_APIFN_FREE_SEARCH_FILTER,
               NO_OBJECT_PARAM, filter) == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }
   err_handler->set_status_code( raif_mngr->FreeFilter( filter) );

   return end_API_Call(SE_APIFN_FREE_SEARCH_FILTER);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSpatialSearchBoundary
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_FreeSpatialSearchBoundary
(
    SE_Search_Boundary search_boundary_in
)
{
SE_SearchBoundary *search_boundary=(SE_SearchBoundary*)search_boundary_in;

   if( begin_API_Call( SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY,
                NO_OBJECT_PARAM, search_boundary) == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }
   err_handler->set_status_code(
         raif_mngr->FreeSpatialSearchBoundary(search_boundary));

   return end_API_Call(SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeStore
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_FreeStore
(
    SE_Store store_in
)
{
SE_Api_Store *store=(SE_Api_Store*)store_in;

   if( begin_API_Call( SE_APIFN_FREE_STORE,
               NO_OBJECT_PARAM, store ) == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }
   err_handler->set_status_code( raif_mngr->FreeStore(store) );

   return end_API_Call(SE_APIFN_FREE_STORE);
} /* end SE_CreateStore */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTransmittal
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
SE_FreeTransmittal
(
    SE_Transmittal trans_in
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

   if( begin_API_Call( SE_APIFN_FREE_TRANSMITTAL,
               NO_OBJECT_PARAM, trans ) == SE_RETCOD_FAILURE )
   {
      return SE_RETCOD_FAILURE;
   }
   err_handler->set_status_code( raif_mngr->FreeTransmittal(trans) );

   return end_API_Call(SE_APIFN_FREE_TRANSMITTAL);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetAggregate
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetAggregate
(
    SE_Object         object_in,
    SE_DRM_Class      drm_class,
    SE_ITR_Behaviour  itr_bhvr,
    SE_Object        *object_out_ptr,
    SE_Object        *link_object_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_AGGREGATE,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!object_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                       "Aggregate SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidDRMClass(drm_class) == SE_FALSE ||
             SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE)
    {
        err_handler->add_err_descr("Invalid DRM Class or ITR Behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
        err_handler->set_status_code(
                obj->get_nth_aggregate( 0,
                           (SE_Api_Object**)object_out_ptr,
                           (SE_Api_Object**)link_object_out_ptr,
                            drm_class, itr_bhvr ) );
    }
    return end_API_Call(SE_APIFN_GET_AGGREGATE);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetAssociate
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetAssociate
(
    SE_Object              object_in,
    SE_DRM_Class           drm_class,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Object             *object_out_ptr,
    SE_Object             *link_object_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_ASSOCIATE,
                            obj) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!object_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                       "Associate SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidDRMClass(drm_class) == SE_FALSE ||
             SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE)
    {
        err_handler->add_err_descr("Invalid DRM Class or ITR Behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
       err_handler->set_status_code(
               obj->get_nth_association( 0,
                          (SE_Api_Object**)object_out_ptr,
                          (SE_Api_Object**)link_object_out_ptr,
                          drm_class, itr_bhvr ) );
    }
    return end_API_Call(SE_APIFN_GET_ASSOCIATE);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetColourModel
 *
 *  The color model is set in the SE_Context class.
 *  The color model for the API will be stored there.
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetColourModel
(
    SE_Transmittal       trans_in,
    SE_Colour_Model *color_model_out_ptr
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if( begin_API_Call( SE_APIFN_GET_COLOUR_MODEL,
                NO_OBJECT_PARAM, trans ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!color_model_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                       "Colour Model", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->GetColorModel( trans, color_model_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_COLOUR_MODEL);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetComponent
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetComponent
(
    SE_Object        object_in,
    SE_DRM_Class     drm_class,
    SE_Boolean       directly_attach_table_components,
    SE_Boolean       process_inheritance,
    SE_ITR_Behaviour itr_bhvr,
    SE_Object       *object_out_ptr,
    SE_Object       *link_object_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_COMPONENT,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!object_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                       "Component Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidDRMClass(drm_class) == SE_FALSE ||
             drm_class == SE_CLS_DRM_NULL ||
             SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE)
    {
        err_handler->add_err_descr("Invalid DRM Class or ITR Behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
        err_handler->set_status_code(
                obj->GetComponent( drm_class,
                       directly_attach_table_components,
                       process_inheritance, itr_bhvr,
                       (SE_Api_Object**)object_out_ptr,
                       (SE_Api_Object**)link_object_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_GET_COMPONENT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetContextTransformation
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetContextTransformation
(
    SE_Object       object_in,
    SRM_Matrix_4x4  matrix_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_CONTEXT_TRANSFORMATION,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!matrix_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                       "Matrix 4x4", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code( obj->getCartMatrix(matrix_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_CONTEXT_TRANSFORMATION);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetMeshFaceTableData
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetMeshFaceTableData
(
    SE_Object             mesh_face_table_object,
    SE_Boolean            get_adjacent_face_table_data,
    SE_Integer_Positive   start_face,  // 1-based
    SE_Integer_Positive   number_faces,
    SE_Store              store_in,
    SE_Integer_Unsigned **mesh_face_table_data,
    SE_Integer_Unsigned **adjacent_face_table_data
)
{
SE_Api_Object *mft_obj=(SE_Api_Object*)mesh_face_table_object;
SE_Api_Store *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_MESH_FACE_TABLE_DATA,
                            mft_obj, store) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    //if( mesh_face_table_data )
      //  *mesh_face_table_data = NULL;

    //if( adjacent_face_table_data )
      // *adjacent_face_table_data = NULL;

    if( mesh_face_table_data == NULL )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                             "mft_data", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( mft_obj->tag() != SE_CLS_DRM_MESH_FACE_TABLE )
    {
        err_handler->add_err_descr( "input object is not a Mesh Face Table",
                             SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( get_adjacent_face_table_data == SE_TRUE &&
             adjacent_face_table_data == NULL )
    {
       err_handler->add_err_descr( "Parameter get_adjacent_face_table_data "
           "is TRUE but the parameter adjacent_face_table_data is NULL\n",
                                    SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( start_face == 0 )

    {
       err_handler->add_err_descr( "Parameter start_face can not be zero. "
           "This is a 1-based index.\n", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->GetMeshFaceTableData( mft_obj, start_face-1, number_faces,
               store, mesh_face_table_data,
              (get_adjacent_face_table_data == SE_TRUE ?
                  adjacent_face_table_data : NULL)));
    }
    return end_API_Call(SE_APIFN_GET_MESH_FACE_TABLE_DATA);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableData
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetDataTableData
(
          SE_Object                  object_in,
    const SE_Data_Table_Sub_Extent  *extents_ptr,
          SE_Integer_Positive       element_count,
    const SE_Integer_Positive       tbl_prop_descr_indices[],
          SE_Store                   store_in,
          SE_Data_Table_Data      **data_out_ptr
)
{
SE_Api_Object *dt_obj=(SE_Api_Object*)object_in;
SE_Api_Store *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_DATA_TABLE_DATA,
                            dt_obj, store) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( data_out_ptr )
        *data_out_ptr = NULL;

    if( !data_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                    "", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( !extents_ptr || !tbl_prop_descr_indices  || !element_count )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                    "", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if ( !SE_IsA[dt_obj->tag()][SE_CLS_DRM_DATA_TABLE])
    {
        err_handler->add_err_descr( "input object is not a DRM class derived "
          "from SE_CLS_DRM_DATA_TABLE", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( SE_ValidDataTableSignature( element_count,
                         tbl_prop_descr_indices ) != SE_STATCODE_SUCCESS)
    {
        err_handler->add_err_descr( "The data table has an invalid signature.",
                                     SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->GetDataTableData( dt_obj, extents_ptr,
              element_count, tbl_prop_descr_indices, store, data_out_ptr ));
    }
    return end_API_Call(SE_APIFN_GET_DATA_TABLE_DATA);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetFields
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetFields
(
    SE_Object      object_in,
    SE_Store       store_in,
    SE_FIELDS_PTR *fields_out_ptr
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;
    SE_Api_Store *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_FIELDS,
                            obj, store ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (fields_out_ptr)
        *fields_out_ptr = NULL;

    if (!fields_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
           "Fields Pointer", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                raif_mngr->GetFields( obj, store, fields_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_FIELDS);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetObjectIDString
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetObjectIDString
(
    SE_Object  object_in,
    SE_Store   store_in,
    SE_String *id_string
)
{
   SE_Api_Object *obj=(SE_Api_Object*)object_in;
   SE_Api_Store *store=(SE_Api_Store*)store_in;

   if (begin_API_Call(SE_APIFN_GET_OBJECT_ID_STRING,
                      obj, store) == SE_RETCOD_FAILURE)
   {
      return SE_RETCOD_FAILURE;
   }

   if (id_string)
   {
      *id_string = SE_STRING_DEFAULT;
       err_handler->set_status_code(
           raif_mngr->GetObjectIDString( obj, store, id_string));
   }
   else
   {
       err_handler->add_err_descr(ERR_DESCR_NULL_OUTPUT_PARAM,
          "ID String", SE_STATCODE_INACTIONABLE_FAILURE );
   }
   return end_API_Call(SE_APIFN_GET_OBJECT_ID_STRING);
} /* end SE_GetObjectIDString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetImageData
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetImageData
(
          SE_Object                   object_in,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
          SE_Store                    store_in,
          SE_Image_Data              *data_out_ptr
)
{
    SE_Api_Object *img_obj=(SE_Api_Object*)object_in;
    SE_Api_Store *store=(SE_Api_Store*)store_in;

    if (begin_API_Call(SE_APIFN_GET_IMAGE_DATA, img_obj, store)
        == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (!data_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                "Image Data", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else if (!start_texel)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_INPUT_PARAM,
            "start texel", SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else if (!stop_texel)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_INPUT_PARAM,
            "stop texel", SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else if ( img_obj->tag() != SE_CLS_DRM_IMAGE)
    {
        err_handler->add_err_descr("The object is not an <Image> instance",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetImageData( img_obj,
                             start_texel, stop_texel,
                             mip_level, store, data_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_IMAGE_DATA);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetEncoding
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetEncoding
(
    SE_Object    object_in,
    SE_Encoding *encoding
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_ENCODING,
                            obj) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!encoding)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                "Encoding", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetEncoding( obj, encoding ) );
    }
    return end_API_Call(SE_APIFN_GET_ENCODING);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetIterationLengthRemaining
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetIterationLengthRemaining
(
     SE_Iterator  iterator_in,
     SE_Integer_Unsigned   *count_out_ptr
)
{
    SE_Api_Iterator *iterator=(SE_Api_Iterator *)iterator_in;

    if( begin_API_Call( SE_APIFN_GET_ITERATION_LENGTH_REMAINING,
                     NO_OBJECT_PARAM, iterator ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!count_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                    "Iteration Count", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code( iterator->external_length(count_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_ITERATION_LENGTH_REMAINING);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_IsIteratorComplete
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean SE_IsIteratorComplete( SE_Iterator iter_in )
{
SE_Api_Iterator *iter=(SE_Api_Iterator *)iter_in;

    if( begin_API_Call( SE_APIFN_IS_ITERATOR_COMPLETE,
                        NO_OBJECT_PARAM, iter ) == SE_RETCOD_FAILURE )
    {
// if there was an error then don't set empty to true. The use case is for
// the error to be discovered and processed when the iterator is asked for
// its next object.
// Otherwise normal processing will not discover that there was actually an
// error. They'll just think that the iterator was good and was empty.
//
       return SE_FALSE;
    }
    SE_Boolean empty=SE_FALSE;

    err_handler->set_status_code( iter->is_empty( &empty ) );

    return empty;
}



/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNextObject
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetNextObject
(
    SE_Iterator  iterator_in,
    SE_Object   *next_object_out_ptr,
    SE_Object   *link_object_out_ptr
)
{
SE_Api_Iterator *iterator=(SE_Api_Iterator *)iterator_in;

    if( begin_API_Call( SE_APIFN_GET_NEXT_OBJECT,
                     NO_OBJECT_PARAM, iterator ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (next_object_out_ptr)
        *next_object_out_ptr = NULL;

    if (link_object_out_ptr)
        *link_object_out_ptr = NULL;

    if (!next_object_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                    "Next Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                   iterator->external_next_object(
                          (SE_Api_Object**)next_object_out_ptr,
                          (SE_Api_Object**)link_object_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_GET_NEXT_OBJECT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNthAssociate
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetNthAssociate
(
    SE_Object     object_in,
    SE_DRM_Class  assoc_type,
    SE_Integer_Unsigned     n,
    SE_Object     *assoc_object_out_ptr,
    SE_Object     *link_object_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call(SE_APIFN_GET_NTH_ASSOCIATE, obj) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (assoc_object_out_ptr)
        *assoc_object_out_ptr = NULL;

    if (link_object_out_ptr)
        *link_object_out_ptr = NULL;

    if (!assoc_object_out_ptr)
    {
       err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                         "Nth Associate Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if ( n == 0 )
    {
       err_handler->add_err_descr( "Invalid Nth of 0: Nth is a 1-based index",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidDRMClass(assoc_type) == SE_FALSE)
    {
        err_handler->add_err_descr("Invalid DRM Class",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if (assoc_type == SE_CLS_DRM_NULL)
    {
        err_handler->add_err_descr("CLS_DRM_NULL is not allowed for this function",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
// SE_GetAssociateOfType sets the status code
//
         const SE_Requirement *assoc_req_ptr = NULL;

         if( SE_GetAssociateOfType(obj->tag(), assoc_type,
                  &assoc_req_ptr) == SE_DRM_STAT_CODE_SUCCESS )
         {
            if( assoc_req_ptr->ordered == SE_FALSE )
            {
                err_handler->add_err_descr( "This relationship is not "\
                 "specified as an ordered relationship", SE_STATCODE_INACTIONABLE_FAILURE );
            }
            else
            {
// The internal RAIF code has 0 based components so decrement n by one.

                err_handler->set_status_code(
                      obj->GetNthAssociateOfDRMClass( n-1, assoc_type,
                           (SE_Api_Object**)assoc_object_out_ptr,
                           (SE_Api_Object**)link_object_out_ptr ) );
            }
        }
    }
    return end_API_Call(SE_APIFN_GET_NTH_ASSOCIATE);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNthComponent
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetNthComponent
(
    SE_Object      object_in,
    SE_DRM_Class  comp_type,
    SE_Integer_Unsigned      n,
    SE_Object     *comp_object_out_ptr,
    SE_Object     *link_class_object_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_NTH_COMPONENT,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    const SE_Requirement *comp_req_ptr;

    if (comp_object_out_ptr)
       *comp_object_out_ptr = NULL;

    if (link_class_object_out_ptr)
       *link_class_object_out_ptr = NULL;

    if (!comp_object_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                          "Nth Component Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if ( n == 0 )
    {
       err_handler->add_err_descr( "Invalid Nth of 0: Nth is a 1-based index",
                                    SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if ( comp_type == SE_CLS_DRM_NULL )
    {
       err_handler->add_err_descr( "DRM_CLS_NULL is not allowed for this "
                                   "function", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        if( SE_GetComponentOfType( obj->tag(), comp_type,
                        &comp_req_ptr) == SE_DRM_STAT_CODE_SUCCESS )
        {
           if ( !comp_req_ptr->ordered )
           {
               err_handler->add_err_descr( "This relationship is not "
                "specified as an ordered relationship", SE_STATCODE_INACTIONABLE_FAILURE );
           }
           else
           {
      // The internal RAIF code has 0 based components so decrement n by one.

               err_handler->set_status_code(
                   obj->GetNthComponentOfDRMClass( n-1, comp_type,
                        (SE_Api_Object**)comp_object_out_ptr,
                        (SE_Api_Object**)link_class_object_out_ptr ));
           }
        }
    }
    return end_API_Call(SE_APIFN_GET_NTH_COMPONENT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNumberOfPathsTransmittalRoot
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetNumberOfPathsToTransmittalRoot
(
    SE_Object  object_in,
    SE_Integer_Unsigned *num_paths_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call(
           SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT,
                            obj) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( !num_paths_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                          "Number of Paths", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
             obj->num_of_paths_to_transmittal_root(num_paths_out_ptr) );
    }
    return end_API_Call(
                 SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetObjectFromIDString
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetObjectFromIDString
(
          SE_Transmittal  trans_in,
    const SE_String      *id_string,
          SE_Object      *obj_out_ptr
)
{
    SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if (begin_API_Call(SE_APIFN_GET_OBJECT_FROM_ID_STRING,
                       NO_OBJECT_PARAM, trans) == SE_RETCOD_FAILURE)
    {
        return SE_RETCOD_FAILURE;
    }

    if (!obj_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                          "Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (id_string == NULL)
    {
        *obj_out_ptr = NULL;
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                          "ID String", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_CompareLocales(&(id_string->locale), &SE_LOCALE_DEFAULT)
             != 0)
    {
        *obj_out_ptr = NULL;
        err_handler->add_err_descr("Not default locale for ID String",
                                   SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                 raif_mngr->GetObjectFromIDString( trans, id_string,
                              (SE_Api_Object**)obj_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_GET_OBJECT_FROM_ID_STRING);
} /* end SE_GetObjectFromIDString  */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetObjectReferenceCount
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetObjectReferenceCount
(
    SE_Object  object_in,
    SE_Integer  *ref_count_out_ptr
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_OBJECT_REFERENCE_COUNT,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!ref_count_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                          "Reference Count", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        *ref_count_out_ptr = raif_mngr->GetObjRefCount( obj );
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(SE_APIFN_GET_OBJECT_REFERENCE_COUNT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPublishedLabels
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetPublishedLabels
(
   SE_Object             object_in,
   SE_Store              store_in,
   SE_Integer_Unsigned  *num_labels_out_ptr,
   SE_String           **label_list_out_ptr
)
{
   SE_Api_Object *obj=(SE_Api_Object*)object_in;
   SE_Api_Store  *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_PUBLISHED_LABELS,
                            obj, store ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (label_list_out_ptr)
        *label_list_out_ptr = NULL;

    if (num_labels_out_ptr)
        *num_labels_out_ptr = 0;

    if (!label_list_out_ptr || !num_labels_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
              "Object Labels List or Number of Labels", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetPublishedLabels( obj, store,
                                  num_labels_out_ptr, label_list_out_ptr));
    }
    return end_API_Call(SE_APIFN_GET_PUBLISHED_LABELS);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPublishedObjectList
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetPublishedObjectList
(
    SE_Transmittal        trans_in,
    SE_Store              store_in,
    SE_Integer_Unsigned  *num_publ_obj_out_ptr,
    SE_Object           **publ_obj_list_ptr
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;
SE_Api_Store       *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_PUBLISHED_OBJECT_LIST,
                 NO_OBJECT_PARAM, trans, store ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (publ_obj_list_ptr)
        *publ_obj_list_ptr = NULL;

    if (num_publ_obj_out_ptr)
        *num_publ_obj_out_ptr = 0;

    if (!publ_obj_list_ptr || !num_publ_obj_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
              "Published Object List or Number of Published Objects",
               SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->GetPublishedObjectList( trans, store,
                                  num_publ_obj_out_ptr,
                    (SE_Api_Object***)publ_obj_list_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_PUBLISHED_OBJECT_LIST);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetReferencedTransmittalList
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetReferencedTransmittalList
(
    SE_Transmittal        trans_in,
    SE_Store              store_in,
    SE_Integer_Unsigned  *trans_list_len_out_ptr,
    SE_URN              **trans_name_list_out_ptr
)
{
   SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;
   SE_Api_Store       *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST,
                NO_OBJECT_PARAM, trans, store) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (trans_name_list_out_ptr)
        *trans_name_list_out_ptr = NULL;

    if (trans_list_len_out_ptr)
        *trans_list_len_out_ptr = 0;

    if (!trans_name_list_out_ptr || !trans_list_len_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
              "Transmittal List or Transmittal List Length",
               SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetReferencedTransmittalList(trans, store,
                         trans_list_len_out_ptr, trans_name_list_out_ptr));
    }
    return end_API_Call(SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRelationCounts
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetRelationCounts
(
    SE_Object  object_in,
    SE_ITR_Behaviour     itr_bhvr,
    SE_Integer_Unsigned *num_comp_out_ptr,
    SE_Integer_Unsigned *num_agg_out_ptr,
    SE_Integer_Unsigned *num_assoc_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_RELATION_COUNTS,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if(!num_comp_out_ptr && !num_agg_out_ptr && !num_assoc_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
              "Num Components, Num Aggregates and Num Associates",
               SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
              raif_mngr->GetRelationCounts( obj, itr_bhvr,
                   num_comp_out_ptr, num_agg_out_ptr, num_assoc_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_GET_RELATION_COUNTS);
}


//------------------------------------------------------------------------
//------------------------------------------------------------------------
SE_Return_Code
SE_GetRemainingObjectsList
(
   SE_Iterator                iterator_in,
   SE_Remaining_Objects_List *remaining_objects_out_ptr
)
{
    SE_Api_Iterator *iterator=(SE_Api_Iterator *)iterator_in;

    if( remaining_objects_out_ptr )
    {
        remaining_objects_out_ptr->object_count = 0;
        remaining_objects_out_ptr->remaining_objects_list = NULL;
        remaining_objects_out_ptr->remaining_link_objects_list = NULL;
    }

    if( begin_API_Call( SE_APIFN_GET_REMAINING_OBJECTS_LIST,
                          NO_OBJECT_PARAM, iterator ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( !remaining_objects_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
              "Remaining Objects LIst", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                      iterator->get_remaining_objects_list(
                                    remaining_objects_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_REMAINING_OBJECTS_LIST);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRootObject
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetRootObject
(
    SE_Transmittal  trans_in,
    SE_Object      *root_obj_out_ptr
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if( begin_API_Call( SE_APIFN_GET_ROOT_OBJECT,
                          NO_OBJECT_PARAM, trans) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (root_obj_out_ptr)
        *root_obj_out_ptr=NULL;

    if (!root_obj_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
              "Root Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->GetRoot( trans, (SE_Api_Object**)root_obj_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_ROOT_OBJECT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetSRFContextInfo
(
    SE_Object             object_in,
    SE_SRF_Context_Info  *SRF_info_out_ptr
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call(SE_APIFN_GET_SRF_CONTEXT_INFO, obj) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (!SRF_info_out_ptr)
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_OUTPUT_PARAM,
                                   "SRF Context Info", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else
    {
        err_handler->set_status_code(
           raif_mngr->GetToSRFInfoForObject(obj, SRF_info_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_SRF_CONTEXT_INFO);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalFromObject
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetTransmittalFromObject
(
    SE_Object       object_in,
    SE_Transmittal *trans_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (trans_out_ptr)
        *trans_out_ptr = NULL;

    if (!trans_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                   "Transmittal", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                 raif_mngr->GetTransmittalFromObject(
                               obj, (SE_Api_Transmittal**)trans_out_ptr) );
    }
    return end_API_Call(SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalLocation
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetTransmittalLocation
(
    SE_Transmittal  trans_in,
    SE_Store        store_in,
    SE_URL         *file_loc_out_ptr
)
{
    SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;
    SE_Api_Store       *store=(SE_Api_Store*)store_in;

    if (begin_API_Call( SE_APIFN_GET_TRANSMITTAL_LOCATION,
          NO_OBJECT_PARAM, trans, store) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (file_loc_out_ptr)
        *file_loc_out_ptr = SE_URL_DEFAULT;

    if (!file_loc_out_ptr)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_OUTPUT_PARAM,
            "File Location", SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else
    {
        err_handler->set_status_code(
                raif_mngr->GetTransmittalLocation(
                           trans, store, file_loc_out_ptr));
    }
    return end_API_Call(SE_APIFN_GET_TRANSMITTAL_LOCATION);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalName
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetTransmittalName
(
    SE_Transmittal  trans_in,
    SE_Store        store_in,
    SE_URN         *name_out_ptr
)
{
   SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;
   SE_Api_Store       *store=(SE_Api_Store*)store_in;

    if (begin_API_Call(SE_APIFN_GET_TRANSMITTAL_NAME,
          NO_OBJECT_PARAM, trans, store) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }


    if (name_out_ptr)
        *name_out_ptr = SE_URN_DEFAULT;

    if (!name_out_ptr)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_OUTPUT_PARAM,
            "Transmittal Name",
            SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetTransmittalName(trans, store, name_out_ptr));
    }
    return end_API_Call(SE_APIFN_GET_TRANSMITTAL_NAME);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetUniqueTransmittalID
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetUniqueTransmittalID
(
    SE_Transmittal  trans_in,
    SE_Store        store_in,
    SE_String      *id_ptr
)
{
   SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;
   SE_Api_Store       *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID,
           NO_OBJECT_PARAM, trans, store ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!id_ptr)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_OUTPUT_PARAM,
            "Transmittal ID", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetUniqueTransmittalId(trans, store, id_ptr));
    }
    return end_API_Call(SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalDataModelVersion
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetTransmittalVersionInformation
(
    SE_Transmittal             trans_in,
    SE_Short_Integer_Positive *major_DRM_version_out_ptr,
    SE_Byte_Unsigned          *minor_DRM_version_out_ptr,
    char                      *interim_DRM_version_out_ptr,
    SE_Short_Integer_Positive *major_EDCS_version_out_ptr,
    SE_Byte_Unsigned          *minor_EDCS_version_out_ptr,
    char                      *interim_EDCS_version_out_ptr,
    SE_Short_Integer_Positive *major_SRM_version_out_ptr,
    SE_Byte_Unsigned          *minor_SRM_version_out_ptr,
    char                      *interim_SRM_version_out_ptr
)
{
SE_Api_Transmittal *trans=(SE_Api_Transmittal *)trans_in;

    if( major_DRM_version_out_ptr )   *major_DRM_version_out_ptr = 0;
    if( minor_DRM_version_out_ptr )   *minor_DRM_version_out_ptr = 0;
    if( interim_DRM_version_out_ptr ) *interim_DRM_version_out_ptr = '\0';
    if( interim_EDCS_version_out_ptr ) *interim_EDCS_version_out_ptr = '\0';
    if( major_EDCS_version_out_ptr )  *major_EDCS_version_out_ptr = 0;
    if( minor_EDCS_version_out_ptr )  *minor_EDCS_version_out_ptr = 0;
    if( interim_SRM_version_out_ptr ) *interim_SRM_version_out_ptr = '\0';
    if( major_SRM_version_out_ptr )  *major_SRM_version_out_ptr = 0;
    if( minor_SRM_version_out_ptr )  *minor_SRM_version_out_ptr = 0;

    if (begin_API_Call(SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION,
           NO_OBJECT_PARAM, trans) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (!major_DRM_version_out_ptr  || !minor_DRM_version_out_ptr  ||
        !interim_DRM_version_out_ptr|| !major_EDCS_version_out_ptr ||
        !minor_EDCS_version_out_ptr || !interim_EDCS_version_out_ptr ||
        !major_SRM_version_out_ptr || !minor_SRM_version_out_ptr ||
        !interim_SRM_version_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                   "", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->GetTransmittalVersionInfo(trans,
                major_DRM_version_out_ptr, minor_DRM_version_out_ptr,
                interim_DRM_version_out_ptr, major_EDCS_version_out_ptr,
                minor_EDCS_version_out_ptr, interim_EDCS_version_out_ptr,
                major_SRM_version_out_ptr, minor_SRM_version_out_ptr,
                interim_SRM_version_out_ptr));
    }
    return end_API_Call(SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetUserData
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_GetUserData
(
    SE_Object   object_in,
    void      **user_data_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if (begin_API_Call(SE_APIFN_GET_USER_DATA, obj) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (!user_data_out_ptr)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_OUTPUT_PARAM,
            "User Data",
            SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else
    {
        *user_data_out_ptr = (void *)obj->GetIntObj()->get_user_data();
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(SE_APIFN_GET_USER_DATA);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDRMClass
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_GetDRMClass
(
    SE_Object     object_in,
    SE_DRM_Class *drm_cls_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_GET_DRM_CLASS,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!drm_cls_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                                   "DRM Class", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        *drm_cls_out_ptr = obj->tag();

        err_handler->set_status_code(
            (*drm_cls_out_ptr == SE_CLS_DRM_NULL ?
                 SE_STATCODE_INACTIONABLE_FAILURE : SE_STATCODE_SUCCESS ) );
    }
    return end_API_Call(SE_APIFN_GET_DRM_CLASS);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeAggregateIterator
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_InitializeAggregateIterator
(
    SE_Object              object_in,
    SE_Search_Filter       filter_in,       // can be NULL
    SE_ITR_Behaviour       itr_bhvr,
    SE_Iterator           *iterator_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    SE_SearchFilter *filter=(SE_SearchFilter *)filter_in;

    if( iterator_out_ptr )
        *iterator_out_ptr = NULL;

    if( !iterator_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                            "Aggregate Iterator", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid ITR behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if( filter && !VALID_SHAREABLE(filter) )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                            "Search Filter", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
               raif_mngr->CreateAggrIterator( obj, filter,
                        itr_bhvr, (SE_Api_Iterator**)iterator_out_ptr) );
    }
    return end_API_Call( SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR );
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeAssociateIterator
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_InitializeAssociateIterator
(
    SE_Object              object_in,
    SE_Search_Filter       filter_in,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Iterator           *iterator_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    SE_SearchFilter *filter=(SE_SearchFilter *)filter_in;

    if (iterator_out_ptr)
        *iterator_out_ptr = NULL;

    if (!iterator_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                               "Associate Iterator", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid ITR behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if( filter && !VALID_SHAREABLE(filter) )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                            "Search Filter", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->CreateAssocIterator( obj, filter,
                       itr_bhvr, (SE_Api_Iterator**)iterator_out_ptr) );
    }
    return end_API_Call(SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeComponentIterator
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_InitializeComponentIterator
(
          SE_Object                       object_in,
          SE_Search_Boundary              search_boundary_in,
          SE_Search_Filter                filter_in,
          SE_Boolean                      directly_attach_table_components,
          SE_Boolean                      process_inheritance,
          SE_Boolean                      transform_locations,
          SE_Boolean                      follow_model_instances,
          SE_Boolean                      evaluate_static_control_links,
    const SE_Hierarchy_Select_Parameters *select_parameters_ptr,
    const SE_Hierarchy_Order_Parameters  *traversal_order_parameters_ptr,
          SE_Traversal_Order              general_traversal_pattern,
          SE_ITR_Behaviour                itr_bhvr,
          SE_Iterator                    *iterator_out_ptr
)
{
SE_Api_Object     *obj=(SE_Api_Object*)object_in;
SE_SearchBoundary *search_boundary=(SE_SearchBoundary*)search_boundary_in;
SE_SearchFilter   *filter=(SE_SearchFilter *)filter_in;

    if( begin_API_Call( SE_APIFN_INITIALIZE_COMPONENT_ITERATOR,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (iterator_out_ptr)
        *iterator_out_ptr = NULL;

    if( !iterator_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                            "Component Iterator", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( SE_ValidTraversalOrder(general_traversal_pattern) == SE_FALSE ||
             SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid Traversal Order or ITR Behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if( filter && !VALID_SHAREABLE(filter) )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Filter", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( search_boundary && !VALID_SHAREABLE(search_boundary))
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Boundary", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
              raif_mngr->CreateCompIterator( obj,
                          search_boundary, filter,
                          directly_attach_table_components,
                          process_inheritance,
                          transform_locations,
                          follow_model_instances,
                          evaluate_static_control_links,
                          select_parameters_ptr,
                          traversal_order_parameters_ptr,
                          general_traversal_pattern,
                          itr_bhvr, (SE_Api_Iterator**)iterator_out_ptr) );
    }
    return end_API_Call(SE_APIFN_INITIALIZE_COMPONENT_ITERATOR);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeInheritedComponentIterator
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_InitializeInheritedComponentIterator
(
    SE_Object              object_in,
    SE_Search_Filter       filter_in,
    SE_Boolean             directly_attach_table_components,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Iterator           *iterator_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call(
            SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    SE_SearchFilter *filter=(SE_SearchFilter *)filter_in;

    if( !iterator_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                     "Inherited Component Iterator", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( SE_ValidITRBehaviour(itr_bhvr) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid ITR Behaviour",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else if( filter && !VALID_SHAREABLE(filter) )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                                   "Search Filter", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
                    raif_mngr->CreateInheritedCompIterator( obj,
                       filter, directly_attach_table_components,
                       itr_bhvr, (SE_Api_Iterator**)iterator_out_ptr ) );
    }

    // Can't ise ITR. why is it here ir directly attaching table components?

    return end_API_Call(SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ObjectIsPublished
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_ObjectIsPublished
(
    SE_Object   object_in,
    SE_Boolean *result_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_OBJECT_IS_PUBLISHED,
                            obj ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!result_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                         "Published Flag", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->IsObjectPublished( obj, result_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_OBJECT_IS_PUBLISHED);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ObjectIsResolved
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_ObjectIsResolved
(
    SE_Object   object_in,
    SE_Boolean *result_out_ptr
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

// don't check object here since unresolved is an acceptable state.
//
    if( begin_API_Call(
             SE_APIFN_OBJECT_IS_RESOLVED ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( !VALID_SHAREABLE(obj) )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                       "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                        "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( !result_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                         "Resolved Flag", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        *result_out_ptr = obj->IsResolved();
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(SE_APIFN_OBJECT_IS_RESOLVED);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ObjectsAreSame
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_ObjectsAreSame
(
    SE_Object   obj1_in,
    SE_Object   obj2_in,
    SE_Boolean *result_out_ptr
)
{
SE_Api_Object *obj1=(SE_Api_Object*)obj1_in;
SE_Api_Object *obj2=(SE_Api_Object*)obj2_in;

    if( begin_API_Call( SE_APIFN_OBJECTS_ARE_SAME,
                            obj1, obj2 ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( !result_out_ptr )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                       "Same As Flag", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (obj2->IsRemoved())
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                        "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if (!obj2->IsResolved())
    {
        err_handler->add_err_descr( ERR_DESCR_UNRESOLVED_OBJECT,
                       "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        raif_mngr->ObjectsAreSame( obj1, obj2, result_out_ptr );
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(SE_APIFN_OBJECTS_ARE_SAME);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OpenTransmittalByFile
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_OpenTransmittalByLocation
(
    const SE_URL         *file_location,
          SE_Encoding     encoding,
          SE_Access_Mode  access_mode,
          SE_Transmittal *trans_out_ptr
)
{
    if (begin_API_Call(SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION) ==
        SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (trans_out_ptr) *trans_out_ptr = NULL;

    if (!trans_out_ptr)
    {
        err_handler->add_err_descr
        (
             ERR_DESCR_NULL_OUTPUT_PARAM,
             "Transmittal",
             SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else if (!file_location || !file_location->characters)
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_INPUT_PARAM,
            "File Location",
            SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else
    {
        err_handler->set_status_code(
             raif_mngr->OpenTransmittalByLocation( file_location,
                              encoding, access_mode,
                              (SE_Api_Transmittal**)trans_out_ptr ) );
    }

    if (end_API_Call(SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION) ==
        SE_RETCOD_SUCCESS)
    {
       return SE_RETCOD_SUCCESS;
    }
    else
    {
       RAIFManager::Stop();
       return SE_RETCOD_FAILURE;
    }
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OpenTransmittalByName
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_OpenTransmittalByName
(
    const SE_URN         *trans_name,
          SE_Encoding     encoding,
          SE_Access_Mode  access_mode,
          SE_Transmittal *trans_out_ptr
)
{
    if (begin_API_Call(SE_APIFN_OPEN_TRANSMITTAL_BY_NAME) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if( trans_out_ptr ) *trans_out_ptr = NULL;

    if( !trans_out_ptr )
    {
        err_handler->add_err_descr
        (
            ERR_DESCR_NULL_OUTPUT_PARAM,
            "Transmittal Name",
            SE_STATCODE_INACTIONABLE_FAILURE
        );
    }
    else if (!trans_name || SE_ValidTransmittalName(trans_name) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid Transmittal Name",
                           SE_STATCODE_INVALID_TRANSMITTAL_NAME );
    }
    else
    {
        err_handler->set_status_code(
                 raif_mngr->OpenTransmittalByName(trans_name,
                                 encoding, access_mode,
                                 (SE_Api_Transmittal**)trans_out_ptr));
    }

    if( end_API_Call( SE_APIFN_OPEN_TRANSMITTAL_BY_NAME )
                                            == SE_RETCOD_SUCCESS )
    {
       return SE_RETCOD_SUCCESS;
    }
    else
    {
       RAIFManager::Stop();
       return SE_RETCOD_FAILURE;
    }
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ResolveObject
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_ResolveObject
(
    SE_Object object_in
)
{
SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_RESOLVE_OBJECT )
                             == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( !VALID_SHAREABLE(obj) )
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                       "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( obj->IsRemoved() )
    {
        err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                       "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( obj->IsResolved() )
    {
        err_handler->add_err_descr( "Object is already Resolved",
                                     SE_STATCODE_SUCCESS );
    }
    else
    {
        err_handler->set_status_code( raif_mngr->ResolveObject(obj) );
    }
    return end_API_Call(SE_APIFN_RESOLVE_OBJECT);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ResolveTransmittalName
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_ResolveTransmittalName
(
    const SE_URN   *trans_name_in,
          SE_Store  store_in,
          SE_URL   *location
)
{
   SE_Api_Store *store=(SE_Api_Store*)store_in;

    if( begin_API_Call( SE_APIFN_RESOLVE_TRANSMITTAL_NAME,
            NO_OBJECT_PARAM, store ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (location)
    {
        location->length     = 0;
        location->characters = NULL;
    }

    if (!trans_name_in || !location)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                       "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else if( !trans_name_in ||
              SE_ValidTransmittalName(trans_name_in) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid Transmittal Name",
                           SE_STATCODE_INVALID_TRANSMITTAL_NAME );
    }
    else
    {
        err_handler->set_status_code(
                 raif_mngr->ResolveTransmittalName( trans_name_in,
                                         store, location));
    }
    return end_API_Call(SE_APIFN_RESOLVE_TRANSMITTAL_NAME);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetSpecificCallback
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SetSpecificCallback
(
    SE_Status_Logger_Ptr user_defined_function,
    SE_API_Function      function_to_catch,
    SE_Status_Code       status_code_to_catch
)
{
    if( begin_API_Call(
          SE_APIFN_SET_SPECIFIC_CALLBACK ) == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (SE_ValidStatusCode(status_code_to_catch) == SE_FALSE ||
        SE_ValidAPIFunction(function_to_catch) == SE_FALSE)
    {
        err_handler->add_err_descr
        (
            "Invalid Status Code or Invalid Level 0 Function",
            SE_STATCODE_C_ENUMERATION_VALUE_INVALID
        );
    }
    else
    {
        err_handler->set_first_level_callback( user_defined_function,
                                    function_to_catch, status_code_to_catch);
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(SE_APIFN_SET_SPECIFIC_CALLBACK);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetColourModel
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SetColourModel
(
    SE_Colour_Model new_color_model
)
{
    if( begin_API_Call( SE_APIFN_SET_COLOUR_MODEL )
                                          == SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( SE_ValidColourModel(new_color_model) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid Colour Model",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
        err_handler->set_status_code(
                        raif_mngr->SetToColorModel(new_color_model) );
    }
    return end_API_Call(SE_APIFN_SET_COLOUR_MODEL);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetFirstErrorMessage
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SetFirstErrorMessage
(
    const SE_String *msg
)
{
    begin_API_Call( SE_APIFN_SET_FIRST_ERROR_MESSAGE );

    err_handler->set_first_error_msg(msg);
    err_handler->set_status_code( SE_STATCODE_SUCCESS );
    return SE_RETCOD_SUCCESS;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetGeneralCallback
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SetGeneralCallback
(
    SE_Status_Logger_Ptr user_defined_function
)
{
    begin_API_Call( SE_APIFN_SET_GENERAL_CALLBACK );

    err_handler->set_third_level_callback( user_defined_function );
    err_handler->set_status_code( SE_STATCODE_SUCCESS );
    return SE_RETCOD_SUCCESS;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetGeneralCallbackForOneFunction
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SetGeneralCallbackForOneFunction
(
    SE_Status_Logger_Ptr user_defined_function,
    SE_API_Function      function_to_catch
)
{
    if (begin_API_Call(
          SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION) == SE_RETCOD_FAILURE)
    {
       return SE_RETCOD_FAILURE;
    }

    if (SE_ValidAPIFunction(function_to_catch) == SE_FALSE)
    {
        err_handler->add_err_descr( "Invalid API Function",
                                   SE_STATCODE_C_ENUMERATION_VALUE_INVALID);
    }
    else
    {
        err_handler->set_second_level_callback(
                                  user_defined_function, function_to_catch );
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(
            SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION );
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetSecondErrorMessage
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SetSecondErrorMessage
(
    const SE_String *msg
)
{
    begin_API_Call( SE_APIFN_SET_SECOND_ERROR_MESSAGE );

    err_handler->set_second_error_msg(msg);
    err_handler->set_status_code( SE_STATCODE_SUCCESS );
    return SE_RETCOD_SUCCESS;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_SetSRFContextInfo
(
    SE_SRF_Context_Info new_SRF_info
)
{
    if( begin_API_Call( SE_APIFN_SET_SRF_CONTEXT_INFO )
                                           ==  SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if( SE_ValidSRFContextInfo( &new_SRF_info, SE_FALSE, NULL) == SE_FALSE )
    {
        err_handler->add_err_descr( "Invalid SRF Info",
                                     SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
            raif_mngr->SetToSRFInfo( &new_SRF_info ) );
    }
    return end_API_Call( SE_APIFN_SET_SRF_CONTEXT_INFO );
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UseDefaultSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_UseDefaultSRFContextInfo(void)
{
    begin_API_Call( SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO );

    err_handler->set_status_code(
        raif_mngr->SetToSRFInfo((SE_SRF_Context_Info*)NULL));
    return SE_RETCOD_SUCCESS;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetUserData
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_SetUserData
(
    const SE_User_Data user_data,
          SE_Object    object_in
)
{
    SE_Api_Object *obj=(SE_Api_Object*)object_in;

    if( begin_API_Call( SE_APIFN_SET_USER_DATA,
                            obj ) ==  SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!user_data)
    {
        err_handler->add_err_descr(ERR_DESCR_NULL_OUTPUT_PARAM,
                        "User Data", SE_STATCODE_INACTIONABLE_FAILURE);
    }
    else
    {
        obj->GetIntObj()->set_user_data(user_data);
        err_handler->set_status_code( SE_STATCODE_SUCCESS );
    }
    return end_API_Call(SE_APIFN_SET_USER_DATA );
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_TransmittalsAreSame
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_TransmittalsAreSame
(
    SE_Transmittal  trans_a_in,
    SE_Transmittal  trans_b_in,
    SE_Boolean     *result_out_ptr
)
{
    SE_Api_Transmittal *trans_a=(SE_Api_Transmittal *)trans_a_in;
    SE_Api_Transmittal *trans_b=(SE_Api_Transmittal *)trans_b_in;

    if (begin_API_Call( SE_APIFN_TRANSMITTALS_ARE_SAME,
               NO_OBJECT_PARAM, trans_a, trans_b ) ==  SE_RETCOD_FAILURE )
    {
       return SE_RETCOD_FAILURE;
    }

    if (!result_out_ptr)
    {
        err_handler->add_err_descr( ERR_DESCR_NULL_OUTPUT_PARAM,
                        "Same As Flag", SE_STATCODE_INACTIONABLE_FAILURE );
    }
    else
    {
        err_handler->set_status_code(
              raif_mngr->TransmittalsAreSame(
                            trans_a, trans_b, result_out_ptr ) );
    }
    return end_API_Call(SE_APIFN_TRANSMITTALS_ARE_SAME);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UseDefaultColourModel
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code SE_UseDefaultColourModel(void)
{
    begin_API_Call( SE_APIFN_USE_DEFAULT_COLOUR_MODEL );

    err_handler->set_status_code(
        raif_mngr->SetColorModel((SE_Colour_Model)-1) );
    return SE_RETCOD_SUCCESS;
}


/*
 *-----------------------------------------------------------------------------
 *
 *   FUNCTION - SE_GetImplVerInfo (implementation specific)
 *
 *   This function returns the implementation version of the API component.
 *
 *-----------------------------------------------------------------------------
 */
const char* SE_GetImplVerInfo(void)
{
    return "4.1.4";
}


} // End of extern "C" section
