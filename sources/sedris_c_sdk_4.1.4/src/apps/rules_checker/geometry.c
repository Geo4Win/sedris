/*
 * FILE       : geometry.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a transmittal, with regard
 *    to constraints affecting <Geometry Representation> instances.
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
#include "geometry.h"
#include "image.h"
#include "metadata.h"
#include "prop_set_table.h"
#include "sound_symbol.h"

static void
check_perimeter_related_geometry_topology
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_polygon
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  polygon,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_primitive_geometry
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  prim_geometry,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

static void
check_PGHP
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                 mandatory_spatial_extent
);

static void
check_spatial_index_related_geometry_topology
(
          SE_Short_Integer_Unsigned                 level,
          SE_DRM_Class                              path
                                                    [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                 object,
    const SE_Spatial_Index_Related_Geometry_Topology_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                                  *context,
          SE_LOCAL_SUMMARY                                  *summary
);

static void
check_stamp_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
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

static void
check_union_of_primitive_geometry
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                 inherits_classification_data
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_union_of_geometry_hierarchy
 *
 *-----------------------------------------------------------------------------
 */
static void
check_union_of_geometry_hierarchy
(
          SE_Short_Integer_Unsigned              level,
          SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                              object,
    const SE_Union_Of_Geometry_Hierarchy_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                      *context,
          SE_LOCAL_SUMMARY                      *summary,
          SE_Boolean                             inherits_classification_data
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Boolean            pass_down_classification_data = SE_FALSE;
    SE_Integer_Unsigned   vector_count = 0,
                          vector_type_array[SE_REFVEC_VERTICAL_AXIS+1];
    char                  err_msg[256];

    if (SE_GetComponent(object, SE_CLS_DRM_CLASSIFICATION_DATA, SE_FALSE,
        SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_Classification_Entry entry;

            check_classification_data
            (level+1, path, next_object, next_fields_ptr, &entry, summary);

            SE_FreeClassificationEntry(&entry, NULL);
        }
        else
        {
            printLastFnctStatus
            ("check_union_of_geometry_hierarchy:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_CLASSIFICATION_DATA, level+1,
               path, MSGTYP_ERROR, "can't get fields");
        }

        if (fields_ptr->union_reason == SE_UNIONREAS_OTHER)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
             "union_reason violates <<Classification Data Constraints>> "\
             "(has <Classification Data> so union_reason cannot "\
             "be SE_UNIONREAS_OTHER)");
        }
        else if (fields_ptr->union_reason ==
                 SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS)
        {
            pass_down_classification_data = SE_TRUE;
        }
    }
    else if ((fields_ptr->union_reason == SE_UNIONREAS_OTHER) &&
             (inherits_classification_data == SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
         "union_reason violates <<Classification Data Constraints>> "\
         "(inherits <Classification Data> so union_reason cannot "\
         "be SE_UNIONREAS_OTHER)");
    }
    else if ((fields_ptr->union_reason ==
             SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS) &&
             (inherits_classification_data == SE_TRUE))
    {
        pass_down_classification_data = SE_TRUE;
    }
    else if ((fields_ptr->union_reason != SE_UNIONREAS_OTHER) &&
             (inherits_classification_data != SE_TRUE))
    {
       /*
        * $$$ what if only some contexts for the
        * $$$ <Union Of Geometry Hierarchy> supply <Classification Data>?
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
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

   /*
    * Since SE_Reference_Vector_Type's values are all non-negative,
    * this will work nicely
    */
    for (vector_count = 0; vector_count <= SE_REFVEC_VERTICAL_AXIS;
         vector_count++)
    {
        vector_type_array[vector_count] = 0;
    }
    vector_count = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_union_of_geometry_hierarchy:SE_GetNextObject");
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

                case SE_CLS_DRM_REFERENCE_VECTOR:
                     check_reference_vector(level+1, path, next_object,
                         next_fields_ptr, context, summary);
                     if (SE_ValidReferenceVectorType
                         (next_fields_ptr->u.Reference_Vector.vector_type))
                     {
                         vector_type_array
                         [next_fields_ptr->u.Reference_Vector.vector_type]++;
                        /*
                         * only complain when the first duplicate is encountered
                         * rather than for all of them
                         */
                         if (vector_type_array
                             [next_fields_ptr->u.Reference_Vector.vector_type] == 2)
                         {
                             sprintf(err_msg,
                               "has multiple <Reference Vector> components "\
                               "for vector_type %s",
                               SE_PrintReferenceVectorType
                               (next_fields_ptr->u.Reference_Vector.vector_type));
                             se_message(object, path[level], level, path,
                                MSGTYP_ERROR, err_msg);
                         }
                     }
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE,
                             pass_down_classification_data);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                     }
                     else if (next_fields_ptr->tag != SE_CLS_DRM_CLASSIFICATION_DATA)
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
            ("check_union_of_geometry_hierarchy:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_union_of_geometry_hierarchy */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_alt_hier_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_alt_hier_related_geometry
(
          SE_Short_Integer_Unsigned   level,
          SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                                       object,
    const SE_Alternate_Hierarchy_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                               *context,
          SE_LOCAL_SUMMARY                               *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Element_Code_Queue       eac_val_queue;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         i=0;
    SE_Alternate_Hierarchy_Parameters link_fields;
    SE_FIELDS_PTR                     link_fields_ptr = NULL,
                                      next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus(
          "check_alt_hier_related_geometry:local_InitializeComponentIterator3");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
              &link_fields.hierarchy_data_count) != SE_RETCOD_SUCCESS) ||
             (link_fields.hierarchy_data_count < 1))
    {
        printLastFnctStatus(
          "check_alt_hier_related_geometry:SE_GetIterationLengthRemaining");
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
            ("check_alt_hier_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         SE_DRM_Class_Fields clone_fields;

                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) != SE_RETCOD_SUCCESS)
                         {
                             printLastFnctStatus
                             ("check_alt_hier_related_geometry:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_HIERARCHY_DATA, level+1,
                                path, MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         else if (SE_CloneFields(link_fields_ptr, &clone_fields) !=
                                  SE_DRM_STAT_CODE_SUCCESS)
                         {
                             se_message(link_object, SE_CLS_DRM_HIERARCHY_DATA, level+1,
                                path, MSGTYP_ERROR, "Can't clone fields of link object");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();

                             memcpy(&(link_fields.hierarchy_data_array[i]),
                                    &(clone_fields.u.Hierarchy_Data),
                                    sizeof(SE_Hierarchy_Data_Fields));
                             i++;
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            ("check_alt_hier_related_geometry:SE_GetFields");
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
} /* end check_alt_hier_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_classification_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_classification_related_geometry
(
          SE_Short_Integer_Unsigned   level,
          SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                   object,
    const SE_Classification_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                          *context,
          SE_LOCAL_SUMMARY                          *summary
)
{
    SE_Iterator                  iter = NULL;
    SE_Element_Code_Queue        eac_val_queue;
    SE_Object                    link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned          i=0;
    SE_FIELDS_PTR                link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_Classification_Parameters link_fields;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus(
          "check_classification_related_geometry:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &link_fields.classification_count) != SE_RETCOD_SUCCESS)
          || (link_fields.classification_count < 1))
    {
        printLastFnctStatus(
          "check_classification_related_geometry:SE_GetIterationLengthRemaining");
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
            ("check_classification_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                                          &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                             (SE_IsA[link_fields_ptr->tag]
                                    [SE_CLS_DRM_CLASSIFICATION_DATA]!=SE_TRUE))
                         {
                             printLastFnctStatus
                             ("check_classification_related_geometry:SE_GetFields");
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                               MSGTYP_ERROR, "can't get fields of corresponding <Classification Data>");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();
                             SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                             if (check_classification_data(level+1, path, link_object,
                                 link_fields_ptr, &(link_fields.classification_array[i]),
                                 summary) == SE_TRUE)
                             {
                                 i++;
                             }
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_TRUE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            ("check_classification_related_geometry:SE_GetFields");
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
} /* end check_classification_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_animation_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_animation_related_geometry
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
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Integer_Unsigned   gh_count = 0, max_b_frame = 0;

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
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus(
                 "check_animation_related_geometry:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_ANIMATION_BEHAVIOUR:
                     if (next_fields_ptr->u.Animation_Behaviour.ending_frame >
                         max_b_frame)
                     {
                         max_b_frame = next_fields_ptr->u.Animation_Behaviour.
                                       ending_frame;
                     }
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         gh_count++;
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);

    if (max_b_frame > gh_count)
    {
        char err_msg[256];

        sprintf(err_msg, "has <Animation Behaviour> with out-of-range "\
                "ending_frame %u (only %u frames)",
                (unsigned int)max_b_frame, (unsigned int)gh_count);
        se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
} /* end check_animation_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_continuous_lod_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_continuous_lod_related_geometry
(
          SE_Short_Integer_Unsigned                  level,
          SE_DRM_Class                               path
                                                     [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                  object,
    const SE_Continuous_LOD_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                          *context,
          SE_LOCAL_SUMMARY                          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_continuous_lod_related_geometry:SE_InitializeComponentIterator");
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
            printLastFnctStatus
            ("check_continuous_lod_related_geometry:SE_GetNex tObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path,
                             next_object, next_fields_ptr, context, summary);
                     }
                     else
                     {
                         check_attribute(level+1, path,
                             next_object, next_fields_ptr, context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus
            ("check_continuous_lod_related_geometry:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_continuous_lod_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_LODRG
 *
 *-----------------------------------------------------------------------------
 */
static void
check_LODRG
(
          SE_Short_Integer_Unsigned       level,
          SE_DRM_Class                    path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                       object,
    const SE_LOD_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT               *context,
          SE_LOCAL_SUMMARY               *summary
)
{
    SE_Iterator              iter = NULL;
    SE_Element_Code_Queue    eac_val_queue;
    SE_Object                link_object = NULL, next_object = NULL;
    SE_DRM_Class             expected_tag = SE_CLS_DRM_NULL;
    SE_Integer_Unsigned      i = 0;
    SE_FIELDS_PTR            next_fields_ptr = NULL, link_fields_ptr = NULL;
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
         "check_LODRG:GetIterationLengthRemaining");
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
            printLastFnctStatus("check_LODRG:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                                          &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                             (SE_IsA[link_fields_ptr->tag]
                              [SE_CLS_DRM_BASE_LOD_DATA] != SE_TRUE))
                         {
                             printLastFnctStatus("check_LODRG:SE_GetFields");
                             se_message(next_object, next_fields_ptr->tag, level+1, path,
                                MSGTYP_ERROR,
                                "can't get fields of corresponding <Base LOD Data>");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();
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
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
    link_fields.lod_entry_count = SE_BRRNGMAT_EXACT;

    if ((link_fields.lod_entry_count > 0) &&
        (SE_ValidLODSelectParameters(&link_fields, SE_FALSE, NULL)
         != SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
        SE_ValidLODSelectParameters(&link_fields, SE_TRUE, NULL);
    }
    SE_FreeLODSelectParameters(&link_fields, NULL);
} /* end check_LODRG */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_octant_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_octant_related_geometry
(
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                  object,
    const SE_Octant_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                  *context,
          SE_LOCAL_SUMMARY                  *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Element_Code_Queue       eac_val_queue;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         i=0;
    SE_Octant_Select_Parameters link_fields;
    SE_FIELDS_PTR               link_fields_ptr = NULL, next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &(link_fields.octant_data_count)) != SE_RETCOD_SUCCESS)
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
            printLastFnctStatus
            ("check_octant_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) == SE_RETCOD_SUCCESS)
                         {
                             SE_UpdateAnalysisCounts();
                             SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                             memcpy(&(link_fields.octant_data_array[i]),
                                    &(link_fields_ptr->u.Octant_Data),
                                    sizeof(SE_Octant_Data_Fields));
                             i++;
                         }
                         else
                         {
                             printLastFnctStatus
                             ("check_octant_related_geometry:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_OCTANT_DATA, level+1, path,
                                MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_TRUE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
                     {
                         check_topology_hierarchy(level+1, path,
                             next_object, next_fields_ptr, context, summary);
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
            ("check_octant_related_geometry:SE_GetFields");
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
           "has more than 8 Octants");
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
} /* end check_octant_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_perimeter_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_perimeter_related_geometry
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
            ("check_perimeter_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         SE_UpdateAnalysisCounts();

                         check_perimeter_data(level+1, path, link_object,
                             context, summary);
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            ("check_perimeter_related_geometry:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_perimeter_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_quadrant_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_quadrant_related_geometry
(
          SE_Short_Integer_Unsigned            level,
          SE_DRM_Class                         path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                            object,
    const SE_Quadrant_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                    *context,
          SE_LOCAL_SUMMARY                    *summary
)
{
    SE_Iterator                   iter = NULL;
    SE_Element_Code_Queue         eac_val_queue;
    SE_Object                     link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned           i=0;
    SE_Quadrant_Select_Parameters link_fields;
    SE_FIELDS_PTR                 link_fields_ptr = NULL, next_fields_ptr = NULL;

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
            ("check_quadrant_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) == SE_RETCOD_SUCCESS)
                         {
                             SE_UpdateAnalysisCounts();

                             memcpy(&(link_fields.quadrant_data_array[i]),
                                    &(link_fields_ptr->u.Quadrant_Data),
                                    sizeof(SE_Quadrant_Data_Fields));
                             i++;
                         }
                         else
                         {
                             printLastFnctStatus
                             ("check_quadrant_related_geometry:SE_GetFields");
                             se_message(link_object, SE_CLS_DRM_QUADRANT_DATA, level+1,
                                path, MSGTYP_ERROR, "Can't get fields of link object");
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_TRUE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            ("check_quadrant_related_geometry:SE_GetFields");
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
} /* end check_quadrant_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_separating_plane
 *
 *-----------------------------------------------------------------------------
 */
static void
check_separating_plane
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator               iter = NULL;
    SE_Remaining_Objects_List object_list;
    SE_FIELDS_PTR             next_fields_ptr = NULL;
    SE_Integer_Unsigned       i = 0;

    path[level] = fields_ptr->tag;

    if (SE_SimpleCreateComponentIterator(object, SE_CLS_DRM_LOCATION,
        SE_ITRBEH_RESOLVE, &iter) != SE_STATCODE_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    if (SE_GetRemainingObjectsList(iter, &object_list) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_separating_plane:SE_GetRemainingObjectsList");
        return;
    }
    SE_FreeIterator(iter);

    for (i = 0; i < object_list.object_count; i++)
    {
        SE_UpdateAnalysisCounts();

        if ((SE_GetFields(object_list.remaining_objects_list[i],
            GetGlobalStore(level), &next_fields_ptr) != SE_RETCOD_SUCCESS) ||
            !SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
        {
            se_message(object_list.remaining_objects_list[i], SE_CLS_DRM_NULL,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        else
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_location
            (
                level+1,
                path,
                object_list.remaining_objects_list[i],
                next_fields_ptr,
                NULL,
                context,
                summary
            );
        }
    }

   /*
    * If there are more or less than the required 3 <Locations>,
    * that's not rules_checker's business to report. We're
    * interested in checking that the object actually forms
    * a valid plane, given the working assumption that the
    * syntax check has already been performed elsewhere.
    */
    if (object_list.object_count == 3)
    {
        if (check_object_list_for_duplicate_locations(object_list.object_count,
            object_list.remaining_objects_list, &i) == SE_TRUE)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "not a valid plane -- two or more <Location> components"\
               " have the same coordinates");
            se_message(object_list.remaining_objects_list[i], SE_CLS_DRM_LOCATION,
               level+1, path, MSGTYP_WARNING, "first duplicate found");
        }
    }
    SE_FreeRemainingObjectsList(&object_list);
} /* end check_separating_plane */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_separating_plane_relations
 *
 *-----------------------------------------------------------------------------
 */
static void
check_separating_plane_relations
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL, link_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL, link_fields_ptr = NULL;
    SE_Integer_Unsigned false_count = 0, i=0, link_object_count = 0,
                        true_count = 0;

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
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
            ("check_separating_plane_relations:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag == SE_CLS_DRM_SEPARATING_PLANE)
            {
                check_separating_plane(level+1, path, next_object,
                    next_fields_ptr, context, summary);
            }
            else /* SE_CLS_DRM_GEOMETRY_HIERARCHY */
            {
                if (SE_GetFields(link_object, GetGlobalTempStore(level),
                    &link_fields_ptr) == SE_RETCOD_SUCCESS)
                {
                    SE_UpdateAnalysisCounts();
                    SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                    link_object_count++;
                    if (link_fields_ptr->u.Separating_Plane_Data.positive ==
                        SE_TRUE)
                    {
                        true_count++;
                    }
                    else
                    {
                        false_count++;
                    }
                }
                else
                {
                    se_message(link_object, SE_CLS_DRM_SEPARATING_PLANE_DATA,
                       level+1, path, MSGTYP_ERROR,
                       "Can't get fields of link object");
                }
                /* No link data */
                check_geometry_hierarchy(level+1, path, next_object,
                    next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
            }
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "can't get fields");
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (true_count > 1 || false_count > 1)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>>");
    }
} /* end check_separating_plane_relations */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_SPRG
 *
 *-----------------------------------------------------------------------------
 */
static void
check_SPRG
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
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
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_SPRG:SE_GetNextObject");
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

                case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
                     check_separating_plane_relations(level+1, path,
                         next_object, next_fields_ptr, context, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag]
                               [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            printLastFnctStatus("check_SPRG:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_SPRG */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_index_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_spatial_index_related_geometry
(
          SE_Short_Integer_Unsigned   level,
          SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                   object,
    const SE_Spatial_Index_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                         *context,
          SE_LOCAL_SUMMARY                         *summary
)
{
    SE_Iterator                 iter = NULL;
    SE_Element_Code_Queue       eac_val_queue;
    SE_Object                   link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned         cell_count = 0, i=0;
    SE_Spatial_Index_Parameters link_fields;
    char                        err_msg[256];
    SE_FIELDS_PTR               link_fields_ptr = NULL, next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &link_fields.spatial_index_data_count)!=SE_RETCOD_SUCCESS)
          || (link_fields.spatial_index_data_count < 1))
    {
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
        if (SE_GetNextObject(iter, &next_object,  &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_spatial_index_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if (SE_GetFields(link_object, GetGlobalTempStore(level),
                             &link_fields_ptr) != SE_RETCOD_SUCCESS)
                         {
                             se_message(link_object, SE_CLS_DRM_SPATIAL_INDEX_DATA,
                                level+1, path, MSGTYP_ERROR, "Can't get fields");
                         }
                         else
                         {
                             SE_UpdateAnalysisCounts();

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
                                 se_message(link_object,
                                    SE_CLS_DRM_SPATIAL_INDEX_DATA,
                                    level+1, path, MSGTYP_ERROR, err_msg);
                             }
                             memcpy(&(link_fields.spatial_index_data_array[i]),
                                    &(link_fields_ptr->u.Spatial_Index_Data),
                                    sizeof(SE_Spatial_Index_Data_Fields));
                             i++;
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
                 "check_spatial_index_related_geometry:SE_GetFields");
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
            se_message(object, path[level], level, path, MSGTYP_ERROR,
                     "sparse==SE_FALSE but some entries are missing");
    }
    else if (i == cell_count)
    {
        if (fields_ptr->sparse)
            se_message(object, path[level], level, path, MSGTYP_ERROR,
                     "sparse==SE_TRUE but all entries are present");
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
} /* end check_spatial_index_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_state_related_geometry
 *
 *   Checks <<State Related Organizing Principle>> constraint.
 *
 *-----------------------------------------------------------------------------
 */
static void
check_state_related_geometry
(
          SE_Short_Integer_Unsigned         level,
          SE_DRM_Class                      path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                         object,
    const SE_State_Related_Geometry_Fields *fields_ptr,
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
    else if ((link_fields.state_entry_array = (SE_State_Entry *)
            calloc(link_fields.state_entry_count, sizeof(SE_State_Entry)))
            == NULL)
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
            ("check_state_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                              &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                             (SE_IsA[link_fields_ptr->tag][SE_CLS_DRM_STATE_DATA]!=SE_TRUE))
                         {
                             se_message(link_object, SE_CLS_DRM_STATE_DATA, level+1, path,
                                MSGTYP_ERROR, "can't get fields or is not <State Data>");
                         }
                         else if (check_state_data(level, path,
                                  fields_ptr->state_tag,
                                  fields_ptr->active_state_value.attribute_value_type,
                                  link_object, link_fields_ptr,
                                  &link_fields.state_entry_array[i]) == SE_TRUE)
                         {
                             i++;
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
    link_fields.matching_rules = SE_BRRNGMAT_FULL_CONTAINMENT;
    link_fields.state_entry_count = i;

    if ((link_fields.state_entry_count > 0) &&
        (SE_ValidStateSelectParameters(&link_fields, SE_FALSE, NULL)!=SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "branches violate <<Distinct Link Objects>> or "\
           "<<State Related Organizing Principle>>");
        SE_ValidStateSelectParameters(&link_fields, SE_TRUE, NULL);
    }
    free(link_fields.state_entry_array);
} /* end check_state_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_time_related_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_time_related_geometry
(
          SE_Short_Integer_Unsigned        level,
          SE_DRM_Class                     path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                        object,
    const SE_Time_Related_Geometry_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                *context,
          SE_LOCAL_SUMMARY                *summary
)
{
    SE_Iterator               iter = NULL;
    SE_Element_Code_Queue     eac_val_queue;
    SE_Object                 link_object = NULL, next_object = NULL;
    SE_DRM_Class              expected_tag = SE_CLS_DRM_NULL;
    SE_Integer_Unsigned       i = 0;
    SE_FIELDS_PTR             next_fields_ptr;
    SE_Time_Select_Parameters link_fields;

    if (local_InitializeComponentIterator3(object, search_filter,
          &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &(link_fields.time_entry_count))!=SE_RETCOD_SUCCESS)
          || (link_fields.time_entry_count < 1))
    {
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
            ("check_time_related_geometry:SE_GetNextObject");
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
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_GEOMETRY_HIERARCHY])
                     {
                         if (link_object)
                         {
                             SE_UpdateAnalysisCounts();

                             check_time_constraints_data(level+1, path,
                                 link_object, expected_tag, summary);
                         }
                         check_geometry_hierarchy(level+1, path, next_object,
                             next_fields_ptr, context, summary, SE_FALSE, SE_FALSE);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            ("check_time_related_geometry:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "can't get fields");
        }

        if (link_object)
            SE_FreeObject(link_object);
        SE_FreeObject(next_object);

    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
    link_fields.time_entry_count = i;
    link_fields.matching_rules = SE_BRRNGMAT_INTERSECTION;

   /*
    * $$$ needs to also check for contained times (though not overlapping)
    * $$$ times as an illegal case, not just identical matches
    */
    if ((link_fields.time_entry_count > 0) &&
        (SE_ValidTimeSelectParameters(&link_fields, SE_FALSE, NULL)
         != SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "branches violate <<Distinct Link Objects>>");
        SE_ValidTimeSelectParameters(&link_fields, SE_TRUE, NULL);
    }
    SE_FreeTimeSelectParameters(&link_fields, NULL);
} /* end check_time_related_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_gmi
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
check_gmi
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
                 "<Geometry Model Instance>");
            SE_FreeIterator(iter);
            return;
        }
        else
        {
            memset(indx_list, 0, sizeof(SE_Integer_Unsigned)*expr_count);
        }
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;
    expr_count     = 0;

   /*
    * $$$ handle <Spatial Extent> before handling <Stamp Behaviour>
    */
    /* <Stamp Behaviour> */
    if (SE_GetComponent(object, SE_CLS_DRM_STAMP_BEHAVIOUR,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
        &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        check_stamp_behaviour(level+1, path, next_object, context, summary);

        SE_FreeObject(next_object);
        next_object = NULL;
    }

   /*
    * now for the rest of the components
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_gmi:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_EXPRESSION])
            {
                if ((SE_GetFields(link_object, GetGlobalTempStore(level),
                     &link_fields_ptr) != SE_RETCOD_SUCCESS) ||
                    !SE_IsA[link_fields_ptr->tag]
                       [SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX])
                {
                    printLastFnctStatus("check_gmi:SE_GetFields");
                    se_message(link_object,
                       SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX,
                       level+1, path, MSGTYP_ERROR, "can't get fields");
                }
                else
                {
                    SE_Boolean found_pos = SE_FALSE;

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
                check_expression(level+1, path,
                    next_object, next_fields_ptr,
                    (context->has_variables ? &(context->interface_template)
                                        : NULL), summary);
            }
            else if (next_fields_ptr->tag==SE_CLS_DRM_PROPERTY_VALUE)
            {
                check_property_value(level+1, path, next_object,
                    next_fields_ptr, &eac_val_queue, summary);
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    context, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_gmi:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
        if (link_object)
            SE_FreeObject(link_object);

    }
    SE_FreeIterator(iter);

    if (indx_list != NULL)
    {
       /*
        * If the first entry in the template index list is greater than
        * 1, then all the <Variables> that would be indexed between 1
        * and indx_list[0] have not been provided with values by this
        * <Geometry Model Instance>.
        */
        if (indx_list[0] > 1)
        {
            sprintf(err_msg, "<Geometry Model Instance> has no <Expressions>"\
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
                sprintf(err_msg, "<Geometry Model Instance> has no "\
                        "<Expression>s for template indices %u through %u",
                        (unsigned int)(indx_list[j-1]+1),
                        (unsigned int)(indx_list[j]-1));
                se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
            }
        }
        free(indx_list);
    }
    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_gmi */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_aggregate_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_aggregate_geometry
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
    SE_Object        next_object = NULL;
    SE_FIELDS_PTR    next_fields_ptr = NULL;
    SE_LOCAL_CONTEXT local_context;
    SE_Boolean       has_spatial_extent = SE_FALSE;

    path[level] = fields_ptr->tag;

   /*
    * SE_SpawnUpdatedLocalContext handles any <Property Description>s,
    * <Presentation Domain>, and/or <Spatial Extent>
    */
    SE_SpawnUpdatedLocalContext(level, path, object, context,
        &local_context, summary, &has_spatial_extent);

    if ((mandatory_spatial_extent == SE_TRUE) &&
        (has_spatial_extent != SE_TRUE))
    {
        printLastFnctStatus("check_aggregate_geometry:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Quadrant Related Organizing Principle>> or "\
           "<<Octant Related Organizing Principle>> "\
           "(no <Spatial Extent> component)");
    }

    /* <Stamp Behaviour> */
    if (SE_GetComponent(object, SE_CLS_DRM_STAMP_BEHAVIOUR,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
           &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        check_stamp_behaviour(level+1, path, next_object, &local_context,
            summary);

        SE_FreeObject(next_object);
        next_object = NULL;
    }

   /*
    * Processing for specific types of <Aggregate Geometry>
    */
    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
             check_alt_hier_related_geometry(level, path, object,
                &(fields_ptr->u.Alternate_Hierarchy_Related_Geometry),
                &local_context, summary);
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
             check_classification_related_geometry(level, path, object,
                 &(fields_ptr->u.Classification_Related_Geometry),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
             check_union_of_geometry_hierarchy(level, path, object,
                 &(fields_ptr->u.Union_Of_Geometry_Hierarchy),
                 &local_context, summary, inherits_classification_data);
             break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
             if (SE_ValidFields(fields_ptr, SE_TRUE, NULL))
             {
                 check_LODRG(level, path, object,
                    &(fields_ptr->u.LOD_Related_Geometry),
                    &local_context, summary);
             }
             else
             {
                 se_message(object, path[level], level, path,
                     MSGTYP_ERROR_SYNTAX, "skipping, invalid fields");
             }
             break;

        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
             if (!has_spatial_extent)
             {
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, "violates <<Octant Organizing Principle>> "\
                          "(no <Spatial Extent> component)");
             }
             check_octant_related_geometry(level, path, object,
                 &(fields_ptr->u.Octant_Related_Geometry),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
             check_perimeter_related_geometry(level, path, object,
                 &local_context, summary);
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
             if (!has_spatial_extent)
             {
                se_message(object, path[level], level, path,
                   MSGTYP_ERROR, "violates <<Quadrant Organizing Principle>> "\
                         "(no <Spatial Extent> component)");
             }
             check_quadrant_related_geometry(level, path, object,
                 &(fields_ptr->u.Quadrant_Related_Geometry),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
             local_CheckSpatialIndexUnit
             (level, path, object, fields_ptr, &(local_context.srf_context_info));

             check_spatial_index_related_geometry(level, path, object,
                 &(fields_ptr->u.Spatial_Index_Related_Geometry),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             check_state_related_geometry(level, path, object,
                 &(fields_ptr->u.State_Related_Geometry),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
             check_time_related_geometry(level, path, object,
                 &(fields_ptr->u.Time_Related_Geometry),
                 &local_context, summary);
             break;

        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
             check_union_of_primitive_geometry(level, path, object,
                 fields_ptr, &local_context, summary,
                 inherits_classification_data);
             break;

        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
             check_animation_related_geometry(level, path, object,
                 &local_context, summary);
             break;

        case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
             if (path[1] != SE_CLS_DRM_ENVIRONMENT_ROOT)
             {
                se_message(object, path[level], level, path,
                    MSGTYP_ERROR, "violates <<Continuous LOD Restrictions>>");
             }
             check_continuous_lod_related_geometry(level, path, object,
               &(fields_ptr->u.Continuous_LOD_Related_Geometry),
               &local_context, summary);
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
             check_SPRG(level, path, object, fields_ptr,
                 &local_context, summary);
             break;

        default:
             se_message(object, path[level], level, path, MSGTYP_ERROR,
                      "$$$ unrecognized <Aggregate Geometry> subclass");
             break;
    }
   /*
    * do *not* free local_context
    */
} /* end check_aggregate_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_geometry_hierarchy
 *
 *-----------------------------------------------------------------------------
 */
void
check_geometry_hierarchy
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
    path[level] = fields_ptr->tag;

   /*
    * Processing for specific types of <Geometry Hierarchy>
    */
    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
             check_gmi(level, path, object, context, summary,
                 mandatory_spatial_extent);
             break;

        case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
             summary->data_tables_present = SE_TRUE;
             check_PGHP(level, path, object, fields_ptr, context, summary,
                 mandatory_spatial_extent);
             break;

        default:
             check_aggregate_geometry(level, path, object, fields_ptr,
                 context, summary, mandatory_spatial_extent,
                 inherits_classification_data);
             break;
    }
} /* end check_geometry_hierarchy */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_vertex
 *
 * location - mandatory OUT parameter, clone of object's <Location> component;
 *   set to NULL if the <Location> component doesn't pass its own check
 *
 *-----------------------------------------------------------------------------
 */
static void
check_vertex
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Object                 *location,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned tc_count = 0, vector_count = 0,
                        vector_type_array[SE_REFVEC_VERTICAL_AXIS+1];
    char                err_msg[256];

    path[level] = fields_ptr->tag;

    *location = NULL;
    if (local_InitializeComponentIterator3(object, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
       se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize component iter");
        return;
    }

   /*
    * Since SE_Reference_Vector_Type's values are all non-negative,
    * this will work nicely
    */
    for (vector_count = 0; vector_count <= SE_REFVEC_VERTICAL_AXIS;
         vector_count++)
    {
        vector_type_array[vector_count] = 0;
    }
    vector_count = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_vertex:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_REFERENCE_VECTOR:
                {
                    check_reference_vector(level+1, path, next_object,
                        next_fields_ptr, context, summary);
                    if (SE_ValidReferenceVectorType
                        (next_fields_ptr->u.Reference_Vector.vector_type))
                    {
                        vector_type_array
                        [next_fields_ptr->u.Reference_Vector.vector_type]++;
                       /*
                        * only complain when the first duplicate is encountered
                        * rather than for all of them
                        */
                        if (vector_type_array
                            [next_fields_ptr->u.Reference_Vector.vector_type] == 2)
                        {
                            sprintf(err_msg,
                              "has multiple <Reference Vector> components "\
                              "for vector_type %s",
                              SE_PrintReferenceVectorType
                              (next_fields_ptr->u.Reference_Vector.vector_type));
                            se_message(object, path[level], level, path, MSGTYP_ERROR,
                               err_msg);
                        }
                    }
                    break;
                }
                case SE_CLS_DRM_TEXTURE_COORDINATE:
                {
                    tc_count++;
                    check_texture_coordinate(level+1, path, next_object,
                        context, summary);
                    break;
                }
                default:
                    if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                    {
                        if (check_location(level+1, path, next_object, next_fields_ptr,
                            NULL, context, summary) == SE_TRUE)
                        {
                            if (SE_CloneObjectHandle(next_object, location) != SE_RETCOD_SUCCESS)
                            {
                                printLastFnctStatus("check_vertex:SE_CloneObjectHandle");
                                location = NULL;
                            }
                        }
                    }
                    else
                    {
                        check_attribute(level+1, path, next_object,
                            next_fields_ptr, context, summary);
                    }
                    break;
            } /* end switch */
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if ((context->has_unresolved_psi != SE_TRUE) &&
        (context->expected_texture_coordinate_count != tc_count))
    {
        char err_msg[256];

        sprintf(err_msg, "violates "\
           "<<Image Mapping Functions and Texture Coordinates>> constraint "\
           "(%u IMF != %u TC)",
           (unsigned int)context->expected_texture_coordinate_count,
           (unsigned int)tc_count);
        se_message(object, fields_ptr->tag, level, path,
           MSGTYP_ERROR, err_msg);
    }
} /* end check_vertex */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_ellipse
 *
 *-----------------------------------------------------------------------------
 */
static void
check_ellipse
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  ellipse,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(ellipse, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
       se_message(ellipse, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize component iter");
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_ellipse:SE_GetNextObject");
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

                case SE_CLS_DRM_REFERENCE_VECTOR:
                     check_reference_vector(level+1, path, next_object,
                         next_fields_ptr, context, summary);
                     break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                     /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                        next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     else
                     {
                         check_attribute(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                     }
                     break;
            }
        }
        else
        {
            printLastFnctStatus("check_ellipse:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_ellipse */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_finite_element_mesh
 *
 *-----------------------------------------------------------------------------
 */
static void
check_finite_element_mesh
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  finite_element_mesh,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator            iter = NULL;
    SE_Element_Code_Queue  eac_val_queue;
    SE_Object              next_object = NULL;
    SE_FIELDS_PTR          next_fields_ptr = NULL;
    SE_Object             *loc_array = NULL;
    SE_Integer_Unsigned    loc_array_count = 0, i = 0;

    if (local_InitializeComponentIterator3(finite_element_mesh, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
       se_message(finite_element_mesh, path[level], level, path,
          MSGTYP_ERROR, "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &loc_array_count)!=SE_RETCOD_SUCCESS)
          || (loc_array_count < 1))
    {
        se_message(finite_element_mesh, path[level], level, path,
           MSGTYP_ERROR, "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((loc_array = (SE_Object *)
             calloc(loc_array_count, sizeof(SE_Object))) == NULL)
    {
        se_message(finite_element_mesh, path[level], level, path,
           MSGTYP_ERROR, "can't calloc loc_array");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;
    loc_array_count = 0; /* now will set to actual <Location> count */

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_finite_element_mesh:SE_GetNextObject");
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

                case SE_CLS_DRM_VERTEX:
                     check_vertex(level+1, path,
                         next_object, next_fields_ptr, &(loc_array[loc_array_count]),
                         context, summary);
                     if (loc_array[loc_array_count] != NULL)
                         loc_array_count++;
                     break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                     /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                         next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                 default:
                      check_attribute(level+1, path,
                          next_object, next_fields_ptr, context, summary);
                      break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_finite_element_mesh:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    if (check_object_list_for_duplicate_locations(loc_array_count,
        loc_array, &i) == SE_TRUE)
    {
        se_message(finite_element_mesh, path[level], level, path,
           MSGTYP_ERROR, "violates <<Finite Element Mesh Structure>>");
        path[level+1] = SE_CLS_DRM_VERTEX;
        se_message(loc_array[i], SE_CLS_DRM_LOCATION, level+2,
                  path, MSGTYP_WARNING, "first duplicate found");
    }
    while (loc_array_count > 0)
    {
        SE_FreeObject(loc_array[loc_array_count-1]);
        loc_array_count--;
    }
    free(loc_array);
    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_finite_element_mesh */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_linear_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_linear_geometry
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  linear_geometry,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator            iter = NULL;
    SE_Element_Code_Queue  eac_val_queue;
    SE_Object              next_object = NULL;
    SE_FIELDS_PTR          next_fields_ptr = NULL;
    SE_LOCAL_CONTEXT       local_context;
    SE_Boolean             has_spatial_extent = SE_FALSE;
    SE_Object             *loc_array = NULL;
    SE_Integer_Unsigned    i = 0, loc_array_count = 0, vector_count = 0,
                           vector_type_array[SE_REFVEC_VERTICAL_AXIS+1];
    char                   err_msg[256];

    path[level] = fields_ptr->tag;

    SE_SpawnUpdatedLocalContext(level, path, linear_geometry, context,
        &local_context, summary, &has_spatial_extent);

    if (local_InitializeComponentIterator3(linear_geometry, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
       se_message(linear_geometry, path[level], level, path,
          MSGTYP_ERROR, "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &loc_array_count)!=SE_RETCOD_SUCCESS)
          || (loc_array_count < 1))
    {
        se_message(linear_geometry, path[level], level, path,
           MSGTYP_ERROR, "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((loc_array = (SE_Object *)
             calloc(loc_array_count, sizeof(SE_Object))) == NULL)
    {
        se_message(linear_geometry, path[level], level, path,
           MSGTYP_ERROR, "can't calloc loc_array");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * Since SE_Reference_Vector_Type's values are all non-negative,
    * this will work nicely
    */
    for (vector_count = 0; vector_count <= SE_REFVEC_VERTICAL_AXIS;
         vector_count++)
    {
        vector_type_array[vector_count] = 0;
    }
    vector_count = 0;

    loc_array_count = 0; /* now will set to actual <Location> count */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_linear_geometry:SE_GetNextObject");
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

                case SE_CLS_DRM_REFERENCE_VECTOR:
                     check_reference_vector(level+1, path, next_object,
                         next_fields_ptr, context, summary);
                     if (SE_ValidReferenceVectorType
                         (next_fields_ptr->u.Reference_Vector.vector_type))
                     {
                         vector_type_array
                         [next_fields_ptr->u.Reference_Vector.vector_type]++;
                        /*
                         * only complain when the first duplicate is encountered
                         * rather than for all of them
                         */
                         if (vector_type_array
                             [next_fields_ptr->u.Reference_Vector.vector_type] == 2)
                         {
                             sprintf(err_msg,
                               "has multiple <Reference Vector> components "\
                               "for vector_type %s",
                               SE_PrintReferenceVectorType
                               (next_fields_ptr->u.Reference_Vector.vector_type));
                             se_message(linear_geometry, path[level], level, path,
                                MSGTYP_ERROR, err_msg);
                         }
                     }
                     break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                     /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                         next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                case SE_CLS_DRM_VERTEX:
                     check_vertex(level+1, path,
                         next_object, next_fields_ptr, &(loc_array[loc_array_count]),
                         context, summary);
                     if (loc_array[loc_array_count] != NULL)
                         loc_array_count++;
                     break;

                default:
                     check_attribute(level+1, path,
                         next_object, next_fields_ptr, context, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_linear_geometry:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if (check_object_list_for_duplicate_locations(loc_array_count,
        loc_array, &i) == SE_TRUE)
    {
        se_message(linear_geometry, path[level], level, path,
           MSGTYP_ERROR, "violates <<Linear Geometry Structure>>");
        path[level+1] = SE_CLS_DRM_VERTEX;
        se_message(loc_array[i], SE_CLS_DRM_LOCATION, level+2,
                   path, MSGTYP_WARNING, "first duplicate found");
    }
    while (loc_array_count > 0)
    {
        SE_FreeObject(loc_array[loc_array_count-1]);
        loc_array_count--;
    }
    free(loc_array);

   /*
    * do *not* free local_context
    */
} /* end check_linear_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_point
 *
 *-----------------------------------------------------------------------------
 */
static void
check_point
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  point,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Integer_Unsigned   tc_count = 0, vector_count = 0,
                          vector_type_array[SE_REFVEC_VERTICAL_AXIS+1];
    char                  err_msg[256];

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(point, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
       se_message(point, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize component iter");
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * Since SE_Reference_Vector_Type's values are all non-negative,
    * this will work nicely
    */
    for (vector_count = 0; vector_count <= SE_REFVEC_VERTICAL_AXIS;
         vector_count++)
    {
        vector_type_array[vector_count] = 0;
    }
    vector_count = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_point:SE_GetNextObject");
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

                case SE_CLS_DRM_REFERENCE_VECTOR:
                    check_reference_vector(level+1, path, next_object,
                        next_fields_ptr, context, summary);
                    if (SE_ValidReferenceVectorType
                        (next_fields_ptr->u.Reference_Vector.vector_type))
                    {
                        vector_type_array
                        [next_fields_ptr->u.Reference_Vector.vector_type]++;
                       /*
                        * only complain when the first duplicate is encountered
                        * rather than for all of them
                        */
                        if (vector_type_array
                            [next_fields_ptr->u.Reference_Vector.vector_type] == 2)
                        {
                            sprintf(err_msg,
                              "has multiple <Reference Vector> components "\
                              "for vector_type %s",
                              SE_PrintReferenceVectorType
                              (next_fields_ptr->u.Reference_Vector.vector_type));
                            se_message(point, path[level], level, path, MSGTYP_ERROR,
                               err_msg);
                        }
                    }
                    break;

                case SE_CLS_DRM_TEXTURE_COORDINATE:
                     tc_count++;
                     check_texture_coordinate(level+1, path, next_object,
                         context, summary);
                     break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                     /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                         next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     else
                     {
                         check_attribute(level+1, path,
                             next_object, next_fields_ptr, context, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_point:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);

    if ((context->has_unresolved_psi != SE_TRUE) &&
        (context->expected_texture_coordinate_count != tc_count))
    {
        se_message(point, fields_ptr->tag, level, path,
           MSGTYP_ERROR, "violates "\
           "<<Image Mapping Functions and Texture Coordinates>> constraint");
    }
} /* end check_point */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_polyhedron
 *
 *-----------------------------------------------------------------------------
 */
static void
check_polyhedron
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  polyhedron,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;

   /*
    * $$$ need to check associated <Geometry Volume> against
    * $$$ the <Polygon> components' <Geometry Face> associates
    */
    if (local_InitializeComponentIterator3(polyhedron, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
       se_message(polyhedron, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize component iter");
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_polyhedron:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_POLYGON:
                     check_primitive_geometry(level+1, path, next_object,
                         next_fields_ptr, context, summary);
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                    /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                        next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                default:
                     check_attribute(level+1, path,
                         next_object, next_fields_ptr, context, summary);
                     break;

            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_polyhedron:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_polyhedron */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_polygon
 *
 *-----------------------------------------------------------------------------
 */
static void
check_polygon
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  polygon,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator            iter = NULL;
    SE_Element_Code_Queue  eac_val_queue;
    SE_Object              next_object = NULL;
    SE_FIELDS_PTR          next_fields_ptr = NULL;
    SE_Object             *loc_array = NULL;
    SE_Integer_Unsigned    loc_array_count = 0, i = 0;
    SE_Integer_Unsigned    vector_count = 0,
                           vector_type_array[SE_REFVEC_VERTICAL_AXIS+1];
    char                   err_msg[256];

    if (local_InitializeComponentIterator3(polygon, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
       se_message(polygon, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
             &loc_array_count)!=SE_RETCOD_SUCCESS)
          || (loc_array_count < 1))
    {
        se_message(polygon, path[level], level, path, MSGTYP_ERROR,
                 "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((loc_array = (SE_Object *)
             calloc(loc_array_count, sizeof(SE_Object))) == NULL)
    {
        se_message(polygon, path[level], level, path, MSGTYP_ERROR,
                 "can't calloc loc_array");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

   /*
    * Since SE_Reference_Vector_Type's values are all non-negative,
    * this will work nicely
    */
    for (vector_count = 0; vector_count <= SE_REFVEC_VERTICAL_AXIS;
         vector_count++)
    {
        vector_type_array[vector_count] = 0;
    }
    vector_count = 0;

    loc_array_count = 0; /* now will set to actual <Location> count */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_polygon:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_POLYGON_CONTROL_LINK:
                     check_control_link(level+1, path,
                        next_object, next_fields_ptr,
                        (context->has_variables ? &(context->interface_template)
                                        : NULL), summary);
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;

                case SE_CLS_DRM_REFERENCE_VECTOR:
                    check_reference_vector(level+1, path, next_object,
                        next_fields_ptr, context, summary);
                    if (SE_ValidReferenceVectorType
                        (next_fields_ptr->u.Reference_Vector.vector_type))
                    {
                        vector_type_array
                        [next_fields_ptr->u.Reference_Vector.vector_type]++;
                       /*
                        * only complain when the first duplicate is encountered
                        * rather than for all of them
                        */
                        if (vector_type_array
                            [next_fields_ptr->u.Reference_Vector.vector_type] == 2)
                        {
                            sprintf(err_msg,
                              "has multiple <Reference Vector> components "\
                              "for vector_type %s",
                              SE_PrintReferenceVectorType
                              (next_fields_ptr->u.Reference_Vector.vector_type));
                            se_message(polygon, path[level], level, path, MSGTYP_ERROR,
                               err_msg);
                        }
                    }
                    break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                            MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                     /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                         next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                case SE_CLS_DRM_VERTEX:
                     check_vertex(level+1, path,
                         next_object, next_fields_ptr, &(loc_array[loc_array_count]),
                         context, summary);
                     if (loc_array[loc_array_count] != NULL)
                         loc_array_count++;
                     break;

                default:
                     check_attribute(level+1, path,
                        next_object, next_fields_ptr, context, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_polygon:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_val_queue);

    if (check_object_list_for_duplicate_locations(loc_array_count,
        loc_array, &i) == SE_TRUE)
    {
        se_message(polygon, path[level], level, path, MSGTYP_ERROR,
                 "violates <<Polygon As Bounded Plane>>");
        path[level+1] = SE_CLS_DRM_VERTEX;
        se_message(loc_array[i], SE_CLS_DRM_LOCATION, level+2,
           path, MSGTYP_WARNING, "first duplicate found");
    }
    while (loc_array_count > 0)
    {
        SE_FreeObject(loc_array[loc_array_count-1]);
        loc_array_count--;
    }
    free(loc_array);
} /* end check_polygon */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_volume_object
 *
 *-----------------------------------------------------------------------------
 */
static void
check_volume_object
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  volume_object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(volume_object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
       se_message(volume_object, path[level], level, path, MSGTYP_ERROR,
          "can't initialize component iter");
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_volume_object:SE_GetNextObject");
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
                     check_property_value(level+1, path, next_object, next_fields_ptr,
                         &eac_val_queue, summary);
                     break;

                case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
                     if (path[level-2] == SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY)
                     {
                         se_message(next_object, next_fields_ptr->tag, level+1, path,
                             MSGTYP_ERROR, "violates <<Continuous LOD Constraints>>, part (b)");
                     }
                     /* $$$ need additional check for planar rule */
                     check_union_of_primitive_geometry(level+1, path,
                         next_object, next_fields_ptr, context, summary, SE_FALSE);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION_3D])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_VOLUME_EXTENT])
                     {
                         SE_Volume_Extent_Entry volume_extent_entry;

                         check_volume_extent(level+1, path, next_object, context, summary,
                             &volume_extent_entry);
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
            printLastFnctStatus("check_volume_object:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_volume_object */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_primitive_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_primitive_geometry
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  primitive_geometry,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_LOCAL_CONTEXT local_context;

    path[level] = fields_ptr->tag;

   /*
    * Impossible for a <Primitive Geometry> instance to have a
    * <Spatial Extent> component, so pass NULL for that pointer
    */
    SE_SpawnUpdatedLocalContext(level, path, primitive_geometry, context,
        &local_context, summary, NULL);

   /*
    * Processing for specific types of <Primitive Geometry>
    *
    * For each applicable subclass, check <<Nested Primitive Geometry>>
    */
    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_ELLIPSE:
        {
            if ((level > 1) &&
                (SE_IsA[path[level-2]][SE_CLS_DRM_LINEAR_GEOMETRY]
              || (path[level-2] == SE_CLS_DRM_POINT)))
            {
                se_message(primitive_geometry, path[level], level, path,
                    MSGTYP_ERROR, "violates <<Nested Primitive Geometry>>");
            }
            check_ellipse(level, path, primitive_geometry, fields_ptr,
                &local_context, summary);
        }
        break;

        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        {
            if ((level > 1) &&
                (SE_IsA[path[level-2]][SE_CLS_DRM_LINEAR_GEOMETRY]
              || (path[level-2] == SE_CLS_DRM_POINT)))
            {
                se_message(primitive_geometry, path[level], level, path,
                   MSGTYP_ERROR, "violates <<Nested Primitive Geometry>>");
            }
            check_finite_element_mesh(level, path, primitive_geometry,
                fields_ptr, &local_context, summary);
        }
        break;

        case SE_CLS_DRM_LINEAR_GEOMETRY:
        case SE_CLS_DRM_ARC:
        case SE_CLS_DRM_LINE:
        {
            if ((level > 1) &&
                (path[level-2] == SE_CLS_DRM_POINT))
            {
                se_message(primitive_geometry, path[level], level, path,
                   MSGTYP_ERROR, "violates <<Nested Primitive Geometry>>");
            }
            check_linear_geometry(level, path, primitive_geometry,
                fields_ptr, &local_context, summary);
        }
        break;

        case SE_CLS_DRM_POINT:
        {
            check_point(level, path, primitive_geometry, fields_ptr,
                &local_context, summary);
        }
        break;

        case SE_CLS_DRM_POLYGON:
        {
            if ((level > 1) &&
                (SE_IsA[path[level-2]][SE_CLS_DRM_LINEAR_GEOMETRY]
              || (path[level-2] == SE_CLS_DRM_POINT)))
            {
                se_message(primitive_geometry, path[level], level, path,
                   MSGTYP_ERROR, "violates <<Nested Primitive Geometry>>");
            }
            check_polygon(level, path, primitive_geometry, fields_ptr,
                &local_context, summary);
        }
        break;

        case SE_CLS_DRM_POLYHEDRON:
        {
            if ((level > 1) &&
                (SE_IsA[path[level-2]][SE_CLS_DRM_LINEAR_GEOMETRY]
              || SE_IsA[path[level-2]][SE_CLS_DRM_SURFACE_GEOMETRY]
              || (path[level-2] == SE_CLS_DRM_POINT)))
            {
                se_message(primitive_geometry, path[level], level, path,
                   MSGTYP_ERROR, "violates <<Nested Primitive Geometry>>");
            }
            check_polyhedron(level, path, primitive_geometry, fields_ptr,
                &local_context, summary);
        }
        break;

        case SE_CLS_DRM_VOLUME_OBJECT:
        {
            if ((level > 1) &&
                (SE_IsA[path[level-2]][SE_CLS_DRM_LINEAR_GEOMETRY]
              || SE_IsA[path[level-2]][SE_CLS_DRM_SURFACE_GEOMETRY]
              || (path[level-2] == SE_CLS_DRM_POINT)))
            {
                se_message(primitive_geometry, path[level], level, path,
                   MSGTYP_ERROR, "violates <<Nested Primitive Geometry>>");
            }
            check_volume_object(level, path, primitive_geometry, fields_ptr,
                &local_context, summary);
        }
        break;

        default:
             se_message(primitive_geometry, path[level], level, path,
                MSGTYP_ERROR, "$$$ unrecognized <Primitive Geometry> subclass");
        break;
    } /* end switch */
   /*
    * do *not* free local_context - the only pointers it would have
    * updated are shared and are supposed to be shared with context
    */
} /* check_primitive_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_union_of_primitive_geometry
 *
 *-----------------------------------------------------------------------------
 */
static void
check_union_of_primitive_geometry
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
    SE_Boolean            direct_classification_data = SE_FALSE;
    SE_Integer_Unsigned   vector_count = 0,
                          vector_type_array[SE_REFVEC_VERTICAL_AXIS+1];
    char                  err_msg[256];

    path[level] = fields_ptr->tag;

   /*
    * since no <Union Of Geometry> instance can be a direct component
    * of a <Union Of Primitive Geometry> instance, we don't have to
    * check the next level's union_reason
    */
    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
       printLastFnctStatus
       ("check_union_of_primitive_geometry:SE_InitializeComponentIterator");
       se_message(object, path[level], level, path, MSGTYP_ERROR,
          "can't initialize component iter");
        return;
    }
    eac_val_queue.head  = NULL;
    eac_val_queue.tail  = NULL;

   /*
    * Since SE_Reference_Vector_Type's values are all non-negative,
    * this will work nicely
    */
    for (vector_count = 0; vector_count <= SE_REFVEC_VERTICAL_AXIS;
         vector_count++)
    {
        vector_type_array[vector_count] = 0;
    }
    vector_count = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_union_of_primitive_geometry:SE_GetNextObject");
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

                case SE_CLS_DRM_CLASSIFICATION_DATA:
                {
                     SE_Classification_Entry entry;

                     check_classification_data
                     (level+1, path, next_object, next_fields_ptr, &entry, summary);

                     SE_FreeClassificationEntry(&entry, NULL);
                     direct_classification_data = SE_TRUE;
                }
                     break;

                case SE_CLS_DRM_REFERENCE_VECTOR:
                     check_reference_vector(level+1, path, next_object,
                         next_fields_ptr, context, summary);
                     if (SE_ValidReferenceVectorType
                         (next_fields_ptr->u.Reference_Vector.vector_type))
                     {
                         vector_type_array
                         [next_fields_ptr->u.Reference_Vector.vector_type]++;
                        /*
                         * only complain when the first duplicate is encountered
                         * rather than for all of them
                         */
                         if (vector_type_array
                             [next_fields_ptr->u.Reference_Vector.vector_type] == 2)
                         {
                             sprintf(err_msg,
                               "has multiple <Reference Vector> components "\
                               "for vector_type %s",
                               SE_PrintReferenceVectorType
                               (next_fields_ptr->u.Reference_Vector.vector_type));
                             se_message(object, path[level], level, path,
                                MSGTYP_ERROR, err_msg);
                         }
                     }
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_PRIMITIVE_GEOMETRY])
                     {
                         check_primitive_geometry(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag]
                                    [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
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
            ("check_union_of_primitive_geometry:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);

    if (fields_ptr->u.Union_Of_Primitive_Geometry.union_reason ==
        SE_UNIONREAS_OTHER)
    {
        if (direct_classification_data == SE_TRUE)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
             "union_reason violates <<Classification Data Constraints>>");
        }
        else if (inherits_classification_data == SE_TRUE)
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
             "union_reason violates <<Classification Data Constraints>> "\
             "(inherits <Classification Data> so union_reason cannot "\
             "be SE_UNIONREAS_OTHER)");
        }
    }
    else if ((inherits_classification_data != SE_TRUE) &&
             (direct_classification_data != SE_TRUE))
    {
       /*
        * $$$ what if only some contexts for the
        * $$$ <Union Of Primitive Geometry> supply <Classification Data>?
        * $$$ will get different answers for the different contexts there
        */
        se_message(object, path[level], level, path, MSGTYP_ERROR,
         "union_reason violates <<Classification Data Constraints>> "\
         "(no direct or inherited <Classification Data> but union_reason != "\
         "SE_UNIONREAS_OTHER)");
    }
} /* end check_union_of_primitive_geometry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_PGHP
 *
 *-----------------------------------------------------------------------------
 */
static void
check_PGHP
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                 mandatory_spatial_extent
)
{
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_val_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_LOCAL_CONTEXT      local_context;
    SE_Boolean            has_spatial_extent = SE_FALSE;

   /*
    * check <Spatial Extent> before handling other components
    */
    SE_SpawnUpdatedLocalContext(level, path, object, context,
        &local_context, summary, &has_spatial_extent);

    if ((mandatory_spatial_extent == SE_TRUE) &&
        (has_spatial_extent != SE_TRUE))
    {
        printLastFnctStatus("check_PGHP:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "violates <<Quadrant Related Organizing Principle>> or "\
                 "<<Octant Related Organizing Principle>> "\
                 "(no <Spatial Extent> component)");
    }

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_PGHP:SE_InitializeComponentIterator");
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
            printLastFnctStatus("check_PGHP:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_GRID:
                     check_data_table(level+1, path, next_object,
                         next_fields_ptr, summary);
                     break;

                case SE_CLS_DRM_PROPERTY_VALUE:
                     check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     else
                     {
                         check_attribute(level+1, path, next_object,
                             next_fields_ptr, context, summary);
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

    local_FreeElementCodeQueue(&eac_val_queue);
} /* end check_PGHP */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_geometry_edge
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_geometry_edge
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  geometry_edge,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_geometry_topology
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Object      geometry_node_start = NULL, geometry_node_end = NULL;
    SE_Boolean     found_node = SE_FALSE;

    path[level] = SE_CLS_DRM_GEOMETRY_EDGE;

   /*
    * Do not SE_UpdateAnalysisCounts for the <Geometry Node>;
    * that is handled elsewhere
    */
    if (SE_GetNthAssociate(geometry_edge, SE_CLS_DRM_GEOMETRY_NODE, 1,
        &geometry_node_start, NULL) == SE_RETCOD_SUCCESS)
    {
        if (local_IsComponentOf(level, path, union_of_geometry_topology,
            geometry_node_start, NULL, &found_node) == SE_RETCOD_SUCCESS)
        {
            if (found_node != SE_TRUE)
            {
                se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
                   "start <Geometry Node> is not a component of "\
                   "the <Union Of Geometry Topology> instance containing "\
                   "the <Geometry Edge>");
                ret_status = SE_RETCOD_FAILURE;
            }
        }
        else
        {
            se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
               "can't verify whether start <Geometry Node> is a component of "\
               "the <Union Of Geometry Topology> instance containing "\
               "the <Geometry Edge>");
            ret_status = SE_RETCOD_FAILURE;
        }
    }
    else
    {
        printLastFnctStatus("check_geometry_edge:SE_GetNthAssociate");
        se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
           "can't retrieve start <Geometry Node>");
        return SE_RETCOD_FAILURE;
    }

   /*
    * Do not SE_UpdateAnalysisCounts for the <Geometry Node>;
    * that is handled elsewhere
    */
    if (SE_GetNthAssociate(geometry_edge, SE_CLS_DRM_GEOMETRY_NODE, 2,
        &geometry_node_end, NULL) == SE_RETCOD_SUCCESS)
    {
        found_node = SE_FALSE;
        if (local_IsComponentOf(level, path, union_of_geometry_topology,
            geometry_node_end, NULL, &found_node) == SE_RETCOD_SUCCESS)
        {
            if (found_node != SE_TRUE)
            {
                se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
                   "end <Geometry Node> is not a component of "\
                   "the <Union Of Geometry Topology> instance containing "\
                   "the <Geometry Edge>");
                ret_status = SE_RETCOD_FAILURE;
            }
        }
        else
        {
            se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
               "can't verify whether start <Geometry Node> is a component of "\
               "the <Union Of Geometry Topology> instance containing "\
               "the <Geometry Edge>");
            ret_status = SE_RETCOD_FAILURE;
        }
    }
    else
    {
        printLastFnctStatus("check_geometry_edge:SE_GetNthAssociate");
        se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
           "can't retrieve start <Geometry Node>");
        SE_FreeObject(geometry_node_start);
        return SE_RETCOD_FAILURE;
    }

    found_node = SE_FALSE;
    if (SE_ObjectsAreSame(geometry_node_start, geometry_node_end, &found_node)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_geometry_edge:SE_ObjectsAreSame");
        se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
           "can't verify that start and end <Geometry Node> instances are "\
           "different objects");
        ret_status = SE_RETCOD_FAILURE;
    }
    else if (found_node == SE_TRUE)
    {
        se_message(geometry_edge, path[level], level, path, MSGTYP_ERROR,
           "start and end <Geometry Node> instances are the same object");
        ret_status = SE_RETCOD_FAILURE;
    }
    SE_FreeObject(geometry_node_start);
    SE_FreeObject(geometry_node_end);

   /* $$$
    *
    * loc_count = i;
    *
    * Where this loops through a class of associates, they will then not
    * need to loop through instances of <Geometry Node>.
    * 1) <Geometry Node> instances are not co-located
    * 2) <Geometry Face> instances do not appear twice - they check that
    * 2) no <Geometry Volume> instances appear twice
    */
    return ret_status;
} /* end check_geometry_edge */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_geometry_face
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_geometry_face
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  geometry_face,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_geometry_topology
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

    path[level] = SE_CLS_DRM_GEOMETRY_FACE;

    if (SE_InitializeAssociateIterator(geometry_face,
        GetGlobalAssociationFilter(SE_CLS_DRM_GEOMETRY_FACE),
        SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(geometry_face, path[level], level, path,
           MSGTYP_ERROR,"can't initialize associate iter");
        return SE_RETCOD_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iter, &ro_list)
         != SE_RETCOD_SUCCESS)
    {
        SE_FreeIterator(iter);
        se_message(geometry_face, path[level], level, path,
           MSGTYP_ERROR, "can't get ro_list");
        return SE_RETCOD_FAILURE;
    }
    SE_FreeIterator(iter);

    for (i = 0; i < ro_list.object_count; i++)
    {
        if (local_IsComponentOf(level, path, union_of_geometry_topology,
            ro_list.remaining_objects_list[i], NULL, &found_edge)
            == SE_RETCOD_SUCCESS)
        {
            if (found_edge != SE_TRUE)
            {
                se_message(geometry_face, path[level], level, path, MSGTYP_ERROR,
                   "<Geometry Edge> is not a component of "\
                   "the <Union Of Geometry Topology> instance containing "\
                   "the <Geometry Face>");
                ret_status = SE_RETCOD_FAILURE;
            }
        }
        else
        {
            se_message(geometry_face, path[level], level, path, MSGTYP_ERROR,
               "can't verify whether <Geometry Edge> is a component of "\
               "the <Union Of Geometry Topology> instance containing "\
               "the <Geometry Face>");
            ret_status = SE_RETCOD_FAILURE;
        }
    }

   /*
    * check <Geometry Edge> direction constraints
    * 1) <<Face Ring Edge Consistency>>
    */
    if (ro_list.object_count < 3)
    {
        se_message(geometry_face, path[level], level, path,
            MSGTYP_ERROR,
            "has fewer than 3 <Geometry Edge> associates -"\
            " cannot represent bounded region");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        for (i = 0; i < ro_list.object_count - 1; i++)
        {
            if (SE_GetFields(
                ro_list.remaining_link_objects_list[i],
                GetGlobalStore(level),
                &link_fields_i_ptr) == SE_RETCOD_SUCCESS)
            {
                SE_Object end_node_i = NULL, start_node_j = NULL;

                if (link_fields_i_ptr->u.Edge_Direction.forwards == SE_TRUE)
                {
                    if (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
                        SE_CLS_DRM_GEOMETRY_NODE, 2, &end_node_i, NULL) !=
                        SE_RETCOD_SUCCESS)
                    {
                        path[level+1] = SE_CLS_DRM_GEOMETRY_EDGE;
                        se_message(ro_list.remaining_objects_list[i],
                             SE_CLS_DRM_GEOMETRY_EDGE, level+1, path, MSGTYP_ERROR,
                             "can't get end <Geometry Node>");
                        end_node_i = NULL;
                        ret_status = SE_RETCOD_FAILURE;
                    }
                }
                else
                {
                    if (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
                        SE_CLS_DRM_GEOMETRY_NODE, 1, &end_node_i, NULL) !=
                        SE_RETCOD_SUCCESS)
                    {
                        path[level+1] = SE_CLS_DRM_GEOMETRY_EDGE;
                        se_message(ro_list.remaining_objects_list[i],
                             SE_CLS_DRM_GEOMETRY_EDGE, level+1, path, MSGTYP_ERROR,
                             "can't get start <Geometry Node>");
                        end_node_i = NULL;
                        ret_status = SE_RETCOD_FAILURE;
                    }
                }

                for (j = i+1;
                     (ret_status == SE_RETCOD_SUCCESS) &&
                     (j < ro_list.object_count); j++)
                {
                    if (SE_ObjectsAreSame(ro_list.
                        remaining_objects_list[i],
                        ro_list.remaining_objects_list[j],
                       &obj_match) != SE_RETCOD_SUCCESS)
                    {
                        printLastFnctStatus
                        ("check_geometry_face:SE_ObjectsAreSame");
                        ret_status = SE_RETCOD_FAILURE;
                        se_message2(ro_list.remaining_objects_list[i],
                           ro_list.remaining_objects_list[j],
                           SE_CLS_DRM_GEOMETRY_EDGE, level+1, path, MSGTYP_WARNING,
                           "can't compare <Geometry Edge>s, aborting");
                    }
                    else if (obj_match == SE_TRUE)
                    {
                        se_message(geometry_face, path[level], level, path,
                            MSGTYP_ERROR,
                            "references the same <Geometry Edge> more than once -"\
                            " cannot represent bounded region");
                        ret_status = SE_RETCOD_FAILURE;
                    }
                    else if ((end_node_i != NULL) && (j == (i-1)))
                    {
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
                            if ((link_fields_i_ptr->u.Edge_Direction.forwards ==
                                     SE_TRUE) &&
                                (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
                                 SE_CLS_DRM_GEOMETRY_NODE, 1, &start_node_j, NULL) !=
                                 SE_RETCOD_SUCCESS))
                            {
                                path[level+1] = SE_CLS_DRM_GEOMETRY_EDGE;
                                se_message(ro_list.remaining_objects_list[i],
                                   SE_CLS_DRM_GEOMETRY_EDGE, level+1, path,
                                   MSGTYP_ERROR,
                                   "can't get start <Geometry Node>");
                                start_node_j = NULL;
                                ret_status = SE_RETCOD_FAILURE;
                            }
                            else if ((link_fields_i_ptr->u.Edge_Direction.forwards !=
                                      SE_TRUE) &&
                                     (SE_GetNthAssociate(ro_list.remaining_objects_list[i],
                                      SE_CLS_DRM_GEOMETRY_NODE, 2, &start_node_j, NULL)
                                      != SE_RETCOD_SUCCESS))
                            {
                                path[level+1] = SE_CLS_DRM_GEOMETRY_EDGE;
                                se_message(ro_list.remaining_objects_list[i],
                                   SE_CLS_DRM_GEOMETRY_EDGE, level+1, path,
                                   MSGTYP_ERROR, "can't get end <Geometry Node>");
                                start_node_j = NULL;
                                ret_status = SE_RETCOD_FAILURE;
                            }
                            else if (SE_ObjectsAreSame(end_node_i, start_node_j,
                                     &obj_match) != SE_RETCOD_SUCCESS)
                            {
                                printLastFnctStatus
                                ("check_geometry_face:SE_ObjectsAreSame");
                                se_message(ro_list.remaining_objects_list[i],
                                   SE_CLS_DRM_GEOMETRY_EDGE, level+1, path,
                                   MSGTYP_ERROR,
                                   "can't determine if end <Geometry Node> associate is "\
                                   "the same object as the start <Geometry Node> associate"\
                                   " of the next <Geometry Edge> instance in the"\
                                   "<Geometry Face>");
                                path[level+1] = SE_CLS_DRM_GEOMETRY_EDGE;
                                se_message2(start_node_j, end_node_i,
                                   SE_CLS_DRM_GEOMETRY_NODE, level+2, path, MSGTYP_WARNING,
                                   "start <Geometry Node>, end <Geometry Node>");
                                ret_status = SE_RETCOD_FAILURE;
                            }
                            else if (obj_match != SE_TRUE)
                            {
                                if (link_fields_i_ptr->u.Edge_Direction.forwards == SE_TRUE)
                                {
                                    if (link_fields_j_ptr->u.Edge_Direction.forwards == SE_FALSE)
                                    {
                                        se_message(ro_list.remaining_objects_list[i],
                                           SE_CLS_DRM_GEOMETRY_EDGE, level+1, path, MSGTYP_ERROR,
                                           "end <Geometry Node> associate isn't the same object "\
                                           "as the start <Geometry Node> associate of the next "\
                                           "<Geometry Edge> instance in the <Geometry Face>; "\
                                           "<Geometry Face> instance isn't a ring");
                                        ret_status = SE_RETCOD_FAILURE;
                                    }
                                    else
                                    {
                                        se_message(ro_list.remaining_objects_list[i],
                                           SE_CLS_DRM_GEOMETRY_EDGE, level+1, path,
                                           MSGTYP_ERROR,
                                           "end <Geometry Node> associate isn't the same object "\
                                           "as the end <Geometry Node> associate of the next "\
                                           "<Geometry Edge> instance in the <Geometry Face>; "\
                                           "<Geometry Face> instance isn't a ring");
                                        ret_status = SE_RETCOD_FAILURE;
                                    }
                                }
                                else
                                {
                                    if (link_fields_j_ptr->u.Edge_Direction.forwards == SE_FALSE)
                                    {
                                        se_message(ro_list.remaining_objects_list[i],
                                           SE_CLS_DRM_GEOMETRY_EDGE, level+1, path,
                                           MSGTYP_ERROR,
                                           "start <Geometry Node> associate isn't the same object "\
                                           "as the start <Geometry Node> associate of the next "\
                                           "<Geometry Edge> instance in the <Geometry Face>; "\
                                           "<Geometry Face> instance isn't a ring");
                                        ret_status = SE_RETCOD_FAILURE;
                                    }
                                    else
                                    {
                                        se_message(ro_list.remaining_objects_list[i],
                                           SE_CLS_DRM_GEOMETRY_EDGE, level+1, path, MSGTYP_ERROR,
                                           "start <Geometry Node> associate isn't the same object "\
                                           "as the end <Geometry Node> associate of the next "\
                                           "<Geometry Edge> instance in the <Feature Face>; "\
                                           "<Geometry Face> instance isn't a ring");
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
                } /* end for j */

                if (end_node_i != NULL)
                {
                    SE_FreeObject(end_node_i);
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
    SE_FreeRemainingObjectsList(&ro_list);
    return ret_status;
} /* end check_geometry_face */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_geometry_node
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_geometry_node
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  geometry_node,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code             ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator                iter = NULL;
    SE_Remaining_Objects_List  ro_list;
    SE_Integer_Unsigned        i = 0, j = 0, loc_count = 0;
    SE_Boolean                 found_duplicates = SE_FALSE,
                               obj_match = SE_FALSE;
    SE_DRM_Class               drm_class_i = SE_CLS_DRM_NULL,
                               drm_class_j = SE_CLS_DRM_NULL;
    SE_Object                 *loc_array = NULL;

    path[level] = SE_CLS_DRM_GEOMETRY_NODE;

    if (SE_InitializeAssociateIterator(geometry_node,
           GetGlobalAssociationFilter(SE_CLS_DRM_GEOMETRY_NODE),
           SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(geometry_node, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize associate iter");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        if (SE_GetRemainingObjectsList(iter, &ro_list)
            != SE_RETCOD_SUCCESS)
        {
            se_message(geometry_node, path[level], level, path, MSGTYP_ERROR,
                     "can't get ro_list");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (ro_list.object_count < 1)
        {
            SE_FreeRemainingObjectsList(&ro_list);
            se_message(geometry_node, path[level], level, path, MSGTYP_ERROR,
                 "no associated <Geometry Representation> or <Vertex>");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (ro_list.object_count == 1)
        {
            SE_FreeIterator(iter);
            SE_FreeRemainingObjectsList(&ro_list);
            return ret_status;
        }
        SE_FreeIterator(iter);
    }

    if ((ret_status != SE_RETCOD_SUCCESS) ||
        ((loc_array=(SE_Object*)calloc(sizeof(SE_Object),
          ro_list.object_count)) == NULL))
    {
        return ret_status;
    }

   /*
    * check <Geometry Node> position - at this point have
    * verified is present but multiple instances are involved
    * - syntax checker has verified that they're distinct objects
    *   since each is in a zero or one association relationship
    * - need to verify here that they're co-located
    */
    for (i = 0, loc_count = 0; i < ro_list.object_count; i++)
    {
        if (SE_GetComponent(ro_list.remaining_objects_list[i],
            SE_CLS_DRM_LOCATION, SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
            &(loc_array[i]), NULL) == SE_RETCOD_SUCCESS)
        {
            loc_count++;
        }
        else
        {
            ret_status = SE_RETCOD_FAILURE;
            se_message(geometry_node, path[level], level, path, MSGTYP_ERROR,
                     "can't get <Location> from associate");
        }
    } /* end for i */
    SE_FreeRemainingObjectsList(&ro_list);

    if ((loc_count > 1) && (ret_status == SE_RETCOD_SUCCESS))
    {
        SE_Object loc_array2[2];

        for (i = 0; (ret_status==SE_RETCOD_SUCCESS) && (i < loc_count-1); i++)
        {
            loc_array2[0] = loc_array[i];
            for (j = i+1; (ret_status==SE_RETCOD_SUCCESS) && (j < loc_count); j++)
            {
                SE_Integer_Unsigned first_dup_indx_ptr = 0;

                loc_array2[1] = loc_array[j];
                if (check_object_list_for_duplicate_locations
                    (2, loc_array2, &first_dup_indx_ptr) != SE_TRUE)
                {
                    ret_status = SE_RETCOD_FAILURE;
                    se_message(geometry_node, path[level], level, path,
                       MSGTYP_ERROR, "some <Location>s from associated "\
                       "geometry are not co-located");
                }
            }
        }
        loc_array[0] = NULL;
        loc_array[1] = NULL;
    }
    for (i = 0; i < loc_count; i++)
    {
        SE_FreeObject(loc_array[i]);
    } /* end for i */
    free(loc_array);
    return ret_status;
} /* end check_geometry_node */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_geometry_volume
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_geometry_volume
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  geometry_volume,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Object                  union_of_geometry_topology
)
{
    SE_Return_Code            ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator               iter = NULL;
    SE_Remaining_Objects_List ro_list;
    SE_FIELDS_PTR             link_fields_i_ptr = NULL,
                              link_fields_j_ptr = NULL;
    SE_Integer_Unsigned       i = 0, j = 0;
    SE_Boolean                obj_match = SE_FALSE;

    path[level] = SE_CLS_DRM_GEOMETRY_VOLUME;

    if (SE_InitializeAssociateIterator(geometry_volume,
           GetGlobalAssociationFilter(SE_CLS_DRM_GEOMETRY_VOLUME),
           SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_geometry_volume:SE_InitializeAssociateIterator");
        se_message(geometry_volume, path[level], level, path, MSGTYP_ERROR,
                 "can't initialize associate iter");
        return SE_RETCOD_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iter, &ro_list)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_geometry_volume:SE_GetRemainingObjectsList");
        se_message(geometry_volume, path[level], level, path,
           MSGTYP_ERROR, "can't get ro_list");
        return SE_RETCOD_FAILURE;
    }
    SE_FreeIterator(iter);

    for (i = 0; i < ro_list.object_count; i++)
    {
        SE_Boolean found_face = SE_FALSE;

        if (local_IsComponentOf(level, path, union_of_geometry_topology,
            ro_list.remaining_objects_list[i], NULL, &found_face)
            == SE_RETCOD_SUCCESS)
        {
            if (found_face != SE_TRUE)
            {
                se_message(geometry_volume, path[level], level, path,
                   MSGTYP_ERROR, "<Geometry Face> is not a component of "\
                   "the <Union Of Geometry Topology> instance containing "\
                   "the <Geometry Volume>");
                ret_status = SE_RETCOD_FAILURE;
            }
        }
        else
        {
            se_message(geometry_volume, path[level], level, path, MSGTYP_ERROR,
               "can't verify whether <Geometry Face> is a component of "\
               "the <Union Of Geometry Topology> instance containing "\
               "the <Geometry Volume>");
            ret_status = SE_RETCOD_FAILURE;
        }
    }

   /*
    * check <Geometry Edge> direction constraints
    * 1) <<Face Ring Edge Consistency>>
    * $$$ 2) <<Edges Bordering Faces>>
    */
    if (ro_list.object_count < 4)
    {
        se_message(geometry_volume, path[level], level, path, MSGTYP_ERROR,
                 "has fewer than 4 <Geometry Face> associates - "\
                 "cannot represent bounded volume");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        for (i = 0; (i < ro_list.object_count - 1) &&
                    (ret_status == SE_RETCOD_FAILURE); i++)
        {
            for (j = i+1; (j < ro_list.object_count) &&
                          (ret_status == SE_RETCOD_FAILURE); j++)
            {
                if (SE_ObjectsAreSame(ro_list.
                    remaining_objects_list[i],
                    ro_list.remaining_objects_list[j],
                   &obj_match) != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_geometry_volume:SE_ObjectsAreSame");
                    ret_status = SE_RETCOD_FAILURE;
                }
                else if (obj_match == SE_TRUE)
                {
                    se_message(geometry_volume, path[level], level, path, MSGTYP_ERROR,
                     "references the same <Geometry Face> more than once - "\
                     "cannot represent bounded region");
                    ret_status = SE_RETCOD_FAILURE;
                }
            } /* end for j */
        } /* end for i */
    }
    SE_FreeRemainingObjectsList(&ro_list);
    return ret_status;
} /* end check_geometry_volume */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_union_of_geometry_topology
 *
 *-----------------------------------------------------------------------------
 */
static void
check_union_of_geometry_topology
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  union_of_geometry_topology,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY;

    if (local_InitializeComponentIterator3(union_of_geometry_topology,
         search_filter, &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(union_of_geometry_topology, path[level], level, path,
           MSGTYP_ERROR, "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_union_of_geometry_topology:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_GEOMETRY_NODE:
                     check_geometry_node(level+1, path, next_object, context,
                        summary);
                     break;

                case SE_CLS_DRM_GEOMETRY_EDGE:
                     check_geometry_edge(level+1, path, next_object, context,
                        summary, union_of_geometry_topology);
                     break;

                case SE_CLS_DRM_GEOMETRY_FACE:
                     check_geometry_face(level+1, path, next_object, context,
                        summary, union_of_geometry_topology);
                     break;

                case SE_CLS_DRM_GEOMETRY_VOLUME:
                     check_geometry_volume(level+1, path, next_object, context,
                        summary, union_of_geometry_topology);
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
} /* end check_union_of_geometry_topology */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_perimeter_related_geometry_topology
 *
 *-----------------------------------------------------------------------------
 */
static void
check_perimeter_related_geometry_topology
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

    if (local_InitializeComponentIterator3(object, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter ) == SE_FALSE )
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS )
        {
            printLastFnctStatus
            ("check_perimeter_related_geometry_topology:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            if (SE_IsA[next_fields_ptr->tag]
                      [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY]==SE_TRUE)
            {
                if (link_object)
                {
                    SE_UpdateAnalysisCounts();

                    check_perimeter_data(level+1, path, link_object, context, summary);
                }
                else
                {
                    se_message(next_object, next_fields_ptr->tag, level, path,
                       MSGTYP_ERROR, "missing link object");
                }
                check_topology_hierarchy(level+1, path, next_object,
                    next_fields_ptr, context, summary);
            }
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level, path,
               MSGTYP_ERROR, "can't get fields");
        }

        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_perimeter_related_geometry_topology */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_index_related_geometry_topology
 *
 *-----------------------------------------------------------------------------
 */
static void
check_spatial_index_related_geometry_topology
(
          SE_Short_Integer_Unsigned                 level,
          SE_DRM_Class                              path
                                                    [MAX_CHECKER_PATH_LENGTH],
          SE_Object                                 object,
    const SE_Spatial_Index_Related_Geometry_Topology_Fields *fields_ptr,
          SE_LOCAL_CONTEXT                         *context,
          SE_LOCAL_SUMMARY                         *summary
)
{
    SE_Iterator                  iter = NULL;
    SE_Element_Code_Queue        eac_val_queue;
    SE_Object                    link_object = NULL, next_object = NULL;
    SE_Integer_Unsigned          i, cell_count;
    SE_Spatial_Index_Parameters  link_fields;
    char                         err_msg[256];
    SE_FIELDS_PTR                link_fields_ptr = NULL, next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }
    else if ((SE_GetIterationLengthRemaining(iter,
              &(link_fields.spatial_index_data_count))!=SE_RETCOD_SUCCESS)
          || (link_fields.spatial_index_data_count < 1))
    {
        se_message(object, path[level], level, path,
           MSGTYP_ERROR, "can't get iteration length or is zero");
        SE_FreeIterator(iter);
        return;
    }
    else if ((link_fields.spatial_index_data_array =
              (SE_Spatial_Index_Data_Fields *)
               calloc(link_fields.spatial_index_data_count,
                      sizeof(SE_Spatial_Index_Data_Fields))) == NULL)
    {
        se_message(object, path[level], level, path,
           MSGTYP_ERROR, "can't calloc spatial_index_data_array");
        SE_FreeIterator(iter);
        return;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;
    i = 0;

    while (SE_IsIteratorComplete(iter ) == SE_FALSE )
    {
        if (SE_GetNextObject(iter, &next_object, &link_object)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus(
             "check_spatial_index_related_geometry_topology:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) != SE_RETCOD_SUCCESS)
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        else if (SE_IsA[next_fields_ptr->tag]
                       [SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY])
        {
            if (SE_GetFields(link_object, GetGlobalTempStore(level),
                &link_fields_ptr) != SE_RETCOD_SUCCESS)
            {
                se_message(next_object,  SE_CLS_DRM_SPATIAL_INDEX_DATA,
                   level+1, path, MSGTYP_ERROR,
                   "Can't get fields of link object");
            }
            else if (!SE_IsA[link_fields_ptr->tag]
                            [SE_CLS_DRM_SPATIAL_INDEX_DATA])
            {
                SE_UpdateAnalysisCounts();

                se_message(next_object, next_fields_ptr->tag,
                   level+1, path, MSGTYP_ERROR, "invalid link object");
            }
            else
            {
                SE_UpdateAnalysisCounts();

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
            check_topology_hierarchy(level+1, path, next_object,
                next_fields_ptr, context, summary);
        }
        else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
        {
            check_location(level+1, path, next_object, next_fields_ptr,
                  NULL, context, summary);
        }
        if (link_object)
            SE_FreeObject(link_object);

        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    local_FreeElementCodeQueue(&eac_val_queue);

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
} /* end check_spatial_index_related_geometry_topology */


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
    path[level] = fields_ptr->tag;

    switch (path[level])
    {
        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY:
             check_perimeter_related_geometry_topology(level, path,
                  object, context, summary);
             break;
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
             local_CheckSpatialIndexUnit
             (level, path, object, fields_ptr, &(context->srf_context_info));
             check_spatial_index_related_geometry_topology(level, path, object,
                &(fields_ptr->u.Spatial_Index_Related_Geometry_Topology),
                  context, summary);
             break;
        case SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY:
             check_union_of_geometry_topology(level, path,
                 object, fields_ptr, context, summary);
             break;
        default:
             se_message(object, fields_ptr->tag, level, path,
                MSGTYP_ERROR, "invalid component");
             break;
    }
} /* end check_topology_hierarchy */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_stamp_behaviour
 *
 *-----------------------------------------------------------------------------
 */
static void
check_stamp_behaviour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_STAMP_BEHAVIOUR;

    if ((context->srf_context_info.srf_parameters_info.srf_params_info_code
         != SRM_SRFPARAMINFCOD_TEMPLATE) ||
        (context->srf_context_info.srf_parameters_info.value.
         srf_template.template_code != SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Stamp Behaviour Constraints>> - "\
           "context is not 3D LSR");
    }

   /* <Location 3D> */
    if (SE_GetComponent(object, SE_CLS_DRM_LOCATION_3D,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
        &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();
        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_location
            (
                level+1,
                path,
                next_object,
                next_fields_ptr,
                NULL,
                context,
                summary
            );
        }
        else
        {
            printLastFnctStatus("check_stamp_behaviour:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_LOCATION_3D, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
} /* end check_stamp_behaviour */
