/* EDCS API
 *
 * FILE       : edcs_print_gen.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains print functions for all EDCS types.
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
#include <string.h>
#include "edcs.h"
#include "edcs_print.h"


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_Indent
 *
 *    Indent the number of spaces appropriate for the given level.
 *
 * PARAMETERS:
 *
 *   level -- 1/2 the number of spaces to indent
 *
 *   out_file_ptr -- output file to which we're printing
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_Indent
(
    EDCS_Count  level,
    FILE       *out_file_ptr
)
{
    EDCS_Count i;

    for (i=1; i<level; i++)
        fprintf(out_file_ptr, "  ");
} /* end SE_Indent */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintAttributeDictionaryEntry
(
    const EDCS_Attribute_Dictionary_Entry *value_ptr,
    const char                            *name_ptr,
          EDCS_Count                       level
)
{
    char  buffer[1024];
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Attribute_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintAttributeCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr, EDCS_PrintAttributeLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->value_type: %s\n", name_ptr,
                EDCS_PrintAttributeValueType(value_ptr->value_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eq_class: %s\n", name_ptr,
                EDCS_PrintUnitEquivalenceCode(value_ptr->eq_class));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eg_count: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->eg_count));
        if ((value_ptr->eg_count > 0) && (value_ptr->eg_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eg_count; i++)
            {
                sprintf(buffer, "%s->eg_list[%u]", name_ptr, i);
                EDCS_PrintGroupPair(&(value_ptr->eg_list[i]), buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ee_count: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->ee_count));
        if ((value_ptr->ee_count > 0) && (value_ptr->ee_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->ee_count; i++)
            {
                sprintf(buffer, "%s->ee_list[%u]", name_ptr, i);
                EDCS_PrintEnumerantDictionaryEntry(&(value_ptr->ee_list[i]),
                   buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n", EDCS_PrintAttributeCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintAttributeLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "value_type: %s\n",
                EDCS_PrintAttributeValueType(value_ptr->value_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eq_class: %s\n",
                EDCS_PrintUnitEquivalenceCode(value_ptr->eq_class));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eg_count: %s\n", EDCS_PrintCount(value_ptr->eg_count));
        if ((value_ptr->eg_count > 0) && (value_ptr->eg_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eg_count; i++)
            {
                sprintf(buffer, "eg_list[%u]", i);
                EDCS_PrintGroupPair(&(value_ptr->eg_list[i]), buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ee_count: %s\n", EDCS_PrintCount(value_ptr->ee_count));
        if ((value_ptr->ee_count > 0) && (value_ptr->ee_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->ee_count; i++)
            {
                sprintf(buffer, "ee_list[%u]", i);
                EDCS_PrintEnumerantDictionaryEntry(&(value_ptr->ee_list[i]),
                   buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintAttributeDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintAttributeLabel
(
    EDCS_Attribute_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintAttributeLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeValue
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintAttributeValue
(
          EDCS_Attribute_Code     ea_code,
    const EDCS_Attribute_Value *value_ptr,
    const char                 *name_ptr,
          EDCS_Count            level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Attribute_Value\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->attribute_value_type: %s\n", name_ptr,
                EDCS_PrintAttributeValueType(value_ptr->attribute_value_type));
        switch (value_ptr->attribute_value_type)
        {
            case EDCS_AVT_REAL:
                sprintf(buffer, "%s->value.real_value", name_ptr);
                EDCS_PrintLongFloatValue(&(value_ptr->value.real_value),
                  buffer, level);
                break;

            case EDCS_AVT_INTEGER:
                sprintf(buffer, "%s->value.integer_value", name_ptr);
                EDCS_PrintIntegerValue(&(value_ptr->value.integer_value),
                  buffer, level);
                break;

            case EDCS_AVT_COUNT:
                sprintf(buffer, "%s->value.count_value", name_ptr);
                EDCS_PrintCountValue(&(value_ptr->value.count_value), buffer,
                  level);
                break;

            case EDCS_AVT_INDEX:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.index_value: %s\n", name_ptr,
                        EDCS_PrintInteger(value_ptr->value.index_value));
                break;

            case EDCS_AVT_STRING:
                sprintf(buffer, "%s->value.string_value", name_ptr);
                EDCS_PrintString(&(value_ptr->value.string_value), buffer,
                  level);
                break;

            case EDCS_AVT_CONSTRAINED_STRING:
                sprintf(buffer, "%s->value.constrained_string_value", name_ptr);
                EDCS_PrintString(&(value_ptr->value.constrained_string_value),
                  buffer, level);
                break;

            case EDCS_AVT_KEY:
                sprintf(buffer, "%s->value.key_value", name_ptr);
                EDCS_PrintString(&(value_ptr->value.key_value), buffer, level);
                break;

            case EDCS_AVT_ENUMERATION:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.enumeration_value: %s\n", name_ptr,
                        EDCS_PrintEnumerantCode(ea_code,
                        value_ptr->value.enumeration_value));
                break;

            case EDCS_AVT_BOOLEAN:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.boolean_value: %s\n", name_ptr,
                        EDCS_PrintBoolean(value_ptr->value.boolean_value));
                break;

            case EDCS_AVT_NULL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.null_value: %s\n", name_ptr,
                        EDCS_PrintNull(value_ptr->value.null_value));
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "attribute_value_type: %s\n",
                EDCS_PrintAttributeValueType(value_ptr->attribute_value_type));
        switch (value_ptr->attribute_value_type)
        {
            case EDCS_AVT_REAL:
                sprintf(buffer, "value.real_value");
                EDCS_PrintLongFloatValue(&(value_ptr->value.real_value),
                  buffer, level);
                break;

            case EDCS_AVT_INTEGER:
                sprintf(buffer, "value.integer_value");
                EDCS_PrintIntegerValue(&(value_ptr->value.integer_value),
                  buffer, level);
                break;

            case EDCS_AVT_COUNT:
                sprintf(buffer, "value.count_value");
                EDCS_PrintCountValue(&(value_ptr->value.count_value), buffer,
                  level);
                break;

            case EDCS_AVT_INDEX:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.index_value: %s\n", EDCS_PrintInteger
                        (value_ptr->value.index_value));
                break;

            case EDCS_AVT_STRING:
                sprintf(buffer, "value.string_value");
                EDCS_PrintString(&(value_ptr->value.string_value), buffer,
                  level);
                break;

            case EDCS_AVT_CONSTRAINED_STRING:
                sprintf(buffer, "value.constrained_string_value");
                EDCS_PrintString(&(value_ptr->value.constrained_string_value),
                  buffer, level);
                break;

            case EDCS_AVT_KEY:
                sprintf(buffer, "value.key_value");
                EDCS_PrintString(&(value_ptr->value.key_value), buffer, level);
                break;

            case EDCS_AVT_ENUMERATION:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.enumeration_value: %s\n",
                        EDCS_PrintEnumerantCode(ea_code,
                        value_ptr->value.enumeration_value));
                break;

            case EDCS_AVT_BOOLEAN:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.boolean_value: %s\n",
                        EDCS_PrintBoolean(value_ptr->value.boolean_value));
                break;

            case EDCS_AVT_NULL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.null_value: %s\n",
                        EDCS_PrintNull(value_ptr->value.null_value));
                break;

        } /* end switch */
    }
} /* end EDCS_PrintAttributeValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeValueType
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintAttributeValueType
(
    EDCS_Attribute_Value_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_AVT_REAL:
             return "EDCS_AVT_REAL";

        case EDCS_AVT_INTEGER:
             return "EDCS_AVT_INTEGER";

        case EDCS_AVT_COUNT:
             return "EDCS_AVT_COUNT";

        case EDCS_AVT_INDEX:
             return "EDCS_AVT_INDEX";

        case EDCS_AVT_STRING:
             return "EDCS_AVT_STRING";

        case EDCS_AVT_CONSTRAINED_STRING:
             return "EDCS_AVT_CONSTRAINED_STRING";

        case EDCS_AVT_KEY:
             return "EDCS_AVT_KEY";

        case EDCS_AVT_ENUMERATION:
             return "EDCS_AVT_ENUMERATION";

        case EDCS_AVT_BOOLEAN:
             return "EDCS_AVT_BOOLEAN";

        case EDCS_AVT_NULL:
             return "EDCS_AVT_NULL";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Attribute_Value_Type VALUE"\
                    " (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintAttributeValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintBoolean
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintBoolean
(
    EDCS_Boolean value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_FALSE:
             return "EDCS_FALSE";

        case EDCS_TRUE:
             return "EDCS_TRUE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Boolean VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintBoolean */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCharacter
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintCharacter
(
    EDCS_Character value
)
{
    static char buffer[10];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%c", value);
    return buffer;
} /* end EDCS_PrintCharacter */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintClassificationDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintClassificationDictionaryEntry
(
    const EDCS_Classification_Dictionary_Entry *value_ptr,
    const char                                 *name_ptr,
          EDCS_Count                            level
)
{
    char  buffer[1024];
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "EDCS_Classification_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintClassificationCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr,
                EDCS_PrintClassificationLabel(value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eg_count: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->eg_count));
        if ((value_ptr->eg_count > 0) && (value_ptr->eg_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eg_count; i++)
            {
                sprintf(buffer, "%s->eg_list[%u]", name_ptr, i);
                EDCS_PrintGroupPair(&(value_ptr->eg_list[i]), buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n",
                EDCS_PrintClassificationCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintClassificationLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eg_count: %s\n", EDCS_PrintCount(value_ptr->eg_count));
        if ((value_ptr->eg_count > 0) && (value_ptr->eg_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eg_count; i++)
            {
                sprintf(buffer, "eg_list[%u]", i);
                EDCS_PrintGroupPair(&(value_ptr->eg_list[i]), buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintClassificationDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintClassificationLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintClassificationLabel
(
    EDCS_Classification_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintClassificationLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintConceptStatus
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintConceptStatus
(
    EDCS_Concept_Status value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_CONCEPT_STAT_ISO:
             return "EDCS_CONCEPT_STAT_ISO";

        case EDCS_CONCEPT_STAT_DEPRECATED:
             return "EDCS_CONCEPT_STAT_DEPRECATED";

        case EDCS_CONCEPT_STAT_REGISTRY:
             return "EDCS_CONCEPT_STAT_REGISTRY";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Concept_Status VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintConceptStatus */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCount
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintCount
(
    EDCS_Count value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%u", (unsigned int) value);
    return buffer;
} /* end EDCS_PrintCount */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCountInterval
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintCountInterval
(
    const EDCS_Count_Interval *value_ptr,
    const char                *name_ptr,
          EDCS_Count           level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Count_Interval\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lower_bound: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->lower_bound));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->upper_bound: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->upper_bound));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lower_bound: %s\n", EDCS_PrintCount
                (value_ptr->lower_bound));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "upper_bound: %s\n", EDCS_PrintCount
                (value_ptr->upper_bound));
    }
} /* end EDCS_PrintCountInterval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCountValue
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintCountValue
(
    const EDCS_Count_Value *value_ptr,
    const char             *name_ptr,
          EDCS_Count        level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Count_Value\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->numeric_value_type: %s\n", name_ptr,
                EDCS_PrintNumericValueType(value_ptr->numeric_value_type));
        switch (value_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.single_value: %s\n", name_ptr,
                        EDCS_PrintCount(value_ptr->value.single_value));
                break;

            case EDCS_NVT_OPEN_INTERVAL:
                sprintf(buffer, "%s->value.open_interval", name_ptr);
                EDCS_PrintCountInterval(&(value_ptr->value.open_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GE_LT_INTERVAL:
                sprintf(buffer, "%s->value.ge_lt_interval", name_ptr);
                EDCS_PrintCountInterval(&(value_ptr->value.ge_lt_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_LE_INTERVAL:
                sprintf(buffer, "%s->value.gt_le_interval", name_ptr);
                EDCS_PrintCountInterval(&(value_ptr->value.gt_le_interval),
                  buffer, level);
                break;

            case EDCS_NVT_CLOSED_INTERVAL:
                sprintf(buffer, "%s->value.closed_interval", name_ptr);
                EDCS_PrintCountInterval(&(value_ptr->value.closed_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.gt_semi_interval: %s\n", name_ptr,
                        EDCS_PrintCount(value_ptr->value.gt_semi_interval));
                break;

            case EDCS_NVT_GE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.ge_semi_interval: %s\n", name_ptr,
                        EDCS_PrintCount(value_ptr->value.ge_semi_interval));
                break;

            case EDCS_NVT_LT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.lt_semi_interval: %s\n", name_ptr,
                        EDCS_PrintCount(value_ptr->value.lt_semi_interval));
                break;

            case EDCS_NVT_LE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.le_semi_interval: %s\n", name_ptr,
                        EDCS_PrintCount(value_ptr->value.le_semi_interval));
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "numeric_value_type: %s\n",
                EDCS_PrintNumericValueType(value_ptr->numeric_value_type));
        switch (value_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.single_value: %s\n", EDCS_PrintCount
                        (value_ptr->value.single_value));
                break;

            case EDCS_NVT_OPEN_INTERVAL:
                sprintf(buffer, "value.open_interval");
                EDCS_PrintCountInterval(&(value_ptr->value.open_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GE_LT_INTERVAL:
                sprintf(buffer, "value.ge_lt_interval");
                EDCS_PrintCountInterval(&(value_ptr->value.ge_lt_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_LE_INTERVAL:
                sprintf(buffer, "value.gt_le_interval");
                EDCS_PrintCountInterval(&(value_ptr->value.gt_le_interval),
                  buffer, level);
                break;

            case EDCS_NVT_CLOSED_INTERVAL:
                sprintf(buffer, "value.closed_interval");
                EDCS_PrintCountInterval(&(value_ptr->value.closed_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.gt_semi_interval: %s\n", EDCS_PrintCount
                        (value_ptr->value.gt_semi_interval));
                break;

            case EDCS_NVT_GE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.ge_semi_interval: %s\n", EDCS_PrintCount
                        (value_ptr->value.ge_semi_interval));
                break;

            case EDCS_NVT_LT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.lt_semi_interval: %s\n", EDCS_PrintCount
                        (value_ptr->value.lt_semi_interval));
                break;

            case EDCS_NVT_LE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.le_semi_interval: %s\n", EDCS_PrintCount
                        (value_ptr->value.le_semi_interval));
                break;

        } /* end switch */
    }
} /* end EDCS_PrintCountValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintDictionaryType
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintDictionaryType
(
    EDCS_Dictionary_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_DT_CLASSIFICATION:
             return "EDCS_DT_CLASSIFICATION";

        case EDCS_DT_ATTRIBUTE:
             return "EDCS_DT_ATTRIBUTE";

        case EDCS_DT_ATTRIBUTE_VALUE_CHARACTERISTIC:
             return "EDCS_DT_ATTRIBUTE_VALUE_CHARACTERISTIC";

        case EDCS_DT_ATTRIBUTE_ENUMERANT:
             return "EDCS_DT_ATTRIBUTE_ENUMERANT";

        case EDCS_DT_UNIT:
             return "EDCS_DT_UNIT";

        case EDCS_DT_UNIT_SCALE:
             return "EDCS_DT_UNIT_SCALE";

        case EDCS_DT_UNIT_EQUIVALENCE_CLASS:
             return "EDCS_DT_UNIT_EQUIVALENCE_CLASS";

        case EDCS_DT_ORGANIZATION_SCHEMA:
             return "EDCS_DT_ORGANIZATION_SCHEMA";

        case EDCS_DT_GROUP:
             return "EDCS_DT_GROUP";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Dictionary_Type VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintDictionaryType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintEnumerantDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintEnumerantDictionaryEntry
(
    const EDCS_Enumerant_Dictionary_Entry *value_ptr,
    const char                            *name_ptr,
          EDCS_Count                       level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Enumerant_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ea_code: %s\n", name_ptr,
                EDCS_PrintAttributeCode(value_ptr->ea_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ee_code: %s\n", name_ptr,
                EDCS_PrintEnumerantCode(value_ptr->ea_code,
                value_ptr->ee_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr, EDCS_PrintEnumerantLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ea_code: %s\n",
                EDCS_PrintAttributeCode(value_ptr->ea_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ee_code: %s\n",
                EDCS_PrintEnumerantCode(value_ptr->ea_code,
                value_ptr->ee_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintEnumerantLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintEnumerantDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintEnumerantLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintEnumerantLabel
(
    EDCS_Enumerant_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintEnumerantLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintGroupDictionaryEntry
(
    const EDCS_Group_Dictionary_Entry *value_ptr,
    const char                        *name_ptr,
          EDCS_Count                   level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Group_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eo_code: %s\n", name_ptr,
                EDCS_PrintOrganizationSchemaCode(value_ptr->eo_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eg_code: %s\n", name_ptr,
                EDCS_PrintGroupCode(value_ptr->eo_code, value_ptr->eg_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr, EDCS_PrintGroupLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eo_code: %s\n",
                EDCS_PrintOrganizationSchemaCode(value_ptr->eo_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eg_code: %s\n",
                EDCS_PrintGroupCode(value_ptr->eo_code, value_ptr->eg_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintGroupLabel(value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintGroupDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintGroupLabel
(
    EDCS_Group_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintGroupLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupPair
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintGroupPair
(
    const EDCS_Group_Pair *value_ptr,
    const char            *name_ptr,
          EDCS_Count       level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Group_Pair\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eg_code: %s\n", name_ptr,
                EDCS_PrintGroupCode(value_ptr->eo_code, value_ptr->eg_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eo_code: %s\n", name_ptr,
                EDCS_PrintOrganizationSchemaCode(value_ptr->eo_code));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eg_code: %s\n",
                EDCS_PrintGroupCode(value_ptr->eo_code, value_ptr->eg_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eo_code: %s\n",
                EDCS_PrintOrganizationSchemaCode(value_ptr->eo_code));
    }
} /* end EDCS_PrintGroupPair */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintInteger
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintInteger
(
    EDCS_Integer value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%i", (int) value);
    return buffer;
} /* end EDCS_PrintInteger */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintIntegerInterval
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintIntegerInterval
(
    const EDCS_Integer_Interval *value_ptr,
    const char                  *name_ptr,
          EDCS_Count             level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Integer_Interval\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lower_bound: %s\n", name_ptr, EDCS_PrintInteger
                (value_ptr->lower_bound));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->upper_bound: %s\n", name_ptr, EDCS_PrintInteger
                (value_ptr->upper_bound));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lower_bound: %s\n", EDCS_PrintInteger
                (value_ptr->lower_bound));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "upper_bound: %s\n", EDCS_PrintInteger
                (value_ptr->upper_bound));
    }
} /* end EDCS_PrintIntegerInterval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintIntegerValue
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintIntegerValue
(
    const EDCS_Integer_Value *value_ptr,
    const char               *name_ptr,
          EDCS_Count          level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Integer_Value\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->numeric_value_type: %s\n", name_ptr,
                EDCS_PrintNumericValueType(value_ptr->numeric_value_type));
        switch (value_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.single_value: %s\n", name_ptr,
                        EDCS_PrintInteger(value_ptr->value.single_value));
                break;

            case EDCS_NVT_OPEN_INTERVAL:
                sprintf(buffer, "%s->value.open_interval", name_ptr);
                EDCS_PrintIntegerInterval(&(value_ptr->value.open_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GE_LT_INTERVAL:
                sprintf(buffer, "%s->value.ge_lt_interval", name_ptr);
                EDCS_PrintIntegerInterval(&(value_ptr->value.ge_lt_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_LE_INTERVAL:
                sprintf(buffer, "%s->value.gt_le_interval", name_ptr);
                EDCS_PrintIntegerInterval(&(value_ptr->value.gt_le_interval),
                  buffer, level);
                break;

            case EDCS_NVT_CLOSED_INTERVAL:
                sprintf(buffer, "%s->value.closed_interval", name_ptr);
                EDCS_PrintIntegerInterval(&(value_ptr->value.closed_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.gt_semi_interval: %s\n", name_ptr,
                        EDCS_PrintInteger(value_ptr->value.gt_semi_interval));
                break;

            case EDCS_NVT_GE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.ge_semi_interval: %s\n", name_ptr,
                        EDCS_PrintInteger(value_ptr->value.ge_semi_interval));
                break;

            case EDCS_NVT_LT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.lt_semi_interval: %s\n", name_ptr,
                        EDCS_PrintInteger(value_ptr->value.lt_semi_interval));
                break;

            case EDCS_NVT_LE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.le_semi_interval: %s\n", name_ptr,
                        EDCS_PrintInteger(value_ptr->value.le_semi_interval));
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "numeric_value_type: %s\n",
                EDCS_PrintNumericValueType(value_ptr->numeric_value_type));
        switch (value_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.single_value: %s\n", EDCS_PrintInteger
                        (value_ptr->value.single_value));
                break;

            case EDCS_NVT_OPEN_INTERVAL:
                sprintf(buffer, "value.open_interval");
                EDCS_PrintIntegerInterval(&(value_ptr->value.open_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GE_LT_INTERVAL:
                sprintf(buffer, "value.ge_lt_interval");
                EDCS_PrintIntegerInterval(&(value_ptr->value.ge_lt_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_LE_INTERVAL:
                sprintf(buffer, "value.gt_le_interval");
                EDCS_PrintIntegerInterval(&(value_ptr->value.gt_le_interval),
                  buffer, level);
                break;

            case EDCS_NVT_CLOSED_INTERVAL:
                sprintf(buffer, "value.closed_interval");
                EDCS_PrintIntegerInterval(&(value_ptr->value.closed_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.gt_semi_interval: %s\n",
                        EDCS_PrintInteger(value_ptr->value.gt_semi_interval));
                break;

            case EDCS_NVT_GE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.ge_semi_interval: %s\n",
                        EDCS_PrintInteger(value_ptr->value.ge_semi_interval));
                break;

            case EDCS_NVT_LT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.lt_semi_interval: %s\n",
                        EDCS_PrintInteger(value_ptr->value.lt_semi_interval));
                break;

            case EDCS_NVT_LE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.le_semi_interval: %s\n",
                        EDCS_PrintInteger(value_ptr->value.le_semi_interval));
                break;

        } /* end switch */
    }
} /* end EDCS_PrintIntegerValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintISO3166Entry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintISO3166Entry
(
    const EDCS_ISO_3166_Entry *value_ptr,
    const char                *name_ptr,
          EDCS_Count           level
)
{
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_ISO_3166_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->country_A3[0..2]: ", name_ptr);
        for (i = 0; i < 3; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->country_A3[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->country_A2[0..1]: ", name_ptr);
        for (i = 0; i < 2; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->country_A2[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->country_name:", name_ptr);
        if (value_ptr->country_name != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->country_name);
        }
        fprintf(f_ptr, "\n");
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "country_A3[0..2]: ");
        for (i = 0; i < 3; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->country_A3[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "country_A2[0..1]: ");
        for (i = 0; i < 2; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->country_A2[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "country_name:");
        if (value_ptr->country_name != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->country_name);
        }
        fprintf(f_ptr, "\n");
    }
} /* end EDCS_PrintISO3166Entry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintISO639Entry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintISO639Entry
(
    const EDCS_ISO_639_Entry *value_ptr,
    const char               *name_ptr,
          EDCS_Count          level
)
{
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_ISO_639_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->language_A2[0..1]: ", name_ptr);
        for (i = 0; i < 2; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->language_A2[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->language_name:", name_ptr);
        if (value_ptr->language_name != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->language_name);
        }
        fprintf(f_ptr, "\n");
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "language_A2[0..1]: ");
        for (i = 0; i < 2; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->language_A2[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "language_name:");
        if (value_ptr->language_name != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->language_name);
        }
        fprintf(f_ptr, "\n");
    }
} /* end EDCS_PrintISO639Entry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLocale
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintLocale
(
    const EDCS_Locale *value_ptr,
    const char        *name_ptr,
          EDCS_Count   level
)
{
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Locale\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->language[0..1]: ", name_ptr);
        for (i = 0; i < 2; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->language[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->country[0..2]: ", name_ptr);
        for (i = 0; i < 3; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->country[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "language[0..1]: ");
        for (i = 0; i < 2; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->language[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "country[0..2]: ");
        for (i = 0; i < 3; i++)
        {
            fprintf(f_ptr, "%c", value_ptr->country[i]);
        } /* end for i */
        fprintf(f_ptr, "\n");
    }
} /* end EDCS_PrintLocale */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLongFloat
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintLongFloat
(
    EDCS_Long_Float value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%*.*f",(int)EDCS_GetMinWidth(), (int)EDCS_GetPrecision(), (double)value);
    return buffer;
} /* end EDCS_PrintLongFloat */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLongFloatInterval
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintLongFloatInterval
(
    const EDCS_Long_Float_Interval *value_ptr,
    const char                     *name_ptr,
          EDCS_Count                level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Long_Float_Interval\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lower_bound: %s\n", name_ptr, EDCS_PrintLongFloat
                (value_ptr->lower_bound));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->upper_bound: %s\n", name_ptr, EDCS_PrintLongFloat
                (value_ptr->upper_bound));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lower_bound: %s\n", EDCS_PrintLongFloat
                (value_ptr->lower_bound));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "upper_bound: %s\n", EDCS_PrintLongFloat
                (value_ptr->upper_bound));
    }
} /* end EDCS_PrintLongFloatInterval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLongFloatValue
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintLongFloatValue
(
    const EDCS_Long_Float_Value *value_ptr,
    const char                  *name_ptr,
          EDCS_Count             level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Long_Float_Value\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->numeric_value_type: %s\n", name_ptr,
                EDCS_PrintNumericValueType(value_ptr->numeric_value_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->unit: %s\n", name_ptr,
                EDCS_PrintUnitCode(value_ptr->unit));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->unit_scale: %s\n", name_ptr,
                EDCS_PrintUnitScaleCode(value_ptr->unit_scale));
        switch (value_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.single_value: %s\n", name_ptr,
                        EDCS_PrintLongFloat(value_ptr->value.single_value));
                break;

            case EDCS_NVT_OPEN_INTERVAL:
                sprintf(buffer, "%s->value.open_interval", name_ptr);
                EDCS_PrintLongFloatInterval(&(value_ptr->value.open_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GE_LT_INTERVAL:
                sprintf(buffer, "%s->value.ge_lt_interval", name_ptr);
                EDCS_PrintLongFloatInterval(&(value_ptr->value.ge_lt_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_LE_INTERVAL:
                sprintf(buffer, "%s->value.gt_le_interval", name_ptr);
                EDCS_PrintLongFloatInterval(&(value_ptr->value.gt_le_interval),
                  buffer, level);
                break;

            case EDCS_NVT_CLOSED_INTERVAL:
                sprintf(buffer, "%s->value.closed_interval", name_ptr);
                EDCS_PrintLongFloatInterval(&(value_ptr->value.closed_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.gt_semi_interval: %s\n", name_ptr,
                        EDCS_PrintLongFloat
                        (value_ptr->value.gt_semi_interval));
                break;

            case EDCS_NVT_GE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.ge_semi_interval: %s\n", name_ptr,
                        EDCS_PrintLongFloat
                        (value_ptr->value.ge_semi_interval));
                break;

            case EDCS_NVT_LT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.lt_semi_interval: %s\n", name_ptr,
                        EDCS_PrintLongFloat
                        (value_ptr->value.lt_semi_interval));
                break;

            case EDCS_NVT_LE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.le_semi_interval: %s\n", name_ptr,
                        EDCS_PrintLongFloat
                        (value_ptr->value.le_semi_interval));
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "numeric_value_type: %s\n",
                EDCS_PrintNumericValueType(value_ptr->numeric_value_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "unit: %s\n", EDCS_PrintUnitCode(value_ptr->unit));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "unit_scale: %s\n",
                EDCS_PrintUnitScaleCode(value_ptr->unit_scale));
        switch (value_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.single_value: %s\n", EDCS_PrintLongFloat
                        (value_ptr->value.single_value));
                break;

            case EDCS_NVT_OPEN_INTERVAL:
                sprintf(buffer, "value.open_interval");
                EDCS_PrintLongFloatInterval(&(value_ptr->value.open_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GE_LT_INTERVAL:
                sprintf(buffer, "value.ge_lt_interval");
                EDCS_PrintLongFloatInterval(&(value_ptr->value.ge_lt_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_LE_INTERVAL:
                sprintf(buffer, "value.gt_le_interval");
                EDCS_PrintLongFloatInterval(&(value_ptr->value.gt_le_interval),
                  buffer, level);
                break;

            case EDCS_NVT_CLOSED_INTERVAL:
                sprintf(buffer, "value.closed_interval");
                EDCS_PrintLongFloatInterval(&(value_ptr->value.closed_interval),
                  buffer, level);
                break;

            case EDCS_NVT_GT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.gt_semi_interval: %s\n",
                        EDCS_PrintLongFloat
                        (value_ptr->value.gt_semi_interval));
                break;

            case EDCS_NVT_GE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.ge_semi_interval: %s\n",
                        EDCS_PrintLongFloat
                        (value_ptr->value.ge_semi_interval));
                break;

            case EDCS_NVT_LT_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.lt_semi_interval: %s\n",
                        EDCS_PrintLongFloat
                        (value_ptr->value.lt_semi_interval));
                break;

            case EDCS_NVT_LE_SEMI_INTERVAL:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.le_semi_interval: %s\n",
                        EDCS_PrintLongFloat
                        (value_ptr->value.le_semi_interval));
                break;

        } /* end switch */
    }
} /* end EDCS_PrintLongFloatValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintNull
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintNull
(
    EDCS_Null value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_NULL:
             return "EDCS_NULL";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Null VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintNull */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintNumericValueType
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintNumericValueType
(
    EDCS_Numeric_Value_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_NVT_SINGLE_VALUE:
             return "EDCS_NVT_SINGLE_VALUE";

        case EDCS_NVT_OPEN_INTERVAL:
             return "EDCS_NVT_OPEN_INTERVAL";

        case EDCS_NVT_GE_LT_INTERVAL:
             return "EDCS_NVT_GE_LT_INTERVAL";

        case EDCS_NVT_GT_LE_INTERVAL:
             return "EDCS_NVT_GT_LE_INTERVAL";

        case EDCS_NVT_CLOSED_INTERVAL:
             return "EDCS_NVT_CLOSED_INTERVAL";

        case EDCS_NVT_GT_SEMI_INTERVAL:
             return "EDCS_NVT_GT_SEMI_INTERVAL";

        case EDCS_NVT_GE_SEMI_INTERVAL:
             return "EDCS_NVT_GE_SEMI_INTERVAL";

        case EDCS_NVT_LT_SEMI_INTERVAL:
             return "EDCS_NVT_LT_SEMI_INTERVAL";

        case EDCS_NVT_LE_SEMI_INTERVAL:
             return "EDCS_NVT_LE_SEMI_INTERVAL";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Numeric_Value_Type VALUE"\
                    " (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintNumericValueType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintOrganizationSchemaDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintOrganizationSchemaDictionaryEntry
(
    const EDCS_Organization_Schema_Dictionary_Entry *value_ptr,
    const char                                      *name_ptr,
          EDCS_Count                                 level
)
{
    char  buffer[1024];
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "EDCS_Organization_Schema_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintOrganizationSchemaCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr,
                EDCS_PrintOrganizationSchemaLabel(value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eg_count: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->eg_count));
        if ((value_ptr->eg_count > 0) && (value_ptr->eg_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eg_count; i++)
            {
                sprintf(buffer, "%s->eg_list[%u]", name_ptr, i);
                EDCS_PrintGroupDictionaryEntry(&(value_ptr->eg_list[i]),
                   buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n",
                EDCS_PrintOrganizationSchemaCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintOrganizationSchemaLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eg_count: %s\n", EDCS_PrintCount(value_ptr->eg_count));
        if ((value_ptr->eg_count > 0) && (value_ptr->eg_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eg_count; i++)
            {
                sprintf(buffer, "eg_list[%u]", i);
                EDCS_PrintGroupDictionaryEntry(&(value_ptr->eg_list[i]),
                   buffer, level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintOrganizationSchemaDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintOrganizationSchemaLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintOrganizationSchemaLabel
(
    EDCS_Organization_Schema_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintOrganizationSchemaLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintRealValue
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintRealValue
(
    const EDCS_Real_Value *value_ptr,
    const char            *name_ptr,
          EDCS_Count       level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Real_Value\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->unit: %s\n", name_ptr,
                EDCS_PrintUnitCode(value_ptr->unit));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->unit_scale: %s\n", name_ptr,
                EDCS_PrintUnitScaleCode(value_ptr->unit_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->value: %s\n", name_ptr, EDCS_PrintLongFloat
                (value_ptr->value));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "unit: %s\n", EDCS_PrintUnitCode(value_ptr->unit));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "unit_scale: %s\n",
                EDCS_PrintUnitScaleCode(value_ptr->unit_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "value: %s\n", EDCS_PrintLongFloat(value_ptr->value));
    }
} /* end EDCS_PrintRealValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintReferenceType
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintReferenceType
(
    EDCS_Reference_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_REF_TYP_PRESCRIPTIVE:
             return "EDCS_REF_TYP_PRESCRIPTIVE";

        case EDCS_REF_TYP_AUTHORITATIVE:
             return "EDCS_REF_TYP_AUTHORITATIVE";

        case EDCS_REF_TYP_INFORMATIVE:
             return "EDCS_REF_TYP_INFORMATIVE";

        case EDCS_REF_TYP_NOT_APPLICABLE:
             return "EDCS_REF_TYP_NOT_APPLICABLE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Reference_Type VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintReferenceType */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintStatusCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintStatusCode
(
    EDCS_Status_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT:
             return "EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT";

        case EDCS_SC_INVALID_INPUT_LABEL:
             return "EDCS_SC_INVALID_INPUT_LABEL";

        case EDCS_SC_INVALID_INPUT_CODE:
             return "EDCS_SC_INVALID_INPUT_CODE";

        case EDCS_SC_NULL_REQUIRED_PARAMETER:
             return "EDCS_SC_NULL_REQUIRED_PARAMETER";

        case EDCS_SC_SUCCESS:
             return "EDCS_SC_SUCCESS";

        case EDCS_SC_INVALID_INPUT_UNIT:
             return "EDCS_SC_INVALID_INPUT_UNIT";

        case EDCS_SC_INVALID_OUTPUT_UNIT:
             return "EDCS_SC_INVALID_OUTPUT_UNIT";

        case EDCS_SC_INVALID_INPUT_UNIT_SCALE:
             return "EDCS_SC_INVALID_INPUT_UNIT_SCALE";

        case EDCS_SC_INVALID_OUTPUT_UNIT_SCALE:
             return "EDCS_SC_INVALID_OUTPUT_UNIT_SCALE";

        case EDCS_SC_UNITS_NOT_EQUIVALENT:
             return "EDCS_SC_UNITS_NOT_EQUIVALENT";

        case EDCS_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE:
             return "EDCS_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE";

        case EDCS_SC_INVALID_INPUT_GROUP:
             return "EDCS_SC_INVALID_INPUT_GROUP";

        case EDCS_SC_INVALID_INPUT_DICTIONARY:
             return "EDCS_SC_INVALID_INPUT_DICTIONARY";

        case EDCS_SC_OTHER_FAILURE:
             return "EDCS_SC_OTHER_FAILURE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Status_Code VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintStatusCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintString
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintString
(
    const EDCS_String *value_ptr,
    const char        *name_ptr,
          EDCS_Count   level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_String\n");
        return;
    }
    if (name_ptr)
    {
        sprintf(buffer, "%s->locale", name_ptr);
        EDCS_PrintLocale(&(value_ptr->locale), buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->length: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->length));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->characters:", name_ptr);
        if (value_ptr->characters != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->characters);
        }
        fprintf(f_ptr, "\n");
    }
    else
    {
        sprintf(buffer, "locale");
        EDCS_PrintLocale(&(value_ptr->locale), buffer, level);
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "length: %s\n", EDCS_PrintCount(value_ptr->length));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "characters:");
        if (value_ptr->characters != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->characters);
        }
        fprintf(f_ptr, "\n");
    }
} /* end EDCS_PrintString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitConcept
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintUnitConcept
(
    const EDCS_Unit_Concept *value_ptr,
    const char              *name_ptr,
          EDCS_Count         level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Unit_Concept\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->quantity:", name_ptr);
        if (value_ptr->quantity != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->quantity);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "quantity:");
        if (value_ptr->quantity != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->quantity);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
    }
} /* end EDCS_PrintUnitConcept */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintUnitDictionaryEntry
(
    const EDCS_Unit_Dictionary_Entry *value_ptr,
    const char                       *name_ptr,
          EDCS_Count                  level
)
{
    char  buffer[1024];
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Unit_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintUnitCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr, EDCS_PrintUnitLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eq_code: %s\n", name_ptr,
                EDCS_PrintUnitEquivalenceCode(value_ptr->eq_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->unit_status: %s\n", name_ptr,
                EDCS_PrintUnitStatus(value_ptr->unit_status));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbol:", name_ptr);
        if (value_ptr->symbol != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbol);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_count: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->concept_count));
        if ((value_ptr->concept_count > 0) && (value_ptr->concept_list !=
            NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->concept_count; i++)
            {
                sprintf(buffer, "%s->concept_list[%u]", name_ptr, i);
                EDCS_PrintUnitConcept(&(value_ptr->concept_list[i]), buffer,
                   level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n", EDCS_PrintUnitCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintUnitLabel(value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eq_code: %s\n",
                EDCS_PrintUnitEquivalenceCode(value_ptr->eq_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "unit_status: %s\n",
                EDCS_PrintUnitStatus(value_ptr->unit_status));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbol:");
        if (value_ptr->symbol != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbol);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_count: %s\n", EDCS_PrintCount
                (value_ptr->concept_count));
        if ((value_ptr->concept_count > 0) && (value_ptr->concept_list !=
            NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->concept_count; i++)
            {
                sprintf(buffer, "concept_list[%u]", i);
                EDCS_PrintUnitConcept(&(value_ptr->concept_list[i]), buffer,
                   level);
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintUnitDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitEquivalenceDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintUnitEquivalenceDictionaryEntry
(
    const EDCS_Unit_Equivalence_Dictionary_Entry *value_ptr,
    const char                                   *name_ptr,
          EDCS_Count                              level
)
{
    FILE *f_ptr;
    EDCS_Count i;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "EDCS_Unit_Equivalence_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintUnitEquivalenceCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr,
                EDCS_PrintUnitEquivalenceLabel(value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->eu_count: %s\n", name_ptr, EDCS_PrintCount
                (value_ptr->eu_count));
        if ((value_ptr->eu_count > 0) && (value_ptr->eu_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eu_count; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->eu_list[%u]: %s\n", name_ptr, i,
                        EDCS_PrintUnitCode(value_ptr->eu_list[i]));
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n",
                EDCS_PrintUnitEquivalenceCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintUnitEquivalenceLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "eu_count: %s\n", EDCS_PrintCount(value_ptr->eu_count));
        if ((value_ptr->eu_count > 0) && (value_ptr->eu_list != NULL))
        {
            for (i = 0; i < (EDCS_Count) value_ptr->eu_count; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "eu_list[%u]: %s\n", i, EDCS_PrintUnitCode
                        (value_ptr->eu_list[i]));
            } /* end for i */
        }
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintUnitEquivalenceDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitEquivalenceLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitEquivalenceLabel
(
    EDCS_Unit_Equivalence_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintUnitEquivalenceLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitLabel
(
    EDCS_Unit_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintUnitLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitScaleDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintUnitScaleDictionaryEntry
(
    const EDCS_Unit_Scale_Dictionary_Entry *value_ptr,
    const char                             *name_ptr,
          EDCS_Count                        level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Unit_Scale_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintUnitScaleCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr, EDCS_PrintUnitScaleLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbol:", name_ptr);
        if (value_ptr->symbol != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbol);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n", EDCS_PrintUnitScaleCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintUnitScaleLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbol:");
        if (value_ptr->symbol != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbol);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintUnitScaleDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitScaleLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitScaleLabel
(
    EDCS_Unit_Scale_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintUnitScaleLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitStatus
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitStatus
(
    EDCS_Unit_Status value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_UNIT_STAT_RECOMMENDED:
             return "EDCS_UNIT_STAT_RECOMMENDED";

        case EDCS_UNIT_STAT_ACCEPTED:
             return "EDCS_UNIT_STAT_ACCEPTED";

        case EDCS_UNIT_STAT_DEPRECATED:
             return "EDCS_UNIT_STAT_DEPRECATED";

        case EDCS_UNIT_STAT_NOT_SI:
             return "EDCS_UNIT_STAT_NOT_SI";

        default:
             sprintf(buffer,"ERROR - ILLEGAL EDCS_Unit_Status VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintUnitStatus */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicApplicability
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintValueCharacteristicApplicability
(
    EDCS_Value_Characteristic_Applicability value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case EDCS_ATTR_VAL_CHAR_APPLICABILITY_ALL:
             return "EDCS_ATTR_VAL_CHAR_APPLICABILITY_ALL";

        case EDCS_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC:
             return "EDCS_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC";

        default:
             sprintf(buffer,"ERROR - ILLEGAL"\
                    " EDCS_Value_Characteristic_Applicability VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end EDCS_PrintValueCharacteristicApplicability */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
void
EDCS_PrintValueCharacteristicDictionaryEntry
(
    const EDCS_Value_Characteristic_Dictionary_Entry *value_ptr,
    const char                                       *name_ptr,
          EDCS_Count                                  level
)
{
    FILE *f_ptr;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "EDCS_Value_Characteristic_Dictionary_Entry\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->code: %s\n", name_ptr,
                EDCS_PrintValueCharacteristicCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->label: %s\n", name_ptr,
                EDCS_PrintValueCharacteristicLabel(value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->symbolic_constant:", name_ptr);
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->applicability: %s\n", name_ptr,
                EDCS_PrintValueCharacteristicApplicability(value_ptr->applicability));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->is_quantitative: %s\n", name_ptr,
                EDCS_PrintBoolean(value_ptr->is_quantitative));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->definition:", name_ptr);
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference_type: %s\n", name_ptr,
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->reference:", name_ptr);
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->supplemental_references:", name_ptr);
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->concept_status: %s\n", name_ptr,
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "code: %s\n",
                EDCS_PrintValueCharacteristicCode(value_ptr->code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "label: %s\n", EDCS_PrintValueCharacteristicLabel
                (value_ptr->label));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "symbolic_constant:");
        if (value_ptr->symbolic_constant != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->symbolic_constant);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "applicability: %s\n",
                EDCS_PrintValueCharacteristicApplicability(value_ptr->applicability));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "is_quantitative: %s\n",
                EDCS_PrintBoolean(value_ptr->is_quantitative));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "definition:");
        if (value_ptr->definition != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->definition);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference_type: %s\n",
                EDCS_PrintReferenceType(value_ptr->reference_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "reference:");
        if (value_ptr->reference != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->reference);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "supplemental_references:");
        if (value_ptr->supplemental_references != NULL)
        {
            fprintf(f_ptr, " %s", value_ptr->supplemental_references);
        }
        fprintf(f_ptr, "\n");
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "concept_status: %s\n",
                EDCS_PrintConceptStatus(value_ptr->concept_status));
    }
} /* end EDCS_PrintValueCharacteristicDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicLabel
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintValueCharacteristicLabel
(
    EDCS_Value_Characteristic_Label value
)
{
    return (const char *)value;
} /* end EDCS_PrintValueCharacteristicLabel */
