/*
 * FILE       : map_3p1_enumerant.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This simple program takes a series of EDCS 4.x attribute code/label and
 *     EDCS 4.x enumerant codes/label pairs and prints out the mapping
 *     information to map to EDCS 4.x.
 *
 * Usage:
 *   map_3p1_enumerant ea_code1,ee_code1 ea_code2,ee_code2 ... ea_codeN,ee_codeN
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for PRIMARY_RAW_MATERIAL with the value of
 *   ICE:
 *     map_3p1_enumerant 867,38
 *   or
 *     map_3p1_enumerant PRIMARY_RAW_MATERIAL,ICE
 *
 * EDCS 3.1 to EDCS 4.4 Mapping SDK Release 4.4.0.0 - July 1, 2011 
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
#include <ctype.h>

#include "edcs.h"
#include "edcs3p1_to_edcs4px.h"

const char *const EdcsVersionString = "4.4.x";
const char *const ToolName = "map_3p1_enumerant";
const char *const ToolVersionString = "4.4.0.0";
const char *const BaseToolString = "%s v%s\n    (compatible with EDCS SDK %s)\n\n\n";

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: print_usage_and_exit
 *
 *-----------------------------------------------------------------------------
 */
static void
print_usage_and_exit
(
    const char *err_msg
)
{
    fprintf(stderr, "%s\n\n", err_msg);

    fprintf(stderr,
"map_3p1_enumerant takes a series of EDCS 3.1 attribute code/label and\n"\
"    EDCS 3.1 enumerant codes/label pairs and prints out the mapping\n"\
"    information to map to EDCS %u.%u.\n"\
"\n"\
"Usage: map_3p1_enumerant ea_code1,ee_code1 ea_code2,ee_code2 ... ea_codeN,ee_codeN\n"\
"\n"\
" Options:\n" \
"\n" \
"  None\n" \
"\n" \
"Examples:\n" \
"  To find mapping information for PRIMARY_RAW_MATERIAL with the value of\n"\
"  ICE:\n"\
"    map_3p1_enumerant 867,38\n"\
"  or\n"\
"    map_3p1_enumerant PRIMARY_RAW_MATERIAL,ICE\n",
     (EDCS_Count)EDCS_MAJOR_VERSION, (EDCS_Count)EDCS_MINOR_VERSION);
    fflush(stderr);
    exit(-1);
} /* end print_usage_and_exit */

int main(int argc, char * argv[])
{
    const EDCS_3p1_4px_Enumerant_Mapping_Structure * mapping_info_out_ptr = NULL;

    EDCS_Boolean           valid_input = EDCS_TRUE;
    EDCS_Status_Code       status;

    EDCS_Integer           ea_code, ee_code;

    char * ea_code_str, * ee_code_str;
    int code_pair_i;

    fprintf(stderr, BaseToolString, ToolName, ToolVersionString,
            EdcsVersionString);

    if (argc < 2)
    {
        print_usage_and_exit("Can't map with no given entries");
    }
    else if (EDCS_Init3p1MappingInfo() != EDCS_SC_SUCCESS)
    {
        fprintf(stderr, "Failed to initialize "\
                "EDCS 3.1 to 4.x mapping library.\n");
        exit(-1);
    }
    else
    {
        for (code_pair_i = 1; code_pair_i < argc; code_pair_i++)
        {
            valid_input = EDCS_TRUE;
            ea_code_str = argv[code_pair_i];
            ee_code_str = strchr(ea_code_str, ',');

            if (ee_code_str == NULL)
            {
                fprintf(stderr, "In code pair %d, couldn't find "\
                        "enumerant code for attribute %s\n",
                        code_pair_i, ea_code_str);
                valid_input = EDCS_FALSE;
            }
            else
            {
                ee_code_str[0] = '\0';
                ee_code_str++;

                if ((ea_code = strtol(ea_code_str, NULL, 10)) == 0)
                {
                    if (EDCS_3p1AttributeCodeFromLabel(ea_code_str, &ea_code)
                        != EDCS_SC_SUCCESS)
                    {
                        valid_input = EDCS_FALSE;
                        fprintf(stderr, "Unrecognized attribute %s\n",
                                ea_code_str);
                    }
                }
                ee_code = strtol(ee_code_str, NULL, 10);
            }

            if (valid_input)
            {
                if (ee_code != 0)
                {
                    status = EDCS_Map3p1EnumerantCode
                             (ea_code, ee_code, &mapping_info_out_ptr);
                }
                else
                {
                    status = EDCS_Map3p1EnumerantLabel
                             (ea_code, ee_code_str, &mapping_info_out_ptr);
                }

                if (status == EDCS_SC_SUCCESS)
                {
                    EDCS_Count mapping_entry_index = 0;

                    switch (mapping_info_out_ptr->map_type)
                    {
                        case EDCS_MAPPING_TYP_ONE_TO_ZERO:
                        {

                            printf("EDCS 3.1 attribute %s with "\
                              "enumerant %s maps to no EDCS 4.x concept.  "\
                                   "The concept was deleted.\n",
                                   mapping_info_out_ptr->ea_3p1_label,
                                   mapping_info_out_ptr->ee_3p1_label);

                            break;
                        }
                        case EDCS_MAPPING_TYP_ONE_TO_ONE:
                        {
                            printf("EDCS 3.1 attribute %s with "\
                              "enumerant %s maps exactly to the EDCS 4.x "\
                              "attribute symbolic constant %s with the "\
                              "enumerant symbolic constant %s\n",
                                   mapping_info_out_ptr->ea_3p1_label,
                                   mapping_info_out_ptr->ee_3p1_label,
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_4px_code),
                                   EDCS_PrintEnumerantCode
                                   (mapping_info_out_ptr->ea_4px_code,
                                    mapping_info_out_ptr->ee_4px_code));
                            break;
                        }
                        case EDCS_MAPPING_TYP_ONE_TO_ONE_QUALIFIED:
                        {
                            printf("EDCS 3.1 attribute %s with "\
                              "enumerant %s maps to the EDCS 4.x "\
                              "attribute symbolic constant %s with the "\
                              "enumerant symbolic constant %s, qualified by\n",
                                   mapping_info_out_ptr->ea_3p1_label,
                                   mapping_info_out_ptr->ee_3p1_label,
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_4px_code),
                                   EDCS_PrintEnumerantCode
                                   (mapping_info_out_ptr->ea_4px_code,
                                    mapping_info_out_ptr->ee_4px_code));
                            for (mapping_entry_index = 0;
                                 mapping_entry_index < mapping_info_out_ptr->entry_count;
                                 mapping_entry_index++)
                            {
                                char entry_name[100];

                                sprintf(entry_name, "entry_list[%u]", mapping_entry_index);
                                EDCS_PrintMappingEntry
                                (&(mapping_info_out_ptr->entry_list[mapping_entry_index]),
                                entry_name, 4);
                            }
                            break;
                        }
                        case EDCS_MAPPING_TYP_ONE_TO_MANY:
                        {
                            printf("EDCS 3.1 attribute %s "\
                              "with enumerant %s has a one to many mapping",
                              mapping_info_out_ptr->ea_3p1_label,
                              mapping_info_out_ptr->ee_3p1_label);
                            if (mapping_info_out_ptr->ee_4px_code == 0)
                            {
                                printf(".\n");
                            }
                            else
                            {
                                printf(" with a default mapping to the "\
                                  "EDCS 4.x attribute symbolic constant "\
                                  "%s with the enumerant "\
                                  "symbolic constant %s with "\
                                  "the following one to many info:\n",
                                       EDCS_PrintAttributeCode
                                       (mapping_info_out_ptr->ea_4px_code),
                                       EDCS_PrintEnumerantCode
                                       (mapping_info_out_ptr->ea_4px_code,
                                        mapping_info_out_ptr->ee_4px_code));
                            }
                            break;
                        }
                        case EDCS_MAPPING_TYP_ONE_TO_ONE_CONDITIONAL:
                        {
                            printf("EDCS 3.1 attribute %s with enumerant %s"\
                                   "has a one-to-one conditional mapping to:\n",
                                   mapping_info_out_ptr->ea_3p1_label,
                                   mapping_info_out_ptr->ee_3p1_label);
                                EDCS_PrintMappingEntry
                                (&(mapping_info_out_ptr->entry_list[0]),
                                "mapped_value", 4);
                            break;
                        }
                        case EDCS_MAPPING_TYP_CHANGE_TO_CHARACTERISTIC:
                        {
                            printf("EDCS 3.1 attribute %s with enumerant %s "\
                                   "maps to EDCS 4.x "\
                                   "attribute %s with the EV value %s.\n",
                                   mapping_info_out_ptr->ea_3p1_label,
                                   mapping_info_out_ptr->ee_3p1_label,
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->entry_list[0].u.characteristic_entry.ea_code),
                                   EDCS_PrintValueCharacteristicCode
                                   (mapping_info_out_ptr->entry_list[0].u.characteristic_entry.ev_code));
                            break;
                        }
                        case EDCS_MAPPING_TYP_CHANGE_IN_DATATYPE:
                        {
                            printf("EDCS 3.1 attribute %s with enumerant %s "\
                                   "maps to the non-enumerated EDCS 4.x "\
                                   "attribute %s with the following value:\n",
                                   mapping_info_out_ptr->ea_3p1_label,
                                   mapping_info_out_ptr->ee_3p1_label,
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->entry_list[0].u.attr_value_entry.ea_code));
                            EDCS_PrintAttributeValue
                            (mapping_info_out_ptr->entry_list[0].u.attr_value_entry.ea_code,
                             &(mapping_info_out_ptr->entry_list[0].u.attr_value_entry.ea_value),
                            "mapped_value", 4);
                            break;
                        }
                        case EDCS_MAPPING_TYP_SPECIAL_CASE:
                        {
                            if (mapping_info_out_ptr->ee_4px_code == 0)
                            {
                                printf("EDCS 3.1 attribute %s with enumerant %s has a special case mapping:\n",
                                       mapping_info_out_ptr->ea_3p1_label,
                                       mapping_info_out_ptr->ee_3p1_label);
                            }
                            else
                            {
                                printf("EDCS 3.1 attribute %s with "\
                                  "enumerant %s maps to the "\
                                  "EDCS 4.x attribute symbolic constant "\
                                  "%s with the enumerant "\
                                  "symbolic constant %s with "\
                                       "the following special case info:\n",
                                       mapping_info_out_ptr->ea_3p1_label,
                                       mapping_info_out_ptr->ee_3p1_label,
                                       EDCS_PrintAttributeCode
                                       (mapping_info_out_ptr->ea_4px_code),
                                       EDCS_PrintEnumerantCode
                                       (mapping_info_out_ptr->ea_4px_code,
                                        mapping_info_out_ptr->ee_4px_code));
                            }
                            break;
                        }
                        default:
                        {
                            fprintf(stderr, "Error: EDCS 3.1 attribute %s "\
                              "with the enumerant %s has an unhandled "\
                                    "mapping type %s\n",
                                    mapping_info_out_ptr->ea_3p1_label,
                                    mapping_info_out_ptr->ee_3p1_label,
                                    EDCS_PrintMappingTypeCode(mapping_info_out_ptr->map_type));
                            break;
                        }
                    }

                    if (strlen(mapping_info_out_ptr->notes) > 0)
                    {
                        printf("Notes: %s\n", mapping_info_out_ptr->notes);
                    }

                }
                else
                {
                    fprintf(stderr, "EDCS 3.1 attribute %s with the "\
                            "enumerant %s failed with status %s\n",
                            ea_code_str, ee_code_str,
                            EDCS_PrintStatusCode(status));
                }
            }
            printf("\n");
        }
        EDCS_Shutdown3p1MappingInfo();
    }
    return 0;
} /* end main */
