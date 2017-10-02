/*
 * FILE       : map_FACC_attribute.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This program takes a series of 3 character FACC 2.1 attribute codes
 *     and prints out the mapping information to map to EDCS 4.x
 *
 * Usage:
 *   map_FACC_attribute code1 code2 code3 ... codeN
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for a single FACC attribute code:
 *     map_FACC_attribute HGT
 *
 *   To retrieve mapping information for multiple FACC attribute codes:
 *     map_FACC_attribute HGT WID
 *
 * FACC 2.1 to EDCS 4.4 Mapping SDK Release 4.4.0.0 - July 1, 2011
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
#include "facc2p1_to_edcs4px.h"

const char *const EdcsVersionString = "4.4.x";
const char *const ToolName = "map_FACC_attribute";
const char *const ToolVersionString = "4.4.0.0";
const char *const BaseToolString = "%s v%s\n    (compatible with EDCS SDK %s)\n\n\n";

/*
 *-----------------------------------------------------------------------------
 *
 *-----------------------------------------------------------------------------
 */
static void
print_usage_and_exit
(
    void
)
{
    printf(
"Usage: map_FACC_attribute code1 code2 ... codeN\n");
    exit(0);
} /* end print_usage_and_exit */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: process_arguments
 *
 *-----------------------------------------------------------------------------
 */
static void
process_arguments
(
    int   argc,
    char *argv[]
)
{
    if (argc < 2)
    {
        print_usage_and_exit();
    }
    else
    {
       /*
        * Must call this function once before any EDCS_Map* functions are used
        */
        if (EDCS_InitFACC_2p1_MappingInfo() != EDCS_SC_SUCCESS)
        {
            fprintf(stderr, "Initialization of EDCS Mapping Code failed\n");
            exit(-1);
        }
    }
} /* end process_arguments */


int main
(
    int   argc,
    char *argv[]
)
{
    const FACC_2p1_Attribute_Mapping_Structure *mapping_info_out_ptr = NULL;
    const FACC_2p1_Unit_Mapping_Structure *unit_mapping_info_out_ptr = NULL;

    FACC_2p1_Attribute_Code attribute_code;
    EDCS_Status_Code        status;
    int i, j;

    fprintf(stderr, BaseToolString, ToolName, ToolVersionString,
            EdcsVersionString);

    process_arguments(argc, argv);

    for(i = 1; i < argc; i++)
    {
        if(strlen(argv[i]) != 3)
        {
            fprintf(stderr, "Valid FACC 2.1 Attribute codes "\
                    "have 3 characters %s has %d\n",
                    argv[i], strlen(argv[i]));
        }
        else
        {
            /* prepare the FACC_2p1_Attribute_Code with the given code */
            strncpy(attribute_code.tag, argv[i], 3);

            status = EDCS_MapFACC_2p1_AttributeCode(&attribute_code,
                                                    &unit_mapping_info_out_ptr,
                                                    &mapping_info_out_ptr);

            if (status == EDCS_SC_SUCCESS)
            {
                /*
                 * the map_type should be only one of 5 things
                 * for attribute mapping:
                 *  FACC_MAP_TYP_CHANGE_IN_DATATYPE,
                 *  FACC_MAP_TYP_ONE_TO_ONE,
                 *  FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED,
                 *  FACC_MAP_TYP_ONE_TO_ZERO,
                 *  FACC_MAP_TYP_SPECIAL
                 */
                printf("FACC 2.1 code %s ",
                       argv[i]);
                switch (mapping_info_out_ptr->map_type)
                {
                    case FACC_MAP_TYP_CHANGE_IN_DATATYPE:
                    {
                        /*
                         * For FACC attributes the units were often part of
                         * the attribute definition. If there is
                         * unit information in the mapping, it will be in the
                         * unit_mapping_info_out_ptr. If the ptr is NULL
                         * then there is no such information.
                         */
                        if (unit_mapping_info_out_ptr != NULL)
                        {
                            printf("maps with a change in datatype to the "\
                                   "EDCS 4.x attribute symbolic constant %s "\
                                   "[Unit: %s, Scale: %s]\n",
                               EDCS_PrintAttributeCode
                               (mapping_info_out_ptr->ea_code),
                               EDCS_PrintUnitCode
                               (unit_mapping_info_out_ptr->eu_code),
                               EDCS_PrintUnitScaleCode
                               (unit_mapping_info_out_ptr->es_code));
                        }
                        else
                        {
                            printf("maps with a change in datatype to the "\
                                   "EDCS 4.x attribute symbolic constant %s\n",
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_code));
                        }
                        break;
                    }
                    case FACC_MAP_TYP_ONE_TO_ONE:
                    {
                        /*
                         * For FACC attributes the units were often part of
                         * the attribute definition. If there is
                         * unit information in the mapping, it will be in the
                         * unit_mapping_info_out_ptr. If the ptr is NULL
                         * then there is no such information.
                         */
                        if (unit_mapping_info_out_ptr != NULL)
                        {
                            printf("maps exactly to the "\
                                   "EDCS 4.x attribute symbolic constant %s "\
                                   "[Unit: %s, Scale: %s]\n",
                               EDCS_PrintAttributeCode
                               (mapping_info_out_ptr->ea_code),
                               EDCS_PrintUnitCode
                               (unit_mapping_info_out_ptr->eu_code),
                               EDCS_PrintUnitScaleCode
                               (unit_mapping_info_out_ptr->es_code));
                        }
                        else
                        {
                            printf("maps exactly to the "\
                                   "EDCS 4.x attribute symbolic constant %s\n",
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_code));
                        }
                        break;
                    }
                    case FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED:
                    {
                        if (unit_mapping_info_out_ptr != NULL)
                        {
                            printf("to the "\
                                   "EDCS 4.x attribute symbolic constant %s "\
                                   "[Unit: %s, Scale: %s] qualified by "\
                                   "the following concept%s:\n",
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_code),
                                   EDCS_PrintUnitCode
                                   (unit_mapping_info_out_ptr->eu_code),
                                   EDCS_PrintUnitScaleCode
                                   (unit_mapping_info_out_ptr->es_code),
                                   (mapping_info_out_ptr->num_entries > 1 ?
                                   "s" : ""));
                        }
                        else
                        {
                            printf("maps to the "\
                                   "EDCS 4.x attribute symbolic constant %s "\
                                   "qualified by the following concept%s:\n",
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_code),
                                   (mapping_info_out_ptr->num_entries > 1 ?
                                    "s" : ""));
                        }

                        /*
                         * when the mapping type is
                         * FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED, in addition to
                         * the EDCS_Attribute_Code given in the ea_code field,
                         * there will be a list of EDCS_Mapping_Entries that
                         * qualify the main ea_code.

                         * When the mapping type is
                         * FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL, the
                         * ea_code field will be 0 and devoid of meaning;
                         * all concepts will be in the mapping entry list
                         *
                         * Loop through the mapping entry list and switch on
                         * the EDCS_Mapping_Entry_Type to discover the
                         * additional concepts
                         */
                        for (j = 0; j < mapping_info_out_ptr->num_entries; j++)
                        {
                            EDCS_PrintMappingEntry
                            (&(mapping_info_out_ptr->entry_list[j]),
                            NULL, 0);
                        }
                    }
                    break;

                    case FACC_MAP_TYP_ONE_TO_ZERO:
                    {
                        printf("maps to no EDCS 4.x concept.  "\
                               "The concept was deleted.\n");
                        break;
                    }
                    case FACC_MAP_TYP_SPECIAL_CASE:
                    {
                        if (mapping_info_out_ptr->ea_code == 0)
                        {
                            printf("has a special case mapping:\n");
                        }
                        else if (unit_mapping_info_out_ptr != NULL)
                        {
                            printf("maps to the "\
                                   "EDCS 4.x attribute symbolic constant %s "
                                   "[Unit: %s, Scale %s] with the "\
                                   "following special case info:\n",
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_code),
                                   EDCS_PrintUnitCode
                                   (unit_mapping_info_out_ptr->eu_code),
                                   EDCS_PrintUnitScaleCode
                                   (unit_mapping_info_out_ptr->eu_code));
                        }
                        else
                        {
                            printf("maps to the "\
                                   "EDCS 4.x attribute symbolic constant %s "
                                   "with the following special case info:\n",
                                   EDCS_PrintAttributeCode
                                   (mapping_info_out_ptr->ea_code));
                        }
                        break;
                    }

                    default:
                    {
                        fprintf(stderr, "Error: "\
                                "has an unhandled mapping type code %d\n",
                                mapping_info_out_ptr->map_type);
                        break;
                    }
                }

                if (strlen(mapping_info_out_ptr->information) > 0)
                {
                    printf("Notes: %s\n", mapping_info_out_ptr->information);
                }
            }
            else
            {
                fprintf(stderr, "FACC 2.1 code %s failed with status %s\n",
                 argv[i], EDCS_PrintStatusCode(status));
            }
        }
        printf("\n");
    }
    return 0;
}
