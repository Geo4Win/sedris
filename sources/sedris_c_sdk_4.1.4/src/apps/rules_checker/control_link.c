/*
 * FILE       : control_link.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a SEDRIS transmittal, with
 *    regard to constraints affecting <Control Link> and <Transformation>
 *    instances.
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
#include "metadata.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_variable
 *
 *-----------------------------------------------------------------------------
 */
static void
check_variable
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      expr,
    SE_FIELDS_PTR                  fields_ptr,
    SE_INTERFACE_TEMPLATE_WRAPPER *interface_template
)
{
    SE_Object  interface_template2 = NULL;
    SE_Boolean are_same = SE_FALSE;
    char       err_msg[512];

    if (SE_GetAssociate(expr, SE_CLS_DRM_INTERFACE_TEMPLATE,
        SE_ITRBEH_RESOLVE, &interface_template2, NULL) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_variable:SE_GetAssociate");
        se_message(expr, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "Can't get <Interface Template>");
    }
    else if (SE_ObjectsAreSame(interface_template->interface_template,
             interface_template2, &are_same) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_variable:SE_ObjectsAreSame");
        se_message(expr, path[level], level, path, MSGTYP_ERROR,
           "SE_ObjectsAreSame failed; possible violation "\
           "of <<Constraints on Associates>>");
    }
    else if (are_same != SE_TRUE)
    {
        strcpy(err_msg, "Violates <<Constraints on Associates>>; "\
               "associates to the wrong <Interface Template>");

        se_message(expr, path[level], level, path, MSGTYP_ERROR, err_msg);
    }
    else
    {
        SE_Boolean found = SE_FALSE;
        SE_Integer_Unsigned  i = 0;

        while (!found && (i < interface_template->var_count))
        {
            if ((SE_ObjectsAreSame(expr,
                interface_template->variable_array[i],&are_same)
                == SE_RETCOD_SUCCESS) && (are_same == SE_TRUE))
            {
                found = SE_TRUE;
                interface_template->var_index_array[i] = SE_TRUE;
            }
            else
            {
                i++;
            }
        }
    }
    if (interface_template2)
        SE_FreeObject(interface_template2);
} /* end check_variable */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_function
 *
 *-----------------------------------------------------------------------------
 */
static void
check_function
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      object,
    SE_FIELDS_PTR                  fields_ptr,
    SE_INTERFACE_TEMPLATE_WRAPPER *interface_template,
    SE_LOCAL_SUMMARY              *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize iterator");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_function:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
            check_expression(level+1, path,
                next_object, next_fields_ptr, interface_template, summary);
        }
        else
        {
            printLastFnctStatus("check_function:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_EXPRESSION, level, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_function */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_expression
 *
 *-----------------------------------------------------------------------------
 */
void
check_expression
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      expr,
    SE_FIELDS_PTR                  fields_ptr,
    SE_INTERFACE_TEMPLATE_WRAPPER *interface_template,
    SE_LOCAL_SUMMARY              *summary
)
{
    char err_msg[512];

    path[level] = fields_ptr->tag;

    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_LITERAL:
             break;
        case SE_CLS_DRM_PREDEFINED_FUNCTION:
        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
             check_function(level, path, expr, fields_ptr,
                 interface_template, summary);
             break;

        case SE_CLS_DRM_VARIABLE:
             if (interface_template)
             {
                 check_variable(level, path, expr, fields_ptr,
                     interface_template);
             }
             else
             {
                 se_message(expr, path[level], level, path,
                    MSGTYP_ERROR, "The context in which this <Variable> appears "\
                    "has no <Interface Template>");
             }
             break;

        default:
             sprintf(err_msg, "$$$ Skipping %s (should be Expression)\n",
                     SE_GetDRMClassString(fields_ptr->tag));

             se_message(expr, path[level], level, path, MSGTYP_ERROR_SYNTAX,
                err_msg);
             break;
    }
} /* end check_expression */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_control_link
 *
 *-----------------------------------------------------------------------------
 */
void
check_control_link
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      object,
    SE_FIELDS_PTR                  fields_ptr,
    SE_INTERFACE_TEMPLATE_WRAPPER *interface_template,
    SE_LOCAL_SUMMARY              *summary
)
{
    SE_Iterator         iter = NULL;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned i = 0, num_exprs=0;
    char                err_msg[256];

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize iterator");
        return;
    }
    i = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_control_link:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
            check_expression(level+1, path, next_object, next_fields_ptr,
                interface_template, summary);
            i++;
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_EXPRESSION, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    num_exprs = i;

    SE_FreeIterator(iter);

    switch (path[level])
    {
        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
             if (i < fields_ptr->u.Property_Set_Index_Control_Link.expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Property_Set_Index_Control_Link.expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
             if (i < fields_ptr->u.CMY_Colour_Control_Link.cyan_expression_index)
             {
                 sprintf(err_msg, "cyan_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.CMY_Colour_Control_Link.cyan_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.CMY_Colour_Control_Link.magenta_expression_index)
             {
                 sprintf(err_msg, "magenta_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.CMY_Colour_Control_Link.magenta_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.CMY_Colour_Control_Link.yellow_expression_index)
             {
                 sprintf(err_msg, "yellow_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.CMY_Colour_Control_Link.yellow_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
             if (i < fields_ptr->u.Colour_Index_Control_Link.colour_index)
             {
                 sprintf(err_msg,
                         "colour_index is %u but only has %u Expression "\
                         "components", (unsigned int) fields_ptr->u.
                         Colour_Index_Control_Link.colour_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Colour_Index_Control_Link.
                 intensity_level_index)
             {
                 sprintf(err_msg, "intensity_level_index is %u but only has "\
                         "%u Expression components", (unsigned int)fields_ptr->
                         u.Colour_Index_Control_Link.intensity_level_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_STATE_CONTROL_LINK:
             if (i < fields_ptr->u.State_Control_Link.expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.State_Control_Link.expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
             if (i < fields_ptr->u.HSV_Colour_Control_Link.hue_expression_index)
             {
                 sprintf(err_msg, "hue_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.HSV_Colour_Control_Link.hue_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.HSV_Colour_Control_Link.saturation_expression_index)
             {
                 sprintf(err_msg, "saturation_expression_index is %u but only has "\
                        "%u Expression components", (unsigned int) fields_ptr->
                        u.HSV_Colour_Control_Link.saturation_expression_index,
                        (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.HSV_Colour_Control_Link.value_expression_index)
             {
                 sprintf(err_msg, "value_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.HSV_Colour_Control_Link.value_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
             if (i < fields_ptr->u.Light_Rendering_Properties_Control_Link.
                 active_expression_index)
             {
                 sprintf(err_msg, "active_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Light_Rendering_Properties_Control_Link.
                         active_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Light_Rendering_Properties_Control_Link.
                 candela_value_expression_index)
             {
                 sprintf(err_msg, "candela_value_expression_index is %u but only "\
                         "has %u Expression components", (unsigned int)
                         fields_ptr->u.Light_Rendering_Properties_Control_Link.
                         candela_value_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Light_Rendering_Properties_Control_Link.
                 lower_candela_value_index)
             {
                 sprintf(err_msg, "lower_candela_value_index is %u but "\
                         "only has %u Expression components", (unsigned int)
                         fields_ptr->u.Light_Rendering_Properties_Control_Link.
                         lower_candela_value_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Light_Rendering_Properties_Control_Link.
                 upper_candela_value_index)
             {
                 sprintf(err_msg, "upper_candela_value_index is %u but "\
                         "only has %u Expression components", (unsigned int)
                         fields_ptr->u.Light_Rendering_Properties_Control_Link.
                         upper_candela_value_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
             if (i < fields_ptr->u.Light_Source_Control_Link.expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Light_Source_Control_Link.expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
             if (i < fields_ptr->u.LSR_3D_Location_Control_Link.u_expression_index)
             {
                 sprintf(err_msg, "u_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.LSR_3D_Location_Control_Link.u_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.LSR_3D_Location_Control_Link.v_expression_index)
             {
                 sprintf(err_msg, "v_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.LSR_3D_Location_Control_Link.v_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.LSR_3D_Location_Control_Link.w_expression_index)
             {
                 sprintf(err_msg, "w_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.LSR_3D_Location_Control_Link.w_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
             if (i < fields_ptr->u.Polygon_Control_Link.hat_test_expression_index)
             {
                 sprintf(err_msg, "hat_test_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Polygon_Control_Link.hat_test_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Polygon_Control_Link.collidible_expression_index)
             {
                 sprintf(err_msg, "collidible_expression_index is %u but only has "\
                         "%u Expression components", (unsigned int)fields_ptr->
                         u.Polygon_Control_Link.collidible_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Polygon_Control_Link.invisible_expression_index)
             {
                 sprintf(err_msg, "invisible_expression_index is %u but only has "\
                         "%u Expression components", (unsigned int)fields_ptr->
                         u.Polygon_Control_Link.invisible_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Polygon_Control_Link.
                 laser_range_finding_expression_index)
             {
                 sprintf(err_msg, "laser_range_finding_expression_index is %u but "\
                         "only has %u Expression components",
                         (unsigned int)fields_ptr->u.Polygon_Control_Link.
                         laser_range_finding_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
             if (i < fields_ptr->u.Property_Table_Reference_Control_Link.
                 expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Property_Table_Reference_Control_Link.expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
             if (i < fields_ptr->u.Reference_Vector_Control_Link.v0_expression_index)
             {
                 sprintf(err_msg, "expression_index_v0 is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Reference_Vector_Control_Link.v0_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Reference_Vector_Control_Link.v1_expression_index)
             {
                 sprintf(err_msg, "expression_index_v1 is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Reference_Vector_Control_Link.v1_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Reference_Vector_Control_Link.v2_expression_index)
             {
                 sprintf(err_msg, "expression_index_v2 is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Reference_Vector_Control_Link.v2_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
             if (i < fields_ptr->u.RGB_Colour_Control_Link.red_expression_index)
             {
                 sprintf(err_msg, "red_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.RGB_Colour_Control_Link.red_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.RGB_Colour_Control_Link.green_expression_index)
             {
                 sprintf(err_msg, "green_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.RGB_Colour_Control_Link.green_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.RGB_Colour_Control_Link.blue_expression_index)
             {
                 sprintf(err_msg, "blue_expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.RGB_Colour_Control_Link.blue_expression_index,
                         (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
             if (i < fields_ptr->u.Rotation_Control_Link.expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Rotation_Control_Link.expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Rotation_Control_Link.lower_expression_index)
             {
                 sprintf(err_msg, "lower_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Rotation_Control_Link.lower_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Rotation_Control_Link.upper_expression_index)
             {
                 sprintf(err_msg, "upper_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Rotation_Control_Link.upper_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_SCALE_CONTROL_LINK:
             if (i < fields_ptr->u.Scale_Control_Link.expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Scale_Control_Link.expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (i < fields_ptr->u.Scale_Control_Link.lower_expression_index)
             {
                 sprintf(err_msg, "lower_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Scale_Control_Link.lower_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }

             if (fields_ptr->u.Scale_Control_Link.upper_expression_index > i)
             {
                 sprintf(err_msg, "upper_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Scale_Control_Link.upper_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
             if (i < fields_ptr->u.Sound_Instance_Control_Link.
                 active_sound_value_expression_index)
             {
                 sprintf(err_msg, "expression_index is %u but only has %u "\
                         "Expression components", (unsigned int) fields_ptr->
                         u.Sound_Instance_Control_Link.
                         active_sound_value_expression_index, (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
             }
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
            if (i < fields_ptr->u.Texture_Coordinate_Control_Link.s_expression_index)
            {
                sprintf(err_msg, "s_expression_index is %u but only has %u "\
                        "Expression components", (unsigned int) fields_ptr->
                        u.Texture_Coordinate_Control_Link.s_expression_index,
                        (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
            }

            if (i < fields_ptr->u.Texture_Coordinate_Control_Link.t_expression_index)
            {
                sprintf(err_msg, "t_expression_index is %u but only has %u "\
                        "Expression components", (unsigned int) fields_ptr->
                        u.Texture_Coordinate_Control_Link.t_expression_index,
                        (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
            }
            break;

        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
            if (i < fields_ptr->u.Translation_Control_Link.expression_index)
            {
                sprintf(err_msg, "expression_index is %u but only has %u "\
                        "Expression components", (unsigned int) fields_ptr->
                        u.Translation_Control_Link.expression_index,
                        (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
            }

            if (i < fields_ptr->u.Translation_Control_Link.lower_expression_index)
            {
                sprintf(err_msg, "lower_index is %u but only has %u "\
                        "Expression components", (unsigned int) fields_ptr->
                        u.Translation_Control_Link.lower_expression_index,
                        (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
            }

            if (i < fields_ptr->u.Translation_Control_Link.upper_expression_index)
            {
                sprintf(err_msg, "upper_index is %u but only has %u "\
                        "Expression components", (unsigned int) fields_ptr->
                        u.Translation_Control_Link.upper_expression_index,
                        (unsigned int) i);
                 se_message(object, path[level], level, path,
                    MSGTYP_ERROR, err_msg);
            }
            break;
    }
} /* end check_control_link */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_LSR_transformation
 *
 *-----------------------------------------------------------------------------
 */
void
check_LSR_transformation
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator iter = NULL;
    SE_Object   next_object = NULL;
    SE_Boolean  got_matrix = SE_FALSE, got_steps = SE_FALSE;

    path[level] = SE_CLS_DRM_LSR_TRANSFORMATION;

    if ((context->srf_context_info.srf_parameters_info.srf_params_info_code !=
         SRM_SRFPARAMINFCOD_TEMPLATE) ||
        (context->srf_context_info.srf_parameters_info.value.srf_template.
         template_code != SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D &&
         context->srf_context_info.srf_parameters_info.value.srf_template.
         template_code != SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "invalid - occurs in non-LSR SRF");
    }

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_LSR_Transformation:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iterator!");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        SE_FIELDS_PTR next_fields_ptr, component_fields_ptr;
        SE_Object     component;

        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_LSR_Transformation:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_LOCAL_4X4:
                     got_matrix = SE_TRUE;
                     break;
                case SE_CLS_DRM_ROTATION:
                case SE_CLS_DRM_SCALE:
                case SE_CLS_DRM_TRANSLATION:
                     got_steps = SE_TRUE;

                     if (SE_GetComponent(next_object,
                           SE_CLS_DRM_CONTROL_LINK, SE_FALSE, SE_FALSE,
                           SE_ITRBEH_RESOLVE, &component, NULL)
                         == SE_RETCOD_SUCCESS)
                     {
                         SE_UpdateAnalysisCounts();

                         if (SE_GetFields(component, GetGlobalTempStore(level),
                              &component_fields_ptr) == SE_RETCOD_SUCCESS)
                         {
                             SE_UpdateLocalSummaryFromFields(summary, component_fields_ptr);
                             check_control_link(
                                 level+1, path, component,
                                 component_fields_ptr,
                                 context->has_variables ?
                                   &(context->interface_template) : NULL,
                                   summary);
                         }
                         else
                         {
                             se_message(next_object, next_fields_ptr->tag,
                                level+1, path, MSGTYP_ERROR,
                                "can't get fields");
                         }
                         SE_FreeObject(component);
                     }

                     if (SE_GetComponent(next_object,
                         SE_CLS_DRM_REFERENCE_VECTOR, SE_FALSE, SE_FALSE,
                         SE_ITRBEH_RESOLVE, &component, NULL)
                         == SE_RETCOD_SUCCESS)
                     {
                         SE_UpdateAnalysisCounts();

                         if (SE_GetFields(component, GetGlobalTempStore(level),
                             &component_fields_ptr) == SE_RETCOD_SUCCESS)
                         {
                             SE_UpdateLocalSummaryFromFields(summary, component_fields_ptr);
                             check_reference_vector(level+1, path,
                                 component, component_fields_ptr,
                                 context, summary);
                         }
                         else
                         {
                             se_message(next_object, SE_CLS_DRM_REFERENCE_VECTOR,
                                level+1, path, MSGTYP_ERROR,
                                "can't get fields");
                         }
                         SE_FreeObject(component);
                     }
                     break;

                default:
                     se_message(next_object, next_fields_ptr->tag, level+1,
                        path, MSGTYP_ERROR_SYNTAX, "not a legal component of "\
                        "<LSR Transformation>");
                     break;
            }
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    if (!got_matrix && !got_steps)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Violates <<LSR Transformation Components>>");
    }
} /* end check_LSR_transformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_world_transformation
 *
 *-----------------------------------------------------------------------------
 */
void
check_world_transformation
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object location = NULL, location_3x3 = NULL, world_3x3 = NULL;

    path[level] = SE_CLS_DRM_WORLD_TRANSFORMATION;

    if (SE_GetComponent(object, SE_CLS_DRM_LOCATION, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &location, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR loc_fields = NULL;

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
            printLastFnctStatus("check_world_transformation:SE_GetFields");
            se_message(location, loc_fields->tag, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
    }
    else
    {
        printLastFnctStatus("check_world_transformation:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't get <Location> component");
    }

    if (SE_GetComponent(object, SE_CLS_DRM_WORLD_3X3, SE_FALSE, SE_FALSE,
        SE_ITRBEH_RESOLVE, &world_3x3, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetComponent(object, SE_CLS_DRM_LOCATION, SE_FALSE, SE_FALSE,
            SE_ITRBEH_RESOLVE, &location_3x3, NULL) == SE_RETCOD_SUCCESS)
        {
            SE_Boolean locs_match = SE_FALSE;

            if (location != NULL)
            {
                if (SE_ObjectsAreSame(location, location_3x3, &locs_match)
                    != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_world_transformation:SE_ObjectsAreSame");
                }
                else if (locs_match != SE_TRUE)
                {
                    se_message(world_3x3, SE_CLS_DRM_WORLD_3X3, level+1, path,
                       MSGTYP_ERROR,
                       "has directly attached <Location> component "\
                       "that isn't the parent <World Transformation>'s "\
                       "<Location> component");
                }
            }
            else
            {
                SE_FIELDS_PTR loc_fields = NULL;

                path[level+1] = SE_CLS_DRM_WORLD_3X3;
                if (SE_GetFields(location_3x3, GetGlobalStore(level),
                    &loc_fields) == SE_RETCOD_SUCCESS)
                {
                    SE_UpdateLocalSummaryFromFields(summary, loc_fields);
                    check_location(level+2, path, location_3x3, loc_fields,
                        NULL, context, summary);
                }
                else
                {
                    printLastFnctStatus
                    ("check_world_transformation:SE_GetFields");
                    se_message(location_3x3, loc_fields->tag, level+2, path,
                       MSGTYP_ERROR, "Can't get fields");
                }
            }
            SE_FreeObject(location_3x3);
        }
        SE_FreeObject(world_3x3);
    }
    if (location)
        SE_FreeObject(location);
} /* end check_world_transformation */
