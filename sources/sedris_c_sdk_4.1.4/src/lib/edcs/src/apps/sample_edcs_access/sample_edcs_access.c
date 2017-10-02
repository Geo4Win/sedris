/*
 * FILE       : sample_edcs_access.c
 *
 * PROGRAMMERS: Warren Macchi (Accent Geographic)
 *
 * DESCRIPTION:
 *     This program takes an EDCS classification code (or label)
 *     and an EDCS attribute code (or label) and displays their
 *     information.
 *
 * Usage:
 *   sample_edcs_access ECC_label EAC_label
 *   or
 *   sample_edcs_access ECC_label EAC_code
 *   or
 *   sample_edcs_access ECC_code EAC_label
 *   or
 *   sample_edcs_access ECC_code EAC_code
 *
 * Options: none
 *
 * Examples:
 *
 *   sample_edcs_access WALL WALL_CONSTRUCTION_TYPE
 *   sample_edcs_access 101 200
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
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

#include "edcs.h"

const char *const EdcsVersionString = "4.4.x";
const char *const ToolName = "sample_edcs_access";
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
"sample_edcs_access takes an EDCS classification code (or label) "\
"and an EDCS attribute code (or label) and displays their "\
"information.\n"\
"\n"\
"Usage: sample_edcs_access ECC_label EAC_label\n"\
"    or\n"\
"       sample_edcs_access ECC_label EAC_code\n"\
"    or\n"\
"       sample_edcs_access ECC_code EAC_label\n"\
"    or\n"\
"       sample_edcs_access ECC_code EAC_code\n"\
"\n"\
" Options:\n" \
"\n" \
"  None\n" \
"\n" \
"Examples:\n" \
"  To find mapping information for ECC_BUILDING and EAC_BUILDING_FUNCTION:\n"\
"    sample_edcs_access BUILDING BUILDING_FUNCTION\n"\
"    or\n"\
"    sample_edcs_access BUILDING 208\n\n"\
"    or\n"\
"    sample_edcs_access 173 BUILDING_FUNCTION\n\n"\
"    or\n"\
"    sample_edcs_access 173 208\n\n");
    fflush(stderr);
    exit(-1);
} /* end print_usage_and_exit */

int main( int argc, char * argv[] )
{
    printf(BaseToolString, ToolName, ToolVersionString,
           EdcsVersionString);

    if (argc < 3)
    {
        print_usage_and_exit("Not enough parameters.");
    }
    else
    {
        const EDCS_Classification_Dictionary_Entry *ecd = NULL;
        const EDCS_Attribute_Dictionary_Entry *ead = NULL;
        EDCS_Classification_Code ec_code = 0;
        EDCS_Attribute_Code      ea_code = 0;

        ec_code = atoi(argv[1]);
        if (EDCS_GetECDictionaryEntry(ec_code, &ecd) != EDCS_SC_SUCCESS)
        {
            if (EDCS_LabelToECCode(argv[1], &ec_code) == EDCS_SC_SUCCESS)
            {
                if (EDCS_GetECDictionaryEntry(ec_code, &ecd) != EDCS_SC_SUCCESS)
                {
                    ec_code = 0;
                    ecd     = NULL;
                }
            }
            else
            {
                ec_code = 0;
                ecd     = NULL;
            }
        }

        if (ecd != NULL)
        {
            printf("ECC (%i) - %s:\n\t%s\n",
                   ecd->code, ecd->label, ecd->definition);
        }
        else
        {
            fprintf(stderr,
                    "Error in call to EDCS_GetECDictionaryEntry() - "\
                    " requires integer code or label of a valid EC\n");
        }
        printf("\n");

        ea_code = atoi(argv[2]);
        if (EDCS_GetEADictionaryEntry(ea_code, &ead) != EDCS_SC_SUCCESS)
        {
            if (EDCS_LabelToEACode(argv[2], &ea_code) == EDCS_SC_SUCCESS)
            {
                if (EDCS_GetEADictionaryEntry(ea_code, &ead) != EDCS_SC_SUCCESS)
                {
                    ea_code = 0;
                    ead     = NULL;
                }
            }
            else
            {
                ea_code = 0;
                ead     = NULL;
            }
        }

        if (ead != NULL)
        {
            printf("EAC (%i) - %s:\n\t%s\n",
                   ead->code, ead->label, ead->definition);
        }
        else
        {
            fprintf(stderr,
                    "Error in call to EDCS_GetEADictionaryEntry() - "\
                    " requires integer code or label of a valid EA\n");
        }
    }
    return 0;
} /* end main */
