/*
 * FILE       : feature.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a SEDRIS transmittal, with
 *    regard to constraints affecting <Feature Representation> instances.
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
#include "data_table.h"
#include "feature.h"
#include "metadata.h"
#include "prop_set_table.h"
#include "sound_symbol.h"

static void
check_perimeter_related_feature_topology
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_primitive_feature
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  primitive_feature,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_spatial_index_related_feature_topology
(
          SE_Short_Integer_Unsigned                 level,
          SE_DRM_Class                              path
                                                    [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                 object,
    const SE_Spatial_Index_Related_Feature_Topology_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                                 *context,
          SE_LOCAL_SUMMARY                                 *summary
);

static void
check_topology_hierarchy
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_union_of_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_union_of_features
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                 inherits_classification_data
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Boolean            pass_down_classification_data = SE_FALSE;

    path[level] = fields_ptr->tag;

    if (SE_GetComponent(object, SE_CLS_DRM_CLASSIFICATION_DATA, SE_FALSE,
        SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(next_object, GetGlobalStore(level),
               &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_Classification_Entry entry;

            check_classification_data
            (level+1, path, next_object, next_fields_ptr, &entry, summary);

            SE_FreeClassificationEntry(&entry, NULL);
        }
        else
        {
            printLastFnctStatus
            ("check_union_of_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_CLASSIFICATION_DATA, level+1,
               path, MSGTYP_ERROR, "can't get fields");
        }

        if (fields_ptr->u.Union_Of_Features.union_reason ==
            SE_UNIONREAS_OTHER)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
             "union_reason violates <<Classification Data Constraints>> "\
             "(has <Classification Data> so union_reason cannot "\
             "be SE_UNIONREAS_OTHER)");
        }
        else if (fields_ptr->u.Union_Of_Features.union_reason ==
                 SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS)
        {
            pass_down_classification_data = SE_TRUE;
        }
    }
    else if ((fields_ptr->u.Union_Of_Features.union_reason ==
              SE_UNIONREAS_OTHER) &&
             (inherits_classification_data == SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
         "union_reason violates <<Classification Data Constraints>> "\
         "(inherits <Classification Data> so union_reason cannot "\
         "be SE_UNIONREAS_OTHER)");
    }
    else if ((fields_ptr->u.Union_Of_Features.union_reason ==
             SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS) &&
             (inherits_classification_data == SE_TRUE))
    {
        pass_down_classification_data = SE_TRUE;
    }
    else if ((fields_ptr->u.Union_Of_Features.union_reason !=
              SE_UNIONREAS_OTHER) &&
             (inherits_classification_data != SE_TRUE))
    {
       /*
        * $$$ what if only some contexts for the
        * $$$ <Union Of Features> supply <Classification Data>?
        * $$$ will get different answers for the different contexts there
        */
        se_message(object, path[level], level, path, MSGTYP_ERROR,
         "union_reason violates <<Classification Data Constraints>> "\
         "(no direct or inherited <Classification Data> but union_reason != "\
         "SE_UNIONREAS_OTHER)");
    }
    SE_FreeObject(next_object);
    next_object = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_union_of_features:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_union_of_features:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE,
                             pass_down_classification_data);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_PRIMITIVE_FEATURE])
                     {
                         check_primitive_feature(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                     }
                     else if (next_fields_ptr->tag!=SE_CLS_DRM_CLASSIFICATION_DATA)
                     {
                         check_attribute(level+1, path, next_object, next_fields_ptr,
                             context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus
            ("check_union_of_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_union_of_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_alt_hier_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_alt_hier_related_features
(
          SE_Short_Integer_Unsigned            level,
          SE_DRM_Class                         path
                                               [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                       object,
    const SE_Alternate_Hierarchy_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                               *context,
          SE_LOCAL_SUMMARY                               *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Element_Code_Queue       eac_val_queue;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         i = 0;
    SE_Alternate_Hierarchy_Parameters link_fields;
    SE_FIELDS_PTR                     link_fields_ptr = NULL, next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter,
             &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_alt_hier_related_features:local_InitializeComponentIterator3");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &link_fields.hierarchy_data_count) !=SE_RETCOD_SUCCESS) ||
             (link_fields.hierarchy_data_count < 1))
    {
        printLastFnctStatus(
          "check_alt_hier_related_features:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.hierarchy_data_array = (SE_Hierarchy_Data_Fields *)
              calloc(link_fields.hierarchy_data_count,
                     sizeof(SE_Hierarchy_Data_Fields))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_alt_hier_related_features:SE_GetNextObject");
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

                 default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         SE_DRM_Class_Fields clone_fields;

                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) != SE_RETCOD_SUCCESS)
                         {
                             printLastFnctStatus
                             ("check_alt_hier_related_features:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_HIERARCHY_DATA, level+1, path,
                                MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         else if (SE_CloneFields(link_fields_ptr, &clone_fields) !=
                                  SE_DRM_STAT_CODE_SUCCESS)
                         {
                             se_message(link_object, SE_CLS_DRM_HIERARCHY_DATA, level+1, path,
                                MSGTYP_ERROR, "Can't clone fields of link object");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();

                             memcpy(&(link_fields.hierarchy_data_array[i]),
                                    &(clone_fields.u.Hierarchy_Data),
                                    sizeof(SE_Hierarchy_Data_Fields));
                             i++;
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                              [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus
            ("check_alt_hier_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if (i > 0)
    {
        link_fields.hierarchy_data_count = i;

        if (!SE_ValidAlternateHierarchyParameters(&link_fields, SE_FALSE, NULL))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "branches violate <<Distinct Link Objects>>");
            SE_ValidAlternateHierarchyParameters(&link_fields, SE_TRUE, NULL);
        }
    }
    SE_FreeAlternateHierarchyParameters(&link_fields, NULL);
} /* end check_alt_hier_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_classification_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_classification_related_features
(
          SE_Short_Integer_Unsigned                  level,
          SE_DRM_Class                               path
                                                     [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                  object,
    const SE_Classification_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                          *context,
          SE_LOCAL_SUMMARY                          *summary
)
{
    SE_Iterator                  iter = NULL;
    SE_Element_Code_Queue        eac_val_queue;
    SE_Object                    link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned          i = 0;
    SE_FIELDS_PTR                link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_Classification_Parameters link_fields;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus(
         "check_classification_related_features:InitializeComponentIterator3");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
              &link_fields.classification_count) !=SE_RETCOD_SUCCESS)
          || (link_fields.classification_count < 1))
    {
        printLastFnctStatus(
         "check_classification_related_features:GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.classification_array = (SE_Classification_Entry *)
              calloc(link_fields.classification_count,
                     sizeof(SE_Classification_Entry))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
               != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_classification_related_features:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) == SE_RETCOD_SUCCESS)
                         {
                             SE_UpdateAnalysisCounts();

                             if (check_classification_data(level, path, link_object,
                                 link_fields_ptr, &(link_fields.classification_array[i]),
                                 summary) == SE_TRUE)
                             {
                                 i++;
                             }
                         }
                         else
                         {
                             printLastFnctStatus
                             ("check_classification_related_features:SE_GetFields");
                             se_message(next_object, next_fields_ptr->tag, level, path,
                                MSGTYP_ERROR,
                                "can't get fields of corresponding <Classification Data>");
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_TRUE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus
            ("check_classification_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);

        if (link_object)
            SE_FreeObject(link_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    link_fields.classification_count = i;

    if ((link_fields.classification_count > 0) &&
        (SE_ValidClassificationParameters(&link_fields, SE_FALSE, NULL)
         != SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
        SE_ValidClassificationParameters(&link_fields, SE_TRUE, NULL);
    }
    SE_FreeClassificationParameters(&link_fields, NULL);
} /* end check_classification_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_LODRF
 *
 *-----------------------------------------------------------------------------
 */
static void
check_LODRF
(
          SE_Short_Integer_Unsigned       level,
          SE_DRM_Class                    path
                                          [MAX_CHECKER_PATH_LENGTH],
          SE_Object                       object,
    const SE_LOD_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT               *context,
          SE_LOCAL_SUMMARY               *summary
)
{
    SE_Iterator              iter = NULL;
    SE_Element_Code_Queue    eac_val_queue;
    SE_Object                link_object = NULL, next_object = NULL;
    SE_DRM_Class             expected_tag = SE_CLS_DRM_NULL;
    SE_Integer_Unsigned      i = 0;
    SE_FIELDS_PTR            link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_LOD_Select_Parameters link_fields;

    if (local_InitializeComponentIterator3(object, search_filter,
          &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &link_fields.lod_entry_count) != SE_RETCOD_SUCCESS)
          || (link_fields.lod_entry_count < 1))
    {
        printLastFnctStatus(
         "check_LODRF:GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.lod_entry_array = (SE_LOD_Entry *)
            calloc(link_fields.lod_entry_count,
                   sizeof(SE_LOD_Entry))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }

    switch (fields_ptr->lod_data_type)
    {
        case SE_LODDATTYP_DISTANCE:
             expected_tag = SE_CLS_DRM_DISTANCE_LOD_DATA;
             break;
        case SE_LODDATTYP_INDEX:
             expected_tag = SE_CLS_DRM_INDEX_LOD_DATA;
             break;
        case SE_LODDATTYP_MAP_SCALE:
             expected_tag = SE_CLS_DRM_MAP_SCALE_LOD_DATA;
             break;
        case SE_LODDATTYP_SPATIAL_RESOLUTION:
             expected_tag = SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA;
             break;
        case SE_LODDATTYP_VOLUME:
             expected_tag = SE_CLS_DRM_VOLUME_LOD_DATA;
             break;
        default:
             se_message(object, path[level], level, path, MSGTYP_ERROR,
                "unrecognized lod_data_type");
             expected_tag = SE_CLS_DRM_BASE_LOD_DATA;
             break;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_LODRF:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                                 &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                             (SE_IsA[link_fields_ptr->tag]
                              [SE_CLS_DRM_BASE_LOD_DATA] != SE_TRUE))
                         {
                             printLastFnctStatus("check_LODRF:SE_GetFields");
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                                MSGTYP_ERROR,
                                "can't get fields of corresponding <Base LOD Data>");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();
                             SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                             if (SE_IsA[link_fields_ptr->tag][expected_tag] != SE_TRUE)
                             {
                                 se_message(next_object, next_fields_ptr->tag, level+1, path,
                                    MSGTYP_ERROR,
                                    "violates <<LOD Related Organizing Principle>>, part (a)");
                             }
                            /*
                             * even if the part (a) test failed, can still check the
                             * <Base LOD Data> for compliance with <<Distinct Link Objects>>
                             */
                             if (check_lod_data(level+1, path, link_object,
                                 link_fields_ptr, context, summary, &(link_fields.lod_entry_array[i]))
                                 == SE_RETCOD_SUCCESS)
                             {
                                 i++;
                             }
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus("check_LODRF:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
    link_fields.lod_entry_count = i;
    link_fields.matching_rules = SE_BRRNGMAT_EXACT;

    if ((link_fields.lod_entry_count > 0) &&
        (SE_ValidLODSelectParameters(&link_fields, SE_FALSE, NULL)
         != SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
        SE_ValidLODSelectParameters(&link_fields, SE_TRUE, NULL);
    }
    SE_FreeLODSelectParameters(&link_fields, NULL);
} /* end check_LODRF */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_octant_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_octant_related_features
(
          SE_Short_Integer_Unsigned          level,
          SE_DRM_Class                       path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                          object,
    const SE_Octant_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                  *context,
          SE_LOCAL_SUMMARY                  *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Element_Code_Queue       eac_val_queue;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         i = 0;
    SE_Octant_Select_Parameters link_fields;
    SE_FIELDS_PTR               link_fields_ptr = NULL,
                                next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter,
             &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
              &link_fields.octant_data_count) != SE_RETCOD_SUCCESS)
          || (link_fields.octant_data_count < 1))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.octant_data_array = (SE_Octant_Data_Fields *)
             calloc(link_fields.octant_data_count,
                   sizeof(SE_Octant_Data_Fields))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus(
                 "check_octant_related_features:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) != SE_RETCOD_SUCCESS)
                         {
                             printLastFnctStatus(
                               "check_octant_related_features:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_OCTANT_DATA, level+1,
                                path, MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();
                             SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                             memcpy(&(link_fields.octant_data_array[i]),
                                    &(link_fields_ptr->u.Octant_Data),
                                    sizeof(SE_Octant_Data_Fields));
                             i++;
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_TRUE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                              [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus(
              "check_octant_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if (i > 8)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "has more than 8 octants");
    }
    else
    {
        link_fields.octant_data_count = i;

        if (!SE_ValidOctantSelectParameters(&link_fields, SE_FALSE, NULL))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "branches violate <<Distinct Link Objects>>");
            SE_ValidOctantSelectParameters(&link_fields, SE_TRUE, NULL);
        }
        if ((fields_ptr->strict_organizing_principle == SE_TRUE) &&
            (i != 8))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
              "violates <<Octant Related Organizing Principle>> - claims "\
              "strict_organizing_principle but less than 8 octants");
        }
        else if ((fields_ptr->strict_organizing_principle != SE_TRUE) &&
                 (i == 8))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
              "violates <<Octant Related Organizing Principle>> - claims "\
              "no strict_organizing_principle but has all 8 octants");
        }
    }
    free(link_fields.octant_data_array);
} /* end check_octant_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_perimeter_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_perimeter_related_features
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             link_object = NULL, next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
             != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_perimeter_related_features:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if (link_object)
                         {
                            /*
                             * $$$ need more checks later on that the
                             * $$$ <Perimeter Data> for the different
                             * $$$ branches are distinct and don't overlap
                             * $$$ except at their boundaries
                             */
                             SE_UpdateAnalysisCounts();
                             check_perimeter_data(level+1, path, link_object, context, summary);
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                                next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus
            ("check_perimeter_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level, path,
              MSGTYP_ERROR, "can't get fields");
        }

        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_perimeter_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_quadrant_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_quadrant_related_features
(
          SE_Short_Integer_Unsigned            level,
          SE_DRM_Class                         path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                            object,
    const SE_Quadrant_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                    *context,
          SE_LOCAL_SUMMARY                    *summary
)
{
    SE_Iterator                   iter = NULL;
    SE_Element_Code_Queue         eac_val_queue;
    SE_Object                     link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned           i = 0;
    SE_Quadrant_Select_Parameters link_fields;
    SE_FIELDS_PTR                 link_fields_ptr = NULL,
                                  next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &link_fields.quadrant_data_count) != SE_RETCOD_SUCCESS)
          || (link_fields.quadrant_data_count < 1))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.quadrant_data_array = (SE_Quadrant_Data_Fields *)
            calloc(link_fields.quadrant_data_count,
                   sizeof(SE_Quadrant_Data_Fields))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_quadrant_related_features:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) != SE_RETCOD_SUCCESS)
                         {
                             printLastFnctStatus
                             ("check_quadrant_related_features:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_QUADRANT_DATA, level+1,
                                path, MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();

                             memcpy(&(link_fields.quadrant_data_array[i]),
                                    &(link_fields_ptr->u.Quadrant_Data),
                                    sizeof(SE_Quadrant_Data_Fields));
                             i++;
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_TRUE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                              [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus
            ("check_quadrant_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if (i > 4)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "has more than 4 quadrants");
    }
    else
    {
        link_fields.quadrant_data_count = i;
        if (!SE_ValidQuadrantSelectParameters(&link_fields, SE_FALSE, NULL))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "branches violate <<Distinct Link Objects>>");
            SE_ValidQuadrantSelectParameters(&link_fields, SE_TRUE, NULL);
        }
        if ((fields_ptr->strict_organizing_principle == SE_TRUE) &&
            (i != 4))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
              "violates <<Quadrant Related Organizing Principle>> - claims "\
              "strict_organizing_principle but less than 4 quadrants");
        }
        else if ((fields_ptr->strict_organizing_principle != SE_TRUE) &&
                 (i == 4))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
              "violates <<Quadrant Related Organizing Principle>> - claims "\
              "no strict_organizing_principle but has all 4 quadrants");
        }
    }
    free(link_fields.quadrant_data_array);
} /* end check_quadrant_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_index_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_spatial_index_related_features
(
          SE_Short_Integer_Unsigned                 level,
          SE_DRM_Class                              path
                                                    [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                 object,
    const SE_Spatial_Index_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                         *context,
          SE_LOCAL_SUMMARY                         *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Element_Code_Queue       eac_val_queue;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         cell_count = 0, i = 0;
    SE_Spatial_Index_Parameters link_fields;
    char                        err_msg[256];
    SE_FIELDS_PTR               link_fields_ptr = NULL,
                                next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus(
             "check_spatial_index_related_features:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &link_fields.spatial_index_data_count) != SE_RETCOD_SUCCESS)
          || (link_fields.spatial_index_data_count < 1))
    {
        printLastFnctStatus(
             "check_spatial_index_related_features:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.spatial_index_data_array =
             (SE_Spatial_Index_Data_Fields *)
             calloc(link_fields.spatial_index_data_count,
                   sizeof(SE_Spatial_Index_Data_Fields))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
               != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus(
                 "check_spatial_index_related_features:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) != SE_RETCOD_SUCCESS)
                         {
                             printLastFnctStatus
                             ("check_spatial_index_related_features:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_SPATIAL_INDEX_DATA,
                                level+1, path, MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();
                             SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                             if ((link_fields_ptr->u.Spatial_Index_Data.row_index
                                  > fields_ptr->row_count) ||
                                 (link_fields_ptr->u.Spatial_Index_Data.column_index
                                  > fields_ptr->column_count))
                             {
                                 sprintf(err_msg, "(%u, %u) is out of aggregate's defined"\
                                     " range (1, 1) to (%u, %u)",
                                     (unsigned int) link_fields_ptr->u.
                                         Spatial_Index_Data.row_index,
                                     (unsigned int) link_fields_ptr->u.
                                         Spatial_Index_Data.column_index,
                                     (unsigned int) fields_ptr->row_count,
                                     (unsigned int) fields_ptr->column_count);
                                 se_message(link_object, SE_CLS_DRM_SPATIAL_INDEX_DATA,
                                    level+1, path, MSGTYP_ERROR, err_msg);
                             }
                             memcpy(&(link_fields.spatial_index_data_array[i]),
                                    &(link_fields_ptr->u.Spatial_Index_Data),
                                    sizeof(SE_Spatial_Index_Data_Fields));
                             i++;
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                              [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
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
            printLastFnctStatus
            ("check_spatial_index_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }

        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    cell_count = fields_ptr->column_count * fields_ptr->row_count;

    if (i < cell_count)
    {
        if (!fields_ptr->sparse)
            se_message(object, path[level], level, path,
               MSGTYP_ERROR, "sparse==SE_FALSE but some entries are missing");
    }
    else if (i == cell_count)
    {
        if (fields_ptr->sparse)
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "sparse==SE_FALSE but some entries are missing");
    }
    else
    {
        sprintf(err_msg, "has more cells than column_count(%u)*"\
                "row_count(%u)=%u", (unsigned int)fields_ptr->column_count,
                (unsigned int)fields_ptr->row_count,
                (unsigned int)cell_count);
        se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
    link_fields.spatial_index_data_count = i;

    if (!SE_ValidSpatialIndexParameters(&link_fields, SE_FALSE, NULL))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
        SE_ValidSpatialIndexParameters(&link_fields, SE_TRUE, NULL);
    }
    free(link_fields.spatial_index_data_array);
} /* end check_spatial_index_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_state_related_features
 *
 *   Checks <<State Related Organizing Principle>> constraint.
 *
 *-----------------------------------------------------------------------------
 */
static void
check_state_related_features
(
          SE_Short_Integer_Unsigned         level,
          SE_DRM_Class                      path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                         object,
    const SE_State_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                 *context,
          SE_LOCAL_SUMMARY                 *summary
)
{
    SE_Iterator                iter = NULL;
    SE_Element_Code_Queue      eac_val_queue;
    SE_Object                  link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned        i = 0;
    SE_FIELDS_PTR              link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_State_Select_Parameters link_fields;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_state_related_features:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &(link_fields.state_entry_count))!=SE_RETCOD_SUCCESS)
          || (link_fields.state_entry_count < 1))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.state_entry_array =
            (SE_State_Entry *)
            calloc(link_fields.state_entry_count,
            sizeof(SE_State_Entry))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
               != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_state_related_features:SE_GetNextObject");
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

                case SE_CLS_DRM_STATE_CONTROL_LINK:
                     /* $$$ need to check return type for expression */
                     check_control_link(level+1, path,
                         next_object, next_fields_ptr,
                         (context->has_variables ? &(context->interface_template)
                                                 : NULL), summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                                          &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                             (SE_IsA[link_fields_ptr->tag][SE_CLS_DRM_STATE_DATA]!=SE_TRUE))
                         {
                             se_message(next_object, next_fields_ptr->tag, level, path,
                                MSGTYP_ERROR, "can't get fields of corresponding <State Data>");
                         }
                         else if (check_state_data(level, path, fields_ptr->state_tag,
                                 fields_ptr->active_state_value.attribute_value_type, link_object,
                                 link_fields_ptr, &(link_fields.state_entry_array[i]))
                                 == SE_TRUE)
                         {
                             i++;
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus(
                 "check_state_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);

        if (link_object)
            SE_FreeObject(link_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    link_fields.default_choice = SE_UNMSTATBEH_DEFAULT;
    link_fields.matching_rules = SE_BRRNGMAT_INTERSECTION;
    link_fields.state_entry_count = i;
    /*
     * $$$ needs to also check for overlapping states as an illegal
     * $$$ case, not just identical matches
     */
    if ((link_fields.state_entry_count > 0) &&
        (SE_ValidStateSelectParameters(&link_fields, SE_FALSE, NULL)!=SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>> or "\
           "<<State Related Organizing Principle>>");
        SE_ValidStateSelectParameters(&link_fields, SE_TRUE, NULL);
    }
    free(link_fields.state_entry_array);
} /* end check_state_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_time_related_features
 *
 *-----------------------------------------------------------------------------
 */
static void
check_time_related_features
(
          SE_Short_Integer_Unsigned        level,
          SE_DRM_Class                     path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                        object,
    const SE_Time_Related_Features_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                *context,
          SE_LOCAL_SUMMARY                *summary
)
{
    SE_Iterator               iter = NULL;
    SE_Element_Code_Queue     eac_val_queue;
    SE_Object                 link_object = NULL, next_object = NULL;
    SE_DRM_Class              expected_tag = SE_CLS_DRM_NULL;
    SE_Integer_Unsigned       i = 0;
    SE_FIELDS_PTR             next_fields_ptr = NULL;
    SE_Time_Select_Parameters link_fields;

    if (local_InitializeComponentIterator3(object, search_filter,
          &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_time_related_features:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &(link_fields.time_entry_count))!=SE_RETCOD_SUCCESS)
          || (link_fields.time_entry_count < 1))
    {
        printLastFnctStatus
        ("check_time_related_features:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.time_entry_array =
            (SE_Time_Entry *)
            calloc(link_fields.time_entry_count,
            sizeof(SE_Time_Entry))) == NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't check link objects, out of memory");
        SE_FreeIterator(iter);
        return;
    }

    switch (fields_ptr->time_data_type)
    {
        case SE_TIMEDATTYP_SEASON:
             expected_tag = SE_CLS_DRM_SEASON;
             break;
        case SE_TIMEDATTYP_TIME_INTERVAL:
             expected_tag = SE_CLS_DRM_TIME_INTERVAL;
             break;
        case SE_TIMEDATTYP_TIME_OF_DAY:
             expected_tag = SE_CLS_DRM_TIME_OF_DAY;
             break;
        case SE_TIMEDATTYP_TIME_POINT:
             expected_tag = SE_CLS_DRM_TIME_POINT;
             break;
        default:
             se_message(object, path[level], level, path, MSGTYP_ERROR,
                "unrecognized time_data_type");
             expected_tag = SE_CLS_DRM_BASE_TIME_DATA;
             break;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_time_related_features:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_FEATURE_HIERARCHY])
                     {
                         if (link_object)
                         {
                             SE_UpdateAnalysisCounts();

                             check_time_constraints_data(level+1, path, link_object,
                                 expected_tag, summary);
                         }
                         check_feature_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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
            printLastFnctStatus
            ("check_time_related_features:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

   /*
    * $$$ needs to also check for contained times (though not overlapping)
    * $$$ times as an illegal case, not just identical matches
    */
    local_FreeElementCodeQueue(&eac_val_queue);
    SE_FreeTimeSelectParameters(&link_fields, NULL);
} /* end check_time_related_features */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_fmi
 *
 * $$$ NOTE: Later, add checks that
 * (1) <Expression>s are present if and only if the <Model> has an
 *     <Interface Template>
 *     (a) The number of <Expression>s matches the number of <Variable>s
 *         of the <Interface Template>
 *     (b) The value type of an <Expression> is consistent with that of the
 *         <Variable> to which it is being supplied
 *     (c) if an <Expression> component is a <Variable>, its scaled unit
 *         matches that of the <Variable> to which it is being supplied
 * (2) if mandatory_spatial_extent, then <Model> has one
 *
 *-----------------------------------------------------------------------------
 */
static void
check_fmi
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                 mandatory_spatial_extent
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             link_object = NULL, next_object = NULL;
    char                  err_msg[256];
    SE_FIELDS_PTR         link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_Integer_Unsigned   expr_count = 0, *indx_list = NULL, j = 0, k = 0;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter, &expr_count)
             != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get length of component iter");
        SE_FreeIterator(iter);
        return;
    }
    else if (expr_count > 0)
    {
        if ((indx_list = (SE_Integer_Unsigned *)
            calloc(sizeof(SE_Integer_Unsigned), expr_count)) == NULL)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "can't allocate list to check "\
               "<<Distinct Link Objects>> for "\
               "<Feature Model Instance>");
            SE_FreeIterator(iter);
            return;
        }
        else
        {
            memset(indx_list, 0, sizeof(SE_Integer_Unsigned)*expr_count);
        }
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;
    expr_count          = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_fmi:SE_GetNextObject");
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_EXPRESSION])
                     {
                         if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                              &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                              link_fields_ptr->tag!=SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX)
                         {
                             se_message(link_object,
                                SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX,
                                level+1, path, MSGTYP_ERROR, "can't get fields");
                         }
                         else
                         {
                             SE_Boolean found_pos = SE_FALSE;

                             SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);
                             j = 0;
                             while (!found_pos && (j < expr_count))
                             {
                                 if (indx_list[j] < ((SE_Integer_Unsigned)
                                     link_fields_ptr->u.Model_Instance_Template_Index.index))
                                 {
                                     j++;
                                 }
                                 else
                                 {
                                     found_pos = SE_TRUE;
                                 }
                             }
                             if (indx_list[j]==(SE_Integer_Unsigned) link_fields_ptr->u.
                                               Model_Instance_Template_Index.index)
                             {
                                 se_message(link_object,
                                    SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Distinct Link Objects>>");
                             }
                             else
                             {
                                 for (k = expr_count; k > j; k--)
                                 {
                                     indx_list[k] = indx_list[k-1];
                                 }
                                 indx_list[j] = (SE_Integer_Unsigned) link_fields_ptr->u.
                                                Model_Instance_Template_Index.index;
                                 expr_count++;
                             }
                         }
                         check_expression(level+1, path, next_object, next_fields_ptr,
                             (context->has_variables ? &(context->interface_template)
                                        : NULL), summary);
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
            printLastFnctStatus("check_fmi:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);

        if (link_object)
            SE_FreeObject(link_object);
    }
    SE_FreeIterator(iter);

   /*
    * $$$ need to check these against the <Model> being instanced,
    * $$$ as well as mandatory_spatial_extent
    */
    if (indx_list != NULL)
    {
       /*
        * If the first entry in the template index list is greater than
        * 1, then all the <Variable>s that would be indexed between 1
        * and indx_list[0] have not been provided with values by this
        * <Feature Model Instance>.
        */
        if (indx_list[0] > 1)
        {
            sprintf(err_msg, "<Feature Model Instance> has no <Expression>s"\
                    " for template indices 1 through %u (expr_count = %u)",
                    (unsigned int)indx_list[0], (unsigned int)expr_count);
            se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
        }

       /*
        * Check for any gaps in the list of <Expression>s, that is,
        * for any <Variable>s that have not been provided with
        * <Expression>s to be plugged in.
        */
        for (j = 1; j < expr_count; j++)
        {
           /*
            * Since the list is sorted, the entries between these
            * two indx_list entries have no <Expression>s
            */
            if (indx_list[j] != (indx_list[j-1]+1))
            {
                sprintf(err_msg, "<Feature Model Instance> has no "\
                        "<Expression>s for template indices %u through %u",
                        (unsigned int)(indx_list[j-1]+1),
                        (unsigned int)(indx_list[j]-1));
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   err_msg);
            }
        }
        free(indx_list);
    }
    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_fmi */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_hierarchy
 *
 *-----------------------------------------------------------------------------
 */
void
check_feature_hierarchy
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                 mandatory_spatial_extent,
    SE_Boolean                 inherits_classification_data
)
{
    SE_LOCAL_CONTEXT local_context;
    SE_Boolean       has_spatial_extent = SE_FALSE;

    path[level] = fields_ptr->tag;

   /*
    * SE_SpawnUpdatedLocalContext handles any <Property Description>s,
    * <Presentation Domain>, and/or <Spatial Extent>
    */
    SE_SpawnUpdatedLocalContext(level, path, object, context,
        &local_context, summary, &has_spatial_extent);

    if (fields_ptr->tag != SE_CLS_DRM_FEATURE_MODEL_INSTANCE)
    {
        if ((mandatory_spatial_extent == SE_TRUE) &&
            (has_spatial_extent != SE_TRUE))
        {
            printLastFnctStatus("check_feature_hierarchy:SE_GetComponent");
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "violates <<Quadrant Related Organizing Principle>> or "\
               "<<Octant Related Organizing Principle>> "\
               "(no <Spatial Extent> component)");
        }
    }

    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
             check_alt_hier_related_features(level, path, object,
                &(fields_ptr->u.Alternate_Hierarchy_Related_Features),
                &local_context, summary);
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
             check_classification_related_features(level, path, object,
                &(fields_ptr->u.Classification_Related_Features),
                &local_context, summary);
             break;

        case SE_CLS_DRM_UNION_OF_FEATURES:
             check_union_of_features(level, path, object, fields_ptr,
                &local_context, summary, inherits_classification_data);
             break;

        case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
             check_fmi(level, path, object, &local_context, summary,
                       mandatory_spatial_extent);
             break;

        case SE_CLS_DRM_LOD_RELATED_FEATURES:
             if (SE_ValidDRMClassFields(fields_ptr, SE_TRUE, NULL))
             {
                 check_LODRF(level, path, object,
                    &(fields_ptr->u.LOD_Related_Features),
                    &local_context, summary);
             }
             else
             {
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR_SYNTAX, "skipping, invalid fields");
             }
             break;

        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
             if (!has_spatial_extent)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates <<Octant Organizing Principle>> "\
                    "(no <Spatial Extent> component)");
             }
             check_octant_related_features(level, path, object,
                 &(fields_ptr->u.Octant_Related_Features),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
             check_perimeter_related_features(level, path, object,
                 &local_context, summary);
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
             if (!has_spatial_extent)
             {
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates <<Quadrant Organizing Principle>> "\
                    "(no <Spatial Extent> component)");
             }
             check_quadrant_related_features(level, path, object,
                 &(fields_ptr->u.Quadrant_Related_Features),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
             local_CheckSpatialIndexUnit
             (level, path, object, fields_ptr, &(local_context.srf_context_info));

             check_spatial_index_related_features(level, path, object,
                 &(fields_ptr->u.Spatial_Index_Related_Features),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
             if (SE_ValidFields(fields_ptr, SE_TRUE, NULL))
             {
                 check_state_related_features(level, path, object,
                     &(fields_ptr->u.State_Related_Features),
                     &local_context, summary);
             }
             else
             {
                 se_message(object, path[level], level, path,
                     MSGTYP_ERROR_SYNTAX, "skipping, invalid fields");
             }
             break;

        case SE_CLS_DRM_TIME_RELATED_FEATURES:
             check_time_related_features(level, path, object,
                 &(fields_ptr->u.Time_Related_Features),
                 &local_context, summary);
             break;

        default:
             se_message(object, path[level], level, path, MSGTYP_ERROR,
                "$$$ unrecognized <Feature Hierarchy> subclass");
             break;
    }
   /*
    * do *not* free local_context
    */
} /* end check_feature_hierarchy */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_node
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_feature_node
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_node,
    SE_Object                  location_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_feature_topology
)
{
    SE_Return_Code        ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL, feature_face = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Boolean            has_edges = SE_FALSE, has_face = SE_FALSE;

    path[level] = SE_CLS_DRM_FEATURE_NODE;

    if (local_InitializeComponentIterator3(feature_node, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_feature_node:SE_InitializeComponentIterator");
        se_message(feature_node, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * loop through <Feature Node> components
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_feature_node:SE_GetNextObject");
            ret_status = SE_RETCOD_FAILURE;
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

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         if ((SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION_3D]
                             != SE_TRUE) &&
                             ((context->feature_topology_level == SE_FTL_FOUR)
                           || (context->feature_topology_level == SE_FTL_FIVE)))
                         {
                             se_message(feature_node, path[level], level, path,
                                MSGTYP_ERROR,
                                "violates the feature_topology_level's definition "\
                                "(must contain <Location 3D> instances only)");
                         }
                         if (check_location(level+1, path, next_object,
                             next_fields_ptr, NULL, context, summary) != SE_TRUE)
                         {
                             ret_status = SE_RETCOD_FAILURE;
                         }
                         else if ((location_ptr != NULL) &&
                            (SE_CloneObjectHandle(next_object, location_ptr)
                             != SE_RETCOD_SUCCESS))
                         {
                             printLastFnctStatus("check_feature_node:SE_CloneObjectHandle");
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                                MSGTYP_ERROR, "can't clone handle");
                             ret_status = SE_RETCOD_FAILURE;
                         }
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_feature_node:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);

   /*
    * <Feature Node> requirements at level 3:
    * - is an endpoint of least one <Feature Edge> in the same union, or
    * - is an associate of a <Feature Face> in the same union
    *
    * If it is an associate of a non-universal <Feature Face>, must be
    * located within the bounds of the face, and if the topology is clean,
    * shouldn't be an edge endpoint. If it is an associate of a universal
    * <Feature Face>, shouldn't be contained in the bounds of any
    * non-universal <Feature Face>
    */
    if (SE_InitializeAssociateIterator(feature_node,
        GetGlobalAssociationFilter(SE_CLS_DRM_FEATURE_NODE),
        SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_feature_node:SE_InitializeAssociateIterator");
        se_message(feature_node, path[level], level, path, MSGTYP_ERROR,
           "can't initialize associate iter");
        return SE_RETCOD_FAILURE;
    }

   /*
    * loop through associated <Feature Edge> instances
    */
    while ((has_edges != SE_TRUE) &&
           (SE_IsIteratorComplete(iter) == SE_FALSE))
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_feature_node:SE_GetNextObject");
            ret_status = SE_RETCOD_FAILURE;
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (local_IsComponentOf(level, path, union_of_feature_topology,
            next_object, NULL, &has_edges) != SE_RETCOD_SUCCESS)
        {
            se_message(next_object, path[level], level, path, MSGTYP_WARNING,
               "can't verify the union to which <Feature Edge> belongs");
            has_edges = SE_FALSE;
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (SE_GetAssociate3(feature_node, SE_CLS_DRM_FEATURE_FACE, &feature_face)
        == SE_RETCOD_SUCCESS)
    {
        if (local_IsComponentOf(level, path, union_of_feature_topology,
            feature_face, NULL, &has_face) != SE_RETCOD_SUCCESS)
        {
            se_message(feature_face, path[level], level, path, MSGTYP_WARNING,
               "can't verify the union to which <Feature Face> belongs");
            has_face = SE_FALSE;
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(feature_face);
    }

   /*
    * Topology level 3 - <Feature Node> belongs to either a <Feature Edge> or
    * <Feature Face>
    */
    if (ret_status == SE_RETCOD_SUCCESS)
    {
        if ((has_edges == SE_TRUE) && (has_face == SE_TRUE))
        {
            se_message(feature_node, path[level], level, path, MSGTYP_ERROR,
               "associated both <Feature Edge> and <Feature Face>");
        }
        else if ((context->feature_topology_level == SE_FTL_THREE) &&
                 ((has_edges != SE_TRUE) && (has_face != SE_TRUE)))
        {
            se_message(feature_node, path[level], level, path, MSGTYP_ERROR,
               "violates the feature_topology_level's definition "\
               "(must belong to <Feature Edge> or <Feature Face>)");
        }
    }
    return ret_status;
} /* end check_feature_node */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CheckEdgeBorderingFace
 *
 *-----------------------------------------------------------------------------
 */
static void
local_CheckEdgeBorderingFace
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_edge,
    SE_Object                  feature_face
)
{
    SE_Object           face_ring = NULL;
    SE_Boolean          found = SE_FALSE, found_edge = SE_FALSE;
    SE_Integer_Positive i = 1;

    found_edge = SE_FALSE;
    while ((SE_GetNthComponent(feature_face,
           SE_CLS_DRM_FEATURE_FACE_RING, i++, &face_ring, NULL)
           == SE_RETCOD_SUCCESS) && (found_edge != SE_TRUE))
    {
        found = SE_FALSE;
        if (local_IsAssociateOf(level, path, face_ring,
            feature_edge, NULL, &found) == SE_RETCOD_SUCCESS)
        {
            if (found == SE_TRUE)
            {
                found_edge = SE_TRUE;
            }
        }
        SE_FreeObject(face_ring);
    } /* end while */

    if (found_edge != SE_TRUE)
    {
        se_message2(feature_edge, feature_face,
           path[level], level, path, MSGTYP_ERROR,
           "violates <<Edges Bordering Faces>>, part a");
    }
} /* end local_CheckEdgeBorderingFace */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_edge
 *
 *-----------------------------------------------------------------------------
 */
static void
check_feature_edge
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_edge,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_feature_topology
)
{
    SE_Iterator            iter = NULL;
    SE_Element_Code_Queue  eac_val_queue;
    SE_Object              feature_node_start = NULL, feature_node_end = NULL,
                           node_edge_direction = NULL, next_object = NULL;
    SE_FIELDS_PTR          next_fields_ptr = NULL;
    SE_Integer_Positive    i=0, loc_count = 0;
    SE_Object             *loc_array = NULL;
    SE_Integer_Unsigned    loc_array_count = 0;
    SE_Boolean             contains_2D = SE_FALSE, contains_3D = SE_FALSE,
                           found_node = SE_FALSE, got_first_loc = SE_FALSE,
                           is_loop = SE_FALSE, skipped_loc = SE_FALSE,
                           valid_loc_array = SE_TRUE;

    path[level] = SE_CLS_DRM_FEATURE_EDGE;

    if (local_InitializeComponentIterator3(feature_edge, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_feature_edge:SE_InitializeComponentIterator3");
        se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter, &loc_count) !=
             SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_feature_edge:SE_GetIterationLengthRemaining");
        se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
           "can't get component iteration length, aborting check");
        SE_FreeIterator(iter);
        return;
    }
    else if ((loc_array = (SE_Object *)calloc(loc_count+2,
             sizeof(SE_Object))) == NULL)
    {
        se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
          "can't allocate loc_array, aborting check for <Feature Edge>");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * Do not SE_UpdateAnalysisCounts for the <Feature Node>;
    * that is handled elsewhere
    */
    if (SE_GetNthAssociate(feature_edge, SE_CLS_DRM_FEATURE_NODE, 1,
        &feature_node_start, &node_edge_direction) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(node_edge_direction, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            if (next_fields_ptr->u.Edge_Direction.forwards != SE_TRUE)
            {
                se_message(node_edge_direction, SE_CLS_DRM_EDGE_DIRECTION, level,
                   path, MSGTYP_ERROR, "forward != SE_TRUE for start <Feature Node>");
            }
        }
        else
        {
            printLastFnctStatus("check_feature_edge:SE_GetFields");
            se_message(node_edge_direction, SE_CLS_DRM_EDGE_DIRECTION, level,
               path, MSGTYP_ERROR, "can't get <Edge Direction> fields");
        }
        SE_FreeObject(node_edge_direction);

        if (local_IsComponentOf(level, path, union_of_feature_topology,
            feature_node_start, NULL, &found_node) == SE_RETCOD_SUCCESS)
        {
            if (found_node != SE_TRUE)
            {
                se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
                   "start <Feature Node> is not a component of "\
                   "the <Union Of Feature Topology> instance containing "\
                   "the <Feature Edge>");
            }
        }
        else
        {
            se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
              "can't verify whether start <Feature Node> is a component of "\
              "the <Union Of Feature Topology> instance containing "\
              "the <Feature Edge>");
        }

        if (SE_GetComponent(feature_node_start, SE_CLS_DRM_LOCATION,
            SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object,
            NULL) == SE_RETCOD_SUCCESS)
        {
            if (SE_GetFields(next_object, GetGlobalStore(level),
                &next_fields_ptr) == SE_RETCOD_SUCCESS)
            {
                if (check_location(level+1, path, next_object, next_fields_ptr,
                         NULL, context, summary) != SE_TRUE)
                {
                    skipped_loc = SE_TRUE;
                }
                else
                {
                    if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION_3D])
                    {
                        contains_3D = SE_TRUE;
                    }
                    else
                    {
                        contains_2D = SE_TRUE;
                    }
                    /* clone these into our list so we can check for dups */
                    if (SE_CloneObjectHandle(next_object,
                        &loc_array[loc_array_count++]) == SE_RETCOD_SUCCESS)
                    {
                        got_first_loc = SE_TRUE;
                    }
                    else
                    {
                        printLastFnctStatus
                        ("check_feature_edge:SE_CloneObjectHandle");
                        se_message(feature_node_start, SE_CLS_DRM_FEATURE_NODE,
                           level, path, MSGTYP_ERROR,
                           "can't clone <Location> component");
                        loc_array_count--;
                        skipped_loc = SE_TRUE;
                    }
                }
            }
            else
            {
                printLastFnctStatus("check_feature_edge:SE_GetFields");
                skipped_loc = SE_TRUE;
            }
            SE_FreeObject(next_object);
        }
        else
        {
            printLastFnctStatus("check_feature_edge:SE_GetComponent");
            se_message(feature_node_start, SE_CLS_DRM_FEATURE_NODE, level,
               path, MSGTYP_ERROR, "can't get <Location> component");
            skipped_loc = SE_TRUE;
        }
    }
    else
    {
        printLastFnctStatus("check_feature_edge:SE_GetNthAssociate");
        se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
           "can't get start <Feature Node>");
        skipped_loc = SE_TRUE;
    }

   /*
    * now for the <Feature Edge> components
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_feature_edge:SE_GetNextObject");
            se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
               "can't get component");
            skipped_loc = SE_TRUE; /* this may have been a <Location> */
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
            {
                if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION_3D] == SE_TRUE)
                {
                    contains_3D = SE_TRUE;
                }
                else
                {
                    contains_2D = SE_TRUE;
                }
                if (check_location(level+1, path, next_object, next_fields_ptr,
                    NULL, context, summary) != SE_TRUE)
                {
                    skipped_loc = SE_TRUE;
                }
                /* clone these into our list so we can check for dups */
                else if (SE_CloneObjectHandle(next_object, &loc_array[loc_array_count++])
                         != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_feature_edge:SE_CloneObjectHandle");
                    loc_array_count--;
                    skipped_loc = SE_TRUE;
                }
            }
            else if (next_fields_ptr->tag==SE_CLS_DRM_PROPERTY_VALUE)
            {
                check_property_value(level+1, path, next_object,
                    next_fields_ptr, &eac_val_queue, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_feature_edge:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path, MSGTYP_ERROR,
               "can't get fields");
            skipped_loc = SE_TRUE; /* this may have been a <Location> */
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

   /*
    * Do not SE_UpdateAnalysisCounts for the <Feature Node>;
    * that is handled elsewhere
    *
    * We only need to fetch the <Feature Node> associate's <Location>
    * for comparison with other <Location> instances of the edge, so
    * if we haven't managed to retrieve any, we don't fetch this one
    */
    if ((feature_node_start != NULL) ||
        (loc_array_count > 0))
    {
        if (SE_GetNthAssociate(feature_edge, SE_CLS_DRM_FEATURE_NODE, 2,
            &feature_node_end, &node_edge_direction) == SE_RETCOD_SUCCESS)
        {
            if (SE_GetFields(node_edge_direction, GetGlobalStore(level),
                &next_fields_ptr) == SE_RETCOD_SUCCESS)
            {
                if (next_fields_ptr->u.Edge_Direction.forwards != SE_FALSE)
                {
                    se_message(node_edge_direction, SE_CLS_DRM_EDGE_DIRECTION, level,
                       path, MSGTYP_ERROR, "forward != SE_FALSE for end <Feature Node>");
                }
            }
            else
            {
                printLastFnctStatus("check_feature_edge:SE_GetFields");
                se_message(node_edge_direction, SE_CLS_DRM_EDGE_DIRECTION, level,
                   path, MSGTYP_ERROR, "can't get <Edge Direction> fields");
            }
            SE_FreeObject(node_edge_direction);

            if (feature_node_start != NULL)
            {
                if (SE_ObjectsAreSame(feature_node_start, feature_node_end,
                    &is_loop) != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_feature_edge:SE_ObjectsAreSame");
                }
            }
            if (is_loop != SE_TRUE)
            {
                if (local_IsComponentOf(level, path, union_of_feature_topology,
                    feature_node_end, NULL, &found_node) == SE_RETCOD_SUCCESS)
                {
                    if (found_node != SE_TRUE)
                    {
                        se_message(feature_edge, path[level], level, path,
                           MSGTYP_ERROR,
                           "end <Feature Node> is not a component of "\
                           "the <Union Of Feature Topology> instance "\
                           "containing the <Feature Edge>");
                    }
                }
                else
                {
                    se_message(feature_edge, path[level], level, path,
                       MSGTYP_ERROR,
                       "can't verify whether end <Feature Node> "\
                       " is a component of the <Union Of Feature Topology> "\
                       " instance containing the <Feature Edge>");
                }

                if (SE_GetComponent(feature_node_end, SE_CLS_DRM_LOCATION,
                    SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object,
                    NULL) == SE_RETCOD_SUCCESS)
                {
                    if (got_first_loc == SE_TRUE)
                    {
                        SE_Object node_loc_array[2];

                        node_loc_array[0] = loc_array[0];
                        node_loc_array[1] = next_object;
                        if (check_object_list_for_duplicate_locations(2,
                            node_loc_array, &i) == SE_TRUE)
                        {
                            is_loop = SE_TRUE;
                            se_message(feature_edge, path[level], level, path,
                               MSGTYP_ERROR, "start and end <Feature Node> "\
                               "instances are co-located but are not the "\
                               "same object");
                            SE_FreeObject(next_object);
                        }
                        node_loc_array[0] = NULL;
                        node_loc_array[1] = NULL;
                    }
                }
                else
                {
                    printLastFnctStatus("check_feature_edge:SE_GetComponent");
                    se_message(feature_node_end, SE_CLS_DRM_FEATURE_NODE, level,
                       path, MSGTYP_ERROR, "can't get <Location> component");
                    skipped_loc = SE_TRUE;
                }
            }
            if (is_loop != SE_TRUE)
            {
                if (SE_GetFields(next_object, GetGlobalStore(level),
                    &next_fields_ptr) != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus("check_feature_edge:SE_GetFields");
                    se_message(feature_node_end, SE_CLS_DRM_FEATURE_NODE,
                       level, path, MSGTYP_ERROR,
                       "can't get <Location> component's fields");
                    skipped_loc = SE_TRUE;
                }
                else if (check_location(level+1, path, next_object,
                         next_fields_ptr, NULL, context, summary)
                         != SE_TRUE)
                {
                    valid_loc_array = SE_FALSE;
                }
                else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION_3D])
                {
                    contains_3D = SE_TRUE;
                }
                else
                {
                    contains_2D = SE_TRUE;
                }
                /* clone these into our list so we can check for dups */
                if (SE_CloneObjectHandle(next_object,
                    &loc_array[loc_array_count++])
                    != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_feature_edge:SE_CloneObjectHandle");
                    loc_array_count--;
                    skipped_loc = SE_TRUE;
                }
                SE_FreeObject(next_object);
            } /* end if !is_loop */
            SE_FreeObject(feature_node_end);
        }
        else
        {
            printLastFnctStatus("check_feature_edge:SE_GetNthAssociate");
            skipped_loc = SE_TRUE;
        }
        if (feature_node_start != NULL)
            SE_FreeObject(feature_node_start);
    }

   /*
    * If feature_edge is a loop and no <Location> instances
    * were skipped and only one <Location> was found, this
    * is a degenerate case
    */
    if ((is_loop == SE_TRUE) && (skipped_loc != SE_TRUE) &&
        (loc_array_count == 1))
    {
         se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
           "degenerate loop - contains no interior <Location> components");
    }
    else if (check_object_list_for_duplicate_locations(loc_array_count,
             loc_array, &i) == SE_TRUE)
    {
         se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
            "violates <<Feature Edge Constraints>>, part (a)");
         se_message(loc_array[i], SE_CLS_DRM_LOCATION, level+1, path,
            MSGTYP_WARNING, "first duplicate found");
         valid_loc_array = SE_FALSE;
    }
    else if (skipped_loc == SE_TRUE)
    {
         se_message(feature_edge, path[level], level, path, MSGTYP_WARNING,
            "could not verify <<Feature Edge Constraints>>, part (a) "\
            "- some <Location> instances could not be checked");
         valid_loc_array = SE_FALSE;
    }

    for (i = 0; i < loc_array_count; i++)
    {
        SE_FreeObject(loc_array[i] );
    }
    free(loc_array);
    loc_array = NULL;

   /*
    * Topology levels 4 and 5 by definition contain only
    * <Location 3D> instances
    */
    if ((contains_2D == SE_TRUE) &&
        ((context->feature_topology_level == SE_FTL_FOUR)
      || (context->feature_topology_level == SE_FTL_FIVE)))
    {
        se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
           "violates the feature_topology_level's definition "\
           "(must contain <Location 3D> instances only)");
    }

   /*
    * Step through the ordered <Feature Face> associates, if any;
    * each must have exactly one <Feature Face Ring> associating
    * to this <Feature Edge>
    */
    iter = NULL;
    if (SE_InitializeAssociateIterator(feature_edge,
        GetGlobalAssociationFilter(SE_CLS_DRM_FEATURE_EDGE),
        SE_ITRBEH_RESOLVE, &iter) == SE_RETCOD_SUCCESS)
    {
        SE_Remaining_Objects_List ro_list;
        SE_Integer_Unsigned       face_indx1 = 0, face_indx2 = 0,
                                  distinct_face_count = 0;
        SE_Boolean                found = SE_FALSE;

        if (SE_GetRemainingObjectsList(iter, &ro_list) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_feature_edge:SE_GetRemainingObjectsList");
             se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
                "can't get associated <Feature Face> instances, if any");
            SE_FreeIterator(iter);
            return;
        }
        SE_FreeIterator(iter);

        distinct_face_count = ro_list.object_count;
        if (ro_list.object_count > 1)
        {
            for (face_indx1 = 0; face_indx1 < ro_list.object_count-1;
                 face_indx1++)
            {
                found = SE_FALSE;
                for (face_indx2 = face_indx1+1; (found != SE_TRUE) &&
                     (face_indx2 < ro_list.object_count); face_indx2++)
                {
                    if (SE_ObjectsAreSame(ro_list.remaining_objects_list[face_indx1],
                        ro_list.remaining_objects_list[face_indx2], &found)
                        != SE_RETCOD_SUCCESS)
                    {
                        printLastFnctStatus
                        ("check_feature_edge:SE_ObjectsAreSame");
                        se_message2(feature_edge,
                           ro_list.remaining_objects_list[face_indx1],
                           path[level], level, path, MSGTYP_ERROR,
                           "can't verify associated <Feature Face> instance is unique");
                        found = SE_FALSE;
                    }
                } /* end for */

                if (found != SE_TRUE)
                {
                    local_CheckEdgeBorderingFace(level, path, feature_edge,
                        ro_list.remaining_objects_list[face_indx1]);
                }
                else
                {
                    se_message2(feature_edge,
                       ro_list.remaining_objects_list[face_indx1],
                       path[level], level, path, MSGTYP_ERROR,
                       "multiple associations to same <Feature Face> instance");
                    distinct_face_count--;
                }
            } /* end for */
        } /* end if (ro_list.object_count > 1) */

        if (ro_list.object_count > 0)
        {
            local_CheckEdgeBorderingFace(level, path, feature_edge,
                ro_list.remaining_objects_list[ro_list.object_count-1]);
        } /* end if (ro_list.object_count > 0) */

        SE_FreeRemainingObjectsList(&ro_list);

        if ((context->feature_topology_level == SE_FTL_THREE)
         && (distinct_face_count != 2))
        {
            se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
               "violates feature topology level 3 requirements - does not "\
               "associate to two <Feature Face> instances");
        }
    }
    else
    {
        printLastFnctStatus
        ("check_feature_edge:SE_InitializeAssociateIterator");
         se_message(feature_edge, path[level], level, path, MSGTYP_ERROR,
            "can't initialize associate iter");
    }
} /* end check_feature_edge */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_face_ring
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_feature_face_ring
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_face_ring,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  feature_face,
    SE_Object                  union_of_feature_topology
)
{
    SE_Return_Code            ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator               iter = NULL;
    SE_Remaining_Objects_List ro_list;
    SE_FIELDS_PTR             link_fields_i_ptr = NULL,
                              link_fields_j_ptr = NULL;
    SE_Integer_Unsigned       i = 0, j = 0;
    SE_Boolean                found_edge = SE_FALSE,
                              obj_match = SE_FALSE;

    path[level] = fields_ptr->tag;

    if (SE_InitializeAssociateIterator(feature_face_ring, NULL,
        SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(feature_face_ring, path[level], level, path, MSGTYP_ERROR,
           "can't initialize associate iter");
        return SE_RETCOD_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iter, &ro_list)
             != SE_RETCOD_SUCCESS)
    {
        SE_FreeIterator(iter);
        se_message(feature_face_ring, path[level], level, path, MSGTYP_ERROR,
           "can't get ro_list");
        return SE_RETCOD_FAILURE;
    }
    else if (ro_list.object_count < 1)
    {
        SE_FreeIterator(iter);
        SE_FreeRemainingObjectsList(&ro_list);
        se_message(feature_face_ring, path[level], level, path,
           MSGTYP_ERROR, "no associates");
        return SE_RETCOD_FAILURE;
    }
    SE_FreeIterator(iter);

    for (i = 0; i < ro_list.object_count; i++)
    {
        found_edge = SE_FALSE;
        if (local_IsComponentOf(level, path, union_of_feature_topology,
            ro_list.remaining_objects_list[i], NULL, &found_edge)
            == SE_RETCOD_SUCCESS)
        {
            if (found_edge != SE_TRUE)
            {
                se_message(ro_list.remaining_objects_list[i],
                    SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                   "<Feature Edge> is not a component of "\
                   "the <Union Of Feature Topology> instance containing "\
                   "the <Feature Face>");
            }
        }
        else
        {
            se_message(ro_list.remaining_objects_list[i],
              SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
              "can't verify whether <Feature Edge> is a component of "\
              "the <Union Of Feature Topology> instance containing "\
              "the <Feature Face>");
        }
    }

   /*
    * check <Feature Edge> direction constraints
    * 1) <<Face Ring Edge Consistency>>
    *    - a <Feature Face Ring> instance can associate to a
    *      <Feature Edge> instance at most twice, where the
    *      two relationships specify <Edge Direction> link objects
    *      with opposite forwards field values
    * 2) if any <Feature Edge> appears more than once, *all*
    *    of them have to, or the <Feature Face Ring> self-overlaps
    *    as well as being degenerate
    */
    if (ro_list.object_count > 1)
    {
        SE_Boolean is_degenerate = SE_FALSE,
                   self_overlapping = SE_FALSE;

        for (i = 0; (ret_status == SE_RETCOD_SUCCESS) &&
                    (i < ro_list.object_count - 1); i++)
        {
            if (SE_GetFields(
                ro_list.remaining_link_objects_list[i],
                GetGlobalStore(level),
                &link_fields_i_ptr) == SE_RETCOD_SUCCESS)
            {
                SE_Object  end_node_i = NULL, start_node_j = NULL;
                SE_Boolean found_edge_twice = SE_FALSE;

               /*
                * fetch the end node for the ith edge's orientation
                */
                if (link_fields_i_ptr->u.Edge_Direction.forwards == SE_TRUE)
                {
                    if (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
                        SE_CLS_DRM_FEATURE_NODE, 2, &end_node_i, NULL) !=
                        SE_RETCOD_SUCCESS)
                    {
                        path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
                        se_message(ro_list.remaining_objects_list[i],
                             SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                             "can't get end <Feature Node>");
                        end_node_i = NULL;
                        ret_status = SE_RETCOD_FAILURE;
                    }
                }
                else
                {
                    if (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
                        SE_CLS_DRM_FEATURE_NODE, 1, &end_node_i, NULL) !=
                        SE_RETCOD_SUCCESS)
                    {
                        path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
                        se_message(ro_list.remaining_objects_list[i],
                             SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                             "can't get start <Feature Node>");
                        end_node_i = NULL;
                        ret_status = SE_RETCOD_FAILURE;
                    }
                }

               /*
                * loop through the remaining edges of the ring
                * - detect any duplicates of this edge
                *   - if more than one, violation
                *   - if this is the first edge and has a duplicate,
                *     then to be valid, the ring must be degenerate
                *     such that each edge has exactly one duplicate
                *   - if this is the first edge and has no duplicate,
                *     then to be valid, the ring must be not be degenerate
                *     and no edge has any duplicates
                */
                for (j = i+1, found_edge=SE_FALSE, found_edge_twice=SE_FALSE;
                     (ret_status == SE_RETCOD_SUCCESS) &&
                     (found_edge_twice != SE_TRUE) &&
                     (j < ro_list.object_count); j++)
                {
                    if (SE_ObjectsAreSame(ro_list.remaining_objects_list[i],
                        ro_list.remaining_objects_list[j], &obj_match) ==
                        SE_RETCOD_SUCCESS)
                    {
                        if (obj_match == SE_TRUE)
                        {
                            if (found_edge == SE_FALSE)
                            {
                                found_edge = SE_TRUE;
                                if (SE_GetFields(ro_list.
                                      remaining_link_objects_list[j],
                                      GetGlobalTempStore(level),
                                      &link_fields_j_ptr) == SE_RETCOD_SUCCESS)
                                {
                                    if (link_fields_i_ptr->u.Edge_Direction.forwards ==
                                        link_fields_j_ptr->u.Edge_Direction.forwards)
                                    {
                                        se_message(ro_list.remaining_link_objects_list[i],
                                           SE_CLS_DRM_EDGE_DIRECTION, level+1, path,
                                           MSGTYP_ERROR,
                                           "violates <<Face Ring Edge Consistency>>");
                                        ret_status = SE_RETCOD_FAILURE;
                                    }
                                }
                                else
                                {
                                    se_message(ro_list.remaining_link_objects_list[j],
                                       SE_CLS_DRM_EDGE_DIRECTION, level+1, path,
                                       MSGTYP_ERROR, "can't get fields");
                                    ret_status = SE_RETCOD_FAILURE;
                                }
                            }
                            else
                            {
                                found_edge_twice = SE_TRUE;
                                se_message(ro_list.remaining_objects_list[i],
                                   SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                                   "violates <<Face Ring Edge Consistency>> - "\
                                   "appears more than twice in <Feature Face Ring>");
                                ret_status = SE_RETCOD_FAILURE;
                            }
                        }

                        if ((end_node_i != NULL) && (j == (i+1)))
                        {
                            obj_match = SE_FALSE;
                           /*
                            * fetch the jth edge's orientation and start node
                            */
                            if (SE_GetFields(ro_list.
                                  remaining_link_objects_list[j],
                                  GetGlobalTempStore(level),
                                  &link_fields_j_ptr) != SE_RETCOD_SUCCESS)
                            {
                                se_message(ro_list.remaining_link_objects_list[j],
                                    SE_CLS_DRM_EDGE_DIRECTION, level+1, path,
                                    MSGTYP_ERROR, "can't get fields");
                                ret_status = SE_RETCOD_FAILURE;
                            }
                            else
                            {
                                if ((link_fields_j_ptr->u.Edge_Direction.forwards ==
                                         SE_TRUE) &&
                                    (SE_GetNthAssociate(ro_list.remaining_objects_list[j],
                                     SE_CLS_DRM_FEATURE_NODE, 1, &start_node_j, NULL) !=
                                     SE_RETCOD_SUCCESS))
                                {
                                    path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
                                    se_message(ro_list.remaining_objects_list[j],
                                       SE_CLS_DRM_FEATURE_EDGE, level+1, path,
                                       MSGTYP_ERROR,
                                       "can't get start <Feature Node>");
                                    start_node_j = NULL;
                                    ret_status = SE_RETCOD_FAILURE;
                                }
                                else if ((link_fields_j_ptr->u.Edge_Direction.forwards !=
                                          SE_TRUE) &&
                                         (SE_GetNthAssociate(ro_list.remaining_objects_list[j],
                                          SE_CLS_DRM_FEATURE_NODE, 2, &start_node_j, NULL)
                                          != SE_RETCOD_SUCCESS))
                                {
                                    path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
                                    se_message(ro_list.remaining_objects_list[j],
                                       SE_CLS_DRM_FEATURE_EDGE, level+1, path,
                                       MSGTYP_ERROR, "can't get end <Feature Node>");
                                    start_node_j = NULL;
                                    ret_status = SE_RETCOD_FAILURE;
                                }
                                else if (SE_ObjectsAreSame(end_node_i, start_node_j,
                                         &obj_match) != SE_RETCOD_SUCCESS)
                                {
                                    printLastFnctStatus
                                    ("check_feature_face_ring:SE_ObjectsAreSame");
                                    se_message(ro_list.remaining_objects_list[i],
                                       SE_CLS_DRM_FEATURE_EDGE, level+1, path,
                                       MSGTYP_ERROR,
                                       "can't determine if end <Feature Node> associate is "\
                                       "the same object as the start <Feature Node> associate"\
                                       " of the next <Feature Edge> instance in the"\
                                       "<Feature Face Ring>");
                                    path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
                                    se_message2(start_node_j, end_node_i,
                                       SE_CLS_DRM_FEATURE_NODE, level+2, path, MSGTYP_WARNING,
                                       "start <Feature Node>, end <Feature Node>");
                                    ret_status = SE_RETCOD_FAILURE;
                                    continue;
                                }
                                else if (obj_match != SE_TRUE)
                                {
                                    if (link_fields_i_ptr->u.Edge_Direction.forwards == SE_TRUE)
                                    {
                                        if (link_fields_j_ptr->u.Edge_Direction.forwards == SE_FALSE)
                                        {
                                            se_message2(ro_list.remaining_objects_list[i], feature_face_ring,
                                               SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                                               "end <Feature Node> associate isn't the same object "\
                                               "as the start <Feature Node> associate of the next "\
                                               "<Feature Edge> instance in the <Feature Face Ring>; "\
                                               "<Feature Face Ring> instance isn't a ring");
                                            ret_status = SE_RETCOD_FAILURE;
                                        }
                                        else
                                        {
                                            se_message2(ro_list.remaining_objects_list[i], feature_face_ring,
                                               SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                                               "end <Feature Node> associate isn't the same object "\
                                               "as the end <Feature Node> associate of the next "\
                                               "<Feature Edge> instance in the <Feature Face Ring>; "\
                                               "<Feature Face Ring> instance isn't a ring");
                                            ret_status = SE_RETCOD_FAILURE;
                                        }
                                    }
                                    else
                                    {
                                        if (link_fields_j_ptr->u.Edge_Direction.forwards == SE_FALSE)
                                        {
                                            se_message2(ro_list.remaining_objects_list[i], feature_face_ring,
                                               SE_CLS_DRM_FEATURE_EDGE, level+1, path,
                                               MSGTYP_ERROR,
                                               "start <Feature Node> associate isn't the same object "\
                                               "as the start <Feature Node> associate of the next "\
                                               "<Feature Edge> instance in the <Feature Face Ring>; "\
                                               "<Feature Face Ring> instance isn't a ring");
                                            ret_status = SE_RETCOD_FAILURE;
                                        }
                                        else
                                        {
                                            se_message2(ro_list.remaining_objects_list[i], feature_face_ring,
                                               SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                                               "start <Feature Node> associate isn't the same object "\
                                               "as the end <Feature Node> associate of the next "\
                                               "<Feature Edge> instance in the <Feature Face Ring>; "\
                                               "<Feature Face Ring> instance isn't a ring");
                                            ret_status = SE_RETCOD_FAILURE;
                                        }
                                    }
                                }
                                if (start_node_j != NULL)
                                {
                                    SE_FreeObject(start_node_j);
                                    start_node_j = NULL;
                                }
                            } /* end if (end_node_i != NULL) && (j == (i-1)) */
                        }
                    }
                    else
                    {
                        printLastFnctStatus
                        ("check_feature_face_ring:SE_ObjectsAreSame");
                        ret_status = SE_RETCOD_FAILURE;
                        se_message2(ro_list.remaining_objects_list[i],
                           ro_list.remaining_objects_list[j],
                           SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_WARNING,
                           "can't compare <Feature Edge>s, aborting");
                    }
                } /* end for j */

                if (end_node_i != NULL)
                {
                    SE_FreeObject(end_node_i);
                }
                if (ret_status == SE_RETCOD_SUCCESS)
                {
                    if (i == 0)
                    {
                        is_degenerate = found_edge;
                    }
                    else if (is_degenerate != found_edge)
                    {
                        se_message(feature_face_ring,
                           SE_CLS_DRM_FEATURE_FACE_RING, level, path, MSGTYP_ERROR,
                           "<Feature Face Ring> instance self-overlaps - "\
                           "some <Feature Edge>s appear multiple times, but not all of them");
                        ret_status = SE_RETCOD_FAILURE;
                    }
                }
            }
            else
            {
                se_message(ro_list.remaining_link_objects_list[i],
                   SE_CLS_DRM_EDGE_DIRECTION, level+1, path, MSGTYP_ERROR,
                   "can't get fields");
                ret_status = SE_RETCOD_FAILURE;
            }
        } /* end for i */
    }
    else /* only one <Feature Edge>, so must be a loop */
    {
        SE_Object start_node = NULL, end_node = NULL;

        i = 0;
        if (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
            SE_CLS_DRM_FEATURE_NODE, 1, &start_node, NULL) !=
            SE_RETCOD_SUCCESS)
        {
            path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
            se_message(ro_list.remaining_objects_list[i],
                 SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                 "can't get end <Feature Node>");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
            SE_CLS_DRM_FEATURE_NODE, 2, &end_node, NULL) !=
            SE_RETCOD_SUCCESS)
        {
            SE_FreeObject(start_node);
            path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
            se_message(ro_list.remaining_objects_list[i],
                 SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                 "can't get end <Feature Node>");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_ObjectsAreSame(end_node, start_node, &obj_match) !=
                 SE_RETCOD_SUCCESS)
        {
            SE_FreeObject(start_node);
            SE_FreeObject(end_node);
            printLastFnctStatus("check_feature_face_ring:SE_ObjectsAreSame");
            se_message(ro_list.remaining_objects_list[i],
               SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
               "can't determine if end <Feature Node> associate is "\
               "the same object as the start <Feature Node> associate"\
               " of the next <Feature Edge> instance in the"\
               "<Feature Face Ring>");
            path[level+1] = SE_CLS_DRM_FEATURE_EDGE;
            se_message2(start_node, end_node,
               SE_CLS_DRM_FEATURE_NODE, level+2, path, MSGTYP_WARNING,
               "start <Feature Node>, end <Feature Node>");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (obj_match != SE_TRUE)
        {
            ret_status = SE_RETCOD_FAILURE;
            se_message(ro_list.remaining_objects_list[i],
                 SE_CLS_DRM_FEATURE_EDGE, level+1, path, MSGTYP_ERROR,
                 "<Feature Face Ring> instance's only associated <Feature Edge> "\
                 "does not start and end at the the same <Feature Node> instance");
        }
    } /* end if */

   /*
    * check <Feature Edge> constraints
    * 2) <<Edges Bordering Faces>> - if topology level >= 3, all
    *    <Feature Edge> instances associated by feature_face_ring
    *    must be associated to the <Feature Face> to which
    *    feature_face_ring belongs
    */
    if ((context->feature_topology_level == SE_FTL_THREE)
      || (context->feature_topology_level == SE_FTL_FOUR)
      || (context->feature_topology_level == SE_FTL_FIVE))
    {
        for (i = 0; i < ro_list.object_count; i++)
        {
            if ((local_IsAssociateOf(level, path,
                ro_list.remaining_objects_list[i], feature_face, NULL,
                &obj_match) == SE_RETCOD_SUCCESS) &&
                (obj_match != SE_TRUE))
            {
                se_message(ro_list.remaining_objects_list[i],
                   SE_CLS_DRM_FEATURE_EDGE, level, path, MSGTYP_ERROR,
                   "violates <<Edges Bordering Faces>>, part a.2 - "\
                   "missing <Feature Edge> to <Feature Face> association");
            }
        }
    }
    SE_FreeRemainingObjectsList(&ro_list);
    return ret_status;
} /* end check_feature_face_ring */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_volume_shell
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_feature_volume_shell
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_volume_shell,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  feature_volume,
    SE_Object                  union_of_feature_topology
)
{
    SE_Return_Code            ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator               iter = NULL;
    SE_Remaining_Objects_List ro_list;
    SE_FIELDS_PTR             link_fields_i_ptr = NULL,
                              link_fields_j_ptr = NULL;
    SE_Integer_Unsigned       i = 0, j = 0;
    SE_Boolean                found_face = SE_FALSE,
                              obj_match = SE_FALSE;

    path[level] = fields_ptr->tag;

    if (SE_InitializeAssociateIterator(feature_volume_shell, NULL,
        SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_feature_volume_shell:SE_InitializeAssociateIterator");
        se_message(feature_volume_shell, path[level], level, path,
           MSGTYP_ERROR, "can't initialize associate iter");
        return SE_RETCOD_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iter, &ro_list)
        != SE_RETCOD_SUCCESS)
    {
        SE_FreeIterator(iter);
        se_message(feature_volume_shell, path[level], level, path,
           MSGTYP_ERROR, "can't get ro_list");
        return SE_RETCOD_FAILURE;
    }
    else if (ro_list.object_count < 2)
    {
        se_message(feature_volume_shell, path[level], level, path,
           MSGTYP_ERROR, "fewer than 2 <Feature Face> associates - "\
           "invalid syntax");
        ret_status = SE_RETCOD_FAILURE;
    }
    SE_FreeIterator(iter);

   /*
    * check <Feature Volume Shell> direction constraints
    * 1) <<Volume Shell Face Consistency>>
    */
    if (ro_list.object_count > 1)
    {
        for (i = 0; (ret_status == SE_RETCOD_SUCCESS) &&
                    (i < ro_list.object_count - 1); i++)
        {
            SE_Boolean found_face_twice = SE_FALSE;

            found_face = SE_FALSE;
            if (local_IsComponentOf(level, path, union_of_feature_topology,
                ro_list.remaining_objects_list[i], NULL, &found_face)
                == SE_RETCOD_SUCCESS)
            {
                if (found_face != SE_TRUE)
                {
                    se_message(ro_list.remaining_objects_list[i],
                        SE_CLS_DRM_FEATURE_FACE, level+1, path, MSGTYP_ERROR,
                       "<Feature Face> is not a component of "\
                       "the <Union Of Feature Topology> instance containing "\
                       "the <Feature Volume>");
                }
            }
            else
            {
                se_message(ro_list.remaining_objects_list[i],
                  SE_CLS_DRM_FEATURE_FACE, level+1, path, MSGTYP_ERROR,
                  "can't verify whether start <Feature Face> is a "\
                  "component of the <Union Of Feature Topology> instance "\
                  "containing the <Feature Volume>");
            }

            if (SE_GetFields(ro_list.
                remaining_link_objects_list[i],
                GetGlobalStore(level),
                &link_fields_i_ptr) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus
                ("check_feature_volume_shell:SE_GetFields");
                se_message(ro_list.remaining_link_objects_list[i],
                   SE_CLS_DRM_FACE_DIRECTION, level+1, path,
                   MSGTYP_ERROR, "can't get fields");
                ret_status = SE_RETCOD_FAILURE;
            }

            for (j = i+1, found_face = SE_FALSE,
                 found_face_twice = SE_FALSE;
                 (ret_status == SE_RETCOD_SUCCESS) &&
                 (found_face_twice != SE_TRUE) &&
                 (j < ro_list.object_count); j++)
            {
                if (SE_ObjectsAreSame(ro_list.remaining_objects_list[i],
                    ro_list.remaining_objects_list[j], &obj_match) !=
                    SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_feature_volume_shell:SE_ObjectsAreSame");
                    continue;
                }
                else if (obj_match == SE_TRUE)
                {
                    if (found_face != SE_TRUE)
                    {
                        found_face = SE_TRUE;
                        if (SE_GetFields(ro_list.
                                 remaining_link_objects_list[j],
                                 GetGlobalTempStore(level),
                                &link_fields_j_ptr) == SE_RETCOD_SUCCESS)
                        {
                            if (link_fields_i_ptr->u.Face_Direction.front ==
                                link_fields_j_ptr->u.Face_Direction.front)
                            {
                                se_message(ro_list.remaining_objects_list[i],
                                   SE_CLS_DRM_FACE_DIRECTION, level+1, path, MSGTYP_ERROR,
                                   "violates <<Volume Shell Face Consistency>>");
                                ret_status = SE_RETCOD_FAILURE;
                            }
                        }
                        else
                        {
                            printLastFnctStatus
                            ("check_feature_volume_shell:SE_GetFields");
                            se_message(ro_list.remaining_link_objects_list[j],
                               SE_CLS_DRM_FACE_DIRECTION, level+1, path,
                               MSGTYP_ERROR, "can't get fields");
                        }
                    }
                    else
                    {
                        found_face_twice = SE_TRUE;
                        se_message(ro_list.remaining_objects_list[i],
                           SE_CLS_DRM_FEATURE_FACE, level+1, path,
                           MSGTYP_ERROR,
                           "violates <<Volume Shell Face Consistency>> - "\
                           "appears more than twice in <Feature Volume Shell>");
                        ret_status = SE_RETCOD_FAILURE;
                    }
                }
            } /* end for j */
        } /* end for i */
    }

   /*
    * check <Feature Face> constraints
    * 2) <<Faces Bordering Volumes>> - if topology level = 5, all
    *    <Feature Face> instances associated by feature_volume_shell
    *    must be associated to the <Feature Volume> to which
    *    feature_volume_shell belongs
    */
    if (context->feature_topology_level == SE_FTL_FIVE)
    {
        for (i = 0; i < ro_list.object_count; i++)
        {
            if ((local_IsAssociateOf(level, path,
                ro_list.remaining_objects_list[i], feature_volume, NULL,
                &obj_match) == SE_RETCOD_SUCCESS) &&
                (obj_match != SE_TRUE))
            {
                se_message(ro_list.remaining_objects_list[i],
                   SE_CLS_DRM_FEATURE_FACE, level, path, MSGTYP_ERROR,
                   "violates <<Faces Bordering Volumes>>, part b - "\
                   "missing <Feature Face> to <Feature Volume> association");
            }
        }
    }
    SE_FreeRemainingObjectsList(&ro_list);
    return ret_status;
} /* end check_feature_volume_shell */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_face
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_feature_face
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_face,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_feature_topology
)
{
    SE_Return_Code        ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Integer_Unsigned   feature_face_ring_count = 0;

    path[level] = SE_CLS_DRM_FEATURE_FACE;

    if (local_InitializeComponentIterator3(feature_face, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(feature_face, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * Note: a universal <Feature Face> instance with no interior
    * <Feature Face Ring> components and no <Location> components
    * and no <Property Value> components is a legal case, but in
    * that case the <Feature Face> instance's fields will indicate
    * that it is a universal <Feature Face> instance
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_feature_face:SE_GetNextObject");
            ret_status = SE_RETCOD_FAILURE;
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_FEATURE_FACE_RING:
                     feature_face_ring_count++;
                     check_feature_face_ring(level+1, path, next_object,
                         next_fields_ptr, context, summary, feature_face,
                         union_of_feature_topology);
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object, next_fields_ptr,
                         &eac_val_queue, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                        /*
                         * see definition of <Feature Face> <-> <Location> relationship
                         * for these constraints
                         */
                         if ((context->feature_topology_level != SE_FTL_FOUR)
                          && (context->feature_topology_level != SE_FTL_FIVE))
                         {
                             se_message(feature_face, next_fields_ptr->tag, level, path,
                                MSGTYP_ERROR,
                                "a <Feature Face> may not have <Location> components "\
                                "except for a feature_topology_level of 4 or 5");
                         }
                         else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION_3D]
                                  != SE_TRUE)
                         {
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                                MSGTYP_ERROR,
                                "the <Location> components must be 3D if present");
                         }
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_feature_face:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if ((fields_ptr->u.Feature_Face.universal != SE_TRUE) &&
        (feature_face_ring_count < 1))
    {
        se_message(feature_face, path[level], level, path, MSGTYP_ERROR,
                 "<Feature Face> instance has universal != SE_TRUE but "\
                 "has no exterior <Feature Face Ring> component");
        ret_status = SE_RETCOD_FAILURE;
    }

   /*
    * check <<Face Direction Levels 0 3>>
    */
    if ((context->feature_topology_level != SE_FTL_FOUR)
     && (context->feature_topology_level != SE_FTL_FIVE))
    {
        if (SE_InitializeAssociateIterator(feature_face,
            GetGlobalAssociationFilter(SE_CLS_DRM_FEATURE_FACE),
            SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
        {
            se_message(feature_face, path[level], level, path,
               MSGTYP_ERROR, "can't initialize associate iter");
            ret_status = SE_RETCOD_FAILURE;
        }
        else
        {
            SE_Object     link_object = NULL;
            SE_FIELDS_PTR link_fields_ptr = NULL;

            while (SE_IsIteratorComplete(iter) == SE_FALSE)
            {
                if (SE_GetNextObject(iter, &next_object, &link_object) != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus("check_feature_face:SE_GetNextObject");
                    continue;
                }
                SE_UpdateAnalysisCounts();

                if (SE_GetFields(link_object, GetGlobalStore(level),
                    &link_fields_ptr) == SE_RETCOD_SUCCESS)
                {
                    SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                    if (link_fields_ptr->u.Face_Direction.front != SE_TRUE)
                    {
                        se_message(link_object, SE_CLS_DRM_FACE_DIRECTION, level+1, path,
                           MSGTYP_ERROR, "violates <<Face Direction Levels 0 3>>");
                    }
                }
                else
                {
                    printLastFnctStatus("check_feature_face:SE_GetFields");
                    se_message(link_object, SE_CLS_DRM_FACE_DIRECTION, level+1, path,
                       MSGTYP_ERROR, "can't get fields");
                }
                SE_FreeObject(next_object);
                SE_FreeObject(link_object);
            }
            SE_FreeIterator(iter);
        }
    }
    return ret_status;
} /* end check_feature_face */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_feature_volume
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_feature_volume
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  feature_volume,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_feature_topology
)
{
    SE_Return_Code        ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Integer_Unsigned   feature_volume_shell_count = 0;

    path[level] = SE_CLS_DRM_FEATURE_VOLUME;

    if (local_InitializeComponentIterator3(feature_volume, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_feature_volume:SE_InitializeComponentIterator");
        se_message(feature_volume, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * Note: a universal <Feature Volume> instance with no interior
    * <Feature Volume Shell> components and no <Property Value>
    * components is a legal case, but in that case the
    * <Feature Volume> instance's fields will indicate that it
    * is a universal <Feature Volume> instance
    */
    while (SE_IsIteratorComplete(iter ) == SE_FALSE )
    {
        if (SE_GetNextObjectOnly(iter, &next_object ) != SE_RETCOD_SUCCESS )
        {
            printLastFnctStatus("check_feature_volume:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_FEATURE_VOLUME_SHELL:
                     feature_volume_shell_count++;
                     check_feature_volume_shell(level+1, path, next_object,
                         next_fields_ptr, context, summary, feature_volume,
                         union_of_feature_topology);
                     break;
                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object, next_fields_ptr,
                         &eac_val_queue, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_feature_volume:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path, MSGTYP_ERROR,
               "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if ((fields_ptr->u.Feature_Volume.universal != SE_TRUE) &&
        (feature_volume_shell_count < 1))
    {
        se_message(feature_volume, path[level], level, path, MSGTYP_ERROR,
                 "<Feature Volume> instance has universal != SE_TRUE but "\
                 "has no exterior <Feature Volume Shell> component");
        ret_status = SE_RETCOD_FAILURE;
    }
    return ret_status;
} /* end check_feature_volume */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_union_of_feature_topology
 *
 *-----------------------------------------------------------------------------
 */
static void
check_union_of_feature_topology
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  union_of_feature_topology,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator          iter = NULL;
    SE_Object            next_object = NULL;
    SE_FIELDS_PTR        next_fields_ptr = NULL;
    SE_Integer_Unsigned  edge_count = 0, i = 0, j = 0, node_count = 0;
    SE_Object           *node_loc_array = NULL;
    SE_Boolean           check_for_duplicate_nodes = SE_TRUE,
                         found_duplicates = SE_FALSE,
                         found_universal_face = SE_FALSE,
                         found_universal_volume = SE_FALSE;

    path[level] = SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY;

   /*
    *--------------------------------------------------------------------------
    * check <Feature Node> instances
    *--------------------------------------------------------------------------
    */
    if (local_InitializeComponentIterator3(union_of_feature_topology,
        GetGlobalComponentFilter(SE_CLS_DRM_FEATURE_NODE), &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(union_of_feature_topology, path[level], level, path,
           MSGTYP_ERROR, "can't initialize <Feature Node> component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter, &node_count)
             != SE_RETCOD_SUCCESS) ||
             (node_count < 1))
    {
        se_message(union_of_feature_topology, path[level], level, path,
           MSGTYP_WARNING, "can't count any <Feature Node> components");
        check_for_duplicate_nodes = SE_FALSE;
    }
    else
    {
        if ((node_loc_array=(SE_Object *)
             calloc(sizeof(SE_Object),node_count))==NULL)
        {
            se_message(union_of_feature_topology, path[level], level, path,
               MSGTYP_ERROR,
               "can't calloc array of <Location>s, "\
               "can't fully test feature_topology_level");
            check_for_duplicate_nodes = SE_FALSE;
        }

        i = 0;
        while (SE_IsIteratorComplete(iter) == SE_FALSE)
        {
            if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS )
            {
                printLastFnctStatus
                ("check_union_of_feature_topology:SE_GetNextObject");
                continue;
            }
            SE_UpdateAnalysisCounts();

            SE_UpdateLocalSummaryFromDRMClass(summary, SE_CLS_DRM_FEATURE_NODE);

            if (check_feature_node(level+1, path, next_object,
                (check_for_duplicate_nodes == SE_TRUE) ?
                &(node_loc_array[i]) : NULL, context, summary,
                 union_of_feature_topology) == SE_RETCOD_SUCCESS)
            {
                i++;
            }
            SE_FreeObject(next_object);
        }
    }
    SE_FreeIterator(iter);
    iter = NULL;

   /*
    * if all the <Feature Node>s were checked and no
    * duplicates were found, this is not SE_FTL_ZERO
    * (assuming all <Feature Edge> endpoints are hooked up)
    */
    if (check_for_duplicate_nodes == SE_TRUE)
    {
        if (i > 1)
            found_duplicates = check_object_list_for_duplicate_locations
                               (i, node_loc_array, &j);
        else
            found_duplicates = SE_FALSE;

        if (found_duplicates == SE_TRUE)
        {
            if (context->feature_topology_level != SE_FTL_ZERO)
            {
                se_message(union_of_feature_topology, path[level],
                   level, path, MSGTYP_ERROR,
                   "violates feature_topology_level "\
                   "(colocated <Feature Node>s)");

                path[level+1] = SE_CLS_DRM_FEATURE_NODE;
                se_message(node_loc_array[j], SE_CLS_DRM_LOCATION,
                   level+2, path, MSGTYP_WARNING,
                   "first duplicate <Location>");
            }
        }
        else if ((i == node_count)
              && (context->feature_topology_level == SE_FTL_ZERO))
        {
            se_message(union_of_feature_topology, path[level],
               level, path, MSGTYP_ERROR,
               "has no co-located <Feature Node>s but "\
               "feature_topology_level == SE_FTL_ZERO");
        }

        if (node_loc_array != NULL)
        {
            SE_Integer_Unsigned found_count = 0;

            found_count = i;
            for (i = 0; i < found_count; i++)
            {
                SE_FreeObject(node_loc_array[i]);
            }
            free(node_loc_array);
            node_loc_array = NULL;
        }
    }

   /*
    *--------------------------------------------------------------------------
    * check <Feature Edge> instances
    *--------------------------------------------------------------------------
    */
    if (local_InitializeComponentIterator3(union_of_feature_topology,
        GetGlobalComponentFilter(SE_CLS_DRM_FEATURE_EDGE), &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(union_of_feature_topology, path[level], level, path,
           MSGTYP_ERROR, "can't initialize <Feature Edge> component iter");
        return;
    }
    else
    {
        edge_count = 0;
        while (SE_IsIteratorComplete(iter) == SE_FALSE)
        {
            if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus
                ("check_union_of_feature_topology:SE_GetNextObject");
                continue;
            }
            SE_UpdateAnalysisCounts();
            SE_UpdateLocalSummaryFromDRMClass(summary, SE_CLS_DRM_FEATURE_EDGE);
            edge_count++;

            check_feature_edge(level+1, path, next_object,
                context, summary, union_of_feature_topology);
        }
    }
    SE_FreeIterator(iter);
    iter = NULL;

   /*
    *--------------------------------------------------------------------------
    * check <Feature Face> instances
    *--------------------------------------------------------------------------
    */
    if (local_InitializeComponentIterator3(union_of_feature_topology,
        GetGlobalComponentFilter(SE_CLS_DRM_FEATURE_FACE), &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(union_of_feature_topology, path[level], level, path,
           MSGTYP_ERROR, "can't initialize <Feature Face> component iter");
        return;
    }
    else
    {
        while (SE_IsIteratorComplete(iter) == SE_FALSE)
        {
            if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus
                ("check_union_of_feature_topology:SE_GetNextObject");
                continue;
            }
            SE_UpdateAnalysisCounts();
            if (SE_GetFields(next_object, GetGlobalStore(level),
                &next_fields_ptr) == SE_RETCOD_SUCCESS)
            {
                SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                if (next_fields_ptr->u.Feature_Face.universal == SE_TRUE)
                {
                    if (found_universal_face == SE_TRUE)
                    {
                        se_message(union_of_feature_topology, path[level],
                           level, path, MSGTYP_ERROR,
                           "contains multiple universal <Feature Face>s");
                        se_message(next_object, SE_CLS_DRM_FEATURE_FACE,
                           level+1, path, MSGTYP_WARNING,
                           "first extra universal <Feature Face> found");
                    }
                    else
                        found_universal_face = SE_TRUE;
                }
                check_feature_face(level+1, path, next_object, next_fields_ptr,
                    context, summary, union_of_feature_topology);
            }
        }
    }
    SE_FreeIterator(iter);
    iter = NULL;

   /*
    *--------------------------------------------------------------------------
    * check <Feature Volume> instances
    *--------------------------------------------------------------------------
    */
    if (local_InitializeComponentIterator3(union_of_feature_topology,
        GetGlobalComponentFilter(SE_CLS_DRM_FEATURE_VOLUME), &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(union_of_feature_topology, path[level], level, path,
           MSGTYP_ERROR, "can't initialize <Feature Volume> component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS )
        {
            printLastFnctStatus
            ("check_union_of_feature_topology:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->u.Feature_Volume.universal == SE_TRUE)
            {
                if (found_universal_volume == SE_TRUE)
                {
                    se_message(union_of_feature_topology, path[level],
                       level, path, MSGTYP_ERROR,
                       "contains multiple universal <Feature Volume>s");
                    se_message(next_object, SE_CLS_DRM_FEATURE_VOLUME,
                       level+1, path, MSGTYP_WARNING,
                       "first extra universal <Feature Volume> found");
                }
                else
                    found_universal_volume = SE_TRUE;
            }
            check_feature_volume(level+1, path, next_object, next_fields_ptr,
                context, summary, union_of_feature_topology);
        }
        else
        {
            printLastFnctStatus
            ("check_union_of_feature_topology:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_FEATURE_VOLUME, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

   /*
    * check for universal <Feature Face>
    */
    switch (context->feature_topology_level)
    {
        case SE_FTL_THREE:
             if (found_universal_face != SE_TRUE)
             {
                 se_message(union_of_feature_topology, path[level],
                    level, path, MSGTYP_ERROR,
                    "no universal <Feature Face> (required by"\
                    " feature_topology_level)");
             }
             break;

        case SE_FTL_FIVE:
             if (found_universal_volume != SE_TRUE)
             {
                 se_message(union_of_feature_topology, path[level],
                    level, path, MSGTYP_ERROR,
                    "no universal <Feature Volume> (required by"\
                    " feature_topology_level)");
             }
             break;
    } /* end switch */
} /* end check_union_of_feature_topology */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_perimeter_related_feature_topology
 *
 *-----------------------------------------------------------------------------
 */
static void
check_perimeter_related_feature_topology
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL, link_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_perimeter_related_feature_topology:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_perimeter_related_feature_topology:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            SE_UpdateAnalysisCounts();

            check_perimeter_data(level+1, path, link_object, context, summary);
            check_topology_hierarchy(level+1, path, next_object,
                next_fields_ptr, context, summary);
        }
        else
        {
            printLastFnctStatus
            ("check_perimeter_related_feature_topology:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }

        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_perimeter_related_feature_topology */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_index_related_feature_topology
 *
 *-----------------------------------------------------------------------------
 */
static void
check_spatial_index_related_feature_topology
(
          SE_Short_Integer_Unsigned                 level,
          SE_DRM_Class                              path
                                                    [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                 object,
    const SE_Spatial_Index_Related_Feature_Topology_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                                 *context,
          SE_LOCAL_SUMMARY                                 *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         cell_count = 0, i = 0;
    SE_Spatial_Index_Parameters link_fields;
    char                        err_msg[256];
    SE_FIELDS_PTR               link_fields_ptr = NULL, next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus(
         "check_spatial_index_related_feature_topology:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
              &(link_fields.spatial_index_data_count))!=SE_RETCOD_SUCCESS)
          || (link_fields.spatial_index_data_count < 1))
    {
        printLastFnctStatus
        ("check_spatial_index_related_feature_topology:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.spatial_index_data_array =
              (SE_Spatial_Index_Data_Fields *)
               calloc(link_fields.spatial_index_data_count,
                      sizeof(SE_Spatial_Index_Data_Fields)))==NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't calloc spatial_index_data_array");
        SE_FreeIterator(iter);
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus(
             "check_spatial_index_related_feature_topology:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
            {
                check_location(level+1, path, next_object, next_fields_ptr,
                  NULL, context, summary);
            }
            else
            {
                if (SE_GetFields(link_object, GetGlobalTempStore(level),
                    &link_fields_ptr) == SE_RETCOD_SUCCESS)
                {
                    SE_UpdateAnalysisCounts();
                    SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                    if ((link_fields_ptr->u.Spatial_Index_Data.row_index
                                      > fields_ptr->row_count) ||
                         (link_fields_ptr->u.Spatial_Index_Data.column_index
                                      > fields_ptr->column_count) )
                    {
                        sprintf(err_msg, "(%u, %u) out of aggregate range "\
                            "(1,1) to (%u, %u)\n",
                            (unsigned int) link_fields_ptr->u.
                                Spatial_Index_Data.row_index,
                            (unsigned int) link_fields_ptr->u.
                                Spatial_Index_Data.column_index,
                            (unsigned int) fields_ptr->row_count,
                            (unsigned int) fields_ptr->column_count);
                        se_message(next_object, SE_CLS_DRM_SPATIAL_INDEX_DATA,
                           level+1, path, MSGTYP_ERROR, err_msg);
                    }
                    memcpy(&(link_fields.spatial_index_data_array[i]),
                           &(link_fields_ptr->u.Spatial_Index_Data),
                           sizeof(SE_Spatial_Index_Data_Fields));
                    i++;
                }
                else
                {
                    se_message(next_object, SE_CLS_DRM_SPATIAL_INDEX_DATA,
                       level+1, path, MSGTYP_ERROR,
                       "Can't get fields of link object");
                }
                check_topology_hierarchy(level+1, path, next_object,
                    next_fields_ptr, context, summary);
            }
        }
        else
        {
            printLastFnctStatus(
             "check_spatial_index_related_feature_topology:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    cell_count = fields_ptr->column_count * fields_ptr->row_count;

    if (i != cell_count)
    {
        sprintf(err_msg, "# actual cells don't match column_count(%u)*"\
                "row_count(%u)=%u", (unsigned int)fields_ptr->column_count,
                (unsigned int)fields_ptr->row_count,
                (unsigned int)cell_count);
        se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
    link_fields.spatial_index_data_count = i;

    if (!SE_ValidSpatialIndexParameters(&link_fields, SE_FALSE, NULL))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
        SE_ValidSpatialIndexParameters(&link_fields, SE_TRUE, NULL);
    }
    free(link_fields.spatial_index_data_array);
} /* end check_spatial_index_related_feature_topology */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_topology_hierarchy
 *
 *-----------------------------------------------------------------------------
 */
static void
check_topology_hierarchy
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Boolean                old_context_has_ft_level = SE_FALSE;
    SE_Feature_Topology_Level old_context_ft_level = SE_FTL_ZERO;

    path[level] = fields_ptr->tag;

    old_context_has_ft_level = context->has_ft_level;
    old_context_ft_level     = context->feature_topology_level;

    if (!SE_ValidFeatureTopologyLevel
        (fields_ptr->u.Feature_Topology_Hierarchy.feature_topology_level))
    {
        if (context->has_ft_level == SE_TRUE)
        {
            se_message(object, fields_ptr->tag, level, path,
               MSGTYP_ERROR_SYNTAX, "invalid fields, "\
               "using aggregate's feature_topology_level");
        }
        else
        {
            se_message(object, fields_ptr->tag, level, path,
               MSGTYP_ERROR_SYNTAX, "invalid fields, "\
               "treating feature_topology_level as level 0");
            context->has_ft_level = SE_TRUE;
            context->feature_topology_level = SE_FTL_ZERO;
        }
    }
    else
    {
        if ((context->has_ft_level == SE_TRUE) &&
            (fields_ptr->u.Feature_Topology_Hierarchy.feature_topology_level !=
             context->feature_topology_level))
        {
            switch (context->feature_topology_level)
            {
                case SE_FTL_ZERO:
                     break;

                case SE_FTL_ONE:
                     if (fields_ptr->u.Feature_Topology_Hierarchy.
                         feature_topology_level == SE_FTL_ZERO)
                     {
                         se_message(object, fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "feature_topology_level is "\
                            "inconsistent with that of the aggregate");
                     }
                     break;
                case SE_FTL_TWO:
                     if ((fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ZERO) ||
                         (fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ONE))
                     {
                         se_message(object, fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "feature_topology_level is "\
                            "inconsistent with that of the aggregate");
                     }
                     break;
                case SE_FTL_THREE:
                     if ((fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ZERO) ||
                         (fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ONE))
                     {
                         se_message(object, fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "feature_topology_level is "\
                            "inconsistent with that of the aggregate");
                     }
                     break;
                case SE_FTL_FOUR:
                     if ((fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ZERO) ||
                         (fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ONE))
                     {
                         se_message(object, fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "feature_topology_level is "\
                            "inconsistent with that of the aggregate");
                     }
                     break;
                case SE_FTL_FIVE:
                     if ((fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ZERO) ||
                         (fields_ptr->u.Feature_Topology_Hierarchy.
                          feature_topology_level == SE_FTL_ONE))
                     {
                         se_message(object, fields_ptr->tag, level, path,
                            MSGTYP_ERROR, "feature_topology_level is "\
                            "inconsistent with that of the aggregate");
                     }
                     break;
                default:
                     break;
            } /* end switch */
        }
        context->has_ft_level = SE_TRUE;
        context->feature_topology_level =
           fields_ptr->u.Feature_Topology_Hierarchy.feature_topology_level;
    }

    switch (path[level])
    {
        case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
             check_perimeter_related_feature_topology(level, path,
                  object, context, summary);
             break;
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
             local_CheckSpatialIndexUnit
             (level, path, object, fields_ptr, &(context->srf_context_info));

             check_spatial_index_related_feature_topology(level, path, object,
                &(fields_ptr->u.Spatial_Index_Related_Feature_Topology),
                  context, summary);
             break;
        case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
             check_union_of_feature_topology(level, path, object,
                 fields_ptr, context, summary);
             break;
        default:
             se_message(object, fields_ptr->tag, level, path, MSGTYP_ERROR,
                "invalid component");
             break;
    }
    context->has_ft_level           = old_context_has_ft_level;
    context->feature_topology_level = old_context_ft_level;
} /* end check_topology_hierarchy */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_primitive_feature
 *
 *-----------------------------------------------------------------------------
 */
static void
check_primitive_feature
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  primitive_feature,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_LOCAL_CONTEXT      local_context;
    SE_Boolean            has_spatial_extent = SE_FALSE;

    path[level] = fields_ptr->tag;

   /*
    * SE_SpawnUpdatedLocalContext handles any <Spatial Extent>
    */
    SE_SpawnUpdatedLocalContext(level, path, primitive_feature, context,
        &local_context, summary, &has_spatial_extent);

    if (local_InitializeComponentIterator3(primitive_feature, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_primitive_feature:SE_InitializeComponentIterator");
        se_message(primitive_feature, path[level], level, path,
           MSGTYP_ERROR, "can't initialize component iter");
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_primitive_feature:SE_GetNextObject");
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

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                        context, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_primitive_feature:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);

   /*
    * $$$ subclass-specific calls for topology constraints
    *     will go here
    */
   /*
    * do *not* free local_context
    */
} /* end check_primitive_feature */
