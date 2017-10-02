/*
 * FILE       : model.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a transmittal, with
 *    regard to constraints affecting <Model>s.
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
#include "control_link.h"
#include "feature.h"
#include "geometry.h"
#include "metadata.h"
#include "model.h"
#include "prop_set_table.h"

typedef struct
{
    SE_Boolean   has_CD;
    SE_Boolean   CD_tag_is_NULL;
    SE_DRM_Class fh_tag;
    SE_DRM_Class gh_tag;
} EMPTY_MODEL_INFO;


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_model
 *
 *-----------------------------------------------------------------------------
 */
static void
check_feature_model
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_model,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    EMPTY_MODEL_INFO          *empty_model_info
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_FEATURE_MODEL;

    if (local_InitializeComponentIterator3(feature_model, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_feature_model:SE_InitializeComponentIterator");
        se_message(feature_model, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_feature_model:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
            {
                empty_model_info->fh_tag = next_fields_ptr->tag;

                check_feature_hierarchy(level+1, path, next_object,
                     next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    context, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_feature_model:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_feature_model */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_geometry_model
 *
 *-----------------------------------------------------------------------------
 */
static void
check_geometry_model
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  geometry_model,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    EMPTY_MODEL_INFO          *empty_model_info
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;
    SE_Boolean    has_lsr_comps   = SE_FALSE, has_point_comps = SE_FALSE;

    path[level] = SE_CLS_DRM_GEOMETRY_MODEL;

    if (local_InitializeComponentIterator3(geometry_model, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_geometry_model:SE_InitializeComponentIterator");
        se_message(geometry_model, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_geometry_model:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_ATTACHMENT_POINT:
                case SE_CLS_DRM_CONTACT_POINT:
                {
                    SE_Object     location = NULL;
                    SE_FIELDS_PTR loc_fields_ptr = NULL;

                    has_point_comps = SE_TRUE;

                    if (SE_GetComponent(next_object, SE_CLS_DRM_LOCATION, SE_FALSE,
                         SE_FALSE, SE_ITRBEH_RESOLVE, &location, NULL)
                         == SE_RETCOD_SUCCESS)
                    {
                        SE_UpdateAnalysisCounts();
                        if (SE_GetFields(location, GetGlobalTempStore(level),
                            &loc_fields_ptr) == SE_RETCOD_SUCCESS)
                        {
                            SE_UpdateLocalSummaryFromFields(summary, loc_fields_ptr);

                            check_location(level+1, path, location, loc_fields_ptr,
                                  NULL, context, summary);
                        }
                        else
                        {
                            path[level+1] = next_fields_ptr->tag;
                            se_message(location, SE_CLS_DRM_LOCATION, level+2, path,
                               MSGTYP_ERROR, "Can't get fields");
                        }
                        SE_FreeObject(location);
                    }
                    else
                    {
                        se_message(next_object, next_fields_ptr->tag, level+1, path,
                           MSGTYP_ERROR, "Can't get <Location> component");
                    }
                }
                break;

                case SE_CLS_DRM_LSR_TRANSFORMATION:
                     has_lsr_comps = SE_TRUE;

                     check_LSR_transformation(level+1, path, next_object,
                        context, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         empty_model_info->gh_tag = next_fields_ptr->tag;
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else
                     {
                         check_attribute(level+1, path, next_object, next_fields_ptr,
                             context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_geometry_model:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path, MSGTYP_ERROR,
               "Can't get fields");
        }
        SE_FreeObject(next_object);
    }

    if (empty_model_info->gh_tag == SE_CLS_DRM_NULL)
    {
        if (has_point_comps == SE_TRUE)
        {
            se_message(geometry_model, path[level], level, path, MSGTYP_ERROR,
               "violates <<Non-Empty Model Instance>> constraint - has no "\
               "<Geometry Hierarchy> but contains an <Attachment Point>"\
               " or <Contact Point>");
        }
        if (has_lsr_comps == SE_TRUE)
        {
            se_message(geometry_model, path[level], level, path, MSGTYP_ERROR,
               "violates <<Non-Empty Model Instance>> constraint - has no "\
               "<Geometry Hierarchy> but contains an "\
               "<LSR Transformation>");
        }
    }
    SE_FreeIterator(iter);
} /* end check_geometry_model */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_model
 *
 *-----------------------------------------------------------------------------
 */
static void
check_model
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              model,
    SE_FIELDS_PTR                          fields_ptr,
    SE_Boolean                            *all_models_processed_ptr,
    SE_LOCAL_SUMMARY                      *summary_ptr,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_pt_tables
)
{
    SE_Iterator           iter = NULL;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_LOCAL_CONTEXT      context;
    SE_Element_Code_Queue eac_queue;
    char                  err_msg[1024];
    SE_Object             class_data_obj = NULL;
    EMPTY_MODEL_INFO      empty_model_info;
    SE_DRM_Class          fh_summ_tag = SE_CLS_DRM_NULL,
                          gh_summ_tag = SE_CLS_DRM_NULL;
    SE_Boolean            has_f_model = SE_FALSE, has_g_model = SE_FALSE,
                          is_empty_model = SE_FALSE,
                          valid_empty_model = SE_TRUE;
    SE_LOCAL_SUMMARY      summary_summary;

    path[level] = SE_CLS_DRM_MODEL;

    if (SE_ValidDRMClassFields(fields_ptr, SE_TRUE, NULL) != SE_TRUE)
    {
        se_message(model, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "Invalid fields, aborting check");
        *all_models_processed_ptr = SE_FALSE;
        return;
    }
    else
    {
        printf("\nChecking <Model> %s...\n",
               (SE_GetStringAsCharString(&(fields_ptr->u.Model.name)) == NULL)
             ? "" : SE_GetStringAsCharString(&(fields_ptr->u.Model.name)));
        fflush(stdout);
    }
    empty_model_info.has_CD         = SE_FALSE;
    empty_model_info.CD_tag_is_NULL = SE_FALSE;
    empty_model_info.fh_tag         = SE_CLS_DRM_NULL;
    empty_model_info.gh_tag         = SE_CLS_DRM_NULL;

    if (SE_GetComponent(model, SE_CLS_DRM_CLASSIFICATION_DATA, SE_FALSE,
        SE_FALSE, SE_ITRBEH_RESOLVE, &class_data_obj, NULL)
        == SE_RETCOD_SUCCESS)
    {
        /* begin scope for first use of global store */
        SE_FIELDS_PTR class_data_fields_ptr = NULL;

       /*
        * A <Classification Data> instance was returned.
        * We're not considering multiple objects returned,
        * because syntax_checker guarantees there's at most one.
        */
        empty_model_info.has_CD  = SE_TRUE;

        if (SE_GetFields(class_data_obj, GetGlobalStore(level),
            &class_data_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary_ptr, class_data_fields_ptr);

            if (class_data_fields_ptr->u.Classification_Data.tag==ECC_OBJECT)
            {
                empty_model_info.CD_tag_is_NULL = SE_TRUE;
                is_empty_model                  = SE_TRUE;
            }
            else
            {
                empty_model_info.CD_tag_is_NULL = SE_FALSE;
            }
        }
        else
        {
            se_message(class_data_obj, SE_CLS_DRM_CLASSIFICATION_DATA, level+1,
               path, MSGTYP_ERROR, "Can't get fields");
            empty_model_info.CD_tag_is_NULL = SE_FALSE;
        }
    }
    else
    {
        empty_model_info.has_CD  = SE_FALSE;
        empty_model_info.CD_tag_is_NULL = SE_FALSE;
    }
    SE_FreeObject(class_data_obj);

    if (local_InitializeComponentIterator3(model, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_model:SE_InitializeComponentIterator");
        se_message(model, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize iter");
        *all_models_processed_ptr = SE_FALSE;
        return;
    }

   /*
    * SE_InitializeLocalContext deals with <Spatial Extent>
    */
    SE_InitializeLocalContext(level, path, model, fields_ptr,
                              primary_pt_tables, &context);
    eac_queue.head = NULL;
    eac_queue.tail = NULL;

    SE_InitializeLocalSummary(summary_ptr);
    SE_InitializeLocalSummary(&summary_summary);
    has_f_model = SE_FALSE;
    has_g_model = SE_FALSE;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_model:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary_ptr, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_FEATURE_MODEL:
                     has_f_model = SE_TRUE;
                     check_feature_model(level+1, path, next_object,
                         &context, summary_ptr, &empty_model_info);
                     break;

                case SE_CLS_DRM_GEOMETRY_MODEL:
                     has_g_model = SE_TRUE;
                     check_geometry_model(level+1, path, next_object,
                         &context, summary_ptr, &empty_model_info);
                     break;

                case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
                     if (SE_ValidDRMClassFields(next_fields_ptr, SE_FALSE,
                         NULL) != SE_TRUE)
                     {
                         se_message(next_object, next_fields_ptr->tag, level, path,
                            MSGTYP_ERROR_SYNTAX, "invalid fields");
                     }
                     else if ((fh_summ_tag != SE_CLS_DRM_NULL) &&
                              (SE_IsA[next_fields_ptr->u.Hierarchy_Summary_Item.
                              drm_class][SE_CLS_DRM_FEATURE_HIERARCHY]==SE_TRUE))
                     {
                         se_message(next_object, next_fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "violates "\
                            "<<Hierarchy Summary Constraints>>, part 4");
                     }
                     else if ((gh_summ_tag != SE_CLS_DRM_NULL) &&
                              (SE_IsA[next_fields_ptr->u.Hierarchy_Summary_Item.
                              drm_class][SE_CLS_DRM_GEOMETRY_HIERARCHY]==SE_TRUE))
                     {
                         se_message(next_object, next_fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "violates "\
                            "<<Hierarchy Summary Constraints>>, part 4");
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
                     check_primitive_summary_item(level+1, path,
                        next_object, next_fields_ptr, &summary_summary);
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_queue, summary_ptr);
                     break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                         &context, summary_ptr);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_model:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level, path,
                MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_queue);

    if (context.has_variables)
    {
        check_template_list(level+1, path, &(context.interface_template),
            err_msg);
    }
    SE_FreeLocalContext(&context);

    if ((has_f_model != SE_TRUE) && (has_g_model != SE_TRUE))
    {
        valid_empty_model = SE_FALSE;
        se_message(model, path[level], level, path, MSGTYP_ERROR,
           "Violates <<Non-Empty Model Instance>> constraint: <Model> shall " \
           "have a <Feature Model>, <Geometry Model>, or both");
    }
    else
    {
        if (empty_model_info.fh_tag != SE_CLS_DRM_NULL)
        {
            summary_ptr->features_present = SE_TRUE;
        }
        if (empty_model_info.gh_tag != SE_CLS_DRM_NULL)
        {
            summary_ptr->geometry_present = SE_TRUE;
        }
    }

    if (fh_summ_tag != SE_CLS_DRM_NULL)
    {
        if (empty_model_info.fh_tag == SE_CLS_DRM_NULL)
        {
            se_message(model, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "summarizes a <Feature Hierarchy> where no "\
               "non-empty <Feature Model> is present");
        }
        else if (SE_IsA[empty_model_info.fh_tag][fh_summ_tag] != SE_TRUE)
        {
            se_message(model, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "drm_class field doesn't correspond to the class of "\
               "the <Feature Model>'s <Feature Hierarchy>");
        }
    }

    if (gh_summ_tag != SE_CLS_DRM_NULL)
    {
        if (empty_model_info.gh_tag == SE_CLS_DRM_NULL)
        {
            se_message(model, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "summarizes a <Geometry Hierarchy> where no "\
               "non-empty <Geometry Model> is present");
        }
        else if (SE_IsA[empty_model_info.gh_tag][gh_summ_tag] != SE_TRUE)
        {
            se_message(model, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Hierarchy Summary Constraints>> constraint: "\
               "drm_class field doesn't correspond to the class of "\
               "the <Geometry Model>'s <Geometry Hierarchy>");
        }
    }

   /*
    * check here for empty model constraint and its
    * relationship to <<Hierarchy Summary Constraints>>
    */
    if (empty_model_info.has_CD)
    {
        if (empty_model_info.CD_tag_is_NULL)
        {
            if ((empty_model_info.fh_tag != SE_CLS_DRM_NULL) &&
                (has_f_model == SE_TRUE))
            {
                valid_empty_model = SE_FALSE;
                se_message(model, path[level], level, path, MSGTYP_ERROR,
                   "Violates <<Non-Empty Model Instance>> constraint: "\
                   "<Model>'s <Classification Data> indicates "\
                   "empty but <Feature Model> isn't empty");
            }
            if ((empty_model_info.gh_tag != SE_CLS_DRM_NULL) &&
                (has_g_model == SE_TRUE))
            {
                valid_empty_model = SE_FALSE;
                se_message(model, path[level], level, path, MSGTYP_ERROR,
                   "Violates <<Non-Empty Model Instance>> constraint: "\
                   "<Model>'s <Classification Data> indicates "\
                   "empty but <Geometry Model> isn't empty");
            }
        }
        else /* CD tag is not NULL */
        {
            if ((empty_model_info.fh_tag == SE_CLS_DRM_NULL) &&
                (has_f_model == SE_TRUE))
            {
                valid_empty_model = SE_FALSE;
                se_message(model, path[level], level, path, MSGTYP_ERROR,
                   "Violates <<Non-Empty Model Instance>> constraint: "\
                   "<Model>'s <Classification Data> isn't appropriate "\
                   "for an empty <Model>, but <Feature Model> is empty");
            }
            if ((empty_model_info.gh_tag == SE_CLS_DRM_NULL) &&
                (has_g_model == SE_TRUE))
            {
                valid_empty_model = SE_FALSE;
                se_message(model, path[level], level, path, MSGTYP_ERROR,
                   "Violates <<Non-Empty Model Instance>> constraint: "\
                   "<Model>'s <Classification Data> isn't appropriate "\
                   "for an empty <Model>, but <Geometry Model> is empty");
            }
        }
    }
    else /* no CD component */
    {
        if ((empty_model_info.fh_tag == SE_CLS_DRM_NULL) &&
            (has_f_model == SE_TRUE))
        {
            valid_empty_model = SE_FALSE;
            se_message(model, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Non-Empty Model Instance>> constraint: "\
               "<Model> doesn't have appropriate <Classification Data> "\
               "but <Feature Model> is empty");
        }
        if ((empty_model_info.gh_tag == SE_CLS_DRM_NULL) &&
            (has_g_model == SE_TRUE))
        {
            valid_empty_model = SE_FALSE;
            se_message(model, path[level], level, path, MSGTYP_ERROR,
               "Violates <<Non-Empty Model Instance>> constraint: "\
               "<Model> doesn't have appropriate <Classification Data> "\
               "but <Geometry Model> is empty");
        }
    }

    if ((is_empty_model == SE_TRUE) &&
        (valid_empty_model == SE_TRUE) &&
        (fields_ptr->u.Model.model_reference_type != SE_MODREFTYP_ROOT_AND_COMPONENT))
    {
        se_message(model, path[level], level, path, MSGTYP_ERROR,
           "Violates <<Non-Empty Model Instance>> constraint: "\
           "<Model> is empty but model_reference_type != " \
           "SE_MODREFTYP_ROOT_AND_COMPONENT ");
    }
} /* end check_model */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_model_library
 *
 *-----------------------------------------------------------------------------
 */
void
check_model_library
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              model_library,
    SE_Boolean                            *all_models_processed_ptr,
    SE_LOCAL_SUMMARY                      *summary_ptr,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_pt_tables
)
{
    SE_Iterator           iter = NULL;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Integer_Unsigned   root_model_count=0, i;
    char                **root_name_list = NULL;
    SE_LOCAL_SUMMARY      model_summary;

    SE_InitializeLocalSummary(summary_ptr);

   /*
    * Used to check the Classification Data tag for empty model
    * implementation
    */
    path[level] = SE_CLS_DRM_MODEL_LIBRARY;

    if (local_InitializeComponentIterator3(model_library, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_model_library:SE_InitializeComponentIterator");
        se_message(model_library, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iter");
        *all_models_processed_ptr = SE_FALSE;
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter, &root_model_count)
             != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_model_library:SE_GetIterationLengthRemaining");
        se_message(model_library, path[level], level, path, MSGTYP_ERROR,
           "Can't get iteration length");
        SE_FreeIterator(iter);
        *all_models_processed_ptr = SE_FALSE;
        return;
    }
    else if ((root_name_list=(char **)calloc(root_model_count, sizeof(char *)))
             == NULL)
    {
        se_message(model_library, path[level], level, path, MSGTYP_ERROR,
           "Can't allocate space for root model name list");
        SE_FreeIterator(iter);
        *all_models_processed_ptr = SE_FALSE;
        return;
    }
    root_model_count = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_model_library:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary_ptr, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_MODEL:
                     if (next_fields_ptr->u.Model.model_reference_type !=
                         SE_MODREFTYP_COMPONENT)
                     {
                         SE_Boolean   found = SE_FALSE;

                         if (SE_ValidNonNullString(&(next_fields_ptr->u.Model.name),
                             SE_FALSE, NULL))
                         {
                             root_name_list[root_model_count] = (char *)
                                 calloc(next_fields_ptr->u.Model.name.length+1,
                                        sizeof(char));

                             strcpy(root_name_list[root_model_count],
                                    next_fields_ptr->u.Model.name.characters);

                             for (i = 0; i < root_model_count; i++)
                             {
                                 if (strcmp(root_name_list[root_model_count],
                                            root_name_list[i])==0)
                                 {
                                     se_message(next_object, next_fields_ptr->tag,
                                        level, path, MSGTYP_ERROR,
                                        "violates <<Model Reference Type Constraints>>: "\
                                        "Not an SE_MODREFTYP_COMPONENT, but name "\
                                        "is not unique");
                                 }
                             }
                         }
                         else
                         {
                             se_message(next_object, next_fields_ptr->tag, level, path,
                                MSGTYP_ERROR,
                                "violates <<Model Reference Type Constraints>>: "\
                                "<Model> has an empty or invalid name but "\
                                "is not an SE_MODREFTYP_COMPONENT");
                             root_name_list[root_model_count] = "\0";
                         }
                         root_model_count++;
                     }
                     check_model(level+1, path, next_object, next_fields_ptr,
                         all_models_processed_ptr, &model_summary,
                         primary_pt_tables);

                     SE_UpdateLocalSummary(summary_ptr, &model_summary);
                     break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                         NULL, summary_ptr);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_model_library:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    for (i = 0; i < root_model_count; i++)
    {
        if (strlen(root_name_list[i]) > 0)
            free(root_name_list[i]);
    }
    free(root_name_list);
} /* end check_model_library */
