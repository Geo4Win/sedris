// SEDRIS Level 0 Read API
//
// FILE:        se_search_box_support.cpp
//
// PROGRAMMERS: Howard Lu (SAIC), Michele L. Worley (SAIC);
//              Julian Lander (MITRE), Warren Macchi (Arteon)
//
// DESCRIPTION: Search box functions for spatial-type objects.
//
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

#include "se_search_box_support.hpp"
#include "se_search_util.hpp"
#include "se_search_coord.hpp"
#include "SE_SearchBoundary.hpp"
#include "se_value.hpp"
#include "raif_srm_utils.h"

#include "SE_AggregateIterator.hpp"
#include "SE_ComponentIterator.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


/*
 * ENUM: SE_RANGE_DISPOSITION
 *
 */
typedef enum
{
    SE_RANGE_FULLY_INCLUDED,
    SE_RANGE_OVERLAPS,
    SE_RANGE_DISJOINT
} SE_RANGE_DISPOSITION;


//-----------------------------------------------------------------------------
//
// Declare some functions to be defined later
//
//-----------------------------------------------------------------------------

static SE_Status_Code se_search_add_boxes
(
    SE_OBJECT_SEARCH_BOX *old_box,
    SE_OBJECT_SEARCH_BOX *cum_box
);


static SE_Status_Code se_search_box_from_location
(
    SE_Api_Object            *location,
    SE_OBJECT_SEARCH_BOX *box_ptr
);


static SE_Status_Code get_axis_extrema
(
    SE_Api_Object       *axis_obj,
    EDCS_Attribute_Code *axis_type_ptr, /* out */
    SE_Spacing_Type     *spacing_ptr, /* out */
    SE_Long_Float       *min_value, /* out */
    SE_Long_Float       *max_value /* out */
);


//----------------------------------------------------------------------------
//
// FUNCTION: get_circumscribed_search_box
//
//   Takes a box and puts in a new SRF. Since the image of the
//   box may not be a box (the points may not lie in surfaces of constant
//   coordinate values: our boxes are very tightly controlled; also, lines
//   bend, but we are ignoring that here), we find the minimum and maximum
//   values of each coordinate in the new system and use these values to build
//   a new box.
//
//   $$$ This function really DOES NOT WORK because it ignores distortions, but
//   it's good enough for now.
//
//   If we are taking a 2D box component into a 3D system, we will combine
//   combine everything into a 3D box.
//
// PARAMETERS:
//
//   ori_box -- caller guarantees that the pointer is non-NULL
//
//   new_srf_info -- caller guarantees that the pointer is non-NULL
//
//   circumscribed_box -- caller guarantees that the pointer is non-NULL
//
//----------------------------------------------------------------------------
static SE_Status_Code get_circumscribed_search_box
(
          SE_OBJECT_SEARCH_BOX *ori_box,
    const SE_SRF_Context_Info         *new_srf_info,
          SE_OBJECT_SEARCH_BOX *circumscribed_box
);


//----------------------------------------------------------------------------
// FUNCTION: get_location_based_search_box()
//
//   Helper function to retrieve a location from an object and add it to
//   a search box.
//----------------------------------------------------------------------------
SE_Status_Code get_location_based_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code  status;
    SE_Api_Object           *location;

    null_search_box(box_ptr);

    status = obj->GetNthComponentOfDRMClass( 0,
                         SE_CLS_DRM_LOCATION, &location, NULL );

    status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status != SE_STATCODE_SUCCESS)
    {
        obj->raif_mngr()->add_err_descr("get_location_based_search_box: "\
                        "Can't get location");
    }
    else
    {
        // Here it's OK to use point_ptr directly, because its internal
        // pointers don't belong to another object
        //
        status = se_search_box_from_location(location, box_ptr);

        SAFE_RELEASE(location);
        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("get_location_based_search_box: "\
                        "Can't get box from location.");
    }
    return status;
}


//----------------------------------------------------------------------------
// FUNCTION: add_obj_search_box()
//
//   Helper function to retrieve the search box from an object and add it to
//   another search box.
//----------------------------------------------------------------------------
static SE_Status_Code add_obj_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code   status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_BOX *obj_box_ptr;

    obj_box_ptr = SE_SearchBoundary::getSearchBox(obj);

    if (!obj_box_ptr)
    {
        obj->raif_mngr()->add_err_descr("add_obj_search_box: failed getSearchBox()");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        status = se_search_add_boxes(obj_box_ptr, box_ptr);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("add_obj_search_box: Can't combine search boxes.");
    }
    return status;
}

//----------------------------------------------------------------------------
// FUNCTION: add_all_assocs_search_boxes()
//
//   Helper function to retrieve the search boxes from the assocs of an
//   object and add them to another search box.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//----------------------------------------------------------------------------
SE_Status_Code add_all_assocs_search_boxes
(
    SE_Api_Object         *obj,
    SE_DRM_Class           include_type,
    SE_DRM_Class           exclude_type,
    SE_OBJECT_SEARCH_BOX  *box_ptr
)
{
    SE_Status_Code          status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_BOX    avg_search_box;
    SE_Api_Object          *assoc=NULL;
    SE_Integer_Unsigned     i = 0;

    null_search_box(&avg_search_box);

    status = obj->GetNthAssociateOfDRMClass(i, include_type, &assoc, NULL);

    status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status;

        if (assoc->tag() != exclude_type)
            status = add_obj_search_box(assoc, &avg_search_box);

        SAFE_RELEASE(assoc);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("add_all_assocs_search_boxes: failed");
            break;
        }
        i++;

        tmp_status = obj->GetNthAssociateOfDRMClass(i, include_type,
                            &assoc, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;
    }
    *box_ptr = avg_search_box;

    return status;
}


//
//----------------------------------------------------------------------------
// FUNCTION: add_all_components_search_boxes()
//
//   Helper function to retrieve the search boxes from the components of an
//   object and add them to another search box.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//----------------------------------------------------------------------------
SE_Status_Code add_all_components_search_boxes
(
    SE_Api_Object         *obj,
    SE_DRM_Class           include_type,
    SE_DRM_Class           exclude_type,
    SE_OBJECT_SEARCH_BOX  *box_ptr
)
{
    SE_Status_Code          status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_BOX    avg_search_box;
    SE_Api_Object          *component=NULL;
    SE_Integer_Unsigned     i = 0;

    null_search_box(&avg_search_box);

    status = obj->GetNthComponentOfDRMClass(i, include_type, &component, NULL);

    status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status;

        if (component->tag() != exclude_type)
            status = add_obj_search_box(component, &avg_search_box);

        SAFE_RELEASE(component);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("add_all_components_search_boxes: failed");
            break;
        }
        i++;

        tmp_status = obj->GetNthComponentOfDRMClass( i,
                            include_type, &component, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;
    }
    *box_ptr = avg_search_box;

    return status;
}


//----------------------------------------------------------------------------
// FUNCTION: add_location_search_box()
//
//   Helper function to add the search box from a location object to
//   another search box.
//----------------------------------------------------------------------------
static SE_Status_Code
add_location_search_box
(
    SE_Api_Object        *location,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code       status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_BOX new_search_box;

    status = se_search_box_from_location(location, &new_search_box);

    if (status != SE_STATCODE_SUCCESS)
    {
        location->raif_mngr()->add_err_descr("add_location_search_box: "\
                 "Can't get box from location.");
    }
    else
    {
        status = se_search_add_boxes(&new_search_box, box_ptr);

        if (status != SE_STATCODE_SUCCESS)
            location->raif_mngr()->add_err_descr("add_location_search_box: "\
                    "Can't add search boxes.");
    }
    return status;
} // end add_location_search_box


//----------------------------------------------------------------------------
// FUNCTION: add_all_locations_search_boxes()
//
//   Helper function to retrieve the search boxes from the location
//   components of an object and add them to another search box.
//
//   maxLocations can be used to specify the number of locations added (=0
//   to add all found)
//   doDepth2 is a flag to search locations at a depth of 2
//----------------------------------------------------------------------------
SE_Status_Code add_all_locations_search_boxes
(
    SE_Api_Object          *obj,
    SE_Boolean              doDepth2,
    SE_Integer_Unsigned     maxLocations,
    SE_OBJECT_SEARCH_BOX   *box_ptr
)
{
    SE_Status_Code        status = SE_STATCODE_SUCCESS;
    SE_SearchFilter      *search_filter;
    SE_ComponentIterator *iter;
    SE_OBJECT_SEARCH_BOX  avg_search_box;
    SE_Api_Object        *location;
    SE_Integer_Unsigned   i = 0;

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

    null_search_box(&avg_search_box);

    search_filter = new SE_SearchFilter( obj->raif_mngr(),
            (doDepth2 ? location2_search_rules : location1_search_rules) );

    iter = new SE_ComponentIterator( obj->raif_mngr(), obj,
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

        status = add_location_search_box(location, &avg_search_box);

        SAFE_RELEASE(location);
        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("add_all_locations_search_boxes: failed");
            break;
        }
        i++;
    }
    delete iter;

    *box_ptr = avg_search_box;

    return status;
} // end add_all_locations_search_boxes


/**********************************************************************/
/*                                                                    */
/* These functions get search boxes from particular situations        */
/*                                                                    */
/**********************************************************************/

//----------------------------------------------------------------------------
//
// FUNCTION: init_box_from_coord
//
// PARAMETERS:
//
//   srf_info -- must have the same SRF as coord; caller
//                  guarantees that the pointer is non-NULL
//
//   coord -- must have the same SRF as srf_info
//
//   box_ptr -- out parameter; caller guarantees that the pointer is
//                 non-NULL
//
//----------------------------------------------------------------------------
static SE_Status_Code init_box_from_coord
(
    const SE_SRF_Context_Info  *srf_info,
    const SRM_Coordinate       *coord,
          SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (SE_ValidCoordinateForSRFContextInfo( coord, srf_info ) != SRM_TRUE)
    {
        raif_mngr->add_err_descr("init_box_from_coord (search bounds): "\
                 "Location in mismatched SRF.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        memcpy( &(box_ptr->srf_info), srf_info, sizeof( SE_SRF_Context_Info ));

        if( RAIFCoordIs2D( coord->spatial_coord_code ))
        {
            box_ptr->box_3d.box_empty = SE_TRUE;
            box_ptr->box_2d.box_empty = SE_FALSE;
            memcpy( &(box_ptr->box_2d.low_corner), coord, sizeof( SRM_Coordinate ));
            memcpy( &(box_ptr->box_2d.high_corner), coord, sizeof( SRM_Coordinate ));
        }
        else
        {
            box_ptr->box_2d.box_empty = SE_TRUE;
            box_ptr->box_3d.box_empty = SE_FALSE;
            memcpy( &(box_ptr->box_3d.low_corner), coord, sizeof( SRM_Coordinate ));
            memcpy( &(box_ptr->box_3d.high_corner), coord, sizeof( SRM_Coordinate ));
        }
    }
    return status;
} // end init_box_from_coord


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_topology_hierarchy_search_box
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_topology_hierarchy_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code status;

    status = add_all_components_search_boxes(obj,
        SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY, SE_CLS_DRM_NULL, box_ptr);

    if (status != SE_STATCODE_SUCCESS)
        obj->raif_mngr()->add_err_descr("se_search_get_topology_hierarchy_search_box: failed");

    return status;
}


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_aggregate_feature_search_box
//
//   Caller has encountered an <Aggregate Feature>; we don't need to check
//   that it's an <Aggregate Feature>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_aggregate_feature_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_SearchFilter            *search_filter;
    SE_ComponentIterator       *iter;
    SE_Api_Object              *component=NULL;
    SE_OBJECT_SEARCH_BOX        avg_search_box;
    SE_Status_Code              status = SE_STATCODE_SUCCESS;

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

    null_search_box(&avg_search_box);

    search_filter = new SE_SearchFilter( obj->raif_mngr(),
         ( obj->tag() == SE_CLS_DRM_UNION_OF_FEATURES ?
           union_of_feature_search_rules : feature_hierarchy_search_rules) );

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

        status = add_obj_search_box(component, &avg_search_box);

        SAFE_RELEASE(component);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("se_search_get_aggregate_feature_search_box: "\
                    "failed to add search box");
            break;
        }
    }
    delete iter;

    *box_ptr = avg_search_box;

    return status;
}


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_aggregate_geometry_search_box
//
//   Caller has encountered an <Aggregate Geometry>; we don't need to check
//   that it's an <Aggregate Geometry>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_aggregate_geometry_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Api_Object         *component = NULL;
    SE_OBJECT_SEARCH_BOX   avg_search_box;
    SE_DRM_Class           object_type;
    SE_Status_Code         status = SE_STATCODE_SUCCESS;

    null_search_box(&avg_search_box);

    object_type = obj->tag();

    if (object_type == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
    {
        status = obj->GetNthComponentOfDRMClass( 0,
                SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY, &component, NULL);

        status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

        if (status == SE_STATCODE_SUCCESS)
        {
            status = add_obj_search_box(component, &avg_search_box);
            SAFE_RELEASE(component);
        }
    }
    else if (object_type == SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY)
    {
        status = add_obj_search_box(obj, &avg_search_box);
    }
    else
    {
        SE_DRM_Class findt;

        if (object_type == SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY)
        {
            findt = SE_CLS_DRM_PRIMITIVE_GEOMETRY;
        }
        else
        {
            findt = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        }
        status = add_all_components_search_boxes(obj, findt, SE_CLS_DRM_NULL,
                                                    &avg_search_box);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("se_search_get_aggregate_geometry_search_box: "\
                    "failed add_all_components_search_boxes()");
    }

    *box_ptr = avg_search_box;

    return status;
}

//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_ellipse_search_box
//
//   Caller has encountered an <Ellipse>; we don't need to check that it's an
//   <Ellipse>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_ellipse_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code       status = SE_STATCODE_SUCCESS;
    SE_SRF_Context_Info  ellipse_srf_info;
    SRM_Coordinate       ellipse_extrema[4];
    SE_OBJECT_SEARCH_BOX extremum_box;

    null_search_box(box_ptr);

    status = se_search_fetch_ellipse_extrema( obj, &ellipse_srf_info, ellipse_extrema );

    if (status != SE_STATCODE_SUCCESS)
    {
        obj->raif_mngr()->add_err_descr("se_search_get_ellipse_search_box: "\
                 "Can't get ellipse boundaries.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    for (SE_Byte_Unsigned i = 0; OBJSTATUS_VALID(status) && (i < 4); i++)
    {
        status = init_box_from_coord(
                     &ellipse_srf_info,
                     &ellipse_extrema[i],
                     &extremum_box);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("se_search_get_ellipse_search_box: "\
                     "Can't build ellipse box.");
        }
        else
        {
            status = se_search_add_boxes(&extremum_box, box_ptr);

            if (status != SE_STATCODE_SUCCESS)
            {
                obj->raif_mngr()->add_err_descr("se_search_get_ellipse_search_box: "\
                         "Can't add boxes.");
            }
        }
    } // end for i

    return status;
} // end se_search_get_ellipse_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_volume_object_search_box
//
//   Caller has encountered an <Volume Object>; we don't need to check
//   that it's an <Volume Object>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_volume_object_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
   // XXX ********************************************************
   // $$$ If <Volume Extent> already has a function for it then it
   // $$$ might be an easy fix to use that one for this case.
   // XXX ********************************************************

    SE_Status_Code        status = SE_STATCODE_INACTIONABLE_FAILURE;

    return status;
} // end se_search_get_volume_object_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_feature_edge_search_box
//
//   Caller has encountered a <Feature Edge>; we don't need to check that
//   it's a <Feature Edge>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_feature_edge_search_box
(
    SE_Api_Object        *fedgeObj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
SE_Api_Object  *locObj, *fnodeObj;
SE_OBJECT_SEARCH_BOX        avg_search_box;
SE_Status_Code         status = SE_STATCODE_SUCCESS;
SE_Integer_Unsigned  locs_added=0;

    null_search_box(&avg_search_box);

// first get the start and end locations which are components of
// the associated <Feature Node>s
//
    status = fedgeObj->GetNthAssociateOfDRMClass( 0,
                         SE_CLS_DRM_FEATURE_NODE, &fnodeObj, NULL );

    if( OBJSTATUS_VALID(status) )
    {
       status = fnodeObj->GetNthComponentOfDRMClass( 0,
                         SE_CLS_DRM_LOCATION, &locObj, NULL );

       if( OBJSTATUS_VALID(status) )
       {
          status = add_location_search_box( locObj, &avg_search_box );

          SAFE_RELEASE( locObj );

          if( OBJSTATUS_VALID(status) )
          {
              locs_added++;
          }
          else
          {
              fedgeObj->raif_mngr()->add_err_descr("se_search_get_feature_edge_search_box: "\
                       "Can't add location to box");
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
          status = add_location_search_box( locObj, &avg_search_box );

          SAFE_RELEASE( locObj );

          if( OBJSTATUS_VALID(status) )
          {
              locs_added++;
          }
          else
          {
              fedgeObj->raif_mngr()->add_err_descr("se_search_get_feature_edge_search_box: "\
                       "Can't add location to box");
          }
       }
       SAFE_RELEASE( fnodeObj );
    }

// get the locations which are components of the feature edge
//
    SE_Integer_Unsigned nth=0;

    status = fedgeObj->GetNthComponentOfDRMClass( nth++,
                         SE_CLS_DRM_LOCATION, &locObj, NULL );

    while( OBJSTATUS_VALID(status) )
    {
        status = add_location_search_box( locObj, &avg_search_box );

        SAFE_RELEASE( locObj );

        if( OBJSTATUS_VALID(status) )
        {
           locs_added++;
           status = fedgeObj->GetNthComponentOfDRMClass( nth++,
                         SE_CLS_DRM_LOCATION, &locObj, NULL );
        }
        else
        {
            fedgeObj->raif_mngr()->add_err_descr("se_search_get_feature_edge_search_box: "\
                     "Can't add location to box");
        }
    }
    *box_ptr = avg_search_box;

    return (locs_added ? SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE );
} // end se_search_get_feature_edge_search_box

//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_geometry_model_instance_search_box
//
//   Caller has encountered a <Geometry Model Instance>; we don't need to
//   check that it's a <Geometry Model Instance>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_geometry_model_instance_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Api_Object         *model=NULL;
    SE_OBJECT_SEARCH_BOX   avg_search_box;
    SE_Status_Code         status = SE_STATCODE_SUCCESS;

    null_search_box(&avg_search_box);

    status=obj->get_nth_association(0, &model, NULL,
                SE_CLS_DRM_GEOMETRY_MODEL, SE_ITRBEH_RESOLVE );

    if (!OBJSTATUS_VALID(status))
    {
        obj->raif_mngr()->add_err_descr("se_search_get_geometry_model_instance_search_box: "\
                 "Can't get Geometry Model.");
    }
    else
    {
        SE_Api_Object *component=NULL;

        status = model->GetNthComponentOfDRMClass( 0,
                    SE_CLS_DRM_GEOMETRY_HIERARCHY, &component, NULL);

        if (!OBJSTATUS_VALID(status))
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
            obj->raif_mngr()->add_err_descr("se_search_get_geometry_model_instance_search_box: "\
                     "Can't get Geometry Hierarchy.");
        }
        else
        {
            status = add_obj_search_box(component, &avg_search_box);
        }
        SAFE_RELEASE(component);
    }
    SAFE_RELEASE(model);

    *box_ptr = avg_search_box;

    return status;
} // end se_search_get_geometry_model_instance_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_feature_model_instance_search_box
//
//   Caller has encountered a <Feature Model Instance>; we don't need to
//   check that it's a <Feature Model Instance>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_feature_model_instance_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Api_Object         *model=NULL;
    SE_OBJECT_SEARCH_BOX   avg_search_box;
    SE_Status_Code         status = SE_STATCODE_SUCCESS;

    null_search_box(&avg_search_box);

    status=obj->get_nth_association(0, &model, NULL,
                SE_CLS_DRM_FEATURE_MODEL, SE_ITRBEH_RESOLVE );

    if (!OBJSTATUS_VALID(status))
    {
        obj->raif_mngr()->add_err_descr("se_search_get_feature_model_instance_search_box: "\
                 "Can't get Feature Model.");
    }
    else
    {
        SE_Api_Object *component=NULL;

        status = model->GetNthComponentOfDRMClass(0,
                  SE_CLS_DRM_FEATURE_HIERARCHY, &component, NULL);

        status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

        if (status != SE_STATCODE_SUCCESS)
            obj->raif_mngr()->add_err_descr("se_search_get_feature_model_instance_search_box: "\
                     "Can't get Feature Hierarchy.");
        else
            status = add_obj_search_box(component, &avg_search_box);

        SAFE_RELEASE(component);
    }
    SAFE_RELEASE(model);

    *box_ptr = avg_search_box;

    return status;
} // end se_search_get_feature_model_instance_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_get_point_feature_search_box
//
//   Caller has encountered a <Point Feature>; we don't need to check that
//   it's a <Point Feature>.
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_point_feature_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Api_Object           *node;
    SE_Status_Code  status = SE_STATCODE_SUCCESS;

    status = obj->GetNthAssociateOfDRMClass( 0,
                     SE_CLS_DRM_FEATURE_NODE, &node, NULL);

    status = (OBJSTATUS_VALID(status) ?
                 SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status != SE_STATCODE_SUCCESS)
    {
        obj->raif_mngr()->add_err_descr("se_search_get_point_feature_search_box: failed");
    }
    else
    {
        status = add_obj_search_box(node, box_ptr);
        SAFE_RELEASE(node);
    }
    return status;
} // se_search_get_point_feature_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: fetch_extreme_values
//
//----------------------------------------------------------------------------
static void fetch_extreme_values
(
          SE_Short_Integer_Unsigned  axis_count,
    const EDCS_Attribute_Code       *axis_ea_array,
    const SE_Spacing_Type           *axis_spacing_array,
    const SE_Long_Float             *axis_minimum_value_array,
    const SE_Long_Float             *axis_maximum_value_array,
          EDCS_Attribute_Code        ea_to_match,
          SE_Long_Float             *minimum_value_ptr, /* in/out */
          SE_Long_Float             *maximum_value_ptr  /* in/out */
)
{
    SE_Short_Integer_Unsigned i;
    SE_Integer                axis_index = -1;

    // Find the axis of the right type
    for (i = 0; i < axis_count && axis_index == -1; i++)
    {
        if (ea_to_match == axis_ea_array[i])
        {
            axis_index = (SE_Integer) i;
        }
    }

    if (axis_index > -1)
    {
        if (axis_spacing_array[axis_index] == SE_SPACTYP_GEOMETRIC)
        {
            *minimum_value_ptr *= axis_minimum_value_array[axis_index];
            *maximum_value_ptr *= axis_maximum_value_array[axis_index];
        }
        else // linear spacing
        {
            *minimum_value_ptr += axis_minimum_value_array[axis_index];
            *maximum_value_ptr += axis_maximum_value_array[axis_index];
        }
    }
} // end fetch_extreme_values


//
//----------------------------------------------------------------------------
SE_Status_Code se_search_get_property_grid_search_box
(
    SE_Api_Object        *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SE_Status_Code             status = SE_STATCODE_SUCCESS;
    SE_FIELDS_PTR              property_grid_fields;
    SE_SearchFilter           *search_filter = NULL;
    SE_AggregateIterator      *iter = NULL;
    SE_ComponentIterator      *axis_iter = NULL;
    SE_Api_Object             *hook_point = NULL, *axis_object = NULL;
    SE_OBJECT_SEARCH_BOX       avg_search_box, property_grid_search_box;
    EDCS_Attribute_Code       *axis_ea_array = NULL;
    SE_Spacing_Type           *axis_spacing_array = NULL;
    SE_Long_Float             *axis_minimum_value_array = NULL,
                              *axis_maximum_value_array = NULL;
    SE_Short_Integer_Unsigned  spatial_axes_count, i;
    SRM_Coordinate            *low2_corner_ptr=NULL, *high2_corner_ptr=NULL;
    SRM_Coordinate            *low3_corner_ptr=NULL, *high3_corner_ptr=NULL;

    static SE_Search_Rule hook_point_search_rules[] =
                           {
                               SE_DRM_CLASS_MATCH(PROPERTY_GRID_HOOK_POINT)
                               SE_END
                           };

    static SE_Search_Rule axis_search_rules[] =
                           {
                               SE_AND
                               (
                                   SE_DRM_CLASS_MATCH(AXIS),
                                   SE_MAX_SEARCH_DEPTH(1)
                               )
                               SE_END
                           };

    null_search_box(&avg_search_box);

    property_grid_fields = obj->GetIntObj()->OrigFields();

    search_filter = new SE_SearchFilter( obj->raif_mngr(),
                                         hook_point_search_rules);

    iter = new SE_AggregateIterator( obj->raif_mngr(),obj, search_filter );

    SAFE_RELEASE(search_filter);

    while (status == SE_STATCODE_SUCCESS)
    {
        SE_Status_Code tmp_status = iter->next_object(&hook_point, NULL);

        if (!OBJSTATUS_VALID(tmp_status))
            break;

        status = add_obj_search_box(hook_point, &avg_search_box);

        SAFE_RELEASE(hook_point);

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: "\
                        "failed to add component hook point box");
            break;
        }
    }
    delete iter;

    if (status != SE_STATCODE_SUCCESS)
        return status;

   /*
    * Set up an array of axis fields for the spatial axes
    */
    spatial_axes_count = property_grid_fields->u.Property_Grid.spatial_axes_count;
    axis_ea_array = new EDCS_Attribute_Code[spatial_axes_count];
    axis_spacing_array = new SE_Spacing_Type[spatial_axes_count];
    axis_minimum_value_array = new SE_Long_Float[spatial_axes_count];
    axis_maximum_value_array = new SE_Long_Float[spatial_axes_count];

   /*
    * Fill the fields array with the fields of each spatial axis
    */
    search_filter = new SE_SearchFilter( obj->raif_mngr(),
                                         axis_search_rules );

    axis_iter = new SE_ComponentIterator(obj->raif_mngr(), obj,
                      search_filter,
                      SE_FALSE, /* don't attach tables */
                      SE_FALSE, /* no inheritance */
                      SE_FALSE, /* don't apply transforms */
                      SE_FALSE, /* don't follow models */
                      SE_FALSE, /* don't evaluate clinks */
                      NULL, /* no search bounds here */
                      NULL, /* no select params */
                      NULL, /* no order params */
                      SE_TRAVORDR_DEPTH_FIRST);

    SAFE_RELEASE(search_filter);

    for (i = 0; i < spatial_axes_count && OBJSTATUS_VALID(status); i++)
    {
        SE_Status_Code tmp_status = axis_iter->next_object(&axis_object, NULL);

        status = (OBJSTATUS_VALID(tmp_status) ?
                  SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

        if (status == SE_STATCODE_SUCCESS)
        {
            status = get_axis_extrema( axis_object,
                         axis_ea_array + i,
                         axis_spacing_array + i,
                         axis_minimum_value_array + i,
                         axis_maximum_value_array + i );

            SAFE_RELEASE(axis_object);

            if (status != SE_STATCODE_SUCCESS)
            {
                obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: "\
                         "Can't get spatial axis extrema.");
            }
        }
        else
        {
            obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: "\
                     "Can't retrieve spatial axes.");
        }
    }
    delete axis_iter;

    if (!OBJSTATUS_VALID(status))
        return status;

  /* Now we have the box surrounding the hook point(s) and the axis
   * descriptions. We need to expand the box to include the <Property
   * Grid> coverage.
   * First, convert our box into the <Property Grid> system
   */
    SE_SRF_Context_Info pg_srf_info;

    obj->get_srf_info( &pg_srf_info );


    if (pg_srf_info.srf_parameters_info.srf_params_info_code
        != SRM_SRFPARAMINFCOD_TEMPLATE)
    {
        obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: Don't support srf info not using parameters");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    status = get_circumscribed_search_box( &avg_search_box, &pg_srf_info,
                 &property_grid_search_box );

    if (status != SE_STATCODE_SUCCESS)
    {
        obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: Can't convert box.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    * Now we need to add the offsets from the spatial axes
    * Note that only some systems have 2D boxes
    */
    low2_corner_ptr  = &property_grid_search_box.box_2d.low_corner;
    high2_corner_ptr = &property_grid_search_box.box_2d.high_corner;
    low3_corner_ptr  = &property_grid_search_box.box_3d.low_corner;
    high3_corner_ptr = &property_grid_search_box.box_3d.high_corner;

    SE_Long_Float  low2X, low2Y, high2X, high2Y, tZ,
                   low3X, low3Y, low3Z, high3X, high3Y, high3Z;
    EDCS_Attribute_Code   xEAC, yEAC, zEAC;

    bool pgsb_srf_is_2d = RAIFSRFIs2D(pg_srf_info.srf_parameters_info.value.srf_template.template_code);

    se_get_coords(low2_corner_ptr, &low2X, &low2Y, &tZ);
    se_get_coords(high2_corner_ptr, &high2X, &high2Y, &tZ);

    if (!pgsb_srf_is_2d)
    {
        // search box is 3D

        se_get_coords(low3_corner_ptr, &low3X, &low3Y, &low3Z);
        se_get_coords(high3_corner_ptr, &high3X, &high3Y, &high3Z);

        switch( pg_srf_info.srf_parameters_info.value.srf_template.template_code )
        {
           case SRM_SRFTCOD_CELESTIOMAGNETIC :
           case SRM_SRFTCOD_CELESTIODETIC :
                xEAC = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
                yEAC = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
                zEAC = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
                break;

           case SRM_SRFTCOD_EQUATORIAL_INERTIAL :
                xEAC = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
                yEAC = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
                zEAC = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
                break;

           case SRM_SRFTCOD_SOLAR_EQUATORIAL :
           case SRM_SRFTCOD_SOLAR_ECLIPTIC :
           case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
           case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE :
                xEAC = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
                yEAC = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
                zEAC = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
                break;

           case SRM_SRFTCOD_CELESTIOCENTRIC :
           case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D :
           case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN :
           case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL :
           case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL :
           case SRM_SRFTCOD_MERCATOR :
           case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL :
           case SRM_SRFTCOD_TRANSVERSE_MERCATOR :
           case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL :
           case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC :
           case SRM_SRFTCOD_POLAR_STEREOGRAPHIC :
                xEAC = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
                yEAC = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
                zEAC = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
                break;
           case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC :
           case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC :
           case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL :

            default:
                obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: "\
                        "Unrecognized 3D SRF");
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                break;
        }
    }
    else
    {
        // search box is 2D

        switch( pg_srf_info.srf_parameters_info.value.srf_template.template_code )
        {
            case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D :
                xEAC = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
                yEAC = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
                break;

            // others...
            case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D :
            case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D :
            default:
                obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: "\
                        "Unrecognized 2D SRF");
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                break;
        }
    }

    if (status == SE_STATCODE_SUCCESS && !pgsb_srf_is_2d )
    {
        // 3D and possibly 2D
        if (!property_grid_search_box.box_2d.box_empty)
        {
            fetch_extreme_values(
                spatial_axes_count,
                axis_ea_array, axis_spacing_array,
                axis_minimum_value_array, axis_maximum_value_array,
                xEAC, &low2X, &high2X );

            fetch_extreme_values(
                spatial_axes_count,
                axis_ea_array, axis_spacing_array,
                axis_minimum_value_array, axis_maximum_value_array,
                yEAC, &low2Y, &high2Y );
        }

        if( !property_grid_search_box.box_3d.box_empty)
        {
            fetch_extreme_values(
                    spatial_axes_count,
                    axis_ea_array, axis_spacing_array,
                    axis_minimum_value_array, axis_maximum_value_array,
                    xEAC, &low3X, &high3X );

            fetch_extreme_values(
                    spatial_axes_count,
                    axis_ea_array, axis_spacing_array,
                    axis_minimum_value_array, axis_maximum_value_array,
                    yEAC, &low3Y, &high3Y );

            fetch_extreme_values(
                    spatial_axes_count,
                    axis_ea_array, axis_spacing_array,
                    axis_minimum_value_array, axis_maximum_value_array,
                    zEAC, &low3Z, &high3Z );
        }
    }
    else if (status == SE_STATCODE_SUCCESS)
    {
        // only 2D available
        if (!property_grid_search_box.box_2d.box_empty)
        {
            fetch_extreme_values(
                spatial_axes_count,
                axis_ea_array, axis_spacing_array,
                axis_minimum_value_array, axis_maximum_value_array,
                xEAC, &low2X, &high2X );

            fetch_extreme_values(
                spatial_axes_count,
                axis_ea_array, axis_spacing_array,
                axis_minimum_value_array, axis_maximum_value_array,
                yEAC, &low2Y, &high2Y );
        }
    }

    // free the axis information arrays
    delete [] axis_ea_array;
    delete [] axis_spacing_array;
    delete [] axis_minimum_value_array;
    delete [] axis_maximum_value_array;

    se_set_coords(low2_corner_ptr, low2X, low2Y);
    se_set_coords(high2_corner_ptr, high2X, high2Y);

    if (!pgsb_srf_is_2d)
    {
        se_set_coords(low3_corner_ptr, low3X, low3Y, low3Z);
        se_set_coords(high3_corner_ptr, high3X, high3Y, high3Z);
    }

    if (status == SE_STATCODE_SUCCESS)
    {
       /*
        * Now we convert the box back into the hook point system
        */
        status = get_circumscribed_search_box(
                     &property_grid_search_box,
                     &avg_search_box.srf_info ,
                     box_ptr );

        if (status != SE_STATCODE_SUCCESS)
        {
            obj->raif_mngr()->add_err_descr("se_search_get_property_grid_search_box: "\
                     "Can't convert box to user SRF.");
        }
    }
    return status;
} // end se_search_get_property_grid_search_box


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_box_from_location
//
//----------------------------------------------------------------------------
static SE_Status_Code
se_search_box_from_location
(
    SE_Api_Object        *location,
    SE_OBJECT_SEARCH_BOX *box_ptr
)
{
    SRM_Coordinate  coord;
    SE_FIELDS_PTR   loc_fields;
    SE_Status_Code  status = SE_STATCODE_SUCCESS;

    location->get_srf_info(&box_ptr->srf_info);

    loc_fields = location->fields(&status);

    if( !SE_ConvertFieldsToCoordinate(loc_fields, &coord) )
    {
         location->raif_mngr()->add_err_descr("se_search_box_from_location: "\
                    "Can't convert fields to coord");
         status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

// $$$ is this going to work with surfaces???

    else if (SE_IsA[location->tag()][SE_CLS_DRM_LOCATION_2D] ||
             SE_IsA[location->tag()][SE_CLS_DRM_LOCATION_SURFACE])
    {
        box_ptr->box_2d.low_corner  = coord;
        box_ptr->box_2d.high_corner = coord;
        box_ptr->box_2d.box_empty   = SE_FALSE;
        box_ptr->box_3d.box_empty   = SE_TRUE;
    }
    else // Location 3D
    {
        box_ptr->box_3d.low_corner  = coord;
        box_ptr->box_3d.high_corner = coord;
        box_ptr->box_3d.box_empty   = SE_FALSE;
        box_ptr->box_2d.box_empty   = SE_TRUE;
    }
    return status;
}


//----------------------------------------------------------------------------
//
// FUNCTION: check_numeric_range
//
//   Checks to see whether the range [min,max] is completely contained in,
//   overlaps, or is completely disjoint with [rangeMin, rangeMax]
//
//   Don't use this for angular ranges; they have their own function.
//
//----------------------------------------------------------------------------
static SE_RANGE_DISPOSITION check_numeric_range
(
    SE_Long_Float            min,
    SE_Long_Float            max,
    SE_Long_Float            rangeMin,
    SE_Long_Float            rangeMax,
    SE_Search_Bounds_Closure search_bounds_closure
)
{
    if (search_bounds_closure == SE_SEARCHBNDSCLS_FULLY_CLOSED)
    {
        if ((rangeMin <= min) && (max <= rangeMax))
            return SE_RANGE_FULLY_INCLUDED;

        if ((min > rangeMax) || (max < rangeMin))
            return SE_RANGE_DISJOINT;

        // Note in this overlap case, it could be that min,max completely
        // contains the range.
        return SE_RANGE_OVERLAPS;
    }
    else
    {
        // SE_SEARCH_BNDS_CLOSURE_PARTIAL
        if ((rangeMin <= min) && (max < rangeMax))
            return SE_RANGE_FULLY_INCLUDED;

        if ((min >= rangeMax) || (max < rangeMin))
            return SE_RANGE_DISJOINT;

        // Note in this overlap case, it could be that min,max completely
        // contains the range.
        return SE_RANGE_OVERLAPS;
    }
} // end check_numeric_range


//----------------------------------------------------------------------------
//
// FUNCTION: check_angular_range
//
//   Checks to see whether the range [min,max] is completely contained in,
//   overlaps, or is completely disjoint with [rangeMin, rangeMax] in an
//   angular sense
//
//----------------------------------------------------------------------------
static SE_RANGE_DISPOSITION check_angular_range
(
    SE_Long_Float                    min,
    SE_Long_Float                    max,
    SE_Long_Float                    rangeMin,
    SE_Long_Float                    rangeMax,
    SE_Search_Bounds_Closure closure
)
{
    if (se_within_angular_range(min, rangeMin, rangeMax, closure))
    {
        if (se_within_angular_range(max, rangeMin, rangeMax, closure))
            return SE_RANGE_FULLY_INCLUDED;
        else
            return SE_RANGE_OVERLAPS;
    }
    else if (se_within_angular_range(max, rangeMin, rangeMax, closure))
        return SE_RANGE_OVERLAPS;
    else if ((se_within_angular_range(rangeMin, min, max, closure)) ||
        (se_within_angular_range(rangeMax, min, max, closure)))
        return SE_RANGE_OVERLAPS;
    else
        return SE_RANGE_DISJOINT;
} // end check_angular_range


//----------------------------------------------------------------------------
//
// FUNCTION: determine_box2d_inclusion
//
//----------------------------------------------------------------------------
static SE_Boolean determine_box2d_inclusion(
          SRM_Coordinate                   *low_point,
          SRM_Coordinate                   *high_point,
          SE_Search_Bounds              *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Boolean                    *object_fully_included, /* out */
          SE_Boolean                    *object_partly_included /* out */ )
{
    SE_RANGE_DISPOSITION disposition = SE_RANGE_DISJOINT;
    SE_Long_Float lx, ly, hx, hy;
    SE_Long_Float minX, minY, maxX, maxY;
    SE_Boolean is_angular = SE_FALSE;

    // Initialize values
    if (object_fully_included)
        *object_fully_included = SE_TRUE;
    if (object_partly_included)
        *object_partly_included = SE_TRUE;

    se_get_coords( low_point, &lx, &ly );
    is_angular = (SE_Boolean) RAIFCoordIsAngular( low_point->spatial_coord_code );

    se_get_coords( high_point, &hx, &hy);
    se_get_coords( &bounds_ptr->minimum_point, &minX, &minY);
    se_get_coords( &bounds_ptr->maximum_point, &maxX, &maxY);

    // we now check the ranges in the X, Y. If any is disjoint,
    // then both are false and we are done
    //
    if (is_angular)
        disposition = check_angular_range(lx, hx, minX, maxX,
                                    search_bounds_closure);
    else
        disposition = check_numeric_range(lx, hx, minX, maxX,
                                    search_bounds_closure);

    if (disposition == SE_RANGE_DISJOINT)
        goto end_of_check;

    if (is_angular)
        disposition = check_angular_range(ly, hy, minY, maxY,
                                    search_bounds_closure);
    else
        disposition = check_numeric_range(ly, hy, minY, maxY,
                                    search_bounds_closure);

end_of_check:

    if (object_fully_included)
        *object_fully_included =(SE_Boolean)
                                (*object_fully_included &&
                                (disposition == SE_RANGE_FULLY_INCLUDED));

    if (object_partly_included)
        *object_partly_included =(SE_Boolean)
                                (*object_partly_included &&
                                ((disposition == SE_RANGE_FULLY_INCLUDED) ||
                                 (disposition == SE_RANGE_OVERLAPS)));

    return SE_TRUE;
} // end determine_box2d_inclusion


//----------------------------------------------------------------------------
//
// FUNCTION: determine_box3d_inclusion
//
//----------------------------------------------------------------------------
static SE_Boolean determine_box3d_inclusion
(
          SRM_Coordinate                   *low_point,
          SRM_Coordinate                   *high_point,
          SE_Search_Bounds              *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Boolean                    *object_fully_included, /* out */
          SE_Boolean                    *object_partly_included /* out */
)
{
    SE_RANGE_DISPOSITION disposition = SE_RANGE_DISJOINT;
    SE_Long_Float lx, ly, lz, hx, hy, htz;
    SE_Long_Float minX, minY, minZ, maxX, maxY, maxZ;
    SE_Boolean is_angular = SE_FALSE;

    // Initialize values
    if (object_fully_included)
        *object_fully_included = SE_TRUE;
    if (object_partly_included)
        *object_partly_included = SE_TRUE;

    se_get_coords(low_point, &lx, &ly, &lz);
    se_get_coords(high_point, &hx, &hy, &htz);
    se_get_coords(&bounds_ptr->minimum_point, &minX, &minY, &minZ);
    se_get_coords(&bounds_ptr->maximum_point, &maxX, &maxY, &maxZ);

    is_angular = (SE_Boolean) RAIFCoordIsAngular(low_point->spatial_coord_code);

    // we now check the ranges in the X, Y, and Z. If any is disjoint,
    // then both are false and we are done
    //
    if (is_angular)
        disposition = check_angular_range(lx, hx, minX, maxX,
                                           search_bounds_closure);
    else
        disposition = check_numeric_range(lx, hx, minX, maxX,
                                    search_bounds_closure);

    if (disposition == SE_RANGE_DISJOINT)
        goto end_of_check;

    if (is_angular)
        disposition = check_angular_range(ly, hy, minY, maxY,
                                           search_bounds_closure);
    else
        disposition = check_numeric_range(ly, hy, minY, maxY,
                                    search_bounds_closure);

    if (disposition == SE_RANGE_DISJOINT)
        goto end_of_check;

    disposition = check_numeric_range(lz, htz, minZ, maxZ,
                                search_bounds_closure);

end_of_check:

    if (object_fully_included)
        *object_fully_included =(SE_Boolean)
                                (*object_fully_included &&
                                (disposition == SE_RANGE_FULLY_INCLUDED));

    if (object_partly_included)
        *object_partly_included = (SE_Boolean)
                                (*object_partly_included &&
                                ((disposition == SE_RANGE_FULLY_INCLUDED) ||
                                 (disposition == SE_RANGE_OVERLAPS)));

    return SE_TRUE;
} // end determine_box3d_inclusion


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_Status_Code se_search_determine_box_inclusion
(
          SE_OBJECT_SEARCH_BOX     *object_box_ptr,
    const SE_SRF_Context_Info      *bounds_srf_info,
          SE_Search_Bounds         *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Dimension       search_dimension,
          SE_Boolean               *object_fully_included,
          SE_Boolean               *object_partly_included
)
{
    SE_Boolean full_2d_status = SE_TRUE;
    SE_Boolean full_3d_status = SE_TRUE;
    SE_Boolean partial_2d_status = SE_FALSE;
    SE_Boolean partial_3d_status = SE_FALSE;

    if (!SE_SRFContextInfoEqual( &object_box_ptr->srf_info,
                     bounds_srf_info))
    {
        raif_mngr->add_err_descr("se_search_determine_box_inclusion (search bounds): "\
                 "UNSUPPORTED CASE: Object and bounds must use same SRF's");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    switch (search_dimension)
    {
    case SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE:
        if (!object_box_ptr->box_2d.box_empty)
        {
            if( !determine_box2d_inclusion(
                    &object_box_ptr->box_2d.low_corner,
                    &object_box_ptr->box_2d.high_corner,
                    bounds_ptr, search_bounds_closure,
                    &full_2d_status, &partial_2d_status) )
            {
                raif_mngr->add_err_descr("se_search_determine_box_inclusion: "\
                    "Inclusion test 2D failed.");
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }

        if (!object_box_ptr->box_3d.box_empty)
        {
// We have 3D coordinates so convert them and pass them on.

            SRM_Coordinate low_corner, high_corner;

            if(SRM_DeriveCoordinate2DFrom3D(
                  &object_box_ptr->box_3d.low_corner, &low_corner )
                                               != SRM_STATCOD_SUCCESS ||
               SRM_DeriveCoordinate2DFrom3D(
                  &object_box_ptr->box_3d.high_corner, &high_corner )
                                               != SRM_STATCOD_SUCCESS )
            {
                raif_mngr->add_err_descr("se_search_determine_box_inclusion: "\
                         "Inclusion test 2D failed.");
            }

            if (!determine_box2d_inclusion(&low_corner, &high_corner,
                                  bounds_ptr, search_bounds_closure,
                                  &full_3d_status, &partial_3d_status ))
            {
                raif_mngr->add_err_descr("se_search_determine_box_inclusion: "\
                         "Inclusion test 3D failed.");
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }

        if (object_fully_included)
            *object_fully_included = (SE_Boolean)
                                     (full_2d_status && full_3d_status);
        if (object_partly_included)
            *object_partly_included = (SE_Boolean)
                                      (partial_2d_status || partial_3d_status);
        break;

    case SE_SEARCHDIM_THREE_DIMENSIONAL:
        if (!object_box_ptr->box_3d.box_empty)
        {
            if (!determine_box3d_inclusion(
                    &object_box_ptr->box_3d.low_corner,
                    &object_box_ptr->box_3d.high_corner,
                    bounds_ptr, search_bounds_closure,
                    object_fully_included, object_partly_included) )
            {
                raif_mngr->add_err_descr("se_search_determine_box_inclusion: "\
                    "Inclusion test 3D failed.");
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        else
        {
            if (object_fully_included)
                *object_fully_included = SE_FALSE;
            if (object_partly_included)
                *object_partly_included = SE_FALSE;
        }
        break;

    case SE_SEARCHDIM_ALL_DIMENSIONS:
        if (!object_box_ptr->box_2d.box_empty)
        {
            if (!determine_box2d_inclusion(
                    &object_box_ptr->box_2d.low_corner,
                    &object_box_ptr->box_2d.high_corner,
                    bounds_ptr, search_bounds_closure,
                    &full_2d_status, &partial_2d_status) )
            {
                raif_mngr->add_err_descr("se_search_determine_box_inclusion: "\
                    "Inclusion test 2D failed.");
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }

        if (!object_box_ptr->box_3d.box_empty)
        {
            if (!determine_box3d_inclusion(
                    &object_box_ptr->box_3d.low_corner,
                    &object_box_ptr->box_3d.high_corner,
                    bounds_ptr, search_bounds_closure,
                    &full_3d_status, &partial_3d_status) )
            {
                raif_mngr->add_err_descr("se_search_determine_box_inclusion: "\
                    "Inclusion test 3D failed.");
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        if (object_fully_included)
            *object_fully_included = (SE_Boolean)
                                     (full_2d_status && full_3d_status);
        if (object_partly_included)
            *object_partly_included = (SE_Boolean)
                                      (partial_2d_status || partial_3d_status);
        break;
    }
    return SE_STATCODE_SUCCESS;
}


//----------------------------------------------------------------------------
// FUNCTION: get_cumulative_angles
//----------------------------------------------------------------------------
static void get_cumulative_angles
(
    const SE_Long_Float *new_low_point,
    const SE_Long_Float *new_high_point,
          SE_Long_Float *cum_low_point,
          SE_Long_Float *cum_high_point
)
{
    SE_Long_Float low1, high1, low2, high2, lowcum, highcum;

    // Normalize the angles relative to the lower low point
    // that will be treated like 0.
    if (*new_low_point <= *cum_low_point)
    {
        low1 = *new_low_point;
        high1 = *new_high_point;
        low2 = *cum_low_point;
        high2 = *cum_high_point;
    }
    else
    {
        low1 = *cum_low_point;
        high1 = *cum_high_point;
        low2 = *new_low_point;
        high2 = *new_high_point;
    }

    /* Get all angles between low1 and low1 + 360 */
    if (high1 < low1) high1 += 360.0;
    if (low2 < low1) low2 += 360.0;
    if (high2 < low1) high2 += 360.0;

    if (low2 <= high1)
    {
        if (high2 >= low2)
        {
            lowcum = low1;
            highcum = high1 > high2 ? high1 : high2;
        }
        else
        {
            // low1 < high2 < low2 < high1, so we've completed the circle
            lowcum = -180.0;
            highcum = 180.0;
        }
    }
    else /* low2 > high1 */
    {
        if (high2 >= low2)
        {
            if (high2 - low2 <= high1 - low2 + 360.0)
            {
                lowcum = low1;
                highcum = high2;
            }
            else
            {
                lowcum = low2;
                highcum = high1;
            }
        }
        else /* high2 < low2 */
        {
            lowcum = low2;
            highcum = high1 > high2 ? high1 : high2;
        }
    }

    while (lowcum > 180.0) lowcum -= 360.0;
    while (highcum > 180.0) highcum -= 360.0;

    *cum_low_point = lowcum;
    *cum_high_point = highcum;
}


//----------------------------------------------------------------------------
//
// FUNCTION: combine_two2d_boxes
//
//   Takes old_box and cum_box and combines them, placing the status in
//   cum_box. If cum_box was empty and old_box is not, cum_box is set equal
//   to old_box (and is marked non-empty).
//
//----------------------------------------------------------------------------
static SE_Status_Code combine_two2d_boxes
(
    const SE_SRF_Context_Info *srf_info,
          SE_SIMPLE_BOX2D     *old_box,
          SE_SIMPLE_BOX2D     *cum_box
)
{
    if (old_box->box_empty)
    {
        // we have nothing in the old box, no need to add
        return SE_STATCODE_SUCCESS;
    }
    else if (cum_box->box_empty)
    {
        // we have nothing in the cumulative box, so we simply copy
        // the old box into the combined box
        cum_box->box_empty = SE_FALSE;
        cum_box->low_corner = old_box->low_corner;
        cum_box->high_corner = old_box->high_corner;
    }
    else
    {
      // they both have something, add the two boxes
      // The srf could be either 2D or 3d, but we will only need the 2D comps,
      // so we will make a temporary 2D and set it accordingly

        SE_Long_Float ol_x, ol_y, oh_x, oh_y;
        SE_Long_Float nl_x, nl_y, nh_x, nh_y;

        se_get_coords(&old_box->low_corner,  &ol_x, &ol_y);
        se_get_coords(&old_box->high_corner, &oh_x, &oh_y);
        se_get_coords(&cum_box->low_corner,  &nl_x, &nl_y);
        se_get_coords(&cum_box->high_corner, &nh_x, &nh_y);

        switch (srf_info->srf_parameters_info.value.srf_template.template_code)
        {
        case SRM_SRFTCOD_CELESTIODETIC :
            if (ol_x < nl_x) nl_x = ol_x;
            if (oh_x > nh_x) nh_x = oh_x;
            get_cumulative_angles(&ol_y, &oh_y, &nl_y, &nh_y);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
        case SRM_SRFTCOD_MERCATOR:
        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            if (ol_x < nl_x) nl_x = ol_x;
            if (oh_x > nh_x) nh_x = oh_x;
            if (ol_y < nl_y) nl_y = ol_y;
            if (oh_y > nh_y) nh_y = oh_y;
            break;

        default:
            raif_mngr->add_err_descr("combine_two2d_boxes: Unidentified SRF");
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        se_set_coords(&cum_box->low_corner,  nl_x, nl_y);
        se_set_coords(&cum_box->high_corner, nh_x, nh_y);
    }
    return SE_STATCODE_SUCCESS;
}


//----------------------------------------------------------------------------
//
// FUNCTION: combine_two3d_boxes
//
//   Takes old_box and cum_box and combines them, placing the status in
//   cum_box. If cum_box was empty and old_box is not, cum_box is set equal
//   to old_box (and is marked non-empty).
//
//----------------------------------------------------------------------------
static SE_Status_Code
combine_two3d_boxes(
    const SE_SRF_Context_Info    *srf_info,
          SE_SIMPLE_BOX3D        *old_box,
          SE_SIMPLE_BOX3D        *cum_box )
{
    if (old_box->box_empty)
    {
        // we have nothing in the old box, no need to add
        return SE_STATCODE_SUCCESS;
    }
    else if (cum_box->box_empty)
    {
        // we have nothing in the cumulative box, so we simply copy
        // the old box into the combined box
        cum_box->box_empty = SE_FALSE;
        cum_box->low_corner = old_box->low_corner;
        cum_box->high_corner = old_box->high_corner;
    }
    else
    {
        // they both have something, add the two boxes
        SE_Long_Float ol_x, ol_y, ol_z, oh_x, oh_y, oh_z;
        SE_Long_Float nl_x, nl_y, nl_z, nh_x, nh_y, nh_z;

        se_get_coords(&old_box->low_corner,  &ol_x, &ol_y, &ol_z);
        se_get_coords(&old_box->high_corner, &oh_x, &oh_y, &oh_z);
        se_get_coords(&cum_box->low_corner,  &nl_x, &nl_y, &nl_z);
        se_get_coords(&cum_box->high_corner, &nh_x, &nh_y, &nh_z);

        // combine the points from each box
        switch( srf_info->srf_parameters_info.value.srf_template.template_code )
        {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
        case SRM_SRFTCOD_MERCATOR:
        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            if (ol_x < nl_x) nl_x = ol_x;
            if (oh_x > nh_x) nh_x = oh_x;
            if (ol_y < nl_y) nl_y = ol_y;
            if (oh_y > nh_y) nh_y = oh_y;
            if (ol_z < nl_z) nl_z = ol_z;
            if (oh_z > nh_z) nh_z = oh_z;
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
        case SRM_SRFTCOD_CELESTIOMAGNETIC:
        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            if (ol_x < nl_x) nl_x = ol_x;
            if (oh_x > nh_x) nh_x = oh_x;
            get_cumulative_angles(&ol_y, &oh_y, &nl_y, &nh_y);
            if (ol_z < nl_z) nl_z = ol_z;
            if (oh_z > nh_z) nh_z = oh_z;
            break;

        default:
            raif_mngr->add_err_descr("combine_two3d_boxes: Unidentified SRF");
            return SE_STATCODE_INACTIONABLE_FAILURE;
            break;

        }
        se_set_coords(&cum_box->low_corner,  nl_x, nl_y, nl_z);
        se_set_coords(&cum_box->high_corner, nh_x, nh_y, nh_z);
    }
    return SE_STATCODE_SUCCESS;
}


//----------------------------------------------------------------------------
// FUNCTION: se_search_add_boxes
//----------------------------------------------------------------------------
static SE_Status_Code
se_search_add_boxes( SE_OBJECT_SEARCH_BOX *old_box,
                     SE_OBJECT_SEARCH_BOX *cum_box )
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    /* Check ... cannot combine different SRFs. But we only check
     * if the cumulative box is non-empty. If the cumulative box is empty, we
     * must copy the SRF parameters from the new box.
     */
    if (cum_box->box_2d.box_empty && cum_box->box_3d.box_empty)
    {
        memcpy( &cum_box->srf_info, &old_box->srf_info,
               sizeof(SE_SRF_Context_Info));
    }
    else if (!SE_SRFContextInfoEqual( &old_box->srf_info, &cum_box->srf_info ))
    {
        raif_mngr->add_err_descr("se_search_add_boxes: Can't combine different SRFs.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    /*
     * Boxes are of the same SRF. Combine the boxes and return the status
     */
    if (combine_two2d_boxes(&old_box->srf_info,
                   &old_box->box_2d, &cum_box->box_2d) != SE_STATCODE_SUCCESS)
    {
        raif_mngr->add_err_descr("se_search_add_boxes: Can't combine two 2D boxes.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if (combine_two3d_boxes(&old_box->srf_info,
                   &old_box->box_3d, &cum_box->box_3d) != SE_STATCODE_SUCCESS)
    {
        raif_mngr->add_err_descr("se_search_add_boxes: Can't combine two 3D boxes.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}


//----------------------------------------------------------------------------
//
// FUNCTION: get_axis_extrema
//
//   axis_obj -- guaranteed by caller to be an <Axis> instance
//
//----------------------------------------------------------------------------
static SE_Status_Code
get_axis_extrema
(
    SE_Api_Object       *axis_obj,
    EDCS_Attribute_Code *axis_type_ptr,
    SE_Spacing_Type     *spacing_ptr,
    SE_Long_Float       *min_value_ptr,
    SE_Long_Float       *max_value_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_FIELDS_PTR  fields_ptr;

    fields_ptr = axis_obj->GetIntObj()->OrigFields();

    if (fields_ptr->tag == SE_CLS_DRM_ENUMERATION_AXIS)
    {
        axis_obj->raif_mngr()->add_err_descr("Encountered <Enumeration Axis> instance, "\
                 "expected <Property Grid> spatial axis");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_ValidFields(fields_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        axis_obj->raif_mngr()->add_err_descr("Encountered <Axis> instance with invalid fields "\
                 "while computing search point for <Property Grid>");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        *axis_type_ptr = fields_ptr->u.Axis.axis_type;
        *spacing_ptr = SE_SPACTYP_ARITHMETIC;  // default
    }

    if (status != SE_STATCODE_SUCCESS)
    {
        return status;
    }

    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_REGULAR_AXIS:
// $$$ what about the units/scale ????
// $$$ what about the Axis alignment ???
//
             SE_Long_Float spacing;

             switch(fields_ptr->u.Regular_Axis.spacing_type)
             {
                 case SE_SPACTYP_ARITHMETIC:
                      if( SE_SingleValueToLongFloat(
                           &fields_ptr->u.Regular_Axis.first_value,
                            min_value_ptr) != SE_DRM_STAT_CODE_SUCCESS)
                      {
                          axis_obj->raif_mngr()->add_err_descr("get_axis_extrema: bad first_value");
                          status = SE_STATCODE_INACTIONABLE_FAILURE;
                      }
                      else if (SE_SingleValueToLongFloat(
                                &fields_ptr->u.Regular_Axis.spacing,
                                &spacing) != SE_DRM_STAT_CODE_SUCCESS)
                      {
                          axis_obj->raif_mngr()->add_err_descr("get_axis_extrema: bad spacing value");
                          status = SE_STATCODE_INACTIONABLE_FAILURE;
                      }
                      else
                      {
                          *max_value_ptr = *min_value_ptr +
                             (fields_ptr->u.Regular_Axis.axis_value_count - 1)
                           * spacing;
                      }
                      break;

                 case SE_SPACTYP_GEOMETRIC:
                      if (SE_SingleValueToLongFloat(
                           &fields_ptr->u.Regular_Axis.first_value,
                           min_value_ptr) != SE_DRM_STAT_CODE_SUCCESS)
                      {
                          axis_obj->raif_mngr()->add_err_descr("Error attempting to get Axis Extrema ");
                          status = SE_STATCODE_INACTIONABLE_FAILURE;
                      }
                      else if (SE_SingleValueToLongFloat(
                                &fields_ptr->u.Regular_Axis.spacing,
                                &spacing) != SE_DRM_STAT_CODE_SUCCESS)
                      {
                          axis_obj->raif_mngr()->add_err_descr("Error attempting to get Axis Extrema ");
                          status = SE_STATCODE_INACTIONABLE_FAILURE;
                      }
                      else
                      {
                          *max_value_ptr = (*min_value_ptr)
                            * pow(spacing,*max_value_ptr - 1);

                          *spacing_ptr = SE_SPACTYP_GEOMETRIC;
                      }
                      break;

                 default:
                      axis_obj->raif_mngr()->add_err_descr("get_axis_extrema (search bounds): unknown "\
                               "type of Regular Axis spacing.");
                      status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;

        case SE_CLS_DRM_IRREGULAR_AXIS:
             if (SE_SingleValueToLongFloat(
                  &fields_ptr->u.Irregular_Axis.axis_value_array[0],
                  min_value_ptr) != SE_DRM_STAT_CODE_SUCCESS)
             {
                 axis_obj->raif_mngr()->add_err_descr("Error attempting to get Axis Extrema ");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             else if (SE_SingleValueToLongFloat(
                  &fields_ptr->u.Irregular_Axis.axis_value_array
                  [fields_ptr->u.Irregular_Axis.axis_value_count-1],
                    max_value_ptr) != SE_DRM_STAT_CODE_SUCCESS)
             {
                 axis_obj->raif_mngr()->add_err_descr("Error attempting to get Axis Extrema ");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;

        case SE_CLS_DRM_INTERVAL_AXIS:
        {
// $$$ this needs to handle unit and scale
             RAIF_Interval_Value  numeric_interval;

             get_RAIF_Interval(
                 fields_ptr->u.Interval_Axis.axis_interval_value_array[0],
                 numeric_interval );

             *min_value_ptr = numeric_interval.lb;
             *max_value_ptr = numeric_interval.ub;
             break;
        }

        default:
             axis_obj->raif_mngr()->add_err_descr("get_axis_extrema: Unknown axis type");
             status = SE_STATCODE_INACTIONABLE_FAILURE;
             break;
    }
    return status;
}

//----------------------------------------------------------------------------
//
// FUNCTION: get_box2d_corners
//
//----------------------------------------------------------------------------
static SE_Status_Code get_box2d_corners
(
    SE_SIMPLE_BOX2D *box,
    SRM_Coordinate   corners[8]
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Byte_Unsigned            i, j, k;

    for (i = 0; i < 2 && status == SE_STATCODE_SUCCESS; i++)
    {
        for (j = 0; j < 2 && status == SE_STATCODE_SUCCESS; j++)
        {
            for (k = 0; k < 2 && status == SE_STATCODE_SUCCESS; k++)
            {
                SE_Byte_Unsigned     corner_no = i * 4 + j * 2 + k;
                SRM_Coordinate *corner  = &(corners[corner_no]);

                *corner = box->low_corner;

                SE_Long_Float lx, ly, hx, hy;
                SE_Long_Float cx, cy;

                se_get_coords(&box->low_corner, &lx, &ly);
                se_get_coords(&box->high_corner, &hx, &hy);

                switch( box->low_corner.spatial_coord_code )
                {
                   case SRM_SPACOORDCOD_CD_SURFACE :
                   case SRM_SPACOORDCOD_EC_SURFACE :
                   case SRM_SPACOORDCOD_PS_SURFACE :
                   case SRM_SPACOORDCOD_LCC_SURFACE :
                   case SRM_SPACOORDCOD_TM_SURFACE :
                   case SRM_SPACOORDCOD_LTSE_SURFACE :
                   case SRM_SPACOORDCOD_LSR_2D :
                   case SRM_SPACOORDCOD_M_SURFACE :
                   case SRM_SPACOORDCOD_OMS_SURFACE :
                       cx = (i == 0 ? lx : hx);
                       cy = (j == 0 ? ly : hy);
                       break;

                   default:
                       raif_mngr->add_err_descr("get_box2d_corners: invalid SRF");
                       status = SE_STATCODE_INACTIONABLE_FAILURE;
                       break;
                }
                se_set_coords(corner, cx, cy);
            }
        }
    }
    return status;
} // end get_box2d_corners


//----------------------------------------------------------------------------
//
// FUNCTION: get_box3d_corners
//
//----------------------------------------------------------------------------
static SE_Status_Code get_box3d_corners(
    SE_SIMPLE_BOX3D *box, SRM_Coordinate      corners[8] )
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Byte_Unsigned            i, j, k;

    for (i = 0; i < 2 && status == SE_STATCODE_SUCCESS; i++)
    {
        for (j = 0; j < 2 && status == SE_STATCODE_SUCCESS; j++)
        {
            for (k = 0; k < 2 && status == SE_STATCODE_SUCCESS; k++)
            {
                SE_Byte_Unsigned     corner_no = i * 4 + j * 2 + k;
                SRM_Coordinate *corner  = &(corners[corner_no]);

                *corner = box->low_corner;

                SE_Long_Float lx, ly, lz, hx, hy, htz;
                SE_Long_Float cx, cy, cz;

                se_get_coords(&box->low_corner, &lx, &ly, &lz);
                se_get_coords(&box->high_corner, &hx, &hy, &htz);

                switch( box->low_corner.spatial_coord_code )
                {
                   case SRM_SPACOORDCOD_CD_3D :
                   case SRM_SPACOORDCOD_CC_3D :
                   case SRM_SPACOORDCOD_CM_3D :
                   case SRM_SPACOORDCOD_SEC_3D :
                   case SRM_SPACOORDCOD_SME_3D :
                   case SRM_SPACOORDCOD_SMD_3D :
                   case SRM_SPACOORDCOD_EC_AUGMENTED_3D :
                   case SRM_SPACOORDCOD_PS_AUGMENTED_3D :
                   case SRM_SPACOORDCOD_LCC_AUGMENTED_3D :
                   case SRM_SPACOORDCOD_TM_AUGMENTED_3D :
                   case SRM_SPACOORDCOD_LTSE_3D :
                   case SRM_SPACOORDCOD_LSR_3D :
                   case SRM_SPACOORDCOD_M_AUGMENTED_3D :
                   case SRM_SPACOORDCOD_OMS_AUGMENTED_3D :
                       cx = (i == 0 ? lx : hx);
                       cy = (j == 0 ? ly : hy);
                       cz = (k == 0 ? lz : htz);
                       break;

                   case SRM_SPACOORDCOD_EI_3D:
                       cx = (j == 0 ? lx : hx); // notice i<>j exchange
                       cy = (i == 0 ? ly : hy);
                       cz = (k == 0 ? lz : htz);
                       break;

                   default:
                       raif_mngr->add_err_descr("get_box3d_corners: invalid SRF");
                       status = SE_STATCODE_INACTIONABLE_FAILURE;
                       break;
                }
                se_set_coords(corner, cx, cy, cz);
            }
        }
    }
    return status;
} // end get_box3d_corners


//----------------------------------------------------------------------------
//
// FUNCTION: get_circumscribed_search_box
//
// PARAMETERS:
//
//   ori_box -- guaranteed by the caller to be non-NULL
//
//   new_srf_info -- guaranteed by the caller to be non-NULL
//
//   circumscribed_box -- guaranteed by the caller to be non-NULL
//
//----------------------------------------------------------------------------
static SE_Status_Code get_circumscribed_search_box(
          SE_OBJECT_SEARCH_BOX  *ori_box,
    const SE_SRF_Context_Info   *new_srf_info,
          SE_OBJECT_SEARCH_BOX  *circumscribed_box )
{
    SE_Status_Code       status = SE_STATCODE_SUCCESS;
    SRM_Status_Code      coord_status = SRM_STATCOD_SUCCESS;
    SRM_Coordinate       old_coord, new_coord;
    SRM_Coordinate       old_coord3d[8];
    SRM_Coordinate       old_coord2d[8];
    SE_Byte_Unsigned     i;
    SE_OBJECT_SEARCH_BOX coord_box;

    null_search_box(circumscribed_box);

    memcpy( &(circumscribed_box->srf_info), new_srf_info, sizeof( SE_SRF_Context_Info ));

    if (!ori_box->box_3d.box_empty)
    {
        if (get_box3d_corners(&ori_box->box_3d,
                              old_coord3d) != SE_STATCODE_SUCCESS)
        {
            raif_mngr->add_err_descr("get_circumscribed_search_box: Can't get 3D corners.");
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        for (i=0 ; i < 8 && status == SE_STATCODE_SUCCESS ; i++)
        {
            old_coord = old_coord3d[i];

            if (RAIFChangeCoordSRFFromContextInfo( &ori_box->srf_info,
                &old_coord, new_srf_info, &new_coord ) != SRM_STATCOD_SUCCESS)
            {
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
            status = init_box_from_coord( new_srf_info,
                                         &new_coord, &coord_box );
            if (status == SE_STATCODE_SUCCESS)
            {
                status = se_search_add_boxes(&coord_box, circumscribed_box);
            }
        }

        if (status != SE_STATCODE_SUCCESS )
        {
            raif_mngr->add_err_descr("get_circumscribed_search_box: "\
                     "Couldn't build 3D circumscribed box.");
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    if (!ori_box->box_2d.box_empty)
    {
        if (get_box2d_corners( &ori_box->box_2d,
                               old_coord2d) != SE_STATCODE_SUCCESS)
        {
            raif_mngr->add_err_descr("get_circumscribed_search_box: Can't get 2D corners");
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }

        for (i = 0; i < 8 && status == SE_STATCODE_SUCCESS; i++)
        {
            old_coord = old_coord2d[i];

            if( RAIFChangeCoordSRFFromContextInfo( &ori_box->srf_info, &old_coord,
                                                   new_srf_info, &new_coord ) != SRM_STATCOD_SUCCESS )
            {
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
            status = init_box_from_coord( new_srf_info,
                              &new_coord, &coord_box );

            if (status == SE_STATCODE_SUCCESS)
            {
                status = se_search_add_boxes(
                                 &coord_box, circumscribed_box);
            }
        }

        if (status != SE_STATCODE_SUCCESS ||
            coord_status != SRM_STATCOD_SUCCESS)
        {
            raif_mngr->add_err_descr("get_circumscribed_search_box: "\
                        "Couldn't build 2D circumscribed box.");
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    if (OBJSTATUS_VALID(status))
        return SE_STATCODE_SUCCESS;
    else
        return SE_STATCODE_INACTIONABLE_FAILURE;
}


//----------------------------------------------------------------------------
// FUNCTION: se_search_compute_spatial_box
//
// $$$ NOTE: everything must be in the same SRF!!!
//           must convert the boxes into the parameter SRF -
//           doesn't this cause problems???
//----------------------------------------------------------------------------
SE_Status_Code se_search_compute_spatial_box(
    SE_Api_Object        *spatial_obj,
    SE_Api_Object        *link_obj,
    SE_OBJECT_SEARCH_BOX *box )
{
    // Each spatial index has a location component
    SE_Api_Object       *location;
    SRM_Coordinate       tmpcoord, ll, ur;
    SE_FIELDS_PTR        linkFields, spatialFields;
    SE_Status_Code       status = SE_STATCODE_SUCCESS;

    // $$$ what is this really trying to do?
    // how is tmpcoord used later?
//  SE_Integer_Unsigned i=0;
//  while (spatial_obj->GetNthComponentOfDRMClass(i, &location, NULL,
//                               SE_CLS_DRM_LOCATION) == SE_STATCODE_SUCCESS)
//  {
//      SE_FIELDS_PTR tmpfields = location->fields(&status);
//      SE_ConvertFieldsToCoord(tmpfields, &tmpcoord);
//      i++;
//  }

    status = spatial_obj->GetNthComponentOfDRMClass( 0,
                             SE_CLS_DRM_LOCATION, &location, NULL);

    status = (OBJSTATUS_VALID(status) ?
                    SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE);

    if (status != SE_STATCODE_SUCCESS)
    {
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_FIELDS_PTR temp_fields;

        temp_fields = location->fields(&status);

        if (!SE_ConvertFieldsToCoordinate(temp_fields, &tmpcoord))
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        SAFE_RELEASE(location);
        if (!OBJSTATUS_VALID(status))
           return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    spatialFields = spatial_obj->GetIntObj()->OrigFields();
    linkFields    = link_obj->GetIntObj()->OrigFields();

    SE_Integer_Unsigned                 row, col;
    SE_Long_Float                delta_x1, delta_x2, delta_y1, delta_y2;
    SE_Spatial_Index_Spacing_Unit units;

    if (spatial_obj->tag() == SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY)
    {
        row = linkFields->u.Spatial_Index_Data.row_index-1;
        col = linkFields->u.Spatial_Index_Data.column_index-1;

        delta_x1 = col * spatialFields->
            u.Spatial_Index_Related_Geometry.column_width;

        delta_y1 = row * spatialFields->
            u.Spatial_Index_Related_Geometry.row_width;

        units = spatialFields->u.Spatial_Index_Related_Geometry.spacing_unit;

        delta_x2 = delta_x1 + spatialFields->
            u.Spatial_Index_Related_Geometry.column_width;

        delta_y2 = delta_y1 + spatialFields->
            u.Spatial_Index_Related_Geometry.row_width;
    }
    else
    {
        row = linkFields->u.Spatial_Index_Data.row_index-1;
        col = linkFields->u.Spatial_Index_Data.column_index-1;

        delta_x1 = col * spatialFields->
            u.Spatial_Index_Related_Features.column_width;

        delta_y1 = row * spatialFields->
            u.Spatial_Index_Related_Features.row_width;

        units = spatialFields->u.Spatial_Index_Related_Features.spacing_unit;

        delta_x2 = delta_x1 + spatialFields->
            u.Spatial_Index_Related_Features.column_width;

        delta_y2 = delta_y1 + spatialFields->
            u.Spatial_Index_Related_Features.row_width;
    }

    ll = tmpcoord;
    ur = tmpcoord;

    if (!se_offset_coord(&ll, delta_x1, delta_y1, units) ||
        !se_offset_coord(&ur, delta_x2, delta_y2, units))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        null_search_box(box);

        SE_OBJECT_SEARCH_BOX tmpbox;
        SE_SRF_Context_Info srf_info;

        spatial_obj->get_srf_info(&srf_info);

        init_box_from_coord( &srf_info, &ll, &tmpbox);

        if (se_search_add_boxes(&tmpbox, box) != SE_STATCODE_SUCCESS)
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            init_box_from_coord(&srf_info, &ur, &tmpbox);

            if (se_search_add_boxes(&tmpbox, box) != SE_STATCODE_SUCCESS)
                status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    if (OBJSTATUS_VALID(status))
        return SE_STATCODE_SUCCESS;
    else
        return SE_STATCODE_INACTIONABLE_FAILURE;
}


//----------------------------------------------------------------------------
SE_Status_Code se_search_compute_perimeter_box(
    SE_Api_Object            *link_obj,
    SE_OBJECT_SEARCH_BOX *box )
{
    SE_Integer_Unsigned  i=0;
    SE_Status_Code       status = SE_STATCODE_SUCCESS;
    SE_OBJECT_SEARCH_BOX tmpbox;

    null_search_box(box);

    for (i=0; OBJSTATUS_VALID(status); i++)
    {
        SE_Api_Object *location;

        status = link_obj->GetNthComponentOfDRMClass( i,
                           SE_CLS_DRM_LOCATION, &location, NULL);

        if (OBJSTATUS_VALID(status))
        {
            se_search_box_from_location(location, &tmpbox);

            SAFE_RELEASE(location);

            if (se_search_add_boxes(&tmpbox, box) != SE_STATCODE_SUCCESS)
            {
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
    }

    if (i < 3)
    {
        link_obj->raif_mngr()->add_err_descr
        ("se_search_compute_perimeter_box: received fewer than 3 "\
         "<Location> components from ");
        link_obj->raif_mngr()->add_err_descr
        (SE_GetDRMClassString(link_obj->tag()));
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return SE_STATCODE_SUCCESS;
}


//
SE_Status_Code se_search_compute_domain_box
(
    SE_Api_Object        *domain,
    SE_OBJECT_SEARCH_BOX *box
)
{
    SE_Status_Code        status = SE_STATCODE_SUCCESS;
    SE_Api_Object        *ll=NULL, *ur=NULL;
    SE_OBJECT_SEARCH_BOX  tmpbox;
    SE_Boolean            is_2D = SE_FALSE;

    null_search_box(box);

    // Get the Spatial Domain's two location components
    status = domain->GetNthComponentOfDRMClass( 0,
                              SE_CLS_DRM_LOCATION, &ll, NULL);

    if (!OBJSTATUS_VALID(status))
    {
        domain->raif_mngr()->add_err_descr("se_search_compute_domain_box: "\
                "Can't get first location component from spatial domain");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    status = domain->GetNthComponentOfDRMClass( 1,
                              SE_CLS_DRM_LOCATION, &ur, NULL);

    if (!OBJSTATUS_VALID(status))
    {
        domain->raif_mngr()->add_err_descr("se_search_compute_domain_box: "\
            "Can't get second location component from spatial domain");
        SAFE_RELEASE(ll);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    is_2D=(SE_IsA[ll->tag()][SE_CLS_DRM_LOCATION_2D] ||
           SE_IsA[ll->tag()][SE_CLS_DRM_LOCATION_SURFACE] ? SE_TRUE : SE_FALSE);

    if( is_2D == SE_TRUE &&
                 SE_IsA[ur->tag()][SE_CLS_DRM_LOCATION_3D] )
    {
        domain->raif_mngr()->add_err_descr("se_search_compute_domain_box: "\
                 "<Spatial Domain>'s locations are of different dimensions");
        SAFE_RELEASE(ll);
        SAFE_RELEASE(ur);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    se_search_box_from_location(ll, &tmpbox);

    if (se_search_add_boxes(&tmpbox, box) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        se_search_box_from_location(ur, &tmpbox);

        if (se_search_add_boxes(&tmpbox, box) != SE_STATCODE_SUCCESS)
            status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    SAFE_RELEASE(ll);
    SAFE_RELEASE(ur);

    if (OBJSTATUS_VALID(status) &&
        (is_2D && box->box_3d.box_empty))
    {
        SRM_Coordinate *low2_corner_ptr  = &box->box_2d.low_corner;
        SRM_Coordinate *high2_corner_ptr = &box->box_2d.high_corner;
        SRM_Coordinate *low3_corner_ptr  = &box->box_3d.low_corner;
        SRM_Coordinate *high3_corner_ptr = &box->box_3d.high_corner;

        SE_Long_Float  low2X, low2Y, high2X, high2Y;

        se_get_coords( low2_corner_ptr, &low2X, &low2Y);
        se_get_coords(high2_corner_ptr, &high2X, &high2Y);

        switch( box->box_2d.low_corner.spatial_coord_code )
        {
           case SRM_SPACOORDCOD_CD_3D:
           case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
           case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
           case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
           case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
           case SRM_SPACOORDCOD_LSR_3D:
           case SRM_SPACOORDCOD_M_AUGMENTED_3D:
           case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
               se_set_coords(low3_corner_ptr,
                               low2X, low2Y, SE_NEGATIVE_INFINITY);
               se_set_coords(high3_corner_ptr,
                               high2X, high2Y, SE_POSITIVE_INFINITY);
               break;
           default:
               domain->raif_mngr()->add_err_descr("se_search_compute_domain_box: "\
                       "Unidentified corresponding 3D SRF");
               status = SE_STATCODE_INACTIONABLE_FAILURE;
               break;
        }
    }
    if (OBJSTATUS_VALID(status))
        return SE_STATCODE_SUCCESS;
    else
        return status;
}
