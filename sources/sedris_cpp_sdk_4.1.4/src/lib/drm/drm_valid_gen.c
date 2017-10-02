/*
 * FILE       : drm_valid_gen.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains validating functions for all SEDRIS types, and for
 *   an object's fields.
 *
 *   A type's validating function checks that:
 *   - any enumerators have valid values
 *   - any array that is allocated at run-time is non-NULL if
 *     it has a non-zero array count
 *
 *   Some types do not have validating functions because they
 *   contain nothing that can be checked. For a struct type,
 *   the corresponding validating function will check only
 *   those fields that need validating.
 *
 *   These functions are intended for use by any application
 *   in order to insure that a given variable has valid values;
 *   for example, SE_ValidDRMClassFields() may be used by applications
 *   that check that transmittals are valid, e.g. syntax_checker.
 *
 * - DRM spec. 4.1
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
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
#include "drm.h"


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_GetEQForElement
 *
 *-----------------------------------------------------------------------------
 */
static void
local_GetEQForElement
(
    const SE_Element_Type            *element_ptr,
          EDCS_Unit_Equivalence_Code *eq_ptr,
          SE_Boolean                  print_error,
          FILE                       *f_ptr
)
{
    const EDCS_Attribute_Dictionary_Entry *entry_ptr = NULL;
    const EDCS_Unit_Dictionary_Entry      *var_unit_entry_ptr = NULL;
          EDCS_Unit_Code                   var_unit = EUC_UNITLESS;

    *eq_ptr = EQC_PURE_NUMBER;

   /*
    * SE_ValidDRMClassFields already validated element_ptr at this point
    */
    switch (element_ptr->code_type)
    {
        case SE_ELEMTYPCOD_ATTRIBUTE:
             if (EDCS_GetEADictionaryEntry(element_ptr->code.attribute,
                 &entry_ptr) == EDCS_SC_SUCCESS)
             {
                 /* Only need to set eq_ptr if EA type is EDCS_AVT_REAL */
                 if(entry_ptr->value_type == EDCS_AVT_REAL)
                 {
                     *eq_ptr = entry_ptr->eq_class;
                 }
             }
             else
             {
                 if (print_error)
                 {
                     fprintf(f_ptr,
                         "SE_ValidDRMClassFields, local_GetEQForElement: "\
                         "corruption detected, "\
                         "EDCS_GetEADictionaryEntry failed for valid EA\n");
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_ELEMTYPCOD_VARIABLE:
             switch (element_ptr->code.variable)
             {
                 case SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE:
                      var_unit = EUC_CANDELA;
                      break;

                 case SE_VARCOD_LSR_3D_LOCATION_U:
                 case SE_VARCOD_LSR_3D_LOCATION_V:
                 case SE_VARCOD_LSR_3D_LOCATION_W:
                 case SE_VARCOD_SCALE_AMOUNT:
                 case SE_VARCOD_TRANSLATION_AMOUNT:
                      var_unit = EUC_METRE;
                      break;

                 case SE_VARCOD_ROTATION_ANGLE:
                      var_unit = EUC_DEGREE_ARC;
                      break;

                 case SE_VARCOD_TRANSLUCENCY_VALUE:
                      var_unit = EUC_PERCENT;
                      break;

                 default:
                      break;
             }
             if ((var_unit != EUC_UNITLESS) &&
                 (EDCS_GetEUDictionaryEntry(var_unit, &var_unit_entry_ptr)
                  == EDCS_SC_SUCCESS))
             {
                 *eq_ptr = var_unit_entry_ptr->eq_code;
             }
             break;

        case SE_ELEMTYPCOD_INDEX:
        default:
             break;
    }
} /* end local_GetEQForElement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_GetEQForProperty
 *
 *-----------------------------------------------------------------------------
 */
static void
local_GetEQForProperty
(
    const SE_Property_Code           *property_ptr,
          EDCS_Unit_Equivalence_Code *eq_ptr,
          SE_Boolean                  print_error,
          FILE                       *f_ptr
)
{
    const EDCS_Attribute_Dictionary_Entry *entry_ptr = NULL;
    const EDCS_Unit_Dictionary_Entry      *var_unit_entry_ptr = NULL;
          EDCS_Unit_Code                   var_unit = EUC_UNITLESS;

    *eq_ptr = EQC_PURE_NUMBER;

   /*
    * SE_ValidDRMClassFields already validated property_ptr at this point
    */
    switch (property_ptr->code_type)
    {
        case SE_PROPCODTYP_ATTRIBUTE:
             if (EDCS_GetEADictionaryEntry(property_ptr->code.attribute,
                 &entry_ptr) == EDCS_SC_SUCCESS)
             {
                 /* Only need to set eq_ptr if EA type is EDCS_AVT_REAL */
                 if(entry_ptr->value_type == EDCS_AVT_REAL)
                 {
                     *eq_ptr = entry_ptr->eq_class;
                 }
             }
             else
             {
                 if (print_error)
                 {
                     fprintf(f_ptr,
                             "SE_ValidDRMClassFields, local_GetEQForProperty: "\
                             "corruption detected, "\
                             "EDCS_GetEADictionaryEntry failed for valid EA\n");
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_PROPCODTYP_VARIABLE:
             switch (property_ptr->code.variable)
             {
                 case SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE:
                      var_unit = EUC_CANDELA;
                      break;

                 case SE_VARCOD_LSR_3D_LOCATION_U:
                 case SE_VARCOD_LSR_3D_LOCATION_V:
                 case SE_VARCOD_LSR_3D_LOCATION_W:
                 case SE_VARCOD_SCALE_AMOUNT:
                 case SE_VARCOD_TRANSLATION_AMOUNT:
                      var_unit = EUC_METRE;
                      break;

                 case SE_VARCOD_ROTATION_ANGLE:
                      var_unit = EUC_DEGREE_ARC;
                      break;

                 case SE_VARCOD_TRANSLUCENCY_VALUE:
                      var_unit = EUC_PERCENT;
                      break;

                 default:
                      break;
             }
             if ((var_unit != EUC_UNITLESS) &&
                 (EDCS_GetEUDictionaryEntry(var_unit, &var_unit_entry_ptr)
                  == EDCS_SC_SUCCESS))
             {
                 *eq_ptr = var_unit_entry_ptr->eq_code;
             }
             break;

        default:
             break;
    }
} /* end local_GetEQForProperty */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_SpecialTypeForProperty
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_SpecialTypeForProperty
(
    const SE_Property_Code     *code_ptr,
    const EDCS_Attribute_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr,
          SE_Boolean           *main_result_out_ptr,
          FILE                 *f_ptr
)
{
          SE_Boolean                       result = SE_FALSE;
    const EDCS_Attribute_Dictionary_Entry *ea_entry_ptr = NULL;

    switch (code_ptr->code_type)
    {
        case SE_PROPCODTYP_ATTRIBUTE:
             if (EDCS_GetEADictionaryEntry(code_ptr->code.attribute,
                 &ea_entry_ptr) == EDCS_SC_SUCCESS)
             {
                 if ((ea_entry_ptr->value_type == EDCS_AVT_ENUMERATION)
                  && (value_ptr->attribute_value_type == EDCS_AVT_INTEGER))
                 {
                     result = SE_TRUE;
                 }
             }
             else
             {
                 result = SE_TRUE;
             }
             break;
        case SE_PROPCODTYP_VARIABLE:
             switch (code_ptr->code.variable)
             {
                 case SE_VARCOD_ACTIVE_STATE_VALUE:
                 case SE_VARCOD_CLR_INDEX:
                 case SE_VARCOD_CLR_INTENSITY_LEVEL:
                 case SE_VARCOD_GEOMETRY_TEXTURE:
                 case SE_VARCOD_HEAT_PRODUCTION:
                 case SE_VARCOD_PROPERTY_SET_INDEX:
                 case SE_VARCOD_PROP_TABLE_REF_ON_AXIS:
                     break;

                 case SE_VARCOD_LIGHT_SOURCE_ACTIVE:
                 case SE_VARCOD_LGT_RENDER_PROP_ACTIVE:
                 case SE_VARCOD_POLY_FLAGS_COLLIDIBLE:
                 case SE_VARCOD_POLY_FLAGS_HAT_TEST:
                 case SE_VARCOD_POLY_FLAGS_INVISIBLE:
                 case SE_VARCOD_POLY_FLAGS_LASER_RNG_FIND:
                 case SE_VARCOD_SOUND_INSTANCE_ACTIVE:
                     if (value_ptr->attribute_value_type != EDCS_AVT_BOOLEAN)
                     {
                        result = SE_TRUE;
                        *main_result_out_ptr = SE_FALSE;
                        if (error_count_ptr)
                            (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr,
                             "Error in SE_ValidDRMClassFields, "\
                             "local_SpecialTypeForProperty: "\
                             "<Property Value>'s code (BOOLEAN) doesn't "\
                             "match value.attribute_value_type!\n");
                     }
                     break;

                 case SE_VARCOD_CLR_COORDINATE_1:
                 case SE_VARCOD_CLR_COORDINATE_2:
                 case SE_VARCOD_CLR_COORDINATE_3:
                 case SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE:
                 case SE_VARCOD_LSR_3D_LOCATION_U:
                 case SE_VARCOD_LSR_3D_LOCATION_V:
                 case SE_VARCOD_LSR_3D_LOCATION_W:
                 case SE_VARCOD_REF_VEC_V0:
                 case SE_VARCOD_REF_VEC_V1:
                 case SE_VARCOD_REF_VEC_V2:
                 case SE_VARCOD_ROTATION_ANGLE:
                 case SE_VARCOD_SCALE_AMOUNT:
                 case SE_VARCOD_TEXTURE_COORD_S:
                 case SE_VARCOD_TEXTURE_COORD_T:
                 case SE_VARCOD_TRANSLATION_AMOUNT:
                 case SE_VARCOD_TRANSLUCENCY_VALUE:
                     if (value_ptr->attribute_value_type != EDCS_AVT_REAL)
                     {
                        result = SE_TRUE;
                        *main_result_out_ptr = SE_FALSE;
                        if (error_count_ptr)
                            (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr,
                             "Error in SE_ValidDRMClassFields, "\
                             "local_SpecialTypeForProperty: "\
                             "<Property Value>'s code (REAL) doesn't "\
                             "match value.attribute_value_type!\n");
                     }
                     break;

                 default:
                     break;
             } /* end switch */
             break;
        default:
             break;
    } /* end switch */
    return result;
} /* end local_SpecialTypeForProperty */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_ValidValueTypeForVariableCode
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_ValidValueTypeForVariableCode
(
    SE_Variable_Code           var_code,
    EDCS_Attribute_Value_Type  value_type,
    SE_Boolean                 print_error,
    FILE                      *f_ptr
)
{
    SE_Boolean result = SE_TRUE;

    switch (var_code)
    {
        case SE_VARCOD_ACTIVE_STATE_VALUE:
             if ((value_type != EDCS_AVT_BOOLEAN)
              && (value_type != EDCS_AVT_REAL)
              && (value_type != EDCS_AVT_ENUMERATION))
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                 "SE_ValidDRMClassFields, local_ValidValueTypeForVariableCode: "\
                 "%s requires either Boolean, single real, or ENUMERATION value_type but has %s\n",
                     SE_PrintVariableCode(var_code),
                     EDCS_PrintAttributeValueType(value_type));
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_VARCOD_CLR_INDEX:
        case SE_VARCOD_PROPERTY_SET_INDEX:
        case SE_VARCOD_PROP_TABLE_REF_ON_AXIS:
             if (value_type != EDCS_AVT_COUNT)
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                       "SE_ValidDRMClassFields, local_ValidValueTypeForVariableCode: "\
                       "%s requires single count value_type but has %s\n",
                       SE_PrintVariableCode(var_code),
                       EDCS_PrintAttributeValueType(value_type));
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_VARCOD_POLY_FLAGS_COLLIDIBLE:
        case SE_VARCOD_POLY_FLAGS_HAT_TEST:
        case SE_VARCOD_POLY_FLAGS_INVISIBLE:
        case SE_VARCOD_POLY_FLAGS_LASER_RNG_FIND:
        case SE_VARCOD_SOUND_INSTANCE_ACTIVE:
             if (value_type != SE_DTDATAVALTYP_BOOLEAN)
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                       "SE_ValidDRMClassFields, local_ValidValueTypeForVariableCode: "\
                       "%s requires Boolean value_type but has %s\n",
                       SE_PrintVariableCode(var_code),
                       EDCS_PrintAttributeValueType(value_type));
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_VARCOD_CLR_COORDINATE_1:
        case SE_VARCOD_CLR_COORDINATE_2:
        case SE_VARCOD_CLR_COORDINATE_3:
        case SE_VARCOD_CLR_INTENSITY_LEVEL:
        case SE_VARCOD_GEOMETRY_TEXTURE:
        case SE_VARCOD_HEAT_PRODUCTION:
        case SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE:
        case SE_VARCOD_LIGHT_SOURCE_ACTIVE:
        case SE_VARCOD_LGT_RENDER_PROP_ACTIVE:
        case SE_VARCOD_LSR_3D_LOCATION_U:
        case SE_VARCOD_LSR_3D_LOCATION_V:
        case SE_VARCOD_LSR_3D_LOCATION_W:
        case SE_VARCOD_REF_VEC_V0:
        case SE_VARCOD_REF_VEC_V1:
        case SE_VARCOD_REF_VEC_V2:
        case SE_VARCOD_ROTATION_ANGLE:
        case SE_VARCOD_SCALE_AMOUNT:
        case SE_VARCOD_TEXTURE_COORD_S:
        case SE_VARCOD_TEXTURE_COORD_T:
        case SE_VARCOD_TRANSLATION_AMOUNT:
        case SE_VARCOD_TRANSLUCENCY_VALUE:
             if (value_type != EDCS_AVT_REAL)
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                       "SE_ValidDRMClassFields, local_ValidValueTypeForVariableCode: "\
                       "%s requires single real value_type but has %s\n",
                       SE_PrintVariableCode(var_code),
                       EDCS_PrintAttributeValueType(value_type));
                     fflush(f_ptr);
                 }
             }
             break;

        default:
             result = SE_FALSE;
             if (print_error)
             {
                 fprintf(f_ptr,
                 "SE_ValidDRMClassFields, local_ValidValueTypeForVariableCode: "\
                 "unrecognized SE_Variable_Code meaning %s!\n",
                 SE_PrintVariableCode(var_code));
                 fflush(f_ptr);
             }
             break;
    }
    return result;
} /* end local_ValidValueTypeForVariableCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_ValidValueTypeForElement
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_ValidValueTypeForElement
(
    const SE_Element_Type               *element_ptr,
          SE_Data_Table_Data_Value_Type  value_type,
          SE_Boolean                     print_error,
          FILE                          *f_ptr
)
{
          SE_Boolean                       result = SE_TRUE;
    const EDCS_Attribute_Dictionary_Entry *ea_entry_ptr = NULL;

   /*
    * SE_ValidDRMClassFields already validated element_ptr at this point
    */
    switch (element_ptr->code_type)
    {
        case SE_ELEMTYPCOD_ATTRIBUTE:
             if (EDCS_GetEADictionaryEntry(element_ptr->code.attribute,
                 &ea_entry_ptr) == EDCS_SC_SUCCESS)
             {
                 switch (ea_entry_ptr->value_type)
                 {
                     case EDCS_AVT_REAL:
                          if ((value_type != SE_DTDATAVALTYP_SINGLE_LONG_FLOAT)
                           && (value_type != SE_DTDATAVALTYP_LONG_FLOAT)
                           && (value_type != SE_DTDATAVALTYP_SINGLE_INTEGER)
                           && (value_type != SE_DTDATAVALTYP_INTEGER)
                           && (value_type != SE_DTDATAVALTYP_SINGLE_COUNT)
                           && (value_type != SE_DTDATAVALTYP_COUNT))
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires a numeric value_type\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_INTEGER:
                          if ((value_type != SE_DTDATAVALTYP_SINGLE_INTEGER)
                           && (value_type != SE_DTDATAVALTYP_INTEGER))
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_SINGLE_INTEGER or "\
                               "SE_DTDATAVALTYP_INTEGER\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_COUNT:
                          if ((value_type != SE_DTDATAVALTYP_SINGLE_COUNT)
                           && (value_type != SE_DTDATAVALTYP_COUNT))
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_SINGLE_COUNT or "\
                               "SE_DTDATAVALTYP_COUNT\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_INDEX:
                          if (value_type != SE_DTDATAVALTYP_INDEX)
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_INDEX\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_STRING:
                          if (value_type != SE_DTDATAVALTYP_STRING)
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_STRING\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_CONSTRAINED_STRING:
                          if (value_type != SE_DTDATAVALTYP_CONSTRAINED_STRING)
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_CONSTRAINED_STRING\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_KEY:
                          if (value_type != SE_DTDATAVALTYP_KEY)
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_KEY\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_ENUMERATION:
                          if ((value_type != SE_DTDATAVALTYP_ENUMERATION)
                           && (value_type != SE_DTDATAVALTYP_SINGLE_INTEGER))
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_ENUMERATION or "\
                               "SE_DTDATAVALTYP_SINGLE_INTEGER\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     case EDCS_AVT_BOOLEAN:
                          if (value_type != SE_DTDATAVALTYP_BOOLEAN)
                          {
                              result = SE_FALSE;
                              if (print_error)
                              {
                                  fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires value_type "\
                               "SE_DTDATAVALTYP_BOOLEAN\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                                  fflush(f_ptr);
                              }
                          }
                          break;
                     default:
                          result = SE_FALSE;
                          if (print_error)
                          {
                              fprintf(f_ptr,
                               "SE_ValidDRMClassFields, "\
                               "local_ValidValueTypeForElement: "\
                               "meaning (%s) requires recognized value_type\n",
                     EDCS_PrintAttributeCode(element_ptr->code.attribute));
                              fflush(f_ptr);
                          }
                          break;
                 }
             }
             else
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                         "SE_ValidDRMClassFields, local_ValidValueTypeForElement: "\
                         "corruption detected, "\
                         "EDCS_GetEADictionaryEntry failed for valid EA\n");
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_ELEMTYPCOD_VARIABLE:
             switch (value_type)
             {
                 case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
                      result = local_ValidValueTypeForVariableCode
                               (element_ptr->code.variable,
                                EDCS_AVT_REAL, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_SINGLE_INTEGER:
                      result = local_ValidValueTypeForVariableCode
                               (element_ptr->code.variable,
                                EDCS_AVT_INTEGER, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_SINGLE_COUNT:
                      result = local_ValidValueTypeForVariableCode
                               (element_ptr->code.variable,
                                EDCS_AVT_COUNT, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_ENUMERATION:
                      result = local_ValidValueTypeForVariableCode
                               (element_ptr->code.variable,
                                EDCS_AVT_ENUMERATION, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_BOOLEAN:
                      result = local_ValidValueTypeForVariableCode
                               (element_ptr->code.variable,
                                EDCS_AVT_BOOLEAN, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_COUNT:
                 case SE_DTDATAVALTYP_INDEX:
                 case SE_DTDATAVALTYP_INTEGER:
                 case SE_DTDATAVALTYP_LONG_FLOAT:
                 case SE_DTDATAVALTYP_STRING:
                 case SE_DTDATAVALTYP_CONSTRAINED_STRING:
                 case SE_DTDATAVALTYP_KEY:
                 case SE_DTDATAVALTYP_INDEX_CODE:
                 default:
                      result = SE_FALSE;
                      if (print_error)
                      {
                          fprintf(f_ptr,
              "SE_ValidDRMClassFields, local_ValidValueTypeForElement: "\
              "<Table Property Description> is bound to SE_ELEMTYPCOD_VARIABLE "\
              "but its value_type is either not single or not valid for any "\
              "SE_Variable_Code!\n");
                          fflush(f_ptr);
                      }
                      break;
             }
             break;

        case SE_ELEMTYPCOD_INDEX:
             if (value_type != SE_DTDATAVALTYP_INDEX_CODE)
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                    "SE_ValidDRMClassFields, local_ValidValueTypeForElement: "\
                    "<Table Property Description> is bound to SE_ELEMTYPCOD_INDEX "\
                    "but its value_type is not SE_DTDATAVALTYP_INDEX_CODE!\n");
                     fflush(f_ptr);
                 }
             }
             break;

        default:
             result = SE_FALSE;
             if (print_error)
             {
                 fprintf(f_ptr,
               "SE_ValidDRMClassFields, local_ValidValueTypeForElement: "\
               "<Table Property Description> is bound to an invalid meaning!\n");
                 fflush(f_ptr);
             }
             break;
    }
    return result;
} /* end local_ValidValueTypeForElement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_ValidValueTypeForProperty
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_ValidValueTypeForProperty
(
    const SE_Property_Code          *property_ptr,
          EDCS_Attribute_Value_Type  value_type,
          SE_Boolean                 print_error,
          FILE                      *f_ptr
)
{
          SE_Boolean                       result = SE_TRUE;
    const EDCS_Attribute_Dictionary_Entry *ea_entry_ptr = NULL;

   /*
    * SE_ValidDRMClassFields already validated property_ptr at this point
    */
    switch (property_ptr->code_type)
    {
        case SE_PROPCODTYP_ATTRIBUTE:
             if (EDCS_GetEADictionaryEntry(property_ptr->code.attribute,
                 &ea_entry_ptr) == EDCS_SC_SUCCESS)
             {
                 if (ea_entry_ptr->value_type != value_type)
                 {
                     result = SE_FALSE;
                     if (print_error)
                     {
                         fprintf(f_ptr,
                     "SE_ValidDRMClassFields, local_ValidValueTypeForProperty: "\
                     "meaning (%s) requires value_type %s",
                     EDCS_PrintAttributeCode(property_ptr->code.attribute),
                     EDCS_PrintAttributeValueType(ea_entry_ptr->value_type));
                         fprintf(f_ptr,
                     " but has %s\n",
                     EDCS_PrintAttributeValueType(value_type));
                         fflush(f_ptr);
                     }
                 }
             }
             else
             {
                 result = SE_FALSE;
                 if (print_error)
                 {
                     fprintf(f_ptr,
                         "SE_ValidDRMClassFields, "\
                         "local_ValidValueTypeForProperty: "\
                         "corruption detected, "\
                         "EDCS_GetEADictionaryEntry failed for valid EA\n");
                     fflush(f_ptr);
                 }
             }
             break;

        case SE_PROPCODTYP_VARIABLE:
             switch (value_type)
             {
                 case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
                      result = local_ValidValueTypeForVariableCode
                               (property_ptr->code.variable,
                                EDCS_AVT_REAL, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_SINGLE_INTEGER:
                      result = local_ValidValueTypeForVariableCode
                               (property_ptr->code.variable,
                                EDCS_AVT_INTEGER, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_SINGLE_COUNT:
                      result = local_ValidValueTypeForVariableCode
                               (property_ptr->code.variable,
                                EDCS_AVT_COUNT, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_ENUMERATION:
                      result = local_ValidValueTypeForVariableCode
                               (property_ptr->code.variable,
                                EDCS_AVT_ENUMERATION, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_BOOLEAN:
                      result = local_ValidValueTypeForVariableCode
                               (property_ptr->code.variable,
                                EDCS_AVT_BOOLEAN, print_error, f_ptr);
                      break;
                 case SE_DTDATAVALTYP_COUNT:
                 case SE_DTDATAVALTYP_INDEX:
                 case SE_DTDATAVALTYP_INTEGER:
                 case SE_DTDATAVALTYP_LONG_FLOAT:
                 case SE_DTDATAVALTYP_STRING:
                 case SE_DTDATAVALTYP_CONSTRAINED_STRING:
                 case SE_DTDATAVALTYP_KEY:
                 case SE_DTDATAVALTYP_INDEX_CODE:
                 default:
                      result = SE_FALSE;
                      if (print_error)
                      {
                          fprintf(f_ptr,
              "SE_ValidDRMClassFields, local_ValidValueTypeForProperty: "\
              "object is bound to SE_PROPCODTYP_VARIABLE "\
              "but its value_type is either not single or not valid for any "\
              "SE_Variable_Code!\n");
                          fflush(f_ptr);
                      }
                      break;
             }
             break;

        default:
             result = SE_FALSE;
             if (print_error)
             {
                 fprintf(f_ptr,
               "SE_ValidDRMClassFields, local_ValidValueTypeForProperty: "\
               "object is bound to an invalid meaning!\n");
                 fflush(f_ptr);
             }
             break;
    }
    return result;
} /* end local_ValidValueTypeForProperty */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_ValidEUForElement
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_ValidEUForElement
(
    const SE_Element_Type *element_ptr,
          EDCS_Unit_Code   eu,
          SE_Boolean       print_error,
          FILE            *f_ptr
)
{
          SE_Boolean                  result = SE_TRUE;
    const EDCS_Unit_Dictionary_Entry *eu_entry_ptr = NULL;
          EDCS_Unit_Equivalence_Code  eq_class = EQC_PURE_NUMBER;

    local_GetEQForElement
    (
        element_ptr,
       &eq_class,
        print_error,
        f_ptr
    );

    if (EDCS_GetEUDictionaryEntry(eu, &eu_entry_ptr) ==
        EDCS_SC_SUCCESS)
    {
        if (eu_entry_ptr->eq_code != eq_class)
        {
            result = SE_FALSE;
        }
    }
    else
    {
        if (print_error)
        {
            fprintf(f_ptr,
                    "SE_ValidDRMClassFields, local_ValidEUForElement: "\
                    "corruption detected, "\
                    "EDCS_GetEUDictionaryEntry failed for valid EU\n");
            fflush(f_ptr);
        }
        result = SE_FALSE;
    } /* end if */
    return result;
} /* end local_ValidEUForElement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_ValidEUForProperty
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_ValidEUForProperty
(
    const SE_Property_Code *property_ptr,
          EDCS_Unit_Code    eu,
          SE_Boolean        print_error,
          FILE             *f_ptr
)
{
          SE_Boolean                  result = SE_TRUE;
    const EDCS_Unit_Dictionary_Entry *eu_entry_ptr = NULL;
          EDCS_Unit_Equivalence_Code  eq_class = EQC_PURE_NUMBER;

    local_GetEQForProperty
    (
        property_ptr,
       &eq_class,
        print_error,
        f_ptr
    );

    if (EDCS_GetEUDictionaryEntry(eu, &eu_entry_ptr) ==
        EDCS_SC_SUCCESS)
    {
        if (eu_entry_ptr->eq_code != eq_class)
        {
            result = SE_FALSE;
        }
    }
    else
    {
        if (print_error)
        {
            fprintf(f_ptr,
                    "SE_ValidDRMClassFields, local_ValidEUForProperty: "\
                    "corruption detected, "\
                    "EDCS_GetEUDictionaryEntry failed for valid EU\n");
            fflush(f_ptr);
        }
        result = SE_FALSE;
    } /* end if */
    return result;
} /* end local_ValidEUForProperty */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_ValidEUForAttribute
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
local_ValidEUForAttribute
(
    const EDCS_Attribute_Code  ea,
          EDCS_Unit_Code       eu,
          SE_Boolean           print_error,
          FILE                *f_ptr
)
{
          SE_Boolean                       result = SE_TRUE;
    const EDCS_Attribute_Dictionary_Entry *ea_entry_ptr = NULL;
    const EDCS_Unit_Dictionary_Entry      *eu_entry_ptr = NULL;

    if (EDCS_GetEADictionaryEntry(ea, &ea_entry_ptr) != EDCS_SC_SUCCESS)
    {
        if (print_error)
        {
            fprintf(f_ptr,
                    "SE_ValidDRMClassFields, local_ValidEUForAttribute: "\
                    "corruption detected, "\
                    "EDCS_GetEADictionaryEntry failed for valid EA\n");
            fflush(f_ptr);
        }
        result = SE_FALSE;
    }
   /* if it's not a value_type of REAL, there are no units
    * Accept only EUC_UNITLESS as valid in this case.
    */
    else if (ea_entry_ptr->value_type != EDCS_AVT_REAL)
    {
        if (eu != EUC_UNITLESS)
        {
            if (print_error)
            {
                fprintf( f_ptr,
                "Error in SE_ValidDRMClassFields, local_ValidEUForAttribute: "\
                "trying to assign a unit (%s) to a non-REAL type attribute (%s).\n",
                 EDCS_PrintAttributeCode( ea ), EDCS_PrintUnitCode( eu ));
                fflush( f_ptr );
            }
            result = SE_FALSE;
        }
    }
    else if (EDCS_GetEUDictionaryEntry(eu, &eu_entry_ptr) !=
             EDCS_SC_SUCCESS)
    {
        if (print_error)
        {
            fprintf(f_ptr,
                    "SE_ValidDRMClassFields, local_ValidEUForElement: "\
                    "corruption detected, "\
                    "EDCS_GetEUDictionaryEntry failed for valid EU\n");
            fflush(f_ptr);
        }
        result = SE_FALSE;
    }
    else if (eu_entry_ptr->eq_code != ea_entry_ptr->eq_class)
    {
        result = SE_FALSE;
    } /* end if */
    return result;
} /* end local_ValidEUForAttribute */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: ValidPrimitiveSummaryType
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
ValidPrimitiveSummaryType
(
    SE_DRM_Class drm_class
)
{
    SE_Boolean result = SE_FALSE;

    switch (drm_class)
    {
        case SE_CLS_DRM_ABSOLUTE_TIME:
        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
        case SE_CLS_DRM_AGGREGATE_GEOMETRY:
        case SE_CLS_DRM_AMBIENT_COLOUR:
        case SE_CLS_DRM_ARC:
        case SE_CLS_DRM_AREAL_FEATURE:
        case SE_CLS_DRM_AXIS:
        case SE_CLS_DRM_BASE_LOD_DATA:
        case SE_CLS_DRM_BASE_POSITIONAL_LIGHT:
        case SE_CLS_DRM_BASE_TIME_DATA:
        case SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT:
        case SE_CLS_DRM_BOUNDING_VOLUME:
        case SE_CLS_DRM_BROWSE_MEDIA:
        case SE_CLS_DRM_CAMERA_POINT:
        case SE_CLS_DRM_CC_3D_LOCATION:
        case SE_CLS_DRM_CD_3D_LOCATION:
        case SE_CLS_DRM_CD_SURFACE_LOCATION:
        case SE_CLS_DRM_CITATION:
        case SE_CLS_DRM_CLASSIFICATION_DATA:
        case SE_CLS_DRM_CM_3D_LOCATION:
        case SE_CLS_DRM_CMY_COLOUR:
        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
        case SE_CLS_DRM_COLLISION_VOLUME:
        case SE_CLS_DRM_COLOUR:
        case SE_CLS_DRM_COLOUR_DATA:
        case SE_CLS_DRM_COLOUR_INDEX:
        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
        case SE_CLS_DRM_COLOUR_SHININESS:
        case SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT:
        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
        case SE_CLS_DRM_CONTROL_LINK:
        case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
        case SE_CLS_DRM_DATA_QUALITY:
        case SE_CLS_DRM_DATA_TABLE:
        case SE_CLS_DRM_DIFFUSE_COLOUR:
        case SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_DISTANCE_LOD_DATA:
        case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_EC_SURFACE_LOCATION:
        case SE_CLS_DRM_EI_3D_LOCATION:
        case SE_CLS_DRM_ELLIPSE:
        case SE_CLS_DRM_EMISSIVE_COLOUR:
        case SE_CLS_DRM_ENCLOSING_VOLUME:
        case SE_CLS_DRM_ENUMERATION_AXIS:
        case SE_CLS_DRM_EXPRESSION:
        case SE_CLS_DRM_FADE_RANGE:
        case SE_CLS_DRM_FEATURE_REPRESENTATION:
        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        case SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_FUNCTION:
        case SE_CLS_DRM_GEOMETRIC_CENTRE:
        case SE_CLS_DRM_GEOMETRY_EDGE:
        case SE_CLS_DRM_GEOMETRY_FACE:
        case SE_CLS_DRM_GEOMETRY_HIERARCHY:
        case SE_CLS_DRM_GEOMETRY_NODE:
        case SE_CLS_DRM_GEOMETRY_REPRESENTATION:
        case SE_CLS_DRM_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY:
        case SE_CLS_DRM_GEOMETRY_VOLUME:
        case SE_CLS_DRM_HAEC_3D_LOCATION:
        case SE_CLS_DRM_HEEC_3D_LOCATION:
        case SE_CLS_DRM_HEEQ_3D_LOCATION:
        case SE_CLS_DRM_HSV_COLOUR:
        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
        case SE_CLS_DRM_ICON:
        case SE_CLS_DRM_IDENTIFICATION:
        case SE_CLS_DRM_IMAGE_ANCHOR:
        case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
        case SE_CLS_DRM_INDEX_LOD_DATA:
        case SE_CLS_DRM_INFINITE_LIGHT:
        case SE_CLS_DRM_INLINE_COLOUR:
        case SE_CLS_DRM_INTERVAL_AXIS:
        case SE_CLS_DRM_IRREGULAR_AXIS:
        case SE_CLS_DRM_KEYWORDS:
        case SE_CLS_DRM_LABEL:
        case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_LCC_SURFACE_LOCATION:
        case SE_CLS_DRM_LCE_3D_LOCATION:
        case SE_CLS_DRM_LEGAL_CONSTRAINTS:
        case SE_CLS_DRM_LIGHT_RENDERING_BEHAVIOUR:
        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
        case SE_CLS_DRM_LIGHT_SOURCE:
        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
        case SE_CLS_DRM_LINE:
        case SE_CLS_DRM_LINEAGE:
        case SE_CLS_DRM_LINEAR_FEATURE:
        case SE_CLS_DRM_LINEAR_GEOMETRY:
        case SE_CLS_DRM_LITERAL:
        case SE_CLS_DRM_LOBE_DATA:
        case SE_CLS_DRM_LOCAL_4X4:
        case SE_CLS_DRM_LOCATION:
        case SE_CLS_DRM_LOCATION_2D:
        case SE_CLS_DRM_LOCATION_3D:
        case SE_CLS_DRM_LOCATION_SURFACE:
        case SE_CLS_DRM_LSA_2D_LOCATION:
        case SE_CLS_DRM_LSP_2D_LOCATION:
        case SE_CLS_DRM_LSR_2D_LOCATION:
        case SE_CLS_DRM_LSR_3D_LOCATION:
        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
        case SE_CLS_DRM_LSR_TRANSFORMATION:
        case SE_CLS_DRM_LSR_TRANSFORMATION_STEP:
        case SE_CLS_DRM_LTSAS_3D_LOCATION:
        case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
        case SE_CLS_DRM_LTSC_3D_LOCATION:
        case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
        case SE_CLS_DRM_LTSE_3D_LOCATION:
        case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
        case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_M_SURFACE_LOCATION:
        case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
        case SE_CLS_DRM_MESH_FACE_TABLE:
        case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_OMS_SURFACE_LOCATION:
        case SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX:
        case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
        case SE_CLS_DRM_PD_3D_LOCATION:
        case SE_CLS_DRM_PD_SURFACE_LOCATION:
        case SE_CLS_DRM_PERIMETER_DATA:
        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_POINT:
        case SE_CLS_DRM_POINT_FEATURE:
        case SE_CLS_DRM_POLYGON:
        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
        case SE_CLS_DRM_POLYHEDRON:
        case SE_CLS_DRM_POSITIONAL_LIGHT:
        case SE_CLS_DRM_PREDEFINED_FUNCTION:
        case SE_CLS_DRM_PRESENTATION_DOMAIN:
        case SE_CLS_DRM_PRIMITIVE_COLOUR:
        case SE_CLS_DRM_PRIMITIVE_FEATURE:
        case SE_CLS_DRM_PRIMITIVE_GEOMETRY:
        case SE_CLS_DRM_PROCESS_STEP:
        case SE_CLS_DRM_PROPERTY:
        case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
        case SE_CLS_DRM_PROPERTY_SET_INDEX:
        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
        case SE_CLS_DRM_PROPERTY_TABLE:
        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
        case SE_CLS_DRM_PROPERTY_VALUE:
        case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_PS_SURFACE_LOCATION:
        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
        case SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT:
        case SE_CLS_DRM_REFERENCE_SURFACE:
        case SE_CLS_DRM_REFERENCE_VECTOR:
        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
        case SE_CLS_DRM_REGULAR_AXIS:
        case SE_CLS_DRM_RELATIVE_TIME:
        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
        case SE_CLS_DRM_RENDERING_PROPERTIES:
        case SE_CLS_DRM_RESPONSIBLE_PARTY:
        case SE_CLS_DRM_RGB_COLOUR:
        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
        case SE_CLS_DRM_ROLE_DATA:
        case SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_ROTATION:
        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
        case SE_CLS_DRM_SCALE:
        case SE_CLS_DRM_SCALE_CONTROL_LINK:
        case SE_CLS_DRM_SEASON:
        case SE_CLS_DRM_SECURITY_CONSTRAINTS:
        case SE_CLS_DRM_SEC_3D_LOCATION:
        case SE_CLS_DRM_SEDRIS_ABSTRACT_BASE:
        case SE_CLS_DRM_SEQ_3D_LOCATION:
        case SE_CLS_DRM_SMD_3D_LOCATION:
        case SE_CLS_DRM_SME_3D_LOCATION:
        case SE_CLS_DRM_SOUND_INSTANCE:
        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
        case SE_CLS_DRM_SOUND_VOLUME:
        case SE_CLS_DRM_SOURCE:
        case SE_CLS_DRM_SPATIAL_EXTENT:
        case SE_CLS_DRM_SPATIAL_INDEX_DATA:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
        case SE_CLS_DRM_SPECULAR_COLOUR:
        case SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT:
        case SE_CLS_DRM_SPOT_LIGHT:
        case SE_CLS_DRM_STAMP_BEHAVIOUR:
        case SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_SURFACE_GEOMETRY:
        case SE_CLS_DRM_SYMBOL:
        case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
        case SE_CLS_DRM_TACK_POINT:
        case SE_CLS_DRM_TEXT:
        case SE_CLS_DRM_TEXTURE_COORDINATE:
        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
        case SE_CLS_DRM_TIME_CONSTRAINTS_DATA:
        case SE_CLS_DRM_TIME_INTERVAL:
        case SE_CLS_DRM_TIME_OF_DAY:
        case SE_CLS_DRM_TIME_POINT:
        case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_TM_SURFACE_LOCATION:
        case SE_CLS_DRM_TRANSFORMATION:
        case SE_CLS_DRM_TRANSLATION:
        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
        case SE_CLS_DRM_TRANSLUCENCY:
        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
        case SE_CLS_DRM_TWINKLING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_UNION_OF_GEOMETRY:
        case SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
        case SE_CLS_DRM_VARIABLE:
        case SE_CLS_DRM_VERTEX:
        case SE_CLS_DRM_VOLUME_EXTENT:
        case SE_CLS_DRM_VOLUME_GEOMETRY:
        case SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_VOLUME_LOD_DATA:
        case SE_CLS_DRM_VOLUME_OBJECT:
        case SE_CLS_DRM_VOLUMETRIC_FEATURE:
             result = SE_TRUE;
             break;

        default:
             result = SE_FALSE;
             break;
    } /* end switch */
    return result;
} /* end ValidPrimitiveSummaryType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMClassFields
 *
 *   Checks the information in the given SE_DRM_Class_Fields, but does not
 *   check constraints that involve checking an object's relationships with
 *   other objects.
 *
 * PARAMETERS:
 *
 *   field_ptr -- fields to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for this
 *     SE_FIELDS_PTR is stored; if NULL, no error counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if fields_ptr is non-NULL and *fields_ptr is valid
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDRMClassFields
(
    SE_FIELDS_PTR        field_ptr,
    SE_Boolean           print_error,
    SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean        result = SE_TRUE;
    EDCS_Boolean      edcs_result = EDCS_FALSE;
    FILE             *f_ptr = NULL, *orig_srm_f_ptr = NULL,
                     *orig_edcs_f_ptr = NULL;
    SRM_Status_Code   srm_stat_code;
    EDCS_Status_Code  edcs_stat_code;

    if (print_error)
    {
        f_ptr           = SE_GetErrorFilePtr();
        orig_srm_f_ptr  = SRM_GetErrorFilePtr();
        orig_edcs_f_ptr = EDCS_GetErrorFilePtr();

        if ((srm_stat_code = SRM_SetErrorFilePtr(f_ptr)) !=
            SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr, "SE_ValidDRMClassFields: "\
                    "Can't set SRM error file "\
                    "pointer (%s), turning off error printing!\n",
                    SRM_PrintStatusCode(srm_stat_code));
            print_error = SE_FALSE;
        }
        else if ((edcs_stat_code = EDCS_SetErrorFilePtr(f_ptr)) !=
                 EDCS_SC_SUCCESS)
        {
            EDCS_SetErrorFilePtr(orig_edcs_f_ptr);

            fprintf(stderr, "SE_ValidDRMClassFields: "\
                    "Can't set EDCS error file pointer (%s), "\
                    "turning off error printing!\n",
                    EDCS_PrintStatusCode(edcs_stat_code));
            print_error = SE_FALSE;
        }
    }

    switch (field_ptr->tag)
    {
        case SE_CLS_DRM_ABSOLUTE_TIME:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Absolute_Time.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Absolute_Time.time_significance);
            }
            if (!SE_ValidTimeValue(&(field_ptr->u.Absolute_Time.time_value),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Time_Value value\n");
                }
            }
            break;

        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Absolute_Time_Interval.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Absolute_Time_Interval.time_significance);
            }
            if (field_ptr->u.Absolute_Time_Interval.delta_hours > 23)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_hours"\
                            " > 23 in <Absolute Time Interval>!\n");
            }
            if (field_ptr->u.Absolute_Time_Interval.delta_minutes > 59)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_minutes"\
                            " > 59 in <Absolute Time Interval>!\n");
            }
            if ((field_ptr->u.Absolute_Time_Interval.delta_seconds < 0.0) ||
                (field_ptr->u.Absolute_Time_Interval.delta_seconds > 61.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_seconds"\
                            " out of range [0.0, 61.0] in <Absolute Time Interval>!\n");
            }
            break;

        case SE_CLS_DRM_AGGREGATE_FEATURE:
            if (!SE_ValidBoolean
               (field_ptr->u.Aggregate_Feature.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Aggregate_Feature.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Aggregate_Feature.strict_organizing_principle))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Aggregate_Feature.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_AGGREGATE_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Aggregate_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Aggregate_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Aggregate_Geometry.strict_organizing_principle))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Aggregate_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.Alternate_Hierarchy_Related_Features.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Alternate_Hierarchy_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Alternate_Hierarchy_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Alternate_Hierarchy_Related_Features.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Alternate_Hierarchy_Related_Geometry.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Alternate_Hierarchy_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Alternate_Hierarchy_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Alternate_Hierarchy_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_ANIMATION_BEHAVIOUR:
            if (field_ptr->u.Animation_Behaviour.period <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: period"\
                            " <= 0.0 in <Animation Behaviour>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Animation_Behaviour.forward_sequence_mode))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Animation_Behaviour.forward_sequence_mode);
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Animation_Behaviour.beginning_frame))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Animation_Behaviour.beginning_frame"\
                            " value (%d)\n", (int)
                        field_ptr->u.Animation_Behaviour.beginning_frame);
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Animation_Behaviour.ending_frame))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Animation_Behaviour.ending_frame"\
                            " value (%d)\n", (int)
                        field_ptr->u.Animation_Behaviour.ending_frame);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Animation_Behaviour.random_beginning_frame))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Animation_Behaviour.random_beginning_frame);
            }
            break;

        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Animation_Related_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Animation_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Animation_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Animation_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_ARC:
            if (!SE_ValidBoolean(field_ptr->u.Arc.suppress_last))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Arc.suppress_last);
            }
            break;

        case SE_CLS_DRM_AXIS:
            if (!EDCS_ValidAttributeCode(field_ptr->u.Axis.axis_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.Axis.axis_type);
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Axis.axis_value_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Axis.axis_value_count value"\
                            " (%d)\n", (int)
                        field_ptr->u.Axis.axis_value_count);
            }
            break;

        case SE_CLS_DRM_BASE_POSITIONAL_LIGHT:
            if (!SE_ValidBoolean
               (field_ptr->u.Base_Positional_Light.apply_to_children))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Base_Positional_Light.apply_to_children);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Base_Positional_Light.override_positional_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Base_Positional_Light.override_positional_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Base_Positional_Light.override_infinite_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Base_Positional_Light.override_infinite_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Base_Positional_Light.active_light_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Base_Positional_Light.active_light_value);
            }
            if (field_ptr->u.Base_Positional_Light.radius < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: radius"\
                            " < 0.0 in <Base Positional Light>!\n");
            }
            break;

        case SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA:
            if (!SE_ValidSpatialAssociationMeaningType
               (field_ptr->u.Base_Spatial_Association_Data.meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Association_Meaning_Type value"\
                            " (%d)\n", (int)
                        field_ptr->u.Base_Spatial_Association_Data.meaning);
            }
            break;

        case SE_CLS_DRM_BASE_SUMMARY_ITEM:
            if ((field_ptr->u.Base_Summary_Item.drm_class == SE_CLS_DRM_NULL) ||
               !SE_ValidDRMClass(field_ptr->u.Base_Summary_Item.drm_class))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_DRM_Class value (%d)\n", (int)
                        field_ptr->u.Base_Summary_Item.drm_class);
            }
            break;

        case SE_CLS_DRM_BASE_TIME_DATA:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Base_Time_Data.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Base_Time_Data.time_significance);
            }
            break;

        case SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT:
            if ((field_ptr->u.Blend_Directional_Light.upper_plane_angular_offset < -SE_LF_PI) ||
                (field_ptr->u.Blend_Directional_Light.upper_plane_angular_offset > SE_LF_PI))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: upper_plane_angular_offset"\
                            " out of range [-SE_LF_PI, SE_LF_PI] in <Blend Directional Light>!\n");
            }
            if ((field_ptr->u.Blend_Directional_Light.lower_plane_angular_offset < -SE_LF_PI) ||
                (field_ptr->u.Blend_Directional_Light.lower_plane_angular_offset > SE_LF_PI))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: lower_plane_angular_offset"\
                            " out of range [-SE_LF_PI, SE_LF_PI] in <Blend Directional Light>!\n");
            }
            break;

        case SE_CLS_DRM_BROWSE_MEDIA:
            if (!SE_ValidNonNullString(&(field_ptr->u.Browse_Media.name),
                      SE_FALSE, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Browse_Media.name"\
                           " is invalid\n");
            }
            if (!SE_ValidMediaFormat(field_ptr->u.Browse_Media.media_format))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Media_Format value (%d)\n", (int)
                        field_ptr->u.Browse_Media.media_format);
            }
            if (!SE_ValidURN(&(field_ptr->u.Browse_Media.media_urn),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_URN value\n");
                }
            }
            if (!SE_ValidString(&(field_ptr->u.Browse_Media.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_CAMERA_POINT:
            if (!SE_ValidCameraProjectionType
               (field_ptr->u.Camera_Point.projection))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Camera_Projection_Type value (%d)\n", (int)
                        field_ptr->u.Camera_Point.projection);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Camera_Point.use_left_bottom_right_top))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Camera_Point.use_left_bottom_right_top);
            }
            break;

        case SE_CLS_DRM_CC_3D_LOCATION:
            break;

        case SE_CLS_DRM_CD_3D_LOCATION:
            if (!SRM_ValidCD3DCoordinate(
                      &(field_ptr->u.CD_3D_Location.coordinate), (SRM_Boolean)
                      print_error, (SRM_Integer_Unsigned *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_CD_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_CD_SURFACE_LOCATION:
            if (!SRM_ValidCDSurfaceCoordinate(
                      &(field_ptr->u.CD_Surface_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_CD_Surface_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_CITATION:
            if (!SE_ValidNonNullString(&(field_ptr->u.Citation.title),
                      SE_FALSE, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Citation.title is"\
                           " invalid\n");
            }
            if (!SE_ValidString(&(field_ptr->u.Citation.edition), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(&(field_ptr->u.Citation.series_name),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(&(field_ptr->u.Citation.issue_identification),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Citation.other_citation_details),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_CLASSIFICATION_DATA:
            if (!EDCS_ValidClassificationCode
               (field_ptr->u.Classification_Data.tag))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Classification_Code value (%d)\n", (int)
                        field_ptr->u.Classification_Data.tag);
            }
            break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.Classification_Related_Features.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Classification_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Classification_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Classification_Related_Features.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Classification_Related_Geometry.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Classification_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Classification_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Classification_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_CM_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.CM_3D_Location.coordinate), (SRM_Boolean)
                      print_error, (SRM_Integer_Unsigned *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_CMY_COLOUR:
            if (!SE_ValidCMYData(&(field_ptr->u.CMY_Colour.cmy_data),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_CMY_Data value\n");
                }
            }
            break;

        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.CMY_Colour_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.CMY_Colour_Control_Link.cyan_expression_index == 0) &&
                (field_ptr->u.CMY_Colour_Control_Link.magenta_expression_index == 0) &&
                (field_ptr->u.CMY_Colour_Control_Link.yellow_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <CMY Colour Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_COLOUR:
            if (!SE_ValidColourMapping(&(field_ptr->u.Colour.colour_mapping),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Colour_Mapping value\n");
                }
            }
            break;

        case SE_CLS_DRM_COLOUR_INDEX:
            if (!SE_ValidColourMapping(
                      &(field_ptr->u.Colour_Index.colour_mapping),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Colour_Mapping value\n");
                }
            }
            if (!SE_ValidIntegerPositive(field_ptr->u.Colour_Index.index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Colour_Index.index value (%d)\n",
                        (int) field_ptr->u.Colour_Index.index);
            }
            if ((field_ptr->u.Colour_Index.intensity_level < 0.0) ||
                (field_ptr->u.Colour_Index.intensity_level > 1.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: intensity_level"\
                            " out of range [0.0, 1.0] in <Colour Index>!\n");
            }
            break;

        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Colour_Index_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.Colour_Index_Control_Link.colour_index == 0) &&
                (field_ptr->u.Colour_Index_Control_Link.intensity_level_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <Colour Index Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_COLOUR_SHININESS:
            break;

        case SE_CLS_DRM_COLOUR_TABLE_GROUP:
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Colour_Table_Group.primary_table_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Colour_Table_Group.primary_table_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Colour_Table_Group.primary_table_index);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Colour_Table_Group.table_size))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Colour_Table_Group.table_size"\
                            " value (%d)\n", (int)
                        field_ptr->u.Colour_Table_Group.table_size);
            }
            break;

        case SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT:
            if (!SE_ValidBoolean(field_ptr->u.Cone_Directional_Light.has_plane)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Cone_Directional_Light.has_plane);
            }
            if ((field_ptr->u.Cone_Directional_Light.plane_angular_offset < -SE_LF_PI) ||
                (field_ptr->u.Cone_Directional_Light.plane_angular_offset > SE_LF_PI))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: plane_angular_offset"\
                            " out of range [-SE_LF_PI, SE_LF_PI] in <Cone Directional Light>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Cone_Directional_Light.use_full_intensity))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Cone_Directional_Light.use_full_intensity);
            }
            if ((field_ptr->u.Cone_Directional_Light.minimum_colour_intensity < 0.0) ||
                (field_ptr->u.Cone_Directional_Light.minimum_colour_intensity > 1.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minimum_colour_intensity"\
                            " out of range [0.0, 1.0] in <Cone Directional Light>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Cone_Directional_Light.invisible_behind))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Cone_Directional_Light.invisible_behind);
            }
            break;

        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
            if (!EDCS_ValidClassificationCode
               (field_ptr->u.Conformal_Behaviour.classification))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Classification_Code value (%d)\n", (int)
                        field_ptr->u.Conformal_Behaviour.classification);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Conformal_Behaviour.parallel_gravity))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Conformal_Behaviour.parallel_gravity);
            }
            break;

        case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Continuous_LOD_Related_Geometry.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Continuous_LOD_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Continuous_LOD_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Continuous_LOD_Related_Geometry.strict_organizing_principle);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Continuous_LOD_Related_Geometry.terminating_node))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Continuous_LOD_Related_Geometry.terminating_node);
            }
            break;

        case SE_CLS_DRM_CONTROL_LINK:
            if (!SE_ValidString(&(field_ptr->u.Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
            if (field_ptr->u.Cylindrical_Volume_Extent.major_axis_radius < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: major_axis_radius"\
                            " < 0.0 in <Cylindrical Volume Extent>!\n");
            }
            if (field_ptr->u.Cylindrical_Volume_Extent.minor_axis_radius < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minor_axis_radius"\
                            " < 0.0 in <Cylindrical Volume Extent>!\n");
            }
            if (field_ptr->u.Cylindrical_Volume_Extent.cylinder_length <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: cylinder_length"\
                            " <= 0.0 in <Cylindrical Volume Extent>!\n");
            }
            if (field_ptr->u.Cylindrical_Volume_Extent.minor_axis_radius >
                field_ptr->u.Cylindrical_Volume_Extent.major_axis_radius)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "minor_axis_radius > major_axis_radius in <Cylindrical Volume Extent>!\n");
            }
            break;

        case SE_CLS_DRM_DATA_QUALITY:
            if (!SE_ValidBoolean(field_ptr->u.Data_Quality.fictional))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Data_Quality.fictional);
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.field_accuracy),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.logical_consistency),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.completeness), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.abs_horiz_pos_accuracy),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.rel_horiz_pos_accuracy),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.abs_vert_pos_accuracy),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            if (!SE_ValidDataQualityElement(
                      &(field_ptr->u.Data_Quality.rel_vert_pos_accuracy),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Data_Quality_Element value\n");
                }
            }
            break;

        case SE_CLS_DRM_DISTANCE_LOD_DATA:
            if (field_ptr->u.Distance_LOD_Data.minimum_range < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minimum_range"\
                            " < 0.0 in <Distance LOD Data>!\n");
            }
            if (field_ptr->u.Distance_LOD_Data.minimum_fade_band < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minimum_fade_band"\
                            " < 0.0 in <Distance LOD Data>!\n");
            }
            if (field_ptr->u.Distance_LOD_Data.maximum_range < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: maximum_range"\
                            " < 0.0 in <Distance LOD Data>!\n");
            }
            if (field_ptr->u.Distance_LOD_Data.maximum_fade_band < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: maximum_fade_band"\
                            " < 0.0 in <Distance LOD Data>!\n");
            }
            if (field_ptr->u.Distance_LOD_Data.minimum_range >
                field_ptr->u.Distance_LOD_Data.maximum_range)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "minimum_range > maximum_range in <Distance LOD Data>!\n");
            }

            break;

        case SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM:
            if ((field_ptr->u.DRM_Class_Summary_Item.drm_class == SE_CLS_DRM_NULL) ||
               !SE_ValidDRMClass(field_ptr->u.DRM_Class_Summary_Item.drm_class)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_DRM_Class value (%d)\n", (int)
                        field_ptr->u.DRM_Class_Summary_Item.drm_class);
            }
            break;

        case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
            break;

        case SE_CLS_DRM_EC_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
            if (!SE_ValidString(
                      &(field_ptr->u.EDCS_Use_Summary_Item.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_EDGE_DIRECTION:
            if (!SE_ValidBoolean(field_ptr->u.Edge_Direction.forwards))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Edge_Direction.forwards);
            }
            break;

        case SE_CLS_DRM_EI_3D_LOCATION:
            if (!SRM_ValidEI3DCoordinate(
                      &(field_ptr->u.EI_3D_Location.coordinate), (SRM_Boolean)
                      print_error, (SRM_Integer_Unsigned *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_EI_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_ELLIPSE:
            if (field_ptr->u.Ellipse.major_axis_length <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: major_axis_length"\
                            " <= 0.0 in <Ellipse>!\n");
            }
            if (field_ptr->u.Ellipse.minor_axis_length <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minor_axis_length"\
                            " <= 0.0 in <Ellipse>!\n");
            }
            if (field_ptr->u.Ellipse.minor_axis_length >
                field_ptr->u.Ellipse.major_axis_length)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "minor_axis_length > major_axis_length in <Ellipse>!\n");
            }
            break;

        case SE_CLS_DRM_ENUMERATION_AXIS:
            if (!EDCS_ValidAttributeCode
               (field_ptr->u.Enumeration_Axis.axis_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.Enumeration_Axis.axis_type);
            }
            if (!field_ptr->u.Enumeration_Axis.axis_value_array)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL"\
                           " field_ptr->u.Enumeration_Axis.axis_value_array"\
                           " for"\
                           " field_ptr->u.Enumeration_Axis.axis_value_count"\
                           " == %u\n",(unsigned int)
                            field_ptr->u.Enumeration_Axis.axis_value_count);
                }
            }
            else if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Enumeration_Axis.axis_value_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Enumeration_Axis.axis_value_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Enumeration_Axis.axis_value_count);
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Enumeration_Axis.axis_value_count; i++)
                {
                    if (!EDCS_ValidEnumerantCode( field_ptr->u.Enumeration_Axis.axis_type, field_ptr->u.Enumeration_Axis.axis_value_array[i]))
                    {
                        result = SE_FALSE;
                        if (error_count_ptr)
                            (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Invalid enumerant %d found, expected EDCS_Enumerant_Code\n", (int)field_ptr->u.Enumeration_Axis.axis_value_array[i]);
                    }
                } /* end for i */
                for (i = 0; (result==SE_TRUE) &&
                     (i < (SE_Integer_Unsigned)(field_ptr->u.Enumeration_Axis.axis_value_count-1));
                     i++)
                {
                    for (j = i+1; (result==SE_TRUE) &&
                         (j < field_ptr->u.Enumeration_Axis.axis_value_count);
                         j++)
                    {
                        if (field_ptr->u.Enumeration_Axis.axis_value_array[i] ==
                            field_ptr->u.Enumeration_Axis.axis_value_array[j])
                        {
                            result = SE_FALSE;
                            if (error_count_ptr)
                                (*error_count_ptr)++;
                            if (print_error)
                                fprintf(f_ptr,
                                 "<<General Axis Constraints>>: Duplicate EE\n");
                        }
                    } /* end for j */
                } /* end for i */
            }
            break;

        case SE_CLS_DRM_ENVIRONMENT_ROOT:
            if (!SE_ValidSRFContextInfo(
                      &(field_ptr->u.Environment_Root.srf_context_info),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_SRF_Context_Info value\n");
                }
            }
            break;

        case SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY:
            if (!EDCS_ValidClassificationCode
               (field_ptr->u.Environmental_Domain_Summary.environmental_domain)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Classification_Code value (%d)\n", (int)
                        field_ptr->u.Environmental_Domain_Summary.environmental_domain);
            }
            break;

        case SE_CLS_DRM_FACE_DIRECTION:
            if (!SE_ValidBoolean(field_ptr->u.Face_Direction.front))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Face_Direction.front);
            }
            break;

        case SE_CLS_DRM_FADE_RANGE:
            break;

        case SE_CLS_DRM_FEATURE_FACE:
            if (!SE_ValidBoolean(field_ptr->u.Feature_Face.universal))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Feature_Face.universal);
            }
            break;

        case SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY:
            if (!SE_ValidFeatureTopologyLevel
               (field_ptr->u.Feature_Topology_Hierarchy.feature_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Feature_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Feature_Topology_Hierarchy.feature_topology_level);
            }
            break;

        case SE_CLS_DRM_FEATURE_VOLUME:
            if (!SE_ValidBoolean(field_ptr->u.Feature_Volume.universal))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Feature_Volume.universal);
            }
            break;

        case SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR:
            if (field_ptr->u.Flashing_Light_Behaviour.period <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: period"\
                            " <= 0.0 in <Flashing Light Behaviour>!\n");
            }
            if (field_ptr->u.Flashing_Light_Behaviour.delay < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delay"\
                            " < 0.0 in <Flashing Light Behaviour>!\n");
            }
            if (field_ptr->u.Flashing_Light_Behaviour.duration <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: duration"\
                            " <= 0.0 in <Flashing Light Behaviour>!\n");
            }
            break;

        case SE_CLS_DRM_FUNCTION:
            if (!EDCS_ValidAttributeValueType(field_ptr->u.Function.value_type)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Value_Type value (%d)\n", (int)
                        field_ptr->u.Function.value_type);
            }
            else if ((field_ptr->u.Function.value_type ==
                     EDCS_AVT_CONSTRAINED_STRING) ||
                     (field_ptr->u.Function.value_type == EDCS_AVT_INDEX) ||
                     (field_ptr->u.Function.value_type == EDCS_AVT_KEY) ||
                     (field_ptr->u.Function.value_type == EDCS_AVT_NULL) ||
                     (field_ptr->u.Function.value_type == EDCS_AVT_STRING))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: illegal"\
                            " value_type (%s) for <Function>\n",
                        EDCS_PrintAttributeValueType
                        (field_ptr->u.Function.value_type));
            }
            break;

        case SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA:
            if (!SE_ValidFunctionalAssociationMeaningType
               (field_ptr->u.Functional_Association_Data.meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Functional_Association_Meaning_Type value"\
                            " (%d)\n", (int)
                        field_ptr->u.Functional_Association_Data.meaning);
            }
            break;

        case SE_CLS_DRM_GEOMETRIC_CENTRE:
            if (!SE_ValidGeometricCentreCode
               (field_ptr->u.Geometric_Centre.meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Geometric_Centre_Code value (%d)\n", (int)
                        field_ptr->u.Geometric_Centre.meaning);
            }
            break;

        case SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY:
            if (!SE_ValidGeometryTopologyLevel
               (field_ptr->u.Geometry_Topology_Hierarchy.geometry_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Geometry_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Geometry_Topology_Hierarchy.geometry_topology_level);
            }
            break;

        case SE_CLS_DRM_GRID_OVERLAP:
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Grid_Overlap.overlay_group))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Grid_Overlap.overlay_group value"\
                            " (%d)\n", (int)
                        field_ptr->u.Grid_Overlap.overlay_group);
            }
            if (!SE_ValidGridOverlapOperator
               (field_ptr->u.Grid_Overlap.operation))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Grid_Overlap_Operator value (%d)\n", (int)
                        field_ptr->u.Grid_Overlap.operation);
            }
            if ((field_ptr->u.Grid_Overlap.priority == 0) &&
                (field_ptr->u.Grid_Overlap.operation !=
                SE_GROVLOP_BASE))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                           " <Grid Overlap> priority == 0 but operation = %s\n",\
                        SE_PrintGridOverlapOperator
                        (field_ptr->u.Grid_Overlap.operation));
            }
            break;

        case SE_CLS_DRM_HAEC_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.HAEC_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_HEEC_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.HEEC_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_HEEQ_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.HEEQ_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_HIERARCHY_DATA:
            if (!SE_ValidNonNullString(
                      &(field_ptr->u.Hierarchy_Data.alternate_representation_reason),
                      SE_FALSE, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory"\
                           " field_ptr->u.Hierarchy_Data.alternate_representation_reason"\
                           " is invalid\n");
            }
            break;

        case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
            if ((field_ptr->u.Hierarchy_Summary_Item.drm_class == SE_CLS_DRM_NULL) ||
               !SE_ValidDRMClass(field_ptr->u.Hierarchy_Summary_Item.drm_class)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_DRM_Class value (%d)\n", (int)
                        field_ptr->u.Hierarchy_Summary_Item.drm_class);
            }
            else if (!SE_IsA[field_ptr->u.Hierarchy_Summary_Item.drm_class]
                     [SE_CLS_DRM_FEATURE_HIERARCHY] &&
                     !SE_IsA[field_ptr->u.Hierarchy_Summary_Item.drm_class]
                     [SE_CLS_DRM_GEOMETRY_HIERARCHY])
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: illegal"\
                            " drm_class (%s) - must be a <Feature Hierarchy>"\
                            " or <Geometry Hierarchy>\n",
                        SE_PrintDRMClass(field_ptr->u.Hierarchy_Summary_Item.drm_class));
            }
            if (!SE_ValidHSMultiplicityCode
               (field_ptr->u.Hierarchy_Summary_Item.multiplicity_meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_HS_Multiplicity_Code value (%d)\n", (int)
                        field_ptr->u.Hierarchy_Summary_Item.multiplicity_meaning);
            }
            break;

        case SE_CLS_DRM_HSV_COLOUR:
            if (!SE_ValidHSVData(&(field_ptr->u.HSV_Colour.hsv_data),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_HSV_Data value\n");
                }
            }
            break;

        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.HSV_Colour_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.HSV_Colour_Control_Link.hue_expression_index == 0) &&
                (field_ptr->u.HSV_Colour_Control_Link.saturation_expression_index == 0) &&
                (field_ptr->u.HSV_Colour_Control_Link.value_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <HSV Colour Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_IDENTIFICATION:
            if (!SE_ValidNonNullString(
                      &(field_ptr->u.Identification.abstract), SE_FALSE,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory"\
                           " field_ptr->u.Identification.abstract is"\
                           " invalid\n");
            }
            if (!SE_ValidString(&(field_ptr->u.Identification.purpose),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!field_ptr->u.Identification.credit &&
                (field_ptr->u.Identification.credit_count>0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL field_ptr->u.Identification.credit"\
                           " for field_ptr->u.Identification.credit_count =="\
                           " %u\n",(unsigned int)
                            field_ptr->u.Identification.credit_count);
                }
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Identification.credit_count; i++)
                {
                    if (!SE_ValidNonNullString
                            (&(field_ptr->u.Identification.credit[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_String found at "\
                                "field_ptr->u.Identification.credit[%u]\n", i);
                        }
                    }
                } /* end for i */
                if ((result == SE_TRUE) && (field_ptr->u.Identification.credit_count > 1))
                {
                    for (i = 0; (result == SE_TRUE) && (i <
                    (SE_Integer_Unsigned)field_ptr->u.Identification.credit_count-1);
                    i++)
                    {
                        for (j = i+1; (result == SE_TRUE) && (j <
                        (SE_Integer_Unsigned)field_ptr->u.Identification.credit_count);
                        j++)
                        {
                            if (SE_CompareStrings
                        (&(field_ptr->u.Identification.credit[i]),
                        &(field_ptr->u.Identification.credit[j]))==0)
                            {
                                result = SE_FALSE;
                                if (print_error)
                                {
                                    fprintf(f_ptr, "Duplicate entry found at "\
                                    "field_ptr->u.Identification.credit[%u]\n", j);
                                }
                            }
                        } /* end for j */
                    } /* end for i */
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Identification.supplemental_information),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_IMAGE:
            if (!SE_ValidNonNullString(&(field_ptr->u.Image.name), SE_FALSE,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Image.name is"\
                           " invalid\n");
            }
            if (!SE_ValidColourModel(field_ptr->u.Image.colour_model))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Colour_Model value (%d)\n", (int)
                        field_ptr->u.Image.colour_model);
            }
            if (!field_ptr->u.Image.mip_extents_array)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL field_ptr->u.Image.mip_extents_array"\
                           " for field_ptr->u.Image.level_count == %u\n",
                            (unsigned int) field_ptr->u.Image.level_count);
                }
            }
            else if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Image.level_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Image.level_count value (%d)\n",
                        (int) field_ptr->u.Image.level_count);
            }
            else
            {
                SE_Integer_Unsigned i;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Image.level_count; i++)
                {
                    if (!SE_ValidImageMIPExtents
                            (&(field_ptr->u.Image.mip_extents_array[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_Image_MIP_Extents found at "\
                                "field_ptr->u.Image.mip_extents_array[%u]\n", i);
                        }
                    }
                } /* end for i */
            }
            switch (field_ptr->u.Image.image_signature)
            {
                case SE_IMAGSIG_ALPHA:
                    if (field_ptr->u.Image.bits_of_alpha == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_alpha"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_LUMINANCE:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_luminance"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_COLOUR_COORDINATE_1:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_1"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_COLOUR_COORDINATE_2:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_2"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_COLOUR_COORDINATE_3:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_3"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_BUMP_MAP_HEIGHT:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_bump_map_height"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                    if (field_ptr->u.Image.bits_of_alpha == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_alpha"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_luminance"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_123COLOUR:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_1"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_2"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_3"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_123COLOUR_ALPHA:
                    if (field_ptr->u.Image.bits_of_alpha == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_alpha"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_1"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_2"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_colour_coordinate_3"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_ONE_MATERIAL:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_1"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_TWO_MATERIALS:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_1"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_2"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_2_percentage"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_THREE_MATERIALS:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_1"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_2"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_3"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_2_percentage"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_material_3_percentage"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_IMAGE_INDEX:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_image_index"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;
                case SE_IMAGSIG_BUMP_MAP_UV:
                    if (field_ptr->u.Image.bits_of_alpha > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_alpha "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_luminance > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_luminance "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_colour_coordinate_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_height > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_1 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_1 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3 > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3 "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_2_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_material_3_percentage > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_image_index > 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Illegal bits_of_image_index "\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_u == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_bump_map_u"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    if (field_ptr->u.Image.bits_of_bump_map_v == 0)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr) (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr, "Missing required bits_of_bump_map_v"\
                               " for image_signature = %s\n",
                               SE_PrintImageSignature
                               (field_ptr->u.Image.image_signature));
                    }
                    break;

                default:
                    result = SE_FALSE;
                    if (error_count_ptr) (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                                " SE_Image_Signature value (%d)\n",
                            (int) field_ptr->u.Image.image_signature);
                    break;
            } /* end switch */
            if (!SE_ValidImageScanDirection(field_ptr->u.Image.scan_direction))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Scan_Direction value (%d)\n", (int)
                        field_ptr->u.Image.scan_direction);
            }
            if (!SE_ValidImageScanDirectionZ
               (field_ptr->u.Image.scan_direction_z))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Scan_Direction_Z value (%d)\n", (int)
                        field_ptr->u.Image.scan_direction_z);
            }
            if (!SE_ValidImageComponentType
               (field_ptr->u.Image.component_data_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Component_Type value (%d)\n", (int)
                        field_ptr->u.Image.component_data_type);
            }
            if (!SE_ValidBoolean(field_ptr->u.Image.data_is_little_endian))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Image.data_is_little_endian);
            }
            if (!SE_ValidBoolean(field_ptr->u.Image.data_is_3D))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Image.data_is_3D);
            }
            if (field_ptr->u.Image.min_value_of_alpha >
                field_ptr->u.Image.max_value_of_alpha)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_alpha"\
                            " > max_value_of_alpha in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_luminance >
                field_ptr->u.Image.max_value_of_luminance)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_luminance"\
                            " > max_value_of_luminance in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_colour_coordinate_1 >
                field_ptr->u.Image.max_value_of_colour_coordinate_1)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_colour_coordinate_1"\
                            " > max_value_of_colour_coordinate_1 in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_colour_coordinate_2 >
                field_ptr->u.Image.max_value_of_colour_coordinate_2)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_colour_coordinate_2"\
                            " > max_value_of_colour_coordinate_2 in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_colour_coordinate_3 >
                field_ptr->u.Image.max_value_of_colour_coordinate_3)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_colour_coordinate_3"\
                            " > max_value_of_colour_coordinate_3 in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_bump_map_height >
                field_ptr->u.Image.max_value_of_bump_map_height)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_bump_map_height"\
                            " > max_value_of_bump_map_height in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_bump_map_u >
                field_ptr->u.Image.max_value_of_bump_map_u)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_bump_map_u"\
                            " > max_value_of_bump_map_u in <Image>!\n");
            }
            if (field_ptr->u.Image.min_value_of_bump_map_v >
                field_ptr->u.Image.max_value_of_bump_map_v)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " min_value_of_bump_map_v"\
                            " > max_value_of_bump_map_v in <Image>!\n");
            }
            break;

        case SE_CLS_DRM_IMAGE_ANCHOR:
            if (!SE_ValidSRFContextInfo(
                      &(field_ptr->u.Image_Anchor.srf_context_info),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_SRF_Context_Info value\n");
                }
            }
            break;

        case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
            if (!SE_ValidImageMappingMethod
               (field_ptr->u.Image_Mapping_Function.image_mapping_method))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Mapping_Method value (%d)\n", (int)
                        field_ptr->u.Image_Mapping_Function.image_mapping_method);
            }
            if (!SE_ValidImageWrap
               (field_ptr->u.Image_Mapping_Function.image_wrap_s))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Wrap value (%d)\n", (int)
                        field_ptr->u.Image_Mapping_Function.image_wrap_s);
            }
            if (!SE_ValidImageWrap
               (field_ptr->u.Image_Mapping_Function.image_wrap_t))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Wrap value (%d)\n", (int)
                        field_ptr->u.Image_Mapping_Function.image_wrap_t);
            }
            if (!SE_ValidImageProjectionType
               (field_ptr->u.Image_Mapping_Function.image_projection_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Image_Projection_Type value (%d)\n", (int)
                        field_ptr->u.Image_Mapping_Function.image_projection_type);
            }
            if ((field_ptr->u.Image_Mapping_Function.intensity_level < 0.0) ||
                (field_ptr->u.Image_Mapping_Function.intensity_level > 1.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: intensity_level"\
                            " out of range [0.0, 1.0] in <Image Mapping Function>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Image_Mapping_Function.image_detail_mapping))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Image_Mapping_Function.image_detail_mapping);
            }
            break;

        case SE_CLS_DRM_IN_OUT:
            if (!SE_ValidBoolean(field_ptr->u.In_Out.input))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.In_Out.input);
            }
            break;

        case SE_CLS_DRM_INDEX_LOD_DATA:
            if (!SE_ValidIntegerPositive(field_ptr->u.Index_LOD_Data.index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Index_LOD_Data.index value"\
                            " (%d)\n", (int)
                        field_ptr->u.Index_LOD_Data.index);
            }
            break;

        case SE_CLS_DRM_INFINITE_LIGHT:
            if (!SE_ValidBoolean(field_ptr->u.Infinite_Light.apply_to_children)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Infinite_Light.apply_to_children);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Infinite_Light.override_positional_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Infinite_Light.override_positional_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Infinite_Light.override_infinite_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Infinite_Light.override_infinite_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Infinite_Light.active_light_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Infinite_Light.active_light_value);
            }
            break;

        case SE_CLS_DRM_INLINE_COLOUR:
            if (!SE_ValidColourMapping(
                      &(field_ptr->u.Inline_Colour.colour_mapping),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Colour_Mapping value\n");
                }
            }
            break;

        case SE_CLS_DRM_INTERFACE_TEMPLATE:
            if (!SE_ValidString(
                      &(field_ptr->u.Interface_Template.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_INTERVAL_AXIS:
            if (!EDCS_ValidAttributeCode(field_ptr->u.Interval_Axis.axis_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.Interval_Axis.axis_type);
            }
            if (!field_ptr->u.Interval_Axis.axis_interval_value_array)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL"\
                           " field_ptr->u.Interval_Axis.axis_interval_value_array"\
                           " for field_ptr->u.Interval_Axis.axis_value_count"\
                           " == %u\n",(unsigned int)
                            field_ptr->u.Interval_Axis.axis_value_count);
                }
            }
            else if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Interval_Axis.axis_value_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Interval_Axis.axis_value_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Interval_Axis.axis_value_count);
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Interval_Axis.axis_value_count; i++)
                {
                    if (!SE_ValidIntervalValue
                            (&(field_ptr->u.Interval_Axis.axis_interval_value_array[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_Interval_Value found at "\
                                "field_ptr->u.Interval_Axis.axis_interval_value_array[%u]\n", i);
                        }
                    }
                } /* end for i */
                if ((result == SE_TRUE) && (field_ptr->u.Interval_Axis.axis_value_count > 1))
                {
                    for (i = 0; (result == SE_TRUE) && (i <
                    (SE_Integer_Unsigned)field_ptr->u.Interval_Axis.axis_value_count-1);
                    i++)
                    {
                        for (j = i+1; (result == SE_TRUE) && (j <
                        (SE_Integer_Unsigned)field_ptr->u.Interval_Axis.axis_value_count);
                        j++)
                        {
                            if (SE_CompareIntervalValues
                        (&(field_ptr->u.Interval_Axis.axis_interval_value_array[i]),
                        &(field_ptr->u.Interval_Axis.axis_interval_value_array[j]))==0)
                            {
                                result = SE_FALSE;
                                if (print_error)
                                {
                                    fprintf(f_ptr, "Duplicate entry found at "\
                                    "field_ptr->u.Interval_Axis.axis_interval_value_array[%u]\n", j);
                                }
                            }
                        } /* end for j */
                    } /* end for i */
                }
            }
            if (!EDCS_ValidUnitCode(field_ptr->u.Interval_Axis.value_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Code value (%d)\n", (int)
                        field_ptr->u.Interval_Axis.value_unit);
            }
            else if (local_ValidEUForAttribute(field_ptr->u.Interval_Axis.axis_type,
                     field_ptr->u.Interval_Axis.value_unit, print_error,
                     f_ptr) != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates <<General Axis Constraints>> with"\
                            " incompatible %s\n",
                     EDCS_PrintUnitCode(field_ptr->u.Interval_Axis.value_unit));
            }
            if (!EDCS_ValidUnitScaleCode
               (field_ptr->u.Interval_Axis.value_scale))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Scale_Code value (%d)\n", (int)
                        field_ptr->u.Interval_Axis.value_scale);
            }
            if ((result == SE_TRUE) &&
                (field_ptr->u.Interval_Axis.axis_value_count > 1))
            {
                SE_Integer_Unsigned i, j;
                SE_Integer monotonicity = 0; /* 0 = not monotonic;
                                               -1 = decreasing
                                                1 = increasing */

                for (i = 1; (result == SE_TRUE) &&
                     (i < (SE_Integer_Unsigned)
                     field_ptr->u.Interval_Axis.axis_value_count); i++)
                {
                    if (field_ptr->u.Interval_Axis.
                        axis_interval_value_array[i].value_type
                     != field_ptr->u.Interval_Axis.
                        axis_interval_value_array[0].value_type)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr)
                            (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr,
                         "Error in SE_ValidDRMClassFields: "\
                         "axis_interval_value_array[%u].value_type "\
                         "violates <<General Axis Constraints>> constraint "\
                         "(value_type consistency) in <Interval Axis>!\n",
                                    (unsigned int)i);
                    }
                }

                for (i = 0; (result == SE_TRUE) &&
                     (i < (SE_Integer_Unsigned)
                     (field_ptr->u.Interval_Axis.axis_value_count-1)); i++)
                {
                    for (j = i+1; (result == SE_TRUE) &&
                         (j < (SE_Integer_Unsigned)
                         field_ptr->u.Interval_Axis.axis_value_count); j++)
                    {
                       /*
                        * Have already verified that no duplicates exist
                        */
                        if (SE_CompareIntervalValues
                            (&(field_ptr->u.Interval_Axis.axis_interval_value_array[i]),
                             &(field_ptr->u.Interval_Axis.axis_interval_value_array[j]))
                             < 0)
                        {
                            if (monotonicity == 0)
                                monotonicity = 1;
                            else if (monotonicity == -1)
                            {
                                result = SE_FALSE;
                                if (error_count_ptr)
                                   (*error_count_ptr)++;
                                if (print_error)
                                    fprintf(f_ptr,
                                      "Error in SE_ValidDRMClassFields: "\
                                      "array entries not monotonically "\
                                      "increasing in <Interval Axis>!\n");
                             }
                        }
                        else
                        {
                            if (monotonicity == 0)
                                monotonicity = -1;
                            else if (monotonicity == 1)
                            {
                               result = SE_FALSE;
                               if (error_count_ptr)
                                  (*error_count_ptr)++;
                               if (print_error)
                                  fprintf(f_ptr,
                                    "Error in SE_ValidDRMClassFields: "\
                                    "array entries not monotonically "\
                                    "decreasing in <Interval Axis>!\n");
                             }
                        }
                    }
                }
            }
            break;

        case SE_CLS_DRM_IRREGULAR_AXIS:
            if (!EDCS_ValidAttributeCode(field_ptr->u.Irregular_Axis.axis_type)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.Irregular_Axis.axis_type);
            }
            if (!field_ptr->u.Irregular_Axis.axis_value_array)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL"\
                           " field_ptr->u.Irregular_Axis.axis_value_array"\
                           " for"\
                           " field_ptr->u.Irregular_Axis.axis_value_count =="\
                           " %u\n",(unsigned int)
                            field_ptr->u.Irregular_Axis.axis_value_count);
                }
            }
            else if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Irregular_Axis.axis_value_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Irregular_Axis.axis_value_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Irregular_Axis.axis_value_count);
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Irregular_Axis.axis_value_count; i++)
                {
                    if (!SE_ValidSingleValue(
                            field_ptr->u.Irregular_Axis.axis_type,
                            &(field_ptr->u.Irregular_Axis.axis_value_array[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_Single_Value found at "\
                                "field_ptr->u.Irregular_Axis.axis_value_array[%u]\n", i);
                        }
                    }
                    else if ((field_ptr->u.Irregular_Axis.axis_value_array[i].value_type
                             ==SE_SINGVALTYP_ENUMERATION) ||
                            (field_ptr->u.Irregular_Axis.axis_value_array[i].value_type
                             ==SE_SINGVALTYP_CONSTRAINED_STRING) ||
                            (field_ptr->u.Irregular_Axis.axis_value_array[i].value_type
                             ==SE_SINGVALTYP_KEY) ||
                            (field_ptr->u.Irregular_Axis.axis_value_array[i].value_type
                             ==SE_SINGVALTYP_STRING) ||
                            (field_ptr->u.Irregular_Axis.axis_value_array[i].value_type
                             ==SE_SINGVALTYP_BOOLEAN))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Illegal value type SE_Single_Value found at "\
                                "field_ptr->u.Irregular_Axis.axis_value_array[%u]\n", i);
                        }
                    }
                } /* end for i */
                if ((result == SE_TRUE) && (field_ptr->u.Irregular_Axis.axis_value_count > 1))
                {
                    for (i = 0; (result == SE_TRUE) && (i <
                    (SE_Integer_Unsigned)field_ptr->u.Irregular_Axis.axis_value_count-1);
                    i++)
                    {
                        for (j = i+1; (result == SE_TRUE) && (j <
                        (SE_Integer_Unsigned)field_ptr->u.Irregular_Axis.axis_value_count);
                        j++)
                        {
                            if (SE_CompareSingleValues
                        (&(field_ptr->u.Irregular_Axis.axis_value_array[i]),
                        &(field_ptr->u.Irregular_Axis.axis_value_array[j]))==0)
                            {
                                result = SE_FALSE;
                                if (print_error)
                                {
                                    fprintf(f_ptr, "Duplicate entry found at "\
                                    "field_ptr->u.Irregular_Axis.axis_value_array[%u]\n", j);
                                }
                            }
                        } /* end for j */
                    } /* end for i */
                }
            }
            if (!EDCS_ValidUnitCode(field_ptr->u.Irregular_Axis.value_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Code value (%d)\n", (int)
                        field_ptr->u.Irregular_Axis.value_unit);
            }
            else if (local_ValidEUForAttribute(field_ptr->u.Irregular_Axis.axis_type,
                     field_ptr->u.Irregular_Axis.value_unit, print_error,
                     f_ptr) != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates <<General Axis Constraints>> with"\
                            " incompatible %s\n",
                     EDCS_PrintUnitCode(field_ptr->u.Irregular_Axis.value_unit));
            }
            if (!EDCS_ValidUnitScaleCode
               (field_ptr->u.Irregular_Axis.value_scale))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Scale_Code value (%d)\n", (int)
                        field_ptr->u.Irregular_Axis.value_scale);
            }
            if (!SE_ValidInterpolationType
               (field_ptr->u.Irregular_Axis.interpolation_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Interpolation_Type value (%d)\n", (int)
                        field_ptr->u.Irregular_Axis.interpolation_type);
            }
            else if ((field_ptr->u.Irregular_Axis.interpolation_type ==
                     SE_INTERPTYP_DISALLOWED) &&
                     ((field_ptr->u.Irregular_Axis.axis_type
                     ==EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE) ||
                     (field_ptr->u.Irregular_Axis.axis_type
                     ==EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE) ||
                     (field_ptr->u.Irregular_Axis.axis_type
                     ==EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE) ||
                     (field_ptr->u.Irregular_Axis.axis_type
                     ==EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE) ||
                     (field_ptr->u.Irregular_Axis.axis_type
                     ==EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE)))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates <<Spatial Axis Constraints>> with"\
                            " interpolation_type\n");
            }
            if ((result == SE_TRUE) &&
                (field_ptr->u.Irregular_Axis.axis_value_count > 1))
            {
                SE_Integer_Unsigned i, j;
                SE_Integer monotonicity = 0; /* 0 = not monotonic;
                                               -1 = decreasing
                                                1 = increasing */

                for (i = 1; (result == SE_TRUE) &&
                     (i < (SE_Integer_Unsigned)
                     field_ptr->u.Irregular_Axis.axis_value_count); i++)
                {
                    if (field_ptr->u.Irregular_Axis.
                        axis_value_array[i].value_type
                     != field_ptr->u.Irregular_Axis.
                        axis_value_array[0].value_type)
                    {
                        result = SE_FALSE;
                        if (error_count_ptr)
                            (*error_count_ptr)++;
                        if (print_error)
                            fprintf(f_ptr,
                         "Error in SE_ValidDRMClassFields: "\
                         "axis_value_array[%u].value_type "\
                         "violates <<General Axis Constraints>> constraint "\
                         "in <Irregular Axis>!\n", (unsigned int)i);
                    }
                }

                for (i = 0; (result == SE_TRUE) &&
                     (i < (SE_Integer_Unsigned)
                     (field_ptr->u.Irregular_Axis.axis_value_count-1)); i++)
                {
                    for (j = i+1; (result == SE_TRUE) &&
                         j < (SE_Integer_Unsigned)
                         field_ptr->u.Irregular_Axis.axis_value_count; j++)
                    {
                       /*
                        * Have already verified that no duplicates exist
                        */
                        if (SE_CompareSingleValues
                            (&(field_ptr->u.Irregular_Axis.axis_value_array[i]),
                             &(field_ptr->u.Irregular_Axis.axis_value_array[j]))
                             < 0)
                        {
                            if (monotonicity == 0)
                                monotonicity = 1;
                            else if (monotonicity == -1)
                              {
                               result = SE_FALSE;
                               if (error_count_ptr)
                                  (*error_count_ptr)++;
                               if (print_error)
                                   fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                                           " array entries not monotonically "\
                                           "increasing in <Irregular Axis>! \n");
                             }
                        }
                        else
                        {
                            if (monotonicity == 0)
                                monotonicity = -1;
                            else if (monotonicity == 1)
                            {
                                result = SE_FALSE;
                                if (error_count_ptr)
                                    (*error_count_ptr)++;
                                if (print_error)
                                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                                          " array entries not monotonically "\
                                          "decreasing in <Irregular Axis>!\n");
                             }
                        }
                    }
                }
            }
            break;

        case SE_CLS_DRM_KEYWORDS:
            if (!field_ptr->u.Keywords.keyword_array)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL field_ptr->u.Keywords.keyword_array"\
                           " for field_ptr->u.Keywords.keyword_count =="\
                           " %u\n",(unsigned int)
                            field_ptr->u.Keywords.keyword_count);
                }
            }
            else if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Keywords.keyword_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Keywords.keyword_count value"\
                            " (%d)\n", (int)
                        field_ptr->u.Keywords.keyword_count);
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Keywords.keyword_count; i++)
                {
                    if (!SE_ValidNonNullString
                            (&(field_ptr->u.Keywords.keyword_array[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_String found at "\
                                "field_ptr->u.Keywords.keyword_array[%u]\n", i);
                        }
                    }
                } /* end for i */
                if ((result == SE_TRUE) && (field_ptr->u.Keywords.keyword_count > 1))
                {
                    for (i = 0; (result == SE_TRUE) && (i <
                    (SE_Integer_Unsigned)field_ptr->u.Keywords.keyword_count-1);
                    i++)
                    {
                        for (j = i+1; (result == SE_TRUE) && (j <
                        (SE_Integer_Unsigned)field_ptr->u.Keywords.keyword_count);
                        j++)
                        {
                            if (SE_CompareStrings
                        (&(field_ptr->u.Keywords.keyword_array[i]),
                        &(field_ptr->u.Keywords.keyword_array[j]))==0)
                            {
                                result = SE_FALSE;
                                if (print_error)
                                {
                                    fprintf(f_ptr, "Duplicate entry found at "\
                                    "field_ptr->u.Keywords.keyword_array[%u]\n", j);
                                }
                            }
                        } /* end for j */
                    } /* end for i */
                }
            }
            if (!SE_ValidMDKeywordTypeCode(field_ptr->u.Keywords.type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_MD_KeywordTypeCode value (%d)\n", (int)
                        field_ptr->u.Keywords.type);
            }
            break;

        case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
            break;

        case SE_CLS_DRM_LCC_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_LCE_3D_LOCATION:
            break;

        case SE_CLS_DRM_LEGAL_CONSTRAINTS:
            if (!field_ptr->u.Legal_Constraints.use_limitation &&
                (field_ptr->u.Legal_Constraints.use_limitation_count>0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL"\
                           " field_ptr->u.Legal_Constraints.use_limitation"\
                           " for"\
                           " field_ptr->u.Legal_Constraints.use_limitation_count"\
                           " == %u\n",(unsigned int)
                            field_ptr->u.Legal_Constraints.use_limitation_count);
                }
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Legal_Constraints.use_limitation_count; i++)
                {
                    if (!SE_ValidNonNullString
                            (&(field_ptr->u.Legal_Constraints.use_limitation[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_String found at "\
                                "field_ptr->u.Legal_Constraints.use_limitation[%u]\n", i);
                        }
                    }
                } /* end for i */
                if ((result == SE_TRUE) && (field_ptr->u.Legal_Constraints.use_limitation_count > 1))
                {
                    for (i = 0; (result == SE_TRUE) && (i <
                    (SE_Integer_Unsigned)field_ptr->u.Legal_Constraints.use_limitation_count-1);
                    i++)
                    {
                        for (j = i+1; (result == SE_TRUE) && (j <
                        (SE_Integer_Unsigned)field_ptr->u.Legal_Constraints.use_limitation_count);
                        j++)
                        {
                            if (SE_CompareStrings
                        (&(field_ptr->u.Legal_Constraints.use_limitation[i]),
                        &(field_ptr->u.Legal_Constraints.use_limitation[j]))==0)
                            {
                                result = SE_FALSE;
                                if (print_error)
                                {
                                    fprintf(f_ptr, "Duplicate entry found at "\
                                    "field_ptr->u.Legal_Constraints.use_limitation[%u]\n", j);
                                }
                            }
                        } /* end for j */
                    } /* end for i */
                }
            }
            if (!SE_ValidMDRestrictionCode
               (field_ptr->u.Legal_Constraints.access_constraints))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_MD_RestrictionCode value (%d)\n", (int)
                        field_ptr->u.Legal_Constraints.access_constraints);
            }
            if (!SE_ValidMDRestrictionCode
               (field_ptr->u.Legal_Constraints.use_constraints))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_MD_RestrictionCode value (%d)\n", (int)
                        field_ptr->u.Legal_Constraints.use_constraints);
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Legal_Constraints.other_constraints),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((result == SE_TRUE) &&
                ((field_ptr->u.Legal_Constraints.access_constraints ==
                  SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS) ||
                 (field_ptr->u.Legal_Constraints.use_constraints ==
                  SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS)) &&
                (field_ptr->u.Legal_Constraints.other_constraints.length == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                    "access_constraints and/or use_constraints claim "\
                    "other restrictions but other_constraints empty "\
                    "in <Legal Constraints>!\n");
            }

            break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
            if (!SE_ValidPointLightDisplayType
               (field_ptr->u.Light_Rendering_Properties.display_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Point_Light_Display_Type value (%d)\n", (int)
                        field_ptr->u.Light_Rendering_Properties.display_type);
            }
            if (field_ptr->u.Light_Rendering_Properties.light_diameter < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: light_diameter"\
                            " < 0.0 in <Light Rendering Properties>!\n");
            }
            if (field_ptr->u.Light_Rendering_Properties.light_extinguishing_range < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: light_extinguishing_range"\
                            " < 0.0 in <Light Rendering Properties>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Light_Rendering_Properties.random_area_light))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Light_Rendering_Properties.random_area_light);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Light_Rendering_Properties.active_light_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Light_Rendering_Properties.active_light_value);
            }
            if (field_ptr->u.Light_Rendering_Properties.candela_value < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: candela_value"\
                            " < 0.0 in <Light Rendering Properties>!\n");
            }
            break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Light_Rendering_Properties_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.Light_Rendering_Properties_Control_Link.active_expression_index == 0) &&
                (field_ptr->u.Light_Rendering_Properties_Control_Link.candela_value_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: all"\
                            " expression_index = 0 in <Light Rendering Properties Control Link>!\n");
            }
            else if ((field_ptr->u.Light_Rendering_Properties_Control_Link.candela_value_expression_index == 0) &&
                ((field_ptr->u.Light_Rendering_Properties_Control_Link.lower_candela_value_index == 0) ||
                 (field_ptr->u.Light_Rendering_Properties_Control_Link.upper_candela_value_index == 0)))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: set"\
         " lower and/or upper but candela_value_expression_index = 0"\
         " in <Light Rendering Properties Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_LIGHT_SOURCE:
            if (!SE_ValidBoolean(field_ptr->u.Light_Source.apply_to_children))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Light_Source.apply_to_children);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Light_Source.override_positional_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Light_Source.override_positional_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Light_Source.override_infinite_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Light_Source.override_infinite_lights);
            }
            if (!SE_ValidBoolean(field_ptr->u.Light_Source.active_light_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Light_Source.active_light_value);
            }
            break;

        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Light_Source_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Light_Source_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Light_Source_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Light_Source_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_LINE:
            if (!SE_ValidBoolean(field_ptr->u.Line.suppress_last))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Line.suppress_last);
            }
            break;

        case SE_CLS_DRM_LINEAGE:
            if (!SE_ValidString(&(field_ptr->u.Lineage.statement),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_LINEAR_GEOMETRY:
            if (!SE_ValidBoolean(field_ptr->u.Linear_Geometry.suppress_last))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Linear_Geometry.suppress_last);
            }
            break;

        case SE_CLS_DRM_LITERAL:
            if (!SE_ValidSingleValue(EAC_NULL, &(field_ptr->u.Literal.value),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Single_Value value\n");
                }
            }
            break;

        case SE_CLS_DRM_LOBE_DATA:
            if ((field_ptr->u.Lobe_Data.horizontal_width < 0.0) ||
                (field_ptr->u.Lobe_Data.horizontal_width > 2.0*SE_LF_PI))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: horizontal_width"\
                            " out of range [0.0, 2.0*SE_LF_PI] in <Lobe Data>!\n");
            }
            if ((field_ptr->u.Lobe_Data.vertical_width < 0.0) ||
                (field_ptr->u.Lobe_Data.vertical_width > 2.0*SE_LF_PI))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: vertical_width"\
                            " out of range [0.0, 2.0*SE_LF_PI] in <Lobe Data>!\n");
            }
            break;

        case SE_CLS_DRM_LOCAL_4X4:
            break;

        case SE_CLS_DRM_LOD_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.LOD_Related_Features.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.LOD_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.LOD_Related_Features.strict_organizing_principle))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.LOD_Related_Features.strict_organizing_principle);
            }
            if (!SE_ValidLODDataType
               (field_ptr->u.LOD_Related_Features.lod_data_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_LOD_Data_Type value (%d)\n", (int)
                        field_ptr->u.LOD_Related_Features.lod_data_type);
            }
            break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.LOD_Related_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.LOD_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.LOD_Related_Geometry.strict_organizing_principle))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.LOD_Related_Geometry.strict_organizing_principle);
            }
            if (!SE_ValidLODDataType
               (field_ptr->u.LOD_Related_Geometry.lod_data_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_LOD_Data_Type value (%d)\n", (int)
                        field_ptr->u.LOD_Related_Geometry.lod_data_type);
            }
            break;

        case SE_CLS_DRM_LSA_2D_LOCATION:
            if (!SRM_ValidLSA2DCoordinate(
                      &(field_ptr->u.LSA_2D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_LSA_2D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_LSP_2D_LOCATION:
            if (!SRM_ValidLSP2DCoordinate(
                      &(field_ptr->u.LSP_2D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_LSP_2D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_LSR_2D_LOCATION:
            break;

        case SE_CLS_DRM_LSR_3D_LOCATION:
            break;

        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.LSR_3D_Location_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.LSR_3D_Location_Control_Link.u_expression_index == 0) &&
                (field_ptr->u.LSR_3D_Location_Control_Link.v_expression_index == 0) &&
                (field_ptr->u.LSR_3D_Location_Control_Link.w_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <LSR 3D Location Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_LTSAS_3D_LOCATION:
            if (!SRM_ValidLTSAS3DCoordinate(
                      &(field_ptr->u.LTSAS_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_LTSAS_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_LTSC_3D_LOCATION:
            if (!SRM_ValidLTSC3DCoordinate(
                      &(field_ptr->u.LTSC_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_LTSC_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
            if (!SRM_ValidLTSCSurfaceCoordinate(
                      &(field_ptr->u.LTSC_Surface_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_LTSC_Surface_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_LTSE_3D_LOCATION:
            break;

        case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
            break;

        case SE_CLS_DRM_M_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
            if (field_ptr->u.Map_Scale_LOD_Data.map_scale <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: map_scale"\
                            " <= 0.0 in <Map Scale LOD Data>!\n");
            }
            break;

        case SE_CLS_DRM_MESH_FACE_TABLE:
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Mesh_Face_Table.mesh_face_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Mesh_Face_Table.mesh_face_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Mesh_Face_Table.mesh_face_count);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Mesh_Face_Table.maximum_vertices_per_face))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Mesh_Face_Table.maximum_vertices_per_face"\
                            " value (%d)\n", (int)
                        field_ptr->u.Mesh_Face_Table.maximum_vertices_per_face);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Mesh_Face_Table.adjacent_face_table_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Mesh_Face_Table.adjacent_face_table_present);
            }
            break;

        case SE_CLS_DRM_MODEL:
            if (!SE_ValidNonNullString(&(field_ptr->u.Model.name), SE_FALSE,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Model.name is"\
                           " invalid\n");
            }
            if (!SE_ValidSRFContextInfo(
                      &(field_ptr->u.Model.srf_context_info), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_SRF_Context_Info value\n");
                }
            }
            else if ((field_ptr->u.Model.has_moving_parts == SE_TRUE) &&
                     (field_ptr->u.Model.srf_context_info.srf_parameters_info.
                      srf_params_info_code==SRM_SRFPARAMINFCOD_TEMPLATE) &&
                     ((field_ptr->u.Model.srf_context_info.srf_parameters_info.
                      value.srf_template.template_code !=
                      SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D) &&
                      (field_ptr->u.Model.srf_context_info.srf_parameters_info.
                      value.srf_template.template_code !=
                      SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D)))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "violates <<Model SRF>> constraint!\n");
            }
            if (!SE_ValidModelReferenceType
               (field_ptr->u.Model.model_reference_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Model_Reference_Type value (%d)\n", (int)
                        field_ptr->u.Model.model_reference_type);
            }
            else if ((field_ptr->u.Model.model_reference_type ==
                     SE_MODREFTYP_COMPONENT) &&
                     field_ptr->u.Model.dynamic_model_processing)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " SE_MODREFTYP_COMPONENT but"\
                            " dynamic_model_processing == SRM_TRUE\n");
            }
            if (!SE_ValidBoolean(field_ptr->u.Model.dynamic_model_processing))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Model.dynamic_model_processing);
            }
            if (!SE_ValidBoolean(field_ptr->u.Model.has_units))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Model.has_units);
            }
            if (!SE_ValidBoolean(field_ptr->u.Model.has_moving_parts))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Model.has_moving_parts);
            }
            break;

        case SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX:
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Model_Instance_Template_Index.index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Model_Instance_Template_Index.index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Model_Instance_Template_Index.index);
            }
            break;

        case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
            break;

        case SE_CLS_DRM_OCTANT_DATA:
            if (!SE_ValidOctant(field_ptr->u.Octant_Data.octant))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Octant value (%d)\n", (int)
                        field_ptr->u.Octant_Data.octant);
            }
            break;

        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
            if (field_ptr->u.Octant_Related_Features.unique_descendants != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: unique_descendants"\
                            " != SE_TRUE in <Octant Related Features>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Octant_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Octant_Related_Features.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
            if (field_ptr->u.Octant_Related_Geometry.unique_descendants != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: unique_descendants"\
                            " != SE_TRUE in <Octant Related Geometry>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Octant_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Octant_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
            break;

        case SE_CLS_DRM_OMS_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX:
            break;

        case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
            if ((field_ptr->u.Parallelepiped_Volume_Extent.edge_length[0] <= 0.0)
             || (field_ptr->u.Parallelepiped_Volume_Extent.edge_length[1] <= 0.0)
             || (field_ptr->u.Parallelepiped_Volume_Extent.edge_length[2] <= 0.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "edge_length entry <= 0.0 in <Parallelepiped Volume Extent>!\n");
            }

            break;

        case SE_CLS_DRM_PD_3D_LOCATION:
            if (!SRM_ValidPD3DCoordinate(
                      &(field_ptr->u.PD_3D_Location.coordinate), (SRM_Boolean)
                      print_error, (SRM_Integer_Unsigned *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_PD_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_PD_SURFACE_LOCATION:
            if (!SRM_ValidPDSurfaceCoordinate(
                      &(field_ptr->u.PD_Surface_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_PD_Surface_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
            if (!SE_ValidFeatureTopologyLevel
               (field_ptr->u.Perimeter_Related_Feature_Topology.feature_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Feature_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Perimeter_Related_Feature_Topology.feature_topology_level);
            }
            break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.Perimeter_Related_Features.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Perimeter_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Perimeter_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Perimeter_Related_Features.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Perimeter_Related_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Perimeter_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Perimeter_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Perimeter_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY:
            if (!SE_ValidGeometryTopologyLevel
               (field_ptr->u.Perimeter_Related_Geometry_Topology.geometry_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Geometry_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Perimeter_Related_Geometry_Topology.geometry_topology_level);
            }
            break;

        case SE_CLS_DRM_POLYGON:
            if (!SE_ValidPolygonFlag(&(field_ptr->u.Polygon.polygon_flags),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Polygon_Flag value\n");
                }
            }
            break;

        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Polygon_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.Polygon_Control_Link.hat_test_expression_index == 0) &&
                (field_ptr->u.Polygon_Control_Link.collidible_expression_index == 0) &&
                (field_ptr->u.Polygon_Control_Link.invisible_expression_index == 0) &&
                (field_ptr->u.Polygon_Control_Link.laser_range_finding_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <Polygon Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_POSITIONAL_LIGHT:
            if (!SE_ValidBoolean
               (field_ptr->u.Positional_Light.apply_to_children))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Positional_Light.apply_to_children);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Positional_Light.override_positional_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Positional_Light.override_positional_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Positional_Light.override_infinite_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Positional_Light.override_infinite_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Positional_Light.active_light_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Positional_Light.active_light_value);
            }
            if (field_ptr->u.Positional_Light.radius < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: radius"\
                            " < 0.0 in <Positional Light>!\n");
            }
            break;

        case SE_CLS_DRM_PREDEFINED_FUNCTION:
            if (!EDCS_ValidAttributeValueType
               (field_ptr->u.Predefined_Function.value_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Value_Type value (%d)\n", (int)
                        field_ptr->u.Predefined_Function.value_type);
            }
            else if ((field_ptr->u.Predefined_Function.value_type ==
                     EDCS_AVT_CONSTRAINED_STRING) ||
                     (field_ptr->u.Predefined_Function.value_type ==
                     EDCS_AVT_INDEX) ||
                     (field_ptr->u.Predefined_Function.value_type ==
                     EDCS_AVT_KEY) ||
                     (field_ptr->u.Predefined_Function.value_type ==
                     EDCS_AVT_NULL) ||
                     (field_ptr->u.Predefined_Function.value_type ==
                     EDCS_AVT_STRING))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: illegal"\
                            " value_type (%s) for <Predefined Function>\n",
                        EDCS_PrintAttributeValueType
                        (field_ptr->u.Predefined_Function.value_type));
            }
            if (!SE_ValidPredefinedFunction
               (field_ptr->u.Predefined_Function.function))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Predefined_Function value (%d)\n", (int)
                        field_ptr->u.Predefined_Function.function);
            }
            break;

        case SE_CLS_DRM_PRESENTATION_DOMAIN:
            if (!SE_ValidPresentationDomain(
                      &(field_ptr->u.Presentation_Domain.presentation_domain),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Presentation_Domain value\n");
                }
            }
            break;

        case SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM:
            if ((field_ptr->u.Primitive_Summary_Item.drm_class == SE_CLS_DRM_NULL) ||
               !SE_ValidDRMClass(field_ptr->u.Primitive_Summary_Item.drm_class)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_DRM_Class value (%d)\n", (int)
                        field_ptr->u.Primitive_Summary_Item.drm_class);
            }
            else if (!ValidPrimitiveSummaryType
                     (field_ptr->u.Primitive_Summary_Item.drm_class))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: illegal"\
                            " drm_class (%s) - must be reachable from"\
                            " <Primitive Feature> or <Primitive"\
                            " Geometry>\n",
                        SE_PrintDRMClass(field_ptr->u.Primitive_Summary_Item.drm_class));
            }
            break;

        case SE_CLS_DRM_PROCESS_STEP:
            if (!SE_ValidNonNullString(
                      &(field_ptr->u.Process_Step.description), SE_FALSE,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory"\
                           " field_ptr->u.Process_Step.description is"\
                           " invalid\n");
            }
            if (!SE_ValidNonNullString(&(field_ptr->u.Process_Step.rationale),
                      SE_FALSE, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory"\
                           " field_ptr->u.Process_Step.rationale is"\
                           " invalid\n");
            }
            break;

        case SE_CLS_DRM_PROPERTY:
            if (!SE_ValidPropertyCode(&(field_ptr->u.Property.meaning),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Property_Code value\n");
                }
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Property.apply_property_inheritance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Property.apply_property_inheritance);
            }
            break;

        case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
            if (!EDCS_ValidValueCharacteristicCode
               (field_ptr->u.Property_Characteristic.meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Value_Characteristic_Code value (%d)\n",
                        (int) field_ptr->u.Property_Characteristic.meaning);
            }
            if (!EDCS_ValidAttributeValue(EAC_NULL,
                      &(field_ptr->u.Property_Characteristic.characteristic_value),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " EDCS_Attribute_Value value\n");
                }
            }
            if (result == SE_TRUE)
            {
                const EDCS_Value_Characteristic_Dictionary_Entry *entry_ptr;

                if (EDCS_GetEVDictionaryEntry
                    (field_ptr->u.Property_Characteristic.meaning, &entry_ptr) !=
                    EDCS_SC_SUCCESS)
                {
                    result = SE_FALSE;
                    if (error_count_ptr)
                        (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr,
                          "Error in SE_ValidDRMClassFields: "\
                        "can't get applicability data for meaning "\
                        "in <Property Characteristic>!\n");
                }
                else if ((entry_ptr->applicability !=
                         EDCS_ATTR_VAL_CHAR_APPLICABILITY_ALL)
                     && ((field_ptr->u.Property_Characteristic.characteristic_value.
                         attribute_value_type==EDCS_AVT_BOOLEAN)
                      || (field_ptr->u.Property_Characteristic.characteristic_value.
                         attribute_value_type==EDCS_AVT_CONSTRAINED_STRING)
                      || (field_ptr->u.Property_Characteristic.characteristic_value.
                         attribute_value_type==EDCS_AVT_ENUMERATION)
                      || (field_ptr->u.Property_Characteristic.characteristic_value.
                         attribute_value_type==EDCS_AVT_KEY)
                      || (field_ptr->u.Property_Characteristic.characteristic_value.
                         attribute_value_type==EDCS_AVT_NULL)
                      || (field_ptr->u.Property_Characteristic.characteristic_value.
                         attribute_value_type==EDCS_AVT_STRING)))
                {
                    result = SE_FALSE;
                    if (error_count_ptr)
                        (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                        "meaning (%s) is not applicable to "\
                        "characteristic_value's type "\
                        "in <Property Characteristic>!\n",
                        EDCS_PrintValueCharacteristicCode
                        (field_ptr->u.Property_Characteristic.meaning));
                }
            }
            break;

        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
            if (!SE_ValidPropertyCode(
                      &(field_ptr->u.Property_Description.meaning),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Property_Code value\n");
                }
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Property_Description.apply_property_inheritance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Property_Description.apply_property_inheritance);
            }
            break;

        case SE_CLS_DRM_PROPERTY_GRID:
            if (!field_ptr->u.Property_Grid.location_index)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL"\
                           " field_ptr->u.Property_Grid.location_index for"\
                           " field_ptr->u.Property_Grid.spatial_axes_count"\
                           " == %u\n",(unsigned int)
                            field_ptr->u.Property_Grid.spatial_axes_count);
                }
            }
            else if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Property_Grid.spatial_axes_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Property_Grid.spatial_axes_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Property_Grid.spatial_axes_count);
            }
            if (!SE_ValidSRFContextInfo(
                      &(field_ptr->u.Property_Grid.srf_context_info),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_SRF_Context_Info value\n");
                }
            }
            if (!SE_ValidBoolean(field_ptr->u.Property_Grid.data_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Property_Grid.data_present);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Property_Grid.relative_to_hook_point))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Property_Grid.relative_to_hook_point);
            }
            break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX:
            if (!SE_ValidIntegerPositive(field_ptr->u.Property_Set_Index.index)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Property_Set_Index.index value"\
                            " (%d)\n", (int)
                        field_ptr->u.Property_Set_Index.index);
            }
            break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Property_Set_Index_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Property_Set_Index_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Property_Set_Index_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Property_Set_Index_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE:
            if (!SE_ValidString(
                      &(field_ptr->u.Property_Set_Table.table_usage),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidBoolean(field_ptr->u.Property_Set_Table.regular))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Property_Set_Table.regular);
            }
            break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP:
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Property_Set_Table_Group.primary_table_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Property_Set_Table_Group.primary_table_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Property_Set_Table_Group.primary_table_index);
            }
            else if (field_ptr->u.Property_Set_Table_Group.primary_table_index
               > field_ptr->u.Property_Set_Table_Group.table_size)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "field_ptr->u.Property_Set_Table_Group.primary_table_index"\
                            "value (%u) > "\
                            "field_ptr->u.Property_Set_Table_Group.table_size"\
                            "table_size (%u)\n", (unsigned int)
                        field_ptr->u.Property_Set_Table_Group.primary_table_index,
                        (unsigned int)
                        field_ptr->u.Property_Set_Table_Group.table_size);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Property_Set_Table_Group.table_size))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Property_Set_Table_Group.table_size"\
                            " value (%d)\n", (int)
                        field_ptr->u.Property_Set_Table_Group.table_size);
            }
            break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
            if (!EDCS_ValidAttributeCode
               (field_ptr->u.Property_Table_Reference.axis_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.Property_Table_Reference.axis_type);
            }
            break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Property_Table_Reference_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Property_Table_Reference_Control_Link.expression_index)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Property_Table_Reference_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Property_Table_Reference_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_PROPERTY_VALUE:
            if (!SE_ValidPropertyCode(&(field_ptr->u.Property_Value.meaning),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Property_Code value\n");
                }
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Property_Value.apply_property_inheritance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Property_Value.apply_property_inheritance);
            }
            if (!local_SpecialTypeForProperty(
                &(field_ptr->u.Property_Value.meaning),
                &(field_ptr->u.Property_Value.value), print_error,
                error_count_ptr, &result, f_ptr) &&!EDCS_ValidAttributeValue(
                ((field_ptr->u.Property_Value.meaning.code_type ==
                SE_PROPCODTYP_ATTRIBUTE) ?
                field_ptr->u.Property_Value.meaning.code.attribute :
                EAC_NULL), &(field_ptr->u.Property_Value.value),
                (EDCS_Boolean) print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " EDCS_Attribute_Value value\n");
                }
            }
            break;

        case SE_CLS_DRM_PROXIMITY_DATA:
            if (!SE_ValidSpatialAssociationMeaningType
               (field_ptr->u.Proximity_Data.meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Association_Meaning_Type value"\
                            " (%d)\n", (int)
                        field_ptr->u.Proximity_Data.meaning);
            }
            if (field_ptr->u.Proximity_Data.distance < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: distance"\
                            " < 0.0 in <Proximity Data>!\n");
            }
            break;

        case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
            break;

        case SE_CLS_DRM_PS_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
            if (!EDCS_ValidAttributeValueType
               (field_ptr->u.Pseudo_Code_Function.value_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Value_Type value (%d)\n", (int)
                        field_ptr->u.Pseudo_Code_Function.value_type);
            }
            else if ((field_ptr->u.Pseudo_Code_Function.value_type ==
                     EDCS_AVT_CONSTRAINED_STRING) ||
                     (field_ptr->u.Pseudo_Code_Function.value_type ==
                     EDCS_AVT_INDEX) ||
                     (field_ptr->u.Pseudo_Code_Function.value_type ==
                     EDCS_AVT_KEY) ||
                     (field_ptr->u.Pseudo_Code_Function.value_type ==
                     EDCS_AVT_NULL) ||
                     (field_ptr->u.Pseudo_Code_Function.value_type ==
                     EDCS_AVT_STRING))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: illegal"\
                            " value_type (%s) for <Pseudo Code Function>\n",
                        EDCS_PrintAttributeValueType
                        (field_ptr->u.Pseudo_Code_Function.value_type));
            }
            if (!SE_ValidString(&(field_ptr->u.Pseudo_Code_Function.name),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Pseudo_Code_Function.pseudo_code),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT:
            if (!SE_ValidBoolean
               (field_ptr->u.Pyramid_Directional_Light.use_full_intensity))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Pyramid_Directional_Light.use_full_intensity);
            }
            if ((field_ptr->u.Pyramid_Directional_Light.minimum_colour_intensity < 0.0) ||
                (field_ptr->u.Pyramid_Directional_Light.minimum_colour_intensity > 1.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minimum_colour_intensity"\
                            " out of range [0.0, 1.0] in <Pyramid Directional Light>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Pyramid_Directional_Light.invisible_behind))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Pyramid_Directional_Light.invisible_behind);
            }
            break;

        case SE_CLS_DRM_QUADRANT_DATA:
            if (!SE_ValidQuadrant(field_ptr->u.Quadrant_Data.quadrant))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Quadrant value (%d)\n", (int)
                        field_ptr->u.Quadrant_Data.quadrant);
            }
            break;

        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
            if (field_ptr->u.Quadrant_Related_Features.unique_descendants != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: unique_descendants"\
                            " != SE_TRUE in <Quadrant Related Features>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Quadrant_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Quadrant_Related_Features.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
            if (field_ptr->u.Quadrant_Related_Geometry.unique_descendants != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: unique_descendants"\
                            " != SE_TRUE in <Quadrant Related Geometry>!\n");
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Quadrant_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Quadrant_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_REFERENCE_ORIGIN:
            if (!SE_ValidSRFContextInfo(
                      &(field_ptr->u.Reference_Origin.srf_context_info),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_SRF_Context_Info value\n");
                }
            }
            break;

        case SE_CLS_DRM_REFERENCE_SURFACE:
            if (!EDCS_ValidClassificationCode
               (field_ptr->u.Reference_Surface.classification))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Classification_Code value (%d)\n", (int)
                        field_ptr->u.Reference_Surface.classification);
            }
            if (!SE_ValidReferenceSurfaceElevationSelect
               (field_ptr->u.Reference_Surface.multiplicity_rule))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Reference_Surface_Elevation_Select value"\
                            " (%d)\n", (int)
                        field_ptr->u.Reference_Surface.multiplicity_rule);
            }
            if (!SE_ValidReferenceSurfaceLODSelect
               (field_ptr->u.Reference_Surface.lod_rule))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Reference_Surface_LOD_Select value (%d)\n",
                        (int) field_ptr->u.Reference_Surface.lod_rule);
            }
            break;

        case SE_CLS_DRM_REFERENCE_VECTOR:
            {
                SRM_Long_Float magnitude;

                if ((SRM_VectorMagnitude
                    (field_ptr->u.Reference_Vector.
                     unit_vector, &magnitude) != SRM_STATCOD_SUCCESS) ||
                        !SRM_EQUAL(magnitude, 1.0, 0.0001))
                {
                    result = SE_FALSE;
                    if (error_count_ptr)
                        (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr,
                                "<Reference Vector> has magnitude "\
                                "%s (must be a unit vector)\n",
                                SRM_PrintLongFloat(magnitude));
                }
            }
            if (!SE_ValidReferenceVectorType
               (field_ptr->u.Reference_Vector.vector_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Reference_Vector_Type value (%d)\n", (int)
                        field_ptr->u.Reference_Vector.vector_type);
            }
            break;

        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Reference_Vector_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.Reference_Vector_Control_Link.v0_expression_index == 0) &&
                (field_ptr->u.Reference_Vector_Control_Link.v1_expression_index == 0) &&
                (field_ptr->u.Reference_Vector_Control_Link.v2_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <Reference Vector Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_REGULAR_AXIS:
            if (!EDCS_ValidAttributeCode(field_ptr->u.Regular_Axis.axis_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.axis_type);
            }
            else
            {
                const EDCS_Attribute_Dictionary_Entry *ade = NULL;

                EDCS_GetEADictionaryEntry(field_ptr->u.Regular_Axis.axis_type,
                                          &ade);
                if ((ade->value_type == EDCS_AVT_BOOLEAN) ||
                    (ade->value_type == EDCS_AVT_STRING) ||
                    (ade->value_type ==
                     EDCS_AVT_CONSTRAINED_STRING) ||
                    (ade->value_type == EDCS_AVT_KEY) ||
                    (ade->value_type ==
                     EDCS_AVT_ENUMERATION) ||
                    (ade->value_type == EDCS_AVT_NULL))
                    {
                      result = SE_FALSE;
                      if (error_count_ptr)
                         (*error_count_ptr)++;
                      if (print_error)
                         fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                          "violates <<General Axis Constraints>> constraint "\
                          "(non-numeric EA)!\n");
                   }
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Regular_Axis.axis_value_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Regular_Axis.axis_value_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.axis_value_count);
            }
            if (!EDCS_ValidUnitCode(field_ptr->u.Regular_Axis.value_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Code value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.value_unit);
            }
            else if (local_ValidEUForAttribute(field_ptr->u.Regular_Axis.axis_type,
                     field_ptr->u.Regular_Axis.value_unit, print_error, f_ptr)
                     != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates <<General Axis Constraints>> with"\
                            " incompatible %s\n",
                     EDCS_PrintUnitCode(field_ptr->u.Regular_Axis.value_unit));
            }
            if (!EDCS_ValidUnitScaleCode(field_ptr->u.Regular_Axis.value_scale)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Scale_Code value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.value_scale);
            }
            if (!SE_ValidInterpolationType
               (field_ptr->u.Regular_Axis.interpolation_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Interpolation_Type value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.interpolation_type);
            }
            else if ((field_ptr->u.Regular_Axis.interpolation_type ==
                     SE_INTERPTYP_DISALLOWED) &&
                     ((field_ptr->u.Regular_Axis.axis_type
                     ==EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE) ||
                     (field_ptr->u.Regular_Axis.axis_type
                     ==EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE) ||
                     (field_ptr->u.Regular_Axis.axis_type
                     ==EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE) ||
                     (field_ptr->u.Regular_Axis.axis_type
                     ==EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE) ||
                     (field_ptr->u.Regular_Axis.axis_type
                     ==EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE)))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates <<Spatial Axis Constraints>> with"\
                            " interpolation_type\n");
            }
            if (!SE_ValidSingleValue(field_ptr->u.Regular_Axis.axis_type,
                      &(field_ptr->u.Regular_Axis.first_value), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Single_Value value\n");
                }
            }
            if (!SE_ValidSingleValue(field_ptr->u.Regular_Axis.axis_type,
                      &(field_ptr->u.Regular_Axis.spacing), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Single_Value value\n");
                }
            }
            if (!SE_ValidSpacingType(field_ptr->u.Regular_Axis.spacing_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spacing_Type value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.spacing_type);
            }
            if (!SE_ValidAxisAlignment
               (field_ptr->u.Regular_Axis.axis_alignment))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Axis_Alignment value (%d)\n", (int)
                        field_ptr->u.Regular_Axis.axis_alignment);
            }
            if (result == SE_TRUE)
            {
                SE_Boolean firstValueIsSame  = SE_FALSE;
                SE_Boolean isZeroValue = SE_FALSE;
                SE_Boolean nonNumericSpacing = SE_FALSE;

                switch(field_ptr->u.Regular_Axis.spacing.value_type)
                {
                   case SE_SINGVALTYP_LONG_FLOAT:
                        if (field_ptr->u.Regular_Axis.spacing.value.long_float_value == 0.0)
                        {
                            isZeroValue = SE_TRUE;
                        }

                        if (field_ptr->u.Regular_Axis.first_value.value_type == SE_SINGVALTYP_LONG_FLOAT)
                           firstValueIsSame = SE_TRUE;
                        break;

                   case SE_SINGVALTYP_INTEGER:
                       if (field_ptr->u.Regular_Axis.spacing.value.integer_value == 0)
                       {
                           isZeroValue = SE_TRUE;
                       }

                       if (field_ptr->u.Regular_Axis.first_value.value_type == SE_SINGVALTYP_INTEGER)
                           firstValueIsSame = SE_TRUE;
                       break;

                   case SE_SINGVALTYP_COUNT:
                        if (field_ptr->u.Regular_Axis.spacing.value.count_value == 0)
                        {
                            isZeroValue = SE_TRUE;
                        }

                        if (field_ptr->u.Regular_Axis.first_value.value_type == SE_SINGVALTYP_COUNT)
                            firstValueIsSame = SE_TRUE;
                        break;

                   case SE_SINGVALTYP_INDEX:
                        if (field_ptr->u.Regular_Axis.spacing.value.index_value == 0)
                        {
                            isZeroValue = SE_TRUE;
                        }

                        if (field_ptr->u.Regular_Axis.first_value.value_type == SE_SINGVALTYP_INDEX)
                            firstValueIsSame = SE_TRUE;
                        break;

                   default:
                        nonNumericSpacing = SE_TRUE;
                        break;
                }

                if (nonNumericSpacing == SE_TRUE)
                {
                    result = SE_FALSE;
                    if (error_count_ptr)
                        (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                                "non-numeric value spacing in <Regular Axis>!\n");
                }
                else if (isZeroValue == SE_TRUE)
                {
                    result = SE_FALSE;
                    if (error_count_ptr)
                        (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                                "zero value spacing in <Regular Axis>!\n");
                }
                else if (firstValueIsSame == SE_FALSE)
                {
                    result = SE_FALSE;
                    if (error_count_ptr)
                        (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                                "first_value.value_type != "\
                                "spacing.value_type in <Regular Axis>!\n");
                }
            }
            break;

        case SE_CLS_DRM_RELATIVE_TIME:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Relative_Time.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Relative_Time.time_significance);
            }
            if (field_ptr->u.Relative_Time.delta_hours > 23)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_hours"\
                            " > 23 in <Relative Time>!\n");
            }
            if (field_ptr->u.Relative_Time.delta_minutes > 59)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_minutes"\
                            " > 59 in <Relative Time>!\n");
            }
            if ((field_ptr->u.Relative_Time.delta_seconds < 0.0) ||
                (field_ptr->u.Relative_Time.delta_seconds > 61.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_seconds"\
                            " out of range [0.0, 61.0] in <Relative Time>!\n");
            }
            break;

        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Relative_Time_Interval.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Relative_Time_Interval.time_significance);
            }
            if (field_ptr->u.Relative_Time_Interval.delta_start_hours > 23)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_start_hours"\
                            " > 23 in <Relative Time Interval>!\n");
            }
            if (field_ptr->u.Relative_Time_Interval.delta_stop_hours > 23)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_stop_hours"\
                            " > 23 in <Relative Time Interval>!\n");
            }
            if (field_ptr->u.Relative_Time_Interval.delta_start_minutes > 59)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_start_minutes"\
                            " > 59 in <Relative Time Interval>!\n");
            }
            if (field_ptr->u.Relative_Time_Interval.delta_stop_minutes > 59)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_stop_minutes"\
                            " > 59 in <Relative Time Interval>!\n");
            }
            if ((field_ptr->u.Relative_Time_Interval.delta_start_seconds < 0.0) ||
                (field_ptr->u.Relative_Time_Interval.delta_start_seconds >= 60.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_start_seconds"\
                            " out of range [0.0, 60.0) in <Relative Time Interval>!\n");
            }
            if ((field_ptr->u.Relative_Time_Interval.delta_stop_seconds < 0.0) ||
                (field_ptr->u.Relative_Time_Interval.delta_stop_seconds >= 60.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delta_stop_seconds"\
                            " out of range [0.0, 60.0) in <Relative Time Interval>!\n");
            }
            break;

        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Rendering_Priority_Level.rendering_group))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Rendering_Priority_Level.rendering_group"\
                            " value (%d)\n", (int)
                        field_ptr->u.Rendering_Priority_Level.rendering_group);
            }
            break;

        case SE_CLS_DRM_RENDERING_PROPERTIES:
            if (!SE_ValidPixelFillMethod
               (field_ptr->u.Rendering_Properties.fill_method))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Pixel_Fill_Method value (%d)\n", (int)
                        field_ptr->u.Rendering_Properties.fill_method);
            }
            if (!SE_ValidShadingMethod
               (field_ptr->u.Rendering_Properties.shading_method))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Shading_Method value (%d)\n", (int)
                        field_ptr->u.Rendering_Properties.shading_method);
            }
            if (!SE_ValidColourBinding
               (field_ptr->u.Rendering_Properties.colour_binding))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Colour_Binding value (%d)\n", (int)
                        field_ptr->u.Rendering_Properties.colour_binding);
            }
            if (!SE_ValidDisplayStyle(
                      &(field_ptr->u.Rendering_Properties.style), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Display_Style value\n");
                }
            }
            if (!SE_ValidDisplaySide(
                      &(field_ptr->u.Rendering_Properties.side), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Display_Side value\n");
                }
            }
            break;

        case SE_CLS_DRM_RESPONSIBLE_PARTY:
            if (!SE_ValidString(
                      &(field_ptr->u.Responsible_Party.individual_name),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Responsible_Party.organization_name),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Responsible_Party.position_name),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidContactInformation(
                      &(field_ptr->u.Responsible_Party.contact_information),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Contact_Information value\n");
                }
            }
            if ((result == SE_TRUE)
             && (field_ptr->u.Responsible_Party.individual_name.length == 0)
             && (field_ptr->u.Responsible_Party.organization_name.length == 0)
             && (field_ptr->u.Responsible_Party.position_name.length == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                    "violation of <<Mandatory Metadata>> -"\
                    "individual_name, organization_name, position_name"\
                    "all empty in <Responsible Party>!\n");
            }
            break;

        case SE_CLS_DRM_RGB_COLOUR:
            if (!SE_ValidRGBData(&(field_ptr->u.RGB_Colour.rgb_data),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_RGB_Data value\n");
                }
            }
            break;

        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.RGB_Colour_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.RGB_Colour_Control_Link.red_expression_index == 0) &&
                (field_ptr->u.RGB_Colour_Control_Link.green_expression_index == 0) &&
                (field_ptr->u.RGB_Colour_Control_Link.blue_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <RGB Colour Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_ROLE_DATA:
            if (!SE_ValidCIRoleCode(field_ptr->u.Role_Data.role))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_CI_RoleCode value (%d)\n", (int)
                        field_ptr->u.Role_Data.role);
            }
            break;

        case SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR:
            break;

        case SE_CLS_DRM_ROTATION:
            if (!SE_ValidLSRTransformationAxis(field_ptr->u.Rotation.axis))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_LSR_Transformation_Axis value (%d)\n", (int)
                        field_ptr->u.Rotation.axis);
            }
            break;

        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Rotation_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Rotation_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Rotation_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Rotation_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_SCALE:
            if (!SE_ValidLSRTransformationAxis(field_ptr->u.Scale.axis))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_LSR_Transformation_Axis value (%d)\n", (int)
                        field_ptr->u.Scale.axis);
            }
            if (field_ptr->u.Scale.scale_factor == 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: scale_factor"\
                            " == 0.0 in <Scale>!\n");
            }
            break;

        case SE_CLS_DRM_SCALE_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Scale_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Scale_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Scale_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Scale_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_SEASON:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Season.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Season.time_significance);
            }
            if (!SE_ValidSeason(field_ptr->u.Season.season))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Season value (%d)\n", (int)
                        field_ptr->u.Season.season);
            }
            break;

        case SE_CLS_DRM_SECURITY_CONSTRAINTS:
            if (!field_ptr->u.Security_Constraints.use_limitation &&
                (field_ptr->u.Security_Constraints.use_limitation_count>0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                {
                    fprintf(f_ptr,"NULL"\
                           " field_ptr->u.Security_Constraints.use_limitation"\
                           " for"\
                           " field_ptr->u.Security_Constraints.use_limitation_count"\
                           " == %u\n",(unsigned int)
                            field_ptr->u.Security_Constraints.use_limitation_count);
                }
            }
            else
            {
                SE_Integer_Unsigned i, j;

                for (i = 0; i < (SE_Integer_Unsigned)field_ptr->u.Security_Constraints.use_limitation_count; i++)
                {
                    if (!SE_ValidNonNullString
                            (&(field_ptr->u.Security_Constraints.use_limitation[i]),
                            print_error, error_count_ptr))
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Invalid SE_String found at "\
                                "field_ptr->u.Security_Constraints.use_limitation[%u]\n", i);
                        }
                    }
                } /* end for i */
                if ((result == SE_TRUE) && (field_ptr->u.Security_Constraints.use_limitation_count > 1))
                {
                    for (i = 0; (result == SE_TRUE) && (i <
                    (SE_Integer_Unsigned)field_ptr->u.Security_Constraints.use_limitation_count-1);
                    i++)
                    {
                        for (j = i+1; (result == SE_TRUE) && (j <
                        (SE_Integer_Unsigned)field_ptr->u.Security_Constraints.use_limitation_count);
                        j++)
                        {
                            if (SE_CompareStrings
                        (&(field_ptr->u.Security_Constraints.use_limitation[i]),
                        &(field_ptr->u.Security_Constraints.use_limitation[j]))==0)
                            {
                                result = SE_FALSE;
                                if (print_error)
                                {
                                    fprintf(f_ptr, "Duplicate entry found at "\
                                    "field_ptr->u.Security_Constraints.use_limitation[%u]\n", j);
                                }
                            }
                        } /* end for j */
                    } /* end for i */
                }
            }
            if (!SE_ValidMDClassificationCode
               (field_ptr->u.Security_Constraints.classification))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_MD_ClassificationCode value (%d)\n", (int)
                        field_ptr->u.Security_Constraints.classification);
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Security_Constraints.user_note),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Security_Constraints.classification_system),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidString(
                      &(field_ptr->u.Security_Constraints.handling_description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((result == SE_TRUE)
             && (field_ptr->u.Security_Constraints.classification !=
                  SE_MD_CLSCOD_UNCLASSIFIED)
             && (field_ptr->u.Security_Constraints.classification_system.length == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                    "violation of <<Mandatory Metadata>> -"\
                    "classification_system not specified for "\
                    "classification %s in <Security Constraints>!\n"
,                    SE_PrintMDClassificationCode
                    (field_ptr->u.Security_Constraints.classification));
            }
            break;

        case SE_CLS_DRM_SEC_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.SEC_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_SEPARATING_PLANE_DATA:
            if (!SE_ValidBoolean(field_ptr->u.Separating_Plane_Data.positive))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Separating_Plane_Data.positive);
            }
            break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Separating_Plane_Related_Geometry.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Separating_Plane_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Separating_Plane_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Separating_Plane_Related_Geometry.strict_organizing_principle);
            }
            break;

        case SE_CLS_DRM_SEQ_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.SEQ_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_SMD_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.SMD_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_SME_3D_LOCATION:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(field_ptr->u.SME_3D_Location.coordinate),
                      (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SRM_Spherical_3D_Coordinate value\n");
                }
            }
            break;

        case SE_CLS_DRM_SOUND:
            if (!SE_ValidNonNullString(&(field_ptr->u.Sound.name), SE_FALSE,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Sound.name is"\
                           " invalid\n");
            }
            if (!SE_ValidSoundFormat(field_ptr->u.Sound.sound_format))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Sound_Format value (%d)\n", (int)
                        field_ptr->u.Sound.sound_format);
            }
            if (!SE_ValidURN(&(field_ptr->u.Sound.sound_urn), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_URN value\n");
                }
            }
            if (!SE_ValidBytePositive(field_ptr->u.Sound.bits_per_sample))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Sound.bits_per_sample value"\
                            " (%d)\n", (int)
                        field_ptr->u.Sound.bits_per_sample);
            }
            if (!SE_ValidBytePositive(field_ptr->u.Sound.channel_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Sound.channel_count value"\
                            " (%d)\n", (int) field_ptr->u.Sound.channel_count);
            }
            if (!SE_ValidString(&(field_ptr->u.Sound.method), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_SOUND_INSTANCE:
            if (!SE_ValidBoolean
               (field_ptr->u.Sound_Instance.active_sound_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Sound_Instance.active_sound_value);
            }
            break;

        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Sound_Instance_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Sound_Instance_Control_Link.active_sound_value_expression_index)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Sound_Instance_Control_Link.active_sound_value_expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Sound_Instance_Control_Link.active_sound_value_expression_index);
            }
            break;

        case SE_CLS_DRM_SOURCE:
            if (!SE_ValidNonNullString(&(field_ptr->u.Source.description),
                      SE_FALSE, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Source.description"\
                           " is invalid\n");
            }
            if (!SE_ValidIntegerPositive(field_ptr->u.Source.scale))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Source.scale value (%d)\n", (int)
                        field_ptr->u.Source.scale);
            }
            if (!SE_ValidString(&(field_ptr->u.Source.contribution),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            break;

        case SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA:
            if (!SE_ValidSpatialAssociationMeaningType
               (field_ptr->u.Spatial_Association_Data.meaning))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Association_Meaning_Type value"\
                            " (%d)\n", (int)
                        field_ptr->u.Spatial_Association_Data.meaning);
            }
            break;

        case SE_CLS_DRM_SPATIAL_INDEX_DATA:
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Data.row_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Data.row_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Data.row_index);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Data.column_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Data.column_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Data.column_index);
            }
            break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
            if (!SE_ValidFeatureTopologyLevel
               (field_ptr->u.Spatial_Index_Related_Feature_Topology.feature_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Feature_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Feature_Topology.feature_topology_level);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Feature_Topology.sparse))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Feature_Topology.sparse);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Feature_Topology.column_count)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Feature_Topology.column_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Feature_Topology.column_count);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Feature_Topology.row_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Feature_Topology.row_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Feature_Topology.row_count);
            }
            if (field_ptr->u.Spatial_Index_Related_Feature_Topology.column_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: column_width"\
                            " <= 0.0 in <Spatial Index Related Feature Topology>!\n");
            }
            if (field_ptr->u.Spatial_Index_Related_Feature_Topology.row_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: row_width"\
                            " <= 0.0 in <Spatial Index Related Feature Topology>!\n");
            }
            if (!SE_ValidSpatialIndexSpacingUnit
               (field_ptr->u.Spatial_Index_Related_Feature_Topology.spacing_unit)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Index_Spacing_Unit value (%d)\n",
                        (int)
                        field_ptr->u.Spatial_Index_Related_Feature_Topology.spacing_unit);
            }
            break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Features.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Features.strict_organizing_principle);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Features.sparse))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Features.sparse);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Features.column_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Features.column_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Features.column_count);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Features.row_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Features.row_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Features.row_count);
            }
            if (field_ptr->u.Spatial_Index_Related_Features.column_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: column_width"\
                            " <= 0.0 in <Spatial Index Related Features>!\n");
            }
            if (field_ptr->u.Spatial_Index_Related_Features.row_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: row_width"\
                            " <= 0.0 in <Spatial Index Related Features>!\n");
            }
            if (!SE_ValidSpatialIndexSpacingUnit
               (field_ptr->u.Spatial_Index_Related_Features.spacing_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Index_Spacing_Unit value (%d)\n",
                        (int)
                        field_ptr->u.Spatial_Index_Related_Features.spacing_unit);
            }
            break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Geometry.unique_descendants)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry.strict_organizing_principle);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Geometry.sparse))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry.sparse);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Geometry.column_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Geometry.column_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry.column_count);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Geometry.row_count))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Geometry.row_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry.row_count);
            }
            if (field_ptr->u.Spatial_Index_Related_Geometry.column_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: column_width"\
                            " <= 0.0 in <Spatial Index Related Geometry>!\n");
            }
            if (field_ptr->u.Spatial_Index_Related_Geometry.row_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: row_width"\
                            " <= 0.0 in <Spatial Index Related Geometry>!\n");
            }
            if (!SE_ValidSpatialIndexSpacingUnit
               (field_ptr->u.Spatial_Index_Related_Geometry.spacing_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Index_Spacing_Unit value (%d)\n",
                        (int)
                        field_ptr->u.Spatial_Index_Related_Geometry.spacing_unit);
            }
            break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
            if (!SE_ValidGeometryTopologyLevel
               (field_ptr->u.Spatial_Index_Related_Geometry_Topology.geometry_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Geometry_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry_Topology.geometry_topology_level);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spatial_Index_Related_Geometry_Topology.sparse))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry_Topology.sparse);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Geometry_Topology.column_count)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Geometry_Topology.column_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry_Topology.column_count);
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Spatial_Index_Related_Geometry_Topology.row_count)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Spatial_Index_Related_Geometry_Topology.row_count"\
                            " value (%d)\n", (int)
                        field_ptr->u.Spatial_Index_Related_Geometry_Topology.row_count);
            }
            if (field_ptr->u.Spatial_Index_Related_Geometry_Topology.column_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: column_width"\
                            " <= 0.0 in <Spatial Index Related Geometry Topology>!\n");
            }
            if (field_ptr->u.Spatial_Index_Related_Geometry_Topology.row_width <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: row_width"\
                            " <= 0.0 in <Spatial Index Related Geometry Topology>!\n");
            }
            if (!SE_ValidSpatialIndexSpacingUnit
               (field_ptr->u.Spatial_Index_Related_Geometry_Topology.spacing_unit)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Index_Spacing_Unit value (%d)\n",
                        (int)
                        field_ptr->u.Spatial_Index_Related_Geometry_Topology.spacing_unit);
            }
            break;

        case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
            if (field_ptr->u.Spatial_Resolution_LOD_Data.spatial_resolution <= 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: spatial_resolution"\
                            " <= 0.0 in <Spatial Resolution LOD Data>!\n");
            }
            if (!SE_ValidSpatialIndexSpacingUnit
               (field_ptr->u.Spatial_Resolution_LOD_Data.unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Spatial_Index_Spacing_Unit value (%d)\n",
                        (int) field_ptr->u.Spatial_Resolution_LOD_Data.unit);
            }
            break;

        case SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT:
            if (field_ptr->u.Spherical_Volume_Extent.radius < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: radius"\
                            " < 0.0 in <Spherical Volume Extent>!\n");
            }
            break;

        case SE_CLS_DRM_SPOT_LIGHT:
            if (!SE_ValidBoolean(field_ptr->u.Spot_Light.apply_to_children))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spot_Light.apply_to_children);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spot_Light.override_positional_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spot_Light.override_positional_lights);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Spot_Light.override_infinite_lights))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spot_Light.override_infinite_lights);
            }
            if (!SE_ValidBoolean(field_ptr->u.Spot_Light.active_light_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Spot_Light.active_light_value);
            }
            if (field_ptr->u.Spot_Light.radius < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: radius"\
                            " < 0.0 in <Spot Light>!\n");
            }
            break;

        case SE_CLS_DRM_SRF_SUMMARY:
            if (!SE_ValidSRFContextInfo(
                      &(field_ptr->u.SRF_Summary.srf_context_info),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_SRF_Context_Info value\n");
                }
            }
            break;

        case SE_CLS_DRM_STAMP_BEHAVIOUR:
            break;

        case SE_CLS_DRM_STATE_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.State_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.State_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.State_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.State_Control_Link.expression_index);
            }
            if (!SE_ValidStateMismatchBehaviour
               (field_ptr->u.State_Control_Link.mismatch_behaviour))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_State_Mismatch_Behaviour value (%d)\n", (int)
                        field_ptr->u.State_Control_Link.mismatch_behaviour);
            }
            break;

        case SE_CLS_DRM_STATE_DATA:
            if ((field_ptr->u.State_Data.state_value.attribute_value_type !=
                EDCS_AVT_ENUMERATION) &&!EDCS_ValidAttributeValue(EAC_NULL,
                &(field_ptr->u.State_Data.state_value), (EDCS_Boolean)
                print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " EDCS_Attribute_Value value\n");
                }
            }
            if ((field_ptr->u.State_Data.state_value.attribute_value_type
                == EDCS_AVT_STRING) ||
                (field_ptr->u.State_Data.state_value.attribute_value_type
                == EDCS_AVT_INDEX) ||
                (field_ptr->u.State_Data.state_value.attribute_value_type
                == EDCS_AVT_KEY) ||
                (field_ptr->u.State_Data.state_value.attribute_value_type
                == EDCS_AVT_CONSTRAINED_STRING) ||
                (field_ptr->u.State_Data.state_value.attribute_value_type
                == EDCS_AVT_NULL))
            {
                    result = SE_FALSE;
                    if (error_count_ptr) (*error_count_ptr)++;
                    if (print_error)
                        fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                               " <State Data> value_type == %s\n",\
                            EDCS_PrintAttributeValueType
                            (field_ptr->u.State_Data.state_value.
                            attribute_value_type));
            }
            break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.State_Related_Features.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.State_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.State_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.State_Related_Features.strict_organizing_principle);
            }
            if ((EDCS_IsStateApplicable
               (field_ptr->u.State_Related_Features.state_tag, &edcs_result)
               != EDCS_SC_SUCCESS)|| (edcs_result != EDCS_TRUE))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.State_Related_Features.state_tag);
            }
            if (!EDCS_ValidAttributeValue(
                      field_ptr->u.State_Related_Features.state_tag,
                      &(field_ptr->u.State_Related_Features.active_state_value),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " EDCS_Attribute_Value value\n");
                }
            }
            else if (field_ptr->u.State_Related_Features.active_state_value.attribute_value_type
                  == EDCS_AVT_INDEX)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                           " <State Related Features> value_type == %s\n",\
                        EDCS_PrintAttributeValueType
                        (field_ptr->u.State_Related_Features.active_state_value.
                        attribute_value_type));
            }
            break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.State_Related_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.State_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.State_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.State_Related_Geometry.strict_organizing_principle);
            }
            if ((EDCS_IsStateApplicable
               (field_ptr->u.State_Related_Geometry.state_tag, &edcs_result)
               != EDCS_SC_SUCCESS)|| (edcs_result != EDCS_TRUE))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Code value (%d)\n", (int)
                        field_ptr->u.State_Related_Geometry.state_tag);
            }
            if (!EDCS_ValidAttributeValue(
                      field_ptr->u.State_Related_Geometry.state_tag,
                      &(field_ptr->u.State_Related_Geometry.active_state_value),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " EDCS_Attribute_Value value\n");
                }
            }
            else if (field_ptr->u.State_Related_Geometry.active_state_value.attribute_value_type
                  == EDCS_AVT_INDEX)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                           " <State Related Geometry> value_type == %s\n",\
                        EDCS_PrintAttributeValueType
                        (field_ptr->u.State_Related_Geometry.active_state_value.
                        attribute_value_type));
            }
            break;

        case SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR:
            if (field_ptr->u.Strobing_Light_Behaviour.period < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: period"\
                            " < 0.0 in <Strobing Light Behaviour>!\n");
            }
            if (field_ptr->u.Strobing_Light_Behaviour.delay < 0.0)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: delay"\
                            " < 0.0 in <Strobing Light Behaviour>!\n");
            }
            break;

        case SE_CLS_DRM_SYMBOL:
            if (!SE_ValidNonNullString(&(field_ptr->u.Symbol.name), SE_FALSE,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                   fprintf(f_ptr, "Mandatory field_ptr->u.Symbol.name is"\
                           " invalid\n");
            }
            if (!SE_ValidSymbolFormat(field_ptr->u.Symbol.symbol_format))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Symbol_Format value (%d)\n", (int)
                        field_ptr->u.Symbol.symbol_format);
            }
            if (!SE_ValidURN(&(field_ptr->u.Symbol.symbol_urn), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_URN value\n");
                }
            }
            break;

        case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
            if (!SE_ValidElementType(
                      &(field_ptr->u.Table_Property_Description.meaning),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Element_Type value\n");
                }
            }
            else if (!EDCS_ValidUnitCode
               (field_ptr->u.Table_Property_Description.value_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Code value (%d)\n", (int)
                        field_ptr->u.Table_Property_Description.value_unit);
            }
            else if (local_ValidEUForElement(&(field_ptr->u.Table_Property_Description.meaning),
                     field_ptr->u.Table_Property_Description.value_unit,
                     print_error, f_ptr) != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates with incompatible %s\n",
                     EDCS_PrintUnitCode(field_ptr->u.Table_Property_Description.value_unit));
            }
            if (!EDCS_ValidUnitScaleCode
               (field_ptr->u.Table_Property_Description.value_scale))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Scale_Code value (%d)\n", (int)
                        field_ptr->u.Table_Property_Description.value_scale);
            }
            if (!SE_ValidDataTableDataValueType
               (field_ptr->u.Table_Property_Description.value_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Data_Table_Data_Value_Type value (%d)\n",
                        (int)
                        field_ptr->u.Table_Property_Description.value_type);
            }
            if (!EDCS_ValidClassificationCode
               (field_ptr->u.Table_Property_Description.component_data_table_ecc)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Classification_Code value (%d)\n", (int)
                        field_ptr->u.Table_Property_Description.component_data_table_ecc);
            }
            if ((result == SE_TRUE)
             && (!local_ValidValueTypeForElement
                 (&(field_ptr->u.Table_Property_Description.meaning),
                  field_ptr->u.Table_Property_Description.value_type,
                  print_error, f_ptr)))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                    "invalid value_type %s in <Table Property Description>!\n",
                    SE_PrintDataTableDataValueType
                    (field_ptr->u.Table_Property_Description.value_type));
            }
            break;

        case SE_CLS_DRM_TEXT:
            if (!SE_ValidString(&(field_ptr->u.Text.text_string), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidTextFont(&(field_ptr->u.Text.font), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Text_Font value\n");
                }
            }
            break;

        case SE_CLS_DRM_TEXTURE_COORDINATE:
            break;

        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Texture_Coordinate_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((field_ptr->u.Texture_Coordinate_Control_Link.s_expression_index == 0) &&
                (field_ptr->u.Texture_Coordinate_Control_Link.t_expression_index == 0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "all expression_index = 0 in <Texture Coordinate Control Link>!\n");
            }

            break;

        case SE_CLS_DRM_TIME_INTERVAL:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Time_Interval.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Time_Interval.time_significance);
            }
            break;

        case SE_CLS_DRM_TIME_OF_DAY:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Time_Of_Day.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Time_Of_Day.time_significance);
            }
            if (!SE_ValidTimeOfDay(field_ptr->u.Time_Of_Day.time_of_day))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Of_Day value (%d)\n", (int)
                        field_ptr->u.Time_Of_Day.time_of_day);
            }
            break;

        case SE_CLS_DRM_TIME_POINT:
            if (!SE_ValidTimeSignificance
               (field_ptr->u.Time_Point.time_significance))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Significance value (%d)\n", (int)
                        field_ptr->u.Time_Point.time_significance);
            }
            break;

        case SE_CLS_DRM_TIME_RELATED_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.Time_Related_Features.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Time_Related_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Time_Related_Features.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Time_Related_Features.strict_organizing_principle);
            }
            if (!SE_ValidTimeDataType
               (field_ptr->u.Time_Related_Features.time_data_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Data_Type value (%d)\n", (int)
                        field_ptr->u.Time_Related_Features.time_data_type);
            }
            break;

        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Time_Related_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Time_Related_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Time_Related_Geometry.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Time_Related_Geometry.strict_organizing_principle);
            }
            if (!SE_ValidTimeDataType
               (field_ptr->u.Time_Related_Geometry.time_data_type))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Time_Data_Type value (%d)\n", (int)
                        field_ptr->u.Time_Related_Geometry.time_data_type);
            }
            break;

        case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
            break;

        case SE_CLS_DRM_TM_SURFACE_LOCATION:
            break;

        case SE_CLS_DRM_TRANSLATION:
            if (!SE_ValidLSRTransformationAxis(field_ptr->u.Translation.axis))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_LSR_Transformation_Axis value (%d)\n", (int)
                        field_ptr->u.Translation.axis);
            }
            break;

        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Translation_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Translation_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Translation_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Translation_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_TRANSLUCENCY:
            if ((field_ptr->u.Translucency.translucency_value < 0.0) ||
                (field_ptr->u.Translucency.translucency_value > 1.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: translucency_value"\
                            " out of range [0.0, 1.0] in <Translucency>!\n");
            }
            break;

        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
            if (!SE_ValidString(
                      &(field_ptr->u.Translucency_Control_Link.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidIntegerPositive
               (field_ptr->u.Translucency_Control_Link.expression_index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Translucency_Control_Link.expression_index"\
                            " value (%d)\n", (int)
                        field_ptr->u.Translucency_Control_Link.expression_index);
            }
            break;

        case SE_CLS_DRM_TRANSMITTAL_ROOT:
            if (!SE_ValidString(&(field_ptr->u.Transmittal_Root.name),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Transmittal_Root.major_DRM_version))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Transmittal_Root.major_DRM_version"\
                            " value (%d)\n", (int)
                        field_ptr->u.Transmittal_Root.major_DRM_version);
            }
            if (field_ptr->u.Transmittal_Root.minor_DRM_version > 99)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minor_DRM_version"\
                            " > 99 in <Transmittal Root>!\n");
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Transmittal_Root.major_EDCS_version))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Transmittal_Root.major_EDCS_version"\
                            " value (%d)\n", (int)
                        field_ptr->u.Transmittal_Root.major_EDCS_version);
            }
            if (field_ptr->u.Transmittal_Root.minor_EDCS_version > 99)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minor_EDCS_version"\
                            " > 99 in <Transmittal Root>!\n");
            }
            if (!SE_ValidShortIntegerPositive
               (field_ptr->u.Transmittal_Root.major_SRM_version))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " field_ptr->u.Transmittal_Root.major_SRM_version"\
                            " value (%d)\n", (int)
                        field_ptr->u.Transmittal_Root.major_SRM_version);
            }
            if (field_ptr->u.Transmittal_Root.minor_SRM_version > 99)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minor_SRM_version"\
                            " > 99 in <Transmittal Root>!\n");
            }
            break;

        case SE_CLS_DRM_TRANSMITTAL_SUMMARY:
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.features_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.features_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.geometry_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.geometry_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.geometry_topology_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.geometry_topology_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.data_tables_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.data_tables_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.priority_values_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.priority_values_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.mobility_values_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.mobility_values_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.thermal_values_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.thermal_values_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.terrain_lods_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.terrain_lods_present);
            }
            if (!SE_ValidPresentIn
               (field_ptr->u.Transmittal_Summary.two_D_features_flag))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Present_In value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.two_D_features_flag);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Transmittal_Summary.models_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.models_present);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Transmittal_Summary.images_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.images_present);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Transmittal_Summary.sounds_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.sounds_present);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Transmittal_Summary.symbols_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.symbols_present);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Transmittal_Summary.colours_present))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.colours_present);
            }
            if (field_ptr->u.Transmittal_Summary.colours_present &&
                !SE_ValidColourModel
               (field_ptr->u.Transmittal_Summary.colour_model))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                            "Illegal SE_Colour_Model value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.colour_model);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Transmittal_Summary.EDCS_usage_list_is_complete))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Transmittal_Summary.EDCS_usage_list_is_complete);
            }
            break;

        case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
            if (!SE_ValidFeatureTopologyLevel
               (field_ptr->u.Union_Of_Feature_Topology.feature_topology_level))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Feature_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Union_Of_Feature_Topology.feature_topology_level);
            }
            break;

        case SE_CLS_DRM_UNION_OF_FEATURES:
            if (!SE_ValidBoolean
               (field_ptr->u.Union_Of_Features.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Union_Of_Features.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Union_Of_Features.strict_organizing_principle))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Union_Of_Features.strict_organizing_principle);
            }
            if (!SE_ValidUnionReason
               (field_ptr->u.Union_Of_Features.union_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Union_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Features.union_reason);
            }
            if (!SE_ValidOrderingReason
               (field_ptr->u.Union_Of_Features.ordering_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Ordering_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Features.ordering_reason);
            }
            break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY:
            if (!SE_ValidBoolean
               (field_ptr->u.Union_Of_Geometry.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Union_Of_Geometry.strict_organizing_principle))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry.strict_organizing_principle);
            }
            if (!SE_ValidUnionReason
               (field_ptr->u.Union_Of_Geometry.union_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Union_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry.union_reason);
            }
            if (!SE_ValidOrderingReason
               (field_ptr->u.Union_Of_Geometry.ordering_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Ordering_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry.ordering_reason);
            }
            break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
            if (!SE_ValidBoolean
               (field_ptr->u.Union_Of_Geometry_Hierarchy.unique_descendants))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry_Hierarchy.unique_descendants);
            }
            if (!SE_ValidBoolean
               (field_ptr->u.Union_Of_Geometry_Hierarchy.strict_organizing_principle)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry_Hierarchy.strict_organizing_principle);
            }
            if (!SE_ValidUnionReason
               (field_ptr->u.Union_Of_Geometry_Hierarchy.union_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Union_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry_Hierarchy.union_reason);
            }
            if (!SE_ValidOrderingReason
               (field_ptr->u.Union_Of_Geometry_Hierarchy.ordering_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Ordering_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry_Hierarchy.ordering_reason);
            }
            break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY:
            if (!SE_ValidGeometryTopologyLevel
               (field_ptr->u.Union_Of_Geometry_Topology.geometry_topology_level)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Geometry_Topology_Level value (%d)\n", (int)
                        field_ptr->u.Union_Of_Geometry_Topology.geometry_topology_level);
            }
            break;

        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
            if (field_ptr->u.Union_Of_Primitive_Geometry.unique_descendants != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: unique_descendants"\
                            " != SE_TRUE in <Union Of Primitive Geometry>!\n");
            }
            if (field_ptr->u.Union_Of_Primitive_Geometry.strict_organizing_principle != SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: strict_organizing_principle"\
                            " != SE_TRUE in <Union Of Primitive Geometry>!\n");
            }
            if (!SE_ValidUnionReason
               (field_ptr->u.Union_Of_Primitive_Geometry.union_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Union_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Primitive_Geometry.union_reason);
            }
            if (!SE_ValidOrderingReason
               (field_ptr->u.Union_Of_Primitive_Geometry.ordering_reason))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Ordering_Reason value (%d)\n", (int)
                        field_ptr->u.Union_Of_Primitive_Geometry.ordering_reason);
            }
            break;

        case SE_CLS_DRM_VARIABLE:
            if (!SE_ValidString(&(field_ptr->u.Variable.name), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if (!SE_ValidPropertyCode(&(field_ptr->u.Variable.meaning),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_Property_Code value\n");
                }
            }
            else if (!EDCS_ValidUnitCode(field_ptr->u.Variable.value_unit))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Code value (%d)\n", (int)
                        field_ptr->u.Variable.value_unit);
            }
            else if (local_ValidEUForProperty(&(field_ptr->u.Variable.meaning),
                     field_ptr->u.Variable.value_unit, print_error, f_ptr) !=
                     SE_TRUE)
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields:"\
                            " Violates <<Variable Meaning Constraints>> with"\
                            " incompatible %s\n",
                     EDCS_PrintUnitCode(field_ptr->u.Variable.value_unit));
            }
            if (!EDCS_ValidUnitScaleCode(field_ptr->u.Variable.value_scale))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Unit_Scale_Code value (%d)\n", (int)
                        field_ptr->u.Variable.value_scale);
            }
            if (!EDCS_ValidAttributeValueType(field_ptr->u.Variable.value_type)
               )
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " EDCS_Attribute_Value_Type value (%d)\n", (int)
                        field_ptr->u.Variable.value_type);
            }
            else if ((field_ptr->u.Variable.value_type ==
                     EDCS_AVT_CONSTRAINED_STRING) ||
                     (field_ptr->u.Variable.value_type == EDCS_AVT_INDEX) ||
                     (field_ptr->u.Variable.value_type == EDCS_AVT_KEY) ||
                     (field_ptr->u.Variable.value_type == EDCS_AVT_NULL) ||
                     (field_ptr->u.Variable.value_type == EDCS_AVT_STRING))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: illegal"\
                            " value_type (%s) for <Variable>\n",
                        EDCS_PrintAttributeValueType
                        (field_ptr->u.Variable.value_type));
            }
            if (!SE_ValidString(&(field_ptr->u.Variable.description),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                           " SE_String value\n");
                }
            }
            if ((result == SE_TRUE)
             && (!local_ValidValueTypeForProperty
                 (&(field_ptr->u.Variable.meaning),
                  field_ptr->u.Variable.value_type,
                  print_error, f_ptr)))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: "\
                    "invalid value_type %s in <Variable>!\n",
                    EDCS_PrintAttributeValueType
                    (field_ptr->u.Variable.value_type));
            }
            break;

        case SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR:
            if (!SE_ValidBoolean
               (field_ptr->u.Volume_Light_Behaviour.use_full_intensity))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Volume_Light_Behaviour.use_full_intensity);
            }
            if ((field_ptr->u.Volume_Light_Behaviour.minimum_colour_intensity < 0.0) ||
                (field_ptr->u.Volume_Light_Behaviour.minimum_colour_intensity > 1.0))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: minimum_colour_intensity"\
                            " out of range [0.0, 1.0] in <Volume Light Behaviour>!\n");
            }
            break;

        case SE_CLS_DRM_VOLUME_LOD_DATA:
            if (!SE_ValidBoolean(field_ptr->u.Volume_LOD_Data.outside))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SE_ValidDRMClassFields: Illegal"\
                            " SE_Boolean value (%d)\n", (int)
                        field_ptr->u.Volume_LOD_Data.outside);
            }
            break;

        case SE_CLS_DRM_WORLD_3X3:
            break;


        default:
            break;
    }

    if (print_error)
    {
        SRM_SetErrorFilePtr(orig_srm_f_ptr);
        EDCS_SetErrorFilePtr(orig_edcs_f_ptr);
    }
    return result;
} /* end SE_ValidDRMClassFields */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidNonNullString
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidNonNullString
(
    const SE_String           *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE       *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!SE_ValidString(value_ptr, print_error, error_count_ptr))
    {
        result = SE_FALSE;
    }
    else if (!value_ptr->characters || !value_ptr->length)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"Missing required value_ptr->characters for"\
                   " value_ptr->length == %u\n",(unsigned int)
                    value_ptr->length);
        }
    }
    return result;
} /* end SE_ValidNonNullString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAddress
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAddress
(
    const SE_Address *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidAddress: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidShortIntegerPositive(value_ptr->delivery_point_count))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal value_ptr->delivery_point_count value"\
                    " (%d)\n", (int) value_ptr->delivery_point_count);
    }
    else if (!value_ptr->delivery_point)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->delivery_point for"\
                   " value_ptr->delivery_point_count == %u\n",(unsigned int)
                    value_ptr->delivery_point_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->delivery_point_count; i++)
        {
            if (!SE_ValidNonNullString(&(value_ptr->delivery_point[i]),
                    print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_String found at "\
                        "value_ptr->delivery_point[%u]\n", i);
                }
            }
        } /* end for i */
        if ((result == SE_TRUE) && (value_ptr->delivery_point_count > 1))
        {
            for (i = 0; (result == SE_TRUE) && (i <
            (SE_Integer_Unsigned)value_ptr->delivery_point_count-1); i++)
            {
                for (j = i+1; (result == SE_TRUE) && (j <
                (SE_Integer_Unsigned)value_ptr->delivery_point_count); j++)
                {
                    if (SE_CompareStrings(&(value_ptr->delivery_point[i]),
                &(value_ptr->delivery_point[j]))==0)
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Duplicate entry found at "\
                            "value_ptr->delivery_point[%u]\n", j);
                        }
                    }
                } /* end for j */
            } /* end for i */
        }
    }
    if (!SE_ValidString(&(value_ptr->city), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->administrative_area), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->postal_code), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidShortIntegerPositive(value_ptr->email_address_count))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal value_ptr->email_address_count value"\
                    " (%d)\n", (int) value_ptr->email_address_count);
    }
    else if (!value_ptr->email_address)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->email_address for"\
                   " value_ptr->email_address_count == %u\n",(unsigned int)
                    value_ptr->email_address_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->email_address_count; i++)
        {
            if (!SE_ValidNonNullString(&(value_ptr->email_address[i]),
                    print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_String found at "\
                        "value_ptr->email_address[%u]\n", i);
                }
            }
        } /* end for i */
        if ((result == SE_TRUE) && (value_ptr->email_address_count > 1))
        {
            for (i = 0; (result == SE_TRUE) && (i <
            (SE_Integer_Unsigned)value_ptr->email_address_count-1); i++)
            {
                for (j = i+1; (result == SE_TRUE) && (j <
                (SE_Integer_Unsigned)value_ptr->email_address_count); j++)
                {
                    if (SE_CompareStrings(&(value_ptr->email_address[i]),
                &(value_ptr->email_address[j]))==0)
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Duplicate entry found at "\
                            "value_ptr->email_address[%u]\n", j);
                        }
                    }
                } /* end for j */
            } /* end for i */
        }
    }
    return result;
} /* end SE_ValidAddress */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAPI
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAPI
(
    SE_API value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_API_SRM:
        case SE_API_EDCS:
        case SE_API_DRM:
        case SE_API_TACCESS0:
        case SE_API_TACCESS1:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidAPI */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAxisAlignment
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAxisAlignment
(
    SE_Axis_Alignment value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_AXALGN_NONE:
        case SE_AXALGN_LOWER:
        case SE_AXALGN_MEDIAN:
        case SE_AXALGN_UPPER:
        case SE_AXALGN_GEOMETRIC_MEAN:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidAxisAlignment */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidBoolean
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidBoolean
(
    SE_Boolean value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_FALSE:
        case SE_TRUE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidBoolean */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidBytePositive
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidBytePositive
(
    SE_Byte_Positive value
)
{
    SE_Boolean result = SE_TRUE;

    if (value < 1)
        result = SE_FALSE;

    return result;
} /* end SE_ValidBytePositive */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCameraProjectionType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidCameraProjectionType
(
    SE_Camera_Projection_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_CAM_ORTHOGRAPHIC:
        case SE_CAM_PERSPECTIVE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidCameraProjectionType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCIOnlineFunctionCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidCIOnlineFunctionCode
(
    SE_CI_OnlineFunctionCode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_CIOLFCOD_DOWNLOAD:
        case SE_CIOLFCOD_INFORMATION:
        case SE_CIOLFCOD_OFFLINE_ACCESS:
        case SE_CIOLFCOD_ORDER:
        case SE_CIOLFCOD_SEARCH:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidCIOnlineFunctionCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCIOnlineResource
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidCIOnlineResource
(
    const SE_CI_OnlineResource *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidCIOnlineResource: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidURL(&(value_ptr->linkage), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_URL value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->protocol), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->application_profile), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->name), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->description), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidCIOnlineFunctionCode(value_ptr->function))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_CI_OnlineFunctionCode value (%d)\n",
                (int) value_ptr->function);
    }
    return result;
} /* end SE_ValidCIOnlineResource */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCIRoleCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidCIRoleCode
(
    SE_CI_RoleCode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ROLECOD_RESOURCE_PROVIDER:
        case SE_ROLECOD_CUSTODIAN:
        case SE_ROLECOD_OWNER:
        case SE_ROLECOD_USER:
        case SE_ROLECOD_DISTRIBUTOR:
        case SE_ROLECOD_ORIGINATOR:
        case SE_ROLECOD_POINT_OF_CONTACT:
        case SE_ROLECOD_PRINCIPAL_INVESTIGATOR:
        case SE_ROLECOD_PROCESSOR:
        case SE_ROLECOD_PUBLISHER:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidCIRoleCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourBinding
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidColourBinding
(
    SE_Colour_Binding value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_COLRB_NORMAL:
        case SE_COLRB_PARENT_OVERRIDE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidColourBinding */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourData
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidColourData
(
    const SE_Colour_Data *value_ptr,
          SE_Boolean      print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidColourData: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->colour_model)
    {
        case SE_COLRMOD_RGB:
            if (!SE_ValidRGBData(&(value_ptr->u.rgb), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_RGB_Data value\n");
                }
            }
            break;

        case SE_COLRMOD_CMY:
            if (!SE_ValidCMYData(&(value_ptr->u.cmy), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_CMY_Data value\n");
                }
            }
            break;

        case SE_COLRMOD_HSV:
            if (!SE_ValidHSVData(&(value_ptr->u.hsv), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_HSV_Data value\n");
                }
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Colour_Model value (%d)\n", (int)
                         value_ptr->colour_model);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidColourData */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourMapping
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidColourMapping
(
    const SE_Colour_Mapping *value_ptr,
          SE_Boolean         print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidColourMapping: NULL value_ptr\n");
        }
        return result;
    }
    else if (value_ptr->set == 0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidColourMapping: value_ptr->set == 0\n");
        }
        return result;
    }
    return result;
} /* end SE_ValidColourMapping */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourModel
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidColourModel
(
    SE_Colour_Model value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_COLRMOD_RGB:
        case SE_COLRMOD_CMY:
        case SE_COLRMOD_HSV:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidColourModel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidContactInformation
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidContactInformation
(
    const SE_Contact_Information *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidContactInformation: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidTelephoneInformation(&(value_ptr->phone), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Telephone_Information value\n");
        }
    }
    if (!SE_ValidAddress(&(value_ptr->address), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Address value\n");
        }
    }
    if (!SE_ValidCIOnlineResource(&(value_ptr->online_resource), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_CI_OnlineResource value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->hours_of_service), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->contact_instructions), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    return result;
} /* end SE_ValidContactInformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCountIntervalValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidCountIntervalValue
(
    const SE_Count_Interval_Value *value_ptr,
          SE_Boolean               print_error,
          SE_Integer_Unsigned     *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidCountIntervalValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->interval_type)
    {
        case SE_INTRVLTYP_OPEN_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.open_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GE_LT_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.ge_lt_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GT_LE_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.gt_le_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_CLOSED_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.closed_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GT_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_GE_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_LT_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_LE_SEMI_INTERVAL:
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Interval_Type value (%d)\n", (int)
                         value_ptr->interval_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidCountIntervalValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataQualityElement
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDataQualityElement
(
    const SE_Data_Quality_Element *value_ptr,
          SE_Boolean               print_error,
          SE_Integer_Unsigned     *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDataQualityElement: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidString(&(value_ptr->name_of_measure), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->measure_identification), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->measure_description), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->evaluation_method_type), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->evaluation_method_description),
              print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->evaluation_procedure), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->data_time), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidString(&(value_ptr->result), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    return result;
} /* end SE_ValidDataQualityElement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataTableDataValueType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDataTableDataValueType
(
    SE_Data_Table_Data_Value_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        case SE_DTDATAVALTYP_LONG_FLOAT:
        case SE_DTDATAVALTYP_SINGLE_INTEGER:
        case SE_DTDATAVALTYP_INTEGER:
        case SE_DTDATAVALTYP_SINGLE_COUNT:
        case SE_DTDATAVALTYP_COUNT:
        case SE_DTDATAVALTYP_INDEX:
        case SE_DTDATAVALTYP_STRING:
        case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        case SE_DTDATAVALTYP_KEY:
        case SE_DTDATAVALTYP_ENUMERATION:
        case SE_DTDATAVALTYP_BOOLEAN:
        case SE_DTDATAVALTYP_INDEX_CODE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidDataTableDataValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDisplaySide
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDisplaySide
(
    const SE_Display_Side *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDisplaySide: NULL value_ptr\n");
        }
        return result;
    }
    else if (value_ptr->set == 0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDisplaySide: value_ptr->set == 0\n");
        }
        return result;
    }
    return result;
} /* end SE_ValidDisplaySide */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDisplayStyle
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDisplayStyle
(
    const SE_Display_Style *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDisplayStyle: NULL value_ptr\n");
        }
        return result;
    }
    else if (value_ptr->set == 0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDisplayStyle: value_ptr->set == 0\n");
        }
        return result;
    }
    return result;
} /* end SE_ValidDisplayStyle */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMClass
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDRMClass
(
    SE_DRM_Class value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_CLS_DRM_NULL:
        case SE_CLS_DRM_ABSOLUTE_TIME:
        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
        case SE_CLS_DRM_AGGREGATE_FEATURE:
        case SE_CLS_DRM_AGGREGATE_GEOMETRY:
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
        case SE_CLS_DRM_AMBIENT_COLOUR:
        case SE_CLS_DRM_ANIMATION_BEHAVIOUR:
        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
        case SE_CLS_DRM_ARC:
        case SE_CLS_DRM_AREAL_FEATURE:
        case SE_CLS_DRM_ATTACHMENT_POINT:
        case SE_CLS_DRM_AXIS:
        case SE_CLS_DRM_BASE_ASSOCIATION_DATA:
        case SE_CLS_DRM_BASE_LOD_DATA:
        case SE_CLS_DRM_BASE_POSITIONAL_LIGHT:
        case SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA:
        case SE_CLS_DRM_BASE_SUMMARY_ITEM:
        case SE_CLS_DRM_BASE_TIME_DATA:
        case SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT:
        case SE_CLS_DRM_BOUNDING_VOLUME:
        case SE_CLS_DRM_BROWSE_MEDIA:
        case SE_CLS_DRM_CAMERA_POINT:
        case SE_CLS_DRM_CC_3D_LOCATION:
        case SE_CLS_DRM_CD_3D_LOCATION:
        case SE_CLS_DRM_CD_SURFACE_LOCATION:
        case SE_CLS_DRM_CITATION:
        case SE_CLS_DRM_CLASSIFICATION_DATA:
        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
        case SE_CLS_DRM_CM_3D_LOCATION:
        case SE_CLS_DRM_CMY_COLOUR:
        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
        case SE_CLS_DRM_COLLISION_VOLUME:
        case SE_CLS_DRM_COLOUR:
        case SE_CLS_DRM_COLOUR_DATA:
        case SE_CLS_DRM_COLOUR_INDEX:
        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
        case SE_CLS_DRM_COLOUR_SHININESS:
        case SE_CLS_DRM_COLOUR_TABLE:
        case SE_CLS_DRM_COLOUR_TABLE_GROUP:
        case SE_CLS_DRM_COLOUR_TABLE_LIBRARY:
        case SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT:
        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
        case SE_CLS_DRM_CONTACT_POINT:
        case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
        case SE_CLS_DRM_CONTROL_LINK:
        case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
        case SE_CLS_DRM_DATA_QUALITY:
        case SE_CLS_DRM_DATA_TABLE:
        case SE_CLS_DRM_DATA_TABLE_LIBRARY:
        case SE_CLS_DRM_DIFFUSE_COLOUR:
        case SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_DISTANCE_LOD_DATA:
        case SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM:
        case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_EC_SURFACE_LOCATION:
        case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
        case SE_CLS_DRM_EDGE_DIRECTION:
        case SE_CLS_DRM_EI_3D_LOCATION:
        case SE_CLS_DRM_ELLIPSE:
        case SE_CLS_DRM_EMISSIVE_COLOUR:
        case SE_CLS_DRM_ENCLOSING_VOLUME:
        case SE_CLS_DRM_ENUMERATION_AXIS:
        case SE_CLS_DRM_ENVIRONMENT_ROOT:
        case SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY:
        case SE_CLS_DRM_EXPRESSION:
        case SE_CLS_DRM_FACE_DIRECTION:
        case SE_CLS_DRM_FADE_RANGE:
        case SE_CLS_DRM_FEATURE_EDGE:
        case SE_CLS_DRM_FEATURE_FACE:
        case SE_CLS_DRM_FEATURE_FACE_RING:
        case SE_CLS_DRM_FEATURE_HIERARCHY:
        case SE_CLS_DRM_FEATURE_MODEL:
        case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
        case SE_CLS_DRM_FEATURE_NODE:
        case SE_CLS_DRM_FEATURE_REPRESENTATION:
        case SE_CLS_DRM_FEATURE_TOPOLOGY:
        case SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY:
        case SE_CLS_DRM_FEATURE_VOLUME:
        case SE_CLS_DRM_FEATURE_VOLUME_SHELL:
        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        case SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_FUNCTION:
        case SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA:
        case SE_CLS_DRM_GEOMETRIC_CENTRE:
        case SE_CLS_DRM_GEOMETRY_EDGE:
        case SE_CLS_DRM_GEOMETRY_FACE:
        case SE_CLS_DRM_GEOMETRY_HIERARCHY:
        case SE_CLS_DRM_GEOMETRY_MODEL:
        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
        case SE_CLS_DRM_GEOMETRY_NODE:
        case SE_CLS_DRM_GEOMETRY_REPRESENTATION:
        case SE_CLS_DRM_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY:
        case SE_CLS_DRM_GEOMETRY_VOLUME:
        case SE_CLS_DRM_GRID_OVERLAP:
        case SE_CLS_DRM_HAEC_3D_LOCATION:
        case SE_CLS_DRM_HEEC_3D_LOCATION:
        case SE_CLS_DRM_HEEQ_3D_LOCATION:
        case SE_CLS_DRM_HIERARCHY_DATA:
        case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
        case SE_CLS_DRM_HSV_COLOUR:
        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
        case SE_CLS_DRM_ICON:
        case SE_CLS_DRM_IDENTIFICATION:
        case SE_CLS_DRM_IMAGE:
        case SE_CLS_DRM_IMAGE_ANCHOR:
        case SE_CLS_DRM_IMAGE_LIBRARY:
        case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
        case SE_CLS_DRM_IN_OUT:
        case SE_CLS_DRM_INDEX_LOD_DATA:
        case SE_CLS_DRM_INFINITE_LIGHT:
        case SE_CLS_DRM_INLINE_COLOUR:
        case SE_CLS_DRM_INTERFACE_TEMPLATE:
        case SE_CLS_DRM_INTERVAL_AXIS:
        case SE_CLS_DRM_IRREGULAR_AXIS:
        case SE_CLS_DRM_KEYWORDS:
        case SE_CLS_DRM_LABEL:
        case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_LCC_SURFACE_LOCATION:
        case SE_CLS_DRM_LCE_3D_LOCATION:
        case SE_CLS_DRM_LEGAL_CONSTRAINTS:
        case SE_CLS_DRM_LIBRARY:
        case SE_CLS_DRM_LIGHT_RENDERING_BEHAVIOUR:
        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
        case SE_CLS_DRM_LIGHT_SOURCE:
        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
        case SE_CLS_DRM_LINE:
        case SE_CLS_DRM_LINEAGE:
        case SE_CLS_DRM_LINEAR_FEATURE:
        case SE_CLS_DRM_LINEAR_GEOMETRY:
        case SE_CLS_DRM_LITERAL:
        case SE_CLS_DRM_LOBE_DATA:
        case SE_CLS_DRM_LOCAL_4X4:
        case SE_CLS_DRM_LOCATION:
        case SE_CLS_DRM_LOCATION_2D:
        case SE_CLS_DRM_LOCATION_3D:
        case SE_CLS_DRM_LOCATION_SURFACE:
        case SE_CLS_DRM_LOD_RELATED_FEATURES:
        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
        case SE_CLS_DRM_LSA_2D_LOCATION:
        case SE_CLS_DRM_LSP_2D_LOCATION:
        case SE_CLS_DRM_LSR_2D_LOCATION:
        case SE_CLS_DRM_LSR_3D_LOCATION:
        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
        case SE_CLS_DRM_LSR_TRANSFORMATION:
        case SE_CLS_DRM_LSR_TRANSFORMATION_STEP:
        case SE_CLS_DRM_LTSAS_3D_LOCATION:
        case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
        case SE_CLS_DRM_LTSC_3D_LOCATION:
        case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
        case SE_CLS_DRM_LTSE_3D_LOCATION:
        case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
        case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_M_SURFACE_LOCATION:
        case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
        case SE_CLS_DRM_MESH_FACE_TABLE:
        case SE_CLS_DRM_MODEL:
        case SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX:
        case SE_CLS_DRM_MODEL_LIBRARY:
        case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_OCTANT_DATA:
        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
        case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_OMS_SURFACE_LOCATION:
        case SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX:
        case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
        case SE_CLS_DRM_PD_3D_LOCATION:
        case SE_CLS_DRM_PD_SURFACE_LOCATION:
        case SE_CLS_DRM_PERIMETER_DATA:
        case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
        case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_POINT:
        case SE_CLS_DRM_POINT_FEATURE:
        case SE_CLS_DRM_POLYGON:
        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
        case SE_CLS_DRM_POLYHEDRON:
        case SE_CLS_DRM_POSITIONAL_LIGHT:
        case SE_CLS_DRM_PREDEFINED_FUNCTION:
        case SE_CLS_DRM_PRESENTATION_DOMAIN:
        case SE_CLS_DRM_PRIMITIVE_COLOUR:
        case SE_CLS_DRM_PRIMITIVE_FEATURE:
        case SE_CLS_DRM_PRIMITIVE_GEOMETRY:
        case SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM:
        case SE_CLS_DRM_PROCESS_STEP:
        case SE_CLS_DRM_PROPERTY:
        case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
        case SE_CLS_DRM_PROPERTY_GRID:
        case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
        case SE_CLS_DRM_PROPERTY_SET:
        case SE_CLS_DRM_PROPERTY_SET_INDEX:
        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
        case SE_CLS_DRM_PROPERTY_SET_TABLE:
        case SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP:
        case SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY:
        case SE_CLS_DRM_PROPERTY_TABLE:
        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
        case SE_CLS_DRM_PROPERTY_VALUE:
        case SE_CLS_DRM_PROXIMITY_DATA:
        case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_PS_SURFACE_LOCATION:
        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
        case SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT:
        case SE_CLS_DRM_QUADRANT_DATA:
        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
        case SE_CLS_DRM_REFERENCE_ORIGIN:
        case SE_CLS_DRM_REFERENCE_SURFACE:
        case SE_CLS_DRM_REFERENCE_VECTOR:
        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
        case SE_CLS_DRM_REGULAR_AXIS:
        case SE_CLS_DRM_RELATIVE_TIME:
        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
        case SE_CLS_DRM_RENDERING_PROPERTIES:
        case SE_CLS_DRM_RESPONSIBLE_PARTY:
        case SE_CLS_DRM_RGB_COLOUR:
        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
        case SE_CLS_DRM_ROLE_DATA:
        case SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_ROTATION:
        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
        case SE_CLS_DRM_SCALE:
        case SE_CLS_DRM_SCALE_CONTROL_LINK:
        case SE_CLS_DRM_SEASON:
        case SE_CLS_DRM_SECURITY_CONSTRAINTS:
        case SE_CLS_DRM_SEC_3D_LOCATION:
        case SE_CLS_DRM_SEDRIS_ABSTRACT_BASE:
        case SE_CLS_DRM_SEPARATING_PLANE:
        case SE_CLS_DRM_SEPARATING_PLANE_DATA:
        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
        case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
        case SE_CLS_DRM_SEQ_3D_LOCATION:
        case SE_CLS_DRM_SMD_3D_LOCATION:
        case SE_CLS_DRM_SME_3D_LOCATION:
        case SE_CLS_DRM_SOUND:
        case SE_CLS_DRM_SOUND_INSTANCE:
        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
        case SE_CLS_DRM_SOUND_LIBRARY:
        case SE_CLS_DRM_SOUND_VOLUME:
        case SE_CLS_DRM_SOURCE:
        case SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA:
        case SE_CLS_DRM_SPATIAL_EXTENT:
        case SE_CLS_DRM_SPATIAL_INDEX_DATA:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
        case SE_CLS_DRM_SPECULAR_COLOUR:
        case SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT:
        case SE_CLS_DRM_SPOT_LIGHT:
        case SE_CLS_DRM_SRF_SUMMARY:
        case SE_CLS_DRM_STAMP_BEHAVIOUR:
        case SE_CLS_DRM_STATE_CONTROL_LINK:
        case SE_CLS_DRM_STATE_DATA:
        case SE_CLS_DRM_STATE_RELATED_FEATURES:
        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
        case SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_SURFACE_GEOMETRY:
        case SE_CLS_DRM_SYMBOL:
        case SE_CLS_DRM_SYMBOL_LIBRARY:
        case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
        case SE_CLS_DRM_TACK_POINT:
        case SE_CLS_DRM_TEXT:
        case SE_CLS_DRM_TEXTURE_COORDINATE:
        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
        case SE_CLS_DRM_TIME_CONSTRAINTS_DATA:
        case SE_CLS_DRM_TIME_INTERVAL:
        case SE_CLS_DRM_TIME_OF_DAY:
        case SE_CLS_DRM_TIME_POINT:
        case SE_CLS_DRM_TIME_RELATED_FEATURES:
        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
        case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
        case SE_CLS_DRM_TM_SURFACE_LOCATION:
        case SE_CLS_DRM_TRANSFORMATION:
        case SE_CLS_DRM_TRANSLATION:
        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
        case SE_CLS_DRM_TRANSLUCENCY:
        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
        case SE_CLS_DRM_TRANSMITTAL_ROOT:
        case SE_CLS_DRM_TRANSMITTAL_SUMMARY:
        case SE_CLS_DRM_TWINKLING_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
        case SE_CLS_DRM_UNION_OF_FEATURES:
        case SE_CLS_DRM_UNION_OF_GEOMETRY:
        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
        case SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY:
        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
        case SE_CLS_DRM_VARIABLE:
        case SE_CLS_DRM_VERTEX:
        case SE_CLS_DRM_VOLUME_EXTENT:
        case SE_CLS_DRM_VOLUME_GEOMETRY:
        case SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR:
        case SE_CLS_DRM_VOLUME_LOD_DATA:
        case SE_CLS_DRM_VOLUME_OBJECT:
        case SE_CLS_DRM_VOLUMETRIC_FEATURE:
        case SE_CLS_DRM_WORLD_3X3:
        case SE_CLS_DRM_WORLD_TRANSFORMATION:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidDRMClass */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMStatusCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDRMStatusCode
(
    SE_DRM_Status_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_DRM_STAT_CODE_SUCCESS:
        case SE_DRM_STAT_CODE_INVALID_CLASS:
        case SE_DRM_STAT_CODE_INVALID_CLASS_FIELD:
        case SE_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL:
        case SE_DRM_STAT_CODE_INVALID_ENUMERANT:
        case SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR:
        case SE_DRM_STAT_CODE_INVALID_TYPE:
        case SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION:
        case SE_DRM_STAT_CODE_INVALID_TYPE_FIELD:
        case SE_DRM_STAT_CODE_INVALID_VERSION:
        case SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER:
        case SE_DRM_STAT_CODE_FAILURE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidDRMStatusCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDRMType
(
    SE_DRM_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_DRM_TYP_NULL:
        case SE_DRM_TYP_SE_ADDRESS:
        case SE_DRM_TYP_SE_API:
        case SE_DRM_TYP_EDCS_ATTRIBUTE_CODE:
        case SE_DRM_TYP_EDCS_ATTRIBUTE_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_ATTRIBUTE_LABEL:
        case SE_DRM_TYP_EDCS_ATTRIBUTE_VALUE:
        case SE_DRM_TYP_EDCS_ATTRIBUTE_VALUE_TYPE:
        case SE_DRM_TYP_SE_AXIS_ALIGNMENT:
        case SE_DRM_TYP_SRM_AXIS_DIRECTION:
        case SE_DRM_TYP_EDCS_BOOLEAN:
        case SE_DRM_TYP_SE_BOOLEAN:
        case SE_DRM_TYP_SRM_BOOLEAN:
        case SE_DRM_TYP_SE_BYTE:
        case SE_DRM_TYP_SE_BYTE_POSITIVE:
        case SE_DRM_TYP_SE_BYTE_UNSIGNED:
        case SE_DRM_TYP_SE_CAMERA_PROJECTION_TYPE:
        case SE_DRM_TYP_SRM_CD_3D_COORDINATE:
        case SE_DRM_TYP_SRM_CD_SURFACE_COORDINATE:
        case SE_DRM_TYP_EDCS_CHARACTER:
        case SE_DRM_TYP_SE_CHARACTER:
        case SE_DRM_TYP_SE_CI_ONLINEFUNCTIONCODE:
        case SE_DRM_TYP_SE_CI_ONLINERESOURCE:
        case SE_DRM_TYP_SE_CI_ROLECODE:
        case SE_DRM_TYP_EDCS_CLASSIFICATION_CODE:
        case SE_DRM_TYP_EDCS_CLASSIFICATION_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_CLASSIFICATION_LABEL:
        case SE_DRM_TYP_SE_CMY_DATA:
        case SE_DRM_TYP_SE_CMYK_DATA:
        case SE_DRM_TYP_SE_COLOUR_BINDING:
        case SE_DRM_TYP_SE_COLOUR_DATA:
        case SE_DRM_TYP_SE_COLOUR_MAPPING:
        case SE_DRM_TYP_SE_COLOUR_MODEL:
        case SE_DRM_TYP_EDCS_CONCEPT_STATUS:
        case SE_DRM_TYP_SE_CONTACT_INFORMATION:
        case SE_DRM_TYP_SRM_COORDINATE:
        case SE_DRM_TYP_SRM_COORDINATE2D_ARRAY:
        case SE_DRM_TYP_SRM_COORDINATE3D_ARRAY:
        case SE_DRM_TYP_SRM_COORDINATE_VALID_REGION:
        case SE_DRM_TYP_SRM_COORDINATE_VALID_REGION_ARRAY:
        case SE_DRM_TYP_EDCS_COUNT:
        case SE_DRM_TYP_EDCS_COUNT_INTERVAL:
        case SE_DRM_TYP_SE_COUNT_INTERVAL_VALUE:
        case SE_DRM_TYP_EDCS_COUNT_VALUE:
        case SE_DRM_TYP_SRM_CS_CODE:
        case SE_DRM_TYP_SE_DATA_QUALITY_ELEMENT:
        case SE_DRM_TYP_SE_DATA_TABLE_DATA:
        case SE_DRM_TYP_SE_DATA_TABLE_DATA_VALUE_TYPE:
        case SE_DRM_TYP_EDCS_DICTIONARY_TYPE:
        case SE_DRM_TYP_SRM_DIRECTION_ARRAY:
        case SE_DRM_TYP_SE_DISPLAY_SIDE:
        case SE_DRM_TYP_SE_DISPLAY_STYLE:
        case SE_DRM_TYP_SE_DRM_CLASS:
        case SE_DRM_TYP_SE_DRM_STATUS_CODE:
        case SE_DRM_TYP_SE_DRM_TYPE:
        case SE_DRM_TYP_SRM_DSS_CODE:
        case SE_DRM_TYP_SRM_EC_PARAMETERS:
        case SE_DRM_TYP_SRM_EI_3D_COORDINATE:
        case SE_DRM_TYP_SE_ELEMENT_TYPE:
        case SE_DRM_TYP_SE_ELEMENT_TYPE_CODE:
        case SE_DRM_TYP_EDCS_ENUMERANT_CODE:
        case SE_DRM_TYP_EDCS_ENUMERANT_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_ENUMERANT_LABEL:
        case SE_DRM_TYP_SE_ENUMERANT_STRUCTURE:
        case SE_DRM_TYP_SRM_EUCLIDEAN_2D_COORDINATE:
        case SE_DRM_TYP_SRM_EUCLIDEAN_3D_COORDINATE:
        case SE_DRM_TYP_SE_FEATURE_TOPOLOGY_LEVEL:
        case SE_DRM_TYP_SE_FIELD_MODIFIER:
        case SE_DRM_TYP_SE_FLOAT:
        case SE_DRM_TYP_SE_FONT_STYLE:
        case SE_DRM_TYP_SE_FUNCTIONAL_ASSOCIATION_MEANING_TYPE:
        case SE_DRM_TYP_SE_GEOMETRIC_CENTRE_CODE:
        case SE_DRM_TYP_SE_GEOMETRY_TOPOLOGY_LEVEL:
        case SE_DRM_TYP_SE_GRID_OVERLAP_OPERATOR:
        case SE_DRM_TYP_EDCS_GROUP_CODE:
        case SE_DRM_TYP_EDCS_GROUP_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_GROUP_LABEL:
        case SE_DRM_TYP_EDCS_GROUP_PAIR:
        case SE_DRM_TYP_SE_HLS_DATA:
        case SE_DRM_TYP_SE_HS_MULTIPLICITY_CODE:
        case SE_DRM_TYP_SE_HSV_DATA:
        case SE_DRM_TYP_SE_IMAGE_COMPONENT_TYPE:
        case SE_DRM_TYP_SE_IMAGE_MAPPING_METHOD:
        case SE_DRM_TYP_SE_IMAGE_MIP_EXTENTS:
        case SE_DRM_TYP_SE_IMAGE_PROJECTION_TYPE:
        case SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION:
        case SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION_Z:
        case SE_DRM_TYP_SE_IMAGE_SIGNATURE:
        case SE_DRM_TYP_SE_IMAGE_WRAP:
        case SE_DRM_TYP_SE_INDEX_CODE:
        case SE_DRM_TYP_EDCS_INTEGER:
        case SE_DRM_TYP_SE_INTEGER:
        case SE_DRM_TYP_SRM_INTEGER:
        case SE_DRM_TYP_EDCS_INTEGER_INTERVAL:
        case SE_DRM_TYP_SE_INTEGER_INTERVAL_VALUE:
        case SE_DRM_TYP_SRM_INTEGER_POSITIVE:
        case SE_DRM_TYP_SE_INTEGER_POSITIVE:
        case SE_DRM_TYP_SRM_INTEGER_UNSIGNED:
        case SE_DRM_TYP_SE_INTEGER_UNSIGNED:
        case SE_DRM_TYP_EDCS_INTEGER_VALUE:
        case SE_DRM_TYP_SE_INTERPOLATION_TYPE:
        case SE_DRM_TYP_SRM_INTERVAL_TYPE:
        case SE_DRM_TYP_SE_INTERVAL_TYPE:
        case SE_DRM_TYP_SE_INTERVAL_VALUE:
        case SE_DRM_TYP_SE_INTERVAL_VALUE_TYPE:
        case SE_DRM_TYP_EDCS_ISO_3166_ENTRY:
        case SE_DRM_TYP_EDCS_ISO_639_ENTRY:
        case SE_DRM_TYP_SRM_LCC_PARAMETERS:
        case SE_DRM_TYP_SRM_LCE_3D_PARAMETERS:
        case SE_DRM_TYP_EDCS_LOCALE:
        case SE_DRM_TYP_SE_LOCALE:
        case SE_DRM_TYP_SRM_LOCAL_TANGENT_PARAMETERS:
        case SE_DRM_TYP_SE_LOD_DATA_TYPE:
        case SE_DRM_TYP_EDCS_LONG_FLOAT:
        case SE_DRM_TYP_SE_LONG_FLOAT:
        case SE_DRM_TYP_SRM_LONG_FLOAT:
        case SE_DRM_TYP_EDCS_LONG_FLOAT_INTERVAL:
        case SE_DRM_TYP_SE_LONG_FLOAT_INTERVAL_VALUE:
        case SE_DRM_TYP_EDCS_LONG_FLOAT_VALUE:
        case SE_DRM_TYP_SE_LONG_FLOAT_VALUE:
        case SE_DRM_TYP_SRM_LSA_2D_COORDINATE:
        case SE_DRM_TYP_SRM_LSP_2D_COORDINATE:
        case SE_DRM_TYP_SRM_LSR_2D_PARAMETERS:
        case SE_DRM_TYP_SRM_LSR_3D_PARAMETERS:
        case SE_DRM_TYP_SE_LSR_TRANSFORMATION_AXIS:
        case SE_DRM_TYP_SRM_LTSAS_3D_COORDINATE:
        case SE_DRM_TYP_SRM_LTSAS_SURFACE_COORDINATE:
        case SE_DRM_TYP_SRM_LTSC_3D_COORDINATE:
        case SE_DRM_TYP_SRM_LTSC_SURFACE_COORDINATE:
        case SE_DRM_TYP_SRM_LTSE_3D_COORDINATE:
        case SE_DRM_TYP_SRM_LTSE_PARAMETERS:
        case SE_DRM_TYP_SRM_LTSE_SURFACE_COORDINATE:
        case SE_DRM_TYP_SRM_MAP_PROJECTION_3D_COORDINATE:
        case SE_DRM_TYP_SRM_MAP_PROJECTION_SURFACE_COORDINATE:
        case SE_DRM_TYP_SRM_MATRIX_3X3:
        case SE_DRM_TYP_SRM_MATRIX_4X4:
        case SE_DRM_TYP_SE_MD_CLASSIFICATIONCODE:
        case SE_DRM_TYP_SE_MD_KEYWORDTYPECODE:
        case SE_DRM_TYP_SE_MD_RESTRICTIONCODE:
        case SE_DRM_TYP_SE_MEDIA_FORMAT:
        case SE_DRM_TYP_SRM_M_PARAMETERS:
        case SE_DRM_TYP_SE_MODEL_REFERENCE_TYPE:
        case SE_DRM_TYP_SE_MONTH:
        case SE_DRM_TYP_SE_MULTIPLICITY:
        case SE_DRM_TYP_EDCS_NULL:
        case SE_DRM_TYP_EDCS_NUMERIC_VALUE_TYPE:
        case SE_DRM_TYP_SRM_OBJECT_REFERENCE:
        case SE_DRM_TYP_SRM_OBLIQUE_MERCATOR_PARAMETERS:
        case SE_DRM_TYP_SE_OCTANT:
        case SE_DRM_TYP_SE_OCTET:
        case SE_DRM_TYP_SE_ORDERING_REASON:
        case SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_CODE:
        case SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_LABEL:
        case SE_DRM_TYP_SRM_ORM_CODE:
        case SE_DRM_TYP_SRM_ORM_TRANSFORMATION_2D_PARAMETERS:
        case SE_DRM_TYP_SRM_ORM_TRANSFORMATION_3D_PARAMETERS:
        case SE_DRM_TYP_SRM_ORMT_CODE:
        case SE_DRM_TYP_SRM_PD_3D_COORDINATE:
        case SE_DRM_TYP_SRM_PD_SURFACE_COORDINATE:
        case SE_DRM_TYP_SE_PIXEL_FILL_METHOD:
        case SE_DRM_TYP_SE_POINT_LIGHT_DISPLAY_TYPE:
        case SE_DRM_TYP_SRM_POLAR_ASPECT:
        case SE_DRM_TYP_SE_POLYGON_FLAG:
        case SE_DRM_TYP_SE_PREDEF_FUNC_ARG_STRUCTURE:
        case SE_DRM_TYP_SE_PREDEF_FUNC_STRUCTURE:
        case SE_DRM_TYP_SE_PREDEFINED_FUNCTION:
        case SE_DRM_TYP_SE_PRESENT_IN:
        case SE_DRM_TYP_SE_PRESENTATION_DOMAIN:
        case SE_DRM_TYP_SE_PROPERTY_CODE:
        case SE_DRM_TYP_SE_PROPERTY_CODE_TYPE:
        case SE_DRM_TYP_SRM_PS_PARAMETERS:
        case SE_DRM_TYP_SE_QUADRANT:
        case SE_DRM_TYP_SRM_RD_CODE:
        case SE_DRM_TYP_EDCS_REAL_VALUE:
        case SE_DRM_TYP_EDCS_REFERENCE_TYPE:
        case SE_DRM_TYP_SE_REFERENCE_VECTOR_TYPE:
        case SE_DRM_TYP_SE_RGB_DATA:
        case SE_DRM_TYP_SE_ROTATION_DATA:
        case SE_DRM_TYP_SE_REFERENCE_SURFACE_ELEVATION_SELECT:
        case SE_DRM_TYP_SE_REFERENCE_SURFACE_LOD_SELECT:
        case SE_DRM_TYP_SRM_RT_CODE:
        case SE_DRM_TYP_SE_SEASON:
        case SE_DRM_TYP_SE_SHADING_METHOD:
        case SE_DRM_TYP_SE_SHORT_INTEGER:
        case SE_DRM_TYP_SE_SHORT_INTEGER_POSITIVE:
        case SE_DRM_TYP_SE_SHORT_INTEGER_UNSIGNED:
        case SE_DRM_TYP_SE_SINGLE_VALUE:
        case SE_DRM_TYP_SE_SINGLE_VALUE_TYPE:
        case SE_DRM_TYP_SE_SOUND_FORMAT:
        case SE_DRM_TYP_SE_SPACING_TYPE:
        case SE_DRM_TYP_SE_SPATIAL_ASSOCIATION_MEANING_TYPE:
        case SE_DRM_TYP_SRM_SPATIAL_COORDINATE_CODE:
        case SE_DRM_TYP_SE_SPATIAL_INDEX_SPACING_UNIT:
        case SE_DRM_TYP_SRM_SPHERICAL_3D_COORDINATE:
        case SE_DRM_TYP_SRM_SRF_CODE:
        case SE_DRM_TYP_SE_SRF_CONTEXT_INFO:
        case SE_DRM_TYP_SRM_SRF_PARAMETERS_INFO:
        case SE_DRM_TYP_SRM_SRF_PARAMETERS_INFO_CODE:
        case SE_DRM_TYP_SRM_SRF_REFERENCE_SURFACE_INFO:
        case SE_DRM_TYP_SRM_SRFS_CODE:
        case SE_DRM_TYP_SRM_SRFS_CODE_INFO:
        case SE_DRM_TYP_SRM_SRFS_INFO:
        case SE_DRM_TYP_SRM_SRFSM_ALABAMA_SPCS_CODE:
        case SE_DRM_TYP_SRM_SRFSM_GTRS_GCS_CODE:
        case SE_DRM_TYP_SRM_SRFSM_JAPAN_RECTANGULAR_PLANE_CS_CODE:
        case SE_DRM_TYP_SRM_SRFSM_LAMBERT_NTF_CODE:
        case SE_DRM_TYP_SRM_SRFSM_UPS_CODE:
        case SE_DRM_TYP_SRM_SRFSM_UTM_CODE:
        case SE_DRM_TYP_SRM_SRFSM_WISCONSIN_SPCS_CODE:
        case SE_DRM_TYP_SRM_SRFT_CODE:
        case SE_DRM_TYP_SRM_SRFT_PARAMETERS:
        case SE_DRM_TYP_SE_STATE_MISMATCH_BEHAVIOUR:
        case SE_DRM_TYP_EDCS_STATUS_CODE:
        case SE_DRM_TYP_SRM_STATUS_CODE:
        case SE_DRM_TYP_EDCS_STRING:
        case SE_DRM_TYP_SE_STRING:
        case SE_DRM_TYP_SE_SYMBOL_FORMAT:
        case SE_DRM_TYP_SE_TELEPHONE_INFORMATION:
        case SE_DRM_TYP_SE_TEXT_FONT:
        case SE_DRM_TYP_SE_TIME_CONFIGURATION:
        case SE_DRM_TYP_SE_TIME_DATA_TYPE:
        case SE_DRM_TYP_SE_TIME_DAY_OF_YEAR_VALUE:
        case SE_DRM_TYP_SE_TIME_M_VALUE:
        case SE_DRM_TYP_SE_TIME_MD_H_VALUE:
        case SE_DRM_TYP_SE_TIME_MD_HM_VALUE:
        case SE_DRM_TYP_SE_TIME_MD_HMS_VALUE:
        case SE_DRM_TYP_SE_TIME_Y_VALUE:
        case SE_DRM_TYP_SE_TIME_YD_VALUE:
        case SE_DRM_TYP_SE_TIME_YD_H_VALUE:
        case SE_DRM_TYP_SE_TIME_YD_HM_VALUE:
        case SE_DRM_TYP_SE_TIME_YD_HMS_VALUE:
        case SE_DRM_TYP_SE_TIME_YMD_VALUE:
        case SE_DRM_TYP_SE_TIME_YMD_H_VALUE:
        case SE_DRM_TYP_SE_TIME_YMD_HM_VALUE:
        case SE_DRM_TYP_SE_TIME_YMD_HMS_VALUE:
        case SE_DRM_TYP_SE_TIME_OF_DAY:
        case SE_DRM_TYP_SE_TIME_SIGNIFICANCE:
        case SE_DRM_TYP_SE_TIME_VALUE:
        case SE_DRM_TYP_SRM_TM_PARAMETERS:
        case SE_DRM_TYP_SE_TYPE_CLASSIFICATION:
        case SE_DRM_TYP_SE_UNDERLINE_STYLE:
        case SE_DRM_TYP_SE_UNION_REASON:
        case SE_DRM_TYP_EDCS_UNIT_CODE:
        case SE_DRM_TYP_EDCS_UNIT_CONCEPT:
        case SE_DRM_TYP_EDCS_UNIT_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_CODE:
        case SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_LABEL:
        case SE_DRM_TYP_EDCS_UNIT_LABEL:
        case SE_DRM_TYP_EDCS_UNIT_SCALE_CODE:
        case SE_DRM_TYP_EDCS_UNIT_SCALE_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_UNIT_SCALE_LABEL:
        case SE_DRM_TYP_EDCS_UNIT_STATUS:
        case SE_DRM_TYP_SRM_UNUSED:
        case SE_DRM_TYP_SE_URL:
        case SE_DRM_TYP_SE_URN:
        case SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_APPLICABILITY:
        case SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_CODE:
        case SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_DICTIONARY_ENTRY:
        case SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_LABEL:
        case SE_DRM_TYP_SE_VARIABLE_CODE:
        case SE_DRM_TYP_SRM_VECTOR_3D:
        case SE_DRM_TYP_SE_YIQ_DATA:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidDRMType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidElementType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidElementType
(
    const SE_Element_Type *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidElementType: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->code_type)
    {
        case SE_ELEMTYPCOD_ATTRIBUTE:
            if (!EDCS_ValidAttributeCode(value_ptr->code.attribute))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Attribute_Code value (%d)\n",
                        (int) value_ptr->code.attribute);
            }
            break;

        case SE_ELEMTYPCOD_INDEX:
            if (!SE_ValidIndexCode(value_ptr->code.index))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SE_Index_Code value (%d)\n", (int)
                        value_ptr->code.index);
            }
            break;

        case SE_ELEMTYPCOD_VARIABLE:
            if (!SE_ValidVariableCode(value_ptr->code.variable))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SE_Variable_Code value (%d)\n",
                        (int) value_ptr->code.variable);
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Element_Type_Code value (%d)\n",
                         (int) value_ptr->code_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidElementType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidElementTypeCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidElementTypeCode
(
    SE_Element_Type_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ELEMTYPCOD_ATTRIBUTE:
        case SE_ELEMTYPCOD_INDEX:
        case SE_ELEMTYPCOD_VARIABLE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidElementTypeCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidEnumerantStructure
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidEnumerantStructure
(
    const SE_Enumerant_Structure *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidEnumerantStructure: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->abstract_name_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->abstract_name_ptr\n");
        }
    }
    if (!value_ptr->name_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->name_ptr\n");
        }
    }
    return result;
} /* end SE_ValidEnumerantStructure */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFeatureTopologyLevel
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidFeatureTopologyLevel
(
    SE_Feature_Topology_Level value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_FTL_ZERO:
        case SE_FTL_ONE:
        case SE_FTL_TWO:
        case SE_FTL_THREE:
        case SE_FTL_FOUR:
        case SE_FTL_FIVE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidFeatureTopologyLevel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFieldModifier
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidFieldModifier
(
    SE_Field_Modifier value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_FLD_MDFR_PLAIN:
        case SE_FLD_MDFR_BIT:
        case SE_FLD_MDFR_1D_ARRAY:
        case SE_FLD_MDFR_2D_ARRAY:
        case SE_FLD_MDFR_POINTER:
        case SE_FLD_MDFR_UNION:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidFieldModifier */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFontStyle
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidFontStyle
(
    SE_Font_Style value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_FONT_NORMAL:
        case SE_FONT_BOLD:
        case SE_FONT_ITALIC:
        case SE_FONT_BOLD_ITALIC:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidFontStyle */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFunctionalAssociationMeaningType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidFunctionalAssociationMeaningType
(
    SE_Functional_Association_Meaning_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_FNASSMNTYP_CONTROLS:
        case SE_FNASSMNTYP_CONTROLLED_BY:
        case SE_FNASSMNTYP_SUPPORTS:
        case SE_FNASSMNTYP_SUPPORTED_BY:
        case SE_FNASSMNTYP_ATTACHED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidFunctionalAssociationMeaningType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeometricCentreCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidGeometricCentreCode
(
    SE_Geometric_Centre_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_GEOMCTRCOD_CENTRE_OF_BUOYANCY:
        case SE_GEOMCTRCOD_CENTRE_OF_MASS:
        case SE_GEOMCTRCOD_CENTRE_OF_PRESSURE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidGeometricCentreCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeometryTopologyLevel
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidGeometryTopologyLevel
(
    SE_Geometry_Topology_Level value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_GTL_ZERO:
        case SE_GTL_ONE:
        case SE_GTL_TWO:
        case SE_GTL_THREE:
        case SE_GTL_FOUR:
        case SE_GTL_FIVE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidGeometryTopologyLevel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGridOverlapOperator
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidGridOverlapOperator
(
    SE_Grid_Overlap_Operator value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_GROVLOP_BASE:
        case SE_GROVLOP_REPLACE:
        case SE_GROVLOP_MERGE:
        case SE_GROVLOP_ADD:
        case SE_GROVLOP_MEAN:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidGridOverlapOperator */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHSMultiplicityCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidHSMultiplicityCode
(
    SE_HS_Multiplicity_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_HSMULCOD_EXACT:
        case SE_HSMULCOD_ORDER_OF_MAGNITUDE:
        case SE_HSMULCOD_UNKNOWN:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidHSMultiplicityCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageComponentType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageComponentType
(
    SE_Image_Component_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGCOMP_SIGNED_INTEGER:
        case SE_IMAGCOMP_UNSIGNED_INTEGER:
        case SE_IMAGCOMP_FLOATING_POINT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageComponentType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageMappingMethod
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageMappingMethod
(
    SE_Image_Mapping_Method value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGMAPMETH_REPLACE:
        case SE_IMAGMAPMETH_DECAL:
        case SE_IMAGMAPMETH_MODULATE:
        case SE_IMAGMAPMETH_BLEND:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageMappingMethod */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageMIPExtents
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageMIPExtents
(
    const SE_Image_MIP_Extents *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidImageMIPExtents: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidIntegerPositive(value_ptr->size_horizontal))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal value_ptr->size_horizontal value (%d)\n",
                (int) value_ptr->size_horizontal);
    }
    if (!SE_ValidIntegerPositive(value_ptr->size_vertical))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal value_ptr->size_vertical value (%d)\n",
                (int) value_ptr->size_vertical);
    }
    if (!SE_ValidIntegerPositive(value_ptr->size_z))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal value_ptr->size_z value (%d)\n", (int)
                value_ptr->size_z);
    }
    return result;
} /* end SE_ValidImageMIPExtents */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageProjectionType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageProjectionType
(
    SE_Image_Projection_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGPROJTYP_PLANAR:
        case SE_IMAGPROJTYP_CYLINDRICAL:
        case SE_IMAGPROJTYP_SPHERICAL:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageProjectionType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageScanDirection
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageScanDirection
(
    SE_Image_Scan_Direction value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGSCANDIR_RIGHT_UP:
        case SE_IMAGSCANDIR_RIGHT_DOWN:
        case SE_IMAGSCANDIR_DOWN_RIGHT:
        case SE_IMAGSCANDIR_DOWN_LEFT:
        case SE_IMAGSCANDIR_LEFT_UP:
        case SE_IMAGSCANDIR_LEFT_DOWN:
        case SE_IMAGSCANDIR_UP_RIGHT:
        case SE_IMAGSCANDIR_UP_LEFT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageScanDirection */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageScanDirectionZ
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageScanDirectionZ
(
    SE_Image_Scan_Direction_Z value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGSCANDIRZ_NONE:
        case SE_IMAGSCANDIRZ_Z_BACK:
        case SE_IMAGSCANDIRZ_Z_FRONT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageScanDirectionZ */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageSignature
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageSignature
(
    SE_Image_Signature value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGSIG_ALPHA:
        case SE_IMAGSIG_LUMINANCE:
        case SE_IMAGSIG_COLOUR_COORDINATE_1:
        case SE_IMAGSIG_COLOUR_COORDINATE_2:
        case SE_IMAGSIG_COLOUR_COORDINATE_3:
        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
        case SE_IMAGSIG_123COLOUR:
        case SE_IMAGSIG_123COLOUR_ALPHA:
        case SE_IMAGSIG_ONE_MATERIAL:
        case SE_IMAGSIG_TWO_MATERIALS:
        case SE_IMAGSIG_THREE_MATERIALS:
        case SE_IMAGSIG_IMAGE_INDEX:
        case SE_IMAGSIG_BUMP_MAP_UV:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageSignature */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageWrap
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageWrap
(
    SE_Image_Wrap value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IMAGWRAP_CLAMP:
        case SE_IMAGWRAP_REPEAT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidImageWrap */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIndexCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIndexCode
(
    SE_Index_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_IDXCODE_DATA_TABLE_COMPONENT:
        case SE_IDXCODE_DATA_TABLE_LIBRARY:
        case SE_IDXCODE_IMAGE_MAPPING_FUNCTION:
        case SE_IDXCODE_PROP_TABLE_REF_COMPONENT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidIndexCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntegerIntervalValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIntegerIntervalValue
(
    const SE_Integer_Interval_Value *value_ptr,
          SE_Boolean                 print_error,
          SE_Integer_Unsigned       *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidIntegerIntervalValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->interval_type)
    {
        case SE_INTRVLTYP_OPEN_INTERVAL:
            if (!EDCS_ValidIntegerInterval(&(value_ptr->value.open_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GE_LT_INTERVAL:
            if (!EDCS_ValidIntegerInterval(&(value_ptr->value.ge_lt_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GT_LE_INTERVAL:
            if (!EDCS_ValidIntegerInterval(&(value_ptr->value.gt_le_interval),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_CLOSED_INTERVAL:
            if (!EDCS_ValidIntegerInterval(
                      &(value_ptr->value.closed_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GT_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_GE_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_LT_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_LE_SEMI_INTERVAL:
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Interval_Type value (%d)\n", (int)
                         value_ptr->interval_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidIntegerIntervalValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntegerPositive
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIntegerPositive
(
    SE_Integer_Positive value
)
{
    SE_Boolean result = SE_TRUE;

    if (value < 1)
        result = SE_FALSE;

    return result;
} /* end SE_ValidIntegerPositive */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidInterpolationType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidInterpolationType
(
    SE_Interpolation_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_INTERPTYP_BICUBIC_SPLINE:
        case SE_INTERPTYP_DIAGONALIZATION:
        case SE_INTERPTYP_DISALLOWED:
        case SE_INTERPTYP_KRIGING:
        case SE_INTERPTYP_LAGRANGIAN:
        case SE_INTERPTYP_LINEAR:
        case SE_INTERPTYP_METADATA_SPECIFIED:
        case SE_INTERPTYP_NEAREST_NEIGHBOUR:
        case SE_INTERPTYP_NOT_SUPPLIED:
        case SE_INTERPTYP_OAML_DBDB_SPLINE_FIT:
        case SE_INTERPTYP_QUADRATIC:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidInterpolationType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntervalType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIntervalType
(
    SE_Interval_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_INTRVLTYP_OPEN_INTERVAL:
        case SE_INTRVLTYP_GE_LT_INTERVAL:
        case SE_INTRVLTYP_GT_LE_INTERVAL:
        case SE_INTRVLTYP_CLOSED_INTERVAL:
        case SE_INTRVLTYP_GT_SEMI_INTERVAL:
        case SE_INTRVLTYP_GE_SEMI_INTERVAL:
        case SE_INTRVLTYP_LT_SEMI_INTERVAL:
        case SE_INTRVLTYP_LE_SEMI_INTERVAL:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidIntervalType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntervalValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIntervalValue
(
    const SE_Interval_Value *value_ptr,
          SE_Boolean         print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidIntervalValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->value_type)
    {
        case SE_INTRVLVALTYP_FLOAT:
            if (!SE_ValidLongFloatIntervalValue(
                      &(value_ptr->value.long_float_value), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Long_Float_Interval_Value"\
                           " value\n");
                }
            }
            break;

        case SE_INTRVLVALTYP_INTEGER:
            if (!SE_ValidIntegerIntervalValue(
                      &(value_ptr->value.integer_value), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Integer_Interval_Value"\
                           " value\n");
                }
            }
            break;

        case SE_INTRVLVALTYP_COUNT:
            if (!SE_ValidCountIntervalValue(&(value_ptr->value.count_value),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Count_Interval_Value value\n");
                }
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Interval_Value_Type value (%d)\n",
                         (int) value_ptr->value_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidIntervalValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntervalValueType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIntervalValueType
(
    SE_Interval_Value_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_INTRVLVALTYP_FLOAT:
        case SE_INTRVLVALTYP_INTEGER:
        case SE_INTRVLVALTYP_COUNT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidIntervalValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLODDataType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidLODDataType
(
    SE_LOD_Data_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_LODDATTYP_DISTANCE:
        case SE_LODDATTYP_INDEX:
        case SE_LODDATTYP_MAP_SCALE:
        case SE_LODDATTYP_VOLUME:
        case SE_LODDATTYP_SPATIAL_RESOLUTION:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidLODDataType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLongFloatIntervalValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidLongFloatIntervalValue
(
    const SE_Long_Float_Interval_Value *value_ptr,
          SE_Boolean                    print_error,
          SE_Integer_Unsigned          *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidLongFloatIntervalValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->interval_type)
    {
        case SE_INTRVLTYP_OPEN_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.open_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GE_LT_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.ge_lt_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GT_LE_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.gt_le_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_CLOSED_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.closed_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case SE_INTRVLTYP_GT_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_GE_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_LT_SEMI_INTERVAL:
            break;

        case SE_INTRVLTYP_LE_SEMI_INTERVAL:
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Interval_Type value (%d)\n", (int)
                         value_ptr->interval_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidLongFloatIntervalValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLongFloatValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidLongFloatValue
(
    const SE_Long_Float_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidLongFloatValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->numeric_value_type)
    {
        case EDCS_NVT_SINGLE_VALUE:
            break;

        case EDCS_NVT_OPEN_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.open_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GE_LT_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.ge_lt_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GT_LE_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.gt_le_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_CLOSED_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.closed_interval), (EDCS_Boolean)
                      print_error, (EDCS_Count *) error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GT_SEMI_INTERVAL:
            break;

        case EDCS_NVT_GE_SEMI_INTERVAL:
            break;

        case EDCS_NVT_LT_SEMI_INTERVAL:
            break;

        case EDCS_NVT_LE_SEMI_INTERVAL:
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal EDCS_Numeric_Value_Type value (%d)\n",
                         (int) value_ptr->numeric_value_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidLongFloatValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLSRTransformationAxis
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidLSRTransformationAxis
(
    SE_LSR_Transformation_Axis value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_LSRAXIS_U:
        case SE_LSRAXIS_V:
        case SE_LSRAXIS_W:
        case SE_LSRAXIS_ALL:
        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidLSRTransformationAxis */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMDClassificationCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidMDClassificationCode
(
    SE_MD_ClassificationCode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MD_CLSCOD_UNCLASSIFIED:
        case SE_MD_CLSCOD_RESTRICTED:
        case SE_MD_CLSCOD_CONFIDENTIAL:
        case SE_MD_CLSCOD_SECRET:
        case SE_MD_CLSCOD_TOP_SECRET:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidMDClassificationCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMDKeywordTypeCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidMDKeywordTypeCode
(
    SE_MD_KeywordTypeCode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MD_KEYTYPCOD_DISCIPLINE:
        case SE_MD_KEYTYPCOD_PLACE:
        case SE_MD_KEYTYPCOD_STRATUM:
        case SE_MD_KEYTYPCOD_TEMPORAL:
        case SE_MD_KEYTYPCOD_THEME:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidMDKeywordTypeCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMDRestrictionCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidMDRestrictionCode
(
    SE_MD_RestrictionCode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MD_RESTRICTCOD_COPYRIGHT:
        case SE_MD_RESTRICTCOD_PATENT:
        case SE_MD_RESTRICTCOD_PATENT_PENDING:
        case SE_MD_RESTRICTCOD_TRADEMARK:
        case SE_MD_RESTRICTCOD_LICENSE:
        case SE_MD_RESTRICTCOD_INTELLECTUAL_PROPERTY_RIGHTS:
        case SE_MD_RESTRICTCOD_RESTRICTED:
        case SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidMDRestrictionCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMediaFormat
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidMediaFormat
(
    SE_Media_Format value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MEDIAFMT_AVI:
        case SE_MEDIAFMT_BIIF:
        case SE_MEDIAFMT_BMP:
        case SE_MEDIAFMT_CGM:
        case SE_MEDIAFMT_GIF:
        case SE_MEDIAFMT_HTML:
        case SE_MEDIAFMT_JPEG:
        case SE_MEDIAFMT_JPEG2000:
        case SE_MEDIAFMT_NITFS:
        case SE_MEDIAFMT_PICT:
        case SE_MEDIAFMT_PNG:
        case SE_MEDIAFMT_QT:
        case SE_MEDIAFMT_RGB:
        case SE_MEDIAFMT_RIFF:
        case SE_MEDIAFMT_SVG:
        case SE_MEDIAFMT_TIFF:
        case SE_MEDIAFMT_WMF:
        case SE_MEDIAFMT_XBM:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidMediaFormat */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidModelReferenceType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidModelReferenceType
(
    SE_Model_Reference_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MODREFTYP_COMPONENT:
        case SE_MODREFTYP_ROOT:
        case SE_MODREFTYP_ROOT_AND_COMPONENT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidModelReferenceType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMonth
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidMonth
(
    SE_Month value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MONTH_JANUARY:
        case SE_MONTH_FEBRUARY:
        case SE_MONTH_MARCH:
        case SE_MONTH_APRIL:
        case SE_MONTH_MAY:
        case SE_MONTH_JUNE:
        case SE_MONTH_JULY:
        case SE_MONTH_AUGUST:
        case SE_MONTH_SEPTEMBER:
        case SE_MONTH_OCTOBER:
        case SE_MONTH_NOVEMBER:
        case SE_MONTH_DECEMBER:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidMonth */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMultiplicity
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidMultiplicity
(
    SE_Multiplicity value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_MLTPCTY_EXACTLY_ONE:
        case SE_MLTPCTY_ZERO_OR_ONE:
        case SE_MLTPCTY_ZERO_OR_MORE:
        case SE_MLTPCTY_ONE_OR_MORE:
        case SE_MLTPCTY_EXACTLY_N:
        case SE_MLTPCTY_BOUNDED_ARRAY:
        case SE_MLTPCTY_UNBOUNDED_ARRAY:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidMultiplicity */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidOctant
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidOctant
(
    SE_Octant value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_OCTANT_UPPER_LEFT_FRONT:
        case SE_OCTANT_UPPER_LEFT_BACK:
        case SE_OCTANT_LOWER_LEFT_FRONT:
        case SE_OCTANT_LOWER_LEFT_BACK:
        case SE_OCTANT_UPPER_RIGHT_FRONT:
        case SE_OCTANT_UPPER_RIGHT_BACK:
        case SE_OCTANT_LOWER_RIGHT_FRONT:
        case SE_OCTANT_LOWER_RIGHT_BACK:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidOctant */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidOrderingReason
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidOrderingReason
(
    SE_Ordering_Reason value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ORDREAS_NONE:
        case SE_ORDREAS_FIXED_LISTED:
        case SE_ORDREAS_LAYERED_FASTEST_RENDERING:
        case SE_ORDREAS_LAYERED_HIGH_QUALITY_RENDERING:
        case SE_ORDREAS_SHARED_ATTRIBUTE:
        case SE_ORDREAS_VIEWER_RANGE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidOrderingReason */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPixelFillMethod
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPixelFillMethod
(
    SE_Pixel_Fill_Method value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_PIXFILLMETH_CONSTANT:
        case SE_PIXFILLMETH_BLEND:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidPixelFillMethod */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPointLightDisplayType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPointLightDisplayType
(
    SE_Point_Light_Display_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_PTLTDISPTYP_RASTER:
        case SE_PTLTDISPTYP_CALLIGRAPHIC:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidPointLightDisplayType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPolygonFlag
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPolygonFlag
(
    const SE_Polygon_Flag *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidPolygonFlag: NULL value_ptr\n");
        }
        return result;
    }
    else if (!(value_ptr->member.Raised) &&
             (value_ptr->member.Opaque_Top ||
              value_ptr->member.Visible_Floor ||
              value_ptr->member.Visible_Interior ||
              value_ptr->member.Visible_Perimeter))
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr,
             "SE_ValidPolygonFlag: value_ptr->member.Raised is false but "\
             "value_ptr->member.Opaque_Top or "\
             "value_ptr->member.Visible_Floor or "\
             "value_ptr->member.Visible_Interior or "\
             "value_ptr->member.Visible_Perimeter is true\n");
        }
        return result;
    }
    return result;
} /* end SE_ValidPolygonFlag */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPredefFuncArgStructure
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPredefFuncArgStructure
(
    const SE_Predef_Func_Arg_Structure *value_ptr,
          SE_Boolean                    print_error,
          SE_Integer_Unsigned          *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidPredefFuncArgStructure: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidIntegerPositive(value_ptr->valid_type_count))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal value_ptr->valid_type_count value (%d)\n",
                (int) value_ptr->valid_type_count);
    }
    else if (!value_ptr->valid_type_array)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->valid_type_array for"\
                   " value_ptr->valid_type_count == %u\n",(unsigned int)
                    value_ptr->valid_type_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->valid_type_count; i++)
        {
            if (!EDCS_ValidAttributeValueType(value_ptr->valid_type_array[i]))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Invalid enumerant %d found, expected EDCS_Attribute_Value_Type\n", (int)value_ptr->valid_type_array[i]);
            }
        } /* end for i */
    }
    return result;
} /* end SE_ValidPredefFuncArgStructure */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPredefFuncStructure
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPredefFuncStructure
(
    const SE_Predef_Func_Structure *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidPredefFuncStructure: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->argument_array && (value_ptr->argument_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->argument_array for"\
                   " value_ptr->argument_count == %u\n",(unsigned int)
                    value_ptr->argument_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->argument_count; i++)
        {
            if (!SE_ValidPredefFuncArgStructure
                    (&(value_ptr->argument_array[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Predef_Func_Arg_Structure found at "\
                        "value_ptr->argument_array[%u]\n", i);
                }
            }
        } /* end for i */
    }
    return result;
} /* end SE_ValidPredefFuncStructure */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPredefinedFunction
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPredefinedFunction
(
    SE_Predefined_Function value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_PREDEFFN_ADD:
        case SE_PREDEFFN_DIVIDE:
        case SE_PREDEFFN_MODULO:
        case SE_PREDEFFN_MULTIPLY:
        case SE_PREDEFFN_SUBTRACT:
        case SE_PREDEFFN_COSINE:
        case SE_PREDEFFN_SINE:
        case SE_PREDEFFN_TANGENT:
        case SE_PREDEFFN_ARCCOSINE:
        case SE_PREDEFFN_ARCSINE:
        case SE_PREDEFFN_ARCTANGENT:
        case SE_PREDEFFN_ARCTANGENT2:
        case SE_PREDEFFN_HYPOTENUSE:
        case SE_PREDEFFN_ABSOLUTE:
        case SE_PREDEFFN_EXPONENT:
        case SE_PREDEFFN_LN:
        case SE_PREDEFFN_LOG:
        case SE_PREDEFFN_POWER:
        case SE_PREDEFFN_SQRT:
        case SE_PREDEFFN_MAXIMUM:
        case SE_PREDEFFN_MINIMUM:
        case SE_PREDEFFN_NOT:
        case SE_PREDEFFN_AND:
        case SE_PREDEFFN_EQUAL:
        case SE_PREDEFFN_GREATER_THAN:
        case SE_PREDEFFN_GREATER_THAN_OR_EQUAL:
        case SE_PREDEFFN_LESS_THAN:
        case SE_PREDEFFN_LESS_THAN_OR_EQUAL:
        case SE_PREDEFFN_NOT_EQUAL:
        case SE_PREDEFFN_OR:
        case SE_PREDEFFN_EXCLUSIVE_OR:
        case SE_PREDEFFN_IF:
        case SE_PREDEFFN_PI:
        case SE_PREDEFFN_SIMULATION_TIME:
        case SE_PREDEFFN_SIMULATION_UTIME:
        case SE_PREDEFFN_REFERENCE_SURFACE_ELEVATION:
        case SE_PREDEFFN_CYCLE_TIME:
        case SE_PREDEFFN_TABLE_VALUE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidPredefinedFunction */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPresentIn
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPresentIn
(
    SE_Present_In value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_PRESENT_IN_NONE:
        case SE_PRESENT_IN_ENVIRONMENT_ROOT:
        case SE_PRESENT_IN_MODELS:
        case SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidPresentIn */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPresentationDomain
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPresentationDomain
(
    const SE_Presentation_Domain *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidPresentationDomain: NULL value_ptr\n");
        }
        return result;
    }
    else if (value_ptr->set == 0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidPresentationDomain: value_ptr->set == 0\n");
        }
        return result;
    }
    return result;
} /* end SE_ValidPresentationDomain */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPropertyCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPropertyCode
(
    const SE_Property_Code *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidPropertyCode: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->code_type)
    {
        case SE_PROPCODTYP_ATTRIBUTE:
            if (!EDCS_ValidAttributeCode(value_ptr->code.attribute))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Attribute_Code value (%d)\n",
                        (int) value_ptr->code.attribute);
            }
            break;

        case SE_PROPCODTYP_VARIABLE:
            if (!SE_ValidVariableCode(value_ptr->code.variable))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SE_Variable_Code value (%d)\n",
                        (int) value_ptr->code.variable);
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Property_Code_Type value (%d)\n",
                         (int) value_ptr->code_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidPropertyCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPropertyCodeType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidPropertyCodeType
(
    SE_Property_Code_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_PROPCODTYP_ATTRIBUTE:
        case SE_PROPCODTYP_VARIABLE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidPropertyCodeType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidQuadrant
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidQuadrant
(
    SE_Quadrant value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_QUADRANT_LEFT_FRONT:
        case SE_QUADRANT_RIGHT_FRONT:
        case SE_QUADRANT_LEFT_BACK:
        case SE_QUADRANT_RIGHT_BACK:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidQuadrant */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReferenceSurfaceElevationSelect
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidReferenceSurfaceElevationSelect
(
    SE_Reference_Surface_Elevation_Select value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_RSELEVSEL_CLOSEST_TO_ORM_CENTRE:
        case SE_RSELEVSEL_CLOSEST_TO_DSS:
        case SE_RSELEVSEL_FARTHEST_FROM_ORM_CENTRE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidReferenceSurfaceElevationSelect */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReferenceSurfaceLODSelect
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidReferenceSurfaceLODSelect
(
    SE_Reference_Surface_LOD_Select value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_RSLODSEL_MOST_DETAILED:
        case SE_RSLODSEL_LEAST_DETAILED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidReferenceSurfaceLODSelect */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReferenceVectorType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidReferenceVectorType
(
    SE_Reference_Vector_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_REFVEC_CAMERA_FORWARD_AXIS:
        case SE_REFVEC_CAMERA_UP_AXIS:
        case SE_REFVEC_EMISSIVITY_AZIMUTH:
        case SE_REFVEC_EMISSIVITY_NORMAL:
        case SE_REFVEC_FACE_NORMAL:
        case SE_REFVEC_LIGHT_DIRECTION:
        case SE_REFVEC_LSR_TRANSFORMATION_AXIS:
        case SE_REFVEC_MAJOR_AXIS:
        case SE_REFVEC_MINOR_AXIS:
        case SE_REFVEC_MOVEMENT_DIRECTION:
        case SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION:
        case SE_REFVEC_REFLECTIVITY_AZIMUTH:
        case SE_REFVEC_REFLECTIVITY_EMISSIVITY_AZIMUTH:
        case SE_REFVEC_REFLECTIVITY_EMISSIVITY_NORMAL:
        case SE_REFVEC_REFLECTIVITY_NORMAL:
        case SE_REFVEC_RENDERING_NORMAL:
        case SE_REFVEC_VERTICAL_AXIS:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidReferenceVectorType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSeason
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSeason
(
    SE_Season value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SEASON_SPRING:
        case SE_SEASON_SUMMER:
        case SE_SEASON_AUTUMN:
        case SE_SEASON_WINTER:
        case SE_SEASON_DRY:
        case SE_SEASON_WET:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSeason */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidShadingMethod
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidShadingMethod
(
    SE_Shading_Method value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SHADMETH_NONE:
        case SE_SHADMETH_FLAT:
        case SE_SHADMETH_INTERPOLATED_COLOUR:
        case SE_SHADMETH_INTERPOLATED_NORMAL:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidShadingMethod */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidShortIntegerPositive
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidShortIntegerPositive
(
    SE_Short_Integer_Positive value
)
{
    SE_Boolean result = SE_TRUE;

    if (value < 1)
        result = SE_FALSE;

    return result;
} /* end SE_ValidShortIntegerPositive */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSingleValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSingleValue
(
          EDCS_Attribute_Code     attr_code,
    const SE_Single_Value *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidSingleValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
            break;

        case SE_SINGVALTYP_INTEGER:
            break;

        case SE_SINGVALTYP_COUNT:
            break;

        case SE_SINGVALTYP_INDEX:
            break;

        case SE_SINGVALTYP_STRING:
            if (!EDCS_ValidString(&(value_ptr->value.string_value),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_String value\n");
                }
            }
            break;

        case SE_SINGVALTYP_CONSTRAINED_STRING:
            if (!EDCS_ValidString(
                      &(value_ptr->value.constrained_string_value),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_String value\n");
                }
            }
            break;

        case SE_SINGVALTYP_KEY:
            if (!EDCS_ValidString(&(value_ptr->value.key_value),
                      (EDCS_Boolean) print_error, (EDCS_Count *)
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_String value\n");
                }
            }
            break;

        case SE_SINGVALTYP_ENUMERATION:
            if (!EDCS_ValidEnumerantCode(attr_code,
               value_ptr->value.enumerant_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Enumerant_Code value (%d)\n",
                        (int) value_ptr->value.enumerant_value);
            }
            break;

        case SE_SINGVALTYP_BOOLEAN:
            if (!EDCS_ValidBoolean(value_ptr->value.boolean_value))
            {
                result = SE_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Boolean value (%d)\n", (int)
                        value_ptr->value.boolean_value);
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Single_Value_Type value (%d)\n",
                         (int) value_ptr->value_type);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidSingleValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSingleValueType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSingleValueType
(
    SE_Single_Value_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
        case SE_SINGVALTYP_INTEGER:
        case SE_SINGVALTYP_COUNT:
        case SE_SINGVALTYP_INDEX:
        case SE_SINGVALTYP_STRING:
        case SE_SINGVALTYP_CONSTRAINED_STRING:
        case SE_SINGVALTYP_KEY:
        case SE_SINGVALTYP_ENUMERATION:
        case SE_SINGVALTYP_BOOLEAN:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSingleValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSoundFormat
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSoundFormat
(
    SE_Sound_Format value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SOUNDFMT_AIFC:
        case SE_SOUNDFMT_AIFF:
        case SE_SOUNDFMT_AVI:
        case SE_SOUNDFMT_IFF:
        case SE_SOUNDFMT_MIDI:
        case SE_SOUNDFMT_MP2:
        case SE_SOUNDFMT_MP3:
        case SE_SOUNDFMT_MPG:
        case SE_SOUNDFMT_QT:
        case SE_SOUNDFMT_RA:
        case SE_SOUNDFMT_SND:
        case SE_SOUNDFMT_VOC:
        case SE_SOUNDFMT_WAV:
        case SE_SOUNDFMT_WVE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSoundFormat */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpacingType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSpacingType
(
    SE_Spacing_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SPACTYP_ARITHMETIC:
        case SE_SPACTYP_GEOMETRIC:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSpacingType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpatialAssociationMeaningType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSpatialAssociationMeaningType
(
    SE_Spatial_Association_Meaning_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SPATASSMEANTYP_ALTERNATE_REPRESENTATION:
        case SE_SPATASSMEANTYP_CONTAINS:
        case SE_SPATASSMEANTYP_CONTAINED_BY:
        case SE_SPATASSMEANTYP_CROSS:
        case SE_SPATASSMEANTYP_DISJOINT:
        case SE_SPATASSMEANTYP_INTERSECTS:
        case SE_SPATASSMEANTYP_OVERLAP:
        case SE_SPATASSMEANTYP_TOUCH:
        case SE_SPATASSMEANTYP_IN_PROXIMITY_OF:
        case SE_SPATASSMEANTYP_COMPLETELY_ABOVE:
        case SE_SPATASSMEANTYP_PARTIALLY_ABOVE:
        case SE_SPATASSMEANTYP_COMPLETELY_BELOW:
        case SE_SPATASSMEANTYP_PARTIALLY_BELOW:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSpatialAssociationMeaningType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpatialIndexSpacingUnit
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSpatialIndexSpacingUnit
(
    SE_Spatial_Index_Spacing_Unit value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SISPACUNITS_METRE:
        case SE_SISPACUNITS_ARC_SECOND:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSpatialIndexSpacingUnit */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSRFContextInfo
(
    const SE_SRF_Context_Info *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    const EDCS_Unit_Dictionary_Entry *unit_entry_ptr = NULL;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidSRFContextInfo: NULL value_ptr\n");
        }
        return result;
    }

    if (!EDCS_ValidUnitCode(value_ptr->angular_unit))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Code value (%d)\n", (int)
                value_ptr->angular_unit);
    }
    else if (EDCS_GetEUDictionaryEntry(value_ptr->angular_unit,
             &unit_entry_ptr) != EDCS_SC_SUCCESS)
    {
        if (print_error)
            fprintf(f_ptr,
                    "SE_ValidSRFContextInfo: corruption detected, "\
                    "EDCS_GetEUDictionaryEntry failed for valid EU\n");
            fflush(f_ptr);
    }
    else if (unit_entry_ptr->eq_code != EQC_PLANE_ANGLE)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "angular_unit (%s) does not belong to EQC_PLANE_ANGLE\n",
                EDCS_PrintUnitCode(value_ptr->angular_unit));
    }
    if (!EDCS_ValidUnitCode(value_ptr->linear_unit))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Code value (%d)\n", (int)
                value_ptr->linear_unit);
    }
    else if (EDCS_GetEUDictionaryEntry(value_ptr->linear_unit,
             &unit_entry_ptr) != EDCS_SC_SUCCESS)
    {
        if (print_error)
            fprintf(f_ptr,
                    "SE_ValidSRFContextInfo: corruption detected, "\
                    "EDCS_GetEUDictionaryEntry failed for valid EU\n");
            fflush(f_ptr);
    }
    else if (unit_entry_ptr->eq_code != EQC_LENGTH)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "linear_unit (%s) does not belong to EQC_LENGTH\n",
                EDCS_PrintUnitCode(value_ptr->linear_unit));
    }
    if (!EDCS_ValidUnitScaleCode(value_ptr->linear_scale))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Scale_Code value (%d)\n", (int)
                value_ptr->linear_scale);
    }
    if (!SE_ValidBoolean(value_ptr->use_dss_code))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->use_dss_code);
    }
    else if (((value_ptr->use_dss_code == SE_FALSE) &&(value_ptr->dss_code !=
       SRM_DSSCOD_UNSPECIFIED)) || ((value_ptr->use_dss_code == SE_TRUE) &&
       ((value_ptr->dss_code == SRM_DSSCOD_UNSPECIFIED) ||
       !SRM_ValidDSSCode(value_ptr->dss_code))))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_DSS_Code value (%d)\n", (int)
                value_ptr->dss_code);
    }
    if (!SRM_ValidSRFParametersInfo(&(value_ptr->srf_parameters_info),
              (SRM_Boolean) print_error, (SRM_Integer_Unsigned *)
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SRM_SRF_Parameters_Info value\n");
        }
    }
    return result;
} /* end SE_ValidSRFContextInfo */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStateMismatchBehaviour
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidStateMismatchBehaviour
(
    SE_State_Mismatch_Behaviour value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_STMISMBEH_DEFAULT:
        case SE_STMISMBEH_LAST:
        case SE_STMISMBEH_NONE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidStateMismatchBehaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidString
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidString
(
    const SE_String *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidString: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidLocale(&(value_ptr->locale), print_error, error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_Locale value\n");
        }
    }
    if (!value_ptr->characters && (value_ptr->length>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->characters for value_ptr->length"\
                   " == %u\n",(unsigned int) value_ptr->length);
        }
    }
    return result;
} /* end SE_ValidString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSymbolFormat
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidSymbolFormat
(
    SE_Symbol_Format value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_SYMBFMT_CGM:
        case SE_SYMBFMT_SVG:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidSymbolFormat */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTelephoneInformation
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTelephoneInformation
(
    const SE_Telephone_Information *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTelephoneInformation: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->voice && (value_ptr->voice_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->voice for value_ptr->voice_count"\
                   " == %u\n",(unsigned int) value_ptr->voice_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->voice_count; i++)
        {
            if (!SE_ValidNonNullString(&(value_ptr->voice[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_String found at "\
                        "value_ptr->voice[%u]\n", i);
                }
            }
        } /* end for i */
        if ((result == SE_TRUE) && (value_ptr->voice_count > 1))
        {
            for (i = 0; (result == SE_TRUE) && (i <
            (SE_Integer_Unsigned)value_ptr->voice_count-1); i++)
            {
                for (j = i+1; (result == SE_TRUE) && (j <
                (SE_Integer_Unsigned)value_ptr->voice_count); j++)
                {
                    if (SE_CompareStrings(&(value_ptr->voice[i]),
                &(value_ptr->voice[j]))==0)
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Duplicate entry found at "\
                            "value_ptr->voice[%u]\n", j);
                        }
                    }
                } /* end for j */
            } /* end for i */
        }
    }
    if (!value_ptr->facsimile && (value_ptr->facsimile_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->facsimile for"\
                   " value_ptr->facsimile_count == %u\n",(unsigned int)
                    value_ptr->facsimile_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->facsimile_count; i++)
        {
            if (!SE_ValidNonNullString(&(value_ptr->facsimile[i]),
                    print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_String found at "\
                        "value_ptr->facsimile[%u]\n", i);
                }
            }
        } /* end for i */
        if ((result == SE_TRUE) && (value_ptr->facsimile_count > 1))
        {
            for (i = 0; (result == SE_TRUE) && (i <
            (SE_Integer_Unsigned)value_ptr->facsimile_count-1); i++)
            {
                for (j = i+1; (result == SE_TRUE) && (j <
                (SE_Integer_Unsigned)value_ptr->facsimile_count); j++)
                {
                    if (SE_CompareStrings(&(value_ptr->facsimile[i]),
                &(value_ptr->facsimile[j]))==0)
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Duplicate entry found at "\
                            "value_ptr->facsimile[%u]\n", j);
                        }
                    }
                } /* end for j */
            } /* end for i */
        }
    }
    if (!value_ptr->tdd_tty && (value_ptr->tdd_tty_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->tdd_tty for"\
                   " value_ptr->tdd_tty_count == %u\n",(unsigned int)
                    value_ptr->tdd_tty_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i, j;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->tdd_tty_count; i++)
        {
            if (!SE_ValidNonNullString(&(value_ptr->tdd_tty[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_String found at "\
                        "value_ptr->tdd_tty[%u]\n", i);
                }
            }
        } /* end for i */
        if ((result == SE_TRUE) && (value_ptr->tdd_tty_count > 1))
        {
            for (i = 0; (result == SE_TRUE) && (i <
            (SE_Integer_Unsigned)value_ptr->tdd_tty_count-1); i++)
            {
                for (j = i+1; (result == SE_TRUE) && (j <
                (SE_Integer_Unsigned)value_ptr->tdd_tty_count); j++)
                {
                    if (SE_CompareStrings(&(value_ptr->tdd_tty[i]),
                &(value_ptr->tdd_tty[j]))==0)
                    {
                        result = SE_FALSE;
                        if (print_error)
                        {
                            fprintf(f_ptr, "Duplicate entry found at "\
                            "value_ptr->tdd_tty[%u]\n", j);
                        }
                    }
                } /* end for j */
            } /* end for i */
        }
    }
    return result;
} /* end SE_ValidTelephoneInformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTextFont
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTextFont
(
    const SE_Text_Font *value_ptr,
          SE_Boolean    print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTextFont: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidString(&(value_ptr->font_family), print_error,
              error_count_ptr))
    {
        result = SE_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SE_String value\n");
        }
    }
    if (!SE_ValidFontStyle(value_ptr->font_style))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Font_Style value (%d)\n", (int)
                value_ptr->font_style);
    }
    if (!SE_ValidUnderlineStyle(value_ptr->underline_style))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Underline_Style value (%d)\n", (int)
                value_ptr->underline_style);
    }
    return result;
} /* end SE_ValidTextFont */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeConfiguration
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeConfiguration
(
    SE_Time_Configuration value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TIMECFG_DATE_YMD_AND_TIME_HMS:
        case SE_TIMECFG_DATE_YMD_AND_TIME_HM:
        case SE_TIMECFG_DATE_YMD_AND_TIME_H:
        case SE_TIMECFG_DATE_YMD:
        case SE_TIMECFG_DATE_YD_AND_TIME_HMS:
        case SE_TIMECFG_DATE_YD_AND_TIME_HM:
        case SE_TIMECFG_DATE_YD_AND_TIME_H:
        case SE_TIMECFG_DATE_YD:
        case SE_TIMECFG_DATE_MD_AND_TIME_HMS:
        case SE_TIMECFG_DATE_MD_AND_TIME_HM:
        case SE_TIMECFG_DATE_MD_AND_TIME_H:
        case SE_TIMECFG_DATE_Y:
        case SE_TIMECFG_DATE_M:
        case SE_TIMECFG_DAY_OF_YEAR:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeConfiguration */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeDataType
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeDataType
(
    SE_Time_Data_Type value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TIMEDATTYP_SEASON:
        case SE_TIMEDATTYP_TIME_INTERVAL:
        case SE_TIMEDATTYP_TIME_OF_DAY:
        case SE_TIMEDATTYP_TIME_POINT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeDataType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeDayOfYearValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeDayOfYearValue
(
    const SE_Time_Day_Of_Year_Value *value_ptr,
          SE_Boolean                 print_error,
          SE_Integer_Unsigned       *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeDayOfYearValue: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->day_of_year < 1) || (value_ptr->day_of_year > 366))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeDayOfYearValue: day_of_year"\
                    " out of range [1, 366]!\n");
    }
    return result;
} /* end SE_ValidTimeDayOfYearValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeMValue
(
    const SE_Time_M_Value *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeMValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    return result;
} /* end SE_ValidTimeMValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMDHValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeMDHValue
(
    const SE_Time_MD_H_Value *value_ptr,
          SE_Boolean          print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeMDHValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHValue: day"\
                    " out of range [1, 31]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHValue: hour"\
                    " > 23!\n");
    }
    return result;
} /* end SE_ValidTimeMDHValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMDHMValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeMDHMValue
(
    const SE_Time_MD_HM_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeMDHMValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMValue: day"\
                    " out of range [1, 31]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMValue: hour"\
                    " > 23!\n");
    }
    if (value_ptr->minutes > 59)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMValue: minutes"\
                    " > 59!\n");
    }
    return result;
} /* end SE_ValidTimeMDHMValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMDHMSValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeMDHMSValue
(
    const SE_Time_MD_HMS_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeMDHMSValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMSValue: day"\
                    " out of range [1, 31]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMSValue: hour"\
                    " > 23!\n");
    }
    if (value_ptr->minutes > 59)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMSValue: minutes"\
                    " > 59!\n");
    }
    if ((value_ptr->seconds < 0) || (value_ptr->seconds > 60))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeMDHMSValue: seconds"\
                    " out of range [0, 60]!\n");
    }
    return result;
} /* end SE_ValidTimeMDHMSValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeOfDay
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeOfDay
(
    SE_Time_Of_Day value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TIMEOFDAY_DAWN:
        case SE_TIMEOFDAY_MORNING:
        case SE_TIMEOFDAY_DAY:
        case SE_TIMEOFDAY_AFTERNOON:
        case SE_TIMEOFDAY_DUSK:
        case SE_TIMEOFDAY_EVENING:
        case SE_TIMEOFDAY_NIGHT:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeOfDay */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeSignificance
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeSignificance
(
    SE_Time_Significance value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TIMESIGNIF_ANALYSIS:
        case SE_TIMESIGNIF_CERTIFICATION_DATE:
        case SE_TIMESIGNIF_CREATION_DATE:
        case SE_TIMESIGNIF_FORECAST:
        case SE_TIMESIGNIF_MODIFICATION_DATE:
        case SE_TIMESIGNIF_OBSERVATION:
        case SE_TIMESIGNIF_OCCURRENCE:
        case SE_TIMESIGNIF_PERIOD_OF_CONTENT:
        case SE_TIMESIGNIF_PUBLICATION_DATE:
        case SE_TIMESIGNIF_REFERENCE:
        case SE_TIMESIGNIF_REVISION_DATE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeSignificance */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeValue
(
    const SE_Time_Value *value_ptr,
          SE_Boolean     print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->configuration)
    {
        case SE_TIMECFG_DATE_YMD_AND_TIME_HMS:
            if (!SE_ValidTimeYMDHMSValue(&(value_ptr->value.ymd_hms),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YMD_HMS_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YMD_AND_TIME_HM:
            if (!SE_ValidTimeYMDHMValue(&(value_ptr->value.ymd_hm),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YMD_HM_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YMD_AND_TIME_H:
            if (!SE_ValidTimeYMDHValue(&(value_ptr->value.ymd_h), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YMD_H_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YMD:
            if (!SE_ValidTimeYMDValue(&(value_ptr->value.ymd), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YMD_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YD_AND_TIME_HMS:
            if (!SE_ValidTimeYDHMSValue(&(value_ptr->value.yd_hms),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YD_HMS_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YD_AND_TIME_HM:
            if (!SE_ValidTimeYDHMValue(&(value_ptr->value.yd_hm), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YD_HM_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YD_AND_TIME_H:
            if (!SE_ValidTimeYDHValue(&(value_ptr->value.yd_h), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YD_H_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_YD:
            if (!SE_ValidTimeYDValue(&(value_ptr->value.yd), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_YD_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_MD_AND_TIME_HMS:
            if (!SE_ValidTimeMDHMSValue(&(value_ptr->value.md_hms),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_MD_HMS_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_MD_AND_TIME_HM:
            if (!SE_ValidTimeMDHMValue(&(value_ptr->value.md_hm), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_MD_HM_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_MD_AND_TIME_H:
            if (!SE_ValidTimeMDHValue(&(value_ptr->value.md_h), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_MD_H_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DATE_Y:
            break;

        case SE_TIMECFG_DATE_M:
            if (!SE_ValidTimeMValue(&(value_ptr->value.month), print_error,
                      error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_M_Value value\n");
                }
            }
            break;

        case SE_TIMECFG_DAY_OF_YEAR:
            if (!SE_ValidTimeDayOfYearValue(&(value_ptr->value.day_of_year),
                      print_error, error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SE_Time_Day_Of_Year_Value"\
                           " value\n");
                }
            }
            break;

        default:
             result = SE_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SE_Time_Configuration value (%d)\n",
                         (int) value_ptr->configuration);
             break;
    } /* end switch */
    return result;
} /* end SE_ValidTimeValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDHValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYDHValue
(
    const SE_Time_YD_H_Value *value_ptr,
          SE_Boolean          print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYDHValue: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->day_of_year < 1) || (value_ptr->day_of_year > 366))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHValue: day_of_year"\
                    " out of range [1, 366]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHValue: hour"\
                    " > 23!\n");
    }
    return result;
} /* end SE_ValidTimeYDHValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDHMValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYDHMValue
(
    const SE_Time_YD_HM_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYDHMValue: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->day_of_year < 1) || (value_ptr->day_of_year > 366))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMValue: day_of_year"\
                    " out of range [1, 366]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMValue: hour"\
                    " > 23!\n");
    }
    if (value_ptr->minutes > 59)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMValue: minutes"\
                    " > 59!\n");
    }
    return result;
} /* end SE_ValidTimeYDHMValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDHMSValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYDHMSValue
(
    const SE_Time_YD_HMS_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYDHMSValue: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->day_of_year < 1) || (value_ptr->day_of_year > 366))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMSValue: day_of_year"\
                    " out of range [1, 366]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMSValue: hour"\
                    " > 23!\n");
    }
    if (value_ptr->minutes > 59)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMSValue: minutes"\
                    " > 59!\n");
    }
    if (value_ptr->seconds < 0.0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDHMSValue: seconds"\
                    " < 0.0!\n");
    }
    return result;
} /* end SE_ValidTimeYDHMSValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYDValue
(
    const SE_Time_YD_Value *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYDValue: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->day_of_year < 1) || (value_ptr->day_of_year > 366))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYDValue: day_of_year"\
                    " out of range [1, 366]!\n");
    }
    return result;
} /* end SE_ValidTimeYDValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDHValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYMDHValue
(
    const SE_Time_YMD_H_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYMDHValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHValue: day"\
                    " out of range [1, 31]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHValue: hour"\
                    " > 23!\n");
    }
    return result;
} /* end SE_ValidTimeYMDHValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDHMValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYMDHMValue
(
    const SE_Time_YMD_HM_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYMDHMValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMValue: day"\
                    " out of range [1, 31]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMValue: hour"\
                    " > 23!\n");
    }
    if (value_ptr->minutes > 59)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMValue: minutes"\
                    " > 59!\n");
    }
    return result;
} /* end SE_ValidTimeYMDHMValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDHMSValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYMDHMSValue
(
    const SE_Time_YMD_HMS_Value *value_ptr,
          SE_Boolean             print_error,
          SE_Integer_Unsigned   *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYMDHMSValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMSValue: day"\
                    " out of range [1, 31]!\n");
    }
    if (value_ptr->hour > 23)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMSValue: hour"\
                    " > 23!\n");
    }
    if (value_ptr->minutes > 59)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMSValue: minutes"\
                    " > 59!\n");
    }
    if (value_ptr->seconds < 0.0)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDHMSValue: seconds"\
                    " < 0.0!\n");
    }
    return result;
} /* end SE_ValidTimeYMDHMSValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDValue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTimeYMDValue
(
    const SE_Time_YMD_Value *value_ptr,
          SE_Boolean         print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidTimeYMDValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidMonth(value_ptr->month))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Month value (%d)\n", (int)
                value_ptr->month);
    }
    if ((value_ptr->day < 1) || (value_ptr->day > 31))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SE_ValidTimeYMDValue: day"\
                    " out of range [1, 31]!\n");
    }
    return result;
} /* end SE_ValidTimeYMDValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTypeClassification
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTypeClassification
(
    SE_Type_Classification value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_TYP_CLASSIF_BASIC:
        case SE_TYP_CLASSIF_ENUM:
        case SE_TYP_CLASSIF_REGISTERABLE_ENUM:
        case SE_TYP_CLASSIF_SET:
        case SE_TYP_CLASSIF_STRUCT:
        case SE_TYP_CLASSIF_FUNCTION:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidTypeClassification */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidUnderlineStyle
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidUnderlineStyle
(
    SE_Underline_Style value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ULSTYL_NONE:
        case SE_ULSTYL_SINGLE:
        case SE_ULSTYL_DOUBLE:
        case SE_ULSTYL_BOLD_SINGLE:
        case SE_ULSTYL_BOLD_DOUBLE:
        case SE_ULSTYL_DASHED:
        case SE_ULSTYL_DOTTED:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidUnderlineStyle */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidUnionReason
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidUnionReason
(
    SE_Union_Reason value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_UNIONREAS_CLASSIFIED_OBJECT:
        case SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS:
        case SE_UNIONREAS_OTHER:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidUnionReason */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidURL
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidURL
(
    const SE_URL *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidURL: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->characters && (value_ptr->length>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->characters for value_ptr->length"\
                   " == %u\n",(unsigned int) value_ptr->length);
        }
    }
    return result;
} /* end SE_ValidURL */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidURN
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidURN
(
    const SE_URN *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Short_Integer_Unsigned start_indx = 11;
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SE_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidURN: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->characters && (value_ptr->length>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->characters for value_ptr->length"\
                   " == %u\n",(unsigned int) value_ptr->length);
        }
    }
    else if (strlen(value_ptr->characters) !=
             (int)value_ptr->length)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidURN: length doesn't"\
                    " correspond to characters!\n");
        }
    }
    else if (strncmp(value_ptr->characters,"urn:sedris:", 11) == 0)
    {
        start_indx = 11;
    }
    else if (strncmp(value_ptr->characters,"urn:x-sedris:", 13) == 0)
    {
        start_indx = 13;
    }
    else
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidURN: not in SEDRIS namespace!\n");
        }
    }

    if (result)
    {
        SE_Short_Integer_Unsigned  i, colon_count = 0;
        SE_Boolean                 found_authority = SE_FALSE,
                                   found_name = SE_FALSE;

        for (i = start_indx; (i < value_ptr->length) && result; i++)
        {
            if (iscntrl(value_ptr->characters[i]) ||
                isspace(value_ptr->characters[i]))
            {
                result = SE_FALSE;
            }
            else if (value_ptr->characters[i] == ':')
            {
                colon_count++;
            }
            else if ((colon_count < 1) && !found_authority)
            {
                found_authority = SE_TRUE;
            }
            else if ((colon_count == 1) && !found_name)
            {
                found_name = SE_TRUE;
            }
        }
        if (!found_authority || !found_name)
            result = SE_FALSE;
    }
    return result;
} /* end SE_ValidURN */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVariableCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidVariableCode
(
    SE_Variable_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_VARCOD_ACTIVE_STATE_VALUE:
        case SE_VARCOD_CLR_COORDINATE_1:
        case SE_VARCOD_CLR_COORDINATE_2:
        case SE_VARCOD_CLR_COORDINATE_3:
        case SE_VARCOD_CLR_INDEX:
        case SE_VARCOD_CLR_INTENSITY_LEVEL:
        case SE_VARCOD_GEOMETRY_TEXTURE:
        case SE_VARCOD_HEAT_PRODUCTION:
        case SE_VARCOD_LIGHT_SOURCE_ACTIVE:
        case SE_VARCOD_LGT_RENDER_PROP_ACTIVE:
        case SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE:
        case SE_VARCOD_LSR_3D_LOCATION_U:
        case SE_VARCOD_LSR_3D_LOCATION_V:
        case SE_VARCOD_LSR_3D_LOCATION_W:
        case SE_VARCOD_POLY_FLAGS_COLLIDIBLE:
        case SE_VARCOD_POLY_FLAGS_HAT_TEST:
        case SE_VARCOD_POLY_FLAGS_INVISIBLE:
        case SE_VARCOD_POLY_FLAGS_LASER_RNG_FIND:
        case SE_VARCOD_PROPERTY_SET_INDEX:
        case SE_VARCOD_PROP_TABLE_REF_ON_AXIS:
        case SE_VARCOD_REF_VEC_V0:
        case SE_VARCOD_REF_VEC_V1:
        case SE_VARCOD_REF_VEC_V2:
        case SE_VARCOD_ROTATION_ANGLE:
        case SE_VARCOD_SCALE_AMOUNT:
        case SE_VARCOD_SOUND_INSTANCE_ACTIVE:
        case SE_VARCOD_TEXTURE_COORD_S:
        case SE_VARCOD_TEXTURE_COORD_T:
        case SE_VARCOD_TRANSLATION_AMOUNT:
        case SE_VARCOD_TRANSLUCENCY_VALUE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidVariableCode */
