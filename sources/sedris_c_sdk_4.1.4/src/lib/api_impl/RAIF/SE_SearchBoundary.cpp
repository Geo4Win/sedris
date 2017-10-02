// SEDRIS Level 0 Read API
//
// FILE       : SE_SearchBoundary.cpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC),
//              Warren Macchi (Arteon)
//
// DESCRIPTION: Methods for the SearchBoundary, a support class.  A
//              SearchBoundary object allows the user to specify
//              the spatial bounds of a candidate object from a search.
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

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_SearchBoundary.hpp"
#include "SE_API_Object.hpp"

#include "se_search_support.hpp"
#include "se_search_point_support.hpp"
#include "se_search_box_support.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG



//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
SE_SearchBoundary::SE_SearchBoundary
(
          RAIFManager                   *raif_manager,
    const SE_Search_Bounds              *bounds,
          SE_Search_Bounds_Closure  bounds_closure,
          SE_Search_Type         search_quality,
          SE_Object_Inclusion       inclusion_choice,
          SE_Search_Dimension       search_dimension
)
:
  SE_Shareable(raif_manager),
  _closure(bounds_closure),
  _quality(search_quality),
  _inclusion_choice(inclusion_choice),
  _dimension(search_dimension)
{
    _bounds = *bounds;
}


//---------------------------------------------------------------------------
// Copy constructor.
//---------------------------------------------------------------------------
SE_SearchBoundary::SE_SearchBoundary(const SE_SearchBoundary& sb)
: SE_Shareable(sb.raif_mngr()),
  _closure         (sb._closure),
  _quality         (sb._quality),
  _inclusion_choice(sb._inclusion_choice),
  _dimension       (sb._dimension)
{

    _bounds = sb._bounds;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
SE_SearchBoundary::~SE_SearchBoundary()
{
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
SE_Boolean
SE_SearchBoundary::obj_in_bounds
(
    SE_Api_Object *object
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Boolean     answer = SE_FALSE;

    if (se_spatial_search_available(object->GetIntObj()))
    {
        status = se_determine_geographic_inclusion
                 (object, &_bounds,
                  _closure, _quality, _dimension,
         (_inclusion_choice == SE_OBJINCL_FULLY_INCLUDED? &answer : NULL),
         (_inclusion_choice == SE_OBJINCL_PARTIALLY_INCLUDED? &answer : NULL),
                  NULL /* surrounds spatial bounds */);
    }
    else
    {
        // NonSpatial objects always fail
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if (status == SE_STATCODE_SUCCESS)
        return answer;
    else
        return SE_FALSE;
}


SE_Boolean
SE_SearchBoundary::check_pass
(
    SE_Api_Object *aggr_obj,
    SE_Api_Object *component_obj,
    SE_Api_Object *link_obj
)
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_OBJECT_SEARCH_BOX search_box;
    SE_DRM_Class aggr_type = aggr_obj->tag();
    SE_DRM_Class component_type = component_obj->tag();

    if (((aggr_type == SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY) ||
         (aggr_type == SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES)) &&
        (SE_IsA[component_type][SE_CLS_DRM_GEOMETRY_HIERARCHY] ||
         SE_IsA[component_type][SE_CLS_DRM_FEATURE_HIERARCHY]))
    {
        status = se_search_compute_spatial_box(aggr_obj, link_obj, &search_box);
    }
    else if (((aggr_type == SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY) ||
              (aggr_type == SE_CLS_DRM_PERIMETER_RELATED_FEATURES)) &&
             (SE_IsA[component_type][SE_CLS_DRM_GEOMETRY_HIERARCHY] ||
              SE_IsA[component_type][SE_CLS_DRM_FEATURE_HIERARCHY]))
    {
        status = se_search_compute_perimeter_box(link_obj, &search_box);
    }
    else
    {
        SE_Api_Object *domain = NULL;

        status = component_obj->GetNthComponentOfDRMClass( 0,
                   SE_CLS_DRM_SPATIAL_EXTENT,
                  &domain, NULL, SE_ITRBEH_RESOLVE );

        if (OBJSTATUS_VALID(status))
        {
            status = se_search_compute_domain_box(domain, &search_box);
        }
    }

    // $$$$ FIX SEARCH BOUNDS HERE

    /*
    if (status == SE_STATCODE_SUCCESS)
        return search_box_in_bounds(&search_box);
    else
    */
    status = SE_STATCODE_SUCCESS;

    if (status == SE_STATCODE_SUCCESS)
       return SE_TRUE;
    else
       return SE_FALSE;
}


// This method will retrieve the spatial search point for
// spatial objects.  This value could either be cached or
// computed.
// RETURNS:  SE_TRUE if successful, SE_FALSE for failure cases.
//
SE_OBJECT_SEARCH_POINT *
SE_SearchBoundary::getSearchPoint( SE_Api_Object *object )
{
    // if the object doesn't have what we want, try to compute it
    if (object->GetIntObj()->getSearchPoint() == NULL)
    {
        SE_OBJECT_SEARCH_POINT *point = computeSearchPoint(object);
        object->GetIntObj()->setSearchPoint(point);
    }
    return object->GetIntObj()->getSearchPoint();
}


// This method will retrieve the spatial search box for
// spatial objects.  This value could either be cached or
// computed.
// RETURNS:  SE_TRUE if successful, SE_FALSE for failure cases.
//
SE_OBJECT_SEARCH_BOX *
SE_SearchBoundary::getSearchBox( SE_Api_Object *object )
{
    // if the object doesn't have what we want, try to compute it
    if (object->GetIntObj()->getSearchBox() == NULL)
    {
        SE_OBJECT_SEARCH_BOX *box = computeSearchBox(object);
        object->GetIntObj()->setSearchBox(box);
    }
    return object->GetIntObj()->getSearchBox();
}


// METHOD: computeSearchPoint
//
// This method will compute the search point representation of
// a spatial object.  The point should be returned in the native
// coordinate system.  It should account for any transformation
// and control link evaluation (state provided by the context).
//
// This method is overloadable by vendors.  For all vendor implementations,
// if there are situations in which their own version cannot compute
// a search point (such as their code cannot handle evaluation of
// static control links), they should invoke the InternalObject's
// default version of the computeSearchPoint method.
//
// This method is recursive, called back by the functions called when
// they themselves attempt to get a search point from an object.
//
// RETURNS:
//
//   a pointer to a new search point if successful, NULL otherwise
//
SE_OBJECT_SEARCH_POINT *
SE_SearchBoundary::computeSearchPoint( SE_Api_Object *object )
{
    SE_OBJECT_SEARCH_POINT *point = new_search_point();

    SE_Status_Code status;

// !!! This relies heavily on the DRM.
//
    switch (object->tag())
    {
        // all aggregate features are in this case
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
        case SE_CLS_DRM_LOD_RELATED_FEATURES:
        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
        case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
        case SE_CLS_DRM_STATE_RELATED_FEATURES:
        case SE_CLS_DRM_TIME_RELATED_FEATURES:
        case SE_CLS_DRM_UNION_OF_FEATURES:
            status = se_search_get_aggregate_feature_search_point(object, point);
            break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
            status = add_all_components_search_points(object,
                      SE_CLS_DRM_GEOMETRY_HIERARCHY, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
            status = add_all_components_search_points(object,
                 SE_CLS_DRM_SEPARATING_PLANE_RELATIONS, SE_CLS_DRM_NULL, point);
            break;

        // all other aggregate geometries are in this case
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
        case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
            status = se_search_get_aggregate_geometry_search_point(object, point);
            break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
            status = se_search_get_topology_hierarchy_search_point(object, point);
            break;

        case SE_CLS_DRM_ARC:
            status = add_all_locations_search_points(object, SE_TRUE, 3, point);
            break;

        case SE_CLS_DRM_AREAL_FEATURE:
        case SE_CLS_DRM_FEATURE_VOLUME_SHELL:
            status = add_all_assocs_search_points( object,
                       SE_CLS_DRM_FEATURE_FACE, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_ELLIPSE:
        case SE_CLS_DRM_FEATURE_NODE:
        case SE_CLS_DRM_POINT:
        case SE_CLS_DRM_POSITIONAL_LIGHT:
        case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
        case SE_CLS_DRM_SPOT_LIGHT:
        case SE_CLS_DRM_VOLUME_OBJECT:
            status = get_location_based_search_point(object, point);
            break;

        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        case SE_CLS_DRM_LINE:
        case SE_CLS_DRM_POLYGON:
            status = add_all_locations_search_points(object, SE_TRUE, 0, point);
            break;

        case SE_CLS_DRM_FEATURE_EDGE:
            status = se_search_get_feature_edge_search_point(object, point);
            break;

        case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
            status = se_search_get_feature_model_instance_search_point
                     (object, point);
            break;

        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
            status = se_search_get_geometry_model_instance_search_point
                     (object, point);
            break;

        case SE_CLS_DRM_FEATURE_FACE_RING:
        case SE_CLS_DRM_LINEAR_FEATURE:
            status = add_all_assocs_search_points( object,
                     SE_CLS_DRM_FEATURE_EDGE, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_POINT_FEATURE:
            status = se_search_get_point_feature_search_point(object, point);
            break;

        case SE_CLS_DRM_POLYHEDRON:
            status = add_all_assocs_search_points( object,
                     SE_CLS_DRM_GEOMETRY_VOLUME, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_GEOMETRY_VOLUME:
            status = add_all_components_search_points(object,
                  SE_CLS_DRM_GEOMETRY_FACE, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_PROPERTY_GRID:
  /* $$$ Old design depended on a non-existent Spatial Domain component. */
            status = SE_STATCODE_INACTIONABLE_FAILURE;
            null_search_point(point);
            break;

        case SE_CLS_DRM_FEATURE_FACE:
            status = add_all_components_search_points(object,
                  SE_CLS_DRM_FEATURE_FACE_RING, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_VOLUMETRIC_FEATURE:
            status = add_all_assocs_search_points( object,
                     SE_CLS_DRM_FEATURE_VOLUME, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_FEATURE_VOLUME:
            status = add_all_components_search_points(object,
                  SE_CLS_DRM_FEATURE_VOLUME_SHELL, SE_CLS_DRM_NULL, point);
            break;

        case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
            status = add_all_components_search_points(object,
                  SE_CLS_DRM_FEATURE_TOPOLOGY, SE_CLS_DRM_NULL, point);
            break;

        default:
        {
            object->raif_mngr()->add_err_descr
            ("se_search_compute_search_point: no search point retrieval "\
             "for object ");
            object->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(object->tag()));
            object->raif_mngr()->add_err_descr(".\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
            break;
        }
    }

    if (!OBJSTATUS_VALID(status))
    {
        free_search_point(point);
        point = NULL;
    }
    return point;
}


// METHOD: computeSearchBox
//
// This method will compute the search box representation of
// a spatial object.  The box should be returned in the native
// coordinate system.  It should account for any transformation
// and control link evaluation (state provided by the context).
//
// This method is overloadable by vendors.  For all vendor implementations,
// if there are situations in which their own version cannot compute
// a search box (such as their code cannot handle evaluation of
// static control links), they should invoke the InternalObject's
// default version of the computeSearchBox method.
//
// This method is recursive, called back by the functions called when
// they themselves attempt to get a search box from an object.
//
// RETURNS: a pointer to a new search box if successful, NULL otherwise
//
SE_OBJECT_SEARCH_BOX *
SE_SearchBoundary::computeSearchBox( SE_Api_Object *object )
{
    SE_OBJECT_SEARCH_BOX *box = new_search_box();

    SE_Status_Code status;

   /*
    * This relies heavily on the data model.
    */
    switch(object->tag())
    {
// all aggregate features are in this case
    case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
    case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
    case SE_CLS_DRM_LOD_RELATED_FEATURES:
    case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
    case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
    case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
    case SE_CLS_DRM_STATE_RELATED_FEATURES:
    case SE_CLS_DRM_TIME_RELATED_FEATURES:
    case SE_CLS_DRM_UNION_OF_FEATURES:
        status = se_search_get_aggregate_feature_search_box(object, box);
        break;

    case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
        status = add_all_components_search_boxes(object,
                SE_CLS_DRM_GEOMETRY_HIERARCHY, SE_CLS_DRM_NULL, box );
        break;

    case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
        status = add_all_components_search_boxes(object,
                SE_CLS_DRM_SEPARATING_PLANE_RELATIONS, SE_CLS_DRM_NULL, box);
        break;

// all other aggregate geometries are in this case
    case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
    case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
    case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
    case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
    case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
    case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
    case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
    case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
    case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
    case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
    case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
    case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
        status = se_search_get_aggregate_geometry_search_box(object, box);
        break;

    case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
        status = se_search_get_topology_hierarchy_search_box(object, box);
        break;

    case SE_CLS_DRM_ARC:
        status = add_all_locations_search_boxes(object, SE_TRUE, 3, box);
        break;

    case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        status = add_all_locations_search_boxes(object, SE_TRUE, 0, box);
        break;

    case SE_CLS_DRM_AREAL_FEATURE:
    case SE_CLS_DRM_FEATURE_VOLUME_SHELL:
        status = add_all_assocs_search_boxes(object,
                    SE_CLS_DRM_FEATURE_FACE, SE_CLS_DRM_NULL, box);
        break;

    case SE_CLS_DRM_ELLIPSE:
        status = se_search_get_ellipse_search_box(object, box);
        break;

    case SE_CLS_DRM_VOLUME_OBJECT:
        status = se_search_get_volume_object_search_box(object, box);
        break;

    case SE_CLS_DRM_FEATURE_EDGE:
        status = se_search_get_feature_edge_search_box(object, box);
        break;

    case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
        status = se_search_get_feature_model_instance_search_box(object, box);
        break;

    case SE_CLS_DRM_FEATURE_NODE:
    case SE_CLS_DRM_POINT:
    case SE_CLS_DRM_POSITIONAL_LIGHT:
    case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
    case SE_CLS_DRM_SPOT_LIGHT:
        status = get_location_based_search_box(object, box);
        break;

    case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
        status = se_search_get_geometry_model_instance_search_box(object, box);
        break;

    case SE_CLS_DRM_LINE:
    case SE_CLS_DRM_POLYGON:
        status = add_all_locations_search_boxes(object, SE_TRUE, 0, box);
        break;

    case SE_CLS_DRM_FEATURE_FACE_RING:
    case SE_CLS_DRM_LINEAR_FEATURE:
        status = add_all_assocs_search_boxes( object, SE_CLS_DRM_FEATURE_EDGE,
                                              SE_CLS_DRM_NULL, box);
        break;

    case SE_CLS_DRM_POINT_FEATURE:
        status = se_search_get_point_feature_search_box(object, box);
        break;

    case SE_CLS_DRM_POLYHEDRON:
        status = add_all_assocs_search_boxes( object,
                 SE_CLS_DRM_GEOMETRY_VOLUME, SE_CLS_DRM_NULL, box);
        break;
    case SE_CLS_DRM_GEOMETRY_VOLUME:
        status = add_all_components_search_boxes( object,
                     SE_CLS_DRM_GEOMETRY_FACE, SE_CLS_DRM_NULL, box);
        break;

    case SE_CLS_DRM_PROPERTY_GRID:
        status = se_search_get_property_grid_search_box( object, box );
        break;

    case SE_CLS_DRM_FEATURE_FACE:
        status = add_all_components_search_boxes( object,
                     SE_CLS_DRM_FEATURE_FACE_RING, SE_CLS_DRM_NULL, box);
        break;

    case SE_CLS_DRM_VOLUMETRIC_FEATURE:
        status = add_all_assocs_search_boxes( object,
                      SE_CLS_DRM_FEATURE_VOLUME, SE_CLS_DRM_NULL, box);
        break;

    case SE_CLS_DRM_FEATURE_VOLUME:
        status = add_all_components_search_boxes( object,
                 SE_CLS_DRM_FEATURE_VOLUME_SHELL, SE_CLS_DRM_NULL, box);
        break;

    case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
        status = add_all_components_search_boxes(object,
                   SE_CLS_DRM_FEATURE_TOPOLOGY, SE_CLS_DRM_NULL, box);
        break;

    default:
        object->raif_mngr()->add_err_descr("se_search_compute_search_box: "\
                "no search box retrieval for this object.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        break;
    }

    if (!OBJSTATUS_VALID(status))
    {
        free_search_box(box);
        box = NULL;
    }
    return box;
}


//---------------------------------------------------------------------------
SE_Boolean
SE_SearchBoundary::check_spatial_branch
(
    SE_Api_Object *spatial,
    SE_Api_Object *link
)
{
    SE_Boolean           result = SE_TRUE;
    SE_OBJECT_SEARCH_BOX search_box;

    if (se_search_compute_spatial_box(spatial,
                   link, &search_box) != SE_STATCODE_SUCCESS)
    {
        raif_mngr()->add_err_descr
        ("Can't compute search box for a branch of a ");
        raif_mngr()->add_err_descr(SE_GetDRMClassString(spatial->tag()));
        raif_mngr()->add_err_descr("... following path");
    }
    else
    {
        SE_SRF_Context_Info srf_info;

        spatial->get_srf_info(&srf_info);

        result = search_box_in_bounds(&search_box, &srf_info);
    }
    return result;
}


//---------------------------------------------------------------------------
SE_Boolean
SE_SearchBoundary::check_perimeter_branch
(
    SE_Api_Object       *link,
    SE_SRF_Context_Info *srf_info
)
{
    SE_Boolean           result = SE_TRUE;
    SE_OBJECT_SEARCH_BOX search_box;

    if (se_search_compute_perimeter_box(link,
                            &search_box) != SE_STATCODE_SUCCESS)
    {
        raif_mngr()->add_err_descr("Can't compute search box for a "\
            "perimeter branch of a ");
        raif_mngr()->add_err_descr(SE_GetDRMClassString(link->tag()));
        raif_mngr()->add_err_descr("... following path");
    }
    else
    {
        result = search_box_in_bounds(&search_box, srf_info );
    }
    return result;
}

//
//---------------------------------------------------------------------------
SE_Boolean
SE_SearchBoundary::check_spatial_domain
(
    SE_Api_Object       *domain,
    SE_SRF_Context_Info *srf_info
)
{
    SE_Boolean           result = SE_TRUE;
    SE_OBJECT_SEARCH_BOX search_box;

    if (se_search_compute_domain_box(domain, &search_box) ==
        SE_STATCODE_SUCCESS)
    {
        result = search_box_in_bounds(&search_box, srf_info);
    }
    return result;
}


//
//----------------------------------------------------------------------------
SE_Boolean
SE_SearchBoundary::search_box_in_bounds
(
          SE_OBJECT_SEARCH_BOX *search_box,
    const SE_SRF_Context_Info  *srf_info
)
{
    SE_Boolean answer = SE_FALSE;

    switch (_inclusion_choice)
    {
        case SE_OBJINCL_PARTIALLY_INCLUDED:
             if (se_search_determine_box_inclusion(search_box,
                  srf_info, &_bounds, _closure,
                  _dimension, NULL, &answer) != SE_STATCODE_SUCCESS)
             {
                 raif_mngr()->add_err_descr
                 ("SE_SearchBoundary::search_box_in_bounds: "\
                  "se_search_determine_box_inclusion failed");
             }
             break;

        case SE_OBJINCL_FULLY_INCLUDED:
             if (se_search_determine_box_inclusion( search_box,
                     srf_info, &_bounds, _closure, _dimension,
                     &answer, NULL) != SE_STATCODE_SUCCESS)
             {
                 raif_mngr()->add_err_descr
                 ("SE_SearchBoundary::search_box_in_bounds: "\
                  "se_search_determine_box_inclusion failed");
             }
             break;

        default:
             raif_mngr()->add_err_descr
             ("SE_SearchBoundary::search_box_in_bounds: "\
              "unhandled inclusion choice\n");
             answer = SE_FALSE;
             break;
    }
    return answer;
}
