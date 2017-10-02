/*
 * FILE       : se_extract_valid_gen.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains validating functions for all SEDRIS Level 0 Read API types.
 *
 *   Some types do not have validating functions because they contain nothing
 *   that can be checked. For a struct type, the corresponding validating
 *   function will check only those fields that need validating.
 *
 *   These functions are intended for use by any application in order to ensure
 *   that a given variable has valid values.
 *
 * - API spec. 4.1
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "se_read0.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareClassificationEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareClassificationEntry
(
    const SE_Classification_Entry *a_ptr,
    const SE_Classification_Entry *b_ptr
)
{
    int result = 0;

    result = (a_ptr->class_data.tag == b_ptr->class_data.tag) ? 0 :
             ((a_ptr->class_data.tag < b_ptr->class_data.tag) ? -1 : 1);

    if ((result == 0) && (a_ptr->prop_val_count != b_ptr->prop_val_count))
    {
        if (a_ptr->prop_val_count < b_ptr->prop_val_count)
            result = -1;
        else
            result = 1;
    }

   /*
    * Having confirmed that the prop_val_arrays are the same size, compare
    * their contents.
    */
    if ((result == 0) && (a_ptr->prop_val_count > 0))
    {
        SE_Integer_Unsigned i,j;
        SE_Boolean          match_entry = SE_FALSE, match_total = SE_TRUE;

         for (i = 0; (match_total == SE_TRUE) && (i < a_ptr->prop_val_count);
              i++)
         {
             match_entry = SE_FALSE;
             for (j = 0; (match_total==SE_TRUE) && (match_entry==SE_FALSE)
                  && (j < b_ptr->prop_val_count); j++)
             {
                /*
                 * Since a_ptr, b_ptr are individually valid, at most 1
                 * entry in b_ptr's array can match an entry in a_ptr's
                 * array, because each array contains only distinct meanings
                 *
                 * $$$ Currently doesn't take unit conversion into account,
                 * but a majority of qualifier-applicable EAs aren't numeric
                 */
                 if (SE_ComparePropertyCodes(&(a_ptr->prop_val_array[i].
                     meaning), &(b_ptr->prop_val_array[j].meaning)) == 0)
                 {
                     result = EDCS_CompareAttributeValues
                              (
                                 &(a_ptr->prop_val_array[i].value),
                                 &(b_ptr->prop_val_array[j].value)
                              );

                     if (result == 0)
                         match_entry = SE_TRUE;
                     else
                         match_total = SE_FALSE;
                 }
             }

             if (match_entry != SE_TRUE)
             {
                 match_total = SE_FALSE;
             }
         }

         if (match_total != SE_TRUE)
         {
             result = -1;
         }
    }
    return result;
} /* end local_CompareClassificationEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareClassificationEntry
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareClassificationEntry
(
    const SE_Classification_Entry *a_ptr,
    const SE_Classification_Entry *b_ptr
)
{
    int result = 0;

    if (SE_ValidClassificationEntry(a_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        result = (SE_ValidClassificationEntry(b_ptr, SE_FALSE, NULL) != SE_TRUE) ? 0 : 1;
    }
    else if (SE_ValidClassificationEntry(b_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        result = -1;
    }
    else
    {
        result = local_CompareClassificationEntry(a_ptr, b_ptr);
    }
    return result;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareVector3D
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareVector3D
(
    const SRM_Vector_3D a_ptr,
    const SRM_Vector_3D b_ptr
)
{
    int result = 0;

   /*
    * prior to this, both vectors have been validated as unit vectors
    */
    if (a_ptr[0] < b_ptr[0])
    {
        result = -1;
    }
    else if (a_ptr[0] > b_ptr[0])
    {
        result = 1;
    }
    else if (a_ptr[1] < b_ptr[1])
    {
        result = -1;
    }
    else if (a_ptr[1] > b_ptr[1])
    {
        result = 1;
    }
    else if (a_ptr[2] < b_ptr[2])
    {
        result = -1;
    }
    else if (a_ptr[2] > b_ptr[2])
    {
        result = 1;
    }
    return result;
} /* end local_CompareVector3D */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareCylindricalVolumeExtentEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareCylindricalVolumeExtentEntry
(
    const SE_Cylindrical_Volume_Extent_Entry *a_ptr,
    const SE_Cylindrical_Volume_Extent_Entry *b_ptr
)
{
    int result = 0;

    if (a_ptr->cylinder.cylinder_length < b_ptr->cylinder.cylinder_length)
    {
        result = -1;
    }
    else if (a_ptr->cylinder.cylinder_length > b_ptr->cylinder.cylinder_length)
    {
        result = 1;
    }
    else if (a_ptr->cylinder.major_axis_radius <
             b_ptr->cylinder.major_axis_radius)
    {
        result = -1;
    }
    else if (a_ptr->cylinder.major_axis_radius >
             b_ptr->cylinder.major_axis_radius)
    {
        result = 1;
    }
    else if (a_ptr->cylinder.minor_axis_radius <
             b_ptr->cylinder.minor_axis_radius)
    {
        result = -1;
    }
    else if (a_ptr->cylinder.minor_axis_radius >
             b_ptr->cylinder.minor_axis_radius)
    {
        result = 1;
    }
    else
    {
        result = local_CompareVector3D(a_ptr->reference_vectors[0].unit_vector,
                 b_ptr->reference_vectors[0].unit_vector);
        if (result == 0)
        {
            result = local_CompareVector3D
                     (a_ptr->reference_vectors[1].unit_vector,
                      b_ptr->reference_vectors[1].unit_vector);
        }
    }
    return result;
} /* end local_CompareCylindricalVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareParallelepipedVolumeExtentEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareParallelepipedVolumeExtentEntry
(
    const SE_Parallelepiped_Volume_Extent_Entry *a_ptr,
    const SE_Parallelepiped_Volume_Extent_Entry *b_ptr
)
{
    int result = 0;

    if (a_ptr->parallelepiped.edge_length[0] <
        b_ptr->parallelepiped.edge_length[0])
    {
        result = -1;
    }
    else if (a_ptr->parallelepiped.edge_length[0] >
             b_ptr->parallelepiped.edge_length[0])
    {
        result = 1;
    }
    else if (a_ptr->parallelepiped.edge_length[1] <
             b_ptr->parallelepiped.edge_length[1])
    {
        result = -1;
    }
    else if (a_ptr->parallelepiped.edge_length[1] >
             b_ptr->parallelepiped.edge_length[1])
    {
        result = 1;
    }
    else if (a_ptr->parallelepiped.edge_length[2] <
             b_ptr->parallelepiped.edge_length[2])
    {
        result = -1;
    }
    else if (a_ptr->parallelepiped.edge_length[2] >
             b_ptr->parallelepiped.edge_length[2])
    {
        result = 1;
    }
    else
    {
        result = local_CompareVector3D
                 (a_ptr->reference_vectors[0].unit_vector,
                  b_ptr->reference_vectors[0].unit_vector);
        if (result == 0)
        {
            result = local_CompareVector3D
                     (a_ptr->reference_vectors[1].unit_vector,
                      b_ptr->reference_vectors[1].unit_vector);
            if (result == 0)
            {
                result = local_CompareVector3D
                         (a_ptr->reference_vectors[2].unit_vector,
                          b_ptr->reference_vectors[2].unit_vector);
            }
        }
    }
    return result;
} /* end local_CompareParallelepipedVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
int
local_CompareVolumeExtentEntry
(
    const SE_Volume_Extent_Entry *a_ptr,
    const SE_Volume_Extent_Entry *b_ptr
)
{
    int result = 0;

    if (a_ptr->volume_type != b_ptr->volume_type)
    {
        return ((a_ptr->volume_type > b_ptr->volume_type) ? 1 : -1);
    }
    switch (a_ptr->volume_type)
    {
        case SE_VOLSHAP_CYLINDER:
            result = local_CompareCylindricalVolumeExtentEntry(
                      &(a_ptr->volume_extent_data.cylinder),
                      &(b_ptr->volume_extent_data.cylinder));
            break;

        case SE_VOLSHAP_PARALLELEPIPED:
            result = local_CompareParallelepipedVolumeExtentEntry(
                      &(a_ptr->volume_extent_data.parallelepiped),
                      &(b_ptr->volume_extent_data.parallelepiped));
            break;

        case SE_VOLSHAP_SPHERE:
             if (a_ptr->volume_extent_data.sphere.radius <
                 b_ptr->volume_extent_data.sphere.radius)
             {
                 result = -1;
             }
             else if (a_ptr->volume_extent_data.sphere.radius >
                 b_ptr->volume_extent_data.sphere.radius)
             {
                 result = 1;
             }
            break;

        default:
             result = -1;
             break;
    } /* end switch */
    return result;
} /* end local_CompareVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareLODVolumeEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareVolumeLODEntry
(
    const SE_Volume_LOD_Entry *a_ptr,
    const SE_Volume_LOD_Entry *b_ptr
)
{
    int         result = 0;
    SRM_Boolean coord_equal = SRM_FALSE;

    if (a_ptr->volume_lod.outside != b_ptr->volume_lod.outside)
    {
        result = (a_ptr->volume_lod.outside==SE_TRUE) ? 1 : -1;
    }
    else if ((SRM_CoordinateEqual(&(a_ptr->coordinate), &(b_ptr->coordinate),
             &coord_equal) != SRM_STATCOD_SUCCESS) ||
             (coord_equal != SRM_TRUE))
    {
        result = -1; /* since they were valid, they're not compatible */
    }
    else
    {
        result = local_CompareVolumeExtentEntry(&(a_ptr->volume_extent),
                                                &(b_ptr->volume_extent));
    }
    return result;
} /* end local_CompareVolumeLODEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareLODEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareLODEntry
(
    const SE_LOD_Entry *a_ptr,
    const SE_LOD_Entry *b_ptr
)
{
    int result = 0;

    result = (a_ptr->lod_entry_type == b_ptr->lod_entry_type) ? 0 :
             ((a_ptr->lod_entry_type < b_ptr->lod_entry_type) ? -1 : 1);

    if (result == 0)
    {
       /*
        * First check for equality
        */
        switch (a_ptr->lod_entry_type)
        {
            case SE_LODDATTYP_DISTANCE:
                 if (a_ptr->lod.distance.minimum_range <
                     b_ptr->lod.distance.minimum_range)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.distance.minimum_range >
                     b_ptr->lod.distance.minimum_range)
                 {
                     result = 1;
                 }
                 else if (a_ptr->lod.distance.maximum_range <
                          b_ptr->lod.distance.maximum_range)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.distance.maximum_range >
                     b_ptr->lod.distance.maximum_range)
                 {
                     result = 1;
                 }
                 else if (a_ptr->lod.distance.minimum_range <
                     b_ptr->lod.distance.minimum_range)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.distance.minimum_fade_band >
                     b_ptr->lod.distance.minimum_fade_band)
                 {
                     result = 1;
                 }
                 else if (a_ptr->lod.distance.maximum_fade_band <
                          b_ptr->lod.distance.maximum_fade_band)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.distance.maximum_fade_band >
                     b_ptr->lod.distance.maximum_fade_band)
                 {
                     result = 1;
                 }
                 break;

            case SE_LODDATTYP_INDEX:
                 if (a_ptr->lod.index.index <
                     b_ptr->lod.index.index)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.index.index >
                     b_ptr->lod.index.index)
                 {
                     result = 1;
                 }
                 break;

            case SE_LODDATTYP_MAP_SCALE:
                 if (a_ptr->lod.map_scale.map_scale <
                     b_ptr->lod.map_scale.map_scale)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.map_scale.map_scale >
                     b_ptr->lod.map_scale.map_scale)
                 {
                     result = 1;
                 }
                 break;

            case SE_LODDATTYP_VOLUME:
                 result = local_CompareVolumeLODEntry(&(a_ptr->lod.volume), &(b_ptr->lod.volume));
                 break;

            case SE_LODDATTYP_SPATIAL_RESOLUTION:
                 if (a_ptr->lod.spatial_resolution.unit <
                     b_ptr->lod.spatial_resolution.unit)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.spatial_resolution.unit >
                     b_ptr->lod.spatial_resolution.unit)
                 {
                     result = 1;
                 }
                 else if (a_ptr->lod.spatial_resolution.spatial_resolution <
                     b_ptr->lod.spatial_resolution.spatial_resolution)
                 {
                     result = -1;
                 }
                 else if (a_ptr->lod.spatial_resolution.spatial_resolution >
                     b_ptr->lod.spatial_resolution.spatial_resolution)
                 {
                     result = 1;
                 }
                 break;

            default:
            /*
             * Impossible case unless new enumerants are registered
             */
                 result = -1;
                 break;
        } /* end switch */
    }
    return result;
} /* end local_CompareLODEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareStateEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareStateEntry
(
    const SE_State_Entry *a_ptr,
    const SE_State_Entry *b_ptr
)
{
    int result = 0;

    result = (a_ptr->state_tag == b_ptr->state_tag) ? 0 :
             ((a_ptr->state_tag < b_ptr->state_tag) ? -1 : 1);

    if (result == 0)
    {
       /*
        * First check for equality
        */
        result = EDCS_CompareAttributeValues
                 (
                     &(a_ptr->state_data.state_value),
                     &(b_ptr->state_data.state_value)
                 );
    }
    return result;
} /* end local_CompareStateEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareTimeEntry
 *
 *   Caller ensures both arguments are individually valid, to save a lot of
 *   unnecessary thrashing around at this point.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareTimeEntry
(
    const SE_Time_Entry *a_ptr,
    const SE_Time_Entry *b_ptr
)
{
    int result = 0;

    result = (a_ptr->time_entry_type == b_ptr->time_entry_type) ? 0 :
             ((a_ptr->time_entry_type < b_ptr->time_entry_type) ? -1 : 1);

    if (result == 0)
    {
       /*
        * First check for equality
        */
        switch (a_ptr->time_entry_type)
        {
            case SE_TIMEDATTYP_SEASON:
                 if (a_ptr->time_data.season.season <
                     b_ptr->time_data.season.season)
                 {
                     result = -1;
                 }
                 else if (a_ptr->time_data.season.season >
                          b_ptr->time_data.season.season)
                 {
                     result = 1;
                 }
                /*
                 * for the moment, ignore SE_Time_Significance
                 */
                 break;

            case SE_TIMEDATTYP_TIME_INTERVAL:
                /*
                 * need more comparison functions
                 */
                 result = -1;
                 break;

            case SE_TIMEDATTYP_TIME_OF_DAY:
                 if (a_ptr->time_data.time_of_day.time_of_day <
                     b_ptr->time_data.time_of_day.time_of_day)
                 {
                     result = -1;
                 }
                 else if (a_ptr->time_data.time_of_day.time_of_day >
                          b_ptr->time_data.time_of_day.time_of_day)
                 {
                     result = 1;
                 }
                /*
                 * for the moment, ignore SE_Time_Significance
                 */
                 break;

            case SE_TIMEDATTYP_TIME_POINT:
                /*
                 * need more comparison functions
                 */
                 result = -1;
                 break;

            default:
            /*
             * Impossible case unless new enumerants are registered
             */
                 result = -1;
                 break;
        } /* end switch */
    }
    return result;
} /* end local_CompareTimeEntry */



/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAbsoluteTimeIntervalEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAbsoluteTimeIntervalEntry
(
    const SE_Absolute_Time_Interval_Entry *value_ptr,
          SE_Boolean                       print_error,
          SE_Integer_Unsigned             *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidAbsoluteTimeIntervalEntry: NULL value_ptr\n");
        }
        return result;
    }

    temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
    memcpy(&(temp_fields.u.Absolute_Time),
           &(value_ptr->reference_time),
           sizeof(SE_Absolute_Time_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL;
    memcpy(&(temp_fields.u.Absolute_Time_Interval),
           &(value_ptr->absolute_interval),
           sizeof(SE_Absolute_Time_Interval_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    return result;
} /* end SE_ValidAbsoluteTimeIntervalEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAccessMode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAccessMode
(
    SE_Access_Mode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_AM_READ_ONLY:
        case SE_AM_UPDATE:
        case SE_AM_CREATE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidAccessMode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAlternateHierarchyParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAlternateHierarchyParameters
(
    const SE_Alternate_Hierarchy_Parameters *value_ptr,
          SE_Boolean                         print_error,
          SE_Integer_Unsigned               *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidAlternateHierarchyParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->hierarchy_data_array &&
        (value_ptr->hierarchy_data_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->hierarchy_data_array for"\
                   " value_ptr->hierarchy_data_count == %u\n",(unsigned int)
                    value_ptr->hierarchy_data_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->hierarchy_data_count; i++)
        {
            temp_fields.tag = SE_CLS_DRM_HIERARCHY_DATA;
            memcpy(&(temp_fields.u.Hierarchy_Data),
                   &(value_ptr->hierarchy_data_array[i]),
                   sizeof(SE_Hierarchy_Data_Fields));
            if (!SE_ValidDRMClassFields(&temp_fields, print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Hierarchy_Data_Fields"\
                        " found at value_ptr->hierarchy_data_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->hierarchy_data_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->hierarchy_data_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) &&
                 (j < (SE_Integer_Unsigned)value_ptr->hierarchy_data_count);
                 j++)
            {
                if (SE_CompareStrings(&(value_ptr->hierarchy_data_array[i].
                    alternate_representation_reason),
                    &(value_ptr->hierarchy_data_array[j].
                    alternate_representation_reason)) == 0)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "hierarchy_data_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidAlternateHierarchyParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAnimationRange
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAnimationRange
(
    const SE_Animation_Range *value_ptr,
          SE_Boolean          print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidAnimationRange: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->beginning_frame > value_ptr->ending_frame)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidAnimationRange: "
                    "beginning_frame > ending_frame\n");
        }
    }
    return result;
} /* end SE_ValidAnimationRange */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAnimationSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAnimationSelectParameters
(
    const SE_Animation_Select_Parameters *value_ptr,
          SE_Boolean                      print_error,
          SE_Integer_Unsigned            *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidAnimationSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->animation_ranges_array && (value_ptr->ranges_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->animation_ranges_array for"\
                   " value_ptr->ranges_count == %u\n",(unsigned int)
                    value_ptr->ranges_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->ranges_count; i++)
        {
            if (!SE_ValidAnimationRange
                    (&(value_ptr->animation_ranges_array[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Animation_Range found at "\
                        "value_ptr->animation_ranges_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->ranges_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->ranges_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) && (j < value_ptr->ranges_count);
                 j++)
            {
                if ((value_ptr->animation_ranges_array[i].beginning_frame ==
                     value_ptr->animation_ranges_array[j].beginning_frame) &&
                    (value_ptr->animation_ranges_array[i].ending_frame ==
                     value_ptr->animation_ranges_array[j].ending_frame))
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "animation_ranges_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidAnimationSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAPIFunction
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAPIFunction
(
    SE_API_Function value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP:
        case SE_APIFN_ADD_COMPONENT_RELATIONSHIP:
        case SE_APIFN_ALLOC_DATA_TABLE_DATA:
        case SE_APIFN_CLONE_OBJECT_HANDLE:
        case SE_APIFN_CLOSE_TRANSMITTAL:
        case SE_APIFN_CREATE_OBJECT:
        case SE_APIFN_CREATE_SEARCH_FILTER:
        case SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY:
        case SE_APIFN_CREATE_STORE:
        case SE_APIFN_DETERMINE_SPATIAL_INCLUSION:
        case SE_APIFN_FREE_ITERATOR:
        case SE_APIFN_FREE_OBJECT:
        case SE_APIFN_FREE_PACKED_HIERARCHY:
        case SE_APIFN_FREE_REMAINING_OBJECTS_LIST:
        case SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST:
        case SE_APIFN_FREE_SEARCH_FILTER:
        case SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY:
        case SE_APIFN_FREE_STORE:
        case SE_APIFN_FREE_TRANSMITTAL:
        case SE_APIFN_GET_AGGREGATE:
        case SE_APIFN_GET_ASSOCIATE:
        case SE_APIFN_GET_COLOUR_MODEL:
        case SE_APIFN_GET_COMPONENT:
        case SE_APIFN_GET_CONTEXT_TRANSFORMATION:
        case SE_APIFN_GET_DATA_TABLE_DATA:
        case SE_APIFN_GET_DRM_CLASS:
        case SE_APIFN_GET_ENCODING:
        case SE_APIFN_GET_FIELDS:
        case SE_APIFN_GET_IMAGE_DATA:
        case SE_APIFN_GET_ITERATION_LENGTH_REMAINING:
        case SE_APIFN_GET_LAST_FUNCTION_STATUS:
        case SE_APIFN_GET_MESH_FACE_TABLE_DATA:
        case SE_APIFN_GET_NEXT_OBJECT:
        case SE_APIFN_GET_NTH_ASSOCIATE:
        case SE_APIFN_GET_NTH_COMPONENT:
        case SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT:
        case SE_APIFN_GET_OBJECT_FROM_ID_STRING:
        case SE_APIFN_GET_OBJECT_ID_STRING:
        case SE_APIFN_GET_OBJECT_REFERENCE_COUNT:
        case SE_APIFN_GET_PACKED_HIERARCHY:
        case SE_APIFN_GET_PUBLISHED_LABELS:
        case SE_APIFN_GET_PUBLISHED_OBJECT_LIST:
        case SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST:
        case SE_APIFN_GET_RELATION_COUNTS:
        case SE_APIFN_GET_REMAINING_OBJECTS_LIST:
        case SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST:
        case SE_APIFN_GET_ROOT_OBJECT:
        case SE_APIFN_GET_SRF_CONTEXT_INFO:
        case SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT:
        case SE_APIFN_GET_TRANSMITTAL_LOCATION:
        case SE_APIFN_GET_TRANSMITTAL_NAME:
        case SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION:
        case SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID:
        case SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL:
        case SE_APIFN_GET_USER_DATA:
        case SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR:
        case SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR:
        case SE_APIFN_INITIALIZE_COMPONENT_ITERATOR:
        case SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR:
        case SE_APIFN_IS_ITERATOR_COMPLETE:
        case SE_APIFN_OBJECT_IS_PUBLISHED:
        case SE_APIFN_OBJECT_IS_RESOLVED:
        case SE_APIFN_OBJECTS_ARE_SAME:
        case SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION:
        case SE_APIFN_OPEN_TRANSMITTAL_BY_NAME:
        case SE_APIFN_PUBLISH_OBJECT:
        case SE_APIFN_PUT_DATA_TABLE_DATA:
        case SE_APIFN_PUT_FIELDS:
        case SE_APIFN_PUT_IMAGE_DATA:
        case SE_APIFN_PUT_MESH_FACE_TABLE_DATA:
        case SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP:
        case SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP:
        case SE_APIFN_REMOVE_FROM_TRANSMITTAL:
        case SE_APIFN_RESOLVE_OBJECT:
        case SE_APIFN_RESOLVE_TRANSMITTAL_NAME:
        case SE_APIFN_SET_COLOUR_MODEL:
        case SE_APIFN_SET_FIRST_ERROR_MESSAGE:
        case SE_APIFN_SET_GENERAL_CALLBACK:
        case SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION:
        case SE_APIFN_SET_ROOT_OBJECT:
        case SE_APIFN_SET_SPECIFIC_CALLBACK:
        case SE_APIFN_SET_SECOND_ERROR_MESSAGE:
        case SE_APIFN_SET_SRF_CONTEXT_INFO:
        case SE_APIFN_SET_TRANSMITTAL_NAME:
        case SE_APIFN_SET_USER_DATA:
        case SE_APIFN_TRANSMITTALS_ARE_SAME:
        case SE_APIFN_UNPUBLISH_OBJECT:
        case SE_APIFN_USE_DEFAULT_COLOUR_MODEL:
        case SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidAPIFunction */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidBranchRangeMatching
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidBranchRangeMatching
(
    SE_Branch_Range_Matching value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_BRRNGMAT_EXACT:
        case SE_BRRNGMAT_FULL_CONTAINMENT:
        case SE_BRRNGMAT_INTERSECTION:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidBranchRangeMatching */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidClassificationEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidClassificationEntry
(
    const SE_Classification_Entry *value_ptr,
          SE_Boolean               print_error,
          SE_Integer_Unsigned     *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidClassificationEntry: NULL value_ptr\n");
        }
        return result;
    }

    temp_fields.tag = SE_CLS_DRM_CLASSIFICATION_DATA;
    memcpy(&(temp_fields.u.Classification_Data),
           &(value_ptr->class_data),
           sizeof(SE_Classification_Data_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    if (!value_ptr->prop_val_array && (value_ptr->prop_val_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->prop_val_array for"\
                   " value_ptr->prop_val_count == %u\n",(unsigned int)
                    value_ptr->prop_val_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->prop_val_count; i++)
        {
            temp_fields.tag = SE_CLS_DRM_PROPERTY_VALUE;
            memcpy(&(temp_fields.u.Property_Value),
                   &(value_ptr->prop_val_array[i]),
                   sizeof(SE_Property_Value_Fields));
            if (!SE_ValidDRMClassFields(&temp_fields, print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Property_Value_Fields"\
                        " found at value_ptr->prop_val_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

   /*
    * If multiple qualifying <Property Value> components are present,
    * they shall not conflict.
    */
    if ((result == SE_TRUE) && (value_ptr->prop_val_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->prop_val_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) && (j < value_ptr->prop_val_count);
                 j++)
            {
                if (SE_ComparePropertyCodes(
                       &(value_ptr->prop_val_array[i].meaning),
                       &(value_ptr->prop_val_array[j].meaning)) == 0)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "prop_val_array has conflicting"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidClassificationEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidClassificationParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidClassificationParameters
(
    const SE_Classification_Parameters *value_ptr,
          SE_Boolean                    print_error,
          SE_Integer_Unsigned          *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidClassificationParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->classification_array &&
        (value_ptr->classification_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->classification_array for"\
                   " value_ptr->classification_count == %u\n",(unsigned int)
                    value_ptr->classification_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->classification_count; i++)
        {
            if (!SE_ValidClassificationEntry
                    (&(value_ptr->classification_array[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Classification_Entry found at "\
                        "value_ptr->classification_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->classification_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->classification_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) &&
                 (j < value_ptr->classification_count);
                 j++)
            {
                if (local_CompareClassificationEntry(&(value_ptr->classification_array[i]),
                   &(value_ptr->classification_array[j]))==0)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "classification_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidClassificationParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidContinuousLODSelectChoice
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidContinuousLODSelectChoice
(
    SE_Continuous_LOD_Select_Choice value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_CLOD_ALL:
        case SE_CLOD_LEAST_DETAILED:
        case SE_CLOD_MOST_DETAILED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidContinuousLODSelectChoice */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidContinuousLODSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidContinuousLODSelectParameters
(
    const SE_Continuous_LOD_Select_Parameters *value_ptr,
          SE_Boolean                           print_error,
          SE_Integer_Unsigned                 *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidContinuousLODSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidContinuousLODSelectChoice(value_ptr->clod_choice))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Continuous_LOD_Select_Choice value"\
                    " (%d)\n", (int) value_ptr->clod_choice);
    }
    return result;
} /* end SE_ValidContinuousLODSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCylindricalVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidCylindricalVolumeExtentEntry
(
    const SE_Cylindrical_Volume_Extent_Entry *value_ptr,
          SE_Boolean                          print_error,
          SE_Integer_Unsigned                *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidCylindricalVolumeExtentEntry: NULL value_ptr\n");
        }
        return result;
    }

    temp_fields.tag = SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT;
    memcpy(&(temp_fields.u.Cylindrical_Volume_Extent),
           &(value_ptr->cylinder),
           sizeof(SE_Cylindrical_Volume_Extent_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < 2; i++)
        {
            temp_fields.tag = SE_CLS_DRM_REFERENCE_VECTOR;
            memcpy(&(temp_fields.u.Reference_Vector),
                   &(value_ptr->reference_vectors[i]),
                   sizeof(SE_Reference_Vector_Fields));
            result = (SE_Boolean)
                   (result && SE_ValidDRMClassFields(&temp_fields,
                   print_error, error_count_ptr));
            if (result == SE_TRUE)
            {
                if ((i==0) && (value_ptr->reference_vectors[i].vector_type !=
                   SE_REFVEC_MAJOR_AXIS))
                {
                    result = SE_FALSE;
                    if (error_count_ptr) (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "value_ptr->reference_vectors[%u]"\
                " (%s) != SE_REFVEC_MAJOR_AXIS\n", i,
                SE_PrintReferenceVectorType(temp_fields.u.Reference_Vector.vector_type));
                }
                else if ((i==1) &&
                (value_ptr->reference_vectors[i].vector_type !=
                SE_REFVEC_MINOR_AXIS))
                {
                    result = SE_FALSE;
                    if (error_count_ptr) (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "value_ptr->reference_vectors[%u]"\
                " (%s) != SE_REFVEC_MAJOR_AXIS\n", i,
                SE_PrintReferenceVectorType(temp_fields.u.Reference_Vector.vector_type));
                }
            }
        } /* end for i */
    }
    if (result == SE_TRUE)
    {
        SRM_Long_Float dot_product = 0.0;

        if ((SRM_DotProduct(value_ptr->reference_vectors[0].unit_vector,
            value_ptr->reference_vectors[1].unit_vector, &dot_product) !=
            SRM_STATCOD_SUCCESS) || (dot_product != 0.0))
        {
            result = SE_FALSE;
            if (error_count_ptr) (*error_count_ptr)++;
            if (print_error)
                fprintf(f_ptr, "Dot product of "\
                  "value_ptr->reference_vectors[0] and "\
                  "value_ptr->reference_vectors[1] either can't be "\
                  "determined or is not zero; must be perpendicular\n");
        }
    }
    return result;
} /* end SE_ValidCylindricalVolumeExtentEntry */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataTableSubExtent
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDataTableSubExtent
(
    const SE_Data_Table_Sub_Extent *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDataTableSubExtent: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->axes_bounds && (value_ptr->axes_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->axes_bounds for"\
                   " value_ptr->axes_count == %u\n",(unsigned int)
                    value_ptr->axes_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->axes_count; i++)
        {
            if (!SE_ValidIndexRange(&(value_ptr->axes_bounds[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Index_Range found at "\
                        "value_ptr->axes_bounds[%u]\n", i);
                }
            }
        } /* end for i */
    }
    return result;
} /* end SE_ValidDataTableSubExtent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidEncoding
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidEncoding
(
    SE_Encoding value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ENCODING_STF:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidEncoding */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeneralHierarchyOrder
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidGeneralHierarchyOrder
(
    const SE_General_Hierarchy_Order *value_ptr,
          SE_Boolean                  print_error,
          SE_Integer_Unsigned        *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidGeneralHierarchyOrder: NULL value_ptr\n");
        }
        return result;
    }
    else if (value_ptr->set == 0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidGeneralHierarchyOrder: value_ptr->set == 0\n");
        }
        return result;
    }
    return result;
} /* end SE_ValidGeneralHierarchyOrder */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeneralHierarchySelect
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidGeneralHierarchySelect
(
    const SE_General_Hierarchy_Select *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidGeneralHierarchySelect: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidHierarchyInclusion(value_ptr->alternate_hierarchy))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->alternate_hierarchy);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->animation_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->animation_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->classification_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->classification_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->continuous_lod_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->continuous_lod_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->octant_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->octant_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->quadrant_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->quadrant_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->separating_plane))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->separating_plane);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->spatial_index_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->spatial_index_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->state_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->state_related);
    }
    if (!SE_ValidBoolean(value_ptr->lod_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->lod_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->lod_distance_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->lod_distance_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->lod_index_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->lod_index_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->lod_map_scale_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->lod_map_scale_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->lod_spatial_resolution_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->lod_spatial_resolution_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->lod_volume_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->lod_volume_related);
    }
    if (!SE_ValidBoolean(value_ptr->time_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->time_related);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->time_related_by_season))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->time_related_by_season);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->time_related_by_time_interval))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->time_related_by_time_interval);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->time_related_by_time_of_day))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->time_related_by_time_of_day);
    }
    if (!SE_ValidHierarchyInclusion(value_ptr->time_related_by_time_point))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Hierarchy_Inclusion value (%d)\n",
                (int) value_ptr->time_related_by_time_point);
    }
    if (!SE_ValidBoolean(value_ptr->perimeter_related))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->perimeter_related);
    }
    if (!SE_ValidBoolean(value_ptr->union_of_features))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->union_of_features);
    }
    if (!SE_ValidBoolean(value_ptr->union_of_geometry_hierarchies))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->union_of_geometry_hierarchies);
    }
    if (!SE_ValidBoolean(value_ptr->union_of_geometry_primitives))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->union_of_geometry_primitives);
    }
    return result;
} /* end SE_ValidGeneralHierarchySelect */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHierarchyInclusion
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidHierarchyInclusion
(
    SE_Hierarchy_Inclusion value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_HIERINC_EXCLUDE_ALL:
        case SE_HIERINC_INCLUDE_ALL:
        case SE_HIERINC_EVALUATE_RULES:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidHierarchyInclusion */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHierarchyOrderParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidHierarchyOrderParameters
(
    const SE_Hierarchy_Order_Parameters *value_ptr,
          SE_Boolean                     print_error,
          SE_Integer_Unsigned           *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidHierarchyOrderParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidGeneralHierarchyOrder(&(value_ptr->general_hierarchy_mask),
              print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_General_Hierarchy_Order value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.member.Alternate_Hierarchy==1) &&
              !SE_ValidAlternateHierarchyParameters(
              &(value_ptr->alternate_hierarchy_traversal_order), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Alternate_Hierarchy_Parameters"\
                   " value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.member.Classification_Related==1) &&
              !SE_ValidClassificationParameters(
              &(value_ptr->classification_traversal_order), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Classification_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.member.LOD_Related==1) &&
       !SE_ValidSiblingTraversalOrder(value_ptr->lod_traversal_order))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Sibling_Traversal_Order value (%d)\n",
                (int) value_ptr->lod_traversal_order);
    }
    if ((value_ptr->general_hierarchy_mask.member.Octant_Related==1) &&
       !SE_ValidSiblingTraversalOrder(value_ptr->octant_traversal_order))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Sibling_Traversal_Order value (%d)\n",
                (int) value_ptr->octant_traversal_order);
    }
    if ((value_ptr->general_hierarchy_mask.member.Quadrant_Related==1) &&
       !SE_ValidSiblingTraversalOrder(value_ptr->quadrant_traversal_order))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Sibling_Traversal_Order value (%d)\n",
                (int) value_ptr->quadrant_traversal_order);
    }
    if ((value_ptr->general_hierarchy_mask.member.Separating_Plane==1) &&
       !SE_ValidSiblingTraversalOrder
       (value_ptr->separating_plane_traversal_order))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Sibling_Traversal_Order value (%d)\n",
                (int) value_ptr->separating_plane_traversal_order);
    }
    if ((value_ptr->general_hierarchy_mask.member.Spatial_Index_Related==1) &&
       !SE_ValidSiblingTraversalOrder
       (value_ptr->spatial_index_general_traversal_order))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Sibling_Traversal_Order value (%d)\n",
                (int) value_ptr->spatial_index_general_traversal_order);
    }
    if(value_ptr->general_hierarchy_mask.member.State_Related == 1)
    {
       temp_fields.tag = SE_CLS_DRM_STATE_DATA;
       memcpy(&(temp_fields.u.State_Data),
              &(value_ptr->state_traversal_order),
              sizeof(SE_State_Data_Fields));
       result = (SE_Boolean)
                (result &&
                SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    }
    if ((value_ptr->general_hierarchy_mask.member.Time_Related==1) &&
       !SE_ValidSiblingTraversalOrder(value_ptr->time_traversal_order))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Sibling_Traversal_Order value (%d)\n",
                (int) value_ptr->time_traversal_order);
    }
    return result;
} /* end SE_ValidHierarchyOrderParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHierarchySelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidHierarchySelectParameters
(
    const SE_Hierarchy_Select_Parameters *value_ptr,
          SE_Boolean                      print_error,
          SE_Integer_Unsigned            *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidHierarchySelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidGeneralHierarchySelect(&(value_ptr->general_hierarchy_mask),
              print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_General_Hierarchy_Select value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.alternate_hierarchy==
              SE_HIERINC_EVALUATE_RULES) &&
              !SE_ValidAlternateHierarchyParameters(
              &(value_ptr->alternate_hierarchy_branches), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Alternate_Hierarchy_Parameters"\
                   " value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.animation_related==
              SE_HIERINC_EVALUATE_RULES) &&!SE_ValidAnimationSelectParameters(
              &(value_ptr->animation_branches), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Animation_Select_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.classification_related==
              SE_HIERINC_EVALUATE_RULES) &&!SE_ValidClassificationParameters(
              &(value_ptr->classification_branches), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Classification_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.continuous_lod_related==
              SE_HIERINC_EVALUATE_RULES) &&
              !SE_ValidContinuousLODSelectParameters(
              &(value_ptr->continuous_lod_branches), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Continuous_LOD_Select_Parameters"\
                   " value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.lod_related==SE_TRUE) &&
              !SE_ValidLODSelectParameters(&(value_ptr->lod_branches),
              print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_LOD_Select_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.octant_related==
              SE_HIERINC_EVALUATE_RULES) &&!SE_ValidOctantSelectParameters(
              &(value_ptr->octant_branches), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Octant_Select_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.quadrant_related==
              SE_HIERINC_EVALUATE_RULES) &&!SE_ValidQuadrantSelectParameters(
              &(value_ptr->quadrant_branches), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Quadrant_Select_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.separating_plane==
              SE_HIERINC_EVALUATE_RULES) &&
              !SE_ValidSeparatingPlaneSelectParameters(
              &(value_ptr->separating_plane_branches), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Separating_Plane_Select_Parameters"\
                   " value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.spatial_index_related==
              SE_HIERINC_EVALUATE_RULES) &&!SE_ValidSpatialIndexParameters(
              &(value_ptr->spatial_index_branches), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Spatial_Index_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.state_related==
              SE_HIERINC_EVALUATE_RULES) &&!SE_ValidStateSelectParameters(
              &(value_ptr->state_branches), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_State_Select_Parameters value\n");
        }
    }
    if ((value_ptr->general_hierarchy_mask.time_related==SE_TRUE) &&
              !SE_ValidTimeSelectParameters(&(value_ptr->time_branches),
              print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Time_Select_Parameters value\n");
        }
    }
    return result;
} /* end SE_ValidHierarchySelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageData
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageData
(
    const SE_Image_Data *value_ptr,
          SE_Boolean     print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidImageData: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->data && (value_ptr->data_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->data for value_ptr->data_count =="\
                   " %u\n",(unsigned int) value_ptr->data_count);
        }
    }
    return result;
} /* end SE_ValidImageData */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIndexRange
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIndexRange
(
    const SE_Index_Range *value_ptr,
          SE_Boolean      print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidIndexRange: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->first_index > value_ptr->last_index)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidIndexRange: first_index > last_index\n");
        }
    }
    return result;
} /* end SE_ValidIndexRange */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidITRBehaviour
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidITRBehaviour
(
    SE_ITR_Behaviour value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ITRBEH_RESOLVE:
        case SE_ITRBEH_REPORT:
        case SE_ITRBEH_IGNORE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidITRBehaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLODEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidLODEntry
(
    const SE_LOD_Entry *value_ptr,
          SE_Boolean    print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidLODEntry: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->lod_entry_type)
    {
        case SE_LODDATTYP_DISTANCE:
            temp_fields.tag = SE_CLS_DRM_DISTANCE_LOD_DATA;
            memcpy(&(temp_fields.u.Distance_LOD_Data),
                   &(value_ptr->lod.distance),
                   sizeof(SE_Distance_LOD_Data_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_LODDATTYP_INDEX:
            temp_fields.tag = SE_CLS_DRM_INDEX_LOD_DATA;
            memcpy(&(temp_fields.u.Index_LOD_Data),
                   &(value_ptr->lod.index),
                   sizeof(SE_Index_LOD_Data_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_LODDATTYP_MAP_SCALE:
            temp_fields.tag = SE_CLS_DRM_MAP_SCALE_LOD_DATA;
            memcpy(&(temp_fields.u.Map_Scale_LOD_Data),
                   &(value_ptr->lod.map_scale),
                   sizeof(SE_Map_Scale_LOD_Data_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_LODDATTYP_VOLUME:
            if (!SE_ValidVolumeLODEntry(&(value_ptr->lod.volume), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Volume_LOD_Entry value\n");
                }
            }
            break;

        case SE_LODDATTYP_SPATIAL_RESOLUTION:
            temp_fields.tag = SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA;
            memcpy(&(temp_fields.u.Spatial_Resolution_LOD_Data),
                   &(value_ptr->lod.spatial_resolution),
                   sizeof(SE_Spatial_Resolution_LOD_Data_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr) (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_LOD_Data_Type value (%d)\n", (int)
                         value_ptr->lod_entry_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidLODEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLODSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidLODSelectParameters
(
    const SE_LOD_Select_Parameters *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidLODSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidBranchRangeMatching(value_ptr->matching_rules))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Branch_Range_Matching value (%d)\n",
                (int) value_ptr->matching_rules);
    }
    if (!value_ptr->lod_entry_array && (value_ptr->lod_entry_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->lod_entry_array for"\
                   " value_ptr->lod_entry_count == %u\n",(unsigned int)
                    value_ptr->lod_entry_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->lod_entry_count; i++)
        {
            if (!SE_ValidLODEntry(&(value_ptr->lod_entry_array[i]),
                    print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_LOD_Entry found at "\
                        "value_ptr->lod_entry_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->lod_entry_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->lod_entry_count-1)); i++)
        {
            for (j = i+1; (result == SE_TRUE) &&
                 (j < (SE_Integer_Unsigned)value_ptr->lod_entry_count);
                 j++)
            {
                if (local_CompareLODEntry(&(value_ptr->lod_entry_array[i]),
                   &(value_ptr->lod_entry_array[j]))==0)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "lod_entry_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            } /* end for j */
        } /* end for i */
    }
    return result;
} /* end SE_ValidLODSelectParameters */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidObjectInclusion
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidObjectInclusion
(
    SE_Object_Inclusion value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_OBJINCL_FULLY_INCLUDED:
        case SE_OBJINCL_PARTIALLY_INCLUDED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidObjectInclusion */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidOctantSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidOctantSelectParameters
(
    const SE_Octant_Select_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidOctantSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->octant_data_array && (value_ptr->octant_data_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->octant_data_array for"\
                   " value_ptr->octant_data_count == %u\n",(unsigned int)
                    value_ptr->octant_data_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->octant_data_count; i++)
        {
            temp_fields.tag = SE_CLS_DRM_OCTANT_DATA;
            memcpy(&(temp_fields.u.Octant_Data),
                   &(value_ptr->octant_data_array[i]),
                   sizeof(SE_Octant_Data_Fields));
            if (!SE_ValidDRMClassFields(&temp_fields, print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Octant_Data_Fields"\
                        " found at value_ptr->octant_data_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->octant_data_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->octant_data_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) && (j < value_ptr->octant_data_count);
                 j++)
            {
                if (value_ptr->octant_data_array[i].octant ==
                    value_ptr->octant_data_array[j].octant)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "octant_data_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidOctantSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidParallelepipedVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidParallelepipedVolumeExtentEntry
(
    const SE_Parallelepiped_Volume_Extent_Entry *value_ptr,
          SE_Boolean                             print_error,
          SE_Integer_Unsigned                   *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidParallelepipedVolumeExtentEntry: NULL value_ptr\n");
        }
        return result;
    }

    temp_fields.tag = SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT;
    memcpy(&(temp_fields.u.Parallelepiped_Volume_Extent),
           &(value_ptr->parallelepiped),
           sizeof(SE_Parallelepiped_Volume_Extent_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < 3; i++)
        {
            temp_fields.tag = SE_CLS_DRM_REFERENCE_VECTOR;
            memcpy(&(temp_fields.u.Reference_Vector),
                   &(value_ptr->reference_vectors[i]),
                   sizeof(SE_Reference_Vector_Fields));
            result = (SE_Boolean)
                   (result && SE_ValidDRMClassFields(&temp_fields,
                   print_error, error_count_ptr));
            if ((result == SE_TRUE) &&
                   (temp_fields.u.Reference_Vector.vector_type !=
                   SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION))
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "value_ptr->reference_vectors[%u] (%s) !="\
                " SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION\n", i,
                SE_PrintReferenceVectorType(temp_fields.u.Reference_Vector.vector_type));
            }
        } /* end for i */

        if (result == SE_TRUE)
        {
            SE_Integer_Unsigned j;
            SRM_Long_Float      dot_product = 0.0;

            for (i = 0; i < 2; i++)
            {
                for (j = i + 1; j < 3; j++)
                {
                    if ((SRM_DotProduct(value_ptr->reference_vectors[i].
                        unit_vector, value_ptr->reference_vectors[j].
                        unit_vector, &dot_product) != SRM_STATCOD_SUCCESS)
                     || (dot_product != 0.0))
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Dot product of "\
                              "value_ptr->reference_vectors[%u].unit_vector "\
                              "and value_ptr->reference_vectors[%u]."\
                              "unit_vector either can't be determined"\
                              " or is not zero; must be "\
                              "perpendicular\n", i, j);
                    }
                } /* end for j */
            } /* end for i */
        } /* end if */
    }
    return result;
} /* end SE_ValidParallelepipedVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidQuadrantSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidQuadrantSelectParameters
(
    const SE_Quadrant_Select_Parameters *value_ptr,
          SE_Boolean                     print_error,
          SE_Integer_Unsigned           *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidQuadrantSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->quadrant_data_array && (value_ptr->quadrant_data_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->quadrant_data_array for"\
                   " value_ptr->quadrant_data_count == %u\n",(unsigned int)
                    value_ptr->quadrant_data_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->quadrant_data_count; i++)
        {
            temp_fields.tag = SE_CLS_DRM_QUADRANT_DATA;
            memcpy(&(temp_fields.u.Quadrant_Data),
                   &(value_ptr->quadrant_data_array[i]),
                   sizeof(SE_Quadrant_Data_Fields));
            if (!SE_ValidDRMClassFields(&temp_fields, print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Quadrant_Data_Fields"\
                        " found at value_ptr->quadrant_data_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->quadrant_data_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->quadrant_data_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) && (j < value_ptr->quadrant_data_count);
                 j++)
            {
                if (value_ptr->quadrant_data_array[i].quadrant ==
                    value_ptr->quadrant_data_array[j].quadrant)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "quadrant_data_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidQuadrantSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidRelativeToAbsoluteTimeEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidRelativeToAbsoluteTimeEntry
(
    const SE_Relative_To_Absolute_Time_Entry *value_ptr,
          SE_Boolean                          print_error,
          SE_Integer_Unsigned                *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidRelativeToAbsoluteTimeEntry: NULL value_ptr\n");
        }
        return result;
    }

    temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
    memcpy(&(temp_fields.u.Absolute_Time),
           &(value_ptr->reference_time),
           sizeof(SE_Absolute_Time_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME;
    memcpy(&(temp_fields.u.Relative_Time),
           &(value_ptr->relative_time),
           sizeof(SE_Relative_Time_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    return result;
} /* end SE_ValidRelativeToAbsoluteTimeEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidRelativeToAbsoluteTimeIntervalEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidRelativeToAbsoluteTimeIntervalEntry
(
    const SE_Relative_To_Absolute_Time_Interval_Entry *value_ptr,
          SE_Boolean                                   print_error,
          SE_Integer_Unsigned                         *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidRelativeToAbsoluteTimeIntervalEntry: NULL value_ptr\n");
        }
        return result;
    }

    temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
    memcpy(&(temp_fields.u.Absolute_Time),
           &(value_ptr->reference_time),
           sizeof(SE_Absolute_Time_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
    memcpy(&(temp_fields.u.Relative_Time_Interval),
           &(value_ptr->relative_interval),
           sizeof(SE_Relative_Time_Interval_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    return result;
} /* end SE_ValidRelativeToAbsoluteTimeIntervalEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReturnCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidReturnCode
(
    SE_Return_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_RETCOD_FAILURE:
        case SE_RETCOD_SUCCESS:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidReturnCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchBounds
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchBounds
(
    const SE_Search_Bounds *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL, *srm_f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
        srm_f_ptr = SRM_GetErrorFilePtr();
        if (SRM_SetErrorFilePtr(f_ptr) != SRM_STATCOD_SUCCESS)
        {
            print_error = SE_FALSE;
        }
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidSearchBounds: NULL value_ptr\n");
        }
        return result;
    }

    if (!SRM_ValidCoordinate(&(value_ptr->minimum_point), (SRM_Boolean)
              print_error, (SRM_Integer_Unsigned *) error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SRM_Coordinate value\n");
        }
    }
    if (!SRM_ValidCoordinate(&(value_ptr->maximum_point), (SRM_Boolean)
              print_error, (SRM_Integer_Unsigned *) error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SRM_Coordinate value\n");
        }
    }

    /* now that the SRM_Coords have been validated
     * we now need to make sure that they are both
     * of the same spatial_coord_code.
     */
    if (value_ptr->minimum_point.spatial_coord_code ==
        value_ptr->maximum_point.spatial_coord_code)
    {
        switch (value_ptr->minimum_point.spatial_coord_code)
        {
            case SRM_SPACOORDCOD_CC_3D:
                 if ((value_ptr->minimum_point.coordinate.cc_3d.u >
                      value_ptr->maximum_point.coordinate.cc_3d.u)
                  || (value_ptr->minimum_point.coordinate.cc_3d.v >
                      value_ptr->maximum_point.coordinate.cc_3d.v)
                  || (value_ptr->minimum_point.coordinate.cc_3d.w >
                      value_ptr->maximum_point.coordinate.cc_3d.w))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_CD_3D:
                 if (value_ptr->minimum_point.coordinate.cd_3d.ellipsoidal_height >
                     value_ptr->maximum_point.coordinate.cd_3d.ellipsoidal_height)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point ellipsoidal_height "\
                           "greater than maximum_point ellipsoidal_height\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_CD_SURFACE:
                 break;

            case SRM_SPACOORDCOD_CM_3D:
                 if (value_ptr->minimum_point.coordinate.cm_3d.radius >
                     value_ptr->maximum_point.coordinate.cm_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
                 if ((value_ptr->minimum_point.coordinate.ec_aug_3d.northing >
                      value_ptr->maximum_point.coordinate.ec_aug_3d.northing)
                  || (value_ptr->minimum_point.coordinate.ec_aug_3d.easting >
                      value_ptr->maximum_point.coordinate.ec_aug_3d.easting)
                  || (value_ptr->minimum_point.coordinate.ec_aug_3d.ellipsoidal_height >
                      value_ptr->maximum_point.coordinate.ec_aug_3d.ellipsoidal_height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_EC_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.ec_surface.northing >
                      value_ptr->maximum_point.coordinate.ec_surface.northing)
                  || (value_ptr->minimum_point.coordinate.ec_surface.easting >
                      value_ptr->maximum_point.coordinate.ec_surface.easting))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_EI_3D:
                 if (value_ptr->minimum_point.coordinate.ei_3d.radius >
                     value_ptr->maximum_point.coordinate.ei_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_HAEC_3D:
                 if (value_ptr->minimum_point.coordinate.haec_3d.radius >
                     value_ptr->maximum_point.coordinate.haec_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_HEEC_3D:
                 if (value_ptr->minimum_point.coordinate.heec_3d.radius >
                     value_ptr->maximum_point.coordinate.heec_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_HEEQ_3D:
                 if (value_ptr->minimum_point.coordinate.heeq_3d.radius >
                     value_ptr->maximum_point.coordinate.heeq_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
                 if ((value_ptr->minimum_point.coordinate.lcc_aug_3d.northing >
                      value_ptr->maximum_point.coordinate.lcc_aug_3d.northing)
                  || (value_ptr->minimum_point.coordinate.lcc_aug_3d.easting >
                      value_ptr->maximum_point.coordinate.lcc_aug_3d.easting)
                  || (value_ptr->minimum_point.coordinate.lcc_aug_3d.ellipsoidal_height >
                      value_ptr->maximum_point.coordinate.lcc_aug_3d.ellipsoidal_height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LCC_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.lcc_surface.northing >
                      value_ptr->maximum_point.coordinate.lcc_surface.northing)
                  || (value_ptr->minimum_point.coordinate.lcc_surface.easting >
                      value_ptr->maximum_point.coordinate.lcc_surface.easting))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LSA_2D:
                 if (value_ptr->minimum_point.coordinate.lsa_2d.radius >
                     value_ptr->maximum_point.coordinate.lsa_2d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LSP_2D:
                 if (value_ptr->minimum_point.coordinate.lsp_2d.radius >
                     value_ptr->maximum_point.coordinate.lsp_2d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LSR_2D:
                 if ((value_ptr->minimum_point.coordinate.lsr_2d.u >
                      value_ptr->maximum_point.coordinate.lsr_2d.u)
                  || (value_ptr->minimum_point.coordinate.lsr_2d.v >
                      value_ptr->maximum_point.coordinate.lsr_2d.v))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LSR_3D:
                 if ((value_ptr->minimum_point.coordinate.lsr_3d.u >
                      value_ptr->maximum_point.coordinate.lsr_3d.u)
                  || (value_ptr->minimum_point.coordinate.lsr_3d.v >
                      value_ptr->maximum_point.coordinate.lsr_3d.v)
                  || (value_ptr->minimum_point.coordinate.lsr_3d.w >
                      value_ptr->maximum_point.coordinate.lsr_3d.w))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LCE_3D:
                 if ((value_ptr->minimum_point.coordinate.lce_3d.u >
                      value_ptr->maximum_point.coordinate.lce_3d.u)
                  || (value_ptr->minimum_point.coordinate.lce_3d.v >
                      value_ptr->maximum_point.coordinate.lce_3d.v)
                  || (value_ptr->minimum_point.coordinate.lce_3d.w >
                      value_ptr->maximum_point.coordinate.lce_3d.w))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LTSAS_3D:
                 if (value_ptr->minimum_point.coordinate.ltsas_3d.radius >
                     value_ptr->maximum_point.coordinate.ltsas_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LTSAS_SURFACE:
                 break;

            case SRM_SPACOORDCOD_LTSC_3D:
                 if (value_ptr->minimum_point.coordinate.ltsc_3d.height >
                     value_ptr->maximum_point.coordinate.ltsc_3d.height)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point height "\
                           "greater than maximum_point height\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LTSC_SURFACE:
                 if (value_ptr->minimum_point.coordinate.ltsc_surface.radius >
                     value_ptr->maximum_point.coordinate.ltsc_surface.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LTSE_3D:
                 if ((value_ptr->minimum_point.coordinate.ltse_3d.x >
                      value_ptr->maximum_point.coordinate.ltse_3d.x)
                  || (value_ptr->minimum_point.coordinate.ltse_3d.y >
                      value_ptr->maximum_point.coordinate.ltse_3d.y)
                  || (value_ptr->minimum_point.coordinate.ltse_3d.height >
                      value_ptr->maximum_point.coordinate.ltse_3d.height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_LTSE_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.ltse_surface.x >
                      value_ptr->maximum_point.coordinate.ltse_surface.x)
                  || (value_ptr->minimum_point.coordinate.ltse_surface.y >
                      value_ptr->maximum_point.coordinate.ltse_surface.y))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_M_AUGMENTED_3D:
                 if ((value_ptr->minimum_point.coordinate.m_aug_3d.northing >
                      value_ptr->maximum_point.coordinate.m_aug_3d.northing)
                  || (value_ptr->minimum_point.coordinate.m_aug_3d.easting >
                      value_ptr->maximum_point.coordinate.m_aug_3d.easting)
                  || (value_ptr->minimum_point.coordinate.m_aug_3d.ellipsoidal_height >
                      value_ptr->maximum_point.coordinate.m_aug_3d.ellipsoidal_height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_M_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.m_surface.northing >
                      value_ptr->maximum_point.coordinate.m_surface.northing)
                  || (value_ptr->minimum_point.coordinate.m_surface.easting >
                      value_ptr->maximum_point.coordinate.m_surface.easting))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
                 if ((value_ptr->minimum_point.coordinate.oms_aug_3d.northing >
                      value_ptr->maximum_point.coordinate.oms_aug_3d.northing)
                  || (value_ptr->minimum_point.coordinate.oms_aug_3d.easting >
                      value_ptr->maximum_point.coordinate.oms_aug_3d.easting)
                  || (value_ptr->minimum_point.coordinate.oms_aug_3d.ellipsoidal_height >
                      value_ptr->maximum_point.coordinate.oms_aug_3d.ellipsoidal_height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_OMS_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.oms_surface.northing >
                      value_ptr->maximum_point.coordinate.oms_surface.northing)
                  || (value_ptr->minimum_point.coordinate.oms_surface.easting >
                      value_ptr->maximum_point.coordinate.oms_surface.easting))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_PD_3D:
                 if (value_ptr->minimum_point.coordinate.pd_3d.ellipsoidal_height >
                     value_ptr->maximum_point.coordinate.pd_3d.ellipsoidal_height)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point ellipsoidal_height "\
                           "greater than maximum_point ellipsoidal_height\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_PD_SURFACE:
                 break;

            case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
                 if ((value_ptr->minimum_point.coordinate.ps_aug_3d.northing >
                      value_ptr->maximum_point.coordinate.ps_aug_3d.northing)
                  || (value_ptr->minimum_point.coordinate.ps_aug_3d.easting >
                      value_ptr->maximum_point.coordinate.ps_aug_3d.easting)
                  || (value_ptr->minimum_point.coordinate.ps_aug_3d.ellipsoidal_height >
                      value_ptr->maximum_point.coordinate.ps_aug_3d.ellipsoidal_height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_PS_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.ps_surface.northing >
                      value_ptr->maximum_point.coordinate.ps_surface.northing)
                  || (value_ptr->minimum_point.coordinate.ps_surface.easting >
                      value_ptr->maximum_point.coordinate.ps_surface.easting))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_SEC_3D:
                 if (value_ptr->minimum_point.coordinate.sec_3d.radius >
                     value_ptr->maximum_point.coordinate.sec_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_SEQ_3D:
                 if (value_ptr->minimum_point.coordinate.seq_3d.radius >
                     value_ptr->maximum_point.coordinate.seq_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_SMD_3D:
                 if (value_ptr->minimum_point.coordinate.smd_3d.radius >
                     value_ptr->maximum_point.coordinate.smd_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_SME_3D:
                 if (value_ptr->minimum_point.coordinate.sme_3d.radius >
                     value_ptr->maximum_point.coordinate.sme_3d.radius)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point radius "\
                           "greater than maximum_point radius\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
                 if ((value_ptr->minimum_point.coordinate.tm_aug_3d.northing >
                      value_ptr->maximum_point.coordinate.tm_aug_3d.northing)
                  || (value_ptr->minimum_point.coordinate.tm_aug_3d.easting >
                      value_ptr->maximum_point.coordinate.tm_aug_3d.easting)
                  || (value_ptr->minimum_point.coordinate.tm_aug_3d.ellipsoidal_height >
                      value_ptr->maximum_point.coordinate.tm_aug_3d.ellipsoidal_height))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;

            case SRM_SPACOORDCOD_TM_SURFACE:
                 if ((value_ptr->minimum_point.coordinate.tm_surface.northing >
                      value_ptr->maximum_point.coordinate.tm_surface.northing)
                  || (value_ptr->minimum_point.coordinate.tm_surface.easting >
                      value_ptr->maximum_point.coordinate.tm_surface.easting))
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr, "minimum_point greater than maximum_point\n");
                     }
                 }
                 break;
        }
    }
    else
    {
       result = SE_FALSE;
       if (print_error)
       {
          fprintf(f_ptr, "Non-matching spatial_coord_codes\n");
       }
    }

    if (print_error)
    {
        SRM_SetErrorFilePtr(srm_f_ptr);
    }
    return result;
} /* end SE_ValidSearchBounds */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchBoundsClosure
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchBoundsClosure
(
    SE_Search_Bounds_Closure value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SEARCHBNDSCLS_FULLY_CLOSED:
        case SE_SEARCHBNDSCLS_PARTIALLY_CLOSED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSearchBoundsClosure */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchDimension
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchDimension
(
    SE_Search_Dimension value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE:
        case SE_SEARCHDIM_THREE_DIMENSIONAL:
        case SE_SEARCHDIM_ALL_DIMENSIONS:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSearchDimension */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchRuleType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchRuleType
(
    SE_Search_Rule_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SEARCHRULETYP_END:
        case SE_SEARCHRULETYP_AND:
        case SE_SEARCHRULETYP_OR:
        case SE_SEARCHRULETYP_NOT:
        case SE_SEARCHRULETYP_OBJECT_AND:
        case SE_SEARCHRULETYP_PREDICATE:
        case SE_SEARCHRULETYP_DRM_CLASS:
        case SE_SEARCHRULETYP_FIELD:
        case SE_SEARCHRULETYP_FIELD_RANGE:
        case SE_SEARCHRULETYP_FIELD_ARRAY:
        case SE_SEARCHRULETYP_COMPONENT:
        case SE_SEARCHRULETYP_COMPONENT_FIELD:
        case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
        case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
        case SE_SEARCHRULETYP_ASSOCIATE:
        case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSearchRuleType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchType
(
    SE_Search_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SEARCHTYP_POINT:
        case SE_SEARCHTYP_BOUNDING_BOX:
        case SE_SEARCHTYP_EXACT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSearchType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchValueType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchValueType
(
    SE_Search_Value_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SEARCHVALTYP_BOOLEAN:
        case SE_SEARCHVALTYP_BYTE:
        case SE_SEARCHVALTYP_BYTE_POSITIVE:
        case SE_SEARCHVALTYP_BYTE_UNSIGNED:
        case SE_SEARCHVALTYP_ENUMERATED:
        case SE_SEARCHVALTYP_FLOAT:
        case SE_SEARCHVALTYP_INTEGER:
        case SE_SEARCHVALTYP_INTEGER_POSITIVE:
        case SE_SEARCHVALTYP_INTEGER_UNSIGNED:
        case SE_SEARCHVALTYP_LONG_FLOAT:
        case SE_SEARCHVALTYP_SET:
        case SE_SEARCHVALTYP_SHORT_INTEGER:
        case SE_SEARCHVALTYP_SHORT_INTEGER_POSITIVE:
        case SE_SEARCHVALTYP_SHORT_INTEGER_UNSIGNED:
        case SE_SEARCHVALTYP_STRING:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSearchValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSeparatingPlaneSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSeparatingPlaneSelectParameters
(
    const SE_Separating_Plane_Select_Parameters *value_ptr,
          SE_Boolean                             print_error,
          SE_Integer_Unsigned                   *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidSeparatingPlaneSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidBoolean(value_ptr->traverse_positive_branches))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->traverse_positive_branches);
    }
    if (!SE_ValidBoolean(value_ptr->traverse_negative_branches))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->traverse_negative_branches);
    }
    return result;
} /* end SE_ValidSeparatingPlaneSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSiblingTraversalOrder
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSiblingTraversalOrder
(
    SE_Sibling_Traversal_Order value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SIBTRAV_ASCENDING:
        case SE_SIBTRAV_DESCENDING:
        case SE_SIBTRAV_UNSPECIFIED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSiblingTraversalOrder */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpatialIndexParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSpatialIndexParameters
(
    const SE_Spatial_Index_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidSpatialIndexParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->spatial_index_data_array &&
        (value_ptr->spatial_index_data_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->spatial_index_data_array for"\
                   " value_ptr->spatial_index_data_count == %u\n",(unsigned
                    int) value_ptr->spatial_index_data_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->spatial_index_data_count; i++)
        {
            temp_fields.tag = SE_CLS_DRM_SPATIAL_INDEX_DATA;
            memcpy(&(temp_fields.u.Spatial_Index_Data),
                   &(value_ptr->spatial_index_data_array[i]),
                   sizeof(SE_Spatial_Index_Data_Fields));
            if (!SE_ValidDRMClassFields(&temp_fields, print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Spatial_Index_Data_Fields"\
                        " found at value_ptr->spatial_index_data_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) &&
        (value_ptr->spatial_index_data_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->spatial_index_data_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) &&
                          (j < value_ptr->spatial_index_data_count);
                 j++)
            {
                if ((value_ptr->spatial_index_data_array[i].column_index ==
                     value_ptr->spatial_index_data_array[j].column_index) &&
                    (value_ptr->spatial_index_data_array[i].row_index ==
                     value_ptr->spatial_index_data_array[j].row_index))
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "spatial_index_data_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidSpatialIndexParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStateEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidStateEntry
(
    const SE_State_Entry *value_ptr,
          SE_Boolean      print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    EDCS_Boolean edcs_result = EDCS_FALSE;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidStateEntry: NULL value_ptr\n");
        }
        return result;
    }

    if ((EDCS_IsStateApplicable(value_ptr->state_tag, &edcs_result) !=
       EDCS_SC_SUCCESS)|| (edcs_result != EDCS_TRUE))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Attribute_Code value (%d)\n", (int)
                value_ptr->state_tag);
    }
    temp_fields.tag = SE_CLS_DRM_STATE_DATA;
    memcpy(&(temp_fields.u.State_Data),
           &(value_ptr->state_data),
           sizeof(SE_State_Data_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    if ((result == SE_TRUE)
     && (value_ptr->state_data.state_value.attribute_value_type==EDCS_AVT_ENUMERATION)
     && (EDCS_ValidAttributeValue(value_ptr->state_tag,
         &(value_ptr->state_data.state_value), (EDCS_Boolean) print_error,
          (EDCS_Count *) error_count_ptr) != EDCS_TRUE))
    {
        result = SE_FALSE;
    }
    return result;
} /* end SE_ValidStateEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStateSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidStateSelectParameters
(
    const SE_State_Select_Parameters *value_ptr,
          SE_Boolean                  print_error,
          SE_Integer_Unsigned        *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidStateSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidUnmatchedStateBehaviour(value_ptr->default_choice))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Unmatched_State_Behaviour value (%d)\n",
                (int) value_ptr->default_choice);
    }
    if (!SE_ValidBranchRangeMatching(value_ptr->matching_rules))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Branch_Range_Matching value (%d)\n",
                (int) value_ptr->matching_rules);
    }
    if (!value_ptr->state_entry_array && (value_ptr->state_entry_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->state_entry_array for"\
                   " value_ptr->state_entry_count == %u\n",(unsigned int)
                    value_ptr->state_entry_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->state_entry_count; i++)
        {
            if (!SE_ValidStateEntry(&(value_ptr->state_entry_array[i]),
                    print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_State_Entry found at "\
                        "value_ptr->state_entry_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->state_entry_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->state_entry_count-1));
             i++)
        {
            for (j = i+1; (result == SE_TRUE) &&
                 (j < value_ptr->state_entry_count);
                 j++)
            {
                if (local_CompareStateEntry(&(value_ptr->state_entry_array[i]),
                   &(value_ptr->state_entry_array[j]))==0)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "state_entry_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            }
        }
    }
    return result;
} /* end SE_ValidStateSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStatusCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidStatusCode
(
    SE_Status_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_STATCODE_SUCCESS:
        case SE_STATCODE_DELETED_OBJECT:
        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
        case SE_STATCODE_INVALID_ACCESS_MODE:
        case SE_STATCODE_INVALID_OBJECT_LABEL:
        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
        case SE_STATCODE_NO_OBJECT:
        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
        case SE_STATCODE_UNPUBLISHED_OBJECT:
        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
        case SE_STATCODE_UNSUPPORTED_ENCODING:
        case SE_STATCODE_INACTIONABLE_FAILURE:
        case SE_STATCODE_OUT_OF_MEMORY:
        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
        case SE_STATCODE_C_STORE_INVALID:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidStatusCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeEntry
(
    const SE_Time_Entry *value_ptr,
          SE_Boolean     print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeEntry: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->time_entry_type)
    {
        case SE_TIMEDATTYP_SEASON:
            temp_fields.tag = SE_CLS_DRM_SEASON;
            memcpy(&(temp_fields.u.Season),
                   &(value_ptr->time_data.season),
                   sizeof(SE_Season_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_TIMEDATTYP_TIME_INTERVAL:
            if (!SE_ValidTimeIntervalEntry(
                      &(value_ptr->time_data.time_interval), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_Interval_Entry value\n");
                }
            }
            break;

        case SE_TIMEDATTYP_TIME_OF_DAY:
            temp_fields.tag = SE_CLS_DRM_TIME_OF_DAY;
            memcpy(&(temp_fields.u.Time_Of_Day),
                   &(value_ptr->time_data.time_of_day),
                   sizeof(SE_Time_Of_Day_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_TIMEDATTYP_TIME_POINT:
            if (!SE_ValidTimePointEntry(&(value_ptr->time_data.time_point),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_Point_Entry value\n");
                }
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr) (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Time_Data_Type value (%d)\n",
                         (int) value_ptr->time_entry_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeIntervalEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeIntervalEntry
(
    const SE_Time_Interval_Entry *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeIntervalEntry: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->time_type)
    {
        case SE_TIMEMEASTYP_GMT:
            if (!SE_ValidAbsoluteTimeIntervalEntry(
                      &(value_ptr->time_interval_data.absolute_time),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Absolute_Time_Interval_Entry"\
                           " value\n");
                }
            }
            break;

        case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
            temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
            memcpy(&(temp_fields.u.Relative_Time_Interval),
                   &(value_ptr->time_interval_data.relative_to_simulation),
                   sizeof(SE_Relative_Time_Interval_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
            if (!SE_ValidRelativeToAbsoluteTimeIntervalEntry(
                      &(value_ptr->time_interval_data.relative_to_absolute),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal"\
                           " SE_Relative_To_Absolute_Time_Interval_Entry"\
                           " value\n");
                }
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr) (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Time_Measurement_Type value"\
                         " (%d)\n", (int) value_ptr->time_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeIntervalEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMeasurementType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeMeasurementType
(
    SE_Time_Measurement_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TIMEMEASTYP_GMT:
        case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
        case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeMeasurementType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimePointEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimePointEntry
(
    const SE_Time_Point_Entry *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimePointEntry: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->time_type)
    {
        case SE_TIMEMEASTYP_GMT:
            temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
            memcpy(&(temp_fields.u.Absolute_Time),
                   &(value_ptr->time_point_data.absolute_time),
                   sizeof(SE_Absolute_Time_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
            temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME;
            memcpy(&(temp_fields.u.Relative_Time),
                   &(value_ptr->time_point_data.relative_to_start),
                   sizeof(SE_Relative_Time_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
            if (!SE_ValidRelativeToAbsoluteTimeEntry(
                      &(value_ptr->time_point_data.relative_to_reference),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal"\
                           " SE_Relative_To_Absolute_Time_Entry value\n");
                }
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr) (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Time_Measurement_Type value"\
                         " (%d)\n", (int) value_ptr->time_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidTimePointEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeSelectParameters
(
    const SE_Time_Select_Parameters *value_ptr,
          SE_Boolean                 print_error,
          SE_Integer_Unsigned       *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeSelectParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidBranchRangeMatching(value_ptr->matching_rules))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Branch_Range_Matching value (%d)\n",
                (int) value_ptr->matching_rules);
    }
    if (!value_ptr->time_entry_array && (value_ptr->time_entry_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->time_entry_array for"\
                   " value_ptr->time_entry_count == %u\n",(unsigned int)
                    value_ptr->time_entry_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->time_entry_count; i++)
        {
            if (!SE_ValidTimeEntry(&(value_ptr->time_entry_array[i]),
                    print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Time_Entry found at "\
                        "value_ptr->time_entry_array[%u]\n", i);
                }
            }
        } /* end for i */
    }

    if ((result == SE_TRUE) && (value_ptr->time_entry_count > 1))
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; (result == SE_TRUE) &&
             (i < (SE_Integer_Unsigned)(value_ptr->time_entry_count-1)); i++)
        {
            for (j = i+1; (result == SE_TRUE) &&
                 (j < (SE_Integer_Unsigned)value_ptr->time_entry_count); j++)
            {
                if (local_CompareTimeEntry(&(value_ptr->time_entry_array[i]),
                   &(value_ptr->time_entry_array[j]))==0)
                {
                    result = SE_FALSE;
                    if (print_error)
                    {
                        fprintf(f_ptr, "time_entry_array has duplicate"\
                          " entries at %u and %u\n", (unsigned int)i,
                          (unsigned int) j);
                    }
                }
            } /* end for j */
        } /* end for i */
    }
    return result;
} /* end SE_ValidTimeSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTraversalOrder
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTraversalOrder
(
    SE_Traversal_Order value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TRAVORDR_BREADTH_FIRST:
        case SE_TRAVORDR_DEPTH_FIRST:
        case SE_TRAVORDR_MOST_EFFICIENT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTraversalOrder */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidUnmatchedStateBehaviour
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidUnmatchedStateBehaviour
(
    SE_Unmatched_State_Behaviour value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_UNMSTATBEH_NONE:
        case SE_UNMSTATBEH_DEFAULT:
        case SE_UNMSTATBEH_ALL:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidUnmatchedStateBehaviour */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidVolumeExtentEntry
(
    const SE_Volume_Extent_Entry *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidVolumeExtentEntry: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->volume_type)
    {
        case SE_VOLSHAP_CYLINDER:
            if (!SE_ValidCylindricalVolumeExtentEntry(
                      &(value_ptr->volume_extent_data.cylinder), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal"\
                           " SE_Cylindrical_Volume_Extent_Entry value\n");
                }
            }
            break;

        case SE_VOLSHAP_PARALLELEPIPED:
            if (!SE_ValidParallelepipedVolumeExtentEntry(
                      &(value_ptr->volume_extent_data.parallelepiped),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal"\
                           " SE_Parallelepiped_Volume_Extent_Entry"\
                           " value\n");
                }
            }
            break;

        case SE_VOLSHAP_SPHERE:
            temp_fields.tag = SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT;
            memcpy(&(temp_fields.u.Spherical_Volume_Extent),
                   &(value_ptr->volume_extent_data.sphere),
                   sizeof(SE_Spherical_Volume_Extent_Fields));
            result = (SE_Boolean)
                     (result &&
                     SE_ValidDRMClassFields(&temp_fields, print_error,
                 error_count_ptr));
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr) (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Volumetric_Shape value (%d)\n",
                         (int) value_ptr->volume_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVolumeLODEntry
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidVolumeLODEntry
(
    const SE_Volume_LOD_Entry *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_DRM_Class_Fields  temp_fields;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL, *srm_f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
        srm_f_ptr = SRM_GetErrorFilePtr();
        if (SRM_SetErrorFilePtr(f_ptr) != SRM_STATCOD_SUCCESS)
        {
            print_error = SE_FALSE;
        }
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidVolumeLODEntry: NULL value_ptr\n");
        }
        return result;
    }

    if (!SRM_ValidCoordinate(&(value_ptr->coordinate), (SRM_Boolean)
              print_error, (SRM_Integer_Unsigned *) error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SRM_Coordinate value\n");
        }
    }
    if (!SE_ValidVolumeExtentEntry(&(value_ptr->volume_extent), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Volume_Extent_Entry value\n");
        }
    }
    temp_fields.tag = SE_CLS_DRM_VOLUME_LOD_DATA;
    memcpy(&(temp_fields.u.Volume_LOD_Data),
           &(value_ptr->volume_lod),
           sizeof(SE_Volume_LOD_Data_Fields));
    result = (SE_Boolean)
             (result &&
             SE_ValidDRMClassFields(&temp_fields, print_error,
         error_count_ptr));
    if (print_error)
    {
        SRM_SetErrorFilePtr(srm_f_ptr);
    }
    return result;
} /* end SE_ValidVolumeLODEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVolumetricShape
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidVolumetricShape
(
    SE_Volumetric_Shape value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_VOLSHAP_CYLINDER:
        case SE_VOLSHAP_PARALLELEPIPED:
        case SE_VOLSHAP_SPHERE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidVolumetricShape */
