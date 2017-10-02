/*
 * FILE       : map_EDCS_attribute.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This program takes a series of EDCS 4.x attribute labels
 *     or symbolic constants  and prints out the mapping information
 *     to map to DIGEST FACC Edition 2.1.
 *
 * Usage:
 *   map_EDCS_attribute label1 label2 label3 ... labelN
 *
 *      where label can be an EDCS Attribute Label or Symbolic Constant
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for EDCS Attribute HEIGHT_ABOVE_SURFACE_LEVEL:
 *     map_EDCS_attribute EAC_HEIGHT_ABOVE_SURFACE_LEVEL
 *      or
 *     map_EDCS_attribute HEIGHT_ABOVE_SURFACE_LEVEL
 *
 *   To retrieve mapping information for HEIGHT_ABOVE_SURFACE_LEVEL and CAPACITY:
 *     map_EDCS_attribute EAC_HEIGHT_ABOVE_SURFACE_LEVEL EAC_CAPACITY
 *      or
 *     map_EDCS_attribute HEIGHT_ABOVE_SURFACE_LEVEL CAPACITY
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
const char *const ToolName = "map_EDCS_attribute";
const char *const ToolVersionString = "4.4.0.0";
const char *const BaseToolString = "%s v%s\n    (compatible with EDCS SDK %s)\n\n\n";

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: map_attribute_code
 *
 *----------------------------------------------------------------------------
 */
void
map_attribute_code
(
    EDCS_Attribute_Code ea_code
)
{
    FACC_Attribute_Mapping_Structure * mapping_entry;

    printf("\n");

    if (EDCS_to_FACC_MapAttributeCode(ea_code, &mapping_entry) !=
        EDCS_SC_SUCCESS)
    {
        fprintf(stderr, "Mapping of EDCS Attribute %s failed\n",
                EDCS_PrintAttributeCode(ea_code));
    }
    else
    {
        if (mapping_entry->mapping_type == FACC_MAP_TYP_ONE_TO_ONE)
        {
            printf("Mapping for EDCS Attribute %s was ONE to ONE:\n",
                   EDCS_PrintAttributeCode(ea_code));

            printf("\t     FACC Attribute: %c%c%c\n",
                     mapping_entry->facc_attribute_code.tag[0],
                     mapping_entry->facc_attribute_code.tag[1],
                     mapping_entry->facc_attribute_code.tag[2]);

            printf("\t    FACC Value Type: %s\n",
                   EDCS_to_FACC_PrintFACCValueType
                   (mapping_entry->facc_target_value_type));

            if (mapping_entry->facc_target_unit_code != 0)
            {
                printf("\t FACC Expected Unit: %s\n"
                       "\tFACC Expected Unit Scale: %s\n",
                       EDCS_PrintUnitCode
                       (mapping_entry->facc_target_unit_code),
                       EDCS_PrintUnitScaleCode
                       (mapping_entry->facc_target_scale_code));
            }
        }
        else if (mapping_entry->mapping_type == FACC_MAP_TYP_ONE_TO_ZERO)
        {
            printf("Mapping for EDCS Attribute %s was ONE_TO_ZERO:\n",
                     EDCS_PrintAttributeCode(ea_code));
        }
        else if (mapping_entry->mapping_type == FACC_MAP_TYP_SPECIAL_CASE)
        {
            printf("Mapping for EDCS Attribute %s was SPECIAL_CASE:\n",
                    EDCS_PrintAttributeCode(ea_code));

            if (mapping_entry->facc_attribute_code.tag[0] != '\0')
            {
                printf("\t     FACC Attribute: %c%c%c\n",
                       mapping_entry->facc_attribute_code.tag[0],
                       mapping_entry->facc_attribute_code.tag[1],
                       mapping_entry->facc_attribute_code.tag[2]);

                printf("\t    FACC Value Type: %s\n",
                       EDCS_to_FACC_PrintFACCValueType
                       (mapping_entry->facc_target_value_type));

                if (mapping_entry->facc_target_unit_code != 0)
                {
                    printf("\t FACC Expected Unit: %s\n"
                           "\tFACC Expected Scale: %s\n",
                           EDCS_PrintUnitCode
                           (mapping_entry->facc_target_unit_code),
                           EDCS_PrintUnitScaleCode
                           (mapping_entry->facc_target_scale_code));
                }
            }

        }
        else if (mapping_entry->mapping_type == FACC_MAP_TYP_MAP_TO_CODED)
        {
            printf("Mapping for EDCS Attribute %s was MAP TO CODED.  "\
              "This means that it maps to a FACC attribute of type CODED,"\
              " where each enumerant typically represents a ranged value."\
              " Use map_EDCS_attribute_value to test specific "\
              "interval mappings.\n",
                             EDCS_PrintAttributeCode(ea_code));

            if (mapping_entry->facc_attribute_code.tag[0] != '\0')
            {
                printf("\t     FACC Attribute: %c%c%c\n",
                       mapping_entry->facc_attribute_code.tag[0],
                       mapping_entry->facc_attribute_code.tag[1],
                       mapping_entry->facc_attribute_code.tag[2]);

                printf("\t    FACC Value Type: %s\n",
                       EDCS_to_FACC_PrintFACCValueType
                       (mapping_entry->facc_target_value_type));

                if (mapping_entry->facc_target_unit_code != 0)
                {
                    printf("\t FACC Expected Unit: %s\n"
                           "\tFACC Expected Scale: %s\n",
                           EDCS_PrintUnitCode
                           (mapping_entry->facc_target_unit_code),
                           EDCS_PrintUnitScaleCode
                           (mapping_entry->facc_target_scale_code));
                }
            }

        }
        else if (mapping_entry->mapping_type == FACC_MAP_TYP_INDETERMINATE)
        {
            printf("Mapping for EDCS Attribute %s was INDETERMINATE.  "\
               "This means that it maps to different FACC Attributes "\
               "depending on the value associated with it. The mapping for "\
               "non-interval and non-metadata values is:\n",
               EDCS_PrintAttributeCode(ea_code));

            if (mapping_entry->facc_attribute_code.tag[0] != '\0')
            {
                printf("\t     FACC Attribute: %c%c%c\n",
                       mapping_entry->facc_attribute_code.tag[0],
                       mapping_entry->facc_attribute_code.tag[1],
                       mapping_entry->facc_attribute_code.tag[2]);

                printf("\t    FACC Value Type: %s\n",
                       EDCS_to_FACC_PrintFACCValueType
                       (mapping_entry->facc_target_value_type));

                if (mapping_entry->facc_target_unit_code != 0)
                {
                    printf("\t FACC Expected Unit: %s\n"\
                           "\tFACC Expected Scale: %s\n",
                           EDCS_PrintUnitCode
                           (mapping_entry->facc_target_unit_code),
                           EDCS_PrintUnitScaleCode
                           (mapping_entry->facc_target_scale_code));
                }
            }

        }

        if (mapping_entry->notes)
        {
            printf("\t      Mapping Notes: %s\n", mapping_entry->notes);
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_usage
 *
 *----------------------------------------------------------------------------
 */
void
print_usage
(
    void
)
{
    printf("\nUsage: map_EDCS_attribute concept1 concept2 ... conceptN\n"
  "\n"
  "Example:\n"
  "\n"
  "To retrieve mapping information for WIDTH and HEIGHT_ABOVE_SURFACE_LEVEL:\n"
  "\tmap_EDCS_attribute EAC_WIDTH EAC_HEIGHT_ABOVE_SURFACE_LEVEL\n"
  "\t  or\n"
  "\tmap_EDCS_attribute WIDTH HEIGHT_ABOVE_SURFACE_LEVEL\n\n");
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *----------------------------------------------------------------------------
 */
int
main
(
    int argc,
    char * argv[]
)
{
    fprintf(stderr, BaseToolString, ToolName, ToolVersionString,
            EdcsVersionString);

    if (argc < 2)
    {
        print_usage();
    }
    else
    {
        int i;
        EDCS_Attribute_Code ea_code;

        /* Have to initialize the mapping library before using it */
        EDCS_to_FACC_InitMappingInfo();

        for (i = 1; i < argc; i++)
        {
            if ((EDCS_LabelToEACode(argv[i], &ea_code) == EDCS_SC_SUCCESS)
             || (EDCS_SymbolicConstantToEACode(argv[i], &ea_code) ==
                 EDCS_SC_SUCCESS))
            {
                map_attribute_code((EDCS_Attribute_Code) ea_code);
            }
            else
            {
                fprintf(stderr,
                        "Unrecognized EDCS Attribute \"%s\", skipping.\n",
                        argv[i]);
            }
        } /* end for i */

        /* Have to shut it down as well */
        EDCS_to_FACC_ShutdownMappingInfo();
        printf("\n");
    }
    return 0;
} /* end main */
