/*
 * FILE       : edcs_mapping_util.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *      Provides EDCS mapping utilities.
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

#include "edcs_mapping_util.h"

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

void
EDCS_PrintAttributeWithValueEntry
(
    const EDCS_Attribute_With_Value_Entry *value_ptr,
    const char                       *name_ptr,
          EDCS_Count                  level
)
{
    char        buffer[1024];
    FILE       *f_ptr = NULL;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Attribute_With_Value_Entry\n");
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ea_code: %s\n", name_ptr,
                EDCS_PrintAttributeCode(value_ptr->ea_code));
        sprintf(buffer, "%s->ea_value", name_ptr);
        EDCS_PrintAttributeValue(value_ptr->ea_code, &(value_ptr->ea_value), buffer, level);
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ea_code: %s\n",
                EDCS_PrintAttributeCode(value_ptr->ea_code));
        EDCS_PrintAttributeValue(value_ptr->ea_code, &(value_ptr->ea_value), "ea_value", level);
    }
} /* end EDCS_PrintAttributeWithValueEntry */

void
EDCS_PrintMappingEntry
(
    const EDCS_Mapping_Entry *value_ptr,
    const char               *name_ptr,
          EDCS_Count          level
)
{
    char        buffer[1024];
    FILE       *f_ptr = NULL;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Mapping_Entry\n");
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->type: %s\n", name_ptr,
          EDCS_PrintMappingEntryTypeCode(value_ptr->type));
        switch (value_ptr->type)
        {
            case EDCS_MAP_ENTRY_TYP_ATTR:
                 SE_Indent(level, f_ptr);
                 fprintf(f_ptr, "%s->u.attribute_entry: %s\n", name_ptr,
                   EDCS_PrintAttributeCode(value_ptr->u.attribute_entry));
                 break;

            case EDCS_MAP_ENTRY_TYP_ATTR_VAL:
                 sprintf(buffer, "%s->u.attr_value_entry", name_ptr);
                 EDCS_PrintAttributeWithValueEntry
                 (&(value_ptr->u.attr_value_entry), buffer, level);
                 break;

            case EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC:
                 sprintf(buffer, "%s->u.characteristic_entry", name_ptr);
                 EDCS_PrintValueCharacteristicCodeEntry
                 (&(value_ptr->u.characteristic_entry), buffer, level);
                 break;

            case EDCS_MAP_ENTRY_TYP_CLASS:
                 SE_Indent(level, f_ptr);
                 fprintf(f_ptr, "%s->u.class_entry: %s\n", name_ptr,
                   EDCS_PrintClassificationCode(value_ptr->u.class_entry));
                 break;

            default:
                 break;
        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "type: %s\n",
          EDCS_PrintMappingEntryTypeCode(value_ptr->type));
        switch (value_ptr->type)
        {
            case EDCS_MAP_ENTRY_TYP_ATTR:
                 SE_Indent(level, f_ptr);
                 fprintf(f_ptr, "u.attribute_entry: %s\n",
                   EDCS_PrintAttributeCode(value_ptr->u.attribute_entry));
                 break;

            case EDCS_MAP_ENTRY_TYP_ATTR_VAL:
                 EDCS_PrintAttributeWithValueEntry
                 (&(value_ptr->u.attr_value_entry), "u.attr_value_entry", level);
                 break;

            case EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC:
                 EDCS_PrintValueCharacteristicCodeEntry
                 (&(value_ptr->u.characteristic_entry), "u.characteristic_entry", level);
                 break;

            case EDCS_MAP_ENTRY_TYP_CLASS:
                 SE_Indent(level, f_ptr);
                 fprintf(f_ptr, "u.class_entry: %s\n",
                   EDCS_PrintClassificationCode(value_ptr->u.class_entry));
                 break;

            default:
                 break;
        } /* end switch */
    }
} /* end EDCS_PrintMappingEntry */

const char *
EDCS_PrintMappingEntryTypeCode
(
    EDCS_Mapping_Entry_Type_Code value
)
{
    static char buffer[255];

    switch (value)
    {
        case EDCS_MAP_ENTRY_TYP_ATTR:
            return "EDCS_MAP_ENTRY_TYP_ATTR";
        case EDCS_MAP_ENTRY_TYP_ATTR_VAL:
            return "EDCS_MAP_ENTRY_TYP_ATTR_VAL";
        case EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC:
            return "EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC";
        case EDCS_MAP_ENTRY_TYP_CLASS:
            return "EDCS_MAP_ENTRY_TYP_CLASS";
        default:
            sprintf(buffer, "Error: Unrecognized EDCS_Mapping_Entry_Type_Code %d", value);
            return buffer;
    } /* end switch */
} /* end EDCS_PrintMappingEntryTypeCode */

const char *
EDCS_PrintMappingTypeCode
(
    EDCS_Mapping_Type_Code value
)
{
    static char buffer[255];

    switch (value)
    {
        case EDCS_MAPPING_TYP_CHANGE_IN_DATATYPE:
            return "CHANGE_IN_DATATYPE";
        case EDCS_MAPPING_TYP_CHANGE_TO_CHARACTERISTIC:
            return "CHANGE_TO_CHARACTERISTIC";
        case EDCS_MAPPING_TYP_ONE_TO_ZERO:
            return "ONE_TO_ZERO";
        case EDCS_MAPPING_TYP_ONE_TO_MANY:
            return "ONE_TO_MANY";
        case EDCS_MAPPING_TYP_ONE_TO_ONE:
            return "ONE_TO_ONE";
        case EDCS_MAPPING_TYP_ONE_TO_ONE_CONDITIONAL:
            return "ONE_TO_ONE_CONDITIONAL";
        case EDCS_MAPPING_TYP_ONE_TO_ONE_QUALIFIED:
            return "ONE_TO_ONE_QUALIFIED";
        case EDCS_MAPPING_TYP_SPECIAL_CASE:
            return "SPECIAL_CASE";
        default:
            sprintf(buffer, "Error: Unrecognized EDCS_Mapping_Type_Code %d", value);
            return buffer;
    } /* end switch */
} /* end EDCS_PrintMappingTypeCode */

void
EDCS_PrintValueCharacteristicCodeEntry
(
    const EDCS_Value_Characteristic_Code_Entry *value_ptr,
    const char       *name_ptr,
          EDCS_Count  level
)
{
    FILE *f_ptr = NULL;

    f_ptr = EDCS_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL EDCS_Value_Characteristic_Code_Entry\n");
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ea_code: %s\n", name_ptr,
                EDCS_PrintAttributeCode(value_ptr->ea_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ev_code: %s\n", name_ptr,
                EDCS_PrintValueCharacteristicCode(value_ptr->ev_code));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ea_code: %s\n",
                EDCS_PrintAttributeCode(value_ptr->ea_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ev_code: %s\n",
                EDCS_PrintValueCharacteristicCode(value_ptr->ev_code));
    }
} /* end EDCS_PrintValueCharacteristicCodeEntry */

const char *
EDCS_MapUtilGetImplVerInfo
(
    void
)
{
    return "4.3.2.0";
} /* end EDCS_MapUtilGetImplVerInfo */
