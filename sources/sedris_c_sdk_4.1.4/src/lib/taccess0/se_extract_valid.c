/*
 * FILE       : se_extract_valid.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
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
 * FUNCTION: SE_ValidDataTableSignature
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_ValidDataTableSignature
(
          SE_Integer_Positive element_count,
    const SE_Integer_Positive table_prop_descript_number[]
)
{
    SE_Status_Code      status = SE_STATCODE_SUCCESS;
    SE_Integer_Unsigned i,j;

    if (!element_count || !table_prop_descript_number)
        status = SE_STATCODE_INACTIONABLE_FAILURE;

    for (i=0;
         (status == SE_STATCODE_SUCCESS) &&
         (i < (SE_Integer_Unsigned)element_count); i++)
    {
        for (j=i+1;
             (status == SE_STATCODE_SUCCESS) &&
             (j < (SE_Integer_Unsigned)element_count); j++)
        {
            if (table_prop_descript_number[i] ==
                table_prop_descript_number[j])
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
    }
    return status;
} /* end SE_ValidDataTableSignature */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageExtents
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageExtents
(
    const SE_Image_Fields            *fields_ptr,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level
)
{
    SE_Boolean result = SE_TRUE;

    if (!fields_ptr || !start_texel || !stop_texel ||
        !fields_ptr->level_count || !fields_ptr->mip_extents_array ||
        (mip_level > fields_ptr->level_count))
    {
        result = SE_FALSE;
    }
    else
    {
        const SE_Image_MIP_Extents *mip_extents_ptr =
                            &fields_ptr->mip_extents_array[mip_level];

        if ((start_texel->horizontal >= mip_extents_ptr->size_horizontal) ||
            (stop_texel->horizontal  >= mip_extents_ptr->size_horizontal) ||
            (start_texel->horizontal >  stop_texel->horizontal) ||
            (start_texel->vertical   >= mip_extents_ptr->size_vertical) ||
            (stop_texel->vertical    >= mip_extents_ptr->size_vertical) ||
            (start_texel->vertical   >  stop_texel->vertical) ||
            (fields_ptr->data_is_3D &&
              ((start_texel->z >= mip_extents_ptr->size_z) ||
               (stop_texel->z  >= mip_extents_ptr->size_z) ||
               (start_texel->z >  stop_texel->z)))
           )
        {
            result = SE_FALSE;
        }
    }
    return result;
} /* end SE_ValidImageExtents */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidObjectLabel
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidObjectLabel
(
    const SE_String *object_label_in
)
{
    SE_Boolean result = SE_TRUE;

    if (SE_ValidString(object_label_in, SE_FALSE, NULL) != SE_TRUE)
    {
        result = SE_FALSE;
    }
    else if (object_label_in->length < 1)
    {
        result = SE_FALSE;
    }
    else if (!isalpha(object_label_in->characters[0]))
    {
        result = SE_FALSE;
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 1; result && (i < object_label_in->length); i++)
        {
            if (!isalnum(object_label_in->characters[i]) &&
                (object_label_in->characters[i] != '_'))
            {
                result = SE_FALSE;
            }
        }
    }
    return result;
} /* end SE_ValidObjectLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSingleSearchRule
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
SE_ValidSingleSearchRule
(
    const SE_Search_Rule      *rule_ptr,
          FILE                *f_ptr,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean result = SE_TRUE;

    switch (rule_ptr->rule_type)
    {
        case SE_SEARCHRULETYP_END:
        case SE_SEARCHRULETYP_AND:
        case SE_SEARCHRULETYP_OBJECT_AND:
        case SE_SEARCHRULETYP_OR:
        case SE_SEARCHRULETYP_NOT:
        case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
             break;

        case SE_SEARCHRULETYP_PREDICATE:
             if (rule_ptr->user_function == NULL)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but user_function == NULL!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_DRM_CLASS:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_FIELD:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (rule_ptr->value_ptr == NULL)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_ptr == NULL!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_ValidSearchValueType(rule_ptr->value_type))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_type == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int) rule_ptr->value_type);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_FIELD_RANGE:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!rule_ptr->value_ptr && !rule_ptr->second_value_ptr)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type ="\
                             " %s\n    but upper and lower bound are"\
                             " both NULL!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_ValidSearchValueType(rule_ptr->value_type) ||
                      (rule_ptr->value_type == SE_SEARCHVALTYP_ENUMERATED))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_type == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int) rule_ptr->value_type);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if ((rule_ptr->value_type != SE_SEARCHVALTYP_STRING) &&
                     (rule_ptr->value_type != SE_SEARCHVALTYP_SET) &&
                     (!rule_ptr->value_ptr || !rule_ptr->second_value_ptr))
                 result = SE_FALSE;
             break;

        case SE_SEARCHRULETYP_FIELD_ARRAY:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (rule_ptr->value_ptr == NULL)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_ptr == NULL!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (rule_ptr->value_array_length == 0)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_array_length == 0!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_ValidSearchValueType(rule_ptr->value_type))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_type == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int) rule_ptr->value_type);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_COMPONENT:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if ((rule_ptr->component_object_drm_class == SE_CLS_DRM_NULL) ||
                      !SE_ValidDRMClass(rule_ptr->component_object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but component_object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->component_object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if ((rule_ptr->component_object_drm_class == SE_CLS_DRM_NULL) ||
                      !SE_ValidDRMClass(rule_ptr->component_object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but component_object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->component_object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (rule_ptr->value_ptr == NULL)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_ptr == NULL!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_ValidSearchValueType(rule_ptr->value_type))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_type == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int) rule_ptr->value_type);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if ((rule_ptr->component_object_drm_class == SE_CLS_DRM_NULL) ||
                      !SE_ValidDRMClass(rule_ptr->component_object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but component_object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)
                             rule_ptr->component_object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_ValidSearchValueType(rule_ptr->value_type) ||
                      (rule_ptr->value_type ==
                       SE_SEARCHVALTYP_ENUMERATED))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_type == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int) rule_ptr->value_type);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if ((rule_ptr->value_type != SE_SEARCHVALTYP_STRING) &&
                     (rule_ptr->value_type != SE_SEARCHVALTYP_SET) &&
                     (!rule_ptr->value_ptr || !rule_ptr->second_value_ptr))
                 result = SE_FALSE;
             break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if ((rule_ptr->component_object_drm_class == SE_CLS_DRM_NULL) ||
                      !SE_ValidDRMClass(rule_ptr->component_object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but component_object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->component_object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (rule_ptr->value_ptr == NULL)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_ptr == NULL!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (rule_ptr->value_array_length == 0)
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_array_length == 0!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_ValidSearchValueType(rule_ptr->value_type))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but value_type == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int) rule_ptr->value_type);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        case SE_SEARCHRULETYP_ASSOCIATE:
             if ((rule_ptr->object_drm_class == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(rule_ptr->object_drm_class))
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: rule_type"\
                             " = %s but object_drm_class == %u!\n",
                             SE_PrintSearchRuleType(rule_ptr->rule_type),
                             (unsigned int)rule_ptr->object_drm_class);
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             else if (!SE_IncomingAssociationsLegal[rule_ptr->object_drm_class])
             {
                 result = SE_FALSE;
                 if (f_ptr)
                 {
                     fprintf(f_ptr, "SE_ValidSingleSearchRule: object_drm_class"\
                             " (%s) cannot have incoming associations!\n",
                             SE_PrintDRMClass(rule_ptr->object_drm_class));
                 }
                 if (error_count_ptr) (*error_count_ptr)++;
             }
             break;

        default:
             result = SE_FALSE;
             if (f_ptr)
             {
                 fprintf(f_ptr, "SE_ValidSingleSearchRule:"\
                         " invalid rule_type = %u!\n",
                         (unsigned int)rule_ptr->rule_type);
             }
             if (error_count_ptr) (*error_count_ptr)++;
             break;
    }
    return result;
} /* end SE_ValidSingleSearchRule */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchRule
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSearchRule
(
    const SE_Search_Rule        rules[],
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean           result = SE_TRUE;
    SE_Integer_Unsigned  i, stack_count;
    FILE                *f_ptr  = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (rules == NULL)
    {
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidSearchRule: NULL rules!\n");
        }
        if (error_count_ptr) (*error_count_ptr)++;

        return SE_FALSE;
    }

    stack_count = 0;
    for (i = 0; (rules[i].rule_type != SE_SEARCHRULETYP_END) && result; i++)
    {
        const SE_Search_Rule *rule_ptr = &rules[i];

        result = SE_ValidSingleSearchRule(rule_ptr, f_ptr, error_count_ptr);

        if (result)
        {
            switch (rule_ptr->rule_type)
            {
                case SE_SEARCHRULETYP_AND:
                case SE_SEARCHRULETYP_OBJECT_AND:
                case SE_SEARCHRULETYP_OR:
                     if (stack_count < 2)
                     {
                         result = SE_FALSE;
                         if (f_ptr)
                         {
                             fprintf(f_ptr, "SE_ValidSingleSearchRule:"\
                                     " rule_type = %s but less than 2"\
                                     " arguments!\n",
                                     SE_PrintSearchRuleType
                                     (rule_ptr->rule_type));
                         }
                         if (error_count_ptr) (*error_count_ptr)++;
                     }
                     else
                     {
                         stack_count--;
                        /*
                         * equivalent of removing the 2 arguments from
                         * the stack and pushing their result onto the stack
                         */
                     }
                     break;

                case SE_SEARCHRULETYP_NOT:
                    /*
                     * Check that the argument is present. If it is, we
                     * don't need to change the stack count (equivalent
                     * to popping the argument & pushing the result).
                     */
                     if (stack_count < 1)
                     {
                         result = SE_FALSE;
                         if (f_ptr)
                         {
                             fprintf(f_ptr, "SE_ValidSingleSearchRule:"\
                                     " rule_type = %s but no arguments!\n",
                                     SE_PrintSearchRuleType
                                     (rule_ptr->rule_type));
                         }
                         if (error_count_ptr) (*error_count_ptr)++;
                     }
                     break;

                case SE_SEARCHRULETYP_END:
                     break;

                default:
                     stack_count++;
                     break;
            }
        }
    }
    if (result && (stack_count != 1))
    {
        result = SE_FALSE;
    }
    return result;
} /* end SE_ValidSearchRule */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTransmittalName
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTransmittalName
(
    const SE_URN *transmittal_name_in
)
{
    return SE_ValidURN(transmittal_name_in, SE_FALSE, NULL);
} /* end SE_ValidTransmittalName */
