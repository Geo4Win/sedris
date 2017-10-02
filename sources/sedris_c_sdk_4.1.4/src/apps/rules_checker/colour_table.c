/*
 * FILE       : colour_table.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a transmittal with respect
 *    to constraints affecting <Colour>s.
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
#include "prop_set_table.h"

static void
check_primitive_colour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_inline_colour
 *
 *-----------------------------------------------------------------------------
 */
void
check_inline_colour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object next_object = NULL;

    path[level] = SE_CLS_DRM_INLINE_COLOUR;

   /*
    * If we have all the context but there were no
    * <Light Rendering Properties>, or we are in a
    * place where the context cannot have
    * <Light Rendering Properties>, then the
    * colour_mapping cannot be specific to
    * <Light Rendering Properties>
    */
    if ((((context->has_unresolved_psi != SE_TRUE) &&
          (context->has_light_ren_prop != SE_TRUE)) ||
         (path[level-1] == SE_CLS_DRM_VERTEX))
     && (fields_ptr->u.Colour.colour_mapping.member.
         Primary_Light_Rendering_Behaviour
      || fields_ptr->u.Colour.colour_mapping.member.
         Secondary_Light_Rendering_Behaviour))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
          "violates <<Colour Mapping Constraints>>");
    }

    if (SE_GetComponent(object, SE_CLS_DRM_PRESENTATION_DOMAIN,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
       /*
        * assumption: that the <Presentation Domain> component's
        * fields were previously validated by syntax_checker
        */
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
        printLastFnctStatus("check_inline_colour:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
          "violates <<Presentation Domain Constraints>> "\
          "(no inherited or direct <Presentation Domain> component found)");
    }
    if (SE_GetComponent(object, SE_CLS_DRM_PRIMITIVE_COLOUR,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        check_primitive_colour(level+1, path, next_object, context, summary);
        SE_FreeObject(next_object);
    }
} /* end check_inline_colour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_colour_index
 *
 *-----------------------------------------------------------------------------
 */
void
check_colour_index
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

   /*
    * If we have all the context but there were no
    * <Light Rendering Properties>, or we are in a
    * place where the context cannot have
    * <Light Rendering Properties>, then the
    * colour_mapping cannot be specific to
    * <Light Rendering Properties>
    */
    if ((((context->has_unresolved_psi != SE_TRUE) &&
          (context->has_light_ren_prop != SE_TRUE)) ||
         (path[level-1] == SE_CLS_DRM_VERTEX))
     && (fields_ptr->u.Colour.colour_mapping.member.
         Primary_Light_Rendering_Behaviour
      || fields_ptr->u.Colour.colour_mapping.member.
         Secondary_Light_Rendering_Behaviour))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
          "violates <<Colour Mapping Constraints>>");
    }

    if (SE_GetAssociate(object, SE_CLS_DRM_COLOUR_TABLE_GROUP,
        SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_colour_index:SE_GetFields");
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "Can't get fields for associated <Colour Table Group>");
        }
        else if ((fields_ptr->u.Colour_Index.index > 1) &&
                (fields_ptr->u.Colour_Index.index >
                next_fields_ptr->u.Colour_Table_Group.table_size))
        {
            char err_msg[1024];

            sprintf(err_msg, "index %u is out of range for the "\
                    "associated table_size %u!",
                    (unsigned int) fields_ptr->u.Colour_Index.index,
                    (unsigned int) next_fields_ptr->u.
                    Colour_Table_Group.table_size);
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               err_msg);
        }
        SE_FreeObject(next_object);
    }
    else
    {
        printLastFnctStatus("check_colour_index:SE_GetAssociate");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get associated <Colour Table Group>");
    }

    if (SE_GetComponent(object, SE_CLS_DRM_PRESENTATION_DOMAIN,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
       /*
        * assumption: that the <Presentation Domain> component's
        * fields were previously validated by syntax_checker
        */
        SE_UpdateAnalysisCounts();
        SE_FreeObject(next_object);
    }
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
        printLastFnctStatus("check_colour_index:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
          "violates <<Presentation Domain Constraints>> "\
          "(no inherited or direct <Presentation Domain> component found)");
    }

    if (SE_GetComponent(object, SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_control_link(level+1, path, next_object, next_fields_ptr,
                (context && context->has_variables) ?
                &(context->interface_template) : NULL, summary);
        }
        else
        {
            printLastFnctStatus("check_colour_index:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
} /* end check_colour_index */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_colour_data
 *
 *-----------------------------------------------------------------------------
 */
static void
check_colour_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_DRM_Class               tag,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object control_link = NULL;

    path[level] = tag;

    if (world_colour_model_defined)
    {
        if (((tag == SE_CLS_DRM_CMY_COLOUR) &&
             (world_colour_model != SE_COLRMOD_CMY)) ||
            ((tag == SE_CLS_DRM_HSV_COLOUR) &&
             (world_colour_model != SE_COLRMOD_HSV)) ||
            ((tag == SE_CLS_DRM_RGB_COLOUR) &&
             (world_colour_model != SE_COLRMOD_RGB)))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "not in world colour model");
        }
    }

   /*
    * Check <Control Link>, if present
    */
    if (SE_GetComponent(object, SE_CLS_DRM_CONTROL_LINK, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &control_link, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR next_fields_ptr = NULL;

        SE_UpdateAnalysisCounts();

        if (SE_GetFields(control_link, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_control_link(level+1, path, control_link, next_fields_ptr,
                (context && context->has_variables) ?
                   &(context->interface_template) : NULL, summary);
        }
        else
        {
            se_message(control_link, SE_CLS_DRM_CONTROL_LINK, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(control_link);
    }
} /* end check_colour_data */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_primitive_colour
 *
 *-----------------------------------------------------------------------------
 */
static void
check_primitive_colour
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator  iter = NULL;
    SE_Object    colour_comp = NULL, next_object = NULL;
    SE_Boolean   found_component = SE_FALSE;
    SE_DRM_Class tag = SE_CLS_DRM_NULL;

    path[level] = SE_CLS_DRM_PRIMITIVE_COLOUR;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_primitive_colour:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iterator");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &colour_comp) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_primitive_colour:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetDRMClass(colour_comp, &tag) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_primitive_colour:SE_GetDRMClass");
            se_message(colour_comp, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't identify DRM class");
        }
        else if (SE_GetComponent(colour_comp, SE_CLS_DRM_COLOUR_DATA,
                 SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
                 == SE_RETCOD_SUCCESS)
        {
            SE_UpdateAnalysisCounts();

            path[level+1]   = tag;
            found_component = SE_TRUE;

            if (SE_GetDRMClass(next_object, &tag) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("check_primitive_colour:SE_GetDRMClass");
                se_message(next_object, SE_CLS_DRM_COLOUR_DATA, level+1,
                   path, MSGTYP_ERROR, "can't identify <Colour Data>");
            }
            else
            {
                check_colour_data(level+1, path, next_object, tag, context,
                    summary);
            }
            SE_FreeObject(next_object);
        }
        SE_FreeObject(colour_comp);
    } /* end while */

    SE_FreeIterator(iter);

    if (!found_component)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "empty <Primitive Colour>");
    }
} /* end check_primitive_colour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_colour_table
 *
 *-----------------------------------------------------------------------------
 */
static void
check_colour_table
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  colour_table,
    SE_LOCAL_SUMMARY          *summary,
    SE_Integer_Positive        table_size
)
{
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned i = 0;

    path[level] = SE_CLS_DRM_COLOUR_TABLE;

    if (SE_GetComponent(colour_table, SE_CLS_DRM_PRESENTATION_DOMAIN,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
        SE_RETCOD_SUCCESS)
    {
       /*
        * assumption: that the <Presentation Domain> component's
        * fields were previously validated by syntax_checker
        */
        SE_UpdateAnalysisCounts();
        SE_FreeObject(next_object);
    }

    if (local_InitializeComponentIterator3(colour_table, search_filter,
           &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_colour_table:SE_InitializeComponentIterator");
        se_message(colour_table, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iterator");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_colour_table:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag == SE_CLS_DRM_PRIMITIVE_COLOUR)
            {
                i++;
                check_primitive_colour(level+1, path, next_object, NULL,
                    summary);
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    NULL, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_colour_table:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (table_size != i)
    {
        char err_msg[1024];

        sprintf(err_msg, "table_size == %s but there are "\
                "%u <Primitive Colour>s",
                SE_PrintIntegerUnsigned(table_size), (unsigned int) i);

        se_message(colour_table, SE_CLS_DRM_COLOUR_TABLE, level, path,
           MSGTYP_ERROR, err_msg);
    }
} /* end check_colour_table */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_colour_table_group
 *
 *-----------------------------------------------------------------------------
 */
static void
check_colour_table_group
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
    SE_Integer_Unsigned i = 0;

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_colour_table_group:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iterator");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_colour_table_group:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag == SE_CLS_DRM_COLOUR_TABLE)
            {
                i++;
                check_colour_table( level+1, path, next_object, summary,
                    fields_ptr->u.Colour_Table_Group.table_size);
            }
            else
            {
                check_attribute( level+1, path, next_object, next_fields_ptr,
                    NULL, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_colour_table_group:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (fields_ptr->u.Colour_Table_Group.primary_table_index > i)
    {
        char err_msg[1024];

        sprintf(err_msg, "primary_table_index == %u but there are "\
                "%u <Colour Table> instances",
            (unsigned int)
            fields_ptr->u.Colour_Table_Group.primary_table_index,
            (unsigned int) i);
        se_message(object, SE_CLS_DRM_COLOUR_TABLE_GROUP, level, path,
           MSGTYP_ERROR, err_msg);
    }
} /* end check_colour_table_group */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_colour_table_library
 *
 *-----------------------------------------------------------------------------
 */
void
check_colour_table_library
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;
    SE_Object     next_object = NULL;

    path[level] = SE_CLS_DRM_COLOUR_TABLE_LIBRARY;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
           != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_colour_table_library:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iterator");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_colour_table_library:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (next_fields_ptr->tag == SE_CLS_DRM_COLOUR_TABLE_GROUP)
            {
                check_colour_table_group(level+1, path, next_object,
                    next_fields_ptr, summary);
            }
            else
            {
                check_attribute(level+1, path, next_object, next_fields_ptr,
                    NULL, summary);
            }
        }
        else
        {
            printLastFnctStatus("check_colour_table_library:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_colour_table_library */
