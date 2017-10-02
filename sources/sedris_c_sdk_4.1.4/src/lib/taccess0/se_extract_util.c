/*
 * FILE       : se_extract_util.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *   These functions are intended for use by any application.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 * - API spec. 4.1
 */

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

#include <stdlib.h> /* for free()   */
#include <string.h> /* for memcpy() */
#include "se_read0.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_BitsPerTexel
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_BitsPerTexel
(
    const SE_Image_Fields     *image_fields_ptr,
          SE_Integer_Unsigned *result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!image_fields_ptr || !result_out_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        switch (image_fields_ptr->image_signature)
        {
            case SE_IMAGSIG_ALPHA:
                 *result_out_ptr = image_fields_ptr->bits_of_alpha;
                 break;

            case SE_IMAGSIG_LUMINANCE:
                 *result_out_ptr = image_fields_ptr->bits_of_luminance;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_1:
                 *result_out_ptr =
                     image_fields_ptr->bits_of_colour_coordinate_1;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_2:
                 *result_out_ptr =
                     image_fields_ptr->bits_of_colour_coordinate_2;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_3:
                 *result_out_ptr =
                     image_fields_ptr->bits_of_colour_coordinate_3;
                 break;

            case SE_IMAGSIG_BUMP_MAP_HEIGHT:
                 *result_out_ptr = image_fields_ptr->bits_of_bump_map_height;
                 break;

            case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
                 *result_out_ptr = sizeof(EDCS_Classification_Code);
                 break;

            case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                 *result_out_ptr = image_fields_ptr->bits_of_luminance +
                                   image_fields_ptr->bits_of_alpha;
                 break;

            case SE_IMAGSIG_123COLOUR:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_colour_coordinate_1 +
                      image_fields_ptr->bits_of_colour_coordinate_2 +
                      image_fields_ptr->bits_of_colour_coordinate_3);
                 break;

            case SE_IMAGSIG_123COLOUR_ALPHA:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_colour_coordinate_1 +
                      image_fields_ptr->bits_of_colour_coordinate_2 +
                      image_fields_ptr->bits_of_colour_coordinate_3 +
                      image_fields_ptr->bits_of_alpha);
                 break;

            case SE_IMAGSIG_ONE_MATERIAL:
                 *result_out_ptr = image_fields_ptr->bits_of_material_1;
                 break;

            case SE_IMAGSIG_TWO_MATERIALS:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_material_1 +
                      image_fields_ptr->bits_of_material_2 +
                      image_fields_ptr->bits_of_material_2_percentage);
                 break;

            case SE_IMAGSIG_THREE_MATERIALS:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_material_1 +
                      image_fields_ptr->bits_of_material_2 +
                      image_fields_ptr->bits_of_material_3 +
                      image_fields_ptr->bits_of_material_2_percentage +
                      image_fields_ptr->bits_of_material_3_percentage);
                 break;

            case SE_IMAGSIG_IMAGE_INDEX:
                 *result_out_ptr = image_fields_ptr->bits_of_image_index;
                 break;

            case SE_IMAGSIG_BUMP_MAP_UV:
                 *result_out_ptr = (image_fields_ptr->bits_of_bump_map_u +
                                    image_fields_ptr->bits_of_bump_map_v);
                 break;

            default:
                 *result_out_ptr = 0;
                 status          = SE_STATCODE_INACTIONABLE_FAILURE;
                 break;
        }
    }
    return status;
} /* end BitsPerTexel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CellCountForSubExtent
 *
 *-----------------------------------------------------------------------------
 */
SE_Integer_Unsigned
SE_CellCountForSubExtent
(
    const SE_Data_Table_Sub_Extent *extents_ptr
)
{
    SE_Integer_Unsigned i = 0, num = 1;

    if (SE_ValidDataTableSubExtent(extents_ptr, SE_FALSE, NULL))
    {
        for (i = 0; i < extents_ptr->axes_count; i++)
        {
            num *= (extents_ptr->axes_bounds[i].last_index -
                    extents_ptr->axes_bounds[i].first_index + 1);
        }
    }
    else
    {
        num = 0;
    }
    return num;
} /* end SE_CellCountForSubExtent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneAlternateHierarchyParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneAlternateHierarchyParameters
(
    const SE_Alternate_Hierarchy_Parameters *src_ptr,
          SE_Alternate_Hierarchy_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        dest_ptr->hierarchy_data_count = 0;
        dest_ptr->hierarchy_data_array = NULL;

        if ((src_ptr->hierarchy_data_count > 0) &&
            (src_ptr->hierarchy_data_array == NULL))
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if ((dest_ptr->hierarchy_data_array =
                 (SE_Hierarchy_Data_Fields *)
                 calloc(sizeof(SE_Hierarchy_Data_Fields),
                 src_ptr->hierarchy_data_count))==NULL)
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
            dest_ptr->hierarchy_data_count = 0;
        }
        else
        {
            SE_Integer_Unsigned i = 0;

            dest_ptr->hierarchy_data_count = src_ptr->hierarchy_data_count;
            while ((status == SE_STATCODE_SUCCESS) &&
                   (i < src_ptr->hierarchy_data_count))
            {
                SE_DRM_Status_Code field_status;

                field_status = SE_CloneString
                               (
                                   &(src_ptr->hierarchy_data_array[i].
                                     alternate_representation_reason),
                                   &(dest_ptr->hierarchy_data_array[i].
                                     alternate_representation_reason)
                               );
                if (field_status == SE_DRM_STAT_CODE_SUCCESS)
                {
                    i++;
                }
                else
                {
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
            }

            if (status != SE_STATCODE_SUCCESS)
            {
                while (i > 0)
                {
                    i--;
                    SE_FreeString
                    (
                        &(dest_ptr->hierarchy_data_array[i].
                        alternate_representation_reason),
                        NULL
                    );
                }
                free(dest_ptr->hierarchy_data_array);
                dest_ptr->hierarchy_data_count = 0;
                dest_ptr->hierarchy_data_array = NULL;
            }
        }
    }
    return status;
} /* end SE_CloneAlternateHierarchyParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneAnimationSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneAnimationSelectParameters
(
    const SE_Animation_Select_Parameters *src_ptr,
          SE_Animation_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        dest_ptr->ranges_count           = 0;
        dest_ptr->animation_ranges_array = NULL;

        if ((src_ptr->ranges_count != 0) &&
            (src_ptr->animation_ranges_array == NULL))
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if ((dest_ptr->animation_ranges_array = (SE_Animation_Range *)
                 calloc(sizeof(SE_Animation_Range),
                 src_ptr->ranges_count))==NULL)
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
            dest_ptr->ranges_count = 0;
        }
        else
        {
            dest_ptr->ranges_count = src_ptr->ranges_count;
            memcpy(dest_ptr->animation_ranges_array,
                   src_ptr->animation_ranges_array,
                   sizeof(SE_Animation_Range)*src_ptr->ranges_count);
        }
    }
    return status;
} /* end SE_CloneAnimationSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneClassificationEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneClassificationEntry
(
    const SE_Classification_Entry *src_ptr,
          SE_Classification_Entry *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_DRM_Class_Fields temp_fields_in, temp_fields_out;
    SE_Integer_Unsigned i, j;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        memcpy(&(dest_ptr->class_data), &(src_ptr->class_data),
               sizeof(SE_Classification_Data_Fields));
        dest_ptr->prop_val_count = src_ptr->prop_val_count;

        for (i = 0; i < src_ptr->prop_val_count; i++)
        {
            temp_fields_in.tag = SE_CLS_DRM_PROPERTY_VALUE;
            memcpy(&(temp_fields_in.u.Property_Value),
                   &(src_ptr->prop_val_array[i]),
                   sizeof(SE_Property_Value_Fields));

            if (SE_CloneFields(&temp_fields_in, &temp_fields_out)
                != SE_DRM_STAT_CODE_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                dest_ptr->class_data = SE_CLASSIFICATION_DATA_FIELDS_DEFAULT;
                for (j = 0; j <= i; j++)
                {
                    temp_fields_out.tag = SE_CLS_DRM_PROPERTY_VALUE;
                    memcpy(&(temp_fields_out.u.Property_Value),
                           &(dest_ptr->prop_val_array[j]),
                           sizeof(SE_Property_Value_Fields));
                    SE_FreeFields(&temp_fields_out, NULL);
                }
                SE_FreeFields(&temp_fields_in, NULL);
                free(dest_ptr->prop_val_array);
                dest_ptr->prop_val_count = 0;
                dest_ptr->prop_val_array = NULL;
                return status;
            }
            else
            {
                memcpy(&(dest_ptr->prop_val_array[i]),
                       &(temp_fields_out.u.Property_Value),
                       sizeof(SE_Property_Value_Fields));
            }
        } /* end for i loop */
    }
    return status;
} /* end SE_CloneClassificationEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneClassificationParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneClassificationParameters
(
    const SE_Classification_Parameters *src_ptr,
          SE_Classification_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->classification_count == 0) ||
             (src_ptr->classification_array == NULL))
    {
        dest_ptr->classification_count = 0;
        dest_ptr->classification_array = NULL;

       /*
        * Cannot clone array without array size
        */
        if (src_ptr->classification_array != NULL)
            status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((dest_ptr->classification_array = (SE_Classification_Entry *)
             calloc(sizeof(SE_Classification_Entry),
                    src_ptr->classification_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->classification_count = 0;
    }
    else
    {
        SE_Integer_Unsigned i = 0;

        dest_ptr->classification_count = src_ptr->classification_count;
        while ((status == SE_STATCODE_SUCCESS) &&
               (i < src_ptr->classification_count))
        {
            status = SE_CloneClassificationEntry
                     (
                         &(src_ptr->classification_array[i]),
                         &(dest_ptr->classification_array[i])
                     );
            if (status == SE_STATCODE_SUCCESS)
                i++;
        }
        if (status != SE_STATCODE_SUCCESS)
        {
            while (i > 0)
            {
                i--;
                SE_FreeClassificationEntry
                (
                   &(dest_ptr->classification_array[i]),
                    NULL
                );
            }
            dest_ptr->classification_count = 0;
            dest_ptr->classification_array = NULL;
        }
    }
    return status;
} /* end SE_CloneClassificationParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeHierarchyOrderParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_InitializeHierarchyOrderParameters
(
    SE_Hierarchy_Order_Parameters *params_ptr
)
{
    if (!params_ptr)
        return SE_STATCODE_INACTIONABLE_FAILURE;

   /*
    * initialize alternate_hierarchy_traversal_order
    */
    params_ptr->general_hierarchy_mask.set = 0;
    params_ptr->alternate_hierarchy_traversal_order.hierarchy_data_count = 0;
    params_ptr->alternate_hierarchy_traversal_order.hierarchy_data_array = NULL;

   /*
    * initialize classification_traversal_order
    */
    params_ptr->classification_traversal_order.classification_count = 0;
    params_ptr->classification_traversal_order.classification_array = NULL;

   /*
    * initialize lod_traversal_order
    */
    params_ptr->lod_traversal_order = SE_SIBTRAV_UNSPECIFIED;

   /*
    * initialize octant_traversal_order
    */
    params_ptr->octant_traversal_order = SE_SIBTRAV_UNSPECIFIED;

   /*
    * initialize quadrant_traversal_order
    */
    params_ptr->quadrant_traversal_order = SE_SIBTRAV_UNSPECIFIED;

   /*
    * initialize separating_plane_traversal_order
    */
    params_ptr->separating_plane_traversal_order = SE_SIBTRAV_UNSPECIFIED;

   /*
    * initialize spatial_index_general_traversal_order
    */
    params_ptr->spatial_index_general_traversal_order =
       SE_SIBTRAV_UNSPECIFIED;

   /*
    * initialize state_traversal_order
    */
    params_ptr->state_traversal_order.state_value =
       EDCS_ATTRIBUTE_VALUE_DEFAULT;

   /*
    * initialize time_branches
    */
    params_ptr->time_traversal_order = SE_SIBTRAV_UNSPECIFIED;

    return SE_STATCODE_SUCCESS;
} /* end SE_InitializeHierarchyOrderParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneHierarchyOrderParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneHierarchyOrderParameters
(
    const SE_Hierarchy_Order_Parameters *src_ptr,
          SE_Hierarchy_Order_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!SE_ValidHierarchyOrderParameters(src_ptr, SE_FALSE, NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_InitializeHierarchyOrderParameters(dest_ptr) !=
             SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (src_ptr->general_hierarchy_mask.member.Alternate_Hierarchy &&
             SE_CloneAlternateHierarchyParameters
             (&(src_ptr->alternate_hierarchy_traversal_order),
              &(dest_ptr->alternate_hierarchy_traversal_order)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else if (src_ptr->general_hierarchy_mask.member.Classification_Related &&
             SE_CloneClassificationParameters
                (&(src_ptr->classification_traversal_order),
                &(dest_ptr->classification_traversal_order)) !=
             SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.member.Alternate_Hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
            (
               &(dest_ptr->alternate_hierarchy_traversal_order),
                NULL
            );
        }
    }
    else
    {
        if (src_ptr->general_hierarchy_mask.member.State_Related == SE_TRUE)
        {
            SE_DRM_Class_Fields temp_fields_in, temp_fields_out;

            temp_fields_in.tag = SE_CLS_DRM_STATE_DATA;
            memcpy(&(temp_fields_in.u.State_Data), &(src_ptr->state_traversal_order),
                   sizeof(SE_State_Data_Fields));

            if (SE_CloneFields(&temp_fields_in, &temp_fields_out)
                != SE_DRM_STAT_CODE_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                dest_ptr->state_traversal_order = SE_STATE_DATA_FIELDS_DEFAULT;

                if (src_ptr->general_hierarchy_mask.member.Alternate_Hierarchy)
                {
                    SE_FreeAlternateHierarchyParameters
                    (
                       &(dest_ptr->alternate_hierarchy_traversal_order),
                        NULL
                    );
                }
                if (src_ptr->general_hierarchy_mask.member.Classification_Related)
                {
                    SE_FreeClassificationParameters
                    (
                       &(dest_ptr->classification_traversal_order),
                        NULL
                    );
                }
                status = SE_STATCODE_OUT_OF_MEMORY;
            }
            else
            {
                memcpy(&(dest_ptr->state_traversal_order),
                       &(temp_fields_out.u.State_Data),
                       sizeof(SE_State_Data_Fields));
            }
        }

        if (status == SE_STATCODE_SUCCESS)
        {
            memcpy(&(dest_ptr->general_hierarchy_mask),
                   &(src_ptr->general_hierarchy_mask),
                   sizeof(SE_General_Hierarchy_Order));

            dest_ptr->lod_traversal_order = src_ptr->lod_traversal_order;
            dest_ptr->octant_traversal_order =
                src_ptr->octant_traversal_order;
            dest_ptr->quadrant_traversal_order =
                src_ptr->quadrant_traversal_order;
            dest_ptr->separating_plane_traversal_order =
                src_ptr->separating_plane_traversal_order;
            dest_ptr->time_traversal_order = src_ptr->time_traversal_order;

            dest_ptr->spatial_index_general_traversal_order =
                 src_ptr->spatial_index_general_traversal_order;
        }
    }
    return status;
} /* end SE_CloneHierarchyOrderParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeHierarchySelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_InitializeHierarchySelectParameters
(
    SE_Hierarchy_Select_Parameters *params_ptr
)
{
    if (!params_ptr)
        return SE_STATCODE_INACTIONABLE_FAILURE;

   /*
    * initialize alternate_hierarchy_branches
    */
    params_ptr->general_hierarchy_mask.alternate_hierarchy =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->alternate_hierarchy_branches.hierarchy_data_count = 0;
    params_ptr->alternate_hierarchy_branches.hierarchy_data_array = NULL;

   /*
    * initialize animation_branches
    */
    params_ptr->general_hierarchy_mask.animation_related =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->animation_branches.ranges_count           = 0;
    params_ptr->animation_branches.animation_ranges_array = NULL;

   /*
    * initialize classification_branches
    */
    params_ptr->general_hierarchy_mask.classification_related =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->classification_branches.classification_count = 0;
    params_ptr->classification_branches.classification_array = NULL;

   /*
    * initialize continuous_lod_branches
    */
    params_ptr->general_hierarchy_mask.continuous_lod_related =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->continuous_lod_branches.clod_choice = SE_CLOD_ALL;

   /*
    * initialize lod_branches
    */
    params_ptr->general_hierarchy_mask.lod_related =
                SE_FALSE;
    params_ptr->general_hierarchy_mask.lod_distance_related =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.lod_index_related =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.lod_map_scale_related =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.lod_volume_related =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.lod_spatial_resolution_related  =
                 SE_HIERINC_EXCLUDE_ALL;
    params_ptr->lod_branches.matching_rules  =
                SE_BRRNGMAT_INTERSECTION;
    params_ptr->lod_branches.lod_entry_count = 0;
    params_ptr->lod_branches.lod_entry_array = NULL;

   /*
    * initialize octant_branches
    */
    params_ptr->general_hierarchy_mask.octant_related =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->octant_branches.octant_data_count   = 0;
    params_ptr->octant_branches.octant_data_array   = NULL;

   /*
    * There are no perimeter-related selection parameters
    */
    params_ptr->general_hierarchy_mask.perimeter_related = SE_FALSE;

   /*
    * initialize quadrant_branches
    */
    params_ptr->general_hierarchy_mask.quadrant_related =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->quadrant_branches.quadrant_data_count   = 0;
    params_ptr->quadrant_branches.quadrant_data_array   = NULL;

   /*
    * initialize separating_plane_branches
    */
    params_ptr->general_hierarchy_mask.separating_plane =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->separating_plane_branches.traverse_positive_branches = SE_FALSE;
    params_ptr->separating_plane_branches.traverse_negative_branches = SE_FALSE;

   /*
    * initialize spatial_index_branches
    */
    params_ptr->general_hierarchy_mask.spatial_index_related =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->spatial_index_branches.spatial_index_data_count = 0;
    params_ptr->spatial_index_branches.spatial_index_data_array = NULL;

   /*
    * initialize state_branches
    */
    params_ptr->general_hierarchy_mask.state_related =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->state_branches.default_choice = SE_UNMSTATBEH_DEFAULT;
    params_ptr->state_branches.matching_rules =
                SE_BRRNGMAT_INTERSECTION;
    params_ptr->state_branches.state_entry_count = 0;
    params_ptr->state_branches.state_entry_array = NULL;

   /*
    * initialize time_branches
    */
    params_ptr->general_hierarchy_mask.time_related = SE_FALSE;
    params_ptr->general_hierarchy_mask.time_related_by_season =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.time_related_by_time_interval =
       SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.time_related_by_time_of_day =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->general_hierarchy_mask.time_related_by_time_point =
                SE_HIERINC_EXCLUDE_ALL;
    params_ptr->time_branches.matching_rules =
                SE_BRRNGMAT_INTERSECTION;
    params_ptr->time_branches.time_entry_count = 0;
    params_ptr->time_branches.time_entry_array = NULL;

   /*
    * There are no selection parameters for <Union of Features>,
    * <Union of Geometry Hierarchy>, or <Union of Primitive Geometry>
    */
    params_ptr->general_hierarchy_mask.union_of_features = SE_FALSE;
    params_ptr->general_hierarchy_mask.union_of_geometry_hierarchies =
                SE_FALSE;
    params_ptr->general_hierarchy_mask.union_of_geometry_primitives =
                SE_FALSE;

    return SE_STATCODE_SUCCESS;
} /* end SE_InitializeHierarchySelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneHierarchySelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneHierarchySelectParameters
(
    const SE_Hierarchy_Select_Parameters *src_ptr,
          SE_Hierarchy_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!SE_ValidHierarchySelectParameters(src_ptr, SE_FALSE, NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_InitializeHierarchySelectParameters(dest_ptr) !=
             SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (src_ptr->general_hierarchy_mask.alternate_hierarchy ==
             SE_HIERINC_EVALUATE_RULES &&
             SE_CloneAlternateHierarchyParameters
            (&(src_ptr->alternate_hierarchy_branches),
             &(dest_ptr->alternate_hierarchy_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else if (src_ptr->general_hierarchy_mask.animation_related ==
             SE_HIERINC_EVALUATE_RULES &&
             SE_CloneAnimationSelectParameters(&(src_ptr->animation_branches),
             &(dest_ptr->animation_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.classification_related ==
             SE_HIERINC_EVALUATE_RULES &&
             SE_CloneClassificationParameters
                (&(src_ptr->classification_branches),
                &(dest_ptr->classification_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.lod_related &&
             SE_CloneLODSelectParameters(&(src_ptr->lod_branches),
                &(dest_ptr->lod_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
        if (src_ptr->general_hierarchy_mask.classification_related)
        {
            SE_FreeClassificationParameters
            (&(dest_ptr->classification_branches),
             NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.octant_related
                 == SE_HIERINC_EVALUATE_RULES &&
             SE_CloneOctantSelectParameters(&(src_ptr->octant_branches),
                &(dest_ptr->octant_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
        if (src_ptr->general_hierarchy_mask.classification_related)
        {
            SE_FreeClassificationParameters
            (
               &(dest_ptr->classification_branches),
                NULL
            );
        }
        if (src_ptr->general_hierarchy_mask.lod_related)
        {
            SE_FreeLODSelectParameters(&(dest_ptr->lod_branches),
                                       NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.quadrant_related
                 == SE_HIERINC_EVALUATE_RULES &&
             SE_CloneQuadrantSelectParameters(&(src_ptr->quadrant_branches),
                &(dest_ptr->quadrant_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
        if (src_ptr->general_hierarchy_mask.classification_related)
        {
            SE_FreeClassificationParameters
            (&(dest_ptr->classification_branches),
             NULL);
        }
        if (src_ptr->general_hierarchy_mask.lod_related)
        {
            SE_FreeLODSelectParameters(&(dest_ptr->lod_branches),
                                       NULL);
        }
        if (src_ptr->general_hierarchy_mask.octant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeOctantSelectParameters(&(dest_ptr->octant_branches),
                                           NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.spatial_index_related
                 == SE_HIERINC_EVALUATE_RULES &&
             SE_CloneSpatialIndexParameters(&(src_ptr->spatial_index_branches),
                &(dest_ptr->spatial_index_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
        if (src_ptr->general_hierarchy_mask.classification_related)
        {
            SE_FreeClassificationParameters
            (&(dest_ptr->classification_branches),
             NULL);
        }
        if (src_ptr->general_hierarchy_mask.lod_related)
        {
            SE_FreeLODSelectParameters(&(dest_ptr->lod_branches),
                                       NULL);
        }
        if (src_ptr->general_hierarchy_mask.octant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeOctantSelectParameters(&(dest_ptr->octant_branches),
                                           NULL);
        }
        if (src_ptr->general_hierarchy_mask.quadrant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeQuadrantSelectParameters(&(dest_ptr->quadrant_branches),
                                            NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.state_related
                 == SE_HIERINC_EVALUATE_RULES &&
             SE_CloneStateSelectParameters(&(src_ptr->state_branches),
                &(dest_ptr->state_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
        if (src_ptr->general_hierarchy_mask.classification_related)
        {
            SE_FreeClassificationParameters
            (&(dest_ptr->classification_branches),
             NULL);
        }
        if (src_ptr->general_hierarchy_mask.lod_related)
        {
            SE_FreeLODSelectParameters(&(dest_ptr->lod_branches),
                                       NULL);
        }
        if (src_ptr->general_hierarchy_mask.octant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeOctantSelectParameters(&(dest_ptr->octant_branches),
                                           NULL);
        }
        if (src_ptr->general_hierarchy_mask.quadrant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeQuadrantSelectParameters(&(dest_ptr->quadrant_branches),
                                            NULL);
        }
        if (src_ptr->general_hierarchy_mask.spatial_index_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeSpatialIndexParameters(&(dest_ptr->spatial_index_branches),
                                          NULL);
        }
    }
    else if (src_ptr->general_hierarchy_mask.time_related == SE_TRUE &&
             SE_CloneTimeSelectParameters(&(src_ptr->time_branches),
                &(dest_ptr->time_branches)) != SE_STATCODE_SUCCESS)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        if (src_ptr->general_hierarchy_mask.alternate_hierarchy)
        {
            SE_FreeAlternateHierarchyParameters
           (&(dest_ptr->alternate_hierarchy_branches), NULL);
        }
        if (src_ptr->general_hierarchy_mask.animation_related)
        {
            SE_FreeAnimationSelectParameters(&(dest_ptr->animation_branches),
                                             NULL);
        }
        if (src_ptr->general_hierarchy_mask.classification_related)
        {
            SE_FreeClassificationParameters
            (&(dest_ptr->classification_branches),
             NULL);
        }
        if (src_ptr->general_hierarchy_mask.lod_related)
        {
            SE_FreeLODSelectParameters(&(dest_ptr->lod_branches),
                                       NULL);
        }
        if (src_ptr->general_hierarchy_mask.octant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeOctantSelectParameters(&(dest_ptr->octant_branches),
                                           NULL);
        }
        if (src_ptr->general_hierarchy_mask.quadrant_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeQuadrantSelectParameters(&(dest_ptr->quadrant_branches),
                                            NULL);
        }
        if (src_ptr->general_hierarchy_mask.spatial_index_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeSpatialIndexParameters(&(dest_ptr->spatial_index_branches),
                                          NULL);
        }
        if (src_ptr->general_hierarchy_mask.state_related
                 == SE_HIERINC_EVALUATE_RULES)
        {
            SE_FreeStateSelectParameters(&(dest_ptr->state_branches),
                                         NULL);
        }
    }
    else
    {
        memcpy(&(dest_ptr->general_hierarchy_mask),
               &(src_ptr->general_hierarchy_mask),
               sizeof(SE_General_Hierarchy_Select));

        if (src_ptr->general_hierarchy_mask.continuous_lod_related
                == SE_HIERINC_EVALUATE_RULES)
        {
            memcpy(&(dest_ptr->continuous_lod_branches),
                   &(src_ptr->continuous_lod_branches),
                   sizeof(SE_Continuous_LOD_Select_Parameters));
        }

        if (src_ptr->general_hierarchy_mask.separating_plane
                 == SE_HIERINC_EVALUATE_RULES)
        {
           memcpy(&(dest_ptr->separating_plane_branches),
                  &(src_ptr->separating_plane_branches),
                  sizeof(SE_Separating_Plane_Select_Parameters));
        }
    }
    return status;
} /* end SE_CloneHierarchySelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneLODSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneLODSelectParameters
(
    const SE_LOD_Select_Parameters *src_ptr,
          SE_LOD_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->lod_entry_count == 0) ||
             (src_ptr->lod_entry_array == NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        dest_ptr->lod_entry_count = 0;
        dest_ptr->lod_entry_array = NULL;
    }
    else if ((dest_ptr->lod_entry_array =(SE_LOD_Entry *)
             calloc(sizeof(SE_LOD_Entry), src_ptr->lod_entry_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->lod_entry_count = 0;
    }
    else
    {
        dest_ptr->matching_rules  = src_ptr->matching_rules;
        dest_ptr->lod_entry_count = src_ptr->lod_entry_count;
        memcpy(dest_ptr->lod_entry_array, src_ptr->lod_entry_array,
               sizeof(SE_LOD_Entry) * src_ptr->lod_entry_count);
    }
    return status;
} /* end SE_CloneLODSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneOctantSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneOctantSelectParameters
(
    const SE_Octant_Select_Parameters *src_ptr,
          SE_Octant_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->octant_data_count == 0) ||
             (src_ptr->octant_data_array == NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        dest_ptr->octant_data_count           = 0;
        dest_ptr->octant_data_array = NULL;
    }
    else if ((dest_ptr->octant_data_array = (SE_Octant_Data_Fields *)
             calloc(sizeof(SE_Octant_Data_Fields),
             src_ptr->octant_data_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->octant_data_count = 0;
    }
    else
    {
        dest_ptr->octant_data_count = src_ptr->octant_data_count;
        memcpy(dest_ptr->octant_data_array,
               src_ptr->octant_data_array,
               sizeof(SE_Octant_Data_Fields)*
               src_ptr->octant_data_count);
    }
    return status;
} /* end SE_CloneOctantSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneQuadrantSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneQuadrantSelectParameters
(
    const SE_Quadrant_Select_Parameters *src_ptr,
          SE_Quadrant_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->quadrant_data_count == 0) ||
             (src_ptr->quadrant_data_array == NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        dest_ptr->quadrant_data_count           = 0;
        dest_ptr->quadrant_data_array = NULL;
    }
    else if ((dest_ptr->quadrant_data_array =(SE_Quadrant_Data_Fields *)
             calloc(sizeof(SE_Quadrant_Data_Fields),
             src_ptr->quadrant_data_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->quadrant_data_count = 0;
    }
    else
    {
        dest_ptr->quadrant_data_count = src_ptr->quadrant_data_count;
        memcpy(dest_ptr->quadrant_data_array,
               src_ptr->quadrant_data_array,
               sizeof(SE_Quadrant_Data_Fields)*
               src_ptr->quadrant_data_count);
    }
    return status;
} /* end SE_CloneQuadrantSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneSpatialIndexParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneSpatialIndexParameters
(
    const SE_Spatial_Index_Parameters *src_ptr,
          SE_Spatial_Index_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->spatial_index_data_count == 0) ||
             (src_ptr->spatial_index_data_array == NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        dest_ptr->spatial_index_data_count = 0;
        dest_ptr->spatial_index_data_array = NULL;
    }
    else if ((dest_ptr->spatial_index_data_array =
             (SE_Spatial_Index_Data_Fields *)
             calloc(sizeof(SE_Spatial_Index_Data_Fields),
             src_ptr->spatial_index_data_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->spatial_index_data_count = 0;
    }
    else
    {
        dest_ptr->spatial_index_data_count = src_ptr->spatial_index_data_count;
        memcpy(dest_ptr->spatial_index_data_array,
               src_ptr->spatial_index_data_array,
               sizeof(SE_Spatial_Index_Data_Fields)*
               src_ptr->spatial_index_data_count);
    }
    return status;
} /* end SE_CloneSpatialIndexParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneStateEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneStateEntry
(
    const SE_State_Entry *src_ptr,
          SE_State_Entry *dest_ptr
)
{
    SE_Status_Code      status = SE_STATCODE_SUCCESS;
    SE_DRM_Class_Fields temp_fields_in, temp_fields_out;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        temp_fields_in.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields_in.u.State_Data), &(src_ptr->state_data),
               sizeof(SE_State_Data_Fields));

        if (SE_CloneFields(&temp_fields_in, &temp_fields_out)
            != SE_DRM_STAT_CODE_SUCCESS)
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
            dest_ptr->state_tag  = EAC_NULL;
            dest_ptr->state_data = SE_STATE_DATA_FIELDS_DEFAULT;
        }
        else
        {
            memcpy(&(dest_ptr->state_tag), &(src_ptr->state_tag),
                   sizeof(EDCS_Attribute_Code));
            memcpy(&(dest_ptr->state_data),
                   &(temp_fields_out.u.State_Data),
                   sizeof(SE_State_Data_Fields));
        }
    }
    return status;
} /* end SE_CloneStateEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneStateSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneStateSelectParameters
(
    const SE_State_Select_Parameters *src_ptr,
          SE_State_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->state_entry_count == 0) ||
             (src_ptr->state_entry_array == NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        dest_ptr->default_choice    = src_ptr->default_choice;
        dest_ptr->matching_rules    = src_ptr->matching_rules;
        dest_ptr->state_entry_count = 0;
        dest_ptr->state_entry_array = NULL;
    }
    else if ((dest_ptr->state_entry_array =(SE_State_Entry *)
             calloc(sizeof(SE_State_Entry),
                    src_ptr->state_entry_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->default_choice    = src_ptr->default_choice;
        dest_ptr->matching_rules    = src_ptr->matching_rules;
        dest_ptr->state_entry_count = 0;
    }
    else
    {
        dest_ptr->default_choice    = src_ptr->default_choice;
        dest_ptr->matching_rules    = src_ptr->matching_rules;
        dest_ptr->state_entry_count = src_ptr->state_entry_count;
        memcpy(dest_ptr->state_entry_array, src_ptr->state_entry_array,
               sizeof(SE_State_Entry) * dest_ptr->state_entry_count);
    }
    return status;
} /* end SE_CloneStateSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneTimeSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_CloneTimeSelectParameters
(
    const SE_Time_Select_Parameters *src_ptr,
          SE_Time_Select_Parameters *dest_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((src_ptr->time_entry_count == 0) ||
             (src_ptr->time_entry_array == NULL))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        dest_ptr->time_entry_count = 0;
        dest_ptr->time_entry_array = NULL;
    }
    else if ((dest_ptr->time_entry_array =(SE_Time_Entry *)
             calloc(sizeof(SE_Time_Entry), src_ptr->time_entry_count))==NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
        dest_ptr->time_entry_count = 0;
    }
    else
    {
        dest_ptr->matching_rules   = src_ptr->matching_rules;
        dest_ptr->time_entry_count = src_ptr->time_entry_count;
        memcpy(dest_ptr->time_entry_array, src_ptr->time_entry_array,
               sizeof(SE_Time_Entry) * src_ptr->time_entry_count);
    }
    return status;
} /* end SE_CloneTimeSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeAlternateHierarchyParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeAlternateHierarchyParameters
(
    SE_Alternate_Hierarchy_Parameters *to_free,
    void                             (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->hierarchy_data_array == NULL)
    {
        to_free->hierarchy_data_count = 0;
    }
    else
    {
        void                (*dealloc_func_ptr)(void *);
        SE_Integer_Unsigned i = 0;

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        for (i = 0; i < to_free->hierarchy_data_count; i++)
        {
            SE_FreeString
            (
                &(to_free->hierarchy_data_array[i].
                  alternate_representation_reason),
                 dealloc_func_ptr
            );
        }
        (*dealloc_func_ptr)(to_free->hierarchy_data_array);
        to_free->hierarchy_data_array = NULL;
        to_free->hierarchy_data_count = 0;
    }
    return status;
} /* end SE_FreeAlternateHierarchyParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeAnimationSelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeAnimationSelectParameters
(
    SE_Animation_Select_Parameters *to_free,
    void                           (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->animation_ranges_array == NULL)
    {
        to_free->ranges_count = 0;
    }
    else
    {
        void (*dealloc_func_ptr)(void *);

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        (*dealloc_func_ptr)(to_free->animation_ranges_array);

        to_free->ranges_count = 0;
        to_free->animation_ranges_array = NULL;
    }
    return status;
} /* end SE_FreeAnimationSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeClassificationParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeClassificationParameters
(
    SE_Classification_Parameters *to_free,
    void                        (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->classification_array == NULL)
    {
        to_free->classification_count = 0;
    }
    else
    {
        void                 (*dealloc_func_ptr)(void *);
        SE_Integer_Unsigned i = 0;

        if (dealloc_func_in_ptr)
        {
           dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
           dealloc_func_ptr = &free;
        }

        for (i = 0; i < to_free->classification_count; i++)
        {
            SE_FreeClassificationEntry
            (
                &(to_free->classification_array[i]),
                dealloc_func_ptr
            );
        }
        (*dealloc_func_ptr)(to_free->classification_array);
        to_free->classification_array = NULL;
        to_free->classification_count = 0;
    }
    return status;
} /* end SE_FreeClassificationParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeClassificationEntry
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeClassificationEntry
(
    SE_Classification_Entry *to_free,
    void                   (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->prop_val_array == NULL)
    {
        to_free->prop_val_count = 0;
    }
    else
    {
        SE_DRM_Class_Fields temp_fields;
        void                 (*dealloc_func_ptr)(void *);
        SE_Integer_Unsigned i;

        if (dealloc_func_in_ptr)
        {
           dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
           dealloc_func_ptr = &free;
        }
        for (i = 0; i < to_free->prop_val_count; i++)
        {
            temp_fields.tag = SE_CLS_DRM_PROPERTY_VALUE;
            memcpy(&(temp_fields.u.Property_Value),
                   &(to_free->prop_val_array[i]),
                   sizeof(SE_Property_Value_Fields));
            SE_FreeFields(&temp_fields, dealloc_func_ptr);
        }
        (*dealloc_func_ptr)(to_free->prop_val_array);
        to_free->class_data = SE_CLASSIFICATION_DATA_FIELDS_DEFAULT;
        to_free->prop_val_count = 0;
        to_free->prop_val_array = NULL;
    }
    return status;
} /* end SE_FreeClassificationEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeHierarchyOrderParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeHierarchyOrderParameters
(
    SE_Hierarchy_Order_Parameters *to_free,
    void                         (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_DRM_Class_Fields temp_fields_in;

        SE_FreeAlternateHierarchyParameters
        (
            &(to_free->alternate_hierarchy_traversal_order),
            dealloc_func_in_ptr
        );
        SE_FreeClassificationParameters
        (
            &(to_free->classification_traversal_order),
            dealloc_func_in_ptr
        );

        temp_fields_in.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields_in.u.State_Data),
               &(to_free->state_traversal_order),
               sizeof(SE_State_Data_Fields));

        SE_FreeFields(&temp_fields_in, dealloc_func_in_ptr);
        to_free->state_traversal_order = SE_STATE_DATA_FIELDS_DEFAULT;
    }
    return status;
} /* end SE_FreeHierarchyOrderParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeHierarchySelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeHierarchySelectParameters
(
    SE_Hierarchy_Select_Parameters *to_free,
    void                          (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_FreeAlternateHierarchyParameters
        (&(to_free->alternate_hierarchy_branches), dealloc_func_in_ptr);
        SE_FreeAnimationSelectParameters(&(to_free->animation_branches),
                                      dealloc_func_in_ptr);
        SE_FreeClassificationParameters(&(to_free->classification_branches),
                                      dealloc_func_in_ptr);
        SE_FreeLODSelectParameters(&(to_free->lod_branches),
                                      dealloc_func_in_ptr);
        SE_FreeOctantSelectParameters(&(to_free->octant_branches),
                                      dealloc_func_in_ptr);
        SE_FreeQuadrantSelectParameters(&(to_free->quadrant_branches),
                                      dealloc_func_in_ptr);
        SE_FreeSpatialIndexParameters(&(to_free->spatial_index_branches),
                                      dealloc_func_in_ptr);
        SE_FreeStateSelectParameters(&(to_free->state_branches),
                                      dealloc_func_in_ptr);
        SE_FreeTimeSelectParameters(&(to_free->time_branches),
                                      dealloc_func_in_ptr);
    }
    return status;
} /* end SE_FreeHierarchySelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeLODSelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeLODSelectParameters
(
    SE_LOD_Select_Parameters *to_free,
    void                    (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->lod_entry_array == NULL)
    {
        to_free->lod_entry_count = 0;
    }
    else
    {
        void (*dealloc_func_ptr)(void *);

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        (*dealloc_func_ptr)(to_free->lod_entry_array);
        to_free->lod_entry_count = 0;
        to_free->lod_entry_array = NULL;
    }
    return status;
} /* end SE_FreeLODSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeOctantSelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeOctantSelectParameters
(
    SE_Octant_Select_Parameters *to_free,
    void                         (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->octant_data_array == NULL)
    {
        to_free->octant_data_count = 0;
    }
    else
    {
        void (*dealloc_func_ptr)(void *);

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        (*dealloc_func_ptr)(to_free->octant_data_array);
        to_free->octant_data_count = 0;
        to_free->octant_data_array = NULL;
    }
    return status;
} /* end SE_FreeOctantSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeQuadrantSelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeQuadrantSelectParameters
(
    SE_Quadrant_Select_Parameters *to_free,
    void                          (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->quadrant_data_array == NULL)
    {
        to_free->quadrant_data_count = 0;
    }
    else
    {
        void (*dealloc_func_ptr)(void *);

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        (*dealloc_func_ptr)(to_free->quadrant_data_array);
        to_free->quadrant_data_count = 0;
        to_free->quadrant_data_array = NULL;
    }
    return status;
} /* end SE_FreeQuadrantSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSpatialIndexParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeSpatialIndexParameters
(
    SE_Spatial_Index_Parameters *to_free,
    void                        (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->spatial_index_data_array == NULL)
    {
        to_free->spatial_index_data_count = 0;
    }
    else
    {
        void (*dealloc_func_ptr)(void *);

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        (*dealloc_func_ptr)(to_free->spatial_index_data_array);
        to_free->spatial_index_data_count = 0;
        to_free->spatial_index_data_array = NULL;
    }
    return status;
} /* end SE_FreeSpatialIndexParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeStateEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeStateEntry
(
    SE_State_Entry *to_free,
    void          (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_DRM_Class_Fields temp_fields_in;

        temp_fields_in.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields_in.u.State_Data), &(to_free->state_data),
               sizeof(SE_State_Data_Fields));

        SE_FreeFields(&temp_fields_in, dealloc_func_in_ptr);
        to_free->state_data = SE_STATE_DATA_FIELDS_DEFAULT;
    }
    return status;
} /* end SE_FreeStateEntry */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeStateSelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeStateSelectParameters
(
    SE_State_Select_Parameters *to_free,
    void                      (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->state_entry_array == NULL)
    {
        to_free->state_entry_count = 0;
    }
    else
    {
        void                (*dealloc_func_ptr)(void *);
        SE_Integer_Unsigned i = 0;

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }

        for (i = 0; i < to_free->state_entry_count; i++)
        {
            SE_FreeStateEntry(&(to_free->state_entry_array[i]),
                              dealloc_func_ptr);
        }
        (*dealloc_func_ptr)(to_free->state_entry_array);
        to_free->state_entry_array = NULL;
        to_free->state_entry_count = 0;
    }
    return status;
} /* end SE_FreeStateSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTimeSelectParameters
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_FreeTimeSelectParameters
(
    SE_Time_Select_Parameters *to_free,
    void                     (*dealloc_func_in_ptr)(void *)
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (to_free->time_entry_array == NULL)
    {
        to_free->time_entry_count = 0;
    }
    else
    {
        void (*dealloc_func_ptr)(void *);

        if (dealloc_func_in_ptr)
        {
            dealloc_func_ptr = dealloc_func_in_ptr;
        }
        else
        {
            dealloc_func_ptr = &free;
        }
        (*dealloc_func_ptr)(to_free->time_entry_array);
        to_free->time_entry_count = 0;
        to_free->time_entry_array = NULL;
    }
    return status;
} /* end SE_FreeTimeSelectParameters */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SizeOfSearchValueType
 *
 *----------------------------------------------------------------------------
 */
SE_Status_Code
SE_SizeOfSearchValueType
(
    SE_Search_Value_Type  type,
    SE_Integer_Unsigned  *result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!result_out_ptr)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    switch (type)
    {
        case SE_SEARCHVALTYP_BOOLEAN:
             *result_out_ptr = sizeof(SE_Boolean);
             break;

        case SE_SEARCHVALTYP_BYTE:
             *result_out_ptr = sizeof(SE_Byte);
             break;

        case SE_SEARCHVALTYP_BYTE_POSITIVE:
             *result_out_ptr = sizeof(SE_Byte_Positive);
             break;

        case SE_SEARCHVALTYP_BYTE_UNSIGNED:
             *result_out_ptr = sizeof(SE_Byte_Unsigned);
             break;

        case SE_SEARCHVALTYP_SHORT_INTEGER:
             *result_out_ptr = sizeof(SE_Short_Integer);
             break;

        case SE_SEARCHVALTYP_SHORT_INTEGER_POSITIVE:
             *result_out_ptr = sizeof(SE_Short_Integer_Positive);
             break;

        case SE_SEARCHVALTYP_SHORT_INTEGER_UNSIGNED:
             *result_out_ptr = sizeof(SE_Short_Integer_Unsigned);
             break;

        case SE_SEARCHVALTYP_INTEGER:
             *result_out_ptr = sizeof(SE_Integer);
             break;

        case SE_SEARCHVALTYP_INTEGER_POSITIVE:
             *result_out_ptr = sizeof(SE_Integer_Positive);
             break;

        case SE_SEARCHVALTYP_INTEGER_UNSIGNED:
             *result_out_ptr = sizeof(SE_Integer_Unsigned);
             break;

        case SE_SEARCHVALTYP_FLOAT:
             *result_out_ptr = sizeof(SE_Float);
             break;

        case SE_SEARCHVALTYP_ENUMERATED:
             *result_out_ptr = 4; /* $$$ varies depending on enum */
             break;

        case SE_SEARCHVALTYP_LONG_FLOAT:
             *result_out_ptr = sizeof(SE_Long_Float);
             break;

        case SE_SEARCHVALTYP_STRING:
             *result_out_ptr = sizeof(SE_String);
             break;

        case SE_SEARCHVALTYP_SET:
             *result_out_ptr = sizeof(SE_Polygon_Flag);/* $$$ XXX get right size */
             break;

        default:
             status          = SE_STATCODE_INACTIONABLE_FAILURE;
             *result_out_ptr = 0;
             break;
    }
    return status;
} /* end SE_SizeOfSearchValueType */
