/*
 * FILE       : map_3p1_group.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This program takes a series of EDCS 3.1 group codes or labels
 *     and prints out the mapping information to map to EDCS 4.x
 *
 * Usage:
 *   map_3p1_group code1 label2 code3 label4 ... codeN-1 labelN
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for EGC_GEN_BUILDING_COMPONENT:
 *     map_3p1_group BUILDING_COMPONENT
 *   or
 *     map_3p1_group 48
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

#include "edcs.h"
#include "edcs3p1_to_edcs4px.h"

const char *const EdcsVersionString = "4.4.x";
const char *const ToolName = "map_3p1_group";
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
"map_3p1_group takes a series of EDCS 3.1 group codes or labels"\
 "and prints out the mapping information to map to EDCS %u.%u.\n"\
"\n"\
"Usage: map_3p1_group code1 label2 code3 label4 ... codeN-1 labelN\n"\
"\n"\
" Options:\n" \
"\n" \
"  None\n" \
"\n" \
"Examples:\n" \
"  To find mapping information for EGC_GEN_BUILDING_COMPONENT:\n"\
"    map_3p1_group BUILDING_COMPONENT\n"\
"    or\n"\
"    map_3p1_group 48\n",
            (EDCS_Count)EDCS_MAJOR_VERSION,
            (EDCS_Count)EDCS_MINOR_VERSION);
    fflush(stderr);
    exit(-1);
} /* end print_usage_and_exit */

int main(int argc, char * argv[])
{
    const EDCS_3p1_4px_Group_Mapping_Structure *mapping_info_out_ptr = NULL;

    EDCS_Integer group_code;
    EDCS_Status_Code status;

    int i;

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
        for (i = 1; i < argc; i++)
        {
            if ((group_code = strtol(argv[i], NULL, 10)) != 0)
            {
                status = EDCS_Map3p1GroupCode(group_code, &mapping_info_out_ptr);
            }
            else
            {
                status = EDCS_Map3p1GroupLabel(argv[i], &mapping_info_out_ptr);
            }

            if (status == EDCS_SC_SUCCESS)
            {
                /* the map_type will be only one of 4 things for EG mapping:
                 *  EDCS_MAPPING_TYP_ONE_TO_ZERO,
                 *  EDCS_MAPPING_TYP_ONE_TO_ONE,
                 *  EDCS_MAPPING_TYP_ONE_TO_MANY,
                 *  EDCS_MAPPING_TYP_SPECIAL_CASE,
                 */
                switch (mapping_info_out_ptr->map_type)
                {
                    case EDCS_MAPPING_TYP_ONE_TO_ZERO:
                    {
                        printf("EDCS 3.1 group %s maps to "\
                          "no EDCS 4.x concept.  The concept was deleted.\n",
                          mapping_info_out_ptr->eg_3p1_label);
                        break;
                    }
                    case EDCS_MAPPING_TYP_ONE_TO_ONE:
                    {
                        printf("EDCS 3.1 group %s maps exactly to "\
                          "the EDCS 4.x group symbolic constant %s\n",
                          mapping_info_out_ptr->eg_3p1_label,
                          EDCS_PrintGroupCode
                          (EOC_GENERAL, mapping_info_out_ptr->eg_4px_code));
                        break;
                    }
                    case EDCS_MAPPING_TYP_ONE_TO_MANY:
                    {
                        if (mapping_info_out_ptr->eg_4px_code != 0)
                        {
                            printf("EDCS 3.1 group %s has a "\
                              "one to many mapping, with a default mapping to "
                              "EDCS 4.x group code %s.\n",
                              mapping_info_out_ptr->eg_3p1_label,
                              EDCS_PrintGroupCode
                              (EOC_GENERAL, mapping_info_out_ptr->eg_4px_code));
                        }
                        else
                        {
                            printf("EDCS 3.1 group %s has a "\
                              "one to many mapping, with no default mapping.\n",
                              mapping_info_out_ptr->eg_3p1_label);
                        }
                        break;
                    }
                    case EDCS_MAPPING_TYP_SPECIAL_CASE:
                    {
                        printf("EDCS 3.1 group %s has a "\
                          "special case mapping to EDCS 4.x group code %s.\n",
                          mapping_info_out_ptr->eg_3p1_label,
                          EDCS_PrintGroupCode
                          (EOC_GENERAL, mapping_info_out_ptr->eg_4px_code));
                        break;
                    }
                    default:
                    {
                        fprintf(stderr, "Error: EDCS 3.1 code %s has "\
                                "an unhandled mapping type %s\n",
                                argv[i],
                                EDCS_PrintMappingEntryTypeCode
                                (mapping_info_out_ptr->map_type));
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
                fprintf(stderr, "The call to map EDCS 3.1 group %s "\
                        "failed with status %s\n",
                        argv[i], EDCS_PrintStatusCode(status));
            }
            printf("\n");
        }
        EDCS_Shutdown3p1MappingInfo();
    }
    return 0;
} /* end main */
