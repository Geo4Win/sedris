/*
 * FILE       : rules_checker.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    This program checks the correctness of a SEDRIS transmittal, with
 *    regard to constraints.
 *
 * Usage:
 *
 *    rules_checker [options] <SEDRIS_transmittal_location>
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
#include "colour_table.h"
#include "data_table.h"
#include "feature.h"
#include "geometry.h"
#include "image.h"
#include "metadata.h"
#include "model.h"
#include "prop_set_table.h"
#include "sound_symbol.h"

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "Rules Checker";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS SDK %s)\n\n\n";

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_env_root
 *
 *-----------------------------------------------------------------------------
 */
void
check_env_root
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              env_root,
    SE_FIELDS_PTR                          fields_ptr,
    SE_LOCAL_SUMMARY                      *summary,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_pt_tables
)
{
    SE_Iterator      iter = NULL;
    SE_Object        next_object = NULL;
    SE_LOCAL_CONTEXT context;
    SE_FIELDS_PTR    next_fields_ptr = NULL;
    char             err_msg[1024];
    SE_DRM_Class     fh_tag = SE_CLS_DRM_NULL, fh_summ_tag = SE_CLS_DRM_NULL,
                     gh_tag = SE_CLS_DRM_NULL, gh_summ_tag = SE_CLS_DRM_NULL;
    SE_Time_Significance *time_sig_array = NULL;
    SE_Integer_Unsigned   comp_count = 0, time_sig_count = 0;
    SE_LOCAL_SUMMARY      summary_summary;

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(env_root, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(env_root, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter, &comp_count)
             != SE_RETCOD_SUCCESS) || (comp_count == 0))
    {
        se_message(env_root, path[level], level, path, MSGTYP_ERROR,
           "Can't get iter length or it's zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((time_sig_array = (SE_Time_Significance *)
             calloc(comp_count, sizeof(SE_Time_Significance)))==NULL)
    {
        se_message(env_root, path[level], level, path, MSGTYP_ERROR,
           "Can't allocate time_sig_array");
        SE_FreeIterator(iter);
        return;
    }
   /*
    * SE_InitializeLocalContext deals with <Spatial Extent>
    */
    SE_InitializeLocalContext(level, path, env_root, fields_ptr,
                              primary_pt_tables, &context);
    SE_InitializeLocalSummary(summary);
    SE_InitializeLocalSummary(&summary_summary);

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_env_root:GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
                     if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL) != SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR_SYNTAX, "invalid fields");
                     }
                     else if ((fh_summ_tag != SE_CLS_DRM_NULL) &&
                              (SE_IsA[next_fields_ptr->u.Hierarchy_Summary_Item.
                              drm_class][SE_CLS_DRM_FEATURE_HIERARCHY]==SE_TRUE))
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Hierarchy Summary Constraints>>, "\
                            "part 4");
                     }
                     else if ((gh_summ_tag != SE_CLS_DRM_NULL) &&
                              (SE_IsA[next_fields_ptr->u.Hierarchy_Summary_Item.
                              drm_class][SE_CLS_DRM_GEOMETRY_HIERARCHY]==SE_TRUE))
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Hierarchy Summary Constraints>>, "\
                            "part 4");
                     }
                     else
                     {
                         if (SE_IsA[next_fields_ptr->u.Hierarchy_Summary_Item.
                                    drm_class][SE_CLS_DRM_FEATURE_HIERARCHY]==SE_TRUE)
                         {
                             fh_summ_tag = next_fields_ptr->u.Hierarchy_Summary_Item.
                                           drm_class;
                         }
                         else
                         {
                             gh_summ_tag = next_fields_ptr->u.Hierarchy_Summary_Item.
                                           drm_class;
                         }
                         check_hierarchy_summary_item(level+1, path, next_object,
                             next_fields_ptr, &summary_summary);
                     }
                     break;

                case SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM:
                     check_primitive_summary_item(level+1, path, next_object,
                         next_fields_ptr, &summary_summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         summary->geometry_present = SE_TRUE;
                         gh_tag       = next_fields_ptr->tag;

                         check_geometry_hierarchy(level+1, path, next_object,
                           next_fields_ptr, &context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         summary->features_present = SE_TRUE;
                         fh_tag       = next_fields_ptr->tag;

                         check_feature_hierarchy(level+1, path, next_object,
                           next_fields_ptr, &context, summary, SE_FALSE, SE_FALSE);
                     }
                     else
                     {
                         check_attribute(level+1, path, next_object, next_fields_ptr,
                             &context, summary);
                         if ((SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_BASE_TIME_DATA]==
                             SE_TRUE) && SE_ValidTimeSignificance
                             (next_fields_ptr->u.Base_Time_Data.time_significance))
                         {
                             SE_Integer_Unsigned j = 0;
                             SE_Boolean          unique_significance = SE_TRUE;

                             unique_significance = SE_TRUE;

                             for (j = 0; (unique_significance==SE_TRUE) &&
                                  j < time_sig_count; j++)
                             {
                                  if (time_sig_array[j] ==
                                     next_fields_ptr->u.Base_Time_Data.time_significance)
                                  {
                                      unique_significance = SE_FALSE;
                                  }
                             }

                             if (unique_significance == SE_TRUE)
                             {
                                  time_sig_array[time_sig_count] =
                                     next_fields_ptr->u.Base_Time_Data.time_significance;
                                  time_sig_count++;
                             }
                             else
                             {
                                 se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR, "violates "\
                                    "<<Distinct Time Significance>>");
                             }
                         }
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_env_root:GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    } /* end while */
    free(time_sig_array);
    SE_FreeIterator(iter);

    if (fh_summ_tag != SE_CLS_DRM_NULL)
    {
        if (fh_tag == SE_CLS_DRM_NULL)
        {
            se_message(env_root, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "summarizes a <Feature Hierarchy> component that isn't "\
               "present");
        }
        else if (SE_IsA[fh_tag][fh_summ_tag] != SE_TRUE)
        {
            se_message(env_root, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "drm_class field doesn't correspond to the class of "\
               "the <Feature Hierarchy>");
        }
    }

    if (gh_summ_tag != SE_CLS_DRM_NULL)
    {
        if (gh_tag == SE_CLS_DRM_NULL)
        {
            se_message(env_root, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "summarizes a <Geometry Hierarchy> component that isn't "\
               "present");
        }
        else if (SE_IsA[gh_tag][gh_summ_tag] != SE_TRUE)
        {
            se_message(env_root, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "drm_class field doesn't correspond to the class of "\
               "the <Geometry Hierarchy>");
        }
    }

    if (context.has_variables)
    {
        check_template_list(level+1, path,
                            &(context.interface_template), err_msg);
    }

    SE_FreeLocalContext(&context);

    if ((summary->features_present != SE_TRUE) &&
        (summary->geometry_present != SE_TRUE))
    {
        se_message(env_root, path[level], level, path, MSGTYP_ERROR,
           "Violates <<Non-Empty Environment Root Instance>> constraint");
    }
} /* end check_env_root */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_transmittal_summary
 *
 *-----------------------------------------------------------------------------
 */
static void
check_transmittal_summary
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Boolean                 images_present,
    SE_Boolean                 models_present,
    SE_Boolean                 sounds_present,
    SE_Boolean                 symbols_present,
    SE_Boolean                 all_roots_processed,
    SE_LOCAL_SUMMARY          *root_summary_ptr,
    SE_Boolean                 all_models_processed,
    SE_LOCAL_SUMMARY          *model_summary_ptr,
    SE_LOCAL_SUMMARY          *other_library_summary_ptr
)
{
    SE_Iterator                  iter = NULL;
    SE_Object                    next_object;
    SE_FIELDS_PTR                next_fields_ptr = NULL;
    SE_Store                     store = NULL;
    char                         err_msg[256];
    SE_Integer_Unsigned          i=0;
    SE_Boolean                   drm_class_summary[SE_DRM_CLASS_UBOUND];
    SE_Classification_Parameters env_domain_fields;
    SE_LOCAL_SUMMARY             summary_summary;

    path[level] = SE_CLS_DRM_TRANSMITTAL_SUMMARY;

    if (fields_ptr->u.Transmittal_Summary.images_present !=
        images_present)
    {
         sprintf(err_msg, "<Transmittal Summary>'s images_present (%s) is "\
                 "incorrect", SE_PrintBoolean(fields_ptr->u.
                 Transmittal_Summary.images_present));
         se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
    if (fields_ptr->u.Transmittal_Summary.models_present !=
        models_present)
    {
         sprintf(err_msg, "<Transmittal Summary>'s models_present (%s) is "\
                 "incorrect", SE_PrintBoolean(fields_ptr->u.
                 Transmittal_Summary.models_present));
         se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
    if (fields_ptr->u.Transmittal_Summary.sounds_present !=
        sounds_present)
    {
         sprintf(err_msg, "<Transmittal Summary>'s sounds_present (%s) is "\
                 "incorrect", SE_PrintBoolean(fields_ptr->u.
                 Transmittal_Summary.sounds_present));
         se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
    if (fields_ptr->u.Transmittal_Summary.symbols_present !=
        symbols_present)
    {
         sprintf(err_msg, "<Transmittal Summary>'s symbols_present (%s) is "\
                 "incorrect", SE_PrintBoolean(fields_ptr->u.
                 Transmittal_Summary.symbols_present));
         se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }

   /*
    * Past this point, if we didn't successfully test all the
    * <Environment Root> instances, we can't tell if the
    * summary data accurately reflects the transmittal content
    * when reporting that something is not present
    */
    switch (fields_ptr->u.Transmittal_Summary.features_present)
    {
        case SE_PRESENT_IN_NONE:
             if (root_summary_ptr->features_present == SE_TRUE)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are not present, but they're present in "\
                    "<Environment Root>s");
             }
             if (model_summary_ptr->features_present == SE_TRUE)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are not present, but they're present in <Model>s");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT:
             if ((all_roots_processed == SE_TRUE) &&
                 (root_summary_ptr->features_present != SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are present in <Environment Root>s, but they aren't");
             }
             if (model_summary_ptr->features_present == SE_TRUE)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are not present in <Model>s, but they are");
             }
             break;

        case SE_PRESENT_IN_MODELS:
             if (root_summary_ptr->features_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are not present in <Environment Root>s, but they are");
             }
             if (!model_summary_ptr->features_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are present in <Model>s, but they aren't");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS:
             if (!root_summary_ptr->features_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are present in <Environment Root>s, but they aren't");
             }
             if (!model_summary_ptr->features_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Feature Representation>s "\
                    "are present in <Model>s, but they aren't");
             }
             break;
    } /* end switch */

    switch (fields_ptr->u.Transmittal_Summary.geometry_present)
    {
        case SE_PRESENT_IN_NONE:
             if (root_summary_ptr->geometry_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are not present, but they're present in "\
                    "<Environment Root>s");
             }
             if (model_summary_ptr->geometry_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are not present, but they're present in <Model>s");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT:
             if (!root_summary_ptr->geometry_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are present in <Environment Root>s, but they aren't");
             }
             if (model_summary_ptr->geometry_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are not present in <Model>s, but they are");
             }
             break;

        case SE_PRESENT_IN_MODELS:
             if (root_summary_ptr->geometry_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are not present in <Environment Root>s, but they are");
             }
             if (!model_summary_ptr->geometry_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are present in <Model>s, but they aren't");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS:
             if (!root_summary_ptr->geometry_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are present in <Environment Root>s, but they aren't");
             }
             if (!model_summary_ptr->geometry_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Geometry Representation>s "\
                    "are present in <Model>s, but they aren't");
             }
             break;
    } /* end switch */

    switch (fields_ptr->u.Transmittal_Summary.priority_values_present)
    {
        case SE_PRESENT_IN_NONE:
             if (root_summary_ptr->priority_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are not present, but they're present in "\
                    "<Environment Root>s");
             }
             if (model_summary_ptr->priority_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are not present, but they're present in <Model>s");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT:
             if (!root_summary_ptr->priority_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are present in <Environment Root>s, but they aren't");
             }
             if (model_summary_ptr->priority_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are not present in <Model>s, but they are");
             }
             break;

        case SE_PRESENT_IN_MODELS:
             if (root_summary_ptr->priority_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are not present in <Environment Root>s, but they are");
             }
             if (!model_summary_ptr->priority_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are present in <Model>s, but they aren't");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS:
             if (!root_summary_ptr->priority_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are present in <Environment Root>s, but they aren't");
             }
             if (!model_summary_ptr->priority_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says <Rendering Priority Level>s "\
                    "are present in <Model>s, but they aren't");
             }
             break;
    } /* end switch */

    switch (fields_ptr->u.Transmittal_Summary.mobility_values_present)
    {
        case SE_PRESENT_IN_NONE:
             if (root_summary_ptr->mobility_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is not present, but they're present in "\
                    "<Environment Root>s");
             }
             if (model_summary_ptr->mobility_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is not present, but they're present in <Model>s");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT:
             if (!root_summary_ptr->mobility_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is present in <Environment Root>s, but it isn't");
             }
             if (model_summary_ptr->mobility_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is not present in <Model>s, but it is");
             }
             break;

        case SE_PRESENT_IN_MODELS:
             if (root_summary_ptr->mobility_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is not present in <Environment Root>s, but it is");
             }
             if (!model_summary_ptr->mobility_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is present in <Model>s, but it isn't");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS:
             if (!root_summary_ptr->mobility_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is present in <Environment Root>s, but it isn't");
             }
             if (!model_summary_ptr->mobility_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says mobility (trafficability) attribution "\
                    "is present in <Model>s, but it isn't");
             }
             break;
    } /* end switch */

    switch (fields_ptr->u.Transmittal_Summary.thermal_values_present)
    {
        case SE_PRESENT_IN_NONE:
             if (root_summary_ptr->thermal_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is not present, but they're present in "\
                    "<Environment Root>s");
             }
             if (model_summary_ptr->thermal_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is not present, but they're present in <Model>s");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT:
             if (!root_summary_ptr->thermal_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is present in <Environment Root>s, but it isn't");
             }
             if (model_summary_ptr->thermal_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is not present in <Model>s, but it is");
             }
             break;

        case SE_PRESENT_IN_MODELS:
             if (root_summary_ptr->thermal_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is not present in <Environment Root>s, but it is");
             }
             if (!model_summary_ptr->thermal_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is present in <Model>s, but it isn't");
             }
             break;

        case SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS:
             if (!root_summary_ptr->thermal_values_present &&
                 (all_roots_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is present in <Environment Root>s, but it isn't");
             }
             if (!model_summary_ptr->thermal_values_present &&
                 (all_models_processed == SE_TRUE))
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "<Transmittal Summary> says thermal attribution "\
                    "is present in <Model>s, but it isn't");
             }
             break;
    } /* end switch */

    SE_InitializeLocalSummary(&summary_summary);
    env_domain_fields.classification_count = 0;
    env_domain_fields.classification_array = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter,
             &(env_domain_fields.classification_count)) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus(
          "check_transmittal_summary:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "can't get iteration length");
        SE_FreeIterator(iter);
        return;
    }
    else if ((env_domain_fields.classification_count > 0) &&
             ((env_domain_fields.classification_array = (SE_Classification_Entry *)
              calloc(env_domain_fields.classification_count,
                     sizeof(SE_Classification_Entry))) == NULL))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "Can't check <Environmental Domain Summary>, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    store = GetGlobalStore(level);

    memset(drm_class_summary, SE_FALSE,
           sizeof(SE_Boolean)*SE_DRM_CLASS_UBOUND);

   /*
    * <<Non Overlapping DRM Class Summary Item Instances>>
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_transmittal_summary:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, store, &next_fields_ptr) ==
            SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(&summary_summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM:
                     if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL) != SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR_SYNTAX, "invalid fields");
                     }
                     else if (drm_class_summary
                              [next_fields_ptr->u.DRM_Class_Summary_Item.drm_class]
                              == SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR,
                       "violates <<Non Overlapping DRM Class Summary Item Instances>>");
                     }
                     else
                     {
                         drm_class_summary[next_fields_ptr->u.DRM_Class_Summary_Item.
                                           drm_class] = SE_TRUE;
                     }
                     break;

                case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
                     check_EDCS_use_summary_item(level, path,
                         next_object, next_fields_ptr, &summary_summary);
                     break;

                case SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY:
                     if (check_classification_data(level+1, path, next_object,
                         next_fields_ptr,
                         &(env_domain_fields.classification_array[i]),
                         &summary_summary) == SE_TRUE)
                     {
                         i++;
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_transmittal_summary:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    env_domain_fields.classification_count = i;

    if ((env_domain_fields.classification_count > 0) &&
        (SE_ValidClassificationParameters(&env_domain_fields, SE_FALSE, NULL)
         != SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
        SE_ValidClassificationParameters(&env_domain_fields, SE_TRUE, NULL);
    }
    SE_FreeClassificationParameters(&env_domain_fields, NULL);
} /* end check_transmittal_summary */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_transmittal_root
 *
 *   Check the <Transmittal Root>.
 *
 * PARAMETERS:
 *
 *   curr_object -- the given object
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
check_transmittal_root
(
    SE_Object curr_object
)
{
    SE_Iterator                iter = NULL;
    SE_Object                  next_object = NULL, trans_summ = NULL;
    SE_FIELDS_PTR              next_fields_ptr = NULL;
    SE_Short_Integer_Unsigned  level = 0;
    SE_Boolean                 models_present = SE_FALSE,
                               images_present = SE_FALSE,
                               sounds_present = SE_FALSE,
                               symbols_present = SE_FALSE,
                               all_models_processed = SE_TRUE,
                               all_roots_processed = SE_TRUE;
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH];
    SE_Store                   store = NULL;
    SE_SRF_Context_Info       *env_root_srf_array = NULL;
    SE_Integer_Positive        comp_count=0, env_root_count=0;
    SE_Time_Significance      *time_sig_array = NULL;
    SE_Integer_Unsigned        time_sig_count = 0;
    SE_LOCAL_SUMMARY           all_roots_summary, env_root_summary,
                               model_library_summary, other_library_summary;
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER primary_pt_tables;

    store = GetGlobalStore(level);

    path[level] = SE_CLS_DRM_TRANSMITTAL_ROOT;

    if (level > global_max_level)
        global_max_level = level;

    SE_UpdateAnalysisCounts();

    if (local_InitializeComponentIterator3(curr_object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(curr_object, SE_CLS_DRM_TRANSMITTAL_ROOT, level,
           path, MSGTYP_ERROR, "Can't initialize iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter, &comp_count)
             != SE_RETCOD_SUCCESS) || (comp_count == 0))
    {
        se_message(curr_object, SE_CLS_DRM_TRANSMITTAL_ROOT, level,
           path, MSGTYP_ERROR, "Can't get iter length or it's zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((env_root_srf_array = (SE_SRF_Context_Info *)
             calloc(comp_count, sizeof(SE_SRF_Context_Info)))==NULL)
    {
        se_message(curr_object, SE_CLS_DRM_TRANSMITTAL_ROOT, level,
           path, MSGTYP_ERROR, "Can't allocate env_root_srf_array");
        SE_FreeIterator(iter);
        return;
    }
    else if ((time_sig_array = (SE_Time_Significance *)
             calloc(comp_count, sizeof(SE_Time_Significance)))==NULL)
    {
        se_message(curr_object, SE_CLS_DRM_TRANSMITTAL_ROOT, level,
           path, MSGTYP_ERROR, "Can't allocate time_sig_array");
        free(env_root_srf_array);
        SE_FreeIterator(iter);
        return;
    }
    SE_InitializeLocalSummary(&all_roots_summary);
    SE_InitializeLocalSummary(&model_library_summary);
    SE_InitializeLocalSummary(&other_library_summary);
    primary_pt_tables.pset_table_group_count = 0;
    primary_pt_tables.pset_table_group_array = NULL;

    if (SE_GetComponent(curr_object, SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
          &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_DRM_Class_Fields dummy_fields;

        dummy_fields.tag = SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY;

        SE_UpdateAnalysisCounts();
        printf("\nChecking <Property Set Table Library>...\n");
        fflush(stdout);

        SE_UpdateLocalSummaryFromFields(&other_library_summary, &dummy_fields);
        check_prop_set_table_library(level+1, path, next_object,
            &other_library_summary, &primary_pt_tables);
        SE_FreeObject(next_object);
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_trans_root:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, store, &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_REFERENCE_ORIGIN:
                     SE_UpdateLocalSummaryFromFields(&other_library_summary,
                                                     next_fields_ptr);

                     check_reference_origin(level+1, path, next_object,
                         next_fields_ptr);
                     break;

                case SE_CLS_DRM_COLOUR_TABLE_LIBRARY:
                     if (world_colour_model_defined)
                     {
                         printf("\nChecking <Colour Table Library>...\n");
                         fflush(stdout);

                         SE_UpdateLocalSummaryFromFields(&other_library_summary, next_fields_ptr);
                         check_colour_table_library(level+1, path, next_object,
                             &other_library_summary);
                     }
                     else
                     {
                         se_message(next_object,
                            SE_CLS_DRM_COLOUR_TABLE_LIBRARY, level, path,
                            MSGTYP_ERROR,
                            "No world colour model, but colours present; "\
                            "won't check library");
                     }
                     break;

                case SE_CLS_DRM_DATA_TABLE_LIBRARY:
                     printf("\nChecking <Data Table Library>...\n");
                     fflush(stdout);

                     SE_UpdateLocalSummaryFromFields(&other_library_summary, next_fields_ptr);
                     check_data_table_library(level+1, path, next_object,
                         &other_library_summary);
                     break;

                case SE_CLS_DRM_ENVIRONMENT_ROOT:
                     printf("\nChecking <Environment Root>...\n");
                     fflush(stdout);

                     if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE, NULL)
                         == SE_TRUE)
                     {
                         SE_Integer_Unsigned j = 0;
                         SE_Boolean          unique_srf = SE_TRUE;

                         unique_srf = SE_TRUE;

                         for (j = 0; (unique_srf==SE_TRUE) &&
                                     j < env_root_count; j++)
                         {
                             if (SE_SRFContextInfoEqual(
                                 &(env_root_srf_array[j]),
                &(next_fields_ptr->u.Environment_Root.srf_context_info))
                                 == SRM_TRUE)
                             {
                                 unique_srf = SE_FALSE;
                             }
                         }

                         if (unique_srf == SE_TRUE)
                         {
                             memcpy(&(env_root_srf_array[env_root_count]),
                                    &(next_fields_ptr->u.Environment_Root.
                                    srf_context_info),
                                    sizeof(SE_SRF_Context_Info));
                             env_root_count++;
                         }
                         else
                         {
                             se_message(next_object, next_fields_ptr->tag,
                               level+1, path, MSGTYP_ERROR,
                               "violates <<Environment Root SRF>>,"\
                               " part 1");
                         }
                         check_env_root(level+1, path,
                             next_object, next_fields_ptr,
                             &env_root_summary, &primary_pt_tables);
                         SE_UpdateLocalSummary(&all_roots_summary,
                                               &env_root_summary);
                     }
                     else
                     {
                         all_roots_processed = SE_FALSE;
                         se_message(next_object, next_fields_ptr->tag,
                            level+1, path, MSGTYP_ERROR_SYNTAX,
                            "Invalid fields, aborting check");
                     }
                     break;

                case SE_CLS_DRM_IMAGE_LIBRARY:
                     printf("\nChecking <Image Library>...\n");
                     fflush(stdout);
                     images_present = SE_TRUE;

                     SE_UpdateLocalSummaryFromFields(&other_library_summary, next_fields_ptr);
                     check_image_library(level+1, path, next_object,
                         &other_library_summary);
                     break;

                case SE_CLS_DRM_MODEL_LIBRARY:
                     printf("\nChecking <Model Library>...\n");
                     fflush(stdout);
                     models_present = SE_TRUE;

                     check_model_library(level+1, path, next_object,
                           &all_models_processed, &model_library_summary,
                           &primary_pt_tables);
                     break;

                case SE_CLS_DRM_SOUND_LIBRARY:
                     printf("\nChecking <Sound Library>...\n");
                     fflush(stdout);
                     sounds_present = SE_TRUE;

                     SE_UpdateLocalSummaryFromFields(&other_library_summary, next_fields_ptr);
                     check_sound_library(level+1, path, next_object,
                         &other_library_summary);
                     break;

                case SE_CLS_DRM_SYMBOL_LIBRARY:
                     printf("\nChecking <Symbol Library>...\n");
                     fflush(stdout);
                     symbols_present = SE_TRUE;

                     SE_UpdateLocalSummaryFromFields(&other_library_summary, next_fields_ptr);
                     check_symbol_library(level+1, path, next_object,
                         &other_library_summary);
                     break;

                default:
                     SE_UpdateLocalSummaryFromFields(&other_library_summary, next_fields_ptr);
                     check_attribute(level+1, path, next_object,
                         next_fields_ptr, NULL, &other_library_summary);
                     if ((SE_IsA[next_fields_ptr->tag]
                         [SE_CLS_DRM_BASE_TIME_DATA]==SE_TRUE) &&
                         SE_ValidTimeSignificance
                         (next_fields_ptr->u.Base_Time_Data.time_significance))
                     {
                         SE_Integer_Unsigned j = 0;
                         SE_Boolean          unique_significance = SE_TRUE;

                         unique_significance = SE_TRUE;

                         for (j = 0; (unique_significance==SE_TRUE) &&
                              j < time_sig_count; j++)
                         {
                             if (time_sig_array[j] ==
                         next_fields_ptr->u.Base_Time_Data.time_significance)
                             {
                                 unique_significance = SE_FALSE;
                             }
                         }

                         if (unique_significance == SE_TRUE)
                         {
                             time_sig_array[time_sig_count] =
                                 next_fields_ptr->u.Base_Time_Data.time_significance;
                             time_sig_count++;
                         }
                         else
                         {
                             se_message(next_object, next_fields_ptr->tag,
                               level+1, path, MSGTYP_ERROR,
                               "violates <<Distinct Time Significance>>");
                         }
                     }
                     break;
            }
        }
        else
        {
            printLastFnctStatus("check_transmittal_root:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    } /* end while */

    if (primary_pt_tables.pset_table_group_count > 0)
    {
        if (primary_pt_tables.pset_table_group_array != NULL)
        {
            while (primary_pt_tables.pset_table_group_count > 0)
            {
                primary_pt_tables.pset_table_group_count--;
                SE_FreeObject(primary_pt_tables.pset_table_group_array
                              [primary_pt_tables.pset_table_group_count].
                              pset_group);
            }
            free(primary_pt_tables.pset_table_group_array);
        }
        primary_pt_tables.pset_table_group_array = NULL;
        primary_pt_tables.pset_table_group_count = 0;
    }
    SE_FreeIterator(iter);
    free(env_root_srf_array);
    free(time_sig_array);

    if (SE_GetComponent(curr_object, SE_CLS_DRM_TRANSMITTAL_SUMMARY, SE_FALSE,
           SE_FALSE, SE_ITRBEH_RESOLVE,
          &trans_summ, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR trans_summ_fields = NULL;

        if (SE_GetFields(trans_summ, store, &trans_summ_fields)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(&other_library_summary,
                trans_summ_fields);

            check_transmittal_summary(level+1, path,
                trans_summ, trans_summ_fields,
                images_present, models_present, sounds_present, symbols_present,
                all_roots_processed, &all_roots_summary,
                all_models_processed, &model_library_summary,
                &other_library_summary);
        }
        else
        {
            printLastFnctStatus("check_transmittal_root:SE_GetFields");
            se_message(trans_summ, SE_CLS_DRM_TRANSMITTAL_SUMMARY, level+1,
               path, MSGTYP_ERROR, "Can't get fields");
            trans_summ_fields = NULL;
        }
        SE_FreeObject(trans_summ);
    }
} /* end check_transmittal_root */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: print_usage_and_exit
 *
 *-----------------------------------------------------------------------------
 */
static void
print_usage_and_exit
(
    const char *err_msg
)
{
    fprintf(stderr, "%s\n\n", err_msg);

    fprintf(stderr,
"rules_checker checks the correctness of the given SEDRIS transmittal, "\
"with regard to constraints.\n"\
"\n"\
"Usage: rules_checker [options] <SEDRIS_transmittal_file>\n"\
"\n"\
" Options:\n" \
"\n" \
"  -f <file name> = file name for formatted output\n" \
"  -u <update rate> = update object count (off=0, default=%u)\n"\
"\n" \
"Examples:\n" \
"  rules_checker test.stf -f error_output.txt\n",
    (SE_Integer_Unsigned) DEFAULT_UPDATE_RATE);
    fflush(stderr);
    exit(-1);
} /* end print_usage_and_exit */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: process_arguments
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
process_arguments
(
    int     argc,
    char   *argv[],
    SE_URL *transmittal_location_ptr
)
{
    SE_Boolean result = SE_TRUE;

    if (argc < 2)
    {
        print_usage_and_exit("");
    }
    argv++;
    argc--;

    transmittal_location_ptr->length     = 0;
    transmittal_location_ptr->characters = NULL;

    while (argc > 0)
    {
        if ((*argv)[0] == '-')
        {
            if ((*argv)[1] == 'u')
            {
                int temp;

                argv++;
                argc--;

                if (argv)
                {
                    temp = atoi(*argv);

                    argv++;
                    argc--;

                    if ((temp < 0) || (temp > SRM_INTEGER_UNSIGNED_MAX))
                    {
                        print_usage_and_exit
                        ("-u option specifies invalid update rate");
                        result = SE_FALSE;
                    }
                    else
                    {
                        global_update_rate = (SE_Integer_Unsigned) temp;
                    }
                }
                else
                {
                    print_usage_and_exit("-u option missing update rate");
                    result = SE_FALSE;
                }
            }
            else if ((*argv)[1] == 'f')
            {
                if (argc > 1)
                {
                    argv++;
                    argc--;

                    file_output_option = SE_TRUE;

                    if ((file_output=fopen(*argv, "w")) == NULL)
                    {
                        char msg[200];
                        sprintf("-f option supplied filename (%s) that "\
                                "could not be opened", *argv);
                        print_usage_and_exit(msg);
                        result = SE_FALSE;
                    }
                    argc--;
                    argv++;
                }
                else
                {
                    print_usage_and_exit
                    ("-f option missing filename");
                    result = SE_FALSE;
                }
            }
            else
            {
                print_usage_and_exit("unsupported option");
                result = SE_FALSE;
            }
        }
        else if (transmittal_location_ptr->length == 0)
        {
            SE_SetURL(*argv, transmittal_location_ptr);
            argc--;
            argv++;
        }
        else
        {
            print_usage_and_exit("only 1 transmittal allowed");
            result = SE_FALSE;
        }
    }

    if (transmittal_location_ptr->characters==NULL)
    {
        print_usage_and_exit("no transmittal specified");
        result = SE_FALSE;
    }
    else
    {
        fprintf(stdout, "Update rate set to every %u objects processed\n",
                global_update_rate);
        fflush(stdout);
    }
    return result;
} /* end process_arguments */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *    Test the correctness of the given SEDRIS transmittal by testing each
 *    object within the transmittal against the constraints documented for
 *    the SEDRIS DRM.
 *
 * RETURNS:
 *    0 if all is well.
 *    -1 if any errors are found.
 *
 *-----------------------------------------------------------------------------
 */
int main
(
    int   argc,
    char *argv[]
)
{
    SE_URL         transmittal_location;
    SE_Transmittal transmittal = NULL;

    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

   /*
    * Parse the arguments
    */
    if (!process_arguments(argc, argv, &transmittal_location))
    {
        return 1;
    }

    if (SE_OpenTransmittalByLocation(&transmittal_location,
        implementation_encoding, SE_AM_READ_ONLY, &transmittal)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Can't open SEDRIS Transmittal %s!\n",
                SE_GetURLAsCharString(&transmittal_location));
        exit(-1);
    }
    else
    {
        fprintf(stdout,"Opened SEDRIS Transmittal %s.\n",
                SE_GetURLAsCharString(&transmittal_location));
    }

    if (SE_GetRootObject(transmittal, &root_obj) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Fatal Error - can't retrieve root object of "\
                "transmittal\n");
        exit(-1);
    }

    if (SE_GetColourModel(transmittal, &world_colour_model) ==
                          SE_RETCOD_SUCCESS)
    {
        world_colour_model_defined = SE_TRUE;
    }
    InitGlobals();

    check_transmittal_root(root_obj);

    FreeGlobals();
    SE_FreeObject(root_obj);

    if (SE_CloseTransmittal(transmittal) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Can't close transmittal %s!\n",
                SE_GetURLAsCharString(&transmittal_location));
    }
    SE_FreeURL(&transmittal_location, NULL);
    return 0;
} /* end main */
