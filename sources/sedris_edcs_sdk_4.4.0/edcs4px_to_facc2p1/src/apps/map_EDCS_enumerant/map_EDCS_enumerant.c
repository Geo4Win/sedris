/*
 * FILE       : map_EDCS_enumerant.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This program takes a series of EDCS 4.x enumerant symbolic
 *     constants or attribute/enumerant label pairs and prints out
 *     the mapping information to map to DIGEST FACC Edition 2.1.
 *
 * Usage:
 *   map_EDCS_enumerant constant1 constant2 constant3 ... constantN
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for EDCS Enumerant MAJOR_AERODROME for
 *   EDCS Attribute AERODROME_TYPE:
 *
 *     map_EDCS_enumerant AERODROME_TYPE:MAJOR_AERODROME
 *       or
 *     map_EDCS_enumerant EEC_AERODTY_MAJOR_AERODROME
 *
 * EDCS 4.4 to FACC 2.1 Mapping SDK Release 4.4.0.0 - July 1, 2011
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
#include <stdlib.h>

#include "edcs.h"
#include "edcs4px_to_facc2p1.h"

const char *const EdcsVersionString = "4.4.x";
const char *const ToolName = "map_EDCS_enumerant";
const char *const ToolVersionString = "4.4.0.0";
const char *const BaseToolString = "%s v%s\n    (compatible with EDCS SDK %s)\n\n\n";

void print_usage(void)
{
    printf("\nUsage: map_EDCS_enumerant constant1 constant2 ... constantN\n"
    "\n"
    "Example:\n"
    "\n"
    "To retrieve mapping information for EDCS Enumerant MAJOR_AERODROME for\n"
    "EDCS Attribute AERODROME_TYPE:\n"
    "     map_EDCS_enumerant AERODROME_TYPE:MAJOR_AERODROME\n"
    "       or\n"
    "     map_EDCS_enumerant EEC_AERODTY_MAJOR_AERODROME\n\n");
}

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: map_enumeration_value
 *
 *-----------------------------------------------------------------------------
 */
void
map_enumeration_value
(
    EDCS_Attribute_Code         ea_code_to_map,
    EDCS_Attribute_Value_Entry *value_to_map
)
{
    FACC_Attribute_With_Value_Mapping_Structure mapping_entry;

    if (EDCS_to_FACC_MapAttributeWithValue(ea_code_to_map,
        value_to_map, &mapping_entry) == EDCS_SC_SUCCESS)
    {
        FACC_Attribute_With_Value *facc_attr_with_val_ptr = NULL;

        facc_attr_with_val_ptr = &(mapping_entry.facc_attribute_with_value);
        switch (mapping_entry.mapping_type)
        {
            case FACC_MAP_TYP_ONE_TO_ONE:
            {
                 printf("Mapping for EDCS Enumerant %s was ONE to ONE:\n",
                        EDCS_PrintEnumerantCode(ea_code_to_map,
                        value_to_map->u.ea_value.value.enumeration_value));

                 printf("\tFACC Attribute: %c%c%c\n",
                        facc_attr_with_val_ptr->facc_attribute_code.tag[0],
                        facc_attr_with_val_ptr->facc_attribute_code.tag[1],
                        facc_attr_with_val_ptr->facc_attribute_code.tag[2]);

                 printf("\tFACC Value Type: %s\n",
                        EDCS_to_FACC_PrintFACCValueType
                        (facc_attr_with_val_ptr->value_type));

                 switch (facc_attr_with_val_ptr->value_type)
                 {
                     case FACC_VAL_TYP_CODED:
                         printf("\tFACC Coded Value: %d\n",
                                facc_attr_with_val_ptr->u.facc_coded_value);
                         break;
                     case FACC_VAL_TYP_SHORT_INTEGER:
                         printf("\tFACC Short Integer Value: %d\n",
                           facc_attr_with_val_ptr->u.facc_short_integer_value);
                         break;
                     case FACC_VAL_TYP_LONG_INTEGER:
                         printf("\tFACC Long Integer Value: %d\n",
                           facc_attr_with_val_ptr->u.facc_long_integer_value);
                         break;
                     case FACC_VAL_TYP_FLOAT:
                         printf("\tFACC Float Value: %f\n",
                                facc_attr_with_val_ptr->u.facc_float_value);
                         break;
                     case FACC_VAL_TYP_TEXT:
                         printf("\tFACC Text Value: %s\n",
                                facc_attr_with_val_ptr->u.facc_text_value);
                         break;
                     default:
                         break;
                 }

                 if (mapping_entry.notes)
                 {
                     printf("\tNotes: %s\n", mapping_entry.notes);
                 }
                 break;
            }
            case FACC_MAP_TYP_ONE_TO_ZERO:
            {
                 printf("Mapping for EDCS Enumerant %s was ONE to ZERO:\n",
                        EDCS_PrintEnumerantCode(ea_code_to_map,
                        value_to_map->u.ea_value.value.enumeration_value));
                 if (mapping_entry.notes)
                 {
                     printf("\tNotes: %s\n", mapping_entry.notes);
                 }
                 else
                 {
                     printf("\tNo notes.\n");
                 }
                 break;
            }
            default:
                 fprintf(stderr, "Unexpected mapping type: %s\n",
                   EDCS_to_FACC_PrintMappingType(mapping_entry.mapping_type));
                 break;
        } /* end switch */
        printf("\n");
    }
    else
    {
        fprintf(stderr, "EDCS_to_FACC_MapAttributeWithValue call FAILED.\n");
    }
} /* end map_enumeration_value */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *-----------------------------------------------------------------------------
 */
int
main
(
    int argc,
    char * argv[]
)
{
    int                        i;
    EDCS_Attribute_Code        ea_code_to_map;
    EDCS_Enumerant_Code        ee_code_to_map;
    EDCS_Attribute_Value_Entry value_to_map;

    fprintf(stderr, BaseToolString, ToolName, ToolVersionString,
            EdcsVersionString);

    if (argc < 2)
    {
        print_usage();
    }
    else
    {
        EDCS_to_FACC_InitMappingInfo();

        printf("\n");

        for (i = 1; i < argc; i++)
        {
            if (!strchr(argv[i], ':'))
            {
                if (EDCS_SymbolicConstantToEECode(argv[i],
                         &ea_code_to_map,
                         &ee_code_to_map) != EDCS_SC_SUCCESS)
                {
                    fprintf(stderr, "Unrecognized EDCS Enumerant "\
                            "symbolic constant \"%s\", skipping.\n", argv[i]);
                    continue;
                }
            }
            else
            {
                char * ea_label, *ee_label;
                ea_label = argv[i];
                ee_label = strchr(ea_label, ':');
                ee_label[0] = '\0';
                ee_label++;

                if (EDCS_LabelToEECode(ea_label, ee_label, &ea_code_to_map,
                    &ee_code_to_map) != EDCS_SC_SUCCESS)
                {
                    fprintf(stderr,
 "Unrecognized EDCS Attribute/Enumerant label pair \"%s:%s\", skipping.\n",
                            ea_label, ee_label);
                    continue;
                }
            }
            value_to_map.is_ev                = EDCS_FALSE;
            value_to_map.u.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
            value_to_map.u.ea_value.value.enumeration_value = ee_code_to_map;
            map_enumeration_value(ea_code_to_map, &value_to_map);
        }
        EDCS_to_FACC_ShutdownMappingInfo();
    }
    return 0;
} /* end main */
