// SEDRIS Level 0 Read API
//
// FILE:        se_search_point_support.cpp
//
// PROGRAMMERS: Howard Lu, Michele L. Worley (SAIC);
//              Julian C. Lander (MITRE), Warren Macchi (Arteon)
//
// DESCRIPTION: Provides support for SEDRIS Search Boundaries
//              by supporting retrieval of search points from
//              locatable SEDRIS objects.
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

#include <math.h>

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "se_search_point_support.hpp"
#include "se_search_util.hpp"
#include "se_search_coord.hpp"
#include "SE_SearchBoundary.hpp"

#include "SE_ComponentIterator.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_API_Object.hpp"

#include "raif_srm_utils.h"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


static SE_Status_Code se_search_add_points(
    SE_OBJECT_SEARCH_POINT *old_point,
    SE_OBJECT_SEARCH_POINT *cum_point );


//   Helper function to retrieve a location from an object and add it to
//   a search point.
//
SE_Status_Code get_location_based_search_point(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr )
{
    SE_Status_Code   status;
    SE_Api_Object   *location=NULL;

    null_search_point(point_ptr);

    status = obj->GetNthComponentOfDRMClass( 0,
                    SE_CLS_DRM_LOCATION, &location, NULL);

    status = ( OBJSTATUS_VALID(status) ?
               SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status != SE_STATCODE_SUCCESS)
    {
        obj->raif_mngr()->add_err_descr("get_location_based_search_point: "\
                        "Can't get location");
    }
    else
    {
        // Here it's OK to use point_ptr directly, because its internal
        // pointers don't belong to another object
        //
        status = se_search_point_from_location(location, point_ptr);

        SAFE_RELEASE(location);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("get_location_based_search_point: "\
                        "Can't get point from location.");
    }
    return status;
}


//   Helper function to retrieve the search point from an object and add it to
//   another search point.
//
static SE_Status_Code add_obj_search_point(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr )
{
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_POINT *obj_point_ptr;

    obj_point_ptr = SE_SearchBoundary::getSearchPoint(obj);

    if (!obj_point_ptr)
    {
        obj->raif_mngr()->add_err_descr("add_obj_search_point: failed getSearchPoint()");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        status = se_search_add_points(obj_point_ptr, point_ptr);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("add_obj_search_point: "\
                     "Can't combine search points.");
    }
    return status;
}

//----------------------------------------------------------------------------
// FUNCTION: add_all_assocs_search_points()
//
//   Helper function to retrieve the search points from the assocs of an
//   object and add them to another search point.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//----------------------------------------------------------------------------
SE_Status_Code add_all_assocs_search_points
(
    SE_Api_Object          *obj,
    SE_DRM_Class            include_type,
    SE_DRM_Class            exclude_type,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Api_Object      *assoc=NULL;
    SE_Integer_Unsigned i = 0;

    null_search_point(&avg_search_point);

    status = obj->GetNthAssociateOfDRMClass(i, include_type, &assoc, NULL);

    status = (OBJSTATUS_VALID(status) ?
                  SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status;

        if (assoc->tag() != exclude_type)
            status = add_obj_search_point(assoc, &avg_search_point);

        SAFE_RELEASE(assoc);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("add_all_assocs_search_points: failed");
            break;
        }
        i++;
        tmp_status = obj->GetNthAssociateOfDRMClass(
                                 i, include_type, &assoc, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;
    }
    *point_ptr = avg_search_point;

    return status;
}


//   Helper function to retrieve the search points from the components of an
//   object and add them to another search point.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//
SE_Status_Code add_all_components_search_points(
    SE_Api_Object          *obj,
    SE_DRM_Class            include_type,
    SE_DRM_Class            exclude_type,
    SE_OBJECT_SEARCH_POINT *point_ptr )
{
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Api_Object      *component=NULL;
    SE_Integer_Unsigned i = 0;

    null_search_point(&avg_search_point);

    status = obj->GetNthComponentOfDRMClass(i, include_type, &component, NULL);

    status = (OBJSTATUS_VALID(status) ?
                SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status;

        if (component->tag() != exclude_type)
            status = add_obj_search_point(component, &avg_search_point);

        SAFE_RELEASE(component);
        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("add_all_components_search_points: failed");
            break;
        }
        i++;
        tmp_status = obj->GetNthComponentOfDRMClass( i,
                             include_type, &component, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;
    }
    *point_ptr = avg_search_point;

    return status;
}


//   Helper function to add the search point from a location object to
//   another search point.
//
static SE_Status_Code add_location_search_point(
    SE_Api_Object          *location,
    SE_OBJECT_SEARCH_POINT *point_ptr )
{
    SE_Status_Code    status;
    SE_OBJECT_SEARCH_POINT new_search_point;

    status = se_search_point_from_location(location, &new_search_point);

    if (status != SE_STATCODE_SUCCESS)
    {
        location->raif_mngr()->add_err_descr("add_location_search_point: "\
                 "Can't get point from location.");
    }
    else
    {
        status = se_search_add_points(&new_search_point, point_ptr);

        if (status != SE_STATCODE_SUCCESS)
            location->raif_mngr()->add_err_descr("add_location_search_point: "\
                    "Can't add search points.");
    }
    return status;

} // end add_location_search_point


//   Helper function to retrieve the search points from the location
//   components of an object and add them to another search point.
//
//   maxLocations can be used to specify the number of locations added (=0
//   to add all found)
//   doDepth2 is a flag to search locations at a depth of 2
//
SE_Status_Code add_all_locations_search_points(
    SE_Api_Object          *obj,
    SE_Boolean              doDepth2,
    SE_Integer_Unsigned     maxLocations,
    SE_OBJECT_SEARCH_POINT *point_ptr)
{
    SE_Status_Code          status = SE_STATCODE_SUCCESS;
    SE_SearchFilter        *search_filter;
    SE_ComponentIterator   *iter;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Api_Object          *location=NULL;
    SE_Integer_Unsigned     i = 0;

    static SE_Search_Rule location1_search_rules[] =
                    {
                        SE_AND(SE_DRM_CLASS_MATCH(LOCATION),
                               SE_MAX_SEARCH_DEPTH(1) )
                        SE_END
                    };


    /* We search to a depth of 2 to find the locations in the vertices */
    static SE_Search_Rule location2_search_rules[] =
                    {
                        SE_AND(SE_DRM_CLASS_MATCH(LOCATION),
                               SE_MAX_SEARCH_DEPTH(2) )
                        SE_END
                    };

    null_search_point(&avg_search_point);

    search_filter = new SE_SearchFilter( obj->raif_mngr(),
          (doDepth2 ? location2_search_rules : location1_search_rules) );

    iter = new SE_ComponentIterator(obj->raif_mngr(), obj,
                    search_filter,
                    SE_TRUE, /* attach tables */
                    SE_FALSE, /* no inheritance */
                    SE_TRUE, /* apply transforms */
                    SE_FALSE, /* don't follow models */
                    SE_TRUE, /* evaluate clinks */
                    NULL, /* no search bounds here */
                    NULL, /* no select params */
                    NULL, /* no order params */
                    SE_TRAVORDR_DEPTH_FIRST );

    SAFE_RELEASE(search_filter);

    while ((maxLocations == 0 || i < maxLocations) &&
            status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status = iter->next_object(&location, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;

        status = add_location_search_point(location, &avg_search_point);

        SAFE_RELEASE(location);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("add_all_locations_search_points: failed");
            break;
        }
        i++;
    }
    delete iter;

    *point_ptr = avg_search_point;

    return status;
} // end add_all_locations_search_points


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_topology_hierarchy_search_point
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_topology_hierarchy_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_SearchFilter        *search_filter;
    SE_ComponentIterator   *iter;
    SE_Api_Object          *component = NULL;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Status_Code          status = SE_STATCODE_SUCCESS;
    SE_Boolean              universal_feature_face = SE_FALSE;

    static SE_Search_Rule union_of_feature_topology_rules[] =
           {
              SE_AND3
              (
                 SE_FIELD_MATCH
                 (
                    FEATURE_FACE, Feature_Face, universal,
                    &universal_feature_face, SE_SEARCHVALTYP_BOOLEAN
                 ),
                 SE_DRM_CLASS_MATCH(FEATURE_TOPOLOGY),
                 SE_MAX_SEARCH_DEPTH(1)
              )
              SE_END
           };

    null_search_point(&avg_search_point);

    search_filter = new SE_SearchFilter( obj->raif_mngr(),
                                         union_of_feature_topology_rules );

    iter = new SE_ComponentIterator( obj->raif_mngr(), obj,
                     search_filter,
                     SE_FALSE, /* don't attach tables */
                     SE_FALSE, /* no inheritance */
                     SE_TRUE, /* apply transforms */
                     SE_FALSE, /* don't follow models */
                     SE_TRUE, /* evaluate clinks */
                     NULL, /* no search bounds here */
                     NULL, /* no select params */
                     NULL, /* no order params */
                     SE_TRAVORDR_DEPTH_FIRST );

    SAFE_RELEASE(search_filter);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status = iter->next_object(&component, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;

        status = add_obj_search_point(component, &avg_search_point);

        SAFE_RELEASE(component);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("se_search_get_topology_hierarchy_search_point: "\
                    "failed to add search point");
            break;
        }
    }
    delete iter;

    *point_ptr = avg_search_point;

    return status;
} // end se_search_get_topology_hierarchy_search_point


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_aggregate_feature_search_point
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_aggregate_feature_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_SearchFilter        *search_filter;
    SE_ComponentIterator   *iter;
    SE_Api_Object          *component=NULL;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Status_Code          status = SE_STATCODE_SUCCESS;

    static SE_Search_Rule union_of_feature_search_rules[] =
                {
                    SE_AND
                    (
                        SE_OR
                        (
                            SE_DRM_CLASS_MATCH(FEATURE_REPRESENTATION),
                            SE_DRM_CLASS_MATCH(FEATURE_TOPOLOGY_HIERARCHY)
                        ),
                        SE_MAX_SEARCH_DEPTH(1)
                    )
                    SE_END
                };

    static SE_Search_Rule feature_hierarchy_search_rules[] =
                {
                    SE_AND
                    (
                        SE_OR
                        (
                            SE_DRM_CLASS_MATCH(FEATURE_HIERARCHY),
                            SE_DRM_CLASS_MATCH(FEATURE_TOPOLOGY_HIERARCHY)
                        ),
                        SE_MAX_SEARCH_DEPTH(1)
                    )
                    SE_END
                };

    null_search_point(&avg_search_point);

    search_filter = new SE_SearchFilter( obj->raif_mngr(),
           (obj->tag() == SE_CLS_DRM_UNION_OF_FEATURES ?
            union_of_feature_search_rules : feature_hierarchy_search_rules) );

    iter = new SE_ComponentIterator(obj->raif_mngr(), obj,
                    search_filter,
                    SE_FALSE, /* don't attach tables */
                    SE_FALSE, /* no inheritance */
                    SE_TRUE, /* apply transforms */
                    SE_FALSE, /* don't follow models */
                    SE_TRUE, /* evaluate clinks */
                    NULL, /* no search bounds here */
                    NULL, /* no select params */
                    NULL, /* no order params */
                    SE_TRAVORDR_DEPTH_FIRST);

    SAFE_RELEASE(search_filter);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status = iter->next_object(&component, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;

        status = add_obj_search_point(component, &avg_search_point);

        SAFE_RELEASE(component);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("se_search_get_aggregate_feature_search_point: "\
                    "failed to add search point");
            break;
        }
    }
    delete iter;

    *point_ptr = avg_search_point;

    return status;
}


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_aggregate_geometry_search_point
//
//   Caller has encountered an <Aggregate Geometry>; we don't need to check
//   that it's an <Aggregate Geometry>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_aggregate_geometry_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_Api_Object          *component = NULL;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_DRM_Class            object_type;
    SE_Status_Code          status = SE_STATCODE_SUCCESS;

    null_search_point(&avg_search_point);

    object_type = obj->tag();

    if (object_type == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
    {
        status = obj->GetNthComponentOfDRMClass( 0,
                   SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY, &component, NULL);

        status = (OBJSTATUS_VALID(status) ?
                   SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

        if (status == SE_STATCODE_SUCCESS)
        {
            status = add_obj_search_point(component, &avg_search_point);

            SAFE_RELEASE(component);
        }
    }
    else if (object_type == SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY)
    {
        status = add_obj_search_point(obj, &avg_search_point);
    }
    else
    {
       SE_DRM_Class findt; //, skipt;

        if (object_type == SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY)
        {
            findt = SE_CLS_DRM_PRIMITIVE_GEOMETRY;
        }
        else
        {
            findt = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        }

        status = add_all_components_search_points(obj, findt, SE_CLS_DRM_NULL,
                                                    &avg_search_point);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("se_search_get_aggregate_geometry_search_point: "\
                    "failed add_all_components_search_points()");
    }
    *point_ptr = avg_search_point;

    return status;
} // end se_search_get_aggregate_geometry_search_point


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_feature_edge_search_point
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_feature_edge_search_point
(
    SE_Api_Object          *fedgeObj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_Api_Object  *locObj, *fnodeObj;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Status_Code         status = SE_STATCODE_SUCCESS;
    SE_Integer_Unsigned  locs_added=0;

    null_search_point(&avg_search_point);

    // get intermediate locations
    status = add_all_locations_search_points(fedgeObj, SE_FALSE, 0,
                                            &avg_search_point);

    if (status != SE_STATCODE_SUCCESS)
    {
        fedgeObj->raif_mngr()->add_err_descr("se_search_get_feature_edge_search_point: "\
                    "failed to add locations");
        return status;
    }
    // first get the start and end locations which are components of
    // the associated feature nodes
    //
    status = fedgeObj->GetNthAssociateOfDRMClass( 0,
                         SE_CLS_DRM_FEATURE_NODE, &fnodeObj, NULL );

    if( OBJSTATUS_VALID(status) )
    {
       status = fnodeObj->GetNthComponentOfDRMClass( 0,
                         SE_CLS_DRM_LOCATION, &locObj, NULL );

       if( OBJSTATUS_VALID(status) )
       {
          status = add_location_search_point( locObj, &avg_search_point );

          SAFE_RELEASE( locObj );

          if( OBJSTATUS_VALID(status) )
          {
              locs_added++;
          }
          else
          {
              fedgeObj->raif_mngr()->add_err_descr("se_search_get_feature_edge_search_point: "\
                       "Can't add location to point");
          }
       }
       SAFE_RELEASE( fnodeObj );
    }
    status = fedgeObj->GetNthAssociateOfDRMClass( 1,
                         SE_CLS_DRM_FEATURE_NODE, &fnodeObj, NULL );

    if( OBJSTATUS_VALID(status) )
    {
       status = fnodeObj->GetNthComponentOfDRMClass( 0,
                         SE_CLS_DRM_LOCATION, &locObj, NULL );

       if( OBJSTATUS_VALID(status) )
       {
          status = add_location_search_point( locObj, &avg_search_point );

          SAFE_RELEASE( locObj );

          if( OBJSTATUS_VALID(status) )
          {
              locs_added++;
          }
          else
          {
              fedgeObj->raif_mngr()->add_err_descr("se_search_get_feature_edge_search_point: "\
                       "Can't add location to point");
          }
       }
       SAFE_RELEASE( fnodeObj );
    }

    *point_ptr = avg_search_point;

    return (locs_added ? SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE );

} // end se_search_get_feature_edge_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_geometry_model_instance_search_point
//
//   Caller has encountered a <Geometry Model Instance>; we don't need to
//   check that it's a <Geometry Model Instance>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_geometry_model_instance_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_Api_Object          *component=NULL, *model=NULL;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Status_Code          status = SE_STATCODE_SUCCESS;

   /*
    * If this model instance has a World Transformation, we return the location
    * associated with the transformation. If it does not, it is in the
    * Environment Root SRF, and we return the search point for
    * the geometry component of the model.
    */

    null_search_point(&avg_search_point);

    status = obj->GetNthComponentOfDRMClass(0, SE_CLS_DRM_WORLD_TRANSFORMATION,
                        &component, NULL);

    status = (OBJSTATUS_VALID(status) ?
                  SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status == SE_STATCODE_SUCCESS)
    {
        status = get_location_based_search_point(component, &avg_search_point);

        SAFE_RELEASE(component);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("se_search_get_geometry_model_instance_search_point: "\
                    "failed to get location point from world xform");
    }
    else
    {
        SAFE_RELEASE(component);
        status = obj->get_nth_association(0, &model, NULL,
                              SE_CLS_DRM_GEOMETRY_MODEL, SE_ITRBEH_RESOLVE);

        if (!OBJSTATUS_VALID(status))
        {
            obj->raif_mngr()->add_err_descr("se_search_get_geometry_model_instance_search_point: "\
                    "Can't get Geometry Model.");
        }
        else
        {
            status = model->GetNthComponentOfDRMClass( 0,
                        SE_CLS_DRM_GEOMETRY_HIERARCHY, &component, NULL);

            status = (OBJSTATUS_VALID(status) ?
                         SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

            if (status != SE_STATCODE_SUCCESS)
            {
                obj->raif_mngr()->add_err_descr("se_search_get_geometry_model_instance_search_point: "\
                        "Can't get Geometry Hierarchy.");
            }
            else
            {
                status = add_obj_search_point(component, &avg_search_point);
                SAFE_RELEASE(component);
            }
        }
        SAFE_RELEASE(model);
    }

    *point_ptr = avg_search_point;

    return status;
} // end se_search_get_geometry_model_instance_search_point


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_feature_model_instance_search_point
//
//   Caller has encountered a <Feature Model Instance>; we don't need to
//   check that it's a <Feature Model Instance>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_feature_model_instance_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_Api_Object          *component=NULL, *model=NULL;
    SE_OBJECT_SEARCH_POINT  avg_search_point;
    SE_Status_Code          status = SE_STATCODE_SUCCESS;

   /*
    * If this model instance has a World Transformation, we return the location
    * associated with the transformation. If it does not, it is in the
    * Environment Root SRF, and we return the search point for
    * the geometry component of the model.
    */

    null_search_point(&avg_search_point);

    status = obj->GetNthComponentOfDRMClass(0, SE_CLS_DRM_WORLD_TRANSFORMATION,
                        &component, NULL);

    status = (OBJSTATUS_VALID(status) ?
                   SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status == SE_STATCODE_SUCCESS)
    {
        status = get_location_based_search_point(component, &avg_search_point);

        SAFE_RELEASE(component);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("se_search_get_feature_model_instance_search_point: "\
                    "failed to get location point from world xform");
    }
    else
    {
        SAFE_RELEASE(component);

        status = obj->get_nth_association(0, &model, NULL,
                        SE_CLS_DRM_FEATURE_MODEL, SE_ITRBEH_RESOLVE);

        if (!OBJSTATUS_VALID(status))
        {
            obj->raif_mngr()->add_err_descr("se_search_get_feature_model_instance_search_point: "\
                    "Can't get Feature Model.");
        }
        else
        {
            status = model->GetNthComponentOfDRMClass( 0,
                       SE_CLS_DRM_FEATURE_HIERARCHY, &component, NULL);

            status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

            if (status != SE_STATCODE_SUCCESS)
            {
                obj->raif_mngr()->add_err_descr("se_search_get_feature_model_instance_search_point: "\
                        "Can't get Feature Hierarchy.");
            }
            else
            {
                status = add_obj_search_point(component,
                                                    &avg_search_point);
                SAFE_RELEASE(component);
            }
        }
        SAFE_RELEASE(model);
    }
    *point_ptr = avg_search_point;

    return status;
} // end se_search_get_feature_model_instance_search_point


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_point_feature_search_point
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_point_feature_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
)
{
    SE_Api_Object   *node;
    SE_Status_Code   status = SE_STATCODE_SUCCESS;

    status = obj->GetNthAssociateOfDRMClass( 0,
                              SE_CLS_DRM_FEATURE_NODE, &node, NULL);

    status = (OBJSTATUS_VALID(status) ?
                 SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status != SE_STATCODE_SUCCESS)
    {
        obj->raif_mngr()->add_err_descr("se_search_get_point_feature_search_point: failed");
    }
    else
    {
        status = add_obj_search_point(node, point_ptr);
        SAFE_RELEASE(node);
    }
    return status;
} // end se_search_get_point_feature_search_point


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_add_points
//
//   Define a function to combine search points.
//
//----------------------------------------------------------------------------
static SE_Status_Code se_search_add_points
(
    SE_OBJECT_SEARCH_POINT *old_point,
    SE_OBJECT_SEARCH_POINT *cum_point
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if( cum_point->num_contributing_pts == 0 )
    {
        // The avg is empty; replace the avg with the new point
        //
        memcpy( &(cum_point->srf_info), &(old_point->srf_info), sizeof( SE_SRF_Context_Info ));
        cum_point->num_contributing_pts = old_point->num_contributing_pts;

        cum_point->point = old_point->point;
    }
    else if( !SE_SRFContextInfoEqual(&old_point->srf_info,
                               &cum_point->srf_info ) )
    {
         raif_mngr->add_err_descr("se_search_add_points: Mismatched coordinate parameters.");
         status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
    // We only need to average if we have points in the old_point

        se_search_coord_get_average_point( old_point, cum_point );

        cum_point->num_contributing_pts += old_point->num_contributing_pts;
    }
    return status;
}


//   Creates a point from a Location object (of any subclass of Location,
//   both 2- and 3D.)
//
SE_Status_Code se_search_point_from_location
(
    SE_Api_Object          *location_obj,
    SE_OBJECT_SEARCH_POINT *point
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_FIELDS_PTR  loc_fields;

    loc_fields = location_obj->fields(&status);

    if (OBJSTATUS_VALID(status))
    {
        null_search_point(point);
        location_obj->get_srf_info( &point->srf_info );

        point->num_contributing_pts = 1;

        if( !SE_ConvertFieldsToCoordinate( loc_fields, &point->point ) )
        {
            location_obj->raif_mngr()->add_err_descr("se_search_point_from_location: Can't parse location.");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    else
    {
        location_obj->raif_mngr()->add_err_descr("se_search_point_from_location: Can't get location fields.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
} // end se_search_point_from_location


//-----------------------------------------------------------------------------
//
// FUNCTION: point_in_search_bounds
//
//   Checks whether a single point is within a box. Both are assumed to be in
//   the same SRF with the same SRF parameters.
//
// PARAMETERS:
//
//   point - the point to be checked; caller guarantees that the pointer is
//           non-NULL
//
//   bounds - the search bounds with min/max coords for the box
//
//   closure   - whether the upper coordinate values of the box are included
//               (SE_SEARCH_BNDS_CLOSURE_FULL) or not (SE_SEARCH_BNDS_CLOSURE_PARTIAL).
//
//   inclusion - OUT parameter; SE_TRUE if the point is in bounds, SE_FALSE
//               otherwise
//
// RETURNS:
//
//   SE_STATCODE_SUCCESS - if the check succeeded
//
//   SE_STATCODE_INACTIONABLE_FAILURE - any other error, such as 2D specified for an
//                SRF that does not support <Location 2D>
//
//-----------------------------------------------------------------------------
static SE_Status_Code point_in_search_bounds
(
       SRM_Coordinate           *point,
       SE_Search_Bounds         *bounds,
       SE_Search_Bounds_Closure  closure,
       SE_Boolean               *inclusion
)
{
    SE_Boolean result = SE_FALSE;
    SRM_Long_Float  ptX,  ptY,  ptZ;
    SRM_Long_Float  minX,  minY,  minZ,  maxX,  maxY,  maxZ;
    SRM_Long_Float  minZ_limit=SE_NEGATIVE_INFINITY;
    SRM_Long_Float  maxZ_limit=SE_POSITIVE_INFINITY;
    *inclusion = SE_FALSE;

// Get the x,y, and z of the search box.

    se_get_coords( &bounds->minimum_point, &minX, &minY, &minZ);
    se_get_coords( &bounds->maximum_point, &maxX, &maxY, &maxZ);

// 2D and surface coordinates will have unbounded z values.
//
    if( RAIFCoordIs2D( bounds->minimum_point.spatial_coord_code ) ||
        RAIFCoordIsSurface( bounds->minimum_point.spatial_coord_code ) )
    {
       minZ = minZ_limit;
       maxZ = maxZ_limit;
    }
    se_get_coords( point, &ptX, &ptY, &ptZ );

// we always check x and y but only check Z if the point and the box
// are not 3D. Thus if we have a 2D search box the third dimension is infinity.
//
    if (!RAIFCoordIsAngular( point->spatial_coord_code ) )
    {
        switch (closure)
        {
          case SE_SEARCHBNDSCLS_FULLY_CLOSED:
              if( ptX >= minX && ptX <= maxX &&
                  ptY >= minY && ptY <= maxY &&
                  ( RAIFCoordIs2D( point->spatial_coord_code ) ||
                  ( RAIFCoordIs3D( point->spatial_coord_code ) &&
                    ptZ >= minZ && ptZ <= maxZ ) ) )
              result = SE_TRUE;
              break;

          case SE_SEARCHBNDSCLS_PARTIALLY_CLOSED:

              if( ptX >= minX && ptX < maxX &&
                  ptY >= minY && ptY < maxY &&
                  ( RAIFCoordIs2D( point->spatial_coord_code ) ||
                  ( RAIFCoordIs3D( point->spatial_coord_code ) &&
                    ptZ >= minZ && ptZ < maxZ ) ) )
              result = SE_TRUE;
              break;
        }
    }
    else
    {
        if( se_within_angular_range(ptX, minX, maxX, closure))
        {
            result = se_within_angular_range(ptY, minY, maxY, closure);

            if( result && RAIFCoordIs3D( point->spatial_coord_code ) )
            {
                switch (closure)
                {
                    case SE_SEARCHBNDSCLS_FULLY_CLOSED:
                       result =(SE_Boolean)(minZ <= ptZ && ptZ <= maxZ);
                       break;
                    case SE_SEARCHBNDSCLS_PARTIALLY_CLOSED:
                       result =(SE_Boolean)(minZ <= ptZ && ptZ < maxZ);
                       break;
                }
            }
        }
    }
    *inclusion = result;

    return SE_STATCODE_SUCCESS;
} /* end point_in_search_bounds */


//----------------------------------------------------------------------------
//
// FUNCTION: determine_2D_point_inclusion
//
//   Determines whether a 2-dimensional point (which must be in GD or a
//   projection SRF originally) is "included" in a 3-dimensional search
//   boundary. Note that some of the arguments are redundant.
//   This is deliberate.
//
// PARAMETERS:
//
//   orig_point_parameters_ptr - the SRF parameters of the
//       2D point before any conversions take place
//
//   orig_point_ptr - pointer to the location of the 2D point in the
//       original SRF
//
//   bounds_srf_info - the SRF parameters in which the
//       search boundary is expressed
//
//   bounds_ptr - the search boundary (3D)
//
//   converted_point_ptr - the location of the 2D point in the search boundary
//       SRF; pointer is guaranteed to be non-NULL by the caller
//
//   search_bounds_closure - is the boundary fully or partly closed
//
//   inclusion_status - the answer determined by this function. The caller
//                      guarantees that this pointer is non-NULL.
//
//----------------------------------------------------------------------------
static SE_Status_Code
determine_2D_point_inclusion
(
    const SE_SRF_Context_Info        *orig_point_srf_info_ptr,
          SRM_Coordinate             *orig_point_ptr,
    const SE_SRF_Context_Info        *bounds_srf_info,
          SE_Search_Bounds           *bounds_ptr,
          SRM_Coordinate             *converted_point_ptr,
          SE_Search_Bounds_Closure   search_bounds_closure,
          SE_Boolean                *inclusion_status /* out parameter */
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (bounds_srf_info->srf_parameters_info.srf_params_info_code !=
        SRM_SRFPARAMINFCOD_TEMPLATE)
    {
        raif_mngr->add_err_descr("determine_2D_point_inclusion: Don't support srf info not using parameters");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if( RAIFSRFIs2D(bounds_srf_info->srf_parameters_info.value.srf_template.template_code))
    {
        /*
         * We can do a 2D search in this SRF directly.
         */
        status = point_in_search_bounds(
                     converted_point_ptr,
                     bounds_ptr,
                     search_bounds_closure,
                     inclusion_status );
    }
    else
    {
        /*
         * Here a single 2D point in 2D space becomes a half-line in Cartesian
         * 3D space, and the line doesn't point in an easily defined direction.
         * $$$ We need to build an algorithm for this.
         */
        *inclusion_status = SE_FALSE;
    }
    return status;
} /* end determine_2D_point_inclusion */



//----------------------------------------------------------------------------
//
// FUNCTION: se_search_determine_object_point_inclusion
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_determine_object_point_inclusion
(
    const SE_OBJECT_SEARCH_POINT   *point_ptr,
    const SE_SRF_Context_Info      *bounds_srf_info,
    const SE_Search_Bounds         *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Dimension       search_dimension,
          SE_Boolean               *object_included // OUT
)
{
    SE_OBJECT_SEARCH_POINT working_point;
    SRM_Coordinate         grand_avg;
    SE_Boolean             inclusion_status;
    SE_Status_Code         status = SE_STATCODE_SUCCESS;

    *object_included = SE_FALSE;

    if (point_ptr->num_contributing_pts == 0 )
    {
        raif_mngr->add_err_descr("se_search_determine_object_point_inclusion: "\
                "Badly-formed search point.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SRM_SRFT_Code template_code = bounds_srf_info->srf_parameters_info.value.srf_template.template_code;

        // Ignore models when doing a geographic world search
        //
        if((point_ptr->point.spatial_coord_code == SRM_SPACOORDCOD_LSR_2D ||
            point_ptr->point.spatial_coord_code == SRM_SPACOORDCOD_LSR_3D ) &&
            template_code != SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D )
        {
            return SE_STATCODE_SUCCESS;
        }
        memcpy( &working_point.srf_info, bounds_srf_info, sizeof( SE_SRF_Context_Info ));

        working_point.num_contributing_pts = point_ptr->num_contributing_pts;

        if( RAIFChangeCoordSRFFromContextInfo( &point_ptr->srf_info, &point_ptr->point,
                             bounds_srf_info, &working_point.point ) != SRM_STATCOD_SUCCESS )
        {
            raif_mngr->add_err_descr("se_search_determine_object_point_inclusion: "\
                    "Can't convert search point to requested SRF.");
            return status;
        }
    }

    /*
     * We now have a working point in the matching SRF if
     * we can use it.  Next we need to deal with the dimension of the
     * search.
     */
    switch (search_dimension)
    {
    case SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE:
        /*
         * We know (from checking at the beginning) that the boundary
         * SRF is a real 2D SRF, so we are working in the proper SRF.
         * We need to average the 2D and 3D components into a grand
         * average, which is the point to check for inclusion.
         */
        /*
         * Start with the 2D portion
$$$ removed code that derived 2d coords from 3d ones and averaged
    with the 2d points.
    if this still needs to be done, do it in the averaging process.
         */
/********
        if (working_point.count_2d > 0)
        {
            grand_avg.dimensionality = SRM_DIM_TWO_D;
            grand_avg.coordinate.two_d = working_point.point_2d;

            // Combine with the 3D portion if it exists
            if (working_point.count_3d > 0)
            {
                SE_OBJECT_SEARCH_POINT working_3d_point;
// Convert the 3D summary into a 2D form by dropping the "height" components.
                null_search_point(&working_3d_point);
                working_3d_point.count_2d = working_point.count_3d;
$$$ not supposed to do this anymore
                if( SRM_DeriveCoordinate2DFrom3D(&working_point.point_3d,
                        &working_3d_point.point_2d) != SRM_STATCOD_SUCCESS)
                {
                 raif_mngr->add_err_descr("se_search_determine_object_point_inclusion: "\
                            "Can't derive 2D from 3D point.");
                 return SE_STATCODE_INACTIONABLE_FAILURE;
                }

// We have both 2d and 3d contributions. Average them.
                if (!se_search_coord_get_average_point( &working_3d_point,
                            &working_point))
                {
                    raif_mngr->add_err_descr("se_search_determine_object_point_inclusion: "\
                            "Can't combine search point components.");
                    return SE_STATCODE_INACTIONABLE_FAILURE;
                }
                else
                {
                    grand_avg.dimensionality = SRM_DIM_TWO_D;
                    grand_avg.coordinate.two_d = working_point.point_2d;
                    status = SE_STATCODE_SUCCESS;
                }
            }
        }
        else
********************/
        {
//          grand_avg.dimensionality = SRM_DIM_THREE_D;
//          grand_avg.coordinate.three_d = working_point.point_3d;
        }
        grand_avg = working_point.point;

        status = point_in_search_bounds( &grand_avg,
                      (SE_Search_Bounds *)bounds_ptr,
                          search_bounds_closure, &inclusion_status );
        break;

    case SE_SEARCHDIM_THREE_DIMENSIONAL:
        if( working_point.num_contributing_pts == 0 )
        {
            inclusion_status = SE_FALSE;
        }
        else
        {
            grand_avg = working_point.point;

            status = point_in_search_bounds( &grand_avg,
                          (SE_Search_Bounds *) bounds_ptr,
                              search_bounds_closure, &inclusion_status );
        }
        break;

    case SE_SEARCHDIM_ALL_DIMENSIONS:
// $$$ need to rework this???
//  this code doesn't implement the commented out code below
//
            grand_avg = working_point.point;

            status = point_in_search_bounds( &grand_avg,
                          (SE_Search_Bounds *) bounds_ptr,
                              search_bounds_closure, &inclusion_status );


/**********
        if (working_point.num_contributing_pts > 0)
        {
            grand_avg.dimensionality = SRM_DIM_THREE_D;
            grand_avg.coordinate.three_d = working_point.point_3d;

            status = point_in_search_bounds( &grand_avg,
                          (SE_Search_Bounds *)bounds_ptr,
                              search_bounds_closure, &inclusion_status );
        }
        else
        {
            inclusion_status = SE_TRUE; // no 3D point, all 3D pts are included
        }

        if (status == SE_STATCODE_SUCCESS && working_point.count_2d > 0)
        {
            grand_avg.dimensionality = SRM_DIM_TWO_D;
            grand_avg.coordinate.two_d = point_ptr->point_2d;

            status = determine_2D_point_inclusion(
                         &point_ptr->srf_info, NULL,
                         bounds_srf_info, (SE_Search_Bounds *) bounds_ptr,
                         &grand_avg,
                         search_bounds_closure,
                         &inclusion_status2 );
            inclusion_status =
                          (SE_Boolean)(inclusion_status && inclusion_status2);
        }
**********/
        break;

    default:
        raif_mngr->add_err_descr("se_search_determine_object_point_inclusion: "\
                "unknown kind of search\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        break;
    }

    if (status == SE_STATCODE_SUCCESS)
        *object_included = inclusion_status;

    return status;
}
