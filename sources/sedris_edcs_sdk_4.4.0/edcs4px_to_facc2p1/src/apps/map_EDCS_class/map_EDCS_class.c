/*
 * FILE       : map_EDCS_class.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This program takes a series of EDCS 4.x classification labels
 *     or symbolic constants  and prints out the mapping information
 *     to map to DIGEST FACC Edition 2.1.
 *
 * Usage:
 *   map_EDCS_class label1 label2 label3 ... labelN
 *
 *      where label can be an EDCS Classification Label or Symbolic Constant
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for EDCS Classification BUILDING:
 *     map_EDCS_class ECC_BUILDING
 *      or
 *     map_EDCS_class BUILDING
 *
 *   To retrieve mapping information for BUILDING and RIVER:
 *     map_EDCS_class ECC_BUILDING ECC_RIVER
 *      or
 *     map_EDCS_class BUILDING RIVER
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
const char *const ToolName = "map_EDCS_class";
const char *const ToolVersionString = "4.4.0.0";
const char *const BaseToolString = "%s v%s\n    (compatible with EDCS SDK %s)\n\n\n";

/*
 * FUNCTION: print_usage
 */
void print_usage(void)
{
    printf("\nUsage: map_EDCS_class concept1 concept2 ... conceptN\n"
           "\n"
           "Example:\n"
           "\n"
           "To retrieve mapping information for BUILDING and RIVER:\n"
           "\tmap_EDCS_class ECC_BUILDING ECC_RIVER\n"
           "\t  or\n"
           "\tmap_EDCS_class BUILDING RIVER\n\n");
} /* end print_usage */

void
map_classification_code
(
    EDCS_Classification_Code ec_code
)
{
    FACC_Feature_Mapping_Structure * mapping_entry;

    printf("\n");

    if (EDCS_to_FACC_MapClassificationCode(ec_code, &mapping_entry) !=
        EDCS_SC_SUCCESS)
    {
        fprintf(stderr, "Mapping %s failed\n",
                EDCS_PrintClassificationCode(ec_code));
    }
    else
    {
        switch (mapping_entry->mapping_type)
        {
            case FACC_MAP_TYP_ONE_TO_ONE:
            {
                 printf("Mapping for EDCS Classification %s was ONE_TO_ONE:\n",
                        EDCS_PrintClassificationCode(ec_code));
                 printf("\t    FACC Feature Code: %c%c%c%c%c\n",
                        mapping_entry->facc_feature_code.tag[0],
                        mapping_entry->facc_feature_code.tag[1],
                        mapping_entry->facc_feature_code.tag[2],
                        mapping_entry->facc_feature_code.tag[3],
                        mapping_entry->facc_feature_code.tag[4]);
                 break;
            }
            case FACC_MAP_TYP_ONE_TO_ZERO:
            {
                 printf("Mapping for EDCS Classification %s was ONE_TO_ZERO:\n",
                        EDCS_PrintClassificationCode(ec_code));
                 break;
            }
            case FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED:
            {
                 int i;

                 printf("Mapping for EDCS Classification %s was "\
                        "ONE_TO_ONE_QUALIFIED:\n",
                        EDCS_PrintClassificationCode(ec_code));

                 printf("\t    FACC Feature Code: %c%c%c%c%c\n",
                        mapping_entry->facc_feature_code.tag[0],
                        mapping_entry->facc_feature_code.tag[1],
                        mapping_entry->facc_feature_code.tag[2],
                        mapping_entry->facc_feature_code.tag[3],
                        mapping_entry->facc_feature_code.tag[4]);

                 printf("\tQualifying Attributes\n"\
              "\t--------------------------------------------------------\n");

                 for (i = 0; i < mapping_entry->additional_concept_count; i++)
                 {
                     switch (mapping_entry->additional_concepts[i].value_type)
                     {
                         case FACC_VAL_TYP_CODED:
                         {
                             printf("\t\tFACC Attribute %c%c%c "\
                                    "with the CODED value of %d",
                                    mapping_entry->additional_concepts[i].
                                                   facc_attribute_code.tag[0],
                                    mapping_entry->additional_concepts[i].
                                                   facc_attribute_code.tag[1],
                                    mapping_entry->additional_concepts[i].
                                                   facc_attribute_code.tag[2],
                                    mapping_entry->additional_concepts[i].
                                                   u.facc_coded_value);
                             printf("\n");
                             break;
                         }
                         default:
                         {
                             fprintf(stderr, "Unhandled FACC_Value_Type %d\n",
                                     mapping_entry->additional_concepts[i].
                                     value_type);
                             break;
                         }
                     } /* end switch */
                 } /* end for i */
                 printf("\t"\
                 "--------------------------------------------------------\n");
             }
             break;
        }

        if (mapping_entry->notes)
        {
            printf("\t        Mapping Notes: %s\n",
                   mapping_entry->notes);
        }
    }
} /* end map_classification_code */


/*
 * FUNCTION: main
 */
int main
(
    int   argc,
    char *argv[]
)
{
    int i;
    EDCS_Classification_Code ec_code;

    fprintf(stderr, BaseToolString, ToolName, ToolVersionString,
            EdcsVersionString);

    if (argc < 2)
    {
        print_usage();
        exit(-1);
    }
    /* Have to initialize the mapping library before using it */
    EDCS_to_FACC_InitMappingInfo();

    for (i = 1; i < argc; i++)
    {
        if (EDCS_LabelToECCode(argv[i], &ec_code) == EDCS_SC_SUCCESS ||
            EDCS_SymbolicConstantToECCode(argv[i], &ec_code) == EDCS_SC_SUCCESS)
        {
            map_classification_code((EDCS_Classification_Code) ec_code);
        }
        else
        {
            fprintf(stderr,
                    "Unrecognized EDCS Classification \"%s\", skipping.\n",
                    argv[i]);
            continue;
        }
    }
    /* Have to shut it down as well */
    EDCS_to_FACC_ShutdownMappingInfo();
    printf("\n");

    return 0;
} /* end main */
