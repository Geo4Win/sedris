/*
 * FILE       : metadata.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), David Shen (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a transmittal with respect
 *    to constraints affecting metadata.
 *
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
#include <ctype.h> /* to support testing constrained strings */
#include "control_link.h"
#include "metadata.h"
#include "prop_set_table.h"

static void
check_lobe_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_moving_light_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_relative_time_interval
(
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                 object,
    SE_FIELDS_PTR             fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_volume_light_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static SE_Return_Code
check_volume_lod_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Volume_LOD_Entry       *volume_lod_entry
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_abs_time_interval
 *
 *-----------------------------------------------------------------------------
 */
static void
check_abs_time_interval
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object     time_pt = NULL;
    SE_FIELDS_PTR time_pt_fields = NULL;

    path[level] = fields_ptr->tag;

    if (SE_GetComponent(object, SE_CLS_DRM_ABSOLUTE_TIME, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &time_pt, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(time_pt, GetGlobalStore(level), &time_pt_fields)
            == SE_RETCOD_SUCCESS)
        {
           SE_UpdateLocalSummaryFromFields(summary, fields_ptr);

           /* $$$ more checking could be done on the time point fields */
            switch (time_pt_fields->u.Absolute_Time.time_value.configuration)
            {
                case SE_TIMECFG_DATE_M:
                case SE_TIMECFG_DATE_Y:
                    /*
                     * if this configuration doesn't specify a day then
                     */
                     if (fields_ptr->u.Absolute_Time_Interval.delta_days != 0)
                     {
                         se_message(object, path[level], level, path, MSGTYP_ERROR,
                            "delta_days violates <<Time Dependency>>, part 1");
                     }
                     break;

                case SE_TIMECFG_DAY_OF_YEAR:
                    if ((fields_ptr->u.Absolute_Time_Interval.delta_days < 0) ||
                        (fields_ptr->u.Absolute_Time_Interval.delta_days > 365))
                    {
                        se_message(object, path[level], level, path, MSGTYP_ERROR,
                           "delta_days violates <<Time Dependency>>, part 3");
                    }
                    break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_abs_time_interval:SE_GetFields");
            se_message(time_pt, SE_CLS_DRM_ABSOLUTE_TIME, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(time_pt);
    }
    else
    {
        printLastFnctStatus("check_abs_time_interval:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "missing <Absolute Time>");
    }
} /* end check_abs_time_interval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_base_time_data
 *
 *-----------------------------------------------------------------------------
 */
void
check_base_time_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = fields_ptr->tag;

    switch (path[level])
    {
        case SE_CLS_DRM_ABSOLUTE_TIME:
        case SE_CLS_DRM_TIME_OF_DAY:
             break;
        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
             check_abs_time_interval(level, path, object, fields_ptr, summary);
             break;
        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
             check_relative_time_interval(level, path, object, fields_ptr,
                 summary);
             break;
        case SE_CLS_DRM_RELATIVE_TIME:
             check_relative_time(level, path, object, fields_ptr);
             break;
        case SE_CLS_DRM_SEASON:
             if (SE_GetComponent(object, SE_CLS_DRM_TIME_INTERVAL,
                 SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
                 &next_object, NULL) == SE_RETCOD_SUCCESS)
             {
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
                     == SE_RETCOD_SUCCESS)
                 {
                     check_time_interval(level+1, path, next_object,
                        next_fields_ptr, summary);
                 }
                 else
                 {
                     se_message(next_object, SE_CLS_DRM_TIME_INTERVAL,
                        level+1, path, MSGTYP_ERROR,
                        "can't get fields");
                 }
                 SE_FreeObject(next_object);
             }
             break;

        default:
             se_message(object, path[level], level, path, MSGTYP_ERROR,
                "expected concrete subclass of <Base Time Data>");
             break;

    } /* end switch */
} /* end check_base_time_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_citation
 *
 *-----------------------------------------------------------------------------
 */
void
check_citation
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned   i=0, time_sig_count = 0;
    SE_Time_Significance *time_sig_array = NULL;

    time_sig_count = 0;
    time_sig_array = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_citation:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter, &time_sig_count)
             != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_citation:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "can't get count for component iter");
        SE_FreeIterator(iter);
        return;
    }
    else if ((time_sig_count > 0) &&
             ((time_sig_array = (SE_Time_Significance *)
             calloc(time_sig_count,
                    sizeof(SE_Time_Significance))) == NULL))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't alloc time_sig_array");
        SE_FreeIterator(iter);
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_citation:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

       /*
        * If an <Absolute Time> component exists, its time_significance
        * must be distinct from those of all the other such components
        */
        if (SE_GetFields(next_object, GetGlobalTempStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag==SE_CLS_DRM_ABSOLUTE_TIME)
            {
                time_sig_array[i] =
                    next_fields_ptr->u.Absolute_Time.time_significance;
                i++;
            }
            /* $$$ need to check <Responsible Party> here */
        }
        else
        {
            printLastFnctStatus("check_citation:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_ABSOLUTE_TIME,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (i < time_sig_count)
    {
        time_sig_count = i;
    }

    if (time_sig_count > 1)
    {
        SE_Boolean          result = SE_TRUE;
        SE_Integer_Unsigned j=0;

        result = SE_TRUE;
        for (i = 0; (result == SE_TRUE) && (i < time_sig_count-1); i++)
        {
            for (j = i+1; (result == SE_TRUE) && (j < time_sig_count); j++)
            {
                if (time_sig_array[i] == time_sig_array[j])
                {
                    se_message(object, SE_CLS_DRM_CITATION, level, path,
                       MSGTYP_ERROR, "violates <<Mandatory Metadata>>");
                }
            }
        }
    }
    free(time_sig_array);
    time_sig_array = NULL;
} /* end check_citation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_classification_data
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
check_classification_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Classification_Entry   *entry_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Boolean          result = SE_TRUE;
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_DRM_Class_Fields temp_fields;
    SE_Integer_Unsigned i=0;

    path[level] = fields_ptr->tag;

    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_CLASSIFICATION_DATA:
             entry_ptr->class_data = fields_ptr->u.Classification_Data;
             break;

        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
             entry_ptr->class_data.tag = fields_ptr->
                        u.Conformal_Behaviour.classification;
             break;

        case SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY:
             entry_ptr->class_data.tag = fields_ptr->
                        u.Environmental_Domain_Summary.environmental_domain;
             break;

        case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
             entry_ptr->class_data.tag = fields_ptr->
                        u.Table_Property_Description.component_data_table_ecc;
             break;

        case SE_CLS_DRM_REFERENCE_SURFACE:
             entry_ptr->class_data.tag = fields_ptr->
                        u.Reference_Surface.classification;
             break;

        default:
             return SE_FALSE;
             break;
    } /* end switch */

    entry_ptr->prop_val_count = 0;
    entry_ptr->prop_val_array = NULL;

    if (local_InitializeComponentIterator3(object,
        GetGlobalComponentFilter(SE_CLS_DRM_PROPERTY_VALUE), &iter)
       != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_FALSE;
    }
    else if (SE_GetIterationLengthRemaining(iter, &entry_ptr->prop_val_count)
             != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get component count");
        SE_FreeIterator(iter);
        return SE_FALSE;
    }
    else if ((entry_ptr->prop_val_count > 0) &&
             ((entry_ptr->prop_val_array = (SE_Property_Value_Fields *)
             calloc(entry_ptr->prop_val_count,
                    sizeof(SE_Property_Value_Fields))) == NULL))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't alloc <Property Value> array");
        SE_FreeIterator(iter);
        return SE_FALSE;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_classification_data:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalTempStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_CloneFields(next_fields_ptr, &temp_fields) ==
                SE_DRM_STAT_CODE_SUCCESS)
            {
                memcpy(&(entry_ptr->prop_val_array[i]),
                       &(temp_fields.u.Property_Value),
                       sizeof(SE_Property_Value_Fields));
                i++;
            }
            else
            {
                se_message(next_object, SE_CLS_DRM_PROPERTY_VALUE, level+1, path,
                   MSGTYP_ERROR, "can't clone fields");
                result = SE_FALSE;
            }
        }
        else
        {
            printLastFnctStatus("check_classification_data:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_PROPERTY_VALUE, level+1, path,
               MSGTYP_ERROR, "can't get fields");
            result = SE_FALSE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (i < entry_ptr->prop_val_count)
    {
        if (i == 0)
        {
            free(entry_ptr->prop_val_array);
            entry_ptr->prop_val_array = NULL;
        }
        entry_ptr->prop_val_count = i;
    }

    if (SE_ValidClassificationEntry(entry_ptr, SE_FALSE, NULL) == SE_FALSE)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Property Constraints>>, part b");
        result = SE_FALSE;
    }
   /*
    * the caller will free the SE_Classification_Entry
    */
    return result;
} /* end check_classification_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_directional_light_behaviour
 *
 *-----------------------------------------------------------------------------
 */
static void
check_directional_light_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_directional_light_behaviour:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_LOBE_DATA:
                     check_lobe_data(level+1, path, next_object, context, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION]==SE_TRUE)
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_directional_light_behaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_distance_lod_data
 *
 *-----------------------------------------------------------------------------
 */
static void
check_distance_lod_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object     location = NULL;
    SE_FIELDS_PTR loc_fields = NULL;

    if (SE_GetComponent(object, SE_CLS_DRM_LOCATION,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
        &location, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(location, GetGlobalStore(level), &loc_fields)
               == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, loc_fields);

            check_location(level+1, path, location, loc_fields,
                  NULL, context, summary);
        }
        else
        {
            se_message(location, loc_fields->tag, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(location);
    }
} /* end check_distance_lod_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_EDCS_use_summary_item
 *
 *-----------------------------------------------------------------------------
 */
void
check_EDCS_use_summary_item
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;
    SE_Boolean    is_empty = SE_TRUE;

    path[level] = fields_ptr->tag;

   /*
    * <<Elaboration Of Classification Data>>
    * <<Property Constraints>>
    * <<Property Meaning Constraints>>
    */
    check_prop_desc_components(level, path, object, summary, &is_empty);

    if (SE_GetComponent(object, SE_CLS_DRM_CLASSIFICATION_DATA,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();
        is_empty = SE_FALSE;

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_Classification_Entry dummy;

            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_classification_data(level, path, next_object,
                next_fields_ptr, &dummy, summary);
            SE_FreeClassificationEntry(&dummy, NULL);
        }
        else
        {
            printLastFnctStatus("check_EDCS_use_summary_item:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_CLASSIFICATION_DATA,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    } /* end if */

    SE_FreeIterator(iter);

    if (is_empty == SE_TRUE)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "provides no components as summary");
    }
} /* end check_EDCS_use_summary_item */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_hierarchy_summary_item
 *
 *-----------------------------------------------------------------------------
 */
void
check_hierarchy_summary_item
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
          SE_Iterator          iter = NULL;
          SE_Object            next_object = NULL;
          SE_FIELDS_PTR        next_fields_ptr = NULL;
    const SE_Requirement      *req_ptr = NULL;
          SE_Integer_Unsigned  comp_count, assoc_count;
          SE_Boolean           drm_class_summary[SE_DRM_CLASS_UBOUND];

    memset(drm_class_summary, SE_FALSE,
           sizeof(SE_Boolean)*SE_DRM_CLASS_UBOUND);

    if (SE_GetRelationCounts(object, SE_ITRBEH_RESOLVE,
        &comp_count, NULL, &assoc_count) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "can't get relation counts");
        return;
    }

    if (comp_count > 0)
    {
        if (local_InitializeComponentIterator3(object, search_filter,
            &iter) != SE_RETCOD_SUCCESS)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "can't initialize component iter");
            return;
        }

   /*
    * <<Hierarchy Summary Constraints>>, 2
    * <<Non Overlapping DRM Class Summary Items>>
    */
        while (SE_IsIteratorComplete(iter) == SE_FALSE)
        {
            if (SE_GetNextObjectOnly(iter, &next_object) !=
                   SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus
                ("check_hierarchy_summary_item:SE_GetNextObject");
                break;
            }
            SE_UpdateAnalysisCounts();

            if (SE_GetFields(next_object, GetGlobalStore(level),
                &next_fields_ptr) == SE_RETCOD_SUCCESS)
            {
                SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                switch (next_fields_ptr->tag)
                {
                    case SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM:
                         if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL)
                             != SE_TRUE)
                         {
                             se_message(next_object, next_fields_ptr->tag,
                                level+1, path, MSGTYP_ERROR_SYNTAX,
                                "invalid fields");
                         }
                         else if (drm_class_summary
                                  [next_fields_ptr->u.DRM_Class_Summary_Item.drm_class]
                                  == SE_TRUE)
                         {
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                                MSGTYP_ERROR, "violates "\
                           "<<Non Overlapping DRM Class Summary Item Instances>>");
                         }
                         else
                         {
                             drm_class_summary[next_fields_ptr->u.DRM_Class_Summary_Item.
                                          drm_class] = SE_TRUE;
                         }
                         break;

                    case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
                         check_EDCS_use_summary_item(level, path, next_object,
                             next_fields_ptr, summary);
                         break;

                    case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
                         if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL) ==
                             SE_TRUE)
                         {
                             if (SE_GetComponentOfType(
                                  fields_ptr->u.Hierarchy_Summary_Item.drm_class,
                                  next_fields_ptr->u.Hierarchy_Summary_Item.drm_class,
                                 &req_ptr) != SE_DRM_STAT_CODE_SUCCESS)
                             {
                                 se_message(next_object, next_fields_ptr->tag, level+1,
                                    path, MSGTYP_ERROR,
                                    "violates <<Hierarchy Summary Constraints>>,"
                                    " part 2");
                             }
                             else
                             {
                                 switch (req_ptr->multiplicity)
                                 {
                                     case SE_MLTPCTY_EXACTLY_ONE:
                                          if ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity_meaning !=
                                              SE_HSMULCOD_EXACT) ||
                                              (next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity != 1))
                                          {
                                              se_message(next_object, next_fields_ptr->tag,
                                                 level+1, path, MSGTYP_ERROR,
                                        "violates <<Hierarchy Summary Constraints>>,"\
                                        " part 2 (multiplicity meaning and value "
                                        "should be exactly 1)");
                                          }
                                          break;

                                     case SE_MLTPCTY_ZERO_OR_ONE:
                                          if ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity_meaning !=
                                              SE_HSMULCOD_UNKNOWN) &&
                                             (next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity != 1))
                                          {
                                              se_message(next_object, next_fields_ptr->tag,
                                                 level+1, path, MSGTYP_ERROR,
                                     "violates <<Hierarchy Summary Constraints>>,"\
                                     " part 2 (multiplicity field value "\
                                     "should be 1)");
                                          }
                                          break;

                                     case SE_MLTPCTY_ZERO_OR_MORE:
                                     case SE_MLTPCTY_ONE_OR_MORE:
                                          if ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity_meaning !=
                                              SE_HSMULCOD_UNKNOWN) &&
                                              (next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity < 1))
                                          {
                                              se_message(next_object, next_fields_ptr->tag,
                                                 level+1, path, MSGTYP_ERROR,
                                     "violates <<Hierarchy Summary Constraints>>,"\
                                     " part 2 (multiplicity field value "\
                                     "should be >= 1)");
                                          }
                                          break;

                                     case SE_MLTPCTY_EXACTLY_N:
                                          if ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity_meaning !=
                                              SE_HSMULCOD_EXACT) ||
                                              (next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity != (SE_Integer_Unsigned)(req_ptr->lower_limit)))
                                          {
                                              se_message(next_object, next_fields_ptr->tag,
                                                 level+1, path, MSGTYP_ERROR,
                                     "violates <<Hierarchy Summary Constraints>>,"\
                                     " part 2 (multiplicity meaning & value "\
                                     "don't match component requirement)");
                                          }
                                          break;

                                     case SE_MLTPCTY_BOUNDED_ARRAY:
                                          if ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity_meaning ==
                                              SE_HSMULCOD_EXACT) &&
                                             ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity < (SE_Integer_Unsigned)(req_ptr->lower_limit)) ||
                                             (next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity > (SE_Integer_Unsigned)(req_ptr->upper_limit))))
                                          {
                                              se_message(next_object, next_fields_ptr->tag,
                                                 level+1, path, MSGTYP_ERROR,
                                     "violates <<Hierarchy Summary Constraints>>,"\
                                     " part 2 (multiplicity field value "\
                                     "doesn't match component requirement)");
                                          }
                                          break;

                                     case SE_MLTPCTY_UNBOUNDED_ARRAY:
                                          if ((next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity_meaning ==
                                              SE_HSMULCOD_EXACT) &&
                                              (next_fields_ptr->u.Hierarchy_Summary_Item.
                                              multiplicity < (SE_Integer_Unsigned)(req_ptr->lower_limit)))
                                          {
                                              se_message(next_object, next_fields_ptr->tag,
                                                 level+1, path, MSGTYP_ERROR,
                                     "violates <<Hierarchy Summary Constraints>>,"\
                                     " part 2 (multiplicity field value "\
                                     "doesn't match component requirement)");
                                          }
                                          break;
                                     default:
                                          break;
                                 } /* end switch */
                             }
                             req_ptr = NULL;

                             check_hierarchy_summary_item(level+1, path,
                                 next_object, next_fields_ptr, summary);
                         }
                         else
                         {
                             se_message(next_object, next_fields_ptr->tag,
                                level+1, path, MSGTYP_ERROR_SYNTAX,
                                "invalid fields");
                         } /* end if */
                         break;
                } /* end switch */
            }
            else
            {
                printLastFnctStatus
                ("check_hierarchy_summary_item:SE_GetFields");
                se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                   MSGTYP_ERROR, "can't get fields");
            } /* end if */
            SE_FreeObject(next_object);
        }
        SE_FreeIterator(iter);
    }

    if (assoc_count > 0)
    {
        if (SE_InitializeAssociateIterator(object, NULL,
            SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_hierarchy_summary_item:SE_InitializeAssociateIterator");
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "can't initialize associate iter");
            return;
        }

       /*
        * <<Hierarchy Summary Constraints>>, 2
        */
        while (SE_IsIteratorComplete(iter) == SE_FALSE)
        {
            if (SE_GetNextObjectOnly(iter, &next_object)
                != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus
                ("check_hierarchy_summary_item:SE_GetNextObject");
               continue;
            }
            SE_UpdateAnalysisCounts();

            if (SE_GetFields(next_object, GetGlobalStore(level),
                &next_fields_ptr) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus
                ("check_hierarchy_summary_item:SE_GetFields");
                se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                   MSGTYP_ERROR, "can't get fields");
            }
            else if (SE_IsA[next_fields_ptr->tag]
                           [fields_ptr->u.Hierarchy_Summary_Item.drm_class]
                     != SE_TRUE)
            {
                se_message(next_object, next_fields_ptr->tag, level+1, path,
                   MSGTYP_ERROR,
                   "violates <<Hierarchy Summary Constraints>>, part 5");

                /*
                 * $$$ NOTE: Doesn't check that associate conforms to
                 * $$$       specified structure, just that it's minimally
                 * $$$       compliant.
                 */
            }
            SE_FreeObject(next_object);
        }
        SE_FreeIterator(iter);
    }
} /* end check_hierarchy_summary_item */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_identification
 *
 *-----------------------------------------------------------------------------
 */
void
check_identification
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  identification,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter = NULL;
    SE_Object      link_object = NULL, next_object = NULL;
    SE_FIELDS_PTR  link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_Boolean             found_duplicate = SE_FALSE,
                           has_citation = SE_FALSE,
                           has_responsible_party_poc = SE_FALSE,
                           has_security_constraints = SE_FALSE;
    SE_Integer_Unsigned    component_count = 0, i, j, keyword_count = 0;
    SE_MD_KeywordTypeCode *keyword_type_array = NULL;

    path[level] = SE_CLS_DRM_IDENTIFICATION;

    if (local_InitializeComponentIterator3(identification, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(identification, path[level], level, path,
           MSGTYP_ERROR, "can't initialize component iterator");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter, &component_count)
             != SE_RETCOD_SUCCESS)
    {
        se_message(identification, path[level], level, path,
            MSGTYP_ERROR, "can't get count for component iter");
        SE_FreeIterator(iter);
        return;
    }
    else if ((component_count > 0) &&
             ((keyword_type_array = (SE_MD_KeywordTypeCode *)
             calloc(component_count,
                    sizeof(SE_MD_KeywordTypeCode))) == NULL))
    {
        se_message(identification, path[level], level, path,
           MSGTYP_ERROR, "can't alloc keyword_type_array");
        SE_FreeIterator(iter);
        return;
    }
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object) !=
            SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_identification:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_attribute(level+1, path, next_object, next_fields_ptr,
                NULL, summary);
            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_CITATION:
                     has_citation = SE_TRUE;
                     break;

                case SE_CLS_DRM_KEYWORDS:
                     keyword_type_array[keyword_count] =
                        next_fields_ptr->u.Keywords.type;
                     keyword_count++;
                     break;

                case SE_CLS_DRM_RESPONSIBLE_PARTY:
                     if (SE_GetFields(link_object, GetGlobalStore(level),
                         &link_fields_ptr) != SE_RETCOD_SUCCESS)
                     {
                         se_message(link_object, SE_CLS_DRM_ROLE_DATA, level+1,
                            path, MSGTYP_ERROR, "can't get fields");
                     }
                     else if (link_fields_ptr->u.Role_Data.role ==
                              SE_ROLECOD_POINT_OF_CONTACT)
                     {
                         has_responsible_party_poc = SE_TRUE;
                     }
                     break;

                case SE_CLS_DRM_SECURITY_CONSTRAINTS:
                     has_security_constraints = SE_TRUE;
                     break;

                default:
                     break;
            }
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
        if (link_object) SE_FreeObject(link_object);
    }
    SE_FreeIterator(iter);

    if (keyword_count > 1)
    {
        found_duplicate = SE_FALSE;
        for (i = 0;
             (found_duplicate != SE_TRUE) && (i < keyword_count-1); i++)
        {
            for (j = i+1;
                 (found_duplicate != SE_TRUE) && (j < keyword_count); j++)
            {
                if (keyword_type_array[i] == keyword_type_array[j])
                {
                    se_message(identification, SE_CLS_DRM_IDENTIFICATION,
                       level, path, MSGTYP_ERROR,
                       "violates <<Mandatory Metadata>> for <Keywords> -"\
                       " two or more of the same type");
                    found_duplicate = SE_TRUE;
                }
            }
        }
    }
    free(keyword_type_array);
    keyword_type_array = NULL;
    if (path[level-1] == SE_CLS_DRM_TRANSMITTAL_ROOT)
    {
        if (has_citation != SE_TRUE)
        {
            se_message(identification, SE_CLS_DRM_IDENTIFICATION, level,
               path, MSGTYP_ERROR, "violates <<Mandatory Metadata>> for "\
               "<Transmittal Root> - missing <Citation>");
        }
        if (keyword_count < 1)
        {
            se_message(identification, SE_CLS_DRM_IDENTIFICATION, level,
               path, MSGTYP_ERROR, "violates <<Mandatory Metadata>> for "\
               "<Transmittal Root> - missing <Keywords>");
        }
        if (has_responsible_party_poc != SE_TRUE)
        {
            se_message(identification, SE_CLS_DRM_IDENTIFICATION, level,
               path, MSGTYP_ERROR, "violates <<Mandatory Metadata>> for "\
               "<Transmittal Root> - missing <Responsible Party> "\
               "playing POINT_OF_CONTACT role");
        }
        if (has_security_constraints != SE_TRUE)
        {
            se_message(identification, SE_CLS_DRM_IDENTIFICATION, level,
               path, MSGTYP_ERROR, "violates <<Mandatory Metadata>> for "\
               "<Transmittal Root> - missing <Security Constraints>");
        }
    }
} /* end check_identification */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_light_rendering_properties
 *
 *-----------------------------------------------------------------------------
 */
void
check_light_rendering_properties
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;
    SE_DRM_Class   homogeneous_dir_bhvr = SE_CLS_DRM_NULL;

    path[level] = SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES;

    if (local_InitializeComponentIterator3(object, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_light_rendering_prop:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
                     check_control_link(level+1, path, next_object,
                       next_fields_ptr, (context->has_variables ?
                       &(context->interface_template) : NULL), summary);
                     break;

                case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
                     check_moving_light_behaviour(level+1, path, next_object,
                         context, summary);
                     break;

                case SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR:
                     check_volume_light_behaviour(level+1, path, next_object,
                         context, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR])
                     {
                         if (homogeneous_dir_bhvr != SE_CLS_DRM_NULL)
                         {
                             if (next_fields_ptr->tag != homogeneous_dir_bhvr)
                             {
                                 se_message(object, next_fields_ptr->tag, level, path,
                                    MSGTYP_ERROR,
                                    "violates <<Homogeneous Light Rendering Properties>>");
                             }
                         }
                         else
                         {
                             homogeneous_dir_bhvr = next_fields_ptr->tag;
                         }
                         check_directional_light_behaviour(level+1, path,
                             next_object, context, summary);
                     }
                     break;

            } /* end switch */
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path, MSGTYP_ERROR,
               "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_light_rendering_properties */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_light_source
 *
 *-----------------------------------------------------------------------------
 */
void
check_light_source
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_LIGHT_SOURCE;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_light_source:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
                     check_control_link(level+1, path, next_object,
                       next_fields_ptr, (context->has_variables ?
                       &(context->interface_template) : NULL), summary);
                     break;

                case SE_CLS_DRM_LOBE_DATA:
                     check_lobe_data(level+1, path, next_object, context, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                            NULL, context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_light_source */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_lobe_data
 *
 *-----------------------------------------------------------------------------
 */
static void
check_lobe_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;
    SE_Boolean    found_direction = SE_FALSE, found_axis = SE_FALSE;

    path[level] = SE_CLS_DRM_LOBE_DATA;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path,
           MSGTYP_ERROR, "can't initialize component iter");
        return;
    }
    found_direction = SE_FALSE;
    found_axis      = SE_FALSE;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_lobe_data:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            != SE_RETCOD_SUCCESS)
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        else if(next_fields_ptr->tag == SE_CLS_DRM_REFERENCE_VECTOR)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->u.Reference_Vector.vector_type)
            {
                case SE_REFVEC_LIGHT_DIRECTION:
                     if (found_direction == SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1,
                            path, MSGTYP_ERROR,
                            "must have only one SE_REFVEC_LIGHT_DIRECTION");
                     }
                     found_direction = SE_TRUE;
                     break;
                case SE_REFVEC_VERTICAL_AXIS:
                     if (found_axis == SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1,
                            path, MSGTYP_ERROR,
                            "must have only one SE_REFVEC_VERTICAL_AXIS");
                     }
                     found_axis = SE_TRUE;
                     break;
                default:
                     se_message(next_object, next_fields_ptr->tag, level+1,
                        path, MSGTYP_ERROR,
                        "vector_type must be SE_REFVEC_LIGHT_DIRECTION "\
                        " or SE_REFVEC_VERTICAL_AXIS");
                     break;
            }
            check_reference_vector(level+1, path, next_object, next_fields_ptr,
                context, summary);
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (!found_axis || !found_direction)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "must have 1 SE_REFVEC_LIGHT_DIRECTION and "\
           "1 SE_REFVEC_VERTICAL_AXIS vector");
    }
} /* end check_lobe_data */


static SE_Boolean
local_Bounds3D
(
    const SE_Search_Bounds *bounds_ptr
)
{
    SE_Boolean result = SE_FALSE;

    switch (bounds_ptr->minimum_point.spatial_coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D:
        case SRM_SPACOORDCOD_CD_3D:
        case SRM_SPACOORDCOD_CM_3D:
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_EI_3D:
        case SRM_SPACOORDCOD_HAEC_3D:
        case SRM_SPACOORDCOD_HEEC_3D:
        case SRM_SPACOORDCOD_HEEQ_3D:
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_LSR_3D:
        case SRM_SPACOORDCOD_LCE_3D:
        case SRM_SPACOORDCOD_LTSAS_3D:
        case SRM_SPACOORDCOD_LTSC_3D:
        case SRM_SPACOORDCOD_LTSE_3D:
        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_PD_3D:
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_SEC_3D:
        case SRM_SPACOORDCOD_SEQ_3D:
        case SRM_SPACOORDCOD_SMD_3D:
        case SRM_SPACOORDCOD_SME_3D:
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
            result = SE_TRUE;
            break;

        default:
            break;
    } /* end switch */
    return result;
} /* end local_Bounds3D */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_location
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
check_location
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              loc_fields,
    SRM_Coordinate            *loc_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SRM_Coordinate  temp_loc, *loc;
    SE_Boolean      result = SE_TRUE;
    SE_Object       next_object;

    path[level] = loc_fields->tag;

    if (loc_ptr != NULL)
    {
        loc = loc_ptr;
    }
    else
    {
        loc = &temp_loc;
    }

    if (SE_ConvertFieldsToCoordinate(loc_fields, loc))
    {
        if ((result = ((SE_Boolean)SE_ValidCoordinateForSRFContextInfo(loc,
            &(context->srf_context_info)))) != SE_TRUE)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "failed SE_ValidCoordinateForSRFContextInfo");
        }
        else if (context->has_spatial_extent == SE_TRUE)
        {
           /*
            * Since the location fields are a union, each coordinate value will
            * be in exactly the same position in the structure.  So we will
            * reference everything as an CD_Surface or CD_3D location and it
            * will always work.
            */
            if (((context->spatial_extent.minimum_point.coordinate.cd_3d.latitude
                  > loc->coordinate.cd_3d.latitude) ||
                 (context->spatial_extent.minimum_point.coordinate.cd_3d.longitude
                  > loc->coordinate.cd_3d.longitude))
             || ((SE_IsA[loc_fields->tag][SE_CLS_DRM_LOCATION_3D] == SE_TRUE) &&
                 (local_Bounds3D(&(context->spatial_extent)) == SE_TRUE) &&
                 ((context->spatial_extent.minimum_point.coordinate.cd_3d.ellipsoidal_height
                   > loc->coordinate.cd_3d.ellipsoidal_height))))
            {
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   "outside context's <Spatial Extent> (less than lower bound)");
            }
            else if (((context->spatial_extent.maximum_point.coordinate.cd_3d.latitude
                       < loc->coordinate.cd_3d.latitude) ||
                      (context->spatial_extent.maximum_point.coordinate.cd_3d.longitude
                       < loc->coordinate.cd_3d.longitude))
                  || ((SE_IsA[loc_fields->tag][SE_CLS_DRM_LOCATION_3D] == SE_TRUE)
                   && (local_Bounds3D(&(context->spatial_extent)) == SE_TRUE) &&
                      (context->spatial_extent.maximum_point.coordinate.cd_3d.ellipsoidal_height
                     < loc->coordinate.cd_3d.ellipsoidal_height)))
            {
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   "outside context's <Spatial Extent> (greater than upper bound)");
            }
        }
    }
    else
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't convert to SRM_Coordinate!");
        result = SE_FALSE;
    }

    if (loc_fields->tag == SE_CLS_DRM_LSR_3D_LOCATION &&
        SE_GetComponent(object, SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
           &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR next_fields_ptr;

        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_control_link(level+1, path, next_object, next_fields_ptr,
             (context->has_variables ? &(context->interface_template) :
             NULL), summary);
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    return result;
} /* end check_location */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_lod_data
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_lod_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_LOD_Entry              *lod_entry
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;

    path[level] = SE_CLS_DRM_NULL;

    if (SE_ValidFields(fields_ptr, SE_FALSE, NULL) == SE_TRUE)
    {
        switch (fields_ptr->tag)
        {
            case SE_CLS_DRM_DISTANCE_LOD_DATA:
                 lod_entry->lod_entry_type = SE_LODDATTYP_DISTANCE;
                 memcpy(&(lod_entry->lod.distance),
                        &(fields_ptr->u.Distance_LOD_Data),
                        sizeof(SE_Distance_LOD_Data_Fields));
                 check_distance_lod_data(level, path, object, context, summary);
                 break;

            case SE_CLS_DRM_INDEX_LOD_DATA:
                 lod_entry->lod_entry_type = SE_LODDATTYP_INDEX;
                 memcpy(&(lod_entry->lod.index),
                        &(fields_ptr->u.Index_LOD_Data),
                        sizeof(SE_Index_LOD_Data_Fields));
                 break;

            case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
                 lod_entry->lod_entry_type = SE_LODDATTYP_MAP_SCALE;
                 memcpy(&(lod_entry->lod.map_scale),
                        &(fields_ptr->u.Map_Scale_LOD_Data),
                        sizeof(SE_Map_Scale_LOD_Data_Fields));
                 break;

            case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
                 lod_entry->lod_entry_type = SE_LODDATTYP_SPATIAL_RESOLUTION;
                 memcpy(&(lod_entry->lod.spatial_resolution),
                        &(fields_ptr->u.Spatial_Resolution_LOD_Data),
                        sizeof(SE_Spatial_Resolution_LOD_Data_Fields));
                 break;

            case SE_CLS_DRM_VOLUME_LOD_DATA:
                 lod_entry->lod_entry_type = SE_LODDATTYP_VOLUME;
                 ret_status = check_volume_lod_data(level, path, object,
                      fields_ptr, context, summary, &(lod_entry->lod.volume));
                 break;

            default:
                 break;
        }
    }
    else
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
                 "invalid fields");
        ret_status = SE_RETCOD_FAILURE;
    }
    return ret_status;
} /* end check_lod_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_moving_light_behaviour
 *
 *-----------------------------------------------------------------------------
 */
static void
check_moving_light_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object     ref_vector = NULL;
    SE_FIELDS_PTR ref_vec_fields;

    path[level] = SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR;

    if (SE_GetComponent(object, SE_CLS_DRM_REFERENCE_VECTOR, SE_FALSE,
        SE_TRUE, SE_ITRBEH_RESOLVE, &ref_vector, NULL) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't get <Reference Vector>");
        return;
    }
    SE_UpdateAnalysisCounts();

    if (SE_GetFields(ref_vector, GetGlobalStore(level), &ref_vec_fields)
        == SE_RETCOD_SUCCESS)
    {
        SE_UpdateLocalSummaryFromFields(summary, ref_vec_fields);

        if (ref_vec_fields->u.Reference_Vector.vector_type !=
            SE_REFVEC_MOVEMENT_DIRECTION)
        {
            se_message(ref_vector, ref_vec_fields->tag, level, path,
              MSGTYP_ERROR, "vector_type is required to be "
              "SE_REFVEC_MOVEMENT_DIRECTION");
        }
        check_reference_vector(level+1, path, ref_vector, ref_vec_fields,
            context, summary);
    }
    else
    {
        se_message(ref_vector, ref_vec_fields->tag, level+1, path,
           MSGTYP_ERROR, "Can't get fields");
    }
    SE_FreeObject(ref_vector);
} /* end check_moving_light_behaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_perimeter_data
 *
 *-----------------------------------------------------------------------------
 */
void
check_perimeter_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator          iter = NULL;
    SE_Object            next_object = NULL;
    SE_FIELDS_PTR        next_fields_ptr = NULL;
    SE_Integer_Unsigned  loc_count=0, loc_indx=0;
    SE_Object           *loc_array = NULL;
    SE_Integer_Unsigned  loc_array_count = 0;
    SE_Boolean           valid_array = SE_TRUE;
    SE_Integer_Unsigned  i;

    path[level] = SE_CLS_DRM_PERIMETER_DATA;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter, &loc_count) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't determine length of iter");
        SE_FreeIterator(iter);
        return;
    }
    else if (loc_count < 3)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "less than 3 <Location> components, aborting check");
        SE_FreeIterator(iter);
        return;
    }
    else if ((loc_array=(SE_Object*)calloc(loc_count, sizeof(SE_Object)))
             == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't calloc loc array, aborting check");
        SE_FreeIterator(iter);
        return;
    }

    while ((valid_array == SE_TRUE) &&
           (SE_IsIteratorComplete(iter) == SE_FALSE))
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_perimeter_data:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if ((SE_GetFields(next_object, GetGlobalStore(level),
                         &next_fields_ptr) != SE_RETCOD_SUCCESS) ||
            !SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get <Location> fields");
        }
        else
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            valid_array = check_location(level+1, path, next_object, next_fields_ptr,
                NULL, context, summary);

            if (SE_CloneObjectHandle(next_object, &loc_array[loc_array_count++]) != SE_RETCOD_SUCCESS)
            {
                se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                   MSGTYP_ERROR, "can't clone object");
            }
            loc_indx++;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (valid_array != SE_FALSE)
    {
        if (check_object_list_for_duplicate_locations(loc_array_count,
            loc_array, &i) == SE_TRUE)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "<Perimeter Data> has non-unique locations");
            se_message(loc_array[i], SE_CLS_DRM_LOCATION, level+1, path,
               MSGTYP_WARNING, "first duplicate found");
            valid_array = SE_FALSE;
        }
        for (i = 0; i < loc_array_count; i++)
        {
            SE_FreeObject(loc_array[i]);
        }
    }
    else
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "cannot check remaining rules since some <Locations>"\
           " are out of scope; aborting check");
        return;
    }
    free(loc_array);
} /* check_perimeter_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_primitive_summary_item
 *
 *-----------------------------------------------------------------------------
 */
void
check_primitive_summary_item
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
          SE_Iterator     iter = NULL;
          SE_Object       next_object = NULL;
          SE_FIELDS_PTR   next_fields_ptr = NULL;
    const SE_Requirement *req_ptr = NULL;
          SE_Boolean      drm_class_summary[SE_DRM_CLASS_UBOUND];

    memset(drm_class_summary, SE_FALSE,
           sizeof(SE_Boolean)*SE_DRM_CLASS_UBOUND);

    if (local_InitializeComponentIterator3(object, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

   /*
    * <<Hierarchy Summary Constraints>>, 2
    * <<Non Overlapping DRM Class Summary Items>>
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_primitive_summary_item:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
                     check_EDCS_use_summary_item(level, path, next_object,
                         next_fields_ptr, summary);
                     break;

                case SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM:
                     if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL)
                         != SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1,
                            path, MSGTYP_ERROR_SYNTAX,
                            "invalid fields, run syntax_checker");
                     }
                     else
                     {
                         if (drm_class_summary
                             [next_fields_ptr->u.Primitive_Summary_Item.drm_class]
                             != SE_TRUE)
                         {
                             drm_class_summary[next_fields_ptr->u.Primitive_Summary_Item.
                                              drm_class] = SE_TRUE;
                         }
                         else
                         {
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                                MSGTYP_ERROR, "violates "\
                                "<<Primitive Summary Item Constraints>>");
                         }
                     }
                     check_primitive_summary_item(level+1, path,
                         next_object, next_fields_ptr, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus
            ("check_primitive_summary_item:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        } /* end if */
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_primitive_summary_item */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_property_description
 *
 *-----------------------------------------------------------------------------
 */
static void
check_property_description
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Element_Code_Queue     *eac_queue_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;
    SE_Boolean     is_unique = SE_FALSE, has_valid_meaning = SE_TRUE;
    SE_Element_Code_Queue          eac_val_queue;
    EDCS_Value_Characteristic_Code pc_meaning[EDCS_TOTAL_EV];
                                  /*
                                   * since the code verifies that the EV is
                                   * valid for each <Property Characteristic>,
                                   * there can be at most EDCS_TOTAL_EV
                                   * distinct pc_meaning[] values
                                   */
    SE_Integer_Unsigned            pc_count = 0, i = 0;

    path[level] = fields_ptr->tag;

    if (SE_ValidDRMClassFields(fields_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "invalid fields");
        has_valid_meaning = SE_FALSE;
    }
    else
    {
        is_unique = local_AddPropertyCodeToQueue(
                    &(fields_ptr->u.Property_Description.
                      meaning), eac_queue_ptr);

        if (is_unique != SE_TRUE)
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "violates <<Property Constraints>>, part (c)");
    }

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_property_description:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
                     if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL))
                     {
                         for (i = 0; i < pc_count; i++)
                         {
                             if (next_fields_ptr->u.Property_Characteristic.meaning !=
                                 pc_meaning[i])
                             {
                                 pc_meaning[pc_count] =
                                   next_fields_ptr->u.Property_Characteristic.meaning;
                                 pc_count++;
                             }
                             else
                             {
                                 se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                                    level+1, path, MSGTYP_ERROR,
                                   "violates <<Property Characteristic Constraints>> - "\
                                   "meaning not unique among this <Property Description>'s "\
                                   "<Property Characteristic> components");
                             }
                         }
                     }
                     else
                     {
                         se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                            level+1, path, MSGTYP_ERROR_SYNTAX, "invalid fields");
                     }
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;
            } /* end switch */
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    local_FreeElementCodeQueue(&eac_val_queue);
    SE_FreeIterator(iter);
} /* end check_property_description */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_desc_components
 *
 *-----------------------------------------------------------------------------
 */
void
check_prop_desc_components
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                *is_empty_ptr
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_desc_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;

    *is_empty_ptr = SE_TRUE;
    if (local_InitializeComponentIterator3(object,
        GetGlobalComponentFilter(SE_CLS_DRM_PROPERTY_DESCRIPTION), &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_prop_desc_components:local_InitializeComponentIterator3");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    eac_desc_queue.head = NULL;
    eac_desc_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_prop_desc_components:SE_GetNextObjectOnly");
            continue;
        }
        SE_UpdateAnalysisCounts();
        *is_empty_ptr = SE_FALSE;

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_property_description(level+1, path, next_object,
                next_fields_ptr, &eac_desc_queue, summary);
        }
        else
        {
            printLastFnctStatus
            ("check_prop_desc_components:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_PROPERTY_DESCRIPTION,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_desc_queue);
} /* end check_prop_desc_components */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_constrained_string
 *
 *   The caller has verified that the fields are syntactically valid and that
 *   1) the <Property Value> passed in is bound to an EDCS_Attribute_Code,
 *   2) the EDCS_Attribute_Code is bound to CONSTRAINED_STRING, and
 *   3) no <Property Characteristic> is involved that overrides the constraint,
 *   so now check that the string complies with the constraint.
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_constrained_string
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    EDCS_Count     i = 0;

    switch (fields_ptr->u.Property_Value.meaning.code.attribute)
    {
        /* self-contained */
        case EAC_BEARING_AND_RECIPROCAL:
             break;

        case EAC_CAPACITY:
        case EAC_OBJECT_RATE:
        case EAC_PEDESTRIAN_RATE:
             if (fields_ptr->u.Property_Value.value.value.constrained_string_value.length < 7)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates constraint - less than 7 characters long");
             }
             break;

        case EAC_CYCLE_DATE:
             if (fields_ptr->u.Property_Value.value.value.constrained_string_value.length != 6)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_CYCLE_DATE constraint - not 6 characters long");
             }
             else if (!isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0])
                  ||  !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1])
                  ||  !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2])
                  ||  !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[3])
                  ||  !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[4])
                  || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]!='0')
                   && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]!='1'))
                  ||  !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_CYCLE_DATE constraint - (4-digit Gregorian year followed by 2-digit cycle number)");
             }
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]=='0'))
                  || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='1')
                   && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]=='5'))
                   ||  (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]=='6')
                   ||  (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]=='7')
                   ||  (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]=='8')
                   ||  (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[6]=='9')))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_CYCLE_DATE constraint - (4-digit Gregorian year followed by 2-digit cycle number)");
             }
             break;

        case EAC_GTRS_GEOTILE:
            /*
             * required to be 6 characters long: 2 letters (megatile) followed by 4 digits
             * - first character: any letter but I or O
             * - second character - latitudinal zone
             *   between 90 degrees S and 90 degrees N, there are 12 zones
             *   A (90 S - 75 S), B (75 S - 60 S), C (60 S - 45 S),
             *   D (45 S - 30 S), E (30 S - 15 S), F (15 S - 0 S),
             *   G ( 0 N - 15 N), H (15 N - 30 N), J (30 N - 45 N),
             *   K (45 N - 60 N), L (60 N - 75 N), M (75 N - 90 N)
             * - third and fourth characters are digits, values constrained by megatile
             * - last two digits are 00 through 14
             */
             if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length != 6)
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == 'I')
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == 'i')
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == 'O')
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == 'o')
              || !isalpha(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0])
              || !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'A')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'a')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'B')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'b')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'C')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'c')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'D')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'd')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'E')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'e')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'F')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'f')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'G')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'g')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'H')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'h')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'J')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'j')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'K')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'k')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'L')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'l')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'M')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'm'))
              || !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2])
              || !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[3])
              /*
               * last two characters must be 00 through 14
               */
             || !(((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[4]=='0')
                && isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]))

              || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[4]=='1')
               && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='0')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='1')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='2')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='3')
                || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[5]=='4')))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_GTRS_GEOTILE constraint - required to be 2 letter megatile code followed by 4 digit geotile code");
             }
            /*
             * For latitudinal zones A and M, the valid longitudinal zones are
             *  00, 03, 05, 06, 09, 10, 12, 15, 18, 20, 21, 24, 25, 27
             */
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'A')
                    || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'a')
                    || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'M')
                    || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'm'))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '0')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '1')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '2'))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '0')
                     && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '1')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '2')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '4')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '7')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '8')))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '1')
                     && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '1')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '3')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '4')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '6')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '7')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '9')))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '2')
                     && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '2')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '3')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '6')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '8')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '9'))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_GTRS_GEOTILE constraint - longtudinal band "\
                    "for this megatile required to be one of: 00, 03, 05, 06, 09, "\
                    "10, 12, 15, 18, 20, 21, 24, 25, 27");
             }
            /*
             * For latitudinal zones B and L, the valid longitudinal zones are
             *  00, 02, 03, 04, 06, 08, 09, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 26, 27, 28
             */
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'B')
                    || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'b')
                    || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'L')
                    || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'l'))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '0')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '1')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '2'))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '0')
                     && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '1')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '5')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '7')))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '1')
                     && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '1')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '3')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '7')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '9')))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '2')
                     && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '3')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '5')
                      || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '9'))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_GTRS_GEOTILE constraint - longtudinal band "\
                    "for this megatile required to be one of: 00, 02, 03, 04, 06, "\
                    "08, 09, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 26, 27, 28");
             }
            /*
             * For the following latitudinal zones, the valid longitudinal zones are 00 - 14
             * C, D, E, F, G, H, J, K
             */
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'C')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'c')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'D')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'd')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'E')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'e')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'F')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'f')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'G')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'g')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'H')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'h')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'J')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'j')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'K')
                   || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == 'k'))
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '0')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '1'))

                     || !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '1')
                      && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '0')
                       || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '1')
                       || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '2')
                       || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '3')
                       || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == '4'))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_GTRS_GEOTILE constraint - longtudinal band for this megatile required to be between 00 and 14 inclusive");
             }
             break;

        case EAC_INTERCHANGE_TRAVERSABILITY:
             if (fields_ptr->u.Property_Value.value.value.constrained_string_value.length != 4)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_INTERCHANGE_TRAVERSABILITY constraint - not 4 characters long");
                 ret_status = SE_RETCOD_FAILURE;
             }
             for (i = 0; (ret_status == SE_RETCOD_SUCCESS) &&
                  i < fields_ptr->u.Property_Value.value.value.constrained_string_value.length; i++)
             {
                 if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[i] != 'N')
                  || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[i] != 'R')
                  || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[i] != 'L')
                  || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[i] != 'B'))
                 {
                     se_message(object, path[level], level, path, MSGTYP_ERROR,
                        "violates EAC_INTERCHANGE_TRAVERSABILITY constraint - each character required to be N, R, L, or B");
                     ret_status = SE_RETCOD_FAILURE;
                 }
             }
             break;

        case EAC_PRIMARY_OPERATING_AGENCY_IDENTIFIER:
             if (fields_ptr->u.Property_Value.value.value.constrained_string_value.length != 2)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_PRIMARY_OPERATING_AGENCY_IDENTIFIER constraint - should be 2 character DAFIF code");
                 ret_status = SE_RETCOD_FAILURE;
             }
            break;

        case EAC_RUNWAY_END_BEARING:
             if (fields_ptr->u.Property_Value.value.value.constrained_string_value.length != 2)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_END_BEARING constraint - should be 2 characters long");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '1')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '2')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '3'))
                    || !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1])

                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] != '0'))


                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '3')
                    && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '7')
                     && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '8')
                     && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '9'))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_END_BEARING constraint - first 2 characters must range from 01-36");
                 ret_status = SE_RETCOD_FAILURE;
             }
             break;

        case EAC_RUNWAY_HIGH_END_IDENTIFIER:
             if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length < 2)
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.length > 4))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_HIGH_END_IDENTIFIER constraint - should be 2-4 characters long");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '1')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '2')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '3'))
                    || !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1])

                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '1')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] != '9'))

                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '3')
                    && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '7')
                     && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '8')
                     && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '9'))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_HIGH_END_IDENTIFIER constraint - first 2 characters must range from 19-36");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length > 2)
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'L')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'R')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'C')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'S')))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_HIGH_END_IDENTIFIER constraint - 3rd character, if present, must be L, R, C, or S");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length == 4)
                   && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[3] != 'T'))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_HIGH_END_IDENTIFIER constraint - 4th character, if present, must be T");
                 ret_status = SE_RETCOD_FAILURE;
             }
             break;

        case EAC_RUNWAY_IDENTIFIER:
             if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length < 2)
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.length > 4))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_IDENTIFIER constraint - should be 2-4 characters long");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '1')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '2')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '3'))
                    || !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1])

                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] != '0'))


                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '3')
                    && ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '7')
                     && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '8')
                     && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '9'))))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_IDENTIFIER constraint - first 2 characters must range from 01-36");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length > 2)
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'L')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'R')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'C')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'S')))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_IDENTIFIER constraint - 3rd character, if present, must be L, R, C, or S");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length == 4)
                   && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[3] != 'T'))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_IDENTIFIER constraint - 4th character, if present, must be T");
                 ret_status = SE_RETCOD_FAILURE;
             }
             break;

        case EAC_RUNWAY_LOW_END_IDENTIFIER:
             if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length < 2)
              || (fields_ptr->u.Property_Value.value.value.constrained_string_value.length > 4))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_LOW_END_IDENTIFIER constraint - should be 2-4 characters long");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if (((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] != '1'))
                    || !isdigit(fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1])

                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '0')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] != '0'))

                   || ((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[0] == '1')
                    && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[1] == '9')))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_LOW_END_IDENTIFIER constraint - first 2 characters must range from 01-18");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length > 2)
                   && !((fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'L')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'R')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'C')
                     || (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[2] == 'S')))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_LOW_END_IDENTIFIER constraint - 3rd character, if present, must be L, R, C, or S");
                 ret_status = SE_RETCOD_FAILURE;
             }
             else if ((fields_ptr->u.Property_Value.value.value.constrained_string_value.length == 4)
                   && (fields_ptr->u.Property_Value.value.value.constrained_string_value.characters[3] != 'T'))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates EAC_RUNWAY_LOW_END_IDENTIFIER constraint - 4th character, if present, must be T");
                 ret_status = SE_RETCOD_FAILURE;
             }
             break;

        case EAC_LIGHT_VISIBILITY_RANGES:
        case EAC_OCEAN_FLOOR_REGION_NAME:
        case EAC_PICTORIAL_RESOURCE_REQUEST:
        case EAC_SIGNAL_LIGHT_CHARACTER:
        case EAC_SIGNAL_LIGHT_PATTERN:
        case EAC_TIME_PERIOD:
        case EAC_VEHICLE_MARKING:
        case EAC_WMO_STATION_IDENTIFIER:
             break;

        /* a second <Property Value> is needed to specify the constraint */
        case EAC_AVIATION_LOCATION_IDENTIFIER:
             /* requires EAC_AVIATION_LOCATION_ID_VALUE_SET */
        case EAC_CALENDAR_DATE:
        case EAC_MARINER_NOTICE_DATE:
        case EAC_NON_SUB_CONTACT_DATE: /* $$$ doesn't spell out constraint */
        case EAC_PERIODIC_END_DATE:
        case EAC_PERIODIC_START_DATE:
        case EAC_RECORDING_DATE:
        case EAC_SOURCE_DATA_SET_COMPILE_DATE:
        case EAC_SOURCE_DATA_SET_PRINT_DATE:
        case EAC_SOURCE_DATA_SET_REVISION_DATE:
        case EAC_SURVEY_END_DATE:
        case EAC_SURVEY_START_DATE:
             /* requires EAC_DATE_FORMAT or EAC_DATE_TIME_FORMAT */
        case EAC_DATE_TIME_GROUP:
             /* requires EAC_DATE_TIME_FORMAT */
        case EAC_COUNTRY_IDENTIFIER:
             /* requires EAC_COUNTRY_ID_VALUE_SET */
        case EAC_NATIONAL_PAINT_SCHEME:
             /* requires EAC_NATIONAL_PAINT_SCHEME_VALUE_SET */
        case EAC_MOONRISE_TIME:
        case EAC_MOONSET_TIME:
        case EAC_SUNRISE_TIME:
        case EAC_SUNSET_TIME:
        case EAC_TIME_OF_DAY:
             /* requires EAC_TIME_FORMAT */
             break;
    } /* end switch */
    return ret_status;
} /* end check_constrained_string */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_property_value
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_property_value
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Element_Code_Queue     *eac_queue_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter = NULL;
    SE_Boolean     is_unique = SE_FALSE, has_valid_meaning = SE_TRUE,
                   overridden_by_ev = SE_FALSE;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;
    EDCS_Value_Characteristic_Code pc_meaning[EDCS_TOTAL_EV];
    SE_Integer_Unsigned            pc_count = 0, i = 0;

    path[level] = fields_ptr->tag;

   /*
    * First check that the <Property Value> instance's fields are
    * syntactically valid. This is necessary, but not sufficient.
    */
    if (SE_ValidDRMClassFields(fields_ptr, SE_FALSE, NULL) == SE_TRUE)
    {
        is_unique = local_AddPropertyCodeToQueue(
                     &(fields_ptr->u.Property_Value.meaning),
                         eac_queue_ptr);

        if (is_unique != SE_TRUE)
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "violates <<Property Constraints>>, part (b)");
    }
    else
    {
        has_valid_meaning = SE_FALSE;
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "invalid fields");
        ret_status = SE_RETCOD_FAILURE;
    }

   /*
    * Now check for any <Property Characteristic> components.
    * - Each has to have a unique EV among the EVs of this
    *   <Property Value>
    */
    if (local_InitializeComponentIterator3(object,
        GetGlobalComponentFilter(SE_CLS_DRM_PROPERTY_CHARACTERISTIC), &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_property_value:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }

    pc_count = 0;
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_property_value:SE_GetNextObject");
            ret_status = SE_RETCOD_FAILURE;
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL)==SE_TRUE)
            {
                if (has_valid_meaning == SE_TRUE)
                {
                    const EDCS_Value_Characteristic_Dictionary_Entry *ev_entry = NULL;

                    if (EDCS_GetEVDictionaryEntry
                        (next_fields_ptr->u.Property_Characteristic.meaning,
                         &ev_entry) == EDCS_SC_SUCCESS)
                    {
                        if (ev_entry->is_quantitative != EDCS_TRUE)
                        {
                            if (overridden_by_ev == SE_TRUE)
                            {
                                se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                                   level, path, MSGTYP_ERROR,
                                   "<Property Value> already has qualitative <Property Characteristic>");
                            }
                            else
                            {
                                overridden_by_ev = SE_TRUE;
                            }
                        }
                    }

                    if (next_fields_ptr->u.Property_Characteristic.
                        characteristic_value.attribute_value_type !=
                        fields_ptr->u.Property_Value.value.attribute_value_type)
                    {
                        se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                           level, path, MSGTYP_ERROR,
                           "violates <<Property Characteristic Constraints>> - "\
                           "value_type mismatch with "\
                           "<Property Value>'s attribute_value_type");
                    }
                }
                for (i = 0; i < pc_count; i++)
                {
                    if (next_fields_ptr->u.Property_Characteristic.meaning !=
                        pc_meaning[i])
                    {
                        pc_meaning[pc_count] =
                          next_fields_ptr->u.Property_Characteristic.meaning;
                        pc_count++;
                    }
                    else
                    {
                        se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                           level+1, path, MSGTYP_ERROR,
                           "violates <<Property Characteristic Constraints>> - "\
                           "meaning not unique among this <Property Value>'s "\
                           "<Property Characteristic> components");
                    }
                }
            }
            else
            {
                se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                   level+1, path, MSGTYP_ERROR_SYNTAX, "invalid fields");
            }
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

   /*
    * if the <Property Value> is bound to a CONSTRAINED_STRING
    * and has not been rebound to a qualitative EV, check the
    * string for correctness
    */
    if ((has_valid_meaning == SE_TRUE) &&
        (fields_ptr->u.Property_Value.meaning.code_type ==
         SE_PROPCODTYP_ATTRIBUTE) &&
        (overridden_by_ev != SE_TRUE) &&
        ((fields_ptr->u.Property_Value.value.attribute_value_type ==
          EDCS_AVT_CONSTRAINED_STRING) ||
         (fields_ptr->u.Property_Value.meaning.code.attribute ==
          EAC_GTRS_GEOTILE)))
    {
        check_constrained_string(level, path, object, fields_ptr, summary);
    }
    return ret_status;
} /* end check_property_value */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_reference_origin
 *
 *-----------------------------------------------------------------------------
 */
void
check_reference_origin
(
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                 object,
    SE_FIELDS_PTR             fields_ptr
)
{
    SE_FIELDS_PTR loc_fields = NULL;
    SE_Object     location = NULL;

    path[level] = fields_ptr->tag;

    if (SE_GetComponent(object, SE_CLS_DRM_LOCATION, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &location, NULL) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't get Location");
        return;
    }
    SE_UpdateAnalysisCounts();

    if (SE_GetFields(location, GetGlobalStore(level), &loc_fields) ==
           SE_RETCOD_SUCCESS)
    {
        SE_LOCAL_CONTEXT context;
        SE_LOCAL_SUMMARY summary;

        SE_InitializeLocalContext(level, path, object, fields_ptr, NULL,
                                  &context);
        SE_InitializeLocalSummary(&summary);
        SE_UpdateLocalSummaryFromFields(&summary, fields_ptr);

        check_location(level+1, path, location, loc_fields,
              NULL, &context, &summary);
    }
    else
    {
        se_message(location, loc_fields->tag, level+1, path, MSGTYP_ERROR,
           "Can't get fields");
    }
    SE_FreeObject(location);
} /* end check_reference_origin */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_reference_vector
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_reference_vector
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code        ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator           iter = NULL;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Boolean            found_location = SE_FALSE;

    path[level] = fields_ptr->tag;

    if (SE_ValidFields(fields_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        se_message(object, path[level], level, path,
           MSGTYP_ERROR_SYNTAX, "invalid fields");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        switch (fields_ptr->u.Reference_Vector.vector_type)
        {
            case SE_REFVEC_CAMERA_FORWARD_AXIS:
            case SE_REFVEC_CAMERA_UP_AXIS:
                 if (path[level-1] != SE_CLS_DRM_CAMERA_POINT)
                 {
                     se_message(object, path[level], level, path, MSGTYP_ERROR,
                       "vector_type is meaningful only within <Camera Point>");
                     ret_status = SE_RETCOD_FAILURE;
                 }
                 break;
            case SE_REFVEC_LIGHT_DIRECTION:
            case SE_REFVEC_VERTICAL_AXIS:
                 if (path[level-1] != SE_CLS_DRM_LOBE_DATA)
                 {
                     se_message(object, path[level], level, path, MSGTYP_ERROR,
                       "vector_type is meaningful only within <Lobe Data>");
                     ret_status = SE_RETCOD_FAILURE;
                 }
                 break;
            case SE_REFVEC_LSR_TRANSFORMATION_AXIS:
                 if (SE_IsA[path[level-1]][SE_CLS_DRM_LSR_TRANSFORMATION_STEP]
                     != SE_TRUE)
                 {
                     se_message(object, path[level], level, path, MSGTYP_ERROR,
                       "vector_type is meaningful only within "\
                       "<LSR Transformation Step>");
                     ret_status = SE_RETCOD_FAILURE;
                 }
                 break;
            case SE_REFVEC_MAJOR_AXIS:
            case SE_REFVEC_MINOR_AXIS:
                 if ((path[level-1] != SE_CLS_DRM_ELLIPSE) ||
                     (path[level-1] != SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT))
                 {
                     se_message(object, path[level], level, path, MSGTYP_ERROR,
                        "vector_type is meaningful only within <Ellipse> or "\
                        "<Cylindrical Volume Extent");
                     ret_status = SE_RETCOD_FAILURE;
                 }
                 break;
            case SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION:
                 if (path[level-1] != SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT)
                 {
                     se_message(object, path[level], level, path, MSGTYP_ERROR,
                       "vector_type is meaningful only within "\
                       "<Parallelepiped Volume Extent>");
                     ret_status = SE_RETCOD_FAILURE;
                 }
                 break;
            default:
                 switch (path[level-1])
                 {
                      case SE_CLS_DRM_CAMERA_POINT:
                      case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
                      case SE_CLS_DRM_ELLIPSE:
                      case SE_CLS_DRM_LOBE_DATA:
                      case SE_CLS_DRM_LSR_TRANSFORMATION_STEP:
                      case SE_CLS_DRM_ROTATION:
                      case SE_CLS_DRM_SCALE:
                      case SE_CLS_DRM_TRANSLATION:
                      case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
                           se_message(object, path[level], level, path,
                              MSGTYP_ERROR,
                              "vector_type is not meaningful here");
                           ret_status = SE_RETCOD_FAILURE;
                           break;
                      case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
                           if (fields_ptr->u.Reference_Vector.vector_type !=
                               SE_REFVEC_MOVEMENT_DIRECTION)
                           {
                               se_message(object, path[level], level, path,
                                  MSGTYP_ERROR,
                                  "vector_type is not meaningful here");
                               ret_status = SE_RETCOD_FAILURE;
                           }
                           break;
                 }
                 break;
        }
    }

    if (local_InitializeComponentIterator3(object, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path,
           MSGTYP_ERROR, "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_reference_vector:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;

                case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
                     check_control_link(level+1, path, next_object,
                      next_fields_ptr, (context->has_variables ?
                      &(context->interface_template) : NULL), summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         found_location = SE_TRUE;
                         if (check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary) != SE_TRUE)
                         {
                             ret_status = SE_RETCOD_FAILURE;
                         }
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_reference_vector:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if (found_location != SE_TRUE)
    {
       /*
        * Did not have a <Location> component
        */
        if ((path[level-1] == SE_CLS_DRM_POLYGON) ||
            (path[level-1] == SE_CLS_DRM_LINE) ||
            (path[level-1] == SE_CLS_DRM_INFINITE_LIGHT) ||
            (path[level-1] == SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR) ||
             SE_IsA[path[level-1]][SE_CLS_DRM_UNION_OF_GEOMETRY])
        {
            se_message(object, path[level], level, path,
               MSGTYP_ERROR, "violates <<Required Reference Vector Location>>");
            ret_status = SE_RETCOD_FAILURE;
        }
    }
    return ret_status;
} /* end check_reference_vector */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_relative_time
 *
 *-----------------------------------------------------------------------------
 */
void
check_relative_time
(
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                 object,
    SE_FIELDS_PTR             fields_ptr
)
{
    SE_Object time_pt = NULL;

    path[level] = fields_ptr->tag;

    if (SE_GetComponent(object, SE_CLS_DRM_ABSOLUTE_TIME, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &time_pt, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR time_pt_fields = NULL;

        SE_UpdateAnalysisCounts();

        if (SE_GetFields(time_pt, GetGlobalStore(level), &time_pt_fields)
            == SE_RETCOD_SUCCESS)
        {
            switch (time_pt_fields->u.Absolute_Time.time_value.configuration)
            {
                case SE_TIMECFG_DATE_Y:
                case SE_TIMECFG_DATE_M:
                     if (fields_ptr->u.Relative_Time.delta_days != 0)
                     {
                         se_message(time_pt, SE_CLS_DRM_ABSOLUTE_TIME, level+1,
                            path, MSGTYP_ERROR,
                            "violates <<Time Dependency>>, part 1");
                     }
                     break;
                case SE_TIMECFG_DAY_OF_YEAR:
                     if ((fields_ptr->u.Relative_Time.delta_days < 0) ||
                         (fields_ptr->u.Relative_Time.delta_days > 365))
                     {
                         se_message(time_pt, SE_CLS_DRM_ABSOLUTE_TIME, level+1,
                            path, MSGTYP_ERROR,
                            "violates <<Time Dependency>>, part 3");
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_relative_time:SE_GetFields");
            se_message(time_pt, SE_CLS_DRM_ABSOLUTE_TIME, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(time_pt);
    }
} /* end check_relative_time */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_relative_time_interval
 *
 *-----------------------------------------------------------------------------
 */
static void
check_relative_time_interval
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object time_pt = NULL;

    path[level] = fields_ptr->tag;

    if (SE_GetComponent(object, SE_CLS_DRM_ABSOLUTE_TIME, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &time_pt, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR time_pt_fields = NULL;

        SE_UpdateAnalysisCounts();

        if (SE_GetFields(time_pt, GetGlobalStore(level), &time_pt_fields)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, time_pt_fields);

            switch (time_pt_fields->u.Absolute_Time.time_value.configuration)
            {
                case SE_TIMECFG_DATE_M:
                     if (fields_ptr->u.Relative_Time_Interval.delta_start_days
                         != 0  ||
                         fields_ptr->u.Relative_Time_Interval.delta_stop_days
                         != 0)
                     {
                         se_message(object, path[level], level, path,
                            MSGTYP_ERROR,
                            "delta_start_days, delta_stop_days violate "\
                            "<<Time Dependency>> constraint");
                     }
                     break;
                case SE_TIMECFG_DATE_Y:
                     if (fields_ptr->u.Relative_Time_Interval.delta_start_days
                         != 0  ||
                         fields_ptr->u.Relative_Time_Interval.delta_stop_days
                         != 0)
                     {
                         se_message(object, path[level], level, path,
                            MSGTYP_ERROR,
                            "delta_start_days, delta_stop_days violate"\
                            " <<Time Dependency>> constraint");
                     }
                     if ((fields_ptr->u.Relative_Time_Interval.delta_stop_days -
                          fields_ptr->u.Relative_Time_Interval.delta_start_days)
                          > 29)
                     {
                         se_message(object, path[level], level, path,
                            MSGTYP_ERROR,
                            "delta_days violates "\
                            "<<Time Interval Calculation>>");
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_relative_time_interval:SE_GetFields");
            se_message(time_pt, SE_CLS_DRM_ABSOLUTE_TIME, level+1, path,
               MSGTYP_ERROR, "can't get fields for <Absolute Time>");
        }
        SE_FreeObject(time_pt);
    }
} /* end check_relative_time_interval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_extent
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_spatial_extent
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code      ret_status = SE_RETCOD_SUCCESS;
    SE_Object           location = NULL;
    SE_Integer_Positive i=1;
    SE_Boolean          locations_ok = SE_TRUE;
    SE_Search_Bounds    test_extent;
    SE_FIELDS_PTR       loc_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_SPATIAL_EXTENT;

    for (i = 1; i <=2; i++)
    {
        if (SE_GetNthComponent(object, SE_CLS_DRM_LOCATION, i, &location,
            NULL) != SE_RETCOD_SUCCESS)
        {
            locations_ok = SE_FALSE;
            printLastFnctStatus("check_spatial_extent:SE_GetNthComponent");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(location, GetGlobalStore(level), &loc_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, loc_fields_ptr);

/* fill in the test_extent and set location_ok to false if so */
            if (!check_location(level+1, path, location, loc_fields_ptr,
                ( i == 1 ? &test_extent.minimum_point :
                           &test_extent.maximum_point), context, summary))
            {
                locations_ok = SE_FALSE;
            }
        }
        else
        {
            printLastFnctStatus("check_spatial_extent:SE_GetFields");
            se_message(location, SE_CLS_DRM_LOCATION, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(location);
    }

    if (locations_ok)
    {
        if (!SE_ValidSearchBounds(&test_extent, SE_FALSE, NULL))
        {
            ret_status = SE_RETCOD_FAILURE;
            se_message(object, path[level], level, path,
               MSGTYP_ERROR, "Does not form valid bounds!");
        }
    }
    else
    {
        ret_status = SE_RETCOD_FAILURE;
    }
    return ret_status;
} /* end check_spatial_extent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_state_data
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
check_state_data
(
    SE_Short_Integer_Unsigned    level,
    SE_DRM_Class                 path[MAX_CHECKER_PATH_LENGTH],
    EDCS_Attribute_Code          state_tag,
    EDCS_Attribute_Value_Type    active_state_value_type,
    SE_Object                    object,
    SE_FIELDS_PTR                fields_ptr,
    SE_State_Entry              *entry_ptr
)
{
    SE_Boolean          result = SE_TRUE;
    SE_Integer_Unsigned i = 0;
    char                err_msg[1024];

   /*
    * Cloning isn't necessary, since no legal values will contain
    * pointers.
    */
    entry_ptr->state_tag  = state_tag;
    entry_ptr->state_data = fields_ptr->u.State_Data;

   /*
    * If we got illegal data, replace it rather than trying to clone it.
    */
    if ((fields_ptr->u.State_Data.state_value.attribute_value_type ==
         EDCS_AVT_CONSTRAINED_STRING) ||
        (fields_ptr->u.State_Data.state_value.attribute_value_type ==
         EDCS_AVT_STRING) ||
        (fields_ptr->u.State_Data.state_value.attribute_value_type ==
         EDCS_AVT_KEY))
    {
        memcpy(&(entry_ptr->state_data.state_value.value.string_value),
               &(SE_STRING_DEFAULT), sizeof(SE_String));
    }

    if (SE_ValidStateEntry(entry_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_ERROR,
           "fields are invalid");
    }
    else if (active_state_value_type !=
             fields_ptr->u.State_Data.state_value.attribute_value_type)

    {
       /*
        * The only permitted mismatch is if the <State Data> is an
        * interval and the active_state_value is a single value
        * of the appropriate type
        */
        sprintf(err_msg, "violates <<State Related Organizing Principle>> -- "\
                "its value_type (%s) doesn't match that of "\
                "active_state_value (%s)",
                EDCS_PrintAttributeValueType
                (fields_ptr->u.State_Data.state_value.attribute_value_type),
                EDCS_PrintAttributeValueType
                (active_state_value_type));

        se_message(object, fields_ptr->tag, level, path, MSGTYP_ERROR,
           err_msg);

        result = SE_FALSE;
    }
    return result;
} /* end check_state_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_time_constraints_data
 *
 *-----------------------------------------------------------------------------
 */
void
check_time_constraints_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_DRM_Class               expected_tag,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_time_constraints_data:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][expected_tag])
            {
                path[level+1] = next_fields_ptr->tag;
            }
            else
            {
                char err_msg[1024];

                sprintf(err_msg, "violates time_data_type; must be "\
                        "a <%s>", SE_GetDRMClassString(expected_tag));
                se_message(next_object, next_fields_ptr->tag, level+1, path,
                   MSGTYP_ERROR, err_msg);
            }
            check_base_time_data(level+1, path, next_object, next_fields_ptr,
                summary);
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level, path,
               MSGTYP_ERROR, "can't get <Base Time Data> fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* check_time_constraints_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_time_interval
 *
 *-----------------------------------------------------------------------------
 */
void
check_time_interval
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    path[level] = fields_ptr->tag;

    switch (path[level])
    {
        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
             check_abs_time_interval(level, path, object, fields_ptr,
                 summary);
             break;
        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
             check_relative_time_interval(level, path, object, fields_ptr,
                 summary);
             break;
        default:
             se_message(object, path[level], level, path,
                MSGTYP_ERROR, "expected subclass of <Time Interval>");
             break;
    }
} /* end check_time_interval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_volume
 *
 *-----------------------------------------------------------------------------
 */
void
check_volume
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = fields_ptr->tag;

    if (SE_GetComponent(object, SE_CLS_DRM_VOLUME_EXTENT, SE_FALSE, SE_FALSE,
           SE_ITRBEH_RESOLVE, &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_Volume_Extent_Entry volume_extent_entry;

        SE_UpdateAnalysisCounts();

        check_volume_extent(level+1, path, next_object, context, summary,
            &volume_extent_entry);

        SE_FreeObject(next_object);
        /* don't need to free volume_extent entry */
    }

    if (SE_GetComponent(object, SE_CLS_DRM_LOCATION_3D, SE_FALSE, SE_FALSE,
           SE_ITRBEH_RESOLVE, &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
            check_location(level+1, path, next_object, next_fields_ptr,
                   NULL, context, summary);
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_LOCATION_3D, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
} /* end check_volume */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_volume_extent
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_volume_extent
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Volume_Extent_Entry    *volume_extent_entry
)
{
    SE_Return_Code      ret_status = SE_RETCOD_SUCCESS;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Object           next_object = NULL;
    SE_Integer_Positive ref_vec_count = 0, i = 0;

    path[level] = SE_CLS_DRM_VOLUME_EXTENT;
    if (SE_GetFields(object, GetGlobalStore(level), &next_fields_ptr)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, SE_CLS_DRM_VOLUME_EXTENT, level, path,
            MSGTYP_ERROR, "Can't get fields");
        ret_status = SE_RETCOD_FAILURE;
    }
    else if (SE_ValidFields(next_fields_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        path[level] = next_fields_ptr->tag;
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "invalid fields");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        path[level] = next_fields_ptr->tag;
        switch (path[level])
        {
            case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
                 ref_vec_count = 2;
                 volume_extent_entry->volume_type = SE_VOLSHAP_CYLINDER;
                 memcpy(&(volume_extent_entry->volume_extent_data.cylinder.cylinder),
                        &(next_fields_ptr->u.Cylindrical_Volume_Extent),
                        sizeof(SE_Cylindrical_Volume_Extent_Fields));
                 break;

            case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
                 ref_vec_count = 3;
                 volume_extent_entry->volume_type = SE_VOLSHAP_PARALLELEPIPED;
                 memcpy(&(volume_extent_entry->volume_extent_data.parallelepiped.parallelepiped),
                        &(next_fields_ptr->u.Parallelepiped_Volume_Extent),
                        sizeof(SE_Parallelepiped_Volume_Extent_Fields));
                 break;

            case SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT:
                 volume_extent_entry->volume_type = SE_VOLSHAP_SPHERE;
                 memcpy(&(volume_extent_entry->volume_extent_data.sphere),
                        &(next_fields_ptr->u.Spherical_Volume_Extent),
                        sizeof(SE_Spherical_Volume_Extent_Fields));
                 return ret_status;

            default:
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, "expected a <Volume Extent>");
                 ret_status = SE_RETCOD_FAILURE;
        }
    }

    for (i = 1; (ret_status == SE_RETCOD_SUCCESS) && (i <= ref_vec_count);
         i++)
    {
        if (SE_GetNthComponent(object, SE_CLS_DRM_REFERENCE_VECTOR, i,
            &next_object, NULL) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_volume_extent:SE_GetNextObject");
             ret_status = SE_RETCOD_FAILURE;
            continue;
        }
        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (check_reference_vector(level+1, path, next_object,
                next_fields_ptr, context, summary) != SE_RETCOD_SUCCESS)
            {
                 ret_status = SE_RETCOD_FAILURE;
            }
            else if (path[level] == SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT)
            {
                if ((i == 1) &&
                    (next_fields_ptr->u.Reference_Vector.vector_type !=
                     SE_REFVEC_MAJOR_AXIS))
                {
                    se_message(next_object, SE_CLS_DRM_REFERENCE_VECTOR,
                       level+1, path, MSGTYP_ERROR,
                       "first <Reference Vector> component is not MAJOR_AXIS");
                     ret_status = SE_RETCOD_FAILURE;
                }
                 else if ((i == 2) &&
                         (next_fields_ptr->u.Reference_Vector.vector_type !=
                          SE_REFVEC_MINOR_AXIS))
                {
                    se_message(next_object, SE_CLS_DRM_REFERENCE_VECTOR,
                       level+1, path, MSGTYP_ERROR,
                       "second <Reference Vector> component is not MINOR_AXIS");
                     ret_status = SE_RETCOD_FAILURE;
                }
                else
                {
                    memcpy(&(volume_extent_entry->volume_extent_data.
                        cylinder.reference_vectors[i-1]),
                        &(next_fields_ptr->u.Reference_Vector),
                        sizeof(SE_Reference_Vector_Fields));
                }
            }
            else
            {
                memcpy(&(volume_extent_entry->volume_extent_data.
                    parallelepiped.reference_vectors[i-1]),
                    &(next_fields_ptr->u.Reference_Vector),
                    sizeof(SE_Reference_Vector_Fields));
            }
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_REFERENCE_VECTOR, level+1, path,
               MSGTYP_ERROR, "can't get fields");
             ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    return ret_status;
} /* end check_volume_extent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_volume_light_behaviour
 *
 *-----------------------------------------------------------------------------
 */
static void
check_volume_light_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_volume_light_bhvr:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path,
           MSGTYP_ERROR, "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_volume_light_bhvr:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION]==SE_TRUE)
            {
                check_location(level+1, path, next_object, next_fields_ptr,
                    NULL, context, summary);
            }
            else if (SE_IsA[next_fields_ptr->tag]
                           [SE_CLS_DRM_VOLUME_EXTENT] == SE_TRUE)
            {
                SE_Volume_Extent_Entry volume_extent_entry;

                check_volume_extent(level+1, path, next_object,
                    context, summary, &volume_extent_entry);
            }
        }
        else
        {
            printLastFnctStatus("check_volume_light_bhvr:SE_GetFields");
            se_message(object, SE_CLS_DRM_NULL, level, path,
                MSGTYP_ERROR, "can't get component's fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_volume_light_behaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_volume_lod_data
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_volume_lod_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Volume_LOD_Entry       *volume_lod_entry
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;

    path[level] = fields_ptr->tag;

    memcpy(&(volume_lod_entry->volume_lod),
           &(fields_ptr->u.Volume_LOD_Data),
           sizeof(SE_Volume_LOD_Data_Fields));

    if (SE_GetComponent(object, SE_CLS_DRM_LOCATION_3D, SE_FALSE, SE_FALSE,
           SE_ITRBEH_RESOLVE, &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (check_location(level+1, path, next_object, next_fields_ptr,
                &(volume_lod_entry->coordinate), context, summary)
                != SE_TRUE)
            {
                ret_status = SE_RETCOD_FAILURE;
            }
        }
        else
        {
            ret_status = SE_RETCOD_FAILURE;
            se_message(next_object, SE_CLS_DRM_LOCATION_3D, level+1, path,
                MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    else
    {
        ret_status = SE_RETCOD_FAILURE;
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get <Location 3D> component");
    }

    if (SE_GetComponent(object, SE_CLS_DRM_VOLUME_EXTENT, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (check_volume_extent(level+1, path, next_object,
            context, summary, &(volume_lod_entry->volume_extent))
            != SE_TRUE)
        {
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
        /* don't need to free volume_extent entry */
    }
    else
    {
        ret_status = SE_RETCOD_FAILURE;
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get <Volume Extent> component");
    }
    return ret_status;
} /* end check_volume_lod_data */
