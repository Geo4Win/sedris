/*
 * FILE       : edcs_valid_gen.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains validating functions for all EDCS types.
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
 *   in order to insure that a given variable has valid values.
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
 * - EDCS spec. 4.4
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
#include "edcs.h"




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidNonNullString
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidNonNullString
(
    const EDCS_String           *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE         *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!EDCS_ValidString(value_ptr, print_error, error_count_ptr))
    {
        result = EDCS_FALSE;
    }
    else if (!value_ptr->characters || !value_ptr->length)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"Missing required value_ptr->characters for"\
                   " value_ptr->length == %u\n",(unsigned int)
                    value_ptr->length);
        }
    }
    return result;
} /* end EDCS_ValidNonNullString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidAttributeValue
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidAttributeValue
(
          EDCS_Attribute_Code     attr_code,
    const EDCS_Attribute_Value *value_ptr,
          EDCS_Boolean          print_error,
          EDCS_Count           *error_count_ptr
)
{
    const EDCS_Attribute_Dictionary_Entry *entry_ptr = NULL;
    EDCS_Boolean  result = EDCS_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidAttributeValue: NULL value_ptr\n");
        }
        return result;
    }
    else if (EDCS_GetEADictionaryEntry(attr_code, &entry_ptr) !=
             EDCS_SC_SUCCESS)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidAttributeValue: invalid attr_code\n");
        }
        return result;
    }
    else if ((attr_code != EAC_NULL) &&
             (entry_ptr->value_type != value_ptr->attribute_value_type))
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidAttributeValue: value_type mismatch "\
                    "with attr_code's value_type\n");
        }
    }

    switch (value_ptr->attribute_value_type)
    {
        case EDCS_AVT_REAL:
            if (!EDCS_ValidLongFloatValue(&(value_ptr->value.real_value),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Value value\n");
                }
            }
            else if ((attr_code != EAC_NULL) &&
                     (entry_ptr->value_type == value_ptr->attribute_value_type))
            {
                const EDCS_Unit_Dictionary_Entry *unit_entry_ptr = NULL;

                if (EDCS_GetEUDictionaryEntry(value_ptr->value.real_value.unit,
                    &unit_entry_ptr) != EDCS_SC_SUCCESS)
                {
                    if (print_error)
                    {
                        fprintf(f_ptr, "EDCS_ValidAttributeValue: Corruption"\
                        " detected, EDCS_GetEUDictionaryEntry failed for valid EU\n");
                    }
                }
                else if (unit_entry_ptr->eq_code != entry_ptr->eq_class)
                {
                    result = EDCS_FALSE;
                    if (error_count_ptr)
                    {
                        (*error_count_ptr)++;
                    }
                    if (print_error)
                    {
                        fprintf(f_ptr, "EDCS_ValidAttributeValue: invalid "\
                        "unit for EA; belongs to %s rather than ",
                        EDCS_PrintUnitEquivalenceCode(unit_entry_ptr->eq_code));
                        fprintf(f_ptr, "%s\n",
                        EDCS_PrintUnitEquivalenceCode(entry_ptr->eq_class));
                    }
                }
            }
            break;

        case EDCS_AVT_INTEGER:
            if (!EDCS_ValidIntegerValue(&(value_ptr->value.integer_value),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Value value\n");
                }
            }
            break;

        case EDCS_AVT_COUNT:
            if (!EDCS_ValidCountValue(&(value_ptr->value.count_value),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Value value\n");
                }
            }
            break;

        case EDCS_AVT_INDEX:
            break;

        case EDCS_AVT_STRING:
            if (!EDCS_ValidString(&(value_ptr->value.string_value),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_String value\n");
                }
            }
            break;

        case EDCS_AVT_CONSTRAINED_STRING:
            if (!EDCS_ValidString(
                      &(value_ptr->value.constrained_string_value),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_String value\n");
                }
            }
            break;

        case EDCS_AVT_KEY:
            if (!EDCS_ValidString(&(value_ptr->value.key_value), print_error,
                      error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_String value\n");
                }
            }
            break;

        case EDCS_AVT_ENUMERATION:
            if (!EDCS_ValidEnumerantCode(attr_code,
               value_ptr->value.enumeration_value))
            {
                result = EDCS_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Enumerant_Code value (%d)\n",
                        (int) value_ptr->value.enumeration_value);
            }
            break;

        case EDCS_AVT_BOOLEAN:
            if (!EDCS_ValidBoolean(value_ptr->value.boolean_value))
            {
                result = EDCS_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Boolean value (%d)\n", (int)
                        value_ptr->value.boolean_value);
            }
            break;

        case EDCS_AVT_NULL:
            if (!EDCS_ValidNull(value_ptr->value.null_value))
            {
                result = EDCS_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal EDCS_Null value (%d)\n", (int)
                        value_ptr->value.null_value);
            }
            break;

        default:
             result = EDCS_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal EDCS_Attribute_Value_Type value"\
                         " (%d)\n", (int) value_ptr->attribute_value_type);
             break;
    } /* end switch */
    return result;
} /* end EDCS_ValidAttributeValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidAttributeValueType
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidAttributeValueType
(
    EDCS_Attribute_Value_Type value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_AVT_REAL:
        case EDCS_AVT_INTEGER:
        case EDCS_AVT_COUNT:
        case EDCS_AVT_INDEX:
        case EDCS_AVT_STRING:
        case EDCS_AVT_CONSTRAINED_STRING:
        case EDCS_AVT_KEY:
        case EDCS_AVT_ENUMERATION:
        case EDCS_AVT_BOOLEAN:
        case EDCS_AVT_NULL:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidAttributeValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidBoolean
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidBoolean
(
    EDCS_Boolean value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_FALSE:
        case EDCS_TRUE:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidBoolean */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidConceptStatus
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidConceptStatus
(
    EDCS_Concept_Status value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_CONCEPT_STAT_ISO:
        case EDCS_CONCEPT_STAT_DEPRECATED:
        case EDCS_CONCEPT_STAT_REGISTRY:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidConceptStatus */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidCountValue
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidCountValue
(
    const EDCS_Count_Value *value_ptr,
          EDCS_Boolean      print_error,
          EDCS_Count       *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidCountValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->numeric_value_type)
    {
        case EDCS_NVT_SINGLE_VALUE:
            break;

        case EDCS_NVT_OPEN_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.open_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GE_LT_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.ge_lt_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GT_LE_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.gt_le_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_CLOSED_INTERVAL:
            if (!EDCS_ValidCountInterval(&(value_ptr->value.closed_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Count_Interval value\n");
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
             result = EDCS_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal EDCS_Numeric_Value_Type value (%d)\n",
                         (int) value_ptr->numeric_value_type);
             break;
    } /* end switch */
    return result;
} /* end EDCS_ValidCountValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidDictionaryType
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidDictionaryType
(
    EDCS_Dictionary_Type value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_DT_CLASSIFICATION:
        case EDCS_DT_ATTRIBUTE:
        case EDCS_DT_ATTRIBUTE_VALUE_CHARACTERISTIC:
        case EDCS_DT_ATTRIBUTE_ENUMERANT:
        case EDCS_DT_UNIT:
        case EDCS_DT_UNIT_SCALE:
        case EDCS_DT_UNIT_EQUIVALENCE_CLASS:
        case EDCS_DT_ORGANIZATION_SCHEMA:
        case EDCS_DT_GROUP:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidDictionaryType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidIntegerValue
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidIntegerValue
(
    const EDCS_Integer_Value *value_ptr,
          EDCS_Boolean        print_error,
          EDCS_Count         *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidIntegerValue: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->numeric_value_type)
    {
        case EDCS_NVT_SINGLE_VALUE:
            break;

        case EDCS_NVT_OPEN_INTERVAL:
            if (!EDCS_ValidIntegerInterval(&(value_ptr->value.open_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GE_LT_INTERVAL:
            if (!EDCS_ValidIntegerInterval(&(value_ptr->value.ge_lt_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GT_LE_INTERVAL:
            if (!EDCS_ValidIntegerInterval(&(value_ptr->value.gt_le_interval),
                      print_error, error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_CLOSED_INTERVAL:
            if (!EDCS_ValidIntegerInterval(
                      &(value_ptr->value.closed_interval), print_error,
                      error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Integer_Interval value\n");
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
             result = EDCS_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal EDCS_Numeric_Value_Type value (%d)\n",
                         (int) value_ptr->numeric_value_type);
             break;
    } /* end switch */
    return result;
} /* end EDCS_ValidIntegerValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidLongFloatValue
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidLongFloatValue
(
    const EDCS_Long_Float_Value *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidLongFloatValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!EDCS_ValidUnitCode(value_ptr->unit))
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Code value (%d)\n", (int)
                value_ptr->unit);
    }
    if (!EDCS_ValidUnitScaleCode(value_ptr->unit_scale))
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Scale_Code value (%d)\n", (int)
                value_ptr->unit_scale);
    }
    switch (value_ptr->numeric_value_type)
    {
        case EDCS_NVT_SINGLE_VALUE:
            break;

        case EDCS_NVT_OPEN_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.open_interval), print_error,
                      error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GE_LT_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.ge_lt_interval), print_error,
                      error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_GT_LE_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.gt_le_interval), print_error,
                      error_count_ptr))
            {
                result = EDCS_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal EDCS_Long_Float_Interval value\n");
                }
            }
            break;

        case EDCS_NVT_CLOSED_INTERVAL:
            if (!EDCS_ValidLongFloatInterval(
                      &(value_ptr->value.closed_interval), print_error,
                      error_count_ptr))
            {
                result = EDCS_FALSE;
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
             result = EDCS_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal EDCS_Numeric_Value_Type value (%d)\n",
                         (int) value_ptr->numeric_value_type);
             break;
    } /* end switch */
    return result;
} /* end EDCS_ValidLongFloatValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidNull
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidNull
(
    EDCS_Null value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_NULL:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidNull */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidNumericValueType
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidNumericValueType
(
    EDCS_Numeric_Value_Type value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_NVT_SINGLE_VALUE:
        case EDCS_NVT_OPEN_INTERVAL:
        case EDCS_NVT_GE_LT_INTERVAL:
        case EDCS_NVT_GT_LE_INTERVAL:
        case EDCS_NVT_CLOSED_INTERVAL:
        case EDCS_NVT_GT_SEMI_INTERVAL:
        case EDCS_NVT_GE_SEMI_INTERVAL:
        case EDCS_NVT_LT_SEMI_INTERVAL:
        case EDCS_NVT_LE_SEMI_INTERVAL:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidNumericValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidRealValue
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidRealValue
(
    const EDCS_Real_Value *value_ptr,
          EDCS_Boolean     print_error,
          EDCS_Count      *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidRealValue: NULL value_ptr\n");
        }
        return result;
    }

    if (!EDCS_ValidUnitCode(value_ptr->unit))
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Code value (%d)\n", (int)
                value_ptr->unit);
    }
    if (!EDCS_ValidUnitScaleCode(value_ptr->unit_scale))
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal EDCS_Unit_Scale_Code value (%d)\n", (int)
                value_ptr->unit_scale);
    }
    return result;
} /* end EDCS_ValidRealValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidReferenceType
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidReferenceType
(
    EDCS_Reference_Type value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_REF_TYP_PRESCRIPTIVE:
        case EDCS_REF_TYP_AUTHORITATIVE:
        case EDCS_REF_TYP_INFORMATIVE:
        case EDCS_REF_TYP_NOT_APPLICABLE:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidReferenceType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidStatusCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidStatusCode
(
    EDCS_Status_Code value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT:
        case EDCS_SC_INVALID_INPUT_LABEL:
        case EDCS_SC_INVALID_INPUT_CODE:
        case EDCS_SC_NULL_REQUIRED_PARAMETER:
        case EDCS_SC_SUCCESS:
        case EDCS_SC_INVALID_INPUT_UNIT:
        case EDCS_SC_INVALID_OUTPUT_UNIT:
        case EDCS_SC_INVALID_INPUT_UNIT_SCALE:
        case EDCS_SC_INVALID_OUTPUT_UNIT_SCALE:
        case EDCS_SC_UNITS_NOT_EQUIVALENT:
        case EDCS_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE:
        case EDCS_SC_INVALID_INPUT_GROUP:
        case EDCS_SC_INVALID_INPUT_DICTIONARY:
        case EDCS_SC_OTHER_FAILURE:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidStatusCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidString
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidString
(
    const EDCS_String *value_ptr,
          EDCS_Boolean  print_error,
          EDCS_Count  *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidString: NULL value_ptr\n");
        }
        return result;
    }

    if (!EDCS_ValidLocale(&(value_ptr->locale), print_error, error_count_ptr))
    {
        result = EDCS_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal EDCS_Locale value\n");
        }
    }
    if (!value_ptr->characters && (value_ptr->length>0))
    {
        result = EDCS_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->characters for value_ptr->length"\
                   " == %u\n",(unsigned int) value_ptr->length);
        }
    }
    return result;
} /* end EDCS_ValidString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitStatus
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidUnitStatus
(
    EDCS_Unit_Status value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_UNIT_STAT_RECOMMENDED:
        case EDCS_UNIT_STAT_ACCEPTED:
        case EDCS_UNIT_STAT_DEPRECATED:
        case EDCS_UNIT_STAT_NOT_SI:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidUnitStatus */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidValueCharacteristicApplicability
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidValueCharacteristicApplicability
(
    EDCS_Value_Characteristic_Applicability value
)
{
    EDCS_Boolean result = EDCS_TRUE;

    switch (value)
    {
        case EDCS_ATTR_VAL_CHAR_APPLICABILITY_ALL:
        case EDCS_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC:
            break;

        default:
            result = EDCS_FALSE;
            break;
    } /* end switch */
    return result;
} /* end EDCS_ValidValueCharacteristicApplicability */
