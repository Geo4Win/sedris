/*
 * FILE       : se_extract_print.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains print functions for all SEDRIS Level 0 API types.
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
#include "se_read0.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_Indent
 *
 *    Indent the number of spaces appropriate for the given level.
 *
 * PARAMETERS:
 *
 *   level -- 1/2 the number of spaces to indent
 *
 *   out_file_ptr -- output file to which we're printing
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_Indent
(
    SE_Integer_Unsigned  level,
    FILE                *out_file_ptr
)
{
    SE_Integer_Unsigned i;

    for (i=1; i<level; i++)
        fprintf(out_file_ptr, "  ");
} /* end SE_Indent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAbsoluteTimeIntervalEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintAbsoluteTimeIntervalEntry
(
    const SE_Absolute_Time_Interval_Entry *value_ptr,
    const char                            *name_ptr,
          SE_Integer_Unsigned              level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Absolute_Time_Interval_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->reference_time", name_ptr);
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
        memcpy(&(temp_fields.u.Absolute_Time),
               &(value_ptr->reference_time),
               sizeof(SE_Absolute_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        sprintf(buffer, "%s->absolute_interval", name_ptr);
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL;
        memcpy(&(temp_fields.u.Absolute_Time_Interval),
               &(value_ptr->absolute_interval),
               sizeof(SE_Absolute_Time_Interval_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
    else
    {
        sprintf(buffer, "reference_time");
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
        memcpy(&(temp_fields.u.Absolute_Time),
               &(value_ptr->reference_time),
               sizeof(SE_Absolute_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        sprintf(buffer, "absolute_interval");
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL;
        memcpy(&(temp_fields.u.Absolute_Time_Interval),
               &(value_ptr->absolute_interval),
               sizeof(SE_Absolute_Time_Interval_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
} /* end SE_PrintAbsoluteTimeIntervalEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAlternateHierarchyParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintAlternateHierarchyParameters
(
    const SE_Alternate_Hierarchy_Parameters *value_ptr,
    const char                              *name_ptr,
          SE_Integer_Unsigned                level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Alternate_Hierarchy_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->hierarchy_data_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->hierarchy_data_count));
        if ((value_ptr->hierarchy_data_count > 0) &&
            (value_ptr->hierarchy_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->hierarchy_data_count; i++)
            {
                sprintf(buffer, "%s->hierarchy_data_array[%u]", name_ptr, i);
                temp_fields.tag = SE_CLS_DRM_HIERARCHY_DATA;
                memcpy(&(temp_fields.u.Hierarchy_Data),
                       &(value_ptr->hierarchy_data_array[i]),
                       sizeof(SE_Hierarchy_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "hierarchy_data_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->hierarchy_data_count));
        if ((value_ptr->hierarchy_data_count > 0) &&
            (value_ptr->hierarchy_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->hierarchy_data_count; i++)
            {
                sprintf(buffer, "hierarchy_data_array[%u]", i);
                temp_fields.tag = SE_CLS_DRM_HIERARCHY_DATA;
                memcpy(&(temp_fields.u.Hierarchy_Data),
                       &(value_ptr->hierarchy_data_array[i]),
                       sizeof(SE_Hierarchy_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintAlternateHierarchyParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAnimationRange
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintAnimationRange
(
    const SE_Animation_Range *value_ptr,
    const char               *name_ptr,
          SE_Integer_Unsigned  level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Animation_Range\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->beginning_frame: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->beginning_frame));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ending_frame: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->ending_frame));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "beginning_frame: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->beginning_frame));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ending_frame: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->ending_frame));
    }
} /* end SE_PrintAnimationRange */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAnimationSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintAnimationSelectParameters
(
    const SE_Animation_Select_Parameters *value_ptr,
    const char                           *name_ptr,
          SE_Integer_Unsigned             level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Animation_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ranges_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->ranges_count));
        if ((value_ptr->ranges_count > 0) &&
            (value_ptr->animation_ranges_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->ranges_count; i++)
            {
                sprintf(buffer, "%s->animation_ranges_array[%u]", name_ptr, i);
                SE_PrintAnimationRange(&(value_ptr->animation_ranges_array[i]),
                   buffer, level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ranges_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->ranges_count));
        if ((value_ptr->ranges_count > 0) &&
            (value_ptr->animation_ranges_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->ranges_count; i++)
            {
                sprintf(buffer, "animation_ranges_array[%u]", i);
                SE_PrintAnimationRange(&(value_ptr->animation_ranges_array[i]),
                   buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintAnimationSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAPIFunction
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintAPIFunction
(
    SE_API_Function value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP:
             return "SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP";

        case SE_APIFN_ADD_COMPONENT_RELATIONSHIP:
             return "SE_APIFN_ADD_COMPONENT_RELATIONSHIP";

        case SE_APIFN_ALLOC_DATA_TABLE_DATA:
             return "SE_APIFN_ALLOC_DATA_TABLE_DATA";

        case SE_APIFN_CLONE_OBJECT_HANDLE:
             return "SE_APIFN_CLONE_OBJECT_HANDLE";

        case SE_APIFN_CLOSE_TRANSMITTAL:
             return "SE_APIFN_CLOSE_TRANSMITTAL";

        case SE_APIFN_CREATE_OBJECT:
             return "SE_APIFN_CREATE_OBJECT";

        case SE_APIFN_CREATE_SEARCH_FILTER:
             return "SE_APIFN_CREATE_SEARCH_FILTER";

        case SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY:
             return "SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY";

        case SE_APIFN_CREATE_STORE:
             return "SE_APIFN_CREATE_STORE";

        case SE_APIFN_DETERMINE_SPATIAL_INCLUSION:
             return "SE_APIFN_DETERMINE_SPATIAL_INCLUSION";

        case SE_APIFN_FREE_ITERATOR:
             return "SE_APIFN_FREE_ITERATOR";

        case SE_APIFN_FREE_OBJECT:
             return "SE_APIFN_FREE_OBJECT";

        case SE_APIFN_FREE_PACKED_HIERARCHY:
             return "SE_APIFN_FREE_PACKED_HIERARCHY";

        case SE_APIFN_FREE_REMAINING_OBJECTS_LIST:
             return "SE_APIFN_FREE_REMAINING_OBJECTS_LIST";

        case SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST:
             return "SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST";

        case SE_APIFN_FREE_SEARCH_FILTER:
             return "SE_APIFN_FREE_SEARCH_FILTER";

        case SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY:
             return "SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY";

        case SE_APIFN_FREE_STORE:
             return "SE_APIFN_FREE_STORE";

        case SE_APIFN_FREE_TRANSMITTAL:
             return "SE_APIFN_FREE_TRANSMITTAL";

        case SE_APIFN_GET_AGGREGATE:
             return "SE_APIFN_GET_AGGREGATE";

        case SE_APIFN_GET_ASSOCIATE:
             return "SE_APIFN_GET_ASSOCIATE";

        case SE_APIFN_GET_COLOUR_MODEL:
             return "SE_APIFN_GET_COLOUR_MODEL";

        case SE_APIFN_GET_COMPONENT:
             return "SE_APIFN_GET_COMPONENT";

        case SE_APIFN_GET_CONTEXT_TRANSFORMATION:
             return "SE_APIFN_GET_CONTEXT_TRANSFORMATION";

        case SE_APIFN_GET_DATA_TABLE_DATA:
             return "SE_APIFN_GET_DATA_TABLE_DATA";

        case SE_APIFN_GET_DRM_CLASS:
             return "SE_APIFN_GET_DRM_CLASS";

        case SE_APIFN_GET_ENCODING:
             return "SE_APIFN_GET_ENCODING";

        case SE_APIFN_GET_FIELDS:
             return "SE_APIFN_GET_FIELDS";

        case SE_APIFN_GET_IMAGE_DATA:
             return "SE_APIFN_GET_IMAGE_DATA";

        case SE_APIFN_GET_ITERATION_LENGTH_REMAINING:
             return "SE_APIFN_GET_ITERATION_LENGTH_REMAINING";

        case SE_APIFN_GET_LAST_FUNCTION_STATUS:
             return "SE_APIFN_GET_LAST_FUNCTION_STATUS";

        case SE_APIFN_GET_MESH_FACE_TABLE_DATA:
             return "SE_APIFN_GET_MESH_FACE_TABLE_DATA";

        case SE_APIFN_GET_NEXT_OBJECT:
             return "SE_APIFN_GET_NEXT_OBJECT";

        case SE_APIFN_GET_NTH_ASSOCIATE:
             return "SE_APIFN_GET_NTH_ASSOCIATE";

        case SE_APIFN_GET_NTH_COMPONENT:
             return "SE_APIFN_GET_NTH_COMPONENT";

        case SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT:
             return "SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT";

        case SE_APIFN_GET_OBJECT_FROM_ID_STRING:
             return "SE_APIFN_GET_OBJECT_FROM_ID_STRING";

        case SE_APIFN_GET_OBJECT_ID_STRING:
             return "SE_APIFN_GET_OBJECT_ID_STRING";

        case SE_APIFN_GET_OBJECT_REFERENCE_COUNT:
             return "SE_APIFN_GET_OBJECT_REFERENCE_COUNT";

        case SE_APIFN_GET_PACKED_HIERARCHY:
             return "SE_APIFN_GET_PACKED_HIERARCHY";

        case SE_APIFN_GET_PUBLISHED_LABELS:
             return "SE_APIFN_GET_PUBLISHED_LABELS";

        case SE_APIFN_GET_PUBLISHED_OBJECT_LIST:
             return "SE_APIFN_GET_PUBLISHED_OBJECT_LIST";

        case SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST:
             return "SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST";

        case SE_APIFN_GET_RELATION_COUNTS:
             return "SE_APIFN_GET_RELATION_COUNTS";

        case SE_APIFN_GET_REMAINING_OBJECTS_LIST:
             return "SE_APIFN_GET_REMAINING_OBJECTS_LIST";

        case SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST:
             return "SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST";

        case SE_APIFN_GET_ROOT_OBJECT:
             return "SE_APIFN_GET_ROOT_OBJECT";

        case SE_APIFN_GET_SRF_CONTEXT_INFO:
             return "SE_APIFN_GET_SRF_CONTEXT_INFO";

        case SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT:
             return "SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT";

        case SE_APIFN_GET_TRANSMITTAL_LOCATION:
             return "SE_APIFN_GET_TRANSMITTAL_LOCATION";

        case SE_APIFN_GET_TRANSMITTAL_NAME:
             return "SE_APIFN_GET_TRANSMITTAL_NAME";

        case SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION:
             return "SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION";

        case SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID:
             return "SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID";

        case SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL:
             return "SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL";

        case SE_APIFN_GET_USER_DATA:
             return "SE_APIFN_GET_USER_DATA";

        case SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR:
             return "SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR";

        case SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR:
             return "SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR";

        case SE_APIFN_INITIALIZE_COMPONENT_ITERATOR:
             return "SE_APIFN_INITIALIZE_COMPONENT_ITERATOR";

        case SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR:
             return "SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR";

        case SE_APIFN_IS_ITERATOR_COMPLETE:
             return "SE_APIFN_IS_ITERATOR_COMPLETE";

        case SE_APIFN_OBJECT_IS_PUBLISHED:
             return "SE_APIFN_OBJECT_IS_PUBLISHED";

        case SE_APIFN_OBJECT_IS_RESOLVED:
             return "SE_APIFN_OBJECT_IS_RESOLVED";

        case SE_APIFN_OBJECTS_ARE_SAME:
             return "SE_APIFN_OBJECTS_ARE_SAME";

        case SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION:
             return "SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION";

        case SE_APIFN_OPEN_TRANSMITTAL_BY_NAME:
             return "SE_APIFN_OPEN_TRANSMITTAL_BY_NAME";

        case SE_APIFN_PUBLISH_OBJECT:
             return "SE_APIFN_PUBLISH_OBJECT";

        case SE_APIFN_PUT_DATA_TABLE_DATA:
             return "SE_APIFN_PUT_DATA_TABLE_DATA";

        case SE_APIFN_PUT_FIELDS:
             return "SE_APIFN_PUT_FIELDS";

        case SE_APIFN_PUT_IMAGE_DATA:
             return "SE_APIFN_PUT_IMAGE_DATA";

        case SE_APIFN_PUT_MESH_FACE_TABLE_DATA:
             return "SE_APIFN_PUT_MESH_FACE_TABLE_DATA";

        case SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP:
             return "SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP";

        case SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP:
             return "SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP";

        case SE_APIFN_REMOVE_FROM_TRANSMITTAL:
             return "SE_APIFN_REMOVE_FROM_TRANSMITTAL";

        case SE_APIFN_RESOLVE_OBJECT:
             return "SE_APIFN_RESOLVE_OBJECT";

        case SE_APIFN_RESOLVE_TRANSMITTAL_NAME:
             return "SE_APIFN_RESOLVE_TRANSMITTAL_NAME";

        case SE_APIFN_SET_COLOUR_MODEL:
             return "SE_APIFN_SET_COLOUR_MODEL";

        case SE_APIFN_SET_FIRST_ERROR_MESSAGE:
             return "SE_APIFN_SET_FIRST_ERROR_MESSAGE";

        case SE_APIFN_SET_GENERAL_CALLBACK:
             return "SE_APIFN_SET_GENERAL_CALLBACK";

        case SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION:
             return "SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION";

        case SE_APIFN_SET_ROOT_OBJECT:
             return "SE_APIFN_SET_ROOT_OBJECT";

        case SE_APIFN_SET_SPECIFIC_CALLBACK:
             return "SE_APIFN_SET_SPECIFIC_CALLBACK";

        case SE_APIFN_SET_SECOND_ERROR_MESSAGE:
             return "SE_APIFN_SET_SECOND_ERROR_MESSAGE";

        case SE_APIFN_SET_SRF_CONTEXT_INFO:
             return "SE_APIFN_SET_SRF_CONTEXT_INFO";

        case SE_APIFN_SET_TRANSMITTAL_NAME:
             return "SE_APIFN_SET_TRANSMITTAL_NAME";

        case SE_APIFN_SET_USER_DATA:
             return "SE_APIFN_SET_USER_DATA";

        case SE_APIFN_TRANSMITTALS_ARE_SAME:
             return "SE_APIFN_TRANSMITTALS_ARE_SAME";

        case SE_APIFN_UNPUBLISH_OBJECT:
             return "SE_APIFN_UNPUBLISH_OBJECT";

        case SE_APIFN_USE_DEFAULT_COLOUR_MODEL:
             return "SE_APIFN_USE_DEFAULT_COLOUR_MODEL";

        case SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO:
             return "SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_API_Function VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintAPIFunction */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintBranchRangeMatching
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintBranchRangeMatching
(
    SE_Branch_Range_Matching value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_BRRNGMAT_EXACT:
             return "SE_BRRNGMAT_EXACT";

        case SE_BRRNGMAT_FULL_CONTAINMENT:
             return "SE_BRRNGMAT_FULL_CONTAINMENT";

        case SE_BRRNGMAT_INTERSECTION:
             return "SE_BRRNGMAT_INTERSECTION";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Branch_Range_Matching VALUE"\
                    " (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintBranchRangeMatching */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintClassificationEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintClassificationEntry
(
    const SE_Classification_Entry *value_ptr,
    const char                    *name_ptr,
          SE_Integer_Unsigned      level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Classification_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->class_data", name_ptr);
        temp_fields.tag = SE_CLS_DRM_CLASSIFICATION_DATA;
        memcpy(&(temp_fields.u.Classification_Data),
               &(value_ptr->class_data),
               sizeof(SE_Classification_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->prop_val_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->prop_val_count));
        if ((value_ptr->prop_val_count > 0) && (value_ptr->prop_val_array !=
            NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->prop_val_count;
                i++)
            {
                sprintf(buffer, "%s->prop_val_array[%u]", name_ptr, i);
                temp_fields.tag = SE_CLS_DRM_PROPERTY_VALUE;
                memcpy(&(temp_fields.u.Property_Value),
                       &(value_ptr->prop_val_array[i]),
                       sizeof(SE_Property_Value_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
    else
    {
        sprintf(buffer, "class_data");
        temp_fields.tag = SE_CLS_DRM_CLASSIFICATION_DATA;
        memcpy(&(temp_fields.u.Classification_Data),
               &(value_ptr->class_data),
               sizeof(SE_Classification_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "prop_val_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->prop_val_count));
        if ((value_ptr->prop_val_count > 0) && (value_ptr->prop_val_array !=
            NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->prop_val_count;
                i++)
            {
                sprintf(buffer, "prop_val_array[%u]", i);
                temp_fields.tag = SE_CLS_DRM_PROPERTY_VALUE;
                memcpy(&(temp_fields.u.Property_Value),
                       &(value_ptr->prop_val_array[i]),
                       sizeof(SE_Property_Value_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintClassificationEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintClassificationParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintClassificationParameters
(
    const SE_Classification_Parameters *value_ptr,
    const char                         *name_ptr,
          SE_Integer_Unsigned           level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Classification_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->classification_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->classification_count));
        if ((value_ptr->classification_count > 0) &&
            (value_ptr->classification_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->classification_count; i++)
            {
                sprintf(buffer, "%s->classification_array[%u]", name_ptr, i);
                SE_PrintClassificationEntry
                   (&(value_ptr->classification_array[i]), buffer, level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "classification_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->classification_count));
        if ((value_ptr->classification_count > 0) &&
            (value_ptr->classification_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->classification_count; i++)
            {
                sprintf(buffer, "classification_array[%u]", i);
                SE_PrintClassificationEntry
                   (&(value_ptr->classification_array[i]), buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintClassificationParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintContinuousLODSelectChoice
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintContinuousLODSelectChoice
(
    SE_Continuous_LOD_Select_Choice value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_CLOD_ALL:
             return "SE_CLOD_ALL";

        case SE_CLOD_LEAST_DETAILED:
             return "SE_CLOD_LEAST_DETAILED";

        case SE_CLOD_MOST_DETAILED:
             return "SE_CLOD_MOST_DETAILED";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Continuous_LOD_Select_Choice"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintContinuousLODSelectChoice */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintContinuousLODSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintContinuousLODSelectParameters
(
    const SE_Continuous_LOD_Select_Parameters *value_ptr,
    const char                                *name_ptr,
          SE_Integer_Unsigned                  level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SE_Continuous_LOD_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->clod_choice: %s\n", name_ptr,
                SE_PrintContinuousLODSelectChoice(value_ptr->clod_choice));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "clod_choice: %s\n",
                SE_PrintContinuousLODSelectChoice(value_ptr->clod_choice));
    }
} /* end SE_PrintContinuousLODSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCylindricalVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintCylindricalVolumeExtentEntry
(
    const SE_Cylindrical_Volume_Extent_Entry *value_ptr,
    const char                               *name_ptr,
          SE_Integer_Unsigned                 level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SE_Cylindrical_Volume_Extent_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->cylinder", name_ptr);
        temp_fields.tag = SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT;
        memcpy(&(temp_fields.u.Cylindrical_Volume_Extent),
               &(value_ptr->cylinder),
               sizeof(SE_Cylindrical_Volume_Extent_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        for (i = 0; i < 2; i++)
        {
            sprintf(buffer, "%s->reference_vectors[%u]", name_ptr, i);
            temp_fields.tag = SE_CLS_DRM_REFERENCE_VECTOR;
            memcpy(&(temp_fields.u.Reference_Vector),
                   &(value_ptr->reference_vectors[i]),
                   sizeof(SE_Reference_Vector_Fields));
            SE_PrintDRMClassFields( &temp_fields, buffer, level);
        } /* end for i */
    }
    else
    {
        sprintf(buffer, "cylinder");
        temp_fields.tag = SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT;
        memcpy(&(temp_fields.u.Cylindrical_Volume_Extent),
               &(value_ptr->cylinder),
               sizeof(SE_Cylindrical_Volume_Extent_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        for (i = 0; i < 2; i++)
        {
            sprintf(buffer, "reference_vectors[%u]", i);
            temp_fields.tag = SE_CLS_DRM_REFERENCE_VECTOR;
            memcpy(&(temp_fields.u.Reference_Vector),
                   &(value_ptr->reference_vectors[i]),
                   sizeof(SE_Reference_Vector_Fields));
            SE_PrintDRMClassFields( &temp_fields, buffer, level);
        } /* end for i */
    }
} /* end SE_PrintCylindricalVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDataTableSubExtent
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintDataTableSubExtent
(
    const SE_Data_Table_Sub_Extent *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Data_Table_Sub_Extent\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->axes_count: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->axes_count));
        if ((value_ptr->axes_count > 0) && (value_ptr->axes_bounds != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->axes_count; i++)
            {
                sprintf(buffer, "%s->axes_bounds[%u]", name_ptr, i);
                SE_PrintIndexRange(&(value_ptr->axes_bounds[i]), buffer,
                   level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "axes_count: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->axes_count));
        if ((value_ptr->axes_count > 0) && (value_ptr->axes_bounds != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->axes_count; i++)
            {
                sprintf(buffer, "axes_bounds[%u]", i);
                SE_PrintIndexRange(&(value_ptr->axes_bounds[i]), buffer,
                   level);
            } /* end for i */
        }
    }
} /* end SE_PrintDataTableSubExtent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintEncoding
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintEncoding
(
    SE_Encoding value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_ENCODING_STF:
             return "SE_ENCODING_STF";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Encoding VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintEncoding */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGeneralHierarchyOrder
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintGeneralHierarchyOrder
(
    const SE_General_Hierarchy_Order *value_ptr,
    const char                       *name_ptr,
          SE_Integer_Unsigned         level
)
{
    FILE *f_ptr;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_General_Hierarchy_Order\n");
        return;
    }
    if (name_ptr)
    {
    if (value_ptr->member.Alternate_Hierarchy)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Alternate_Hierarchy\n", name_ptr);
    }
    if (value_ptr->member.Classification_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Classification_Related\n", name_ptr);
    }
    if (value_ptr->member.LOD_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.LOD_Related\n", name_ptr);
    }
    if (value_ptr->member.Octant_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Octant_Related\n", name_ptr);
    }
    if (value_ptr->member.Quadrant_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Quadrant_Related\n", name_ptr);
    }
    if (value_ptr->member.Separating_Plane)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Separating_Plane\n", name_ptr);
    }
    if (value_ptr->member.Spatial_Index_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Spatial_Index_Related\n", name_ptr);
    }
    if (value_ptr->member.State_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.State_Related\n", name_ptr);
    }
    if (value_ptr->member.Time_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->member.Time_Related\n", name_ptr);
    }
    }
    else
    {
    if (value_ptr->member.Alternate_Hierarchy)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Alternate_Hierarchy\n");
    }
    if (value_ptr->member.Classification_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Classification_Related\n");
    }
    if (value_ptr->member.LOD_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.LOD_Related\n");
    }
    if (value_ptr->member.Octant_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Octant_Related\n");
    }
    if (value_ptr->member.Quadrant_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Quadrant_Related\n");
    }
    if (value_ptr->member.Separating_Plane)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Separating_Plane\n");
    }
    if (value_ptr->member.Spatial_Index_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Spatial_Index_Related\n");
    }
    if (value_ptr->member.State_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.State_Related\n");
    }
    if (value_ptr->member.Time_Related)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "member.Time_Related\n");
    }
    }
} /* end SE_PrintGeneralHierarchyOrder */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGeneralHierarchySelect
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintGeneralHierarchySelect
(
    const SE_General_Hierarchy_Select *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_General_Hierarchy_Select\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->alternate_hierarchy: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->alternate_hierarchy));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->animation_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->animation_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->classification_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->classification_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->continuous_lod_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->continuous_lod_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->octant_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->octant_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->quadrant_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->quadrant_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->separating_plane: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->separating_plane));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->spatial_index_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->spatial_index_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->state_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->state_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_related: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->lod_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_distance_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->lod_distance_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_index_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->lod_index_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_map_scale_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->lod_map_scale_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_spatial_resolution_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->lod_spatial_resolution_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_volume_related: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->lod_volume_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_related: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->time_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_related_by_season: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_season));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_related_by_time_interval: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_time_interval));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_related_by_time_of_day: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_time_of_day));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_related_by_time_point: %s\n", name_ptr,
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_time_point));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->perimeter_related: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->perimeter_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->union_of_features: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->union_of_features));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->union_of_geometry_hierarchies: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->union_of_geometry_hierarchies));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->union_of_geometry_primitives: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->union_of_geometry_primitives));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "alternate_hierarchy: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->alternate_hierarchy));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "animation_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->animation_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "classification_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->classification_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "continuous_lod_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->continuous_lod_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "octant_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->octant_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "quadrant_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->quadrant_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "separating_plane: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->separating_plane));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "spatial_index_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->spatial_index_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "state_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->state_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_related: %s\n",
                SE_PrintBoolean(value_ptr->lod_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_distance_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->lod_distance_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_index_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->lod_index_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_map_scale_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->lod_map_scale_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_spatial_resolution_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->lod_spatial_resolution_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_volume_related: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->lod_volume_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_related: %s\n",
                SE_PrintBoolean(value_ptr->time_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_related_by_season: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_season));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_related_by_time_interval: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_time_interval));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_related_by_time_of_day: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_time_of_day));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_related_by_time_point: %s\n",
                SE_PrintHierarchyInclusion(value_ptr->time_related_by_time_point));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "perimeter_related: %s\n",
                SE_PrintBoolean(value_ptr->perimeter_related));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "union_of_features: %s\n",
                SE_PrintBoolean(value_ptr->union_of_features));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "union_of_geometry_hierarchies: %s\n",
                SE_PrintBoolean(value_ptr->union_of_geometry_hierarchies));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "union_of_geometry_primitives: %s\n",
                SE_PrintBoolean(value_ptr->union_of_geometry_primitives));
    }
} /* end SE_PrintGeneralHierarchySelect */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHierarchyInclusion
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintHierarchyInclusion
(
    SE_Hierarchy_Inclusion value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_HIERINC_EXCLUDE_ALL:
             return "SE_HIERINC_EXCLUDE_ALL";

        case SE_HIERINC_INCLUDE_ALL:
             return "SE_HIERINC_INCLUDE_ALL";

        case SE_HIERINC_EVALUATE_RULES:
             return "SE_HIERINC_EVALUATE_RULES";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Hierarchy_Inclusion VALUE"\
                    " (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintHierarchyInclusion */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHierarchyOrderParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintHierarchyOrderParameters
(
    const SE_Hierarchy_Order_Parameters *value_ptr,
    const char                          *name_ptr,
          SE_Integer_Unsigned            level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Hierarchy_Order_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->general_hierarchy_mask", name_ptr);
        SE_PrintGeneralHierarchyOrder(&(value_ptr->general_hierarchy_mask),
          buffer, level);
        sprintf(buffer, "%s->alternate_hierarchy_traversal_order", name_ptr);
        SE_PrintAlternateHierarchyParameters(&(value_ptr->alternate_hierarchy_traversal_order),
          buffer, level);
        sprintf(buffer, "%s->classification_traversal_order", name_ptr);
        SE_PrintClassificationParameters(&(value_ptr->classification_traversal_order),
          buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_traversal_order: %s\n", name_ptr,
                SE_PrintSiblingTraversalOrder(value_ptr->lod_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->octant_traversal_order: %s\n", name_ptr,
                SE_PrintSiblingTraversalOrder(value_ptr->octant_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->quadrant_traversal_order: %s\n", name_ptr,
                SE_PrintSiblingTraversalOrder(value_ptr->quadrant_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->separating_plane_traversal_order: %s\n", name_ptr,
                SE_PrintSiblingTraversalOrder(value_ptr->separating_plane_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->spatial_index_general_traversal_order: %s\n",
                name_ptr,
                SE_PrintSiblingTraversalOrder(value_ptr->spatial_index_general_traversal_order));
        sprintf(buffer, "%s->state_traversal_order", name_ptr);
        temp_fields.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields.u.State_Data),
               &(value_ptr->state_traversal_order),
               sizeof(SE_State_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_traversal_order: %s\n", name_ptr,
                SE_PrintSiblingTraversalOrder(value_ptr->time_traversal_order));
    }
    else
    {
        sprintf(buffer, "general_hierarchy_mask");
        SE_PrintGeneralHierarchyOrder(&(value_ptr->general_hierarchy_mask),
          buffer, level);
        sprintf(buffer, "alternate_hierarchy_traversal_order");
        SE_PrintAlternateHierarchyParameters(&(value_ptr->alternate_hierarchy_traversal_order),
          buffer, level);
        sprintf(buffer, "classification_traversal_order");
        SE_PrintClassificationParameters(&(value_ptr->classification_traversal_order),
          buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_traversal_order: %s\n",
                SE_PrintSiblingTraversalOrder(value_ptr->lod_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "octant_traversal_order: %s\n",
                SE_PrintSiblingTraversalOrder(value_ptr->octant_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "quadrant_traversal_order: %s\n",
                SE_PrintSiblingTraversalOrder(value_ptr->quadrant_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "separating_plane_traversal_order: %s\n",
                SE_PrintSiblingTraversalOrder(value_ptr->separating_plane_traversal_order));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "spatial_index_general_traversal_order: %s\n",
                SE_PrintSiblingTraversalOrder(value_ptr->spatial_index_general_traversal_order));
        sprintf(buffer, "state_traversal_order");
        temp_fields.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields.u.State_Data),
               &(value_ptr->state_traversal_order),
               sizeof(SE_State_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_traversal_order: %s\n",
                SE_PrintSiblingTraversalOrder(value_ptr->time_traversal_order));
    }
} /* end SE_PrintHierarchyOrderParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHierarchySelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintHierarchySelectParameters
(
    const SE_Hierarchy_Select_Parameters *value_ptr,
    const char                           *name_ptr,
          SE_Integer_Unsigned             level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Hierarchy_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->general_hierarchy_mask", name_ptr);
        SE_PrintGeneralHierarchySelect(&(value_ptr->general_hierarchy_mask),
          buffer, level);
        sprintf(buffer, "%s->alternate_hierarchy_branches", name_ptr);
        SE_PrintAlternateHierarchyParameters(&(value_ptr->alternate_hierarchy_branches),
          buffer, level);
        sprintf(buffer, "%s->animation_branches", name_ptr);
        SE_PrintAnimationSelectParameters(&(value_ptr->animation_branches),
          buffer, level);
        sprintf(buffer, "%s->classification_branches", name_ptr);
        SE_PrintClassificationParameters(&(value_ptr->classification_branches),
          buffer, level);
        sprintf(buffer, "%s->continuous_lod_branches", name_ptr);
        SE_PrintContinuousLODSelectParameters(&(value_ptr->continuous_lod_branches),
          buffer, level);
        sprintf(buffer, "%s->lod_branches", name_ptr);
        SE_PrintLODSelectParameters(&(value_ptr->lod_branches), buffer, level);
        sprintf(buffer, "%s->octant_branches", name_ptr);
        SE_PrintOctantSelectParameters(&(value_ptr->octant_branches), buffer,
          level);
        sprintf(buffer, "%s->quadrant_branches", name_ptr);
        SE_PrintQuadrantSelectParameters(&(value_ptr->quadrant_branches),
          buffer, level);
        sprintf(buffer, "%s->separating_plane_branches", name_ptr);
        SE_PrintSeparatingPlaneSelectParameters(&(value_ptr->separating_plane_branches),
          buffer, level);
        sprintf(buffer, "%s->spatial_index_branches", name_ptr);
        SE_PrintSpatialIndexParameters(&(value_ptr->spatial_index_branches),
          buffer, level);
        sprintf(buffer, "%s->state_branches", name_ptr);
        SE_PrintStateSelectParameters(&(value_ptr->state_branches), buffer,
          level);
        sprintf(buffer, "%s->time_branches", name_ptr);
        SE_PrintTimeSelectParameters(&(value_ptr->time_branches), buffer,
          level);
    }
    else
    {
        sprintf(buffer, "general_hierarchy_mask");
        SE_PrintGeneralHierarchySelect(&(value_ptr->general_hierarchy_mask),
          buffer, level);
        sprintf(buffer, "alternate_hierarchy_branches");
        SE_PrintAlternateHierarchyParameters(&(value_ptr->alternate_hierarchy_branches),
          buffer, level);
        sprintf(buffer, "animation_branches");
        SE_PrintAnimationSelectParameters(&(value_ptr->animation_branches),
          buffer, level);
        sprintf(buffer, "classification_branches");
        SE_PrintClassificationParameters(&(value_ptr->classification_branches),
          buffer, level);
        sprintf(buffer, "continuous_lod_branches");
        SE_PrintContinuousLODSelectParameters(&(value_ptr->continuous_lod_branches),
          buffer, level);
        sprintf(buffer, "lod_branches");
        SE_PrintLODSelectParameters(&(value_ptr->lod_branches), buffer, level);
        sprintf(buffer, "octant_branches");
        SE_PrintOctantSelectParameters(&(value_ptr->octant_branches), buffer,
          level);
        sprintf(buffer, "quadrant_branches");
        SE_PrintQuadrantSelectParameters(&(value_ptr->quadrant_branches),
          buffer, level);
        sprintf(buffer, "separating_plane_branches");
        SE_PrintSeparatingPlaneSelectParameters(&(value_ptr->separating_plane_branches),
          buffer, level);
        sprintf(buffer, "spatial_index_branches");
        SE_PrintSpatialIndexParameters(&(value_ptr->spatial_index_branches),
          buffer, level);
        sprintf(buffer, "state_branches");
        SE_PrintStateSelectParameters(&(value_ptr->state_branches), buffer,
          level);
        sprintf(buffer, "time_branches");
        SE_PrintTimeSelectParameters(&(value_ptr->time_branches), buffer,
          level);
    }
} /* end SE_PrintHierarchySelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageData
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintImageData
(
    const SE_Image_Data *value_ptr,
    const char          *name_ptr,
          SE_Integer_Unsigned  level
)
{
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Image_Data\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->data_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->data_count));
        if ((value_ptr->data_count > 0) && (value_ptr->data != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->data_count; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->data[%u]: %s\n", name_ptr, i, SE_PrintOctet
                        (value_ptr->data[i]));
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "data_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->data_count));
        if ((value_ptr->data_count > 0) && (value_ptr->data != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->data_count; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "data[%u]: %s\n", i, SE_PrintOctet
                        (value_ptr->data[i]));
            } /* end for i */
        }
    }
} /* end SE_PrintImageData */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageTexelLocation3D
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintImageTexelLocation3D
(
    const SE_Image_Texel_Location_3D *value_ptr,
    const char                       *name_ptr,
          SE_Integer_Unsigned         level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Image_Texel_Location_3D\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->horizontal: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->horizontal));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->vertical: %s\n", name_ptr, SE_PrintIntegerUnsigned
                (value_ptr->vertical));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->z: %s\n", name_ptr, SE_PrintIntegerUnsigned
                (value_ptr->z));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "horizontal: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->horizontal));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "vertical: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->vertical));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "z: %s\n", SE_PrintIntegerUnsigned(value_ptr->z));
    }
} /* end SE_PrintImageTexelLocation3D */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIndexRange
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintIndexRange
(
    const SE_Index_Range *value_ptr,
    const char           *name_ptr,
          SE_Integer_Unsigned  level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Index_Range\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->first_index: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->first_index));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->last_index: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->last_index));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "first_index: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->first_index));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "last_index: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->last_index));
    }
} /* end SE_PrintIndexRange */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintITRBehaviour
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintITRBehaviour
(
    SE_ITR_Behaviour value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_ITRBEH_RESOLVE:
             return "SE_ITRBEH_RESOLVE";

        case SE_ITRBEH_REPORT:
             return "SE_ITRBEH_REPORT";

        case SE_ITRBEH_IGNORE:
             return "SE_ITRBEH_IGNORE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_ITR_Behaviour VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintITRBehaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLODEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintLODEntry
(
    const SE_LOD_Entry *value_ptr,
    const char         *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_LOD_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_entry_type: %s\n", name_ptr,
                SE_PrintLODDataType(value_ptr->lod_entry_type));
        switch (value_ptr->lod_entry_type)
        {
            case SE_LODDATTYP_DISTANCE:
                sprintf(buffer, "%s->lod.distance", name_ptr);
                temp_fields.tag = SE_CLS_DRM_DISTANCE_LOD_DATA;
                memcpy(&(temp_fields.u.Distance_LOD_Data),
                       &(value_ptr->lod.distance),
                       sizeof(SE_Distance_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_LODDATTYP_INDEX:
                sprintf(buffer, "%s->lod.index", name_ptr);
                temp_fields.tag = SE_CLS_DRM_INDEX_LOD_DATA;
                memcpy(&(temp_fields.u.Index_LOD_Data),
                       &(value_ptr->lod.index),
                       sizeof(SE_Index_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_LODDATTYP_MAP_SCALE:
                sprintf(buffer, "%s->lod.map_scale", name_ptr);
                temp_fields.tag = SE_CLS_DRM_MAP_SCALE_LOD_DATA;
                memcpy(&(temp_fields.u.Map_Scale_LOD_Data),
                       &(value_ptr->lod.map_scale),
                       sizeof(SE_Map_Scale_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_LODDATTYP_VOLUME:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->lod.volume", name_ptr);
                SE_PrintVolumeLODEntry(&(value_ptr->lod.volume), buffer,
                  level);
                break;

            case SE_LODDATTYP_SPATIAL_RESOLUTION:
                sprintf(buffer, "%s->lod.spatial_resolution", name_ptr);
                temp_fields.tag = SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA;
                memcpy(&(temp_fields.u.Spatial_Resolution_LOD_Data),
                       &(value_ptr->lod.spatial_resolution),
                       sizeof(SE_Spatial_Resolution_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_entry_type: %s\n",
                SE_PrintLODDataType(value_ptr->lod_entry_type));
        switch (value_ptr->lod_entry_type)
        {
            case SE_LODDATTYP_DISTANCE:
                sprintf(buffer, "lod.distance");
                temp_fields.tag = SE_CLS_DRM_DISTANCE_LOD_DATA;
                memcpy(&(temp_fields.u.Distance_LOD_Data),
                       &(value_ptr->lod.distance),
                       sizeof(SE_Distance_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_LODDATTYP_INDEX:
                sprintf(buffer, "lod.index");
                temp_fields.tag = SE_CLS_DRM_INDEX_LOD_DATA;
                memcpy(&(temp_fields.u.Index_LOD_Data),
                       &(value_ptr->lod.index),
                       sizeof(SE_Index_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_LODDATTYP_MAP_SCALE:
                sprintf(buffer, "lod.map_scale");
                temp_fields.tag = SE_CLS_DRM_MAP_SCALE_LOD_DATA;
                memcpy(&(temp_fields.u.Map_Scale_LOD_Data),
                       &(value_ptr->lod.map_scale),
                       sizeof(SE_Map_Scale_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_LODDATTYP_VOLUME:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "lod.volume");
                SE_PrintVolumeLODEntry(&(value_ptr->lod.volume), buffer,
                  level);
                break;

            case SE_LODDATTYP_SPATIAL_RESOLUTION:
                sprintf(buffer, "lod.spatial_resolution");
                temp_fields.tag = SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA;
                memcpy(&(temp_fields.u.Spatial_Resolution_LOD_Data),
                       &(value_ptr->lod.spatial_resolution),
                       sizeof(SE_Spatial_Resolution_LOD_Data_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

        } /* end switch */
    }
} /* end SE_PrintLODEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLODSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintLODSelectParameters
(
    const SE_LOD_Select_Parameters *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_LOD_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->matching_rules: %s\n", name_ptr,
                SE_PrintBranchRangeMatching(value_ptr->matching_rules));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lod_entry_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->lod_entry_count));
        if ((value_ptr->lod_entry_count > 0) && (value_ptr->lod_entry_array !=
            NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->lod_entry_count;
                i++)
            {
                sprintf(buffer, "%s->lod_entry_array[%u]", name_ptr, i);
                SE_PrintLODEntry(&(value_ptr->lod_entry_array[i]), buffer,
                   level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "matching_rules: %s\n",
                SE_PrintBranchRangeMatching(value_ptr->matching_rules));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lod_entry_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->lod_entry_count));
        if ((value_ptr->lod_entry_count > 0) && (value_ptr->lod_entry_array !=
            NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->lod_entry_count;
                i++)
            {
                sprintf(buffer, "lod_entry_array[%u]", i);
                SE_PrintLODEntry(&(value_ptr->lod_entry_array[i]), buffer,
                   level);
            } /* end for i */
        }
    }
} /* end SE_PrintLODSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintObjectInclusion
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintObjectInclusion
(
    SE_Object_Inclusion value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_OBJINCL_FULLY_INCLUDED:
             return "SE_OBJINCL_FULLY_INCLUDED";

        case SE_OBJINCL_PARTIALLY_INCLUDED:
             return "SE_OBJINCL_PARTIALLY_INCLUDED";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Object_Inclusion VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintObjectInclusion */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintOctantSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintOctantSelectParameters
(
    const SE_Octant_Select_Parameters *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Octant_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->octant_data_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->octant_data_count));
        if ((value_ptr->octant_data_count > 0) &&
            (value_ptr->octant_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->octant_data_count; i++)
            {
                sprintf(buffer, "%s->octant_data_array[%u]", name_ptr, i);
                temp_fields.tag = SE_CLS_DRM_OCTANT_DATA;
                memcpy(&(temp_fields.u.Octant_Data),
                       &(value_ptr->octant_data_array[i]),
                       sizeof(SE_Octant_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "octant_data_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->octant_data_count));
        if ((value_ptr->octant_data_count > 0) &&
            (value_ptr->octant_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->octant_data_count; i++)
            {
                sprintf(buffer, "octant_data_array[%u]", i);
                temp_fields.tag = SE_CLS_DRM_OCTANT_DATA;
                memcpy(&(temp_fields.u.Octant_Data),
                       &(value_ptr->octant_data_array[i]),
                       sizeof(SE_Octant_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintOctantSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintParallelepipedVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintParallelepipedVolumeExtentEntry
(
    const SE_Parallelepiped_Volume_Extent_Entry *value_ptr,
    const char                                  *name_ptr,
          SE_Integer_Unsigned                    level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SE_Parallelepiped_Volume_Extent_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->parallelepiped", name_ptr);
        temp_fields.tag = SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT;
        memcpy(&(temp_fields.u.Parallelepiped_Volume_Extent),
               &(value_ptr->parallelepiped),
               sizeof(SE_Parallelepiped_Volume_Extent_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        for (i = 0; i < 3; i++)
        {
            sprintf(buffer, "%s->reference_vectors[%u]", name_ptr, i);
            temp_fields.tag = SE_CLS_DRM_REFERENCE_VECTOR;
            memcpy(&(temp_fields.u.Reference_Vector),
                   &(value_ptr->reference_vectors[i]),
                   sizeof(SE_Reference_Vector_Fields));
            SE_PrintDRMClassFields( &temp_fields, buffer, level);
        } /* end for i */
    }
    else
    {
        sprintf(buffer, "parallelepiped");
        temp_fields.tag = SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT;
        memcpy(&(temp_fields.u.Parallelepiped_Volume_Extent),
               &(value_ptr->parallelepiped),
               sizeof(SE_Parallelepiped_Volume_Extent_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        for (i = 0; i < 3; i++)
        {
            sprintf(buffer, "reference_vectors[%u]", i);
            temp_fields.tag = SE_CLS_DRM_REFERENCE_VECTOR;
            memcpy(&(temp_fields.u.Reference_Vector),
                   &(value_ptr->reference_vectors[i]),
                   sizeof(SE_Reference_Vector_Fields));
            SE_PrintDRMClassFields( &temp_fields, buffer, level);
        } /* end for i */
    }
} /* end SE_PrintParallelepipedVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintQuadrantSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintQuadrantSelectParameters
(
    const SE_Quadrant_Select_Parameters *value_ptr,
    const char                          *name_ptr,
          SE_Integer_Unsigned            level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Quadrant_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->quadrant_data_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->quadrant_data_count));
        if ((value_ptr->quadrant_data_count > 0) &&
            (value_ptr->quadrant_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->quadrant_data_count; i++)
            {
                sprintf(buffer, "%s->quadrant_data_array[%u]", name_ptr, i);
                temp_fields.tag = SE_CLS_DRM_QUADRANT_DATA;
                memcpy(&(temp_fields.u.Quadrant_Data),
                       &(value_ptr->quadrant_data_array[i]),
                       sizeof(SE_Quadrant_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "quadrant_data_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->quadrant_data_count));
        if ((value_ptr->quadrant_data_count > 0) &&
            (value_ptr->quadrant_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->quadrant_data_count; i++)
            {
                sprintf(buffer, "quadrant_data_array[%u]", i);
                temp_fields.tag = SE_CLS_DRM_QUADRANT_DATA;
                memcpy(&(temp_fields.u.Quadrant_Data),
                       &(value_ptr->quadrant_data_array[i]),
                       sizeof(SE_Quadrant_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintQuadrantSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintRelativeToAbsoluteTimeEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintRelativeToAbsoluteTimeEntry
(
    const SE_Relative_To_Absolute_Time_Entry *value_ptr,
    const char                               *name_ptr,
          SE_Integer_Unsigned                 level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SE_Relative_To_Absolute_Time_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->reference_time", name_ptr);
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
        memcpy(&(temp_fields.u.Absolute_Time),
               &(value_ptr->reference_time),
               sizeof(SE_Absolute_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        sprintf(buffer, "%s->relative_time", name_ptr);
        temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME;
        memcpy(&(temp_fields.u.Relative_Time),
               &(value_ptr->relative_time),
               sizeof(SE_Relative_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
    else
    {
        sprintf(buffer, "reference_time");
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
        memcpy(&(temp_fields.u.Absolute_Time),
               &(value_ptr->reference_time),
               sizeof(SE_Absolute_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        sprintf(buffer, "relative_time");
        temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME;
        memcpy(&(temp_fields.u.Relative_Time),
               &(value_ptr->relative_time),
               sizeof(SE_Relative_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
} /* end SE_PrintRelativeToAbsoluteTimeEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintRelativeToAbsoluteTimeIntervalEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintRelativeToAbsoluteTimeIntervalEntry
(
    const SE_Relative_To_Absolute_Time_Interval_Entry *value_ptr,
    const char                                        *name_ptr,
          SE_Integer_Unsigned                          level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SE_Relative_To_Absolute_Time_Interval_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->reference_time", name_ptr);
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
        memcpy(&(temp_fields.u.Absolute_Time),
               &(value_ptr->reference_time),
               sizeof(SE_Absolute_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        sprintf(buffer, "%s->relative_interval", name_ptr);
        temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
        memcpy(&(temp_fields.u.Relative_Time_Interval),
               &(value_ptr->relative_interval),
               sizeof(SE_Relative_Time_Interval_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
    else
    {
        sprintf(buffer, "reference_time");
        temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
        memcpy(&(temp_fields.u.Absolute_Time),
               &(value_ptr->reference_time),
               sizeof(SE_Absolute_Time_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
        sprintf(buffer, "relative_interval");
        temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
        memcpy(&(temp_fields.u.Relative_Time_Interval),
               &(value_ptr->relative_interval),
               sizeof(SE_Relative_Time_Interval_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
} /* end SE_PrintRelativeToAbsoluteTimeIntervalEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintReturnCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintReturnCode
(
    SE_Return_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_RETCOD_FAILURE:
             return "SE_RETCOD_FAILURE";

        case SE_RETCOD_SUCCESS:
             return "SE_RETCOD_SUCCESS";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Return_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintReturnCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchBounds
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintSearchBounds
(
    const SE_Search_Bounds *value_ptr,
    const char             *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL, *srm_f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        srm_f_ptr = SRM_GetOutFilePtr();
        if (SRM_SetOutFilePtr(f_ptr) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr, "ERROR in SE_PrintSearchBounds: "\
                    "SRM_SetOutFilePtr failed\n");
            fflush(stderr);
            return;
        }
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Search_Bounds\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->minimum_point", name_ptr);
        SRM_PrintCoordinate(&(value_ptr->minimum_point), buffer, level);
        sprintf(buffer, "%s->maximum_point", name_ptr);
        SRM_PrintCoordinate(&(value_ptr->maximum_point), buffer, level);
    }
    else
    {
        sprintf(buffer, "minimum_point");
        SRM_PrintCoordinate(&(value_ptr->minimum_point), buffer, level);
        sprintf(buffer, "maximum_point");
        SRM_PrintCoordinate(&(value_ptr->maximum_point), buffer, level);
    }
        if (SRM_SetOutFilePtr(srm_f_ptr) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr, "ERROR in SE_PrintSearchBounds: "\
                    "SRM_SetOutFilePtr failed reset\n");
            fflush(stderr);
        }
} /* end SE_PrintSearchBounds */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchBoundsClosure
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintSearchBoundsClosure
(
    SE_Search_Bounds_Closure value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_SEARCHBNDSCLS_FULLY_CLOSED:
             return "SE_SEARCHBNDSCLS_FULLY_CLOSED";

        case SE_SEARCHBNDSCLS_PARTIALLY_CLOSED:
             return "SE_SEARCHBNDSCLS_PARTIALLY_CLOSED";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Search_Bounds_Closure VALUE"\
                    " (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintSearchBoundsClosure */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchDimension
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintSearchDimension
(
    SE_Search_Dimension value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE:
             return "SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE";

        case SE_SEARCHDIM_THREE_DIMENSIONAL:
             return "SE_SEARCHDIM_THREE_DIMENSIONAL";

        case SE_SEARCHDIM_ALL_DIMENSIONS:
             return "SE_SEARCHDIM_ALL_DIMENSIONS";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Search_Dimension VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintSearchDimension */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSingleSearchRule
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_PrintSingleSearchRule
(
    const SE_Search_Rule      *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level,
          FILE                *f_ptr
)
{
    SE_Indent(level, f_ptr);

    switch (value_ptr->rule_type)
    {
        case SE_SEARCHRULETYP_END:
        case SE_SEARCHRULETYP_AND:
        case SE_SEARCHRULETYP_OR:
        case SE_SEARCHRULETYP_NOT:
        case SE_SEARCHRULETYP_OBJECT_AND:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             break;

        case SE_SEARCHRULETYP_PREDICATE:
             fprintf(f_ptr, "%s = SE_PREDICATE_MATCH(%p, %p)\n", name_ptr,
                     value_ptr->user_function, value_ptr->value_ptr);
             break;

        case SE_SEARCHRULETYP_ASSOCIATE:
        case SE_SEARCHRULETYP_DRM_CLASS:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             break;

        case SE_SEARCHRULETYP_FIELD:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%sfield_offset = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned(value_ptr->field_offset));
             fprintf(f_ptr, "%svalue_ptr = %p\n", name_ptr,
                     value_ptr->value_ptr);
             fprintf(f_ptr, "%svalue_type = %s\n", name_ptr,
                     SE_PrintSearchValueType(value_ptr->value_type));
             break;

        case SE_SEARCHRULETYP_FIELD_RANGE:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%sfield_offset = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned(value_ptr->field_offset));
             fprintf(f_ptr, "%svalue_ptr = %p\n", name_ptr,
                     value_ptr->value_ptr);
             fprintf(f_ptr, "%ssecond_value_ptr = %p\n", name_ptr,
                     value_ptr->second_value_ptr);
             fprintf(f_ptr, "%svalue_type = %s\n", name_ptr,
                     SE_PrintSearchValueType(value_ptr->value_type));
             break;

        case SE_SEARCHRULETYP_FIELD_ARRAY:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%sfield_offset = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned(value_ptr->field_offset));
             fprintf(f_ptr, "%svalue_ptr = %p\n", name_ptr,
                     value_ptr->value_ptr);
             fprintf(f_ptr, "%svalue_type = %s\n", name_ptr,
                     SE_PrintSearchValueType(value_ptr->value_type));
             fprintf(f_ptr, "%svalue_array_length = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned
                     (value_ptr->value_array_length));
             break;

        case SE_SEARCHRULETYP_COMPONENT:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%scomponent_object_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->component_object_drm_class));
             break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%scomponent_object_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->component_object_drm_class));
             fprintf(f_ptr, "%sfield_offset = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned(value_ptr->field_offset));
             fprintf(f_ptr, "%svalue_ptr = %p\n", name_ptr,
                     value_ptr->value_ptr);
             fprintf(f_ptr, "%svalue_type = %s\n", name_ptr,
                     SE_PrintSearchValueType(value_ptr->value_type));
             break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%scomponent_object_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->component_object_drm_class));
             fprintf(f_ptr, "%sfield_offset = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned(value_ptr->field_offset));
             fprintf(f_ptr, "%svalue_ptr = %p\n", name_ptr,
                     value_ptr->value_ptr);
             fprintf(f_ptr, "%ssecond_value_ptr = %p\n", name_ptr,
                     value_ptr->second_value_ptr);
             fprintf(f_ptr, "%svalue_type = %s\n", name_ptr,
                     SE_PrintSearchValueType(value_ptr->value_type));
             break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
             fprintf(f_ptr, "%srule_type = %s\n", name_ptr,
                     SE_PrintSearchRuleType(value_ptr->rule_type));
             fprintf(f_ptr, "%sobject_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->object_drm_class));
             fprintf(f_ptr, "%scomponent_object_drm_class = %s\n", name_ptr,
                     SE_PrintDRMClass(value_ptr->component_object_drm_class));
             fprintf(f_ptr, "%sfield_offset = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned(value_ptr->field_offset));
             fprintf(f_ptr, "%svalue_ptr = %p\n", name_ptr,
                     value_ptr->value_ptr);
             fprintf(f_ptr, "%svalue_type = %s\n", name_ptr,
                     SE_PrintSearchValueType(value_ptr->value_type));
             fprintf(f_ptr, "%svalue_array_length = %s\n", name_ptr,
                     SE_PrintShortIntegerUnsigned
                     (value_ptr->value_array_length));
             break;

        case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
             fprintf(f_ptr, "%s = SE_MAX_SEARCH_DEPTH(%s)\n", name_ptr,
                     SE_PrintShortIntegerUnsigned
                     (value_ptr->max_search_depth));
             break;

        default:
            break;
    } /* end switch */
} /* end SE_PrintSingleSearchRule */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchRule
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintSearchRule
(
    const SE_Search_Rule       rules[],
    const char                *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (SE_ValidSearchRule(rules, SE_FALSE, NULL))
    {
        const SE_Search_Rule      *rule_ptr;
              SE_Integer_Unsigned  i = 0;

        for (i = 0, rule_ptr = &(rules[0]);
             rule_ptr->rule_type != SE_SEARCHRULETYP_END;
             i++, rule_ptr = &(rules[i]))
        {
            if (name_ptr)
            {
                sprintf(buffer, "%s[%u]", name_ptr, (unsigned int) i);
                SE_PrintSingleSearchRule(rule_ptr, buffer, level, f_ptr);
            }
            else
            {
                SE_PrintSingleSearchRule(rule_ptr, "", level, f_ptr);
            }
        }
    }
    else
    {
        if (name_ptr)
            fprintf(f_ptr, "%s are invalid, can't print\n", name_ptr);
        else
            fprintf(f_ptr,
                    "Can't print invalid SE_Search_Rule\n");
        return;
    }
} /* end SE_PrintSearchRule */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchRuleType
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintSearchRuleType
(
    SE_Search_Rule_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_SEARCHRULETYP_END:
             return "SE_SEARCHRULETYP_END";

        case SE_SEARCHRULETYP_AND:
             return "SE_SEARCHRULETYP_AND";

        case SE_SEARCHRULETYP_OR:
             return "SE_SEARCHRULETYP_OR";

        case SE_SEARCHRULETYP_NOT:
             return "SE_SEARCHRULETYP_NOT";

        case SE_SEARCHRULETYP_OBJECT_AND:
             return "SE_SEARCHRULETYP_OBJECT_AND";

        case SE_SEARCHRULETYP_PREDICATE:
             return "SE_SEARCHRULETYP_PREDICATE";

        case SE_SEARCHRULETYP_DRM_CLASS:
             return "SE_SEARCHRULETYP_DRM_CLASS";

        case SE_SEARCHRULETYP_FIELD:
             return "SE_SEARCHRULETYP_FIELD";

        case SE_SEARCHRULETYP_FIELD_RANGE:
             return "SE_SEARCHRULETYP_FIELD_RANGE";

        case SE_SEARCHRULETYP_FIELD_ARRAY:
             return "SE_SEARCHRULETYP_FIELD_ARRAY";

        case SE_SEARCHRULETYP_COMPONENT:
             return "SE_SEARCHRULETYP_COMPONENT";

        case SE_SEARCHRULETYP_COMPONENT_FIELD:
             return "SE_SEARCHRULETYP_COMPONENT_FIELD";

        case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
             return "SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE";

        case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
             return "SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY";

        case SE_SEARCHRULETYP_ASSOCIATE:
             return "SE_SEARCHRULETYP_ASSOCIATE";

        case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
             return "SE_SEARCHRULETYP_MAX_SEARCH_DEPTH";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Search_Rule_Type VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintSearchRuleType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchType
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintSearchType
(
    SE_Search_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_SEARCHTYP_POINT:
             return "SE_SEARCHTYP_POINT";

        case SE_SEARCHTYP_BOUNDING_BOX:
             return "SE_SEARCHTYP_BOUNDING_BOX";

        case SE_SEARCHTYP_EXACT:
             return "SE_SEARCHTYP_EXACT";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Search_Type VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintSearchType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchValueType
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintSearchValueType
(
    SE_Search_Value_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_SEARCHVALTYP_BOOLEAN:
             return "SE_SEARCHVALTYP_BOOLEAN";

        case SE_SEARCHVALTYP_BYTE:
             return "SE_SEARCHVALTYP_BYTE";

        case SE_SEARCHVALTYP_BYTE_POSITIVE:
             return "SE_SEARCHVALTYP_BYTE_POSITIVE";

        case SE_SEARCHVALTYP_BYTE_UNSIGNED:
             return "SE_SEARCHVALTYP_BYTE_UNSIGNED";

        case SE_SEARCHVALTYP_ENUMERATED:
             return "SE_SEARCHVALTYP_ENUMERATED";

        case SE_SEARCHVALTYP_FLOAT:
             return "SE_SEARCHVALTYP_FLOAT";

        case SE_SEARCHVALTYP_INTEGER:
             return "SE_SEARCHVALTYP_INTEGER";

        case SE_SEARCHVALTYP_INTEGER_POSITIVE:
             return "SE_SEARCHVALTYP_INTEGER_POSITIVE";

        case SE_SEARCHVALTYP_INTEGER_UNSIGNED:
             return "SE_SEARCHVALTYP_INTEGER_UNSIGNED";

        case SE_SEARCHVALTYP_LONG_FLOAT:
             return "SE_SEARCHVALTYP_LONG_FLOAT";

        case SE_SEARCHVALTYP_SET:
             return "SE_SEARCHVALTYP_SET";

        case SE_SEARCHVALTYP_SHORT_INTEGER:
             return "SE_SEARCHVALTYP_SHORT_INTEGER";

        case SE_SEARCHVALTYP_SHORT_INTEGER_POSITIVE:
             return "SE_SEARCHVALTYP_SHORT_INTEGER_POSITIVE";

        case SE_SEARCHVALTYP_SHORT_INTEGER_UNSIGNED:
             return "SE_SEARCHVALTYP_SHORT_INTEGER_UNSIGNED";

        case SE_SEARCHVALTYP_STRING:
             return "SE_SEARCHVALTYP_STRING";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Search_Value_Type VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintSearchValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSeparatingPlaneSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintSeparatingPlaneSelectParameters
(
    const SE_Separating_Plane_Select_Parameters *value_ptr,
    const char                                  *name_ptr,
          SE_Integer_Unsigned                    level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SE_Separating_Plane_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->traverse_positive_branches: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->traverse_positive_branches));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->traverse_negative_branches: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->traverse_negative_branches));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "traverse_positive_branches: %s\n",
                SE_PrintBoolean(value_ptr->traverse_positive_branches));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "traverse_negative_branches: %s\n",
                SE_PrintBoolean(value_ptr->traverse_negative_branches));
    }
} /* end SE_PrintSeparatingPlaneSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSiblingTraversalOrder
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintSiblingTraversalOrder
(
    SE_Sibling_Traversal_Order value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_SIBTRAV_ASCENDING:
             return "SE_SIBTRAV_ASCENDING";

        case SE_SIBTRAV_DESCENDING:
             return "SE_SIBTRAV_DESCENDING";

        case SE_SIBTRAV_UNSPECIFIED:
             return "SE_SIBTRAV_UNSPECIFIED";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Sibling_Traversal_Order"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintSiblingTraversalOrder */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSpatialIndexParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintSpatialIndexParameters
(
    const SE_Spatial_Index_Parameters *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Spatial_Index_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->spatial_index_data_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->spatial_index_data_count));
        if ((value_ptr->spatial_index_data_count > 0) &&
            (value_ptr->spatial_index_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->spatial_index_data_count; i++)
            {
                sprintf(buffer, "%s->spatial_index_data_array[%u]", name_ptr, i);
                temp_fields.tag = SE_CLS_DRM_SPATIAL_INDEX_DATA;
                memcpy(&(temp_fields.u.Spatial_Index_Data),
                       &(value_ptr->spatial_index_data_array[i]),
                       sizeof(SE_Spatial_Index_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "spatial_index_data_count: %s\n",
                SE_PrintIntegerUnsigned(value_ptr->spatial_index_data_count));
        if ((value_ptr->spatial_index_data_count > 0) &&
            (value_ptr->spatial_index_data_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->spatial_index_data_count; i++)
            {
                sprintf(buffer, "spatial_index_data_array[%u]", i);
                temp_fields.tag = SE_CLS_DRM_SPATIAL_INDEX_DATA;
                memcpy(&(temp_fields.u.Spatial_Index_Data),
                       &(value_ptr->spatial_index_data_array[i]),
                       sizeof(SE_Spatial_Index_Data_Fields));
                SE_PrintDRMClassFields( &temp_fields, buffer, level);
            } /* end for i */
        }
    }
} /* end SE_PrintSpatialIndexParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStateEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintStateEntry
(
    const SE_State_Entry *value_ptr,
    const char           *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_State_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->state_tag: %s\n", name_ptr,
                EDCS_PrintAttributeCode(value_ptr->state_tag));
        sprintf(buffer, "%s->state_data", name_ptr);
        temp_fields.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields.u.State_Data),
               &(value_ptr->state_data),
               sizeof(SE_State_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "state_tag: %s\n",
                EDCS_PrintAttributeCode(value_ptr->state_tag));
        sprintf(buffer, "state_data");
        temp_fields.tag = SE_CLS_DRM_STATE_DATA;
        memcpy(&(temp_fields.u.State_Data),
               &(value_ptr->state_data),
               sizeof(SE_State_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
} /* end SE_PrintStateEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStateSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintStateSelectParameters
(
    const SE_State_Select_Parameters *value_ptr,
    const char                       *name_ptr,
          SE_Integer_Unsigned         level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_State_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->default_choice: %s\n", name_ptr,
                SE_PrintUnmatchedStateBehaviour(value_ptr->default_choice));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->matching_rules: %s\n", name_ptr,
                SE_PrintBranchRangeMatching(value_ptr->matching_rules));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->state_entry_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->state_entry_count));
        if ((value_ptr->state_entry_count > 0) &&
            (value_ptr->state_entry_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->state_entry_count; i++)
            {
                sprintf(buffer, "%s->state_entry_array[%u]", name_ptr, i);
                SE_PrintStateEntry(&(value_ptr->state_entry_array[i]), buffer,
                   level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "default_choice: %s\n",
                SE_PrintUnmatchedStateBehaviour(value_ptr->default_choice));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "matching_rules: %s\n",
                SE_PrintBranchRangeMatching(value_ptr->matching_rules));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "state_entry_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->state_entry_count));
        if ((value_ptr->state_entry_count > 0) &&
            (value_ptr->state_entry_array != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned)
                value_ptr->state_entry_count; i++)
            {
                sprintf(buffer, "state_entry_array[%u]", i);
                SE_PrintStateEntry(&(value_ptr->state_entry_array[i]), buffer,
                   level);
            } /* end for i */
        }
    }
} /* end SE_PrintStateSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStatusCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintStatusCode
(
    SE_Status_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_STATCODE_SUCCESS:
             return "SE_STATCODE_SUCCESS";

        case SE_STATCODE_DELETED_OBJECT:
             return "SE_STATCODE_DELETED_OBJECT";

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return "SE_STATCODE_DIFFERENT_TRANSMITTAL";

        case SE_STATCODE_INVALID_ACCESS_MODE:
             return "SE_STATCODE_INVALID_ACCESS_MODE";

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             return "SE_STATCODE_INVALID_OBJECT_LABEL";

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             return "SE_STATCODE_INVALID_TRANSMITTAL_NAME";

        case SE_STATCODE_NO_OBJECT:
             return "SE_STATCODE_NO_OBJECT";

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             return "SE_STATCODE_SRF_OPERATION_UNSUPPORTED";

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             return "SE_STATCODE_TRANSMITTAL_INACCESSIBLE";

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             return "SE_STATCODE_UNPUBLISHED_OBJECT";

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             return "SE_STATCODE_UNRESOLVED_TRANSMITTAL";

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             return "SE_STATCODE_UNRESOLVED_INPUT_OBJECT";

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             return "SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT";

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             return "SE_STATCODE_UNSUPPORTED_ENCODING";

        case SE_STATCODE_INACTIONABLE_FAILURE:
             return "SE_STATCODE_INACTIONABLE_FAILURE";

        case SE_STATCODE_OUT_OF_MEMORY:
             return "SE_STATCODE_OUT_OF_MEMORY";

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             return "SE_STATCODE_C_ENUMERATION_VALUE_INVALID";

        case SE_STATCODE_C_STORE_INVALID:
             return "SE_STATCODE_C_STORE_INVALID";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Status_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintStatusCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintTimeEntry
(
    const SE_Time_Entry *value_ptr,
    const char          *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Time_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_entry_type: %s\n", name_ptr,
                SE_PrintTimeDataType(value_ptr->time_entry_type));
        switch (value_ptr->time_entry_type)
        {
            case SE_TIMEDATTYP_SEASON:
                sprintf(buffer, "%s->time_data.season", name_ptr);
                temp_fields.tag = SE_CLS_DRM_SEASON;
                memcpy(&(temp_fields.u.Season),
                       &(value_ptr->time_data.season),
                       sizeof(SE_Season_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEDATTYP_TIME_INTERVAL:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->time_data.time_interval", name_ptr);
                SE_PrintTimeIntervalEntry(&(value_ptr->time_data.time_interval),
                  buffer, level);
                break;

            case SE_TIMEDATTYP_TIME_OF_DAY:
                sprintf(buffer, "%s->time_data.time_of_day", name_ptr);
                temp_fields.tag = SE_CLS_DRM_TIME_OF_DAY;
                memcpy(&(temp_fields.u.Time_Of_Day),
                       &(value_ptr->time_data.time_of_day),
                       sizeof(SE_Time_Of_Day_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEDATTYP_TIME_POINT:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->time_data.time_point", name_ptr);
                SE_PrintTimePointEntry(&(value_ptr->time_data.time_point),
                  buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_entry_type: %s\n",
                SE_PrintTimeDataType(value_ptr->time_entry_type));
        switch (value_ptr->time_entry_type)
        {
            case SE_TIMEDATTYP_SEASON:
                sprintf(buffer, "time_data.season");
                temp_fields.tag = SE_CLS_DRM_SEASON;
                memcpy(&(temp_fields.u.Season),
                       &(value_ptr->time_data.season),
                       sizeof(SE_Season_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEDATTYP_TIME_INTERVAL:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "time_data.time_interval");
                SE_PrintTimeIntervalEntry(&(value_ptr->time_data.time_interval),
                  buffer, level);
                break;

            case SE_TIMEDATTYP_TIME_OF_DAY:
                sprintf(buffer, "time_data.time_of_day");
                temp_fields.tag = SE_CLS_DRM_TIME_OF_DAY;
                memcpy(&(temp_fields.u.Time_Of_Day),
                       &(value_ptr->time_data.time_of_day),
                       sizeof(SE_Time_Of_Day_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEDATTYP_TIME_POINT:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "time_data.time_point");
                SE_PrintTimePointEntry(&(value_ptr->time_data.time_point),
                  buffer, level);
                break;

        } /* end switch */
    }
} /* end SE_PrintTimeEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeIntervalEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintTimeIntervalEntry
(
    const SE_Time_Interval_Entry *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Time_Interval_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_type: %s\n", name_ptr,
                SE_PrintTimeMeasurementType(value_ptr->time_type));
        switch (value_ptr->time_type)
        {
            case SE_TIMEMEASTYP_GMT:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->time_interval_data.absolute_time", name_ptr);
                SE_PrintAbsoluteTimeIntervalEntry(&(value_ptr->time_interval_data.absolute_time),
                  buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
                sprintf(buffer, "%s->time_interval_data.relative_to_simulation", name_ptr);
                temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
                memcpy(&(temp_fields.u.Relative_Time_Interval),
                       &(value_ptr->time_interval_data.relative_to_simulation),
                       sizeof(SE_Relative_Time_Interval_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->time_interval_data.relative_to_absolute", name_ptr);
                SE_PrintRelativeToAbsoluteTimeIntervalEntry(&(value_ptr->time_interval_data.relative_to_absolute),
                  buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_type: %s\n",
                SE_PrintTimeMeasurementType(value_ptr->time_type));
        switch (value_ptr->time_type)
        {
            case SE_TIMEMEASTYP_GMT:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "time_interval_data.absolute_time");
                SE_PrintAbsoluteTimeIntervalEntry(&(value_ptr->time_interval_data.absolute_time),
                  buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
                sprintf(buffer, "time_interval_data.relative_to_simulation");
                temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
                memcpy(&(temp_fields.u.Relative_Time_Interval),
                       &(value_ptr->time_interval_data.relative_to_simulation),
                       sizeof(SE_Relative_Time_Interval_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "time_interval_data.relative_to_absolute");
                SE_PrintRelativeToAbsoluteTimeIntervalEntry(&(value_ptr->time_interval_data.relative_to_absolute),
                  buffer, level);
                break;

        } /* end switch */
    }
} /* end SE_PrintTimeIntervalEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeMeasurementType
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintTimeMeasurementType
(
    SE_Time_Measurement_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_TIMEMEASTYP_GMT:
             return "SE_TIMEMEASTYP_GMT";

        case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
             return "SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START";

        case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
             return "SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Time_Measurement_Type VALUE"\
                    " (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintTimeMeasurementType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimePointEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintTimePointEntry
(
    const SE_Time_Point_Entry *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Time_Point_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_type: %s\n", name_ptr,
                SE_PrintTimeMeasurementType(value_ptr->time_type));
        switch (value_ptr->time_type)
        {
            case SE_TIMEMEASTYP_GMT:
                sprintf(buffer, "%s->time_point_data.absolute_time", name_ptr);
                temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
                memcpy(&(temp_fields.u.Absolute_Time),
                       &(value_ptr->time_point_data.absolute_time),
                       sizeof(SE_Absolute_Time_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
                sprintf(buffer, "%s->time_point_data.relative_to_start", name_ptr);
                temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME;
                memcpy(&(temp_fields.u.Relative_Time),
                       &(value_ptr->time_point_data.relative_to_start),
                       sizeof(SE_Relative_Time_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->time_point_data.relative_to_reference", name_ptr);
                SE_PrintRelativeToAbsoluteTimeEntry(&(value_ptr->time_point_data.relative_to_reference),
                  buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_type: %s\n",
                SE_PrintTimeMeasurementType(value_ptr->time_type));
        switch (value_ptr->time_type)
        {
            case SE_TIMEMEASTYP_GMT:
                sprintf(buffer, "time_point_data.absolute_time");
                temp_fields.tag = SE_CLS_DRM_ABSOLUTE_TIME;
                memcpy(&(temp_fields.u.Absolute_Time),
                       &(value_ptr->time_point_data.absolute_time),
                       sizeof(SE_Absolute_Time_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
                sprintf(buffer, "time_point_data.relative_to_start");
                temp_fields.tag = SE_CLS_DRM_RELATIVE_TIME;
                memcpy(&(temp_fields.u.Relative_Time),
                       &(value_ptr->time_point_data.relative_to_start),
                       sizeof(SE_Relative_Time_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

            case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "time_point_data.relative_to_reference");
                SE_PrintRelativeToAbsoluteTimeEntry(&(value_ptr->time_point_data.relative_to_reference),
                  buffer, level);
                break;

        } /* end switch */
    }
} /* end SE_PrintTimePointEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeSelectParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintTimeSelectParameters
(
    const SE_Time_Select_Parameters *value_ptr,
    const char                      *name_ptr,
          SE_Integer_Unsigned        level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Time_Select_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->matching_rules: %s\n", name_ptr,
                SE_PrintBranchRangeMatching(value_ptr->matching_rules));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->time_entry_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->time_entry_count));
        if ((value_ptr->time_entry_count > 0) && (value_ptr->time_entry_array
            != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->time_entry_count;
                i++)
            {
                sprintf(buffer, "%s->time_entry_array[%u]", name_ptr, i);
                SE_PrintTimeEntry(&(value_ptr->time_entry_array[i]), buffer,
                   level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "matching_rules: %s\n",
                SE_PrintBranchRangeMatching(value_ptr->matching_rules));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "time_entry_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->time_entry_count));
        if ((value_ptr->time_entry_count > 0) && (value_ptr->time_entry_array
            != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->time_entry_count;
                i++)
            {
                sprintf(buffer, "time_entry_array[%u]", i);
                SE_PrintTimeEntry(&(value_ptr->time_entry_array[i]), buffer,
                   level);
            } /* end for i */
        }
    }
} /* end SE_PrintTimeSelectParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTraversalOrder
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintTraversalOrder
(
    SE_Traversal_Order value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_TRAVORDR_BREADTH_FIRST:
             return "SE_TRAVORDR_BREADTH_FIRST";

        case SE_TRAVORDR_DEPTH_FIRST:
             return "SE_TRAVORDR_DEPTH_FIRST";

        case SE_TRAVORDR_MOST_EFFICIENT:
             return "SE_TRAVORDR_MOST_EFFICIENT";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Traversal_Order VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintTraversalOrder */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintUnmatchedStateBehaviour
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintUnmatchedStateBehaviour
(
    SE_Unmatched_State_Behaviour value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_UNMSTATBEH_NONE:
             return "SE_UNMSTATBEH_NONE";

        case SE_UNMSTATBEH_DEFAULT:
             return "SE_UNMSTATBEH_DEFAULT";

        case SE_UNMSTATBEH_ALL:
             return "SE_UNMSTATBEH_ALL";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Unmatched_State_Behaviour"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintUnmatchedStateBehaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVolumeExtentEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintVolumeExtentEntry
(
    const SE_Volume_Extent_Entry *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Volume_Extent_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->volume_type: %s\n", name_ptr,
                SE_PrintVolumetricShape(value_ptr->volume_type));
        switch (value_ptr->volume_type)
        {
            case SE_VOLSHAP_CYLINDER:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->volume_extent_data.cylinder", name_ptr);
                SE_PrintCylindricalVolumeExtentEntry(&(value_ptr->volume_extent_data.cylinder),
                  buffer, level);
                break;

            case SE_VOLSHAP_PARALLELEPIPED:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "%s->volume_extent_data.parallelepiped", name_ptr);
                SE_PrintParallelepipedVolumeExtentEntry(&(value_ptr->volume_extent_data.parallelepiped),
                  buffer, level);
                break;

            case SE_VOLSHAP_SPHERE:
                sprintf(buffer, "%s->volume_extent_data.sphere", name_ptr);
                temp_fields.tag = SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT;
                memcpy(&(temp_fields.u.Spherical_Volume_Extent),
                       &(value_ptr->volume_extent_data.sphere),
                       sizeof(SE_Spherical_Volume_Extent_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "volume_type: %s\n",
                SE_PrintVolumetricShape(value_ptr->volume_type));
        switch (value_ptr->volume_type)
        {
            case SE_VOLSHAP_CYLINDER:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "volume_extent_data.cylinder");
                SE_PrintCylindricalVolumeExtentEntry(&(value_ptr->volume_extent_data.cylinder),
                  buffer, level);
                break;

            case SE_VOLSHAP_PARALLELEPIPED:
                SE_Indent(level, f_ptr);
                sprintf(buffer, "volume_extent_data.parallelepiped");
                SE_PrintParallelepipedVolumeExtentEntry(&(value_ptr->volume_extent_data.parallelepiped),
                  buffer, level);
                break;

            case SE_VOLSHAP_SPHERE:
                sprintf(buffer, "volume_extent_data.sphere");
                temp_fields.tag = SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT;
                memcpy(&(temp_fields.u.Spherical_Volume_Extent),
                       &(value_ptr->volume_extent_data.sphere),
                       sizeof(SE_Spherical_Volume_Extent_Fields));
                SE_PrintDRMClassFields(&temp_fields, buffer, level);
                break;

        } /* end switch */
    }
} /* end SE_PrintVolumeExtentEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVolumeLODEntry
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintVolumeLODEntry
(
    const SE_Volume_LOD_Entry *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL, *srm_f_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        srm_f_ptr = SRM_GetOutFilePtr();
        if (SRM_SetOutFilePtr(f_ptr) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr, "ERROR in SE_PrintVolumeLODEntry: "\
                    "SRM_SetOutFilePtr failed\n");
            fflush(stderr);
            return;
        }
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Volume_LOD_Entry\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->coordinate", name_ptr);
        SRM_PrintCoordinate(&(value_ptr->coordinate), buffer, level);
        sprintf(buffer, "%s->volume_extent", name_ptr);
        SE_PrintVolumeExtentEntry(&(value_ptr->volume_extent), buffer, level);
        sprintf(buffer, "%s->volume_lod", name_ptr);
        temp_fields.tag = SE_CLS_DRM_VOLUME_LOD_DATA;
        memcpy(&(temp_fields.u.Volume_LOD_Data),
               &(value_ptr->volume_lod),
               sizeof(SE_Volume_LOD_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
    else
    {
        sprintf(buffer, "coordinate");
        SRM_PrintCoordinate(&(value_ptr->coordinate), buffer, level);
        sprintf(buffer, "volume_extent");
        SE_PrintVolumeExtentEntry(&(value_ptr->volume_extent), buffer, level);
        sprintf(buffer, "volume_lod");
        temp_fields.tag = SE_CLS_DRM_VOLUME_LOD_DATA;
        memcpy(&(temp_fields.u.Volume_LOD_Data),
               &(value_ptr->volume_lod),
               sizeof(SE_Volume_LOD_Data_Fields));
        SE_PrintDRMClassFields(&temp_fields, buffer, level);
    }
        if (SRM_SetOutFilePtr(srm_f_ptr) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr, "ERROR in SE_PrintVolumeLODEntry: "\
                    "SRM_SetOutFilePtr failed reset\n");
            fflush(stderr);
        }
} /* end SE_PrintVolumeLODEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVolumetricShape
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintVolumetricShape
(
    SE_Volumetric_Shape value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_VOLSHAP_CYLINDER:
             return "SE_VOLSHAP_CYLINDER";

        case SE_VOLSHAP_PARALLELEPIPED:
             return "SE_VOLSHAP_PARALLELEPIPED";

        case SE_VOLSHAP_SPHERE:
             return "SE_VOLSHAP_SPHERE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Volumetric_Shape VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintVolumetricShape */
