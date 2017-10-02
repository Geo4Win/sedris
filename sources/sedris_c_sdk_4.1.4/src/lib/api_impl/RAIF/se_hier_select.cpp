// SEDRIS Level 0 Read API
//
// FILE       : se_hier_select.cpp
//
// PROGRAMMERS: Howard Lu (SAIC)
//
// DESCRIPTION: Auxiliary Functions to determine viability of a search
//              option given selection parameters.
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

#include "se_hier_select.hpp"
#include "SE_InternalObject.hpp"
#include "SE_Context.hpp"
#include "SE_Time.hpp"
#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


// Function Declarations

static SE_Boolean
check_alternate
(
    SE_InternalObject       *link,
    SE_Integer_Unsigned      hierarchy_count,
    SE_Hierarchy_Data_Fields hierarchy_data[]
);

static SE_Boolean
check_classification
(
    SE_InternalObject       *link,
    SE_Integer_Unsigned      classification_count,
    SE_Classification_Entry  classification_array[]
);

static SE_Boolean
check_continuous_lod
(
    SE_InternalObject          *aggregate_object,
    SE_InternalObject          *component_object,
    SE_Continuous_LOD_Select_Choice  select
);

static SE_Boolean
check_lod
(
    SE_InternalObject           *link,
    SE_Integer_Unsigned          lod_count,
    SE_Branch_Range_Matching     matching_rules,
    SE_LOD_Entry                 lod_entries[],
    SE_General_Hierarchy_Select *select
);

static SE_Boolean
check_octant
(
    SE_InternalObject       *link,
    SE_Integer_Unsigned      octant_count,
    SE_Octant_Data_Fields  octant_data[]
);

static SE_Boolean
check_quadrant
(
    SE_InternalObject       *link,
    SE_Integer_Unsigned      quadrant_count,
    SE_Quadrant_Data_Fields quadrant_data[]
);

static SE_Boolean
check_separating_planes
(
    SE_InternalObject *link,
    SE_Boolean         traverse_positive_branches,
    SE_Boolean         traverse_negative_branches
);

static SE_Boolean
check_spatial_index
(
    SE_InternalObject             *link,
    SE_Integer_Unsigned            spatial_index_count,
    SE_Spatial_Index_Data_Fields   spatial_index_data[]
);

static SE_Boolean
check_state
(
    SE_InternalObject            *stateRelated,
    SE_Context                   *context,
    SE_InternalObject            *link,
    SE_Unmatched_State_Behaviour  default_choice,
    SE_Branch_Range_Matching      matching_rules,
    SE_Integer_Unsigned           state_entry_count,
    SE_State_Entry                state_entry_array[]
);

static SE_Boolean
check_animation
(
    SE_Integer_Unsigned which,
    SE_Integer_Unsigned ranges_count,
    SE_Animation_Range  animation_ranges[]
);


//-----------------------------------------------------------------------------
//
// FUNCTION: check_general_select
//
//   This method returns whether or not components of an object obj
//   satisfies the general selection rules or not.
//
//   This function has been modified to return a SE_Hierarchy_Inclusion
//   being (SE_HIERINC_INCLUDE_ALL, SE_HIERINC_EXCLUDE_ALL, SE_HIERINC_EVALUATE_RULES, so that
//   hier_select_check knows to short circuit or continue evaluating rules.
//   Masks that are SE_BOOLEANS in the HIERARCHY_SELECT_PARAMETERS will
//   only return SE_HIERINC_INCLUDE_ALL or SE_HIERINC_EXCLUDE_ALL based on the boolean
//   value
//-----------------------------------------------------------------------------
static SE_Hierarchy_Inclusion check_general_select
(
    SE_Hierarchy_Select_Parameters *select,
    SE_Api_Object                      *obj
)
{
    SE_General_Hierarchy_Select *mask = &select->general_hierarchy_mask;
    SE_Hierarchy_Inclusion result = SE_HIERINC_INCLUDE_ALL;
    SE_FIELDS_PTR     field_ptr;

    switch (obj->tag())
    {
    case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
    case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
        result = mask->alternate_hierarchy;
        break;

    case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
        result = mask->animation_related;
        break;

    case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
    case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
        result = mask->classification_related;
        break;

    case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
        result = mask->continuous_lod_related;
        break;

    case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
    case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
        result = mask->octant_related;
        break;

    case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
    case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
         if(mask->perimeter_related == SE_TRUE)
         {
             result = SE_HIERINC_INCLUDE_ALL;
         }
         else
         {
             result = SE_HIERINC_EXCLUDE_ALL;
         }
         break;

    case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
    case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
        result = mask->quadrant_related;
        break;

    case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
        result = mask->separating_plane;
        break;

    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
        result = mask->spatial_index_related;
        break;

    case SE_CLS_DRM_STATE_RELATED_FEATURES:
    case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
        result = mask->state_related;
        break;

    case SE_CLS_DRM_UNION_OF_FEATURES:
         if(mask->union_of_features == SE_TRUE)
         {
             result = SE_HIERINC_INCLUDE_ALL;
         }
         else
         {
             result = SE_HIERINC_EXCLUDE_ALL;
         }
         break;

    case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
        if(mask->union_of_geometry_hierarchies == SE_TRUE)
        {
            result = SE_HIERINC_INCLUDE_ALL;
        }
        else
        {
            result = SE_HIERINC_EXCLUDE_ALL;
        }
        break;

    case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
        if(mask->union_of_geometry_primitives == SE_TRUE)
        {
            result = SE_HIERINC_INCLUDE_ALL;
        }
        else
        {
            result = SE_HIERINC_EXCLUDE_ALL;
        }
        break;

    case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
        {
            field_ptr = obj->GetIntObj()->OrigFields();

            const SE_LOD_Related_Geometry_Fields *field =
                &field_ptr->u.LOD_Related_Geometry;

            if (mask->lod_related)
            {
                switch (field->lod_data_type)
                {
                case SE_LODDATTYP_DISTANCE:
                    result = mask->lod_distance_related;
                    break;
                case SE_LODDATTYP_INDEX:
                    result = mask->lod_index_related;
                    break;
                case SE_LODDATTYP_MAP_SCALE:
                    result = mask->lod_map_scale_related;
                    break;
                case SE_LODDATTYP_VOLUME:
                    result = mask->lod_volume_related;
                    break;
                case SE_LODDATTYP_SPATIAL_RESOLUTION:
                    result = mask->lod_spatial_resolution_related;
                    break;
                } /* end switch */
            }
            else
            {
                result = SE_HIERINC_EXCLUDE_ALL;
            }
        }
        break;

    case SE_CLS_DRM_LOD_RELATED_FEATURES:
        {
            field_ptr = obj->GetIntObj()->OrigFields();

            const SE_LOD_Related_Features_Fields *field =
                &field_ptr->u.LOD_Related_Features;

            if (mask->lod_related)
            {
                switch (field->lod_data_type)
                {
                case SE_LODDATTYP_DISTANCE:
                    result = mask->lod_distance_related;
                    break;
                case SE_LODDATTYP_INDEX:
                    result = mask->lod_index_related;
                    break;
                case SE_LODDATTYP_MAP_SCALE:
                    result = mask->lod_map_scale_related;
                    break;
                case SE_LODDATTYP_VOLUME:
                    result = mask->lod_volume_related;
                    break;
                case SE_LODDATTYP_SPATIAL_RESOLUTION:
                    result = mask->lod_spatial_resolution_related;
                    break;
                } /* end switch */
            }
            else
            {
                result = SE_HIERINC_EXCLUDE_ALL;
            }
        }
        break;

    case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
        {
            field_ptr = obj->GetIntObj()->OrigFields();

            const SE_Time_Related_Geometry_Fields *field =
                &field_ptr->u.Time_Related_Geometry;

            if (mask->time_related)
            {
                switch (field->time_data_type)
                {
                case SE_TIMEDATTYP_SEASON:
                    result = mask->time_related_by_season;
                    break;
                case SE_TIMEDATTYP_TIME_INTERVAL:
                    result = mask->time_related_by_time_interval;
                    break;
                case SE_TIMEDATTYP_TIME_OF_DAY:
                    result = mask->time_related_by_time_of_day;
                    break;
                case SE_TIMEDATTYP_TIME_POINT:
                    result = mask->time_related_by_time_point;
                    break;
                } /* end switch */
            }
            else
            {
                result = SE_HIERINC_EXCLUDE_ALL;
            }
        }
        break;

    case SE_CLS_DRM_TIME_RELATED_FEATURES:
        {
            field_ptr = obj->GetIntObj()->OrigFields();

            const SE_Time_Related_Features_Fields *field =
                &field_ptr->u.Time_Related_Features;

            if (mask->time_related)
            {
                switch (field->time_data_type)
                {
                case SE_TIMEDATTYP_SEASON:
                    result = mask->time_related_by_season;
                    break;
                case SE_TIMEDATTYP_TIME_INTERVAL:
                    result = mask->time_related_by_time_interval;
                    break;
                case SE_TIMEDATTYP_TIME_OF_DAY:
                    result = mask->time_related_by_time_of_day;
                    break;
                case SE_TIMEDATTYP_TIME_POINT:
                    result = mask->time_related_by_time_point;
                    break;
                } /* end switch */
            }
            else
            {
                result = SE_HIERINC_EXCLUDE_ALL;
            }
        }
        break;
    }
    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: hier_select_check
//
//   Determines if a component (indexed by which in the ordered components
//   list) of an object of type aggregate_type, with a link_field of link,
//   satisfies the select parameters or not.
//
// RETURNS:
//   SE_TRUE if it passes the select parameters,
//   SE_FALSE otherwise.
//
//----------------------------------------------------------------------------
SE_Boolean
hier_select_check
(
    SE_Hierarchy_Select_Parameters  *select_params,
       TimeEntry                     time_data[],
    SE_Integer_Unsigned              which,
    SE_Api_Object                   *aggregate,
    SE_Api_Object                   *component,
    SE_Api_Object                   *link
)
{
    SE_Boolean             result = SE_TRUE;
    SE_DRM_Class           aggregate_type = aggregate->tag();
    SE_Hierarchy_Inclusion inclusion_rule = SE_HIERINC_INCLUDE_ALL;

    if (!select_params)
    {
        return SE_TRUE;
    }

    // check_general_select will tell us if we are including all, excluding
    // all, or evaluating rules.  It will drop through to the switch statement
    // only if we are evaluating rules.  However some of the evaluation calls
    // will still be checking for SE_HIERINC_INCLUDE_ALL, which at this point
    // has already been checked.
    if((inclusion_rule = check_general_select(select_params, aggregate))
       == SE_HIERINC_EXCLUDE_ALL)
    {
        return SE_FALSE;
    }
    else if(inclusion_rule == SE_HIERINC_INCLUDE_ALL)
    {
        return SE_TRUE;
    }

    switch (aggregate_type)
    {
    case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
    case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_alternate( link->GetIntObj(),
                select_params->alternate_hierarchy_branches.
                hierarchy_data_count,
                select_params->alternate_hierarchy_branches.
                hierarchy_data_array );
        }
        break;

    case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_animation
                (
                which,
                select_params->
                animation_branches.ranges_count,
                select_params->
                animation_branches.
                animation_ranges_array
                );
        }
        break;

    case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
    case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_classification( link->GetIntObj(),
                select_params->classification_branches.
                classification_count,
                select_params->classification_branches.
                classification_array );
        }
        break;

    case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
            result = check_continuous_lod(
                aggregate->GetIntObj(),
                component->GetIntObj(),
                select_params->continuous_lod_branches.clod_choice );

        break;

    case SE_CLS_DRM_LOD_RELATED_FEATURES:
    case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_lod( link->GetIntObj(),
                select_params->lod_branches.lod_entry_count,
                select_params->lod_branches.matching_rules,
                select_params->lod_branches.lod_entry_array,
                &select_params->general_hierarchy_mask );
        }
        break;

    case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
    case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_octant( link->GetIntObj(),
                select_params->octant_branches.
                octant_data_count,
                select_params->octant_branches.
                octant_data_array );
        }
        break;

    case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
    case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else // Trivial Acceptance.  To limit searches by perimeter,
            // use a spatial search filter.
            result = SE_TRUE;
        break;

    case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
    case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_quadrant( link->GetIntObj(),
                select_params->quadrant_branches.
                quadrant_data_count,
                select_params->quadrant_branches.
                quadrant_data_array );
        }
        break;

    case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_separating_planes( link->GetIntObj(),
                select_params->separating_plane_branches.
                traverse_positive_branches,
                select_params->separating_plane_branches.
                traverse_negative_branches );
        }
        break;

    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
    case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_spatial_index( link->GetIntObj(),
                select_params->spatial_index_branches.
                spatial_index_data_count,
                select_params->spatial_index_branches.
                spatial_index_data_array );
        }
        break;

    case SE_CLS_DRM_STATE_RELATED_FEATURES:
    case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = check_state(
                aggregate->GetIntObj(), aggregate->get_context(),
                link->GetIntObj(),
                select_params->state_branches.default_choice,
                select_params->state_branches.matching_rules,
                select_params->state_branches.
                state_entry_count,
                select_params->state_branches.
                state_entry_array );
        }
        break;

    case SE_CLS_DRM_TIME_RELATED_FEATURES:
    case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
        if (link == NULL)
        {
            aggregate->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(aggregate_type));
            aggregate->raif_mngr()->add_err_descr
            (" aggregates a component with no link object");
            result = SE_FALSE;
        }
        else
        {
            result = TimeDataValue::check_time(
                link->GetIntObj(), time_data,
                select_params->time_branches.time_entry_count,
                select_params->time_branches.matching_rules,
                select_params->time_branches.time_entry_array,
                &select_params->general_hierarchy_mask );
        }
        break;

    case SE_CLS_DRM_UNION_OF_FEATURES:
    case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
    case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
        result = SE_TRUE;
        break;

    default:
        aggregate->raif_mngr()->add_err_descr
        ("hier_select_check(): Unexpected aggregate class ");
        aggregate->raif_mngr()->add_err_descr
        (SE_PrintDRMClass(aggregate_type));
        break;
    }
    return result;
}



//----------------------------------------------------------------------------
//       Some auxiliary functions used to evaluate a current path
//       through an aggregation object.
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// FUNCTION: compare_range
//
//   Determines if the link range of link_min to link_max satisfies the
//   matching rules to the range of parameter_min to parameter_max.
//----------------------------------------------------------------------------
static SE_Boolean
compare_range
(
    SE_Branch_Range_Matching matching_rules,
    SE_Long_Float                   link_min,
    SE_Long_Float                   link_max,
    SE_Long_Float                   parameter_min,
    SE_Long_Float                   parameter_max
)
{
    SE_Boolean result;

    switch (matching_rules)
    {
      case SE_BRRNGMAT_EXACT:
        result = (SE_Boolean)
                 (SE_EQUAL(link_min, parameter_min, F64_EPSILON) &&
                  SE_EQUAL(link_max, parameter_max, F64_EPSILON));
        break;

      case SE_BRRNGMAT_FULL_CONTAINMENT:
        result = (SE_Boolean)
                 ((SE_EQUAL(link_min, parameter_min, F64_EPSILON) ||
                   (link_min > parameter_min)) &&
                  (SE_EQUAL(link_max, parameter_max, F64_EPSILON) ||
                   (link_max < parameter_max)));
        break;

      case SE_BRRNGMAT_INTERSECTION:
        result = (SE_Boolean)
                         ((SE_EQUAL(link_min, parameter_min, F64_EPSILON)) ||
                  (SE_EQUAL(link_max, parameter_max, F64_EPSILON)) ||
                  (SE_EQUAL(link_min, parameter_max, F64_EPSILON)) ||
                  (SE_EQUAL(link_max, parameter_min, F64_EPSILON)) ||
                  (link_max > parameter_min && link_max < parameter_max) ||
                  (link_min > parameter_min && link_min < parameter_max));
        break;

        /*
        if (((link_max < parameter_min) ||
             (link_min > parameter_max)) &&
            ((!SE_EQUAL(link_min, parameter_min, F64_EPSILON)) &&
             (!SE_EQUAL(link_max, parameter_max, F64_EPSILON))))
          result = SE_FALSE;
        else
          result = SE_TRUE;
        break;
        */

      default:
      {
           fprintf(stderr,
                   "Unknown type of SE_Branch_Range_Matching %s",
                   SE_PrintBranchRangeMatching(matching_rules));
           result = SE_FALSE;
           break;
      }
    }
    return result;
} /* end compare_range */


//----------------------------------------------------------------------------
// FUNCTION: compare_state_range
//
//   Determines if the link range of link_min to link_max satisfies the
//   matching rules to the range of parameter_min to parameter_max.
//----------------------------------------------------------------------------
static SE_Boolean
compare_state_range
(
    SE_Branch_Range_Matching matching_rules,
    EDCS_Attribute_Value       link_min,
    EDCS_Attribute_Value       link_max,
    EDCS_Attribute_Value       parameter_min,
    EDCS_Attribute_Value       parameter_max
)
{
    SE_Boolean result;

    switch (matching_rules)
    {
      case SE_BRRNGMAT_EXACT:
        result =(SE_Boolean)
                ((EDCS_CompareAttributeValues(&link_min, &parameter_min)==0)&&
                (EDCS_CompareAttributeValues(&link_max, &parameter_max)==0));
        break;

      case SE_BRRNGMAT_FULL_CONTAINMENT:
        result = (SE_Boolean)
                 ((EDCS_CompareAttributeValues(&link_min, &parameter_min)>=0)
                  &&
                  (EDCS_CompareAttributeValues(&link_max, &parameter_max)<=0));
        break;

      case SE_BRRNGMAT_INTERSECTION:
        if (((EDCS_CompareAttributeValues(&link_max, &parameter_min)<0) ||
             (EDCS_CompareAttributeValues(&link_min, &parameter_max)>0)) &&
            ((EDCS_CompareAttributeValues(&link_min, &parameter_min)!=0) &&
             (EDCS_CompareAttributeValues(&link_max, &parameter_max)!=0))
           )
          result = SE_FALSE;
        else
          result = SE_TRUE;
        break;

      default:
      {
        fprintf(stderr,
                "Unknown type of SE_Branch_Range_Matching %s",
                SE_PrintBranchRangeMatching(matching_rules));
        result = SE_FALSE;
        break;
        }
    }
    return result;
} /* end compare_state_range */


//----------------------------------------------------------------------------
//
// FUNCTION: check_alternate
//
//   Determines if the component whose link field is link satisfies the
//   alternate feature select rules.
//
//----------------------------------------------------------------------------
static SE_Boolean
check_alternate
(
    SE_InternalObject        *link,
    SE_Integer_Unsigned       hierarchy_count,
    SE_Hierarchy_Data_Fields  hierarchy_data[]
)
{
    SE_Boolean           result = SE_FALSE;
    SE_FIELDS_PTR        fields= link->OrigFields();
    SE_Integer_Unsigned  i;

    // Check if the reason for alternate representation from our link
    // field matches any of the reasons in the select parameters.
    for (i=0; (result == SE_FALSE) && (i < hierarchy_count); i++)
    {
        if (SE_CompareStrings(&fields->u.Hierarchy_Data.
            alternate_representation_reason,
            &hierarchy_data[i].alternate_representation_reason) == 0)
        {
            result = SE_TRUE;
        }
    }
    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: check_classification
//
//   Determines if the component whose link field is link satisfies the
//   classification select rules.
//
//----------------------------------------------------------------------------
static SE_Boolean
check_classification
(
    SE_InternalObject       *link,
    SE_Integer_Unsigned      classification_count,
    SE_Classification_Entry  classification_array[]
)
{
    SE_Boolean          result = SE_FALSE;
    SE_FIELDS_PTR       fields = link->OrigFields();
    SE_Integer_Unsigned i;

    //
    // Check if the classification code from the link field
    // matches any of the class codes in the select parameters.
    //
    for (i=0; (result == SE_FALSE) && (i < classification_count); i++)
    {
        if( fields->u.Classification_Data.tag ==
                      classification_array[i].class_data.tag )
        {
            //
            // OK, we have a matching <Classification Data>. If the
            // SE_Classification_Entry has <Property Values>, we must
            // check that this link object's components match.
            //
            if (classification_array[i].prop_val_count > 0)
            {
                // The user has specified a qualified classification, so
                // verify that this <Classification Data> is a match.
                //
                SE_Status_Code status        = SE_STATCODE_SUCCESS;
                SE_Boolean     found_curr_pv = SE_FALSE,
                               found_all_pv  = SE_TRUE;

               /*
                * Loop through all the <Property Value> components,
                * testing the against the array, until either
                * 1) a component occurs that can't be tested
                * 2) a component occurs that matches nothing
                * 3) runs out of components
                */
                for (SE_Integer_Unsigned j = 0;
                     OBJSTATUS_VALID(status) && (found_all_pv == SE_FALSE);
                     j++)
                {
                    SE_InternalObject *prop_val_ext = NULL;

                    status = link->GetNthObjectOfDRMClass
                                   (j, REF_REL_COMPONENT,
                                    SE_CLS_DRM_PROPERTY_VALUE,
                                    &prop_val_ext);

                    if (OBJSTATUS_VALID(status))
                    {
                        found_curr_pv = SE_FALSE;

                        for (SE_Integer_Unsigned k = 0;
                             k < classification_array[i].prop_val_count &&
                             (found_all_pv == SE_TRUE) &&
                             (found_curr_pv == SE_FALSE);
                             k++)
                        {
                            SE_FIELDS_PTR prop_val_fields =
                                          prop_val_ext->OrigFields();

                            if (SE_ComparePropertyCodes(
                                 &prop_val_fields->u.Property_Value.meaning,
                                 &classification_array[k].prop_val_array[j].
                                  meaning ) == 0)
                            {
                                if (EDCS_CompareAttributeValues(
                                   &prop_val_fields->u.Property_Value.value,
                                   &classification_array[k].
                                       prop_val_array[j].value) == 0)
                                {
                                    found_curr_pv = SE_TRUE;
                                }
                                else
                                {
                                   /*
                                    * Since classification_array passed
                                    * the validity check, no other entry
                                    * in the array can possibly match
                                    * this component
                                    */
                                    found_all_pv = SE_FALSE;
                                }
                            }
                        }
                    }
                    else if ((status != SE_STATCODE_NO_OBJECT) ||
                             (j != classification_array[i].prop_val_count))
                    {
                       /*
                        * If we hit a <Property Value> we couldn't test,
                        * or if the number of <Property Values> doesn't
                        * match that specified by the array, reject
                        */
                        found_all_pv = SE_FALSE;
                    }
                    SAFE_RELEASE(prop_val_ext);
                } /* end for each <Property Value> component */
            }
            else
                result = SE_TRUE;
        }
    }
    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: check_lod
//
//   Determines if the component whose link field is link satisfies the
//   LOD select rules.
//
//----------------------------------------------------------------------------
static SE_Boolean
check_lod
(
    SE_InternalObject            *link,
    SE_Integer_Unsigned           lod_count,
    SE_Branch_Range_Matching      matching_rules,
    SE_LOD_Entry                  lod_entries[],
    SE_General_Hierarchy_Select  *select
)
{
    SE_Boolean         result = SE_FALSE;
    //SE_InternalObject *component;
    SE_Boolean         type_match_found = SE_FALSE;
    SE_DRM_Class       type;
    SE_Integer_Unsigned j;
    SE_FIELDS_PTR fields = link->OrigFields();

    type = link->tag();

    switch(type)
    {
        case SE_CLS_DRM_DISTANCE_LOD_DATA:
             // For distance LODs, check to see if the distance LOD's range
             // satisfies the range matching rules.
             if (select->lod_distance_related == SE_HIERINC_INCLUDE_ALL)
                 return SE_TRUE;
             else if (select->lod_distance_related == SE_HIERINC_EXCLUDE_ALL)
                 return SE_FALSE;
             else
             {
                 SE_Long_Float fieldMin, fieldMax, entriesMin, entriesMax;

                 for (j=0; (j < lod_count) && (result == SE_FALSE); j++)
                 {
                     if (lod_entries[j].lod_entry_type == SE_LODDATTYP_DISTANCE)
                     {
                         type_match_found = SE_TRUE;

                         fieldMin = fields->u.Distance_LOD_Data.minimum_range;
                         fieldMax = fields->u.Distance_LOD_Data.maximum_range;
                         entriesMin = lod_entries[j].lod.distance.minimum_range;
                         entriesMax = lod_entries[j].lod.distance.maximum_range;

                         if (compare_range(matching_rules, fieldMin, fieldMax,
                             entriesMin, entriesMax) == SE_TRUE)
                         result = SE_TRUE;
                     } // end if
                 } // end for j
             }
             break;

        case SE_CLS_DRM_INDEX_LOD_DATA:
             // For <Index LOD Data>, check if the link fields
             // index matches any of the indices in the select parameters.
             if (select->lod_index_related == SE_HIERINC_INCLUDE_ALL)
                 return SE_TRUE;
             else if (select->lod_index_related == SE_HIERINC_EXCLUDE_ALL)
                 return SE_FALSE;

             for (j=0; (j < lod_count) && (result == SE_FALSE); j++)
             {
                 if (lod_entries[j].lod_entry_type == SE_LODDATTYP_INDEX)
                 {
                     type_match_found = SE_TRUE;

                     if (fields->u.Index_LOD_Data.index ==
                         lod_entries[j].lod.index.index)
                     {
                         result = SE_TRUE;
                     }
                 }
             } // end for j
             break;

        case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
             // For map scale LOD, see if the link fields map scale
             // matches any of the map scales in the select parameters.
             if (select->lod_map_scale_related == SE_HIERINC_INCLUDE_ALL)
                 return SE_TRUE;
             if (select->lod_map_scale_related == SE_HIERINC_EXCLUDE_ALL)
                 return SE_FALSE;

             for (j=0; (j < lod_count) && (result == SE_FALSE); j++)
             {
                 if (lod_entries[j].lod_entry_type ==  SE_LODDATTYP_MAP_SCALE)
                 {
                     type_match_found = SE_TRUE;

                     if (fields->u.Map_Scale_LOD_Data.map_scale
                     == lod_entries[j].lod.map_scale.map_scale)
                       result = SE_TRUE;
                 }
             } // end for j
             break;

        case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
             //
             // For spatial resolution LOD, see if the link fields' spatial
             // resolution matches any of the spatial resolutions in the select
             // parameters.
             //
             if (select->lod_spatial_resolution_related ==
                 SE_HIERINC_INCLUDE_ALL)
                 return SE_TRUE;
             if (select->lod_spatial_resolution_related ==
                 SE_HIERINC_EXCLUDE_ALL)
                 return SE_FALSE;

             for (j=0; (j < lod_count) && (result == SE_FALSE); j++)
             {
                 if (lod_entries[j].lod_entry_type ==
                     SE_LODDATTYP_SPATIAL_RESOLUTION)
                 {
                     type_match_found = SE_TRUE;

                     if ((fields->u.Spatial_Resolution_LOD_Data.unit ==
                         lod_entries[j].lod.spatial_resolution.unit) &&
                         (fields->u.Spatial_Resolution_LOD_Data.spatial_resolution ==
                          lod_entries[j].lod.spatial_resolution.spatial_resolution))
                     {
                         result = SE_TRUE;
                     }
                 }
             } // end for j
             break;

        case SE_CLS_DRM_VOLUME_LOD_DATA:
             if (select->lod_volume_related==SE_HIERINC_INCLUDE_ALL)
                 return SE_TRUE;
             if (select->lod_volume_related==SE_HIERINC_EXCLUDE_ALL)
                 return SE_FALSE;

             link->raif_mngr()->add_err_descr("Hierarchy Selection based on volume Level of Details is not "\
              "currently handled  - processing all volume LODs");
             return SE_TRUE;

/******************** $$$ Volume LODS are not completed
         SE_FIELDS_PTR fields = component->OrigFields();

         for (j=0; (j < lod_count) && !result; j++)
         if (lod_entries[j].type_of_lod_entry == SE_LODDATTYP_VOLUME)
         {
         type_match_found = SE_TRUE;

         // $$$ TO BE DONE:

         // Check if the two volumes overlap:
         // fields->u.Volume_Level_Of_Detail_Data.volume
         // lod_entries[j].u.volume_lod.volume

         // $$$ TEMP FOR NOW
         result = SE_TRUE;
         }
         break;

**********************************************/

        default:
        {
             link->raif_mngr()->add_err_descr
             ("Obtained a LOD data of unknown type: ");
             link->raif_mngr()->add_err_descr
             (SE_PrintDRMClass(type));
             return SE_FALSE;
        }
    }

    if (type_match_found == SE_FALSE)
        result = SE_TRUE;

    return result;
}


//----------------------------------------------------------------------------
// FUNCTION: check_continuous_lod
//----------------------------------------------------------------------------
static SE_Boolean
check_continuous_lod
(
    SE_InternalObject          *aggregate_object,
    SE_InternalObject          *component_object,
    SE_Continuous_LOD_Select_Choice  select
)
{
    SE_Boolean result = SE_FALSE;

    if (select == SE_CLOD_ALL)
        result = SE_TRUE;
    else
    {
        SE_DRM_Class component_type = component_object->tag();

        if (select == SE_CLOD_LEAST_DETAILED)
        {
            if (component_type == SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY)
                result = SE_TRUE;
        }
        else if (select == SE_CLOD_MOST_DETAILED)
        {
            SE_Boolean tnode;
            SE_FIELDS_PTR fields_ptr = aggregate_object->OrigFields();

            tnode = fields_ptr->u.
              Continuous_LOD_Related_Geometry.terminating_node;

            if (tnode &&
                (component_type == SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY))
              result = SE_TRUE;
            else if (!tnode &&
                     (component_type != SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY))
              result = SE_TRUE;
        }
    }

    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: check_octant
//
//----------------------------------------------------------------------------
static SE_Boolean
check_octant
(
    SE_InternalObject       *link,
    SE_Integer_Unsigned                octant_count,
    SE_Octant_Data_Fields octant_data[]
)
{
    SE_Boolean    result = SE_FALSE;
    SE_FIELDS_PTR fields = link->OrigFields();

    for (SE_Integer_Unsigned i=0; (i < octant_count) && (result == SE_FALSE); i++)
        if (fields->u.Octant_Data.octant == octant_data[i].octant)
            result = SE_TRUE;

    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: check_quadrant
//
//----------------------------------------------------------------------------
static SE_Boolean
check_quadrant
(
    SE_InternalObject        *link,
    SE_Integer_Unsigned       quadrant_count,
    SE_Quadrant_Data_Fields  quadrant_data[]
)
{
    SE_Boolean    result = SE_FALSE;
    SE_FIELDS_PTR fields = link->OrigFields();

    for (SE_Integer_Unsigned i=0; (i < quadrant_count) && (result == SE_FALSE); i++)
        if (fields->u.Quadrant_Data.quadrant==quadrant_data[i].quadrant)
            result = SE_TRUE;

    return result;
}


//----------------------------------------------------------------------------
// FUNCTION: check_separating_planes
//
//   Determines if the component whose link field is link satisfies the
//   selection parameters specified by the traversal rules.
//----------------------------------------------------------------------------
static SE_Boolean
check_separating_planes
(
    SE_InternalObject  *link,
    SE_Boolean          traverse_positive_branches,
    SE_Boolean          traverse_negative_branches
)
{
    SE_FIELDS_PTR fields = link->OrigFields();
    SE_Boolean        result;

    result = (SE_Boolean)
             ((traverse_positive_branches &&
               fields->u.Separating_Plane_Data.positive) ||
              (traverse_negative_branches &&
               !fields->u.Separating_Plane_Data.positive));

    return result;
}


//----------------------------------------------------------------------------
// FUNCTION: check_spatial_index
//
//   Determines if the component whose link field is link satisfies the
//   spatial index selection rules.
//----------------------------------------------------------------------------
static SE_Boolean
check_spatial_index
(
    SE_InternalObject                *link,
    SE_Integer_Unsigned                         spatial_index_count,
    SE_Spatial_Index_Data_Fields   spatial_index_data[]
)
{
    SE_Boolean    result = SE_FALSE;
    SE_FIELDS_PTR fields = link->OrigFields();
    SE_Integer_Unsigned     i;

    // Check if link's row and column index matches any of the indices
    // in the spatial index selection rules.
    for (i = 0; (result == SE_FALSE) && (i < spatial_index_count); i++)
    {
        if ((fields->u.Spatial_Index_Data.row_index ==
            spatial_index_data[i].row_index) &&
            (fields->u.Spatial_Index_Data.column_index ==
             spatial_index_data[i].column_index))
            result = SE_TRUE;
    }
    return result;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
static SE_Boolean
check_state
(
    SE_InternalObject              *stateRelated,
    SE_Context                     *context,
    SE_InternalObject              *link,
    SE_Unmatched_State_Behaviour    default_choice,
    SE_Branch_Range_Matching        matching_rules,
    SE_Integer_Unsigned                       state_entry_count,
    SE_State_Entry                  state_entry_array[]
)
{
//     SE_Boolean    result = SE_FALSE;
    SE_FIELDS_PTR fields      = stateRelated->OrigFields();
    SE_FIELDS_PTR link_fields = link->OrigFields();

    link->raif_mngr()->add_err_descr("Hierarchy Selection based on States is not "\
         "currently handled  - processing all state related ");
    return SE_TRUE;

/********  FIX THIS $$$$$$ -JC  ********************

    if (stateRelated->tag() == SE_CLS_DRM_STATE_RELATED_GEOMETRY)
        state_tag = &fields->u.State_Related_Geometry.state_tag;
    else
        state_tag = &fields->u.State_Related_Features.state_tag;

    for (SE_Integer_Unsigned i=0; (i < state_entry_count) &&
        (result == SE_FALSE); i++ )
    {
        if( state_tag == state_entry_array[i].state_tag )
        {
            // We've matched the tag.  See if it passes the range test.
            match = SE_TRUE;

            result = compare_state_range( matching_rules,
                         link_state_min, link_state_max,
                         state_entry_array[i].state_data.state_value_min,
                         state_entry_array[i].state_data.state_value_max );
        }
    }

    if (match == SE_FALSE) // Enter default processing
    {
        EDCS_Attribute_Value active_state_value;

        switch (default_choice)
        {
          case SE_UNMSTATBEH_ALL:
            result = SE_TRUE;
            break;

          case SE_UNMSTATBEH_NONE:
            result = SE_FALSE;
            break;

          case SE_UNMSTATBEH_DEFAULT:
            // Get the fields of the State Related Feature/Geometry,
            // evaluating it under this context.  We don't care for
            // any SRF change or color model change.
            //
            fields = stateRelated->OrigFields();

            // Find out the active state value for the StateRelated
            // Feature/Geometry
            //
            if (fields->tag == SE_CLS_DRM_STATE_RELATED_GEOMETRY)
                active_state_value =
                  fields->u.State_Related_Geometry.active_state_value;
            else
                active_state_value =
                  fields->u.State_Related_Features.active_state_value;

            // Go down the path if active_state_value is in
            // [link_state_min, link_state_max)
            {
                if ((EDCS_CompareAttributeValues(&link_state_min,
                     &active_state_value) <= 0) &&
                    (EDCS_CompareAttributeValues(&active_state_value,
                     &link_state_max) < 0) )
                {
                     result = SE_TRUE;
                }
            }
            break;

          default:
            stateRelated->raif_mngr()->add_err_descr
            ("se_hier_select::check_state: rejecting state branch, "\
             "unknown SE_Unmatched_State_Behaviour ");
            stateRelated->raif_mngr()->add_err_descr
            (SE_PrintUnmatchedStateBehaviour(default_choice));
            result = SE_FALSE;
            break;
        }
    }
    return result;

    *******************/
}


//----------------------------------------------------------------------------
// FUNCTION: check_animation
//
//   Determines if the component (indexed by which in the ordered component
//   list) is within the set of acceptable ranges in the select rules.
//----------------------------------------------------------------------------
static SE_Boolean
check_animation
(
    SE_Integer_Unsigned           which,
    SE_Integer_Unsigned           ranges_count,
    SE_Animation_Range  animation_ranges[])
{
    for (SE_Integer_Unsigned i=0; i < ranges_count; i++)
    {
        if ((animation_ranges[i].beginning_frame <= which) &&
            (animation_ranges[i].ending_frame >= which))
            return SE_TRUE;
    }
    return SE_FALSE;
} /* end check_animation */
