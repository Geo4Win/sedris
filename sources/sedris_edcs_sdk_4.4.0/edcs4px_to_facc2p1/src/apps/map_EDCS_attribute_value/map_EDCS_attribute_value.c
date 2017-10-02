/*
 * FILE       : map_EDCS_attribute_value.c
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *     This program takes a series of EDCS 4.x attribute labels
 *     or symbolic constants in combination with values and prints
 *     out the mapping information to map to DIGEST FACC Edition 2.1.
 *
 * Usage:
 *
 *   map_EDCS_attribute_value "label1 value1" "label2 value2" "label3 value3"
 *                            ... "labelN valueN"
 *
 *      Where label can be an EDCS Attribute Label or Symbolic Constant
 *      and value can either be a string, interval, metadata symbolic constant,
 *      boolean, or a single integer or float value.
 *
 *      Interval syntax: [a, b] or (a, b] or [a, b) or (a, b) Units Scale
 *         Use EDCS_POSITIVE_INFINITY and EDCS_NEGATIVE_INFINITY to represent
 *         boundless intervals.
 *
 * Options: none
 *
 * examples:
 *
 *   To find mapping information for EDCS Attribute HEIGHT_ABOVE_SURFACE_LEVEL:
 *     map_EDCS_attribute_value "HEIGHT_ABOVE_SURFACE_LEVEL 10.0 EUC_METRE ESC_UNI"
 *
 *   To retrieve mapping information for HEIGHT_ABOVE_SURFACE_LEVEL and CAPACITY:
 *     map_EDCS_attribute_value "EAC_HEIGHT_ABOVE_SURFACE_LEVEL 10.0" "EAC_CAPACITY EVC_UNDESIGNATED"
 *      or
 *     map_EDCS_attribute_value "HEIGHT_ABOVE_SURFACE_LEVEL 10.0" "CAPACITY EVC_UNDESIGNATED"
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
#include <ctype.h>

#include "edcs.h"
#include "edcs4px_to_facc2p1.h"

const char *const EdcsVersionString = "4.4.x";
const char *const ToolName = "map_EDCS_attribute_value";
const char *const ToolVersionString = "4.4.0.0";
const char *const BaseToolString = "%s v%s\n    (compatible with EDCS SDK %s)\n\n\n";

/*
 * FUNCTION: print_usage
 */
static void
print_usage
(
    void
)
{
    printf(
 "\nUsage:\n"
 "map_EDCS_attribute_value \"label1 value1\" \"label2 value2\" \"label3 value3\" ... \"labelN valueN\"\n"
 "\n"
 "   ***IMPORTANT - Each label value pair MUST be enclosed in quotation marks.***\n"
 "\n"
 "   The label string can be either EDCS Attribute Symbolic Constant or Label\n"
 "   The syntax of the value string can one of the following: \n"
 "      \n"
 "    - Interval syntax: interval unit scale\n"
 "                       where interval can be: [a, b] or (a, b] or [a, b) or (a, b)\n"
 "                       and unit and scale are both symbolic constants (ie EUC_METRE ESC_UNI)\n"
 "                       Use EDCS_POSITIVE_INFINTY and EDCS_NEGATIVE_INFINITY to represent\n"
 "                       boundless intervals.\n"
 "\n"
 "    -  Boolean syntax: EDCS_TRUE or EDCS_FALSE\n"
 "\n"
 "    - Metadata syntax: metadata symbolic constant (ie EVC_UNDESIGNATED)\n"
 "\n"
 "    -    Single Value: value (float or integer) unit scale\n"
 "                       where unit and scale are both symbolic constants (ie EUC_METRE ESC_UNI)\n"
 "\n"
 " Options: none\n"
 "\n"
 "Example:\n"
 "\n"
 "   To find mapping information for EDCS Attribute HEIGHT_ABOVE_SURFACE_LEVEL with a value of 10 metres:\n"
 "     map_EDCS_attribute_value \"EAC_HEIGHT_ABOVE_SURFACE_LEVEL 10.0 EUC_METRE ESC_UNI\"\n"
 "\n"
 "   To retrieve mapping information for BRUSH_DENSITY with an interval of [0.0, 5.0] percent\n"
 "     map_EDCS_attribute_value \"EAC_BRUSH_DENSITY [0.0, 5.0] EUC_PERCENT ESC_UNI\"\n"
 "\n"
 "   To retrieve mapping information for CAPACITY with the metadata value UNDESIGNATED\n"
 "     map_EDCS_attribute_value \"CAPACITY EVC_UNDESIGNATED\" \n"
 "\n"
 "   To retrieve multiple mappings:\n"
 "     map_EDCS_attribute_value \"EAC_BRUSH_DENSITY [0.0, 5.0] EUC_PERCENT ESC_UNI\" \"CAPACITY EVC_UNDESIGNATED\"\n"
 "\n");

} /* end print_usage */

void
map_attribute_value
(
    EDCS_Attribute_Code         ea_code_to_map,
    EDCS_Attribute_Value_Entry *value_to_map
)
{
    FACC_Attribute_With_Value_Mapping_Structure mapping_entry;
    EDCS_Status_Code                            status;

    if (value_to_map->is_ev == EDCS_TRUE)
    {
        printf("ev_code = %s\n",
               EDCS_PrintValueCharacteristicCode(value_to_map->u.ev_code));
    }
    else
    {
        EDCS_PrintAttributeValue
        (ea_code_to_map,
         &(value_to_map->u.ea_value),
         "value_to_map",
         1);
    }

    if ((status=EDCS_to_FACC_MapAttributeWithValue(ea_code_to_map,
                     value_to_map, &mapping_entry)) == EDCS_SC_SUCCESS)
    {
        switch (mapping_entry.mapping_type)
        {
            case FACC_MAP_TYP_INDETERMINATE:
            case FACC_MAP_TYP_MAP_TO_CODED:
            case FACC_MAP_TYP_ONE_TO_ONE:
            case FACC_MAP_TYP_SPECIAL_CASE:
            {
                printf("Mapping was %s:\n",
                        EDCS_to_FACC_PrintMappingType(mapping_entry.mapping_type));

                printf("\tFACC Attribute: %c%c%c\n",
                       mapping_entry.facc_attribute_with_value.facc_attribute_code.tag[0],
                       mapping_entry.facc_attribute_with_value.facc_attribute_code.tag[1],
                       mapping_entry.facc_attribute_with_value.facc_attribute_code.tag[2]);

                printf("\tFACC Value Type: %s\n",
                       EDCS_to_FACC_PrintFACCValueType
                       (mapping_entry.facc_attribute_with_value.value_type));

                switch (mapping_entry.facc_attribute_with_value.value_type)
                {
                    case FACC_VAL_TYP_CODED:
                        printf("\tFACC Coded Value: %d\n",
                               mapping_entry.facc_attribute_with_value.u.facc_coded_value);
                        break;
                    case FACC_VAL_TYP_SHORT_INTEGER:
                        printf("\tFACC Short Integer Value: %d\n",
                               mapping_entry.facc_attribute_with_value.u.facc_short_integer_value);
                        break;
                    case FACC_VAL_TYP_LONG_INTEGER:
                        printf("\tFACC Long Integer Value: %d\n",
                               mapping_entry.facc_attribute_with_value.u.facc_long_integer_value);
                        break;
                    case FACC_VAL_TYP_FLOAT:
                        printf("\tFACC Float Value: %f\n",
                               mapping_entry.facc_attribute_with_value.u.facc_float_value);
                        break;
                    case FACC_VAL_TYP_TEXT:
                        printf("\tFACC Text Value: %s\n",
                               mapping_entry.facc_attribute_with_value.u.facc_text_value);
                        break;
                    default:
                        break;
                }

                if (mapping_entry.notes)
                {
                    fflush(stdout);
                    printf("\tNotes: %s\n", mapping_entry.notes);
                }
                break;
            }
            case FACC_MAP_TYP_ONE_TO_ZERO:
            {
                printf("Mapping was ONE to ZERO\n");

                if (mapping_entry.notes)
                {
                    printf("\tNotes: %s\n", mapping_entry.notes);
                }
                else
                {
                    printf("\tNo notes.\n");
                }
                fflush(stdout);
                break;
            }
            default:
            {
                fprintf(stderr, "Unexpected mapping type: %s\n",
                        EDCS_to_FACC_PrintMappingType(mapping_entry.mapping_type));
                fflush(stderr);
                break;
            }
        }
        printf("\n");
        fflush(stdout);
    }
    else
    {
        fprintf(stderr, "MapAttributeWithValue call FAILED (%s).\n",
                EDCS_PrintStatusCode(status));
        fflush(stderr);
    }
} /* end map_attribute_value */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: map_numeric_value
 *
 *----------------------------------------------------------------------------
 */
static EDCS_Status_Code
map_numeric_value
(
    int                        *i_ptr,
    int                         argc,
    char                      **argv,
    EDCS_Attribute_Value_Type   ea_value_type,
    EDCS_Attribute_Value       *value_to_map
)
{
    EDCS_Status_Code         status = EDCS_SC_SUCCESS;
    char                    *lower_bound, *upper_bound;
    EDCS_Numeric_Value_Type  interval_type = EDCS_NVT_SINGLE_VALUE;
    EDCS_Boolean             lower_closed, upper_closed;
    int                      i;

    value_to_map->attribute_value_type = ea_value_type;

    i = *i_ptr;
   /*
    * parse interval brackets
    */
    if (argv[i][0] == '[' || argv[i][0] == '(')
    {
        if (argv[i][0] == '[')
        {
            lower_closed = EDCS_TRUE;
        }
        else
        {
            lower_closed = EDCS_FALSE;
        }
        lower_bound = argv[i];
        lower_bound++;

        if (strrchr(argv[i], ')') != NULL ||
            strrchr(argv[i], ']') != NULL)
        {
            upper_bound = strchr(argv[i], ',');
            upper_bound[0] = '\0';
            upper_bound++;

            if (upper_bound[strlen(upper_bound)-1] == ']')
            {
                upper_closed = EDCS_TRUE;
            }
            else
            {
                upper_closed = EDCS_FALSE;
            }
            upper_bound[strlen(upper_bound)-1] = '\0';
        }
        else
        {
            if (lower_bound[strlen(lower_bound)-1] == ',')
            {
                lower_bound[strlen(lower_bound)-1] = '\0';
            }
            i++;

            if ((i == argc) || (strlen(argv[i]) < 2))
            {
                *i_ptr = i;
                status = EDCS_SC_OTHER_FAILURE;
            }
            else
            {
                upper_bound = argv[i];

                if (upper_bound[0] == ',')
                {
                    upper_bound++;
                }

                if (upper_bound[strlen(upper_bound)-1] == ']')
                {
                    upper_closed = EDCS_TRUE;
                }
                else
                {
                    upper_closed = EDCS_FALSE;
                }
                upper_bound[strlen(upper_bound)-1] = '\0';
            }
        }

        if ((lower_closed && (!strcmp(lower_bound,"EDCS_NEGATIVE_INFINITY")))
         || (upper_closed && (!strcmp(upper_bound,"EDCS_POSITIVE_INFINITY"))))
        {
            status = EDCS_SC_OTHER_FAILURE;
        }

        if (status != EDCS_SC_SUCCESS)
        {
            fprintf(stderr, "Error in mapping syntax, "\
                    "incorrect interval (no upper bound)\n");
            return status;
        }

        if (upper_closed)
        {
            if (lower_closed)
            {
                if (!strcmp(upper_bound, "EDCS_POSITIVE_INFINITY"))
                {
                    interval_type = EDCS_NVT_GE_SEMI_INTERVAL;
                }
                else
                {
                    interval_type = EDCS_NVT_CLOSED_INTERVAL;
                }
            }
            else
            {
                if (!strcmp(lower_bound, "EDCS_NEGATIVE_INFINITY"))
                {
                    interval_type = EDCS_NVT_LE_SEMI_INTERVAL;
                }
                else
                {
                    interval_type = EDCS_NVT_GT_LE_INTERVAL;
                }
            }
        }
        else
        {
            if (lower_closed)
            {
                if (!strcmp(upper_bound, "EDCS_POSITIVE_INFINITY"))
                {
                    interval_type = EDCS_NVT_GE_SEMI_INTERVAL;
                }
                else
                {
                    interval_type = EDCS_NVT_GE_LT_INTERVAL;
                }
            }
            else
            {
                if (!strcmp(upper_bound, "EDCS_POSITIVE_INFINITY"))
                {
                    interval_type = EDCS_NVT_GT_SEMI_INTERVAL;
                }
                else
                {
                    interval_type = EDCS_NVT_OPEN_INTERVAL;
                }
            }
        }

        /*
         * We now have our upper and lower bounds and
         * interval type
         */

        /*
         * decimals indicate float, everything else is integer
         */
        if (strchr(upper_bound, '.') ||
            strchr(lower_bound, '.'))
        {
            if (value_to_map->attribute_value_type != EDCS_AVT_REAL)
            {
                fprintf(stderr, "Error in mapping syntax, map_numeric_value: "\
                        "real value supplied for non-real attribute\n");
                fflush(stderr);
                return EDCS_SC_OTHER_FAILURE;
            }
         }
    }
    else
    {
        if (strchr(argv[i], '.') != NULL)
        {
            if (value_to_map->attribute_value_type != EDCS_AVT_REAL)
            {
                fprintf(stderr, "Error in mapping syntax, map_numeric_value: "\
                        "real value supplied for non-real attribute\n");
                fflush(stderr);
                return EDCS_SC_OTHER_FAILURE;
            }
        }
    }
    value_to_map->value.real_value.numeric_value_type = interval_type;

    if (value_to_map->attribute_value_type ==EDCS_AVT_REAL)
    {
        switch (value_to_map->value.real_value.numeric_value_type)
        {
              case EDCS_NVT_SINGLE_VALUE:
                   sscanf(argv[i], "%lf",
                          &(value_to_map->value.real_value.value.single_value));
                   break;
              case EDCS_NVT_OPEN_INTERVAL:
                   sscanf(lower_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.open_interval.lower_bound));
                   sscanf(upper_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.open_interval.upper_bound));
                   break;
              case EDCS_NVT_GE_LT_INTERVAL:
                   sscanf(lower_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.ge_lt_interval.lower_bound));
                   sscanf(upper_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.ge_lt_interval.upper_bound));
                   break;
              case EDCS_NVT_GT_LE_INTERVAL:
                   sscanf(lower_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.gt_le_interval.lower_bound));
                   sscanf(upper_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.gt_le_interval.upper_bound));
                   break;
              case EDCS_NVT_CLOSED_INTERVAL:
                   sscanf(lower_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.closed_interval.lower_bound));
                   sscanf(upper_bound, "%lf",
                          &(value_to_map->value.real_value.
                          value.closed_interval.upper_bound));
                   break;
              case EDCS_NVT_GT_SEMI_INTERVAL:
                   sscanf(lower_bound, "%lf",
                      &(value_to_map->value.real_value.value.gt_semi_interval));
                   break;
              case EDCS_NVT_GE_SEMI_INTERVAL:
                   sscanf(lower_bound, "%lf",
                      &(value_to_map->value.real_value.value.ge_semi_interval));
                   break;
              case EDCS_NVT_LT_SEMI_INTERVAL:
                   sscanf(upper_bound, "%lf",
                      &(value_to_map->value.real_value.value.lt_semi_interval));
                   break;
              case EDCS_NVT_LE_SEMI_INTERVAL:
                   sscanf(upper_bound, "%lf",
                      &(value_to_map->value.real_value.value.le_semi_interval));
                   break;
              default:
                   status = EDCS_SC_OTHER_FAILURE;
                   break;
        } /* end switch */

        /* now the next two argv should be unit then scale */
        i++;

        if (i == argc)
        {
            fprintf(stderr, "Error in mapping syntax, "\
                    "incorrect interval "\
                    "(no unit or scale present)\n");
            *i_ptr = i;
            return EDCS_SC_OTHER_FAILURE;
        }

        status = EDCS_SymbolicConstantToEUCode
                      (argv[i], &value_to_map->value.real_value.unit);
        if (status != EDCS_SC_SUCCESS)
        {
            fprintf(stderr, "Unrecognized EDCS Unit \"%s\", skipping.\n",
                    argv[i]);
            i=argc;
        }
        else
        {
            i++;
            if (i == argc)
            {
                fprintf(stderr, "Error in mapping syntax, "\
                        "incorrect interval (no scale present)\n");
                status = EDCS_SC_OTHER_FAILURE;
            }
            else
            {
                if (argv[i][strlen(argv[i])-1] == ',')
                {
                    argv[i][strlen(argv[i])-1] = '\0';
                }

                status = EDCS_SymbolicConstantToESCode
                         (argv[i], &value_to_map->value.real_value.unit_scale);
                if (status != EDCS_SC_SUCCESS)
                {
                    fprintf(stderr,
                            "Unrecognized EDCS Scale \"%s\", skipping.\n",
                            argv[i]);
                    i=argc;
                } /* end if - scale not recognized */
            } /* end if - scale missing */
        } /* end if - unit not recognized */
    }
    else
    {
        value_to_map->attribute_value_type = EDCS_AVT_INTEGER;
        value_to_map->value.integer_value.numeric_value_type = interval_type;
        switch (value_to_map->value.integer_value.numeric_value_type)
        {
              case EDCS_NVT_SINGLE_VALUE:
                   sscanf(argv[i], "%ld",
                          &(value_to_map->value.integer_value.value.single_value));
                   break;
              case EDCS_NVT_OPEN_INTERVAL:
                   sscanf(lower_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.open_interval.lower_bound));
                   sscanf(upper_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.open_interval.upper_bound));
                   break;
              case EDCS_NVT_GE_LT_INTERVAL:
                   sscanf(lower_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.ge_lt_interval.lower_bound));
                   sscanf(upper_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.ge_lt_interval.upper_bound));
                   break;
              case EDCS_NVT_GT_LE_INTERVAL:
                   sscanf(lower_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.gt_le_interval.lower_bound));
                   sscanf(upper_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.gt_le_interval.upper_bound));
                   break;
              case EDCS_NVT_CLOSED_INTERVAL:
                   sscanf(lower_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.closed_interval.lower_bound));
                   sscanf(upper_bound, "%ld",
                          &(value_to_map->value.integer_value.
                          value.closed_interval.upper_bound));
                   break;
              case EDCS_NVT_GT_SEMI_INTERVAL:
                   sscanf(lower_bound, "%ld",
                          &(value_to_map->value.integer_value.value.gt_semi_interval));
                   break;
              case EDCS_NVT_GE_SEMI_INTERVAL:
                   sscanf(lower_bound, "%ld",
                          &(value_to_map->value.integer_value.value.ge_semi_interval));
                   break;
              case EDCS_NVT_LT_SEMI_INTERVAL:
                   sscanf(upper_bound, "%ld",
                          &(value_to_map->value.integer_value.value.lt_semi_interval));
                   break;
              case EDCS_NVT_LE_SEMI_INTERVAL:
                   sscanf(upper_bound, "%ld",
                          &(value_to_map->value.integer_value.value.le_semi_interval));
                   break;
              default:
                   status = EDCS_SC_OTHER_FAILURE;
                   break;
        } /* end switch */
    }
    *i_ptr = i;
    return status;
} /* end map_numeric_value */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_arguments
 *
 *----------------------------------------------------------------------------
 */
static void
process_arguments
(
    int    m_argc,
    char * m_argv[]
)
{
    if (m_argc < 2)
    {
        print_usage();
        exit(-1);
    }
    EDCS_to_FACC_InitMappingInfo();
} /* end process_arguments */


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
    int    m_argc,
    char * m_argv[]
)
{
    char                       *argv[256];
    int                         argc = 1, i, j;
    EDCS_Attribute_Code         ea_code_to_map;
    EDCS_Attribute_Value_Entry  value_to_map;

    fprintf(stderr, BaseToolString, ToolName, ToolVersionString,
            EdcsVersionString);

    process_arguments(m_argc, m_argv);

    /*
     * each m_argv is an entire mapping line
     * this is in turn broken up in the argv[]
     * with each separate component of the mapping line
     */
    for (j = 1; j < m_argc; j++, argc = 1)
    {
        if (m_argv[j][strlen(m_argv[j])-1] == ',')
        {
            m_argv[j][strlen(m_argv[j])-1] = '\0';
        }
        printf("\nMapping %d: \"%s\"\n", j, m_argv[j]);

        argv[0] = strtok(m_argv[j], " ");

        while ((argv[argc++] = strtok(NULL, " ")) != NULL);
        argc--;

        /*
         * first value of list has to be EA Label or Symbolic Constant
         * second value will be one of the following:
         *
         *   Interval: [a, b] or (a, b] or [a, b) or (a, b)
         *             (EDCS_POSITIVE_INFINITY/EDCS_NEGATIVE_INFINTY for
         *              boundless)
         *   Boolean: EDCS_TRUE or EDCS_FALSE
         *   Metadata: EVC_ Symbolic Constants ONLY.
         *      No way to tell if label is supposed to be text or
         *      metadata
         * Integer/Float Value:
         *    Single value, determine if it is float
         *    if a decimal point is found
         *
         * We will not handle enumerations here;
         *    map_EDCS_enumerant serves that purpose
         */

        /* each argc will have the entire mapping in place. */
        for (i = 0; i < argc; i++)
        {
            if (EDCS_LabelToEACode(argv[i], &ea_code_to_map) == EDCS_SC_SUCCESS
             || EDCS_SymbolicConstantToEACode(argv[i], &ea_code_to_map)
                == EDCS_SC_SUCCESS)
            {
                const EDCS_Attribute_Dictionary_Entry *ea_entry = NULL;

                i++;

                if (i == argc)
                {
                    fprintf(stderr, "Error in mapping syntax, "\
                            "no value for attribute %s\n",
                            EDCS_PrintAttributeCode(ea_code_to_map));
                    continue;
                }
                else if (EDCS_GetEADictionaryEntry(ea_code_to_map, &ea_entry)
                         != EDCS_SC_SUCCESS)
                {
                    fprintf(stderr, "EDCS_GetEADictionaryEntry failed to "\
                            "fetch attribute_value_type for attribute %s\n",
                            EDCS_PrintAttributeCode(ea_code_to_map));
                    continue;
                }
                else
                {
                    value_to_map.u.ea_value.attribute_value_type = ea_entry->value_type;
                }

                if (argv[i][strlen(argv[i])-1] == ',')
                {
                    argv[i][strlen(argv[i])-1] = '\0';
                }

                if (strstr(argv[i], "EDCS_TRUE") != NULL)
                {
                    if (value_to_map.u.ea_value.attribute_value_type
                        != EDCS_AVT_BOOLEAN)
                    {
                        fprintf(stderr, "Error in mapping syntax: %s requires"\
                          "a value type of %s, not Boolean\n",
                          EDCS_PrintAttributeCode(ea_code_to_map),
                          EDCS_PrintAttributeValueType(ea_entry->value_type));
                    }
                    value_to_map.is_ev = EDCS_FALSE;
                    value_to_map.u.ea_value.value.boolean_value = EDCS_TRUE;
                }
                else if (strstr(argv[i], "EDCS_FALSE") != NULL)
                {
                    if (value_to_map.u.ea_value.attribute_value_type
                        != EDCS_AVT_BOOLEAN)
                    {
                        fprintf(stderr, "Error in mapping syntax: %s requires"\
                          "a value type of %s, not Boolean\n",
                          EDCS_PrintAttributeCode(ea_code_to_map),
                          EDCS_PrintAttributeValueType(ea_entry->value_type));
                    }
                    value_to_map.is_ev = EDCS_FALSE;
                    value_to_map.u.ea_value.value.boolean_value = EDCS_FALSE;
                }
                else if (strstr(argv[i], "EVC_") != NULL)
                {
                    value_to_map.is_ev = EDCS_TRUE;
                    if (EDCS_SymbolicConstantToEVCode(argv[i],
                        &value_to_map.u.ev_code) != EDCS_SC_SUCCESS)
                    {
                        fprintf(stderr,
                          "Unrecognized EDCS Value Characteristic \"%s\", "\
                          "skipping mapping.\n", argv[i]);
                        i=argc;
                        continue;
                    }
                }
                else if (isalpha(argv[i][0]))
                {
                    if (value_to_map.u.ea_value.attribute_value_type
                             == EDCS_AVT_ENUMERATION)
                    {
                        fprintf(stderr, "Error in mapping syntax: %s requires"\
                                " a value type of ENUMERATION; use"\
                                " map_EDCS_enumerant instead\n",
                          EDCS_PrintAttributeCode(ea_code_to_map));
                        continue;
                    }
                    else if ((value_to_map.u.ea_value.attribute_value_type
                         != EDCS_AVT_CONSTRAINED_STRING)
                     || (value_to_map.u.ea_value.attribute_value_type
                         != EDCS_AVT_KEY)
                     || (value_to_map.u.ea_value.attribute_value_type
                         != EDCS_AVT_STRING))
                    {
                        fprintf(stderr, "Error in mapping syntax: %s requires"\
                          "a value type of %s, not String\n",
                          EDCS_PrintAttributeCode(ea_code_to_map),
                          EDCS_PrintAttributeValueType(ea_entry->value_type));
                        continue;
                    }
                    value_to_map.is_ev = EDCS_FALSE;
                    value_to_map.u.ea_value.value.string_value =
                         EDCS_STRING_DEFAULT;
                    value_to_map.u.ea_value.value.string_value.characters =
                         argv[i];
                    value_to_map.u.ea_value.value.string_value.length =
                         strlen(argv[i]);
                }
                else
                {
                    if ((value_to_map.u.ea_value.attribute_value_type
                         == EDCS_AVT_BOOLEAN)
                     || (value_to_map.u.ea_value.attribute_value_type
                         == EDCS_AVT_CONSTRAINED_STRING)
                     || (value_to_map.u.ea_value.attribute_value_type
                         == EDCS_AVT_KEY)
                     || (value_to_map.u.ea_value.attribute_value_type
                         == EDCS_AVT_STRING))
                    {
                        fprintf(stderr, "Error in mapping syntax: %s requires"\
                          "a value type of %s, not a numeric value type\n",
                          EDCS_PrintAttributeCode(ea_code_to_map),
                          EDCS_PrintAttributeValueType(ea_entry->value_type));
                        continue;
                    }
                    else if (value_to_map.u.ea_value.attribute_value_type
                             == EDCS_AVT_ENUMERATION)
                    {
                        fprintf(stderr, "Error in mapping syntax: %s requires"\
                                " a value type of ENUMERATION; use"\
                                " map_EDCS_enumerant instead\n",
                          EDCS_PrintAttributeCode(ea_code_to_map));
                        continue;
                    }
                    value_to_map.is_ev = EDCS_FALSE;
                    map_numeric_value
                    (
                        &i,
                        argc,
                        argv,
                        ea_entry->value_type,
                       &(value_to_map.u.ea_value)
                    );
                }
                map_attribute_value(ea_code_to_map, &value_to_map);
            }
            else
            {
                fprintf(stderr,
                        "Unrecognized EDCS Attribute \"%s\", skipping.\n",
                        argv[i]);
                i=argc;
                continue;
            }
        }
    }
    printf("\n");
    EDCS_to_FACC_ShutdownMappingInfo();
    return 0;
} /* end main */
