/*
 * FILE       : prop_set_table.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a SEDRIS transmittal, with
 *    regard to constraints affecting <Property Set Table> instances.
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
#include "control_link.h"
#include "data_table.h"
#include "image.h"
#include "metadata.h"
#include "prop_set_table.h"
#include "sound_symbol.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_attribute
 *
 *-----------------------------------------------------------------------------
 */
void
check_attribute
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
    SE_Object           link_object = NULL, next_object = NULL;
    SE_FIELDS_PTR       link_fields_ptr = NULL, next_fields_ptr = NULL;
    SE_Integer_Unsigned tc_count = 0;

    path[level] = fields_ptr->tag;

    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_BOUNDING_VOLUME:
        case SE_CLS_DRM_COLLISION_VOLUME:
             check_volume(level, path, object, fields_ptr, context, summary);
             break;

        case SE_CLS_DRM_CITATION:
             check_citation(level, path, object, fields_ptr, summary);
             break;

        case SE_CLS_DRM_CLASSIFICATION_DATA:
        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
        case SE_CLS_DRM_REFERENCE_SURFACE:
        {
             SE_Classification_Entry entry;

             check_classification_data(level, path, object, fields_ptr,
                 &entry, summary);

             SE_FreeClassificationEntry(&entry, NULL);
             break;
        }

        case SE_CLS_DRM_COLOUR_INDEX:
             check_colour_index( level, path, object, fields_ptr,
                 context, summary);
             break;

        case SE_CLS_DRM_GEOMETRIC_CENTRE:
             if (SE_GetComponent(object, SE_CLS_DRM_LOCATION,
                 SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
                 == SE_RETCOD_SUCCESS)
             {
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
                     check_location(level+1, path, next_object,
                         next_fields_ptr, NULL, context, summary);
                 }
                 else
                 {
                     se_message(next_object, path[level], level+1, path,
                        MSGTYP_WARNING, "can't get fields for <Location> "\
                        "component");
                 }
             }
             else
             {
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, "can't get <Location> component");
             }
             break;

        case SE_CLS_DRM_KEYWORDS:
             if (SE_GetComponent(object, SE_CLS_DRM_CITATION, SE_FALSE,
                    SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
                 == SE_RETCOD_SUCCESS)
             {
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                     check_citation(level+1, path, next_object,
                                    next_fields_ptr, summary);
                 }
                 else
                 {
                     se_message(next_object, SE_CLS_DRM_CITATION, level+1, path,
                        MSGTYP_ERROR, "can't get fields");
                 }
             }
             break;

        case SE_CLS_DRM_PROCESS_STEP:
             if (local_InitializeComponentIterator3(object, search_filter,
                 &iter) != SE_RETCOD_SUCCESS)
             {
                 se_message(object, SE_CLS_DRM_PROCESS_STEP, level, path,
                    MSGTYP_ERROR, "can't initialize iterator");
                 return;
             }

             while (SE_IsIteratorComplete(iter) == SE_FALSE)
             {
                 if (SE_GetNextObject(iter, &next_object, &link_object)
                     != SE_RETCOD_SUCCESS )
                 {
                     printLastFnctStatus("check_attribute:SE_GetNextObject");
                     break;
                 }
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                     check_attribute(level+1, path, next_object,
                         next_fields_ptr, context, summary);

                     switch (next_fields_ptr->tag)
                     {
                         case SE_CLS_DRM_ABSOLUTE_TIME:
                              if (next_fields_ptr->u.Absolute_Time.time_significance
                                  != SE_TIMESIGNIF_OCCURRENCE)
                              {
                                  se_message(object, SE_CLS_DRM_PROCESS_STEP, level,
                                    path, MSGTYP_ERROR, "violates <<Mandatory Metadata>> - "\
                                    "<Absolute Time> time_significance != "\
                                    "SE_TIMESIGNIF_OCCURRENCE");
                              }
                              break;

                         case SE_CLS_DRM_RESPONSIBLE_PARTY:
                              if (SE_GetFields(link_object, GetGlobalTempStore(level),
                                  &link_fields_ptr) == SE_RETCOD_SUCCESS)
                              {
                                  SE_UpdateAnalysisCounts();
                                  SE_UpdateLocalSummaryFromFields(summary, link_fields_ptr);

                                  if (link_fields_ptr->u.Role_Data.role !=
                                      SE_ROLECOD_PROCESSOR)
                                  {
                                      se_message(next_object,
                                         SE_CLS_DRM_RESPONSIBLE_PARTY,
                                         level+1, path, MSGTYP_ERROR,
                                         "violates <<Mandatory Metadata>> - "\
                                         "role != SE_ROLECOD_PROCESSOR");
                                  }
                              }
                              else
                              {
                                  se_message(link_object, SE_CLS_DRM_ROLE_DATA,
                                    level+1, path, MSGTYP_ERROR, "Can't get fields");
                              }
                              break;
                     } /* end switch */
                 }
                 else
                 {
                     printLastFnctStatus("check_attribute:SE_GetFields");
                     se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                        MSGTYP_ERROR, "Can't get fields");
                 } /* end if */
                 SE_FreeObject(next_object);
                 if (link_object) SE_FreeObject(link_object);
             } /* end while */
             SE_FreeIterator(iter);
             break;

        case SE_CLS_DRM_DATA_QUALITY:
             if (local_InitializeComponentIterator3(object, search_filter,
                 &iter) != SE_RETCOD_SUCCESS)
             {
                 se_message(object, SE_CLS_DRM_DATA_QUALITY, level, path,
                    MSGTYP_ERROR, "can't initialize iterator");
                 return;
             }

             while (SE_IsIteratorComplete(iter) == SE_FALSE)
             {
                 if (SE_GetNextObjectOnly(iter, &next_object)
                    != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("check_attribute:SE_GetNextObject");
                     break;
                 }
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                     check_attribute(level+1, path, next_object,
                          next_fields_ptr, context, summary);
                 }
                 else
                 {
                     printLastFnctStatus("check_attribute:SE_GetFields");
                     se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                        MSGTYP_ERROR, "Can't get fields");
                 }
                 SE_FreeObject(next_object);
             }
             SE_FreeIterator(iter);
             break;

        case SE_CLS_DRM_IDENTIFICATION:
             check_identification(level, path, object, summary);
             break;

        case SE_CLS_DRM_INLINE_COLOUR:
             check_inline_colour(level, path, object, fields_ptr,
                 context, summary);
             break;

        case SE_CLS_DRM_LINEAGE:
             {
                 SE_Boolean has_components = SE_FALSE;

                 if (local_InitializeComponentIterator3(object, search_filter,
                     &iter) != SE_RETCOD_SUCCESS)
                 {
                     se_message(object, SE_CLS_DRM_LINEAGE, level, path,
                        MSGTYP_ERROR, "can't initialize iterator");
                     return;
                 }

                 while (SE_IsIteratorComplete(iter) == SE_FALSE)
                 {
                     if (SE_GetNextObjectOnly(iter, &next_object) !=
                         SE_RETCOD_SUCCESS)
                     {
                         printLastFnctStatus("check_attribute:SE_GetNextObject");
                         break;
                     }
                     SE_UpdateAnalysisCounts();

                     if (SE_GetFields(next_object, GetGlobalStore(level),
                         &next_fields_ptr) == SE_RETCOD_SUCCESS)
                     {
                         SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                         check_attribute(level+1, path, next_object,
                             next_fields_ptr, context, summary);
                         if ((next_fields_ptr->tag == SE_CLS_DRM_PROCESS_STEP)
                          || (next_fields_ptr->tag == SE_CLS_DRM_SOURCE))
                         {
                             has_components = SE_TRUE;
                         }
                     }
                     else
                     {
                         se_message(next_object, SE_CLS_DRM_NULL, level, path,
                            MSGTYP_ERROR, "Can't identify <Lineage> component");
                     }
                     SE_FreeObject(next_object);
                 } /* end while */
                 SE_FreeIterator(iter);
                 if ((fields_ptr->u.Lineage.statement.length == 0) &&
                     (has_components != SE_TRUE))
                 {
                     se_message(object, SE_CLS_DRM_LINEAGE, level, path,
                        MSGTYP_ERROR, "violates <<Mandatory Metadata>>");
                 }
             }
             break;

        case SE_CLS_DRM_LIGHT_SOURCE:
             check_light_source(level, path, object, context, summary);
             break;

        case SE_CLS_DRM_LSR_TRANSFORMATION:
             check_LSR_transformation(level, path, object, context, summary);
             break;

        case SE_CLS_DRM_PERIMETER_DATA:
             check_perimeter_data(level, path, object, context, summary);
             break;

        case SE_CLS_DRM_PROPERTY_TABLE:
             check_data_table(level, path, object, fields_ptr, summary);
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
             check_property_table_reference( level, path, object, fields_ptr,
                 (context && context->has_variables) ?
                      &(context->interface_template) : NULL, summary);
            break;

        case SE_CLS_DRM_ABSOLUTE_TIME:
        case SE_CLS_DRM_BASE_TIME_DATA:
        case SE_CLS_DRM_SEASON:
        case SE_CLS_DRM_TIME_OF_DAY:
        case SE_CLS_DRM_TIME_POINT:
             check_base_time_data( level, path, object, fields_ptr, summary);
             break;

        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
        case SE_CLS_DRM_TIME_INTERVAL:
             check_time_interval(level, path, object, fields_ptr, summary);
             break;

        case SE_CLS_DRM_RELATIVE_TIME:
             check_relative_time( level, path, object, fields_ptr );
             break;

        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
             summary->priority_values_present = SE_TRUE;
             break;

        case SE_CLS_DRM_RENDERING_PROPERTIES:
             if (SE_GetComponent(object, SE_CLS_DRM_PRESENTATION_DOMAIN,
                 SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
                 SE_RETCOD_SUCCESS)
             {
                 SE_UpdateAnalysisCounts();
                 SE_FreeObject(next_object);
             }
            /*
             * $$$ for 4.1 and forward, just check if the set member
             * $$$ is zero
             */
             else if ((context->has_unresolved_psi != SE_TRUE) &&
                      !(context->presentation_domain.member.OTW ||
                        context->presentation_domain.member.IR_Hi_Band ||
                        context->presentation_domain.member.IR_Low_Band ||
                        context->presentation_domain.member.NVG ||
                        context->presentation_domain.member.Day_TV_Colour ||
                        context->presentation_domain.member.Day_TV_BW ||
                        context->presentation_domain.member.Radar ||
                        context->presentation_domain.member.SAR ||
                        context->presentation_domain.member.Thermal ||
                        context->presentation_domain.member.Low_Light_TV))
             {
                 printLastFnctStatus("check_attribute:SE_GetComponent");
                 se_message(object, path[level], level, path, MSGTYP_ERROR,
                    "violates <<Presentation Domain Constraints>> "\
                    "(no inherited or direct <Presentation Domain> component "\
                    "found)");
             }
             break;

        case SE_CLS_DRM_SOUND_INSTANCE:
             check_sound_instance(level, path, object, fields_ptr,
                 context, summary);
             break;

        case SE_CLS_DRM_SOURCE:
             if (SE_GetComponent(object, SE_CLS_DRM_CITATION, SE_FALSE,
                    SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
                 == SE_RETCOD_SUCCESS)
             {
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
                     check_citation(level+1, path, next_object,
                         next_fields_ptr, summary);
                 }
                 else
                 {
                     se_message(next_object, SE_CLS_DRM_CITATION, level+1, path,
                        MSGTYP_ERROR, "can't get fields");
                 }
             }
             else
             {
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, "can't get <Citation> component");
             }

             if (next_object)
                 SE_FreeObject(next_object);

             if (SE_GetComponent(object, SE_CLS_DRM_TIME_INTERVAL,
                   SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
                 == SE_RETCOD_SUCCESS)
             {
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
                     check_time_interval(level+1, path,
                         next_object, next_fields_ptr, summary);
                 }
                 else
                 {
                     se_message(next_object, SE_CLS_DRM_TIME_INTERVAL, level+1, path,
                         MSGTYP_ERROR, "can't get fields");
                 }
             }
             else
             {
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, "can't get <Time Interval> component");
             }

             if (next_object)
                 SE_FreeObject(next_object);
             break;

        case SE_CLS_DRM_TACK_POINT:
             if (local_InitializeComponentIterator3(object, search_filter,
                 &iter) != SE_RETCOD_SUCCESS)
             {
                 se_message(object, SE_CLS_DRM_TACK_POINT, level, path,
                    MSGTYP_ERROR, "can't initialize iterator");
                 return;
             }

             tc_count = 0;
             while (SE_IsIteratorComplete(iter) == SE_FALSE)
             {
                 if (SE_GetNextObjectOnly(iter, &next_object)
                     != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("check_attribute:SE_GetNextObject");
                     break;
                 }
                 SE_UpdateAnalysisCounts();

                 if (SE_GetFields(next_object, GetGlobalStore(level),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object,
                            next_fields_ptr, NULL, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_TEXTURE_COORDINATE])
                     {
                         tc_count++;
                         check_texture_coordinate(level+1, path, next_object,
                            context, summary);
                     }
                 }
                 else
                 {
                     se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                        MSGTYP_ERROR, "Can't identify <Tack Point> component");
                 }
                 SE_FreeObject(next_object);
             } /* end while */
             SE_FreeIterator(iter);

             if ((context->has_unresolved_psi != SE_TRUE) &&
                 (context->expected_texture_coordinate_count != tc_count))
             {
                 se_message(object, SE_CLS_DRM_TACK_POINT, level, path,
                    MSGTYP_ERROR, "violates "\
                    "<<Image Mapping Functions and Texture Coordinates>> constraint");
             }
             break;

        case SE_CLS_DRM_TIME_CONSTRAINTS_DATA:
             check_time_constraints_data(level, path, object,
                 SE_CLS_DRM_BASE_TIME_DATA, summary);
             break;

        case SE_CLS_DRM_WORLD_TRANSFORMATION:
             check_world_transformation(level, path, object, context, summary);
             break;

        default:
             if (SE_IsA[fields_ptr->tag]
                 [SE_CLS_DRM_BASE_LOD_DATA])
             {
                 SE_LOD_Entry lod_entry;

                 check_lod_data(level, path, object, fields_ptr,
                     context, summary, &lod_entry);
             }
             break;
    } /* end switch */
} /* end check_attribute */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_index
 *
 *-----------------------------------------------------------------------------
 */
static void
check_prop_set_index
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
    char          err_msg[1024];

    path[level] = fields_ptr->tag;

    if (SE_GetAssociate(object, SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP,
        SE_ITRBEH_RESOLVE, &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            if (fields_ptr->u.Property_Set_Index.index >
                next_fields_ptr->u.Property_Set_Table_Group.table_size)
            {
                sprintf(err_msg, "index %u is out of range for the "\
                    "associated table_size %u!",
                    (unsigned int) fields_ptr->u.Property_Set_Index.index,
                    (unsigned int) next_fields_ptr->u.
                    Property_Set_Table_Group.table_size);
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   err_msg);
            }
            else if (context->primary_pt_tables->pset_table_group_count > 0)
            {
                SE_Integer_Unsigned i = 0;
                SE_Boolean          found = SE_FALSE;

                while ((found != SE_TRUE) &&
                       (i < context->primary_pt_tables->pset_table_group_count))
                {
                    if (SE_ObjectsAreSame(next_object,
                        context->primary_pt_tables->pset_table_group_array[i].pset_group,
                        &found) != SE_RETCOD_SUCCESS)
                    {
                        sprintf(err_msg, "comparison failed during lookup for "\
                                "referenced <Property Set Table Group>");
                        se_message(object, path[level], level, path, MSGTYP_ERROR,
                           err_msg);
                        found = SE_FALSE;
                    }

                    if (found == SE_TRUE)
                    {
                       /*
                        * update context
                        */
                        if (fields_ptr->u.Property_Set_Index.index >
                            context->primary_pt_tables->pset_table_group_array[i].pset_count)
                        {
                            char err_msg[1024];

                            sprintf(err_msg, "index %u is out of range for the "\
                                "associated <Property Set Table Group>'s primary table",
                                (unsigned int) fields_ptr->u.Property_Set_Index.index);
                            se_message(object, path[level], level, path, MSGTYP_ERROR,
                               err_msg);
                        }
                        else if (context->primary_pt_tables->pset_table_group_array[i].
                                 pset_array[fields_ptr->u.Property_Set_Index.index-1].
                                 pset_resolved == SE_TRUE)
                        {
                            /* $$$ need to handle referenced presentation_domain */

                            if (context->primary_pt_tables->pset_table_group_array[i].
                                pset_array[fields_ptr->u.Property_Set_Index.index-1].
                                class_counts_pattern[SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES]
                                > 0)
                            {
                                context->has_light_ren_prop = SE_TRUE;
                            }

                            if (context->primary_pt_tables->pset_table_group_array[i].
                                pset_array[fields_ptr->u.Property_Set_Index.index-1].
                                class_counts_pattern[SE_CLS_DRM_IMAGE_MAPPING_FUNCTION]
                                > 0)
                            {
                                context->expected_texture_coordinate_count =
                                  context->primary_pt_tables->pset_table_group_array[i].
                                  pset_array[fields_ptr->u.Property_Set_Index.index-1].
                                  class_counts_pattern[SE_CLS_DRM_IMAGE_MAPPING_FUNCTION];
                            }
                        }
                    }
                    else
                    {
                        i++;
                    }
                } /* end while */

                if (found != SE_TRUE)
                    context->has_unresolved_psi = SE_TRUE;
            }
        }
        else
        {
            se_message(object, fields_ptr->tag, level, path,
               MSGTYP_ERROR, "Can't get fields for associated "\
               "<Property Set Table Group>");
        }
        SE_FreeObject(next_object);
    }
    else
    {
        printLastFnctStatus("check_prop_set_index:GetAssociate");
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "can't get associated <Property Set Table Group>");
    }

    if (SE_GetComponent(object, SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
               &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_control_link(level+1, path,
                next_object, next_fields_ptr,
                (context && context->has_variables) ?
                 &(context->interface_template) : NULL, summary);
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
} /* end check_prop_set_index */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_indices
 *
 *   This routine is invoked only when an updated context is being spawned
 *   (the context passed in to this routine).
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_prop_set_indices
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;

    if (local_InitializeComponentIterator3(object,
        GetGlobalComponentFilter(SE_CLS_DRM_PROPERTY_SET_INDEX), &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_prop_desc_components:local_InitializeComponentIterator3");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_prop_set_indices:SE_GetNextObjectOnly");
            if (context->has_unresolved_psi != SE_TRUE)
                context->has_unresolved_psi = SE_TRUE;
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_prop_set_index(level+1, path, next_object,
               next_fields_ptr, context, summary);
        }
        else
        {
            printLastFnctStatus
            ("check_prop_set_indices:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_PROPERTY_SET_INDEX,
               level+1, path, MSGTYP_ERROR, "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    return ret_status;
} /* end check_prop_set_indices */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set
 *
 * Unlike most methods that take an SE_LOCAL_CONTEXT parameter as an IN/OUT
 * parameter, this function has it solely as an OUT parameter.
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_prop_set
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  prop_set,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context_to_initialize,
    SE_LOCAL_SUMMARY          *summary,
    SE_PROPERTY_SET_WRAPPER   *pset_to_initialize
)
{
    SE_Return_Code        ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator           iter = NULL;
    SE_Element_Code_Queue eac_queue;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Boolean            has_presentation_domain = SE_FALSE;

    path[level] = SE_CLS_DRM_PROPERTY_SET;
    memset(pset_to_initialize->class_counts_pattern, 0,
           SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));
    pset_to_initialize->pset_resolved = SE_TRUE;

    if (local_InitializeComponentIterator3(prop_set, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_prop_set:SE_InitializeComponentIterator");
        pset_to_initialize->pset_resolved = SE_FALSE;
        return SE_RETCOD_FAILURE;
    }
    eac_queue.head = NULL;
    eac_queue.tail = NULL;

    SE_InitializeLocalContext(level, path, prop_set, fields_ptr,
       NULL, context_to_initialize);
   /*
    * $$$ for 4.1 and forward, just check if the set member
    * $$$ is zero
    */
    if (context_to_initialize->presentation_domain.member.OTW ||
        context_to_initialize->presentation_domain.member.IR_Hi_Band ||
        context_to_initialize->presentation_domain.member.IR_Low_Band ||
        context_to_initialize->presentation_domain.member.NVG ||
        context_to_initialize->presentation_domain.member.Day_TV_Colour ||
        context_to_initialize->presentation_domain.member.Day_TV_BW ||
        context_to_initialize->presentation_domain.member.Radar ||
        context_to_initialize->presentation_domain.member.SAR ||
        context_to_initialize->presentation_domain.member.Thermal ||
        context_to_initialize->presentation_domain.member.Low_Light_TV)
    {
        has_presentation_domain = SE_TRUE;
        pset_to_initialize->class_counts_pattern[SE_CLS_DRM_PRESENTATION_DOMAIN]++;
    }
    if (context_to_initialize->has_light_ren_prop == SE_TRUE)
    {
        pset_to_initialize->class_counts_pattern[SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES]++;
    }
    pset_to_initialize->class_counts_pattern[SE_CLS_DRM_IMAGE_MAPPING_FUNCTION] =
        context_to_initialize->expected_texture_coordinate_count;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_prop_set:SE_GetNextObject");
            ret_status = SE_RETCOD_FAILURE;
            pset_to_initialize->pset_resolved = SE_FALSE;
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            pset_to_initialize->class_counts_pattern[next_fields_ptr->tag]++;

            if (next_fields_ptr->tag==SE_CLS_DRM_PROPERTY_VALUE)
            {
                check_property_value(level+1, path, next_object,
                    next_fields_ptr, &eac_queue, summary);
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    context_to_initialize, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_prop_set:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_WARNING, "can't get fields so checks for regularity "\
               "will not be complete");
            ret_status = SE_RETCOD_FAILURE;
            pset_to_initialize->pset_resolved = SE_FALSE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
    local_FreeElementCodeQueue(&eac_queue);

    return ret_status;
} /* end check_prop_set */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_table
 *
 *-----------------------------------------------------------------------------
 */
static void
check_prop_set_table
(
          SE_Short_Integer_Unsigned      level,
          SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                      object,
    const SE_Property_Set_Table_Fields  *fields_ptr,
          SE_Integer_Positive            table_size,
          SE_PROPERTY_SET_TABLE_WRAPPER *pset_table_to_initialize,
          SE_LOCAL_SUMMARY              *summary
)
{
    SE_Iterator             iter = NULL;
    SE_Object               next_object = NULL;
    SE_Integer_Unsigned     prop_set_count = 0;
    SE_FIELDS_PTR           next_fields_ptr = NULL;
    SE_Boolean              is_regular = SE_TRUE, got_all_psets = SE_TRUE,
                            got_pattern = SE_FALSE;
    SE_Integer_Unsigned     class_counts_pattern[SE_DRM_CLASS_UBOUND];
    SE_PROPERTY_SET_WRAPPER current_pset;
    SE_LOCAL_CONTEXT        pset_context;

    path[level] = SE_CLS_DRM_PROPERTY_SET_TABLE;
    memset(class_counts_pattern, 0,
           SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_prop_set_table:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iterator");
        return;
    }
    else if (pset_table_to_initialize != NULL)
    {
        if (SE_GetIterationLengthRemaining(iter,
            &(pset_table_to_initialize->pset_count)) == SE_RETCOD_SUCCESS)
        {
            if (pset_table_to_initialize->pset_count > 0)
            {
                if ((pset_table_to_initialize->pset_array = (SE_PROPERTY_SET_WRAPPER *)
                    calloc(pset_table_to_initialize->pset_count,
                           sizeof(SE_PROPERTY_SET_WRAPPER))) == NULL)
                {
                    se_message(object, path[level], level, path, MSGTYP_ERROR,
                       "can't allocate memory");
                }
            }
            else
            {
                pset_table_to_initialize->pset_array = NULL;
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   "no components found");
                return;
            }
        }
        else
        {
            pset_table_to_initialize->pset_count = 0;
            pset_table_to_initialize->pset_array = NULL;
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "can't count components");
            return;
        }
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_prop_set_table:SE_GetNextObject");
            got_all_psets = SE_FALSE;
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag == SE_CLS_DRM_PROPERTY_SET)
            {
                prop_set_count++;
                if (check_prop_set(level+1, path, next_object, next_fields_ptr,
                    &pset_context, summary, &current_pset) == SE_RETCOD_SUCCESS)
                {
                    SE_Short_Integer_Unsigned class_indx = 0;

                    if (got_pattern != SE_TRUE)
                    {
                        for (class_indx = 0; class_indx < SE_DRM_CLASS_UBOUND; class_indx++)
                        {
                            class_counts_pattern[class_indx] =
                              current_pset.class_counts_pattern[class_indx];
                        }
                        got_pattern = SE_TRUE;
                    }
                    else
                    {
                        for (class_indx = SE_CLS_DRM_NULL+1;
                             ((is_regular == SE_TRUE) &&
                              (class_indx < SE_DRM_CLASS_UBOUND)); class_indx++)
                        {
                            if (class_counts_pattern[class_indx] !=
                                current_pset.class_counts_pattern[class_indx])
                            {
                                is_regular = SE_FALSE;
                            }
                        }
                    }

                    if ((pset_table_to_initialize != NULL) &&
                        (pset_table_to_initialize->pset_array != NULL))
                    {
                        memcpy(&(pset_table_to_initialize->pset_array[prop_set_count-1]),
                               &current_pset,
                               sizeof(SE_PROPERTY_SET_WRAPPER));
                    }
                } /* end if check_prop_set */
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    NULL, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_prop_set_table:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_WARNING,
               "can't get fields - checks for regularity will be incomplete");
            got_all_psets = SE_FALSE;
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

   /*
    * Check that the <Property Set> count matches the table_size
    * from the <Property Set Table Group>.
    *
    * Note that this check contains some guards, in case another
    * previously reported error means that either the table_size
    * or the prop_set_count cannot be trusted.
    * - If the <Property Set Group> had an invalid field value,
    *   that's already been reported, and the prop_set_count
    *   will not match unless the <Property Set Table Group>
    *   has additional errors.
    *
    * - If we couldn't fetch all the components, then the
    *   <Property Set> count may be off.
    */
    if ((got_all_psets == SE_TRUE) && (table_size > 0) &&
        (table_size != prop_set_count))
    {
        char err_msg[1024];

        sprintf(err_msg, "table_size == %u but encountered "\
                "%u <Property Set> components",
                (unsigned int) table_size, (unsigned int) prop_set_count);

        se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }

    if ((fields_ptr->regular == SE_TRUE) && (is_regular != SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
          "regular==SE_TRUE but <Property Set> components are not regular");
    }
} /* end check_prop_set_table */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_table_group
 *
 *   Check the Property Set Table Group and its components for the following
 *   constraints:
 *   - <<Mandatory Metadata>>
 *
 *-----------------------------------------------------------------------------
 */
static void
check_prop_set_table_group
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      object,
    SE_FIELDS_PTR                  fields_ptr,
    SE_LOCAL_SUMMARY              *summary,
    SE_PROPERTY_SET_TABLE_WRAPPER *primary_table
)
{
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned ps_table_count = 0;
    SE_Boolean          legal_pset_index = SE_TRUE;

    path[level] = fields_ptr->tag;

    if (fields_ptr->u.Property_Set_Table_Group.primary_table_index < 1)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
                   "invalid primary_table_index");
        legal_pset_index = SE_FALSE;
    }
    if (fields_ptr->u.Property_Set_Table_Group.table_size < 1)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "invalid table_size");
    }

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_prop_set_table_group:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iterator");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_prop_set_table_group:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag == SE_CLS_DRM_PROPERTY_SET_TABLE)
            {
                ps_table_count++;
                check_prop_set_table(level+1, path, next_object,
                    &(next_fields_ptr->u.Property_Set_Table),
                    fields_ptr->u.Property_Set_Table_Group.table_size,
                    ((legal_pset_index == SE_TRUE) &&
                     (ps_table_count ==
                      fields_ptr->u.Property_Set_Table_Group.primary_table_index))
                    ? primary_table : NULL, summary);
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    NULL, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_prop_set_table_group:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (fields_ptr->u.Property_Set_Table_Group.primary_table_index >
             ps_table_count)
    {
        char err_msg[1024];

        sprintf(err_msg, "primary_table_index == %u but there are "\
                "%u <Property Set Table> components",
            (unsigned int)
            fields_ptr->u.Property_Set_Table_Group.primary_table_index,
            (unsigned int) ps_table_count);

        se_message(object, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
} /* end check_prop_set_table_group */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_table_library
 *
 *   Check the given <Property Set Table Library> and its components for the
 *   following constraints:
 *   - <<Mandatory Metadata>>
 *
 *-----------------------------------------------------------------------------
 */
void
check_prop_set_table_library
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              object,
    SE_LOCAL_SUMMARY                      *summary,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_tables
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_prop_set_table_library:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "Can't initialize component iterator");
        return;
    }
    else if (SE_GetIterationLengthRemaining(iter,
             &(primary_tables->pset_table_group_count)) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_prop_set_table_library:SE_GetIterationLengthRemaining");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "Can't get number of components");
        return;
    }
    else if (primary_tables->pset_table_group_count < 1)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
                 "No components");
        return;
    }
    else if ((primary_tables->pset_table_group_array =
             (SE_PROPERTY_SET_TABLE_WRAPPER *)
             calloc(sizeof(SE_PROPERTY_SET_TABLE_WRAPPER),
                    primary_tables->pset_table_group_count))==NULL)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
                 "Can't allocate memory to track <Property Set Table Library>"\
                 "information");
        return;
    }

    primary_tables->pset_table_group_count = 0;
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_prop_set_table_lib:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP:
                     primary_tables->pset_table_group_array
                                     [primary_tables->pset_table_group_count].pset_count = 0;
                     primary_tables->pset_table_group_array
                                     [primary_tables->pset_table_group_count].pset_array = NULL;

                     check_prop_set_table_group(level+1, path, next_object,
                         next_fields_ptr, summary,
                         &(primary_tables->pset_table_group_array
                           [primary_tables->pset_table_group_count]));
                    if (SE_CloneObjectHandle(next_object,
                        &(primary_tables->pset_table_group_array
                        [primary_tables->pset_table_group_count].pset_group))
                        != SE_RETCOD_SUCCESS)
                    {
                        primary_tables->pset_table_group_array
                           [primary_tables->pset_table_group_count].pset_group = NULL;
                    }
                    primary_tables->pset_table_group_count++;
                    break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                         NULL, summary);
                     break;
            }
        }
        else
        {
            printLastFnctStatus("check_prop_set_table_lib:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_prop_set_table_library */
