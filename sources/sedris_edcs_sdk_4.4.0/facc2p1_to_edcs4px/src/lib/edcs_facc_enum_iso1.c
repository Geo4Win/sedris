/*
 * FILE: edcs_facc_enum_iso1.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * FACC 2.1 to EDCS 4.4 Mapping SDK Release 4.4.0.0 - July 1, 2011
 * - EDCS spec. 4.4
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
/*
 * disabling 4305 kills the EDCS_Float value = 3.9;
 * truncation of const double warning
 *
 * disabling 4244 kills the warning when assigning
 * EDCS_POS_INFINITY which is defined as an EDCS_Float
 * to an unsigned int.
 *
 * disabling 4049 kills the "terminating line number
 * emission" warning.
 */
#pragma warning ( disable : 4305 4244 4049 )
#endif

#include "facc2p1_to_edcs4px.h"

/*
 * STRUCT: EDCS_FACC_2p1_Enumerant_Mapping
 *
 *   Relates a 2.1 FACC Attribute code and 2.1 FACC Attribute Enumerant to its
 *   EDCS 4.x mapping.
 */
typedef struct
{
    FACC_2p1_Attribute_Code              code;
    FACC_2p1_Attribute_Integer_Code      enum_val;
    FACC_2p1_Enumerant_Mapping_Structure entry;
} EDCS_FACC_2p1_Enumerant_Mapping;

extern EDCS_FACC_2p1_Enumerant_Mapping EDCS_FACC_2p1_Enumerant_Mapping_Array[];

EDCS_Status_Code
local_init_facc_attribute_enum_mapping_pt1( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[0].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[0].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].entry.ee_code = EEC_LOCACCSTMT_ACCURATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].entry.ee_code = EEC_LOCACCSTMT_APPROXIMATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].entry.ee_code = EEC_LOCACCSTMT_DOUBTFUL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].entry.ee_code = EEC_LOCACCSTMT_DISPUTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].entry.ee_code = EEC_LOCACCSTMT_UNDISPUTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].entry.ee_code = EEC_LOCACCSTMT_PRECISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[7].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].entry.ee_code = EEC_LOCACCSTMT_INACCURATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[7].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[8].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[8].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[9].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[9].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[10].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[10].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[11].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[11].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[12].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[12].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[13].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].entry.ee_code = EEC_AVAILFACTY_VISITORS_BERTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[13].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[14].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].entry.ee_code = EEC_AVAILFACTY_VISITORS_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[14].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[15].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].entry.ee_code = EEC_AVAILFACTY_SAILMAKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[15].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[16].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].entry.ee_code = EEC_AVAILFACTY_CHANDLER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[16].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[17].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].entry.ee_code = EEC_AVAILFACTY_PROVISIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[17].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[18].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].entry.ee_code = EEC_AVAILFACTY_HEALTH_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[18].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[19].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].entry.ee_code = EEC_AVAILFACTY_PHARMACY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[19].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[20].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].entry.ee_code = EEC_AVAILFACTY_FRESH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[20].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[21].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].entry.ee_code = EEC_AVAILFACTY_FUEL_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[21].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[22].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].entry.ee_code = EEC_AVAILFACTY_ELECTRICITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[22].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[23].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].entry.ee_code = EEC_AVAILFACTY_BOTTLE_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[23].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[24].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].entry.ee_code = EEC_AVAILFACTY_SHOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[24].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[25].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].entry.ee_code = EEC_AVAILFACTY_LAUNDERETTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[25].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[26].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].entry.ee_code = EEC_AVAILFACTY_PUBLIC_TOILET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[26].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[27].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].entry.ee_code = EEC_AVAILFACTY_POSTBOX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[27].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[28].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].entry.ee_code = EEC_AVAILFACTY_PUBLIC_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[28].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[29].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].entry.ee_code = EEC_AVAILFACTY_REFUSE_BIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[29].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[30].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].entry.ee_code = EEC_AVAILFACTY_MARINE_POLICE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[30].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[31].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].entry.ee_code = EEC_AVAILFACTY_HELIPAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[31].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[32].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].entry.ee_code = EEC_AVAILFACTY_TICKET_SALE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[32].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[33].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].entry.information = "Deleted: \"No Ticket Sales\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[33].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[34].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].entry.ee_code = EEC_AVAILFACTY_NAUTICAL_CLUB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[34].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[35].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].entry.ee_code = EEC_AVAILFACTY_BOAT_LIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[35].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[36].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].entry.ee_code = EEC_AVAILFACTY_SHIPYARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[36].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[37].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].entry.ee_code = EEC_AVAILFACTY_HOTEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[37].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[38].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].entry.ee_code = EEC_AVAILFACTY_RESTAURANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[38].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[39].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].entry.ee_code = EEC_AVAILFACTY_DESALINATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[39].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[40].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].entry.ee_code = EEC_AVAILFACTY_VEHICLE_LOT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[40].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[41].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].entry.ee_code = EEC_AVAILFACTY_PARKING_FOR_BOATS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[41].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[42].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].entry.ee_code = EEC_AVAILFACTY_RECREATIONAL_VEHICLE_PARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[42].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[43].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].entry.ee_code = EEC_AVAILFACTY_CAMPGROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[43].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[44].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].entry.ee_code = EEC_AVAILFACTY_SEWAGE_PUMP_OUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[44].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[45].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].entry.ee_code = EEC_AVAILFACTY_EMERGENCY_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[45].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[46].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].entry.ee_code = EEC_AVAILFACTY_BOAT_RAMP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[46].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[47].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].entry.ee_code = EEC_AVAILFACTY_SCRUBBING_BERTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[47].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[48].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].entry.ee_code = EEC_AVAILFACTY_PICNIC_TRACT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[48].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[49].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].entry.ee_code = EEC_AVAILFACTY_REPAIR_BUILDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[49].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[50].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].entry.ee_code = EEC_AVAILFACTY_SECURITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[50].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[51].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[51].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[52].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].enum_val = 995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].entry.ee_code = EEC_AVAILFACTY_NONE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[52].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[53].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[53].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[54].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[54].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[55].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[55].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[56].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[56].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[57].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].entry.ee_code = EEC_ARRESTGEARTY_NET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[57].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[58].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].entry.ee_code = EEC_ARRESTGEARTY_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[58].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[59].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].entry.ee_code = EEC_ARRESTGEARTY_JET_BARRIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[59].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[60].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[60].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[61].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[61].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[62].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[62].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[63].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[63].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[64].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[64].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[65].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].entry.ee_code = EEC_INLHYDRGPERM_PERENNIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[65].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[66].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].entry.ee_code = EEC_INLHYDRGPERM_INTERMITTENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[66].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[67].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].entry.ee_code = EEC_INLHYDRGPERM_EPHEMERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[67].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[68].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[68].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[69].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[69].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[70].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[70].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[71].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[71].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[72].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERODROME_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[72].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[73].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].entry.ee_code = EEC_AERODTY_MAJOR_AERODROME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[73].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[74].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].entry.ee_code = EEC_AERODTY_MINOR_AERODROME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[74].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[75].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].entry.ee_code = EEC_AERODTY_GENERAL_AVIATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[75].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[76].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].entry.ee_code = EEC_AERODTY_SEAPLANE_BASE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[76].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[77].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].entry.ee_code = EEC_AERODTY_GLIDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[77].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[78].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].entry.ee_code = EEC_AERODTY_MICROLIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[78].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[79].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].entry.ee_code = EEC_AERODTY_HANG_GLIDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[79].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[80].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].entry.ee_code = EEC_AERODTY_WINCH_LAUNCHED_HANG_GLIDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[80].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[81].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].entry.ee_code = EEC_AERODTY_HELIPORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[81].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[82].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].entry.ee_code = EEC_AERODTY_HELICOPTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[82].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[83].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].entry.ee_code = EEC_AERODTY_HELIPORT_AT_HOSPITAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[83].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[84].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].entry.ee_code = EEC_AERODTY_EMERGENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[84].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[85].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].entry.ee_code = EEC_AERODTY_PARASCENDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[85].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[86].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].entry.ee_code = EEC_AERODTY_AERODROME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[86].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[87].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].entry.ee_code = EEC_AERODTY_UNDEFINED_LANDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[87].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[88].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERODROME_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[88].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[89].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERODROME_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[89].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[90].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERODROME_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[90].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[91].code.tag, "APT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERODROME_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[91].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[92].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[92].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[93].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].entry.information = "<= 3 048 metres (10 000 feet).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 3048.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[93].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[94].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].entry.information = "> 3 048 metres (10 000 feet) and <= 6 096 metres (20 000 feet).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 3048.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 6096.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[94].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[95].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].entry.information = "> 6 096 metres (20 000 feet) and <= 9 144 metres (30 000 feet).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 6096.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 9144.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[95].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[96].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].entry.information = "> 9 144 metres (30 000 feet) and <= 12 899,75 metres (42 332 feet).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 9144.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 12899.75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[96].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[97].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[97].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[98].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[98].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[99].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[99].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[100].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AQUEDUCT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[100].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[101].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].entry.ea_code = EAC_AQUEDUCT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].entry.ee_code = EEC_AQUETY_QANAT_SHAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[101].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[102].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AQUEDUCT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[102].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[103].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].entry.ea_code = EAC_AQUEDUCT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].entry.ee_code = EEC_AQUETY_UNDERGROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[103].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[104].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AQUEDUCT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[104].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[105].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AQUEDUCT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[105].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[106].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AQUEDUCT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[106].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[107].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AQUEDUCT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[107].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[108].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[108].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[109].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].entry.ee_code = EEC_ATSRTECMPTLEV_BOTH_195;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[109].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[110].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].entry.ee_code = EEC_ATSRTECMPTLEV_ABOVE_195;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[110].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[111].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].entry.ee_code = EEC_ATSRTECMPTLEV_BELOW_195;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[111].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[112].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].entry.ee_code = EEC_ATSRTECMPTLEV_ABOVE_245;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[112].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[113].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[113].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[114].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[114].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[115].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[115].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[116].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[116].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[117].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[117].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[118].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].entry.ee_code = EEC_AIDNAVSTAT_MARKED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[118].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[119].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].entry.ee_code = EEC_AIDNAVSTAT_UNMARKED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[119].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[120].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].entry.ee_code = EEC_AIDNAVSTAT_LIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[121].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].entry.ee_code = EEC_AIDNAVSTAT_UNLIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[122].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[122].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[123].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[123].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[124].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[124].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[125].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[125].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[126].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_USE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[126].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[127].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].entry.ee_code = EEC_ATSUSETY_AIR_DEFENCE_ADVISORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[127].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[128].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].entry.ee_code = EEC_ATSUSETY_AIR_DEFENCE_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[129].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].entry.ee_code = EEC_ATSUSETY_ARTCC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[129].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[130].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].entry.ee_code = EEC_ARSPCLIMIT_ALERT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[130].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[131].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].entry.ee_code = EEC_ATSUSETY_AREA_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[131].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[132].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].entry.ee_code = EEC_ATSUSETY_BUFFER_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[132].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[133].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].entry.ee_code = EEC_ATSUSETY_CANADIAN_AIR_DEFENCE_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[133].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[134].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].entry.ee_code = EEC_ATSUSETY_CONTROL_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[134].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[135].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].entry.ee_code = EEC_ATSUSETY_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[135].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[136].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].entry.ee_code = EEC_ARSPCLIMIT_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[137].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].entry.ee_code = EEC_ATSUSETY_DEW_EAST_MLTRY_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[138].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].entry.ee_code = EEC_ATSUSETY_DEW_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[139].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].entry.ee_code = EEC_ATSUSETY_FLIGHT_INR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[140].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].entry.ee_code = EEC_ATSUSETY_FRENCH_PERIPHERAL_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[140].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[141].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].entry.ee_code = EEC_ATSUSETY_MLTRY_AERODROME_TZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[141].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[142].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].entry.ee_code = EEC_ATSUSETY_MLTRY_COMMON_REGION_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[143].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].entry.ee_code = EEC_ATSUSETY_MLTRY_CLIMB_CORRIDOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[143].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[144].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].entry.ee_code = EEC_ARSPCLIMIT_MILITARY_FLYING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[145].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].entry.ee_code = EEC_ATSUSETY_MIDCANADA_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[145].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[146].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].entry.ee_code = EEC_ARSPCLIMIT_MILITARY_OPERATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[146].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[147].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].entry.ee_code = EEC_ATSUSETY_MLTRY_TERMINAL_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[147].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[148].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].entry.ee_code = EEC_ATSUSETY_MLTRY_UPPER_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[149].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].entry.ee_code = EEC_ATSUSETY_OCA_NON_FAA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[150].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].entry.ee_code = EEC_ARSPCLIMIT_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[151].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].entry.ee_code = EEC_ARSPCLIMIT_PROHIBITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[152].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].entry.ee_code = EEC_ATSUSETY_POSITIVE_CONTROL_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[153].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].entry.ee_code = EEC_ATSUSETY_POSITIVE_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[154].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].entry.ee_code = EEC_ATSUSETY_RADAR_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[155].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].entry.ee_code = EEC_ARSPCLIMIT_RESTRICTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[156].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].entry.ee_code = EEC_ATSUSETY_SECURITY_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[156].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[157].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].entry.ee_code = EEC_ATSUSETY_SPECIAL_AIR_TRAFFIC_RULES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[158].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].entry.ee_code = EEC_ATSUSETY_SPECIAL_RULES_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[158].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[159].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].entry.ee_code = EEC_ATSUSETY_TRANSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[160].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].entry.ee_code = EEC_ATSUSETY_TERMINAL_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[160].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[161].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].entry.ee_code = EEC_ATSUSETY_CONTINENTAL_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[161].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[162].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].entry.ee_code = EEC_ATSUSETY_SPECIAL_OPERATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[163].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].entry.ee_code = EEC_ATSUSETY_TERMINAL_RADAR_SERVICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[163].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[164].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].entry.ee_code = EEC_ATSUSETY_UPPER_ADVISORY_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[164].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[165].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].entry.ee_code = EEC_ATSUSETY_UPPER_CONTROL_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[165].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[166].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].entry.ee_code = EEC_ATSUSETY_UPPER_FLIGHT_INR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[166].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[167].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].entry.ee_code = EEC_ARSPCLIMIT_WARNING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[167].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[168].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].entry.ee_code = EEC_ATSUSETY_ZONE_OF_INTERIOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[168].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[169].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_USE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[169].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[170].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].entry.ee_code = EEC_ATSUSETY_KOREA_LIMITED_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[170].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[171].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].entry.ee_code = EEC_ATSUSETY_UNCONTROLLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[171].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[172].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].entry.ee_code = EEC_ATSUSETY_CONTROLLED_AIRSPACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[172].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[173].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].entry.ee_code = EEC_ATSUSETY_AIRPORT_TRAFFIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[173].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[174].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].entry.ee_code = EEC_ATSUSETY_AIRPORT_RADAR_SERVICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[174].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[175].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].entry.ee_code = EEC_ARSPCLIMIT_CONTROLLED_FIRING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[175].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[176].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].entry.ee_code = EEC_ARSPCLIMIT_PARACHUTE_DROP_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[176].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[177].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].entry.ee_code = EEC_ATSUSETY_AIRPORT_ADVISORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[177].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[178].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].entry.ee_code = EEC_ATSUSETY_MOUNTAINOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[178].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[179].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].entry.ee_code = EEC_ARSPCLIMIT_BIRD_BREEDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[179].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[180].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].entry.ee_code = EEC_ATSUSETY_CZ_NO_FIXED_WING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[180].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[181].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].entry.ee_code = EEC_ATSUSETY_ALTIMETER_CHANGE_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[181].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[182].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].entry.ee_code = EEC_ARSPCLIMIT_DEFENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[182].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[183].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].entry.ee_code = EEC_ATSUSETY_AERODROME_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[183].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[184].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].entry.ee_code = EEC_ATSUSETY_CLASS_C_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[185].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].entry.ee_code = EEC_ARSPCLIMIT_SPARSELY_SETTLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[185].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[186].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].entry.ee_code = EEC_ATSUSETY_ICAO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[186].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[187].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].entry.ee_code = EEC_ATSUSETY_UPPER_AIRSPACE_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[187].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[188].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].entry.ee_code = EEC_ATSUSETY_DEW_EAST_MLTRY_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[188].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[189].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].entry.ee_code = EEC_ARSPCLIMIT_BIRD_HAZARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[189].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[190].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].entry.ee_code = EEC_ARSPCLIMIT_TEMPORARY_RESERVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[190].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[191].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].entry.ee_code = EEC_ATSUSETY_ARTCC_SECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[191].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[192].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].entry.ee_code = EEC_ATSUSETY_SUB_FLIGHT_INR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[192].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[193].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].entry.ee_code = EEC_ATSUSETY_RADAR_SECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[193].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[194].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].entry.ee_code = EEC_ATSUSETY_OCA_FAA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[194].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[195].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].entry.ee_code = EEC_ATSUSETY_REFUELING_OR_TRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[195].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[196].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].entry.ee_code = EEC_ATSUSETY_BERLIN_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[196].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[197].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].entry.ee_code = EEC_ARSPCLIMIT_HELICOPTER_PROTECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[197].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[198].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].entry.ee_code = EEC_ATSUSETY_TRAFFIC_INZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[198].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[199].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].entry.ee_code = EEC_ATSUSETY_LOW_FLYING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[199].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[200].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].entry.ee_code = EEC_ATSUSETY_SPECIAL_USE_AIRSPACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[200].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[201].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_USE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[201].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[202].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_USE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[202].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[203].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_USE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[203].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[204].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_USE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[204].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[205].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[205].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[206].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].entry.ee_code = EEC_ARSPCTY_FLIGHT_INR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[206].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[207].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].entry.ee_code = EEC_ARSPCTY_SUB_FLIGHT_INR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[207].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[208].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].entry.ee_code = EEC_ARSPCTY_CONTROL_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[208].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[209].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].entry.ee_code = EEC_ARSPCTY_MLTRY_CTZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[209].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[210].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[210].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[211].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].entry.ee_code = EEC_ARSPCTY_SPC_RULES_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[212].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].entry.ee_code = EEC_ARSPCTY_ADVISORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[213].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].entry.ee_code = EEC_ARSPCTY_TERMINAL_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[214].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[214].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[215].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].entry.ee_code = EEC_ARSPCTY_MLTRY_CLIMB_CORRIDOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[215].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[216].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].entry.ee_code = EEC_ARSPCTY_ALTIMETER_SETTING_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[216].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[217].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].entry.ee_code = EEC_ARSPCTY_MOUNTAINOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[217].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[218].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].entry.ee_code = EEC_ARSPCTY_ACC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[218].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[219].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].entry.ee_code = EEC_ARSPCTY_RADAR_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[219].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[220].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].entry.ee_code = EEC_ARSPCTY_RADAR_AREA_SECTOR_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[220].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[221].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].entry.ee_code = EEC_ARSPCTY_RADAR_SERVICE_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[221].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[222].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].entry.ee_code = EEC_ARSPCTY_TERMINAL_RADAR_SERVICE_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[222].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[223].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].entry.ee_code = EEC_ARSPCTY_TRANSITION_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[223].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[224].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].entry.ee_code = EEC_ARSPCTY_UPPER_FLIGHT_INR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[224].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[225].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].entry.ee_code = EEC_ARSPCTY_UPPER_CONTROL_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[225].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[226].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].entry.ee_code = EEC_ARSPCTY_MLTRY_UPPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[226].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[227].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].entry.ee_code = EEC_ARSPCTY_UPPER_ADVISORY_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[227].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[228].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].entry.ee_code = EEC_ARSPCTY_CONTROL_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[228].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[229].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].entry.ee_code = EEC_ARSPCTY_SPC_RULES_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[229].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[230].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].entry.ee_code = EEC_ARSPCTY_MLTRY_RADAR_SERVICE_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[230].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[231].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].entry.ee_code = EEC_ARSPCTY_TRAINING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[231].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[232].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].entry.ee_code = EEC_ARSPCTY_AIR_TO_AIR_REFUELLING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[232].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[233].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].entry.ee_code = EEC_ARSPCTY_CCA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[233].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[234].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].entry.ee_code = EEC_ARSPCTY_OCA_NON_FAA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[234].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[235].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].entry.ee_code = EEC_ARSPCTY_OCA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[235].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[236].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].entry.ee_code = EEC_ARSPCTY_UPPER_AIRSPACE_CENTRES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[236].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[237].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].entry.ee_code = EEC_ARSPCTY_AIR_DEFENCE_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[237].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[238].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].entry.ee_code = EEC_ARSPCTY_BUFFER_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[238].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[239].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].entry.ee_code = EEC_ARSPCTY_DEWMIZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[239].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[240].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].entry.ee_code = EEC_ARSPCTY_DEWIZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[240].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[241].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].entry.ee_code = EEC_ARSPCTY_FRENCH_PERIPHERAL_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[241].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[242].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].entry.ee_code = EEC_ARSPCTY_CADIZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[243].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].entry.ee_code = EEC_ARSPCTY_MIDCANADA_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[243].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[244].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].entry.ee_code = EEC_ARSPCTY_SECURITY_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[244].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[245].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].entry.ee_code = EEC_ARSPCTY_ZONE_OF_INTERIOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[245].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[246].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].entry.ee_code = EEC_ARSPCTY_KOREA_LIMITED_IDZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[246].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[247].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].entry.ee_code = EEC_ARSPCTY_AERODROME_TRAFFIC_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[247].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[248].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].entry.ee_code = EEC_ARSPCTY_AERODROME_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[248].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[249].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].entry.ee_code = EEC_ARSPCTY_MLTRY_ATZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[249].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[250].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].entry.ee_code = EEC_ARSPCTY_AERODROME_RADAR_SERVICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[250].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[251].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].entry.ee_code = EEC_ARSPCTY_AERODROME_ADVISORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[251].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[252].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].entry.ee_code = EEC_ARSPCTY_UNCONTROLLED_AIRSPACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[252].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[253].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].entry.ee_code = EEC_ARSPCTY_CONTROLLED_AIRSPACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[253].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[254].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].entry.ee_code = EEC_ARSPCTY_CONTROLLED_VFR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[254].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[255].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].entry.ee_code = EEC_ARSPCTY_POSITIVE_CONTROL_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[255].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[256].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].entry.ee_code = EEC_ARSPCTY_POSITIVE_CZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[256].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[257].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].entry.ee_code = EEC_ARSPCTY_MANDATORY_RADIO_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[257].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[258].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].entry.ee_code = EEC_ARSPCTY_SAL_ENTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[258].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[259].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].entry.ee_code = EEC_ARSPCTY_SAL_EXIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[259].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[260].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].entry.ee_code = EEC_ARSPCTY_FIC_FSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[260].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[261].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].entry.ee_code = EEC_ARSPCTY_MLTRY_SECTOR_CONTROL_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[261].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[262].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].entry.ee_code = EEC_ARSPCTY_ARTCC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[262].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[263].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].entry.ee_code = EEC_ARSPCTY_ARTCC_SECTOR_DISCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[263].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[264].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].entry.ee_code = EEC_ARSPCTY_VFR_SECTOR_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[264].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[265].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].entry.ee_code = EEC_ARSPCTY_MLTRY_COMMON_AREA_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[265].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[266].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].entry.ee_code = EEC_ARSPCTY_TRAFFIC_INZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[266].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[267].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].entry.ee_code = EEC_ARSPCTY_LFLY_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[267].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[268].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].entry.ee_code = EEC_ARSPCTY_LFLY_SUB_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[268].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[269].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].entry.ee_code = EEC_ARSPCTY_LFLY_TACT_TRAINING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[269].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[270].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].entry.ee_code = EEC_ARSPCTY_LFLY_TACT_ROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[270].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[271].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].entry.ee_code = EEC_ARSPCTY_LFLY_FLOW_ARROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[271].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[272].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].entry.ee_code = EEC_ARSPCTY_LFLY_DIVIDING_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[272].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[273].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].entry.ee_code = EEC_ARSPCTY_LFLY_FLOW_CORRIDOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[274].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].entry.ee_code = EEC_ARSPCTY_LFLY_DEDICATED_USER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[275].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].entry.ee_code = EEC_ARSPCTY_LFLY_WEATHER_CORRIDOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[276].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[276].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[277].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[277].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[278].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[278].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[279].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[279].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[280].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[280].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[281].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_LIMITATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[281].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[282].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].entry.ee_code = EEC_ARSPCLIMIT_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[282].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[283].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].entry.ee_code = EEC_ARSPCLIMIT_PROHIBITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[283].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[284].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].entry.ee_code = EEC_ARSPCLIMIT_RESTRICTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[284].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[285].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].entry.ee_code = EEC_ARSPCLIMIT_PROHIBITED_VFR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[285].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[286].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].entry.ee_code = EEC_ARSPCLIMIT_ALERT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[286].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[287].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].entry.ee_code = EEC_ARSPCLIMIT_WARNING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[287].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[288].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].entry.ee_code = EEC_ARSPCLIMIT_DEFENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[288].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[289].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].entry.ee_code = EEC_ARSPCLIMIT_CONTROLLED_FIRING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[289].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[290].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].entry.ee_code = EEC_ARSPCLIMIT_TEMPORARY_RESERVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[290].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[291].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].entry.ee_code = EEC_ARSPCLIMIT_PARACHUTE_DROP_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[291].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[292].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].entry.ee_code = EEC_ARSPCLIMIT_BIRD_BREEDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[292].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[293].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].entry.ee_code = EEC_ARSPCLIMIT_GAS_VENTING_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[293].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[294].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].entry.ee_code = EEC_ARSPCLIMIT_TOWN_TO_BE_AVOIDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[294].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[295].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].entry.ee_code = EEC_ARSPCLIMIT_NATURE_RESERVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[295].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[296].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].entry.ee_code = EEC_ARSPCLIMIT_HELICOPTER_PROTECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[296].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[297].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].entry.ee_code = EEC_ARSPCLIMIT_AIR_EXERCISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[298].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].entry.ee_code = EEC_ARSPCLIMIT_INTENSE_AIR_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[298].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[299].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].entry.ee_code = EEC_ARSPCLIMIT_BIRD_SANCTUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[299].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[300].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].entry.ee_code = EEC_ARSPCLIMIT_BIRD_HAZARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[300].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[301].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].entry.ee_code = EEC_ARSPCLIMIT_INDUSTRIAL_HAZARDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[301].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[302].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].entry.ee_code = EEC_ARSPCLIMIT_MEDICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[302].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[303].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].entry.ee_code = EEC_ARSPCLIMIT_LOW_FLY_AVOIDANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[303].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[304].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].entry.ee_code = EEC_ARSPCLIMIT_ANIMAL_PROTECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[304].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[305].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].entry.ee_code = EEC_ARSPCLIMIT_LOW_FLY_TACTICAL_TRAINING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[305].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[306].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].entry.ee_code = EEC_ARSPCLIMIT_LOW_FLY_DEDICATED_USER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[307].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].entry.ee_code = EEC_ARSPCLIMIT_MICROLIGHT_FLYING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[308].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].entry.ee_code = EEC_ARSPCLIMIT_PROVOST_MARSHAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[308].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[309].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].entry.ee_code = EEC_ARSPCLIMIT_MILITARY_OPERATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[309].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[310].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].entry.ee_code = EEC_ARSPCLIMIT_HIGH_INTENSITY_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[310].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[311].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].entry.ee_code = EEC_ARSPCLIMIT_MILITARY_FLYING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[311].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[312].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].entry.ee_code = EEC_ARSPCLIMIT_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[312].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[313].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].entry.ee_code = EEC_ARSPCLIMIT_BIRD_BREEDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[313].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[314].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].entry.ee_code = EEC_ARSPCLIMIT_SPARSELY_SETTLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[314].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[315].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].entry.ee_code = EEC_ARSPCLIMIT_CAUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[315].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[316].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_LIMITATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[316].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[317].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_LIMITATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[317].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[318].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_LIMITATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[318].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[319].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AIRSPACE_LIMITATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[319].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[320].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[320].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[321].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].entry.ee_code = EEC_ATSRTETY_AIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[321].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[322].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].entry.ee_code = EEC_ATSRTETY_AIR_ROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[322].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[323].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].entry.ee_code = EEC_ATSRTETY_PURPLE_AIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[323].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[324].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].entry.ee_code = EEC_ATSRTETY_ROYAL_LOW_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[324].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[325].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].entry.ee_code = EEC_ATSRTETY_CORRIDOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[325].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[326].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].entry.ee_code = EEC_ATSRTETY_ATLANTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[326].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[327].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].entry.ee_code = EEC_ATSRTETY_BAHAMAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[327].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[328].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].entry.ee_code = EEC_ATSRTETY_ADVISORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[328].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[329].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].entry.ee_code = EEC_ATSRTETY_DIRECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[329].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[330].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].entry.ee_code = EEC_ATSRTETY_MILITARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[330].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[331].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].entry.ee_code = EEC_ATSRTETY_OCEANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[332].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].entry.ee_code = EEC_ATSRTETY_AREA_NAVIGATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[333].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].entry.ee_code = EEC_ATSRTETY_SUBSTITUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[334].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].entry.ee_code = EEC_ATSRTETY_TACAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[334].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[335].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].entry.ee_code = EEC_ATSRTETY_HELICOPTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[335].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[336].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].entry.ee_code = EEC_ATSRTETY_HELICOPTER_MULTI_ENGINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[336].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[337].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].entry.ee_code = EEC_ATSRTETY_LOW_FLYING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[337].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[338].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].entry.ee_code = EEC_ATSRTETY_ROYAL_HELICOPTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[338].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[339].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].entry.ee_code = EEC_ATSRTETY_JET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[340].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].entry.ee_code = EEC_ATSRTETY_NORTH_AMERICA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[341].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].entry.ee_code = EEC_ATSRTETY_CANADIAN_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[342].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[342].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[343].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[343].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[344].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[344].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[345].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ATS_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[345].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[346].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[346].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[347].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].entry.ee_code = EEC_BLTUPREGNDENS_SPARSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[347].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[348].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].entry.ee_code = EEC_BLTUPREGNDENS_DENSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[348].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[349].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].entry.ee_code = EEC_BLTUPREGNDENS_MODERATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[349].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[350].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[350].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[351].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[351].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[352].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[352].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[353].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[353].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[354].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BYPASS_CONDITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[354].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[355].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].entry.ea_code = EAC_BYPASS_CONDITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].entry.ee_code = EEC_BYPCND_EASY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[355].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[356].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].entry.ea_code = EAC_BYPASS_CONDITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].entry.ee_code = EEC_BYPCND_DIFFICULT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[356].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[357].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].entry.ea_code = EAC_BYPASS_CONDITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].entry.ee_code = EEC_BYPCND_IMPOSSIBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[357].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[358].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BYPASS_CONDITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[358].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[359].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BYPASS_CONDITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[359].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[360].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BYPASS_CONDITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[360].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[361].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BYPASS_CONDITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[361].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[362].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[362].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[363].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].entry.ee_code = EEC_BOTRETROCKSTAT_CLASSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[363].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[364].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].entry.ee_code = EEC_BOTRETROCKSTAT_DETECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[364].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[365].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].entry.ee_code = EEC_BOTRETROCKSTAT_IDENTIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[365].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[366].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[366].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[367].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[367].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[368].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[368].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[369].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[369].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[370].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[370].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[371].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].entry.ee_code = EEC_WTRBDFLRCFG_DOUBLE_BREAK_IN_SLOPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[371].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[372].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].entry.ee_code = EEC_WTRBDFLRCFG_BREAK_IN_SLOPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[372].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[373].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].entry.ee_code = EEC_WTRBDFLRCFG_DEPRESSION_FLAT_BOTTOM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[373].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[374].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].entry.ee_code = EEC_WTRBDFLRCFG_DEPRESSION_STEEP_SIDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[374].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[375].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].entry.ee_code = EEC_WTRBDFLRCFG_DEPRESSION_V_SHAPED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[375].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[376].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].entry.ee_code = EEC_WTRBDFLRCFG_DEPRESSION_SEDIMENT_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[376].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[377].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].entry.ee_code = EEC_WTRBDFLRCFG_ELEVATION_FLAT_TOPPED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[377].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[378].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].entry.ee_code = EEC_WTRBDFLRCFG_ELEVATION_PEAKED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[379].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].entry.ee_code = EEC_WTRBDFLRCFG_ELEVATION_ROUNDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[379].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[380].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].entry.ee_code = EEC_WTRBDFLRCFG_SLUMPED_BLOCKS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[380].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[381].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].entry.ee_code = EEC_WTRBDFLRCFG_SCARP_PROBABLY_FAULTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[381].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[382].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].entry.ee_code = EEC_WTRBDFLRCFG_SLUMP_DEBRIS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[382].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[383].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].entry.ee_code = EEC_WTRBDFLRCFG_STEP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[383].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[384].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].entry.ee_code = EEC_WTRBDFLRCFG_TERRACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[385].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[385].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[386].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[386].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[387].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[387].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[388].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[388].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[389].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_DESIGN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[389].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[390].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].entry.ee_code = EEC_BRIDGEDES_ARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[390].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[391].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].entry.ee_code = EEC_BRIDGEDES_CANTILEVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[391].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[392].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].entry.ee_code = EEC_BRIDGEDES_DECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[392].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[393].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].entry.ee_code = EEC_BRIDGEDES_SLAB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[393].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[394].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].entry.ee_code = EEC_BRIDGEDES_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[394].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[395].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].entry.ee_code = EEC_BRIDGEDES_GIRDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[395].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[396].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].entry.ee_code = EEC_BRIDGEDES_STRINGER_BEAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[396].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[397].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].entry.ee_code = EEC_BRIDGEDES_TRUSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[397].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[398].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].entry.ee_code = EEC_BRIDGEDES_SUSPENSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[398].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[399].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_DESIGN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[399].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[400].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].entry.ee_code = EEC_BRIDGEDES_TRANSPORTER_FERRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[400].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[401].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_DESIGN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[401].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[402].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_DESIGN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[402].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[403].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_DESIGN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[403].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[404].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_DESIGN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[404].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[405].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[405].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[406].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].entry.ee_code = EEC_AIDNAVMARKERTY_VIS_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[406].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[407].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].entry.ee_code = EEC_AIDNAVMARKERTY_VIS_DAYMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[407].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[408].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].entry.ee_code = EEC_AIDNAVMARKERTY_VIS_BEACON_VIS_DAYMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[408].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[409].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[409].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[410].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[410].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[411].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[411].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[412].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[412].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[413].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[413].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[414].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CARDINAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[414].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[415].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_LATERAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[415].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[416].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MOORING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[416].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[417].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_ODAS;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[417].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[418].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SEAPLANE_ANCHORAGE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[418].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[419].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SPOIL_GROUND;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[419].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[420].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_BUOYTY_ARTICULATED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[420].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[421].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_BUOYTY_FLOAT_WITH_BEACON;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[421].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[422].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_RADAR_TRANSPONDER;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[422].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[423].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_STRUCTURAL_PILE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[423].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[424].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_CAIRN;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[424].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[425].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_BUOYANT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[425].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[426].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_FIRING_DANGER;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[426].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[427].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_TARGET;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[427].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[428].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MARKER_SHIP;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[428].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[429].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_DEGAUSSING_RANGE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[429].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[430].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_BARGE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[430].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[431].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CABLE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[431].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[432].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_OUTFALL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[432].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[433].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_RECORDING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[433].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[434].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_RECREATION_ZONE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[434].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[435].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_LEADING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[435].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[436].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MEASURED_DISTANCE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[436].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[437].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_TRAFFIC_SEPARATION_SCHEME;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[437].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[438].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_ANCHORING_PROHIBITED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[438].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[439].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_BERTHING_PROHIBITED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[439].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[440].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_OVERTAKING_PROHIBITED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[440].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[441].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_TWO_WAY_PROHIBITED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[441].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[442].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_REDUCED_WAKE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[442].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[443].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SPEED_LIMIT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[443].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[444].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_STOP;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[444].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[445].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SOUND_SHIPS_SIREN;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[445].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[446].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_RSTRCT_VERT_CLEARANCE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[446].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[447].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MAXIMUM_VESSEL_DRAFT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[447].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[448].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_RSTRCT_HORIZ_CLEARANCE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[448].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[449].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_STRONG_CURRENT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[449].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[450].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_BERTHING_PERMITTED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[450].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[451].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_ELEVATED_ELECTRICAL_CABLE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[451].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[452].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CHANNEL_EDGE_GRADIENT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[452].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[453].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_TELEPHONE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[453].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[454].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_FERRY_CROSSING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[454].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[455].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_PIPELINE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[455].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[456].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CLEARING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[456].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[457].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_REFUGE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[457].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[458].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_FOUL_GROUND;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[458].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[459].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_YACHTING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[459].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[460].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_HELIPORT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[460].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[461].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_GPS;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[461].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[462].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SEAPLANE_LANDING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[462].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[463].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_DIVING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[463].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[464].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_INFORMATION;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[464].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[465].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CAUTIONARY;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[465].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[466].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_PRIVATE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[466].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[467].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SWIMMING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[467].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[468].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].entry.information = "Was: \"Control\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CONTROL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[468].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[469].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_KEEPOUT;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[469].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[470].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_DAYMARK;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[470].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[471].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MODIFIED_PORT_LATERAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[471].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[472].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MODIFIED_STARBOARD_LATERAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[472].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[473].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_STARBOARD_HAND_LATERAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[473].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[474].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_PORT_HAND_LATERAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[474].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[475].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_WEST_CARDINAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[475].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[476].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SOUTH_CARDINAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[476].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[477].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_EAST_CARDINAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[477].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[478].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_NORTH_CARDINAL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[478].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[479].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_INSTALLATION;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[479].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[480].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_ENTRY_PROHIBITED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[480].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[481].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_WORK_IN_PROGRESS;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[481].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[482].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_ARTICULATED_DAYMARK;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[482].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[483].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_TRIANGLE_DAYMARK;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[483].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[484].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_RECTANGLE_DAYMARK;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[484].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[485].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_STAKE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[485].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[486].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_WITHY;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[486].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[487].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_TOWER;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[487].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[488].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARBEACSHAP_LATTICE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[488].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[489].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_WELL_HEAD;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[489].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[490].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CHANNEL_SEPARATION;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[490].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[491].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_MARINE_FARM;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[491].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[492].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_ARTIFICIAL_REEF;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[492].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[493].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_SPECIAL_PURPOSE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[493].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[494].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_NOTICE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[494].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[495].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_GENERAL_WARNING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[495].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[496].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_ANCHORAGE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[496].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[497].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].entry.information = "Was: \"Control Mark\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_MARKTY_CONTROL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_BEACON_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[497].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[498].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[498].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[499].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[499].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[500].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[500].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[501].code.tag, "BET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[501].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[502].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[502].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[503].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].entry.ee_code = EEC_BLDGFN_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[504].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].entry.ee_code = EEC_BLDGFN_GOVERNMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[505].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].entry.ee_code = EEC_BLDGFN_CAPITOL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[506].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].entry.ee_code = EEC_BLDGFN_CASTLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[507].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].entry.ee_code = EEC_BLDGFN_GOVERNMENT_ADMINISTRATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[507].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[508].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].entry.ee_code = EEC_BLDGFN_HOSPITAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[508].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[509].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].entry.ee_code = EEC_BLDGFN_WORSHIP_PLACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[509].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[510].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].entry.ee_code = EEC_BLDGFN_MILITARY_OPERATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[510].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[511].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].entry.ee_code = EEC_BLDGFN_MUSEUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[511].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[512].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].entry.ee_code = EEC_BLDGFN_OBSERVATORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[513].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].entry.ee_code = EEC_BLDGFN_PALACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[514].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].entry.ee_code = EEC_BLDGFN_POLICE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[514].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[515].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].entry.ee_code = EEC_BLDGFN_PRISON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[515].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[516].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].entry.ee_code = EEC_BLDGFN_RANGER_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[516].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[517].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].entry.ee_code = EEC_BLDGFN_SCHOOL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[517].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[518].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].entry.ee_code = EEC_BLDGFN_HOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[518].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[519].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].entry.ee_code = EEC_BLDGFN_MULTI_UNIT_DWELLING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[519].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[520].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].entry.ee_code = EEC_BLDGFN_CEMETERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[520].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[521].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].entry.ee_code = EEC_BLDGFN_FARM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[521].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[522].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].entry.ee_code = EEC_BLDGFN_GREENHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[523].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].entry.ee_code = EEC_BLDGFN_PARKING_GARAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[524].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].entry.ee_code = EEC_BLDGFN_WATER_DRIVEN_GRISTMILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[525].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].entry.ee_code = EEC_BLDGFN_WIND_TUNNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[526].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].entry.ee_code = EEC_BLDGFN_WAREHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[526].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[527].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].entry.ee_code = EEC_BLDGFN_ROUNDHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[527].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[528].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].entry.ee_code = EEC_BLDGFN_RAILWAY_STORAGE_REPAIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[529].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].entry.ee_code = EEC_BLDGFN_DEPOT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[530].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].entry.ee_code = EEC_BLDGFN_ADMINISTRATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[530].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[531].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].entry.ee_code = EEC_BLDGFN_AIRCRAFT_MAINTENANCE_SHOP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[531].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[532].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].entry.ee_code = EEC_BLDGFN_AIRCRAFT_HANGAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[532].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[533].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].entry.ee_code = EEC_BLDGFN_CUSTOMS_HOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[533].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[534].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].entry.ee_code = EEC_BLDGFN_HEALTH_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[534].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[535].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].entry.ee_code = EEC_BLDGFN_WEAPONS_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[535].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[536].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].entry.ee_code = EEC_BLDGFN_POST_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[536].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[537].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].entry.ee_code = EEC_BLDGFN_BARRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].entry.information = "Was: \"Barracks/Dormitory\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[537].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[538].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].entry.ee_code = EEC_BLDGFN_FIRE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[538].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[539].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].entry.ee_code = EEC_BLDGFN_JAIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[539].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[540].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].entry.ee_code = EEC_BLDGFN_GUARDHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Guardhouse)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[540].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[541].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].entry.ee_code = EEC_BLDGFN_TELEPHONE_SWITCHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[541].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[542].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].entry.ee_code = EEC_BLDGFN_ROADSIDE_REST_STOP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[542].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[543].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].entry.ee_code = EEC_BLDGFN_ROAD_MAINTENANCE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[543].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[544].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_BLDGFN_WORSHIP_PLACE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WORSHIPPLACETY_CHURCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[544].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[545].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].entry.ee_code = EEC_BLDGFN_MARKET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[545].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[546].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].entry.ee_code = EEC_BLDGFN_TOWN_HALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[546].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[547].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].entry.ee_code = EEC_BLDGFN_BANK_BUILDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[547].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[548].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].entry.ee_code = EEC_BLDGFN_MOTOR_VEHICLE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[548].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[549].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].entry.ee_code = EEC_BLDGFN_NAUTICAL_CLUB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[549].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[550].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].entry.ee_code = EEC_BLDGFN_PUBLIC_INN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[550].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[551].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].entry.ee_code = EEC_BLDGFN_RESTAURANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[551].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[552].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].entry.ee_code = EEC_BLDGFN_OBSERVATION_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[552].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[553].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].entry.ee_code = EEC_BLDGFN_SCIENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[553].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[554].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].entry.ee_code = EEC_BLDGFN_COLLEGIATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[554].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[555].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].entry.ee_code = EEC_BLDGFN_COUNTY_HALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[555].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[556].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].entry.ee_code = EEC_BLDGFN_LEGATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[556].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[557].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].entry.ee_code = EEC_BLDGFN_MISSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[557].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[558].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].entry.ee_code = EEC_BLDGFN_CHANCERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[558].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[559].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].entry.ee_code = EEC_BLDGFN_AMBASSADORIAL_RESIDENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[559].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[560].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].entry.ee_code = EEC_BLDGFN_EMBASSY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[560].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[561].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].entry.ee_code = EEC_BLDGFN_CONSULATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[561].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[562].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].entry.ee_code = EEC_BLDGFN_GUARDHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[562].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[563].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].entry.ee_code = EEC_BLDGFN_GUARDHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[563].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[564].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].entry.ee_code = EEC_BLDGFN_KENNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[564].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[565].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].entry.ee_code = EEC_BLDGFN_VEGETABLE_OIL_MILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[565].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[566].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].entry.ee_code = EEC_BLDGFN_AERATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[566].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[567].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].entry.ee_code = EEC_BLDGFN_CARPENTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[567].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[568].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].entry.ee_code = EEC_BLDGFN_SAWMILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[568].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[569].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].entry.ee_code = EEC_BLDGFN_INDUSTRIAL_OVEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[569].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[570].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].entry.ee_code = EEC_BLDGFN_RAILWAY_SIGNAL_STRUCTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[570].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[571].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].entry.ee_code = EEC_BLDGFN_HARBOUR_MASTERS_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[571].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[572].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].entry.ee_code = EEC_BLDGFN_MARINE_POLICE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[572].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[573].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].entry.ee_code = EEC_BLDGFN_RESCUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[573].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[574].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].entry.ee_code = EEC_BLDGFN_PORT_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[574].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[575].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].entry.ee_code = EEC_BLDGFN_MARINE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[575].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[576].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].entry.ee_code = EEC_BLDGFN_LIGHTHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[576].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[577].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].entry.ee_code = EEC_BLDGFN_POWER_GENERATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[577].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[578].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].entry.ee_code = EEC_BLDGFN_FILTRATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[578].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[579].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].entry.ee_code = EEC_BLDGFN_NEWSPAPER_PLANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[579].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[580].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].entry.ee_code = EEC_BLDGFN_TELEPHONE_EXCHANGE_MAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[580].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[581].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].entry.ee_code = EEC_BLDGFN_AUDITORIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[581].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[582].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].entry.ee_code = EEC_BLDGFN_OPERA_HOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[582].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[583].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].entry.ee_code = EEC_BLDGFN_PROCESSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[583].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[584].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].entry.ee_code = EEC_BLDGFN_PUMP_ROOM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[584].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[585].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].entry.ee_code = EEC_BLDGFN_MOBILE_HOME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[585].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[586].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].entry.ee_code = EEC_BLDGFN_WEATHER_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[586].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[587].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].entry.ee_code = EEC_BLDGFN_DEPENDENTS_OR_BIVOUAC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[587].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[588].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].entry.ee_code = EEC_BLDGFN_RAILWAY_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[588].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[589].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].entry.ee_code = EEC_BLDGFN_HOTEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[589].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[590].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].entry.ee_code = EEC_BLDGFN_DIPLOMATIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[590].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[591].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].entry.ee_code = EEC_BLDGFN_TRADING_POST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[591].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[592].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].entry.ee_code = EEC_BLDGFN_SHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[592].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[593].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].entry.ee_code = EEC_BLDGFN_BATTERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[593].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[594].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].entry.ee_code = EEC_BLDGFN_MEDICAL_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[594].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[595].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].entry.ee_code = EEC_BLDGFN_MUNICIPAL_HALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[595].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[596].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].entry.ee_code = EEC_BLDGFN_PETROLEUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[596].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[597].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].entry.ee_code = EEC_BLDGFN_OUTBUILDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[597].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[598].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].entry.ee_code = EEC_BLDGFN_PAPER_MILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[598].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[599].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].entry.ee_code = EEC_BLDGFN_REFORMATORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[599].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[600].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].entry.ee_code = EEC_BLDGFN_SANATORIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[600].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[601].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].entry.ee_code = EEC_BLDGFN_SATELLITE_GROUND_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[601].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[602].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].entry.ee_code = EEC_BLDGFN_SEMINARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[602].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[603].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].entry.ee_code = EEC_BLDGFN_SENIOR_CITIZENS_HOME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[603].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[604].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].entry.ee_code = EEC_BLDGFN_SHIPYARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[604].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[605].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].entry.ee_code = EEC_BLDGFN_SPORTSPLEX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[605].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[606].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].entry.ee_code = EEC_BLDGFN_STEEL_MILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[606].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[607].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].entry.ee_code = EEC_BLDGFN_VEHICLE_SCALE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[607].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[608].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_BLDGFN_WORSHIP_PLACE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_NON_CHRISTIANITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[608].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[609].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].entry.ee_code = EEC_BLDGFN_HOSTEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[609].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[610].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].entry.ee_code = EEC_BLDGFN_FACTORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[610].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[611].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].entry.ee_code = EEC_BLDGFN_MOTEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[611].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[612].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].entry.ee_code = EEC_BLDGFN_COMMUNITY_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[612].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[613].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].entry.ee_code = EEC_BLDGFN_CITY_HALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[613].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[614].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].entry.ee_code = EEC_BLDGFN_AUTOMOTIVE_PLANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[614].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[615].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].entry.ee_code = EEC_BLDGFN_ARMOURY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[615].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[616].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].entry.ee_code = EEC_BLDGFN_SHOPPING_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[616].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[617].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].entry.ee_code = EEC_BLDGFN_CORRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[617].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[618].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].entry.ee_code = EEC_BLDGFN_REPAIR_FACILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[618].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[619].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].entry.ee_code = EEC_BLDGFN_FARM_STORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[619].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[620].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].entry.ee_code = EEC_BLDGFN_ASTRONOMICAL_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[620].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[621].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].entry.ee_code = EEC_BLDGFN_THEATRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[621].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[622].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].entry.ee_code = EEC_BLDGFN_LIBRARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[622].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[623].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].entry.ee_code = EEC_BLDGFN_AERODROME_TERMINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[623].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[624].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].entry.ee_code = EEC_BLDGFN_BUS_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[624].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[625].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].entry.ee_code = EEC_BLDGFN_PILOT_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[625].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[626].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].entry.ee_code = EEC_BLDGFN_PILOT_LOOKOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[626].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[627].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].enum_val = 133;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].entry.ee_code = EEC_BLDGFN_COMMERCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[627].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[628].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].enum_val = 134;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].entry.ee_code = EEC_BLDGFN_FORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[628].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[629].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].enum_val = 135;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].entry.ee_code = EEC_BLDGFN_BLOCKHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[629].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[630].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].enum_val = 136;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].entry.ee_code = EEC_BLDGFN_MARTELLO_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[630].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[631].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].enum_val = 137;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].entry.ee_code = EEC_BLDGFN_GUARD_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[631].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[632].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].enum_val = 138;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].entry.ee_code = EEC_BLDGFN_REDOUBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[632].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[633].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].enum_val = 139;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].entry.ee_code = EEC_BLDGFN_COOLING_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[633].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[634].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].enum_val = 150;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].entry.ee_code = EEC_BLDGFN_BARRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[634].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[635].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].enum_val = 151;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].entry.ee_code = EEC_BLDGFN_DORMITORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[635].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[636].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].enum_val = 723;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].entry.ee_code = EEC_BLDGFN_FIRE_AND_POLICE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[636].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[637].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[637].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[638].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[638].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[639].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[639].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[640].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUILDING_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[640].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[641].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BEACH_PORTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[641].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[642].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].entry.ea_code = EAC_BEACH_PORTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].entry.ee_code = EEC_BEACHPORTN_NEARSHORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[642].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[643].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].entry.ea_code = EAC_BEACH_PORTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].entry.ee_code = EEC_BEACHPORTN_FORESHORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[643].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[644].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].entry.ea_code = EAC_BEACH_PORTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].entry.ee_code = EEC_BEACHPORTN_BACKSHORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[644].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[645].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BEACH_PORTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[645].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[646].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BEACH_PORTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[646].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[647].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BEACH_PORTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[647].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[648].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BEACH_PORTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[648].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[649].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[649].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[650].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].entry.ee_code = EEC_WTRBDFLRMATTY_CLAY_AND_SILT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[650].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[651].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].entry.ee_code = EEC_WTRBDFLRMATTY_SILTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[651].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[652].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].entry.ee_code = EEC_WTRBDFLRMATTY_SAND_AND_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[652].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[653].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].entry.ee_code = EEC_WTRBDFLRMATTY_GRAVEL_AND_COBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[653].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[654].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].entry.ee_code = EEC_WTRBDFLRMATTY_ROCK_AND_BOULDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[654].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[655].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].entry.ee_code = EEC_WTRBDFLRMATTY_BEDROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[655].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[656].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].entry.ee_code = EEC_WTRBDFLRMATTY_PAVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[656].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[657].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].entry.ee_code = EEC_WTRBDFLRMATTY_PEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[657].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[658].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].entry.ee_code = EEC_WTRBDFLRMATTY_SAND_AND_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[658].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[659].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].entry.ee_code = EEC_WTRBDFLRMATTY_MIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[659].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[660].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].entry.ee_code = EEC_WTRBDFLRMATTY_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[660].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[661].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].entry.ee_code = EEC_WTRBDFLRMATTY_SLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[661].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[662].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].entry.ee_code = EEC_WTRBDFLRMATTY_ROCKY_OUTCROP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[662].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[663].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].entry.ee_code = EEC_WTRBDFLRMATTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[663].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[664].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[664].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[665].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[665].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[666].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[666].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[667].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[667].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[668].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[668].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[669].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].entry.ee_code = EEC_WETLSRFTY_PALSA_BOG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[669].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[670].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].entry.ee_code = EEC_WETLSRFTY_STRING_BOG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[670].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[671].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[671].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[672].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[672].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[673].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[673].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[674].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[674].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[675].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[675].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[676].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].entry.ee_code = EEC_BRIDGEOPNTY_BASCULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[676].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[677].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].entry.ee_code = EEC_BRIDGEOPNTY_SWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[677].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[678].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].entry.ee_code = EEC_BRIDGEOPNTY_LIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[678].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[679].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].entry.ee_code = EEC_BRIDGEOPNTY_RETRACTABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[679].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[680].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[680].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[681].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[681].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[682].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[682].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[683].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[683].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[684].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[684].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[685].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].entry.ee_code = EEC_BOTRETSTAT_CLASSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[685].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[686].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].entry.ee_code = EEC_BOTRETSTAT_DETECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[686].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[687].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].entry.ee_code = EEC_BOTRETSTAT_IDENTIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[687].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[688].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[688].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[689].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[689].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[690].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[690].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[691].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[691].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[692].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[692].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[693].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].entry.ee_code = EEC_BOTRETTY_IDENTITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[693].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[694].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[694].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[695].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].entry.ee_code = EEC_BOTRETTY_SEABED_INSTALLATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[695].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[696].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].entry.ee_code = EEC_BOTRETTY_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[696].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[697].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].entry.ee_code = EEC_BOTRETTY_OBSTACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[697].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[698].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].entry.ee_code = EEC_BOTRETTY_WRECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[698].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[699].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[699].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[700].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[700].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[701].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[701].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[702].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[702].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[703].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[703].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[704].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].entry.ee_code = EEC_BOTRETALEGN_NEUTRAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[704].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[705].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[705].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[706].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[706].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[707].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[707].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[708].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[708].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[709].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[709].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[710].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].entry.ee_code = EEC_BOTRETOBSTSTAT_CLASSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[710].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[711].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].entry.ee_code = EEC_BOTRETOBSTSTAT_DETECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[711].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[712].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].entry.ee_code = EEC_BOTRETOBSTSTAT_IDENTIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[712].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[713].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[713].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[714].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[714].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[715].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[715].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[716].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[716].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[717].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[717].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[718].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].entry.ee_code = EEC_BOTRETWRCKSTAT_CLASSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[718].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[719].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].entry.ee_code = EEC_BOTRETWRCKSTAT_DETECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[719].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[720].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].entry.ee_code = EEC_BOTRETWRCKSTAT_IDENTIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[720].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[721].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[721].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[722].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[722].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[723].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[723].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[724].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[724].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[725].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[725].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[726].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].entry.ee_code = EEC_BRIDGESTRTY_ARCH_OPEN_SPANDREL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[726].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[727].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].entry.ee_code = EEC_BRIDGESTRTY_CANTILEVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[727].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[728].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].entry.ee_code = EEC_BRIDGESTRTY_DECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[728].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[729].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].entry.ee_code = EEC_BRIDGESTRTY_DRAW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[729].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[730].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].entry.ee_code = EEC_BRIDGESTRTY_PONTOON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[730].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[731].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].entry.ee_code = EEC_BRIDGESTRTY_GIRDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[731].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[732].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].entry.ee_code = EEC_BRIDGESTRTY_TOWER_SUSPENSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[732].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[733].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].entry.ee_code = EEC_BRIDGESTRTY_TRUSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[733].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[734].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].entry.ee_code = EEC_BRIDGESTRTY_SUSPENSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[734].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[735].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].entry.ee_code = EEC_BRIDGESTRTY_SWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[735].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[736].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].entry.ee_code = EEC_BRIDGESTRTY_LIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[736].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[737].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].entry.ee_code = EEC_BRIDGESTRTY_TRANSPORTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[737].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[738].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].entry.ee_code = EEC_BRIDGESTRTY_BASCULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[738].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[739].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].entry.ee_code = EEC_BRIDGESTRTY_UNSPECIFIED_FIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[739].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[740].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].entry.ee_code = EEC_BRIDGESTRTY_SLAB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[740].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[741].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].entry.ee_code = EEC_BRIDGESTRTY_STRINGER_BEAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[741].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[742].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].entry.ee_code = EEC_BRIDGESTRTY_ARCH_SUSPENSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[742].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[743].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].entry.ee_code = EEC_BRIDGESTRTY_RETRACTABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[743].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[744].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].entry.ee_code = EEC_BRIDGESTRTY_SUSPENSION_BOW_STRING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[744].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[745].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].entry.ee_code = EEC_BRIDGESTRTY_SUSPENSION_CABLE_STAYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[745].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[746].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].entry.ee_code = EEC_BRIDGESTRTY_MOVEABLE_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[746].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[747].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].entry.ee_code = EEC_BRIDGESTRTY_COVERED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[747].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[748].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].entry.ee_code = EEC_BRIDGESTRTY_OPENING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[748].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[749].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].entry.ee_code = EEC_BRIDGESTRTY_FOOT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[749].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[750].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].entry.ee_code = EEC_BRIDGESTRTY_FIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[750].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[751].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].entry.ee_code = EEC_BRIDGESTRTY_ARCH_CLOSED_SPANDREL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[751].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[752].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].entry.ee_code = EEC_BRIDGESTRTY_CABLE_STAYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[752].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[753].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[753].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[754].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[754].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[755].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[755].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[756].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[756].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[757].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[757].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[758].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[758].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[759].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[759].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[760].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[760].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[761].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[761].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[762].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[762].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[763].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[763].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[764].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[764].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[765].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].entry.ee_code = EEC_BRIDGESPANTY_TRUSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[765].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[766].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].entry.ee_code = EEC_BRIDGESPANTY_MOVEABLE_TRUSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[766].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[767].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].entry.ee_code = EEC_BRIDGESPANTY_PLATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[767].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[768].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].entry.ee_code = EEC_BRIDGESPANTY_PLATE_VERTICAL_LIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[768].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[769].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].entry.ee_code = EEC_BRIDGESPANTY_PLATE_DRAW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[769].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[770].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].entry.ee_code = EEC_BRIDGESPANTY_PLATE_BASCULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[770].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[771].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].entry.ee_code = EEC_BRIDGESPANTY_STRINGER_BEAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[771].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[772].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].entry.ee_code = EEC_BRIDGESPANTY_STRINGER_VERTICAL_LIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[772].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[773].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].entry.ee_code = EEC_BRIDGESPANTY_STRINGER_DRAW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[773].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[774].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].entry.ee_code = EEC_BRIDGESPANTY_SLAB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[774].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[775].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].entry.ee_code = EEC_BRIDGESPANTY_ARCH_CLOSED_SPANDREL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[775].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[776].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].entry.ee_code = EEC_BRIDGESPANTY_ARCH_OPEN_SPANDREL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[776].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[777].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].entry.ee_code = EEC_BRIDGESPANTY_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[777].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[778].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].entry.ee_code = EEC_BRIDGESPANTY_CULVERT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[778].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[779].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].entry.ee_code = EEC_BRIDGESPANTY_FRAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[779].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[780].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].entry.ee_code = EEC_BRIDGESPANTY_VAULT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[780].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[781].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].entry.ee_code = EEC_BRIDGESPANTY_UNSPECIFIED_FIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[781].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[782].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].entry.ee_code = EEC_BRIDGESPANTY_RETRACTABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[782].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[783].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[783].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[784].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[784].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[785].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[785].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[786].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[786].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[787].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[787].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[788].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].entry.ee_code = EEC_BOTRETSBEDSTAT_CLASSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[788].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[789].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].entry.ee_code = EEC_BOTRETSBEDSTAT_DETECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[789].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[790].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].entry.ee_code = EEC_BOTRETSBEDSTAT_IDENTIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[790].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[791].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[791].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[792].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[792].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[793].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[793].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[794].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[794].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[795].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOUNDARY_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[795].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[796].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].entry.ee_code = EEC_BNDRYSTAT_DEFINITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[796].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[797].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].entry.ee_code = EEC_BNDRYSTAT_INDEFINITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[797].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[798].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].entry.ee_code = EEC_BNDRYSTAT_IN_DISPUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[798].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[799].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].entry.ee_code = EEC_BNDRYSTAT_NOT_DEFINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[799].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[800].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].entry.ee_code = EEC_BNDRYSTAT_RECOG_BY_DATA_PROVIDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[800].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[801].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].entry.ee_code = EEC_BNDRYSTAT_NOT_RECOG_BY_DATA_PROVIDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[801].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[802].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOUNDARY_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[802].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[803].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOUNDARY_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[803].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[804].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOUNDARY_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[804].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[805].code.tag, "BST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BOUNDARY_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[805].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[806].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[806].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[807].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].entry.ee_code = EEC_MARKTY_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[807].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[808].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].entry.ee_code = EEC_BUOYTY_FLOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[808].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[809].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].entry.ee_code = EEC_BUOYTY_ISOLATED_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[809].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[810].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].entry.ee_code = EEC_BUOYTY_LARGE_AUTOMATED_NAVIGATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[810].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[811].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].entry.ee_code = EEC_MARKTY_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[811].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[812].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].entry.ee_code = EEC_BUOYTY_LIGHT_FLOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[812].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[813].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].entry.ee_code = EEC_MARKTY_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[813].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[814].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].entry.ee_code = EEC_BUOYTY_MOORING_WITH_TELEGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[814].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[815].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].entry.ee_code = EEC_BUOYTY_MOORING_WITH_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[815].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[816].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].entry.ee_code = EEC_MARKTY_ODAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[816].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[817].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].entry.ee_code = EEC_BUOYTY_OUTER_LANDFALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[817].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[818].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].entry.ee_code = EEC_BUOYTY_PORT_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[818].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[819].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].entry.ee_code = EEC_MARKTY_MODIFIED_PORT_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].entry.information = "Was: \"Preferred Channel to Port\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[819].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[820].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].entry.ee_code = EEC_MARKTY_MODIFIED_STARBOARD_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].entry.information = "Was: \"Preferred Channel to Starboard\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[820].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[821].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].entry.ee_code = EEC_BUOYTY_SPECIAL_PURPOSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[821].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[822].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].entry.ee_code = EEC_BUOYTY_STARBOARD_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[822].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[823].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].entry.ee_code = EEC_BUOYTY_TANKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[823].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[824].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].entry.ee_code = EEC_MARKTY_SAFE_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[824].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[825].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].entry.ee_code = EEC_MARKTY_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[825].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[826].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].entry.ee_code = EEC_BUOYTY_FAIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[826].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[827].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].entry.ee_code = EEC_BUOYTY_CHANNEL_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[827].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[828].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].entry.ee_code = EEC_BUOYTY_BIFURCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[828].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[829].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].entry.ee_code = EEC_BUOYTY_JUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[829].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[830].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].entry.ee_code = EEC_BUOYTY_WRECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[830].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[831].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].entry.ee_code = EEC_BUOYTY_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[831].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[832].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].entry.ee_code = EEC_BUOYTY_TELEGRAPH_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[832].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[833].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].entry.ee_code = EEC_BUOYTY_WARPING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[833].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[834].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].entry.ee_code = EEC_MARKTY_QUARANTINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[834].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[835].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].entry.ee_code = EEC_MARKTY_MILITARY_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[835].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[836].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].entry.ee_code = EEC_BUOYTY_EXPLOSIVES_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[836].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[837].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].entry.ee_code = EEC_MARKTY_SEAPLANE_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[837].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[838].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].entry.ee_code = EEC_BUOYTY_COMPASS_ADJUSTMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[838].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[839].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].entry.ee_code = EEC_BUOYTY_FISH_TRAP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[839].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[840].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].entry.ee_code = EEC_MARKTY_SPOIL_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[840].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[841].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].entry.ee_code = EEC_BUOYTY_ARTICULATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[841].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[842].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].entry.ee_code = EEC_BUOYTY_FLOAT_WITH_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[842].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[843].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].entry.ee_code = EEC_BUOYTY_DAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[843].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[844].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].entry.ee_code = EEC_MARKTY_ILLUMINATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[844].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[845].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].entry.ee_code = EEC_BUOYTY_TROT_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[845].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[846].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].entry.ee_code = EEC_MARKTY_DIVING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[846].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[847].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].entry.ee_code = EEC_MARKTY_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[847].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[848].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].entry.ee_code = EEC_BUOYTY_DND_CANADA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[848].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[849].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].entry.ee_code = EEC_MARKTY_CAUTIONARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[849].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[850].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].entry.ee_code = EEC_MARKTY_PRIVATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[850].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[851].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].entry.ee_code = EEC_MARKTY_SWIMMING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[851].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[852].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].entry.ee_code = EEC_MARKTY_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[852].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[853].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].entry.ee_code = EEC_BUOYTY_KEEPOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[853].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[854].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].entry.ee_code = EEC_MARKTY_DAYBEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[854].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[855].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].entry.ee_code = EEC_MARKTY_MODIFIED_PORT_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[855].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[856].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].entry.ee_code = EEC_MARKTY_MODIFIED_STARBOARD_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[856].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[857].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].entry.ee_code = EEC_MARKTY_STARBOARD_HAND_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[857].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[858].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].entry.ee_code = EEC_MARKTY_PORT_HAND_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[858].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[859].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].entry.ee_code = EEC_MARKTY_WEST_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[859].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[860].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].entry.ee_code = EEC_MARKTY_SOUTH_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[860].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[861].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].entry.ee_code = EEC_MARKTY_EAST_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[861].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[862].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].entry.ee_code = EEC_MARKTY_NORTH_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[862].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[863].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].entry.ee_code = EEC_BUOYTY_INSTALLATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[863].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[864].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[864].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[865].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[865].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[866].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[866].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[867].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[867].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[868].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].entry.information = "<= 5%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[868].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[869].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].entry.information = "> 5% and <= 15%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[869].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[870].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].entry.information = "> 15% and <= 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[870].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[871].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].entry.information = "> 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[871].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[872].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Not Applicable)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[872].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[873].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[873].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[874].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[874].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[875].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRUSH_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[875].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[876].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[876].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[877].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].entry.ee_code = EEC_BUOYTY_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[877].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[878].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].entry.ee_code = EEC_BUOYTY_FLOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[878].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[879].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].entry.ee_code = EEC_BUOYTY_ISOLATED_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[879].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[880].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].entry.ee_code = EEC_BUOYTY_LARGE_AUTOMATED_NAVIGATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[880].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[881].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].entry.ee_code = EEC_BUOYTY_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[881].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[882].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].entry.ee_code = EEC_BUOYTY_LIGHT_FLOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[882].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[883].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].entry.ee_code = EEC_BUOYTY_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[883].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[884].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].entry.ee_code = EEC_BUOYTY_MOORING_WITH_TELEGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[884].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[885].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].entry.ee_code = EEC_BUOYTY_MOORING_WITH_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[885].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[886].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].entry.ee_code = EEC_BUOYTY_ODAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[886].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[887].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].entry.ee_code = EEC_BUOYTY_OUTER_LANDFALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[887].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[888].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].entry.ee_code = EEC_BUOYTY_PORT_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[888].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[889].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].entry.ee_code = EEC_BUOYTY_PREFERRED_CHANNEL_PORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[889].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[890].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].entry.ee_code = EEC_BUOYTY_PREFERRED_CHANNEL_STARBOARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].entry.information = "Erroneously mapped to PREFERRED_CHANNEL_PORT in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[890].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[891].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].entry.ee_code = EEC_BUOYTY_SPECIAL_PURPOSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[891].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[892].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].entry.ee_code = EEC_BUOYTY_STARBOARD_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[892].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[893].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].entry.ee_code = EEC_BUOYTY_TANKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[893].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[894].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].entry.ee_code = EEC_BUOYTY_SAFE_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[894].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[895].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].entry.ee_code = EEC_BUOYTY_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[895].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[896].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].entry.ee_code = EEC_BUOYTY_FAIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[896].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[897].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].entry.ee_code = EEC_BUOYTY_CHANNEL_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[897].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[898].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].entry.ee_code = EEC_BUOYTY_BIFURCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[898].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[899].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].entry.ee_code = EEC_BUOYTY_JUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[899].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[900].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].entry.ee_code = EEC_BUOYTY_WRECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[900].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[901].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].entry.ee_code = EEC_BUOYTY_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[901].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[902].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].entry.ee_code = EEC_BUOYTY_TELEGRAPH_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[902].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[903].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].entry.ee_code = EEC_BUOYTY_WARPING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[903].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[904].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].entry.ee_code = EEC_BUOYTY_QUARANTINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[904].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[905].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].entry.ee_code = EEC_BUOYTY_MILITARY_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[905].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[906].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].entry.ee_code = EEC_BUOYTY_EXPLOSIVES_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[906].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[907].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].entry.ee_code = EEC_BUOYTY_SEAPLANE_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[907].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[908].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].entry.ee_code = EEC_BUOYTY_COMPASS_ADJUSTMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[908].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[909].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].entry.ee_code = EEC_BUOYTY_FISH_TRAP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[909].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[910].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].entry.ee_code = EEC_BUOYTY_SPOIL_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[910].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[911].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].entry.ee_code = EEC_BUOYTY_ARTICULATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[911].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[912].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].entry.ee_code = EEC_BUOYTY_FLOAT_WITH_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[912].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[913].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].entry.ee_code = EEC_BUOYTY_DAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[913].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[914].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].entry.ee_code = EEC_BUOYTY_ILLUMINATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[914].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[915].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].entry.ee_code = EEC_BUOYTY_TROT_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[915].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[916].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].entry.ee_code = EEC_BUOYTY_DIVING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[916].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[917].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].entry.ee_code = EEC_BUOYTY_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[917].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[918].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].entry.ee_code = EEC_BUOYTY_DND_CANADA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[918].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[919].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].entry.ee_code = EEC_BUOYTY_APEX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[919].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[920].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].entry.ee_code = EEC_BUOYTY_CAUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[920].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[921].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].entry.ee_code = EEC_BUOYTY_PRIVATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[921].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[922].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].entry.ee_code = EEC_BUOYTY_SWIMMING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[922].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[923].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].entry.ee_code = EEC_BUOYTY_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[923].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[924].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].entry.ee_code = EEC_BUOYTY_KEEPOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[924].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[925].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].entry.ee_code = EEC_BUOYTY_DAYBEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[925].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[926].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].entry.ee_code = EEC_BUOYTY_MODIFIED_PORT_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[926].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[927].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].entry.ee_code = EEC_BUOYTY_MODIFIED_STARBOARD_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[927].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[928].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].entry.ee_code = EEC_BUOYTY_STARBOARD_HAND_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[928].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[929].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].entry.ee_code = EEC_BUOYTY_PORT_HAND_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[929].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[930].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].entry.ee_code = EEC_BUOYTY_WEST_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[930].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[931].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].entry.ee_code = EEC_BUOYTY_SOUTH_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[931].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[932].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].entry.ee_code = EEC_BUOYTY_EAST_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[932].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[933].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].entry.ee_code = EEC_BUOYTY_NORTH_CARDINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[933].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[934].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].entry.ee_code = EEC_BUOYTY_INSTALLATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[934].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[935].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].entry.ee_code = EEC_BUOYTY_WAVERIDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[935].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[936].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].entry.ee_code = EEC_BUOYTY_WAVE_METER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[936].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[937].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].entry.ee_code = EEC_BUOYTY_NAVIGATION_COMM_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[937].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[938].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].entry.ee_code = EEC_BUOYTY_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[938].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[939].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].entry.ee_code = EEC_BUOYTY_FIRING_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[939].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[940].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].entry.ee_code = EEC_BUOYTY_TARGET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[940].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[941].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].entry.ee_code = EEC_BUOYTY_MARKER_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[941].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[942].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].entry.ee_code = EEC_BUOYTY_DEGAUSSING_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[942].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[943].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[943].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[944].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].entry.ee_code = EEC_BUOYTY_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[944].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[945].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].entry.ee_code = EEC_BUOYTY_OUTFALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[945].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[946].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].entry.ee_code = EEC_BUOYTY_RECORDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[946].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[947].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].entry.ee_code = EEC_BUOYTY_RECREATION_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[947].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[948].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].entry.ee_code = EEC_BUOYTY_LEADING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[948].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[949].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].entry.ee_code = EEC_BUOYTY_MEASURED_DISTANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[949].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[950].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].entry.ee_code = EEC_BUOYTY_TSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[950].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[951].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].entry.ee_code = EEC_BUOYTY_ANCHORING_PROHIBITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[951].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[952].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].entry.ee_code = EEC_BUOYTY_BERTHING_PROHIBITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[952].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[953].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].entry.ee_code = EEC_BUOYTY_OVERTAKING_PROHIBITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[953].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[954].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].entry.ee_code = EEC_BUOYTY_TWO_WAY_PROHIBITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[954].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[955].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].entry.ee_code = EEC_BUOYTY_REDUCED_WAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[955].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[956].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].entry.ee_code = EEC_BUOYTY_SPEED_LIMIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[956].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[957].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].entry.ee_code = EEC_BUOYTY_STOP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[957].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[958].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].entry.ee_code = EEC_BUOYTY_SOUND_SHIPS_SIREN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[958].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[959].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].entry.ee_code = EEC_BUOYTY_RESTRICT_VERT_CLEAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[959].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[960].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].entry.ee_code = EEC_BUOYTY_MAXIMUM_VESSEL_DRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[960].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[961].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].entry.ee_code = EEC_BUOYTY_RESTRICT_HORIZ_CLEAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[961].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[962].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].entry.ee_code = EEC_BUOYTY_STRONG_CURRENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[962].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[963].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].entry.ee_code = EEC_BUOYTY_BERTHING_PERMITTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[963].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[964].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].entry.ee_code = EEC_BUOYTY_ELEVATED_ELECTRICAL_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[964].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[965].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].entry.ee_code = EEC_BUOYTY_CHANNEL_EDGE_GRADIENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[965].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[966].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].entry.ee_code = EEC_BUOYTY_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[966].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[967].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].entry.ee_code = EEC_BUOYTY_FERRY_CROSSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[967].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[968].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].enum_val = 133;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].entry.ee_code = EEC_BUOYTY_PIPELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[968].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[969].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].enum_val = 134;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].entry.ee_code = EEC_BUOYTY_CLEARING_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[969].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[970].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].enum_val = 135;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].entry.ee_code = EEC_BUOYTY_REFUGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[970].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[971].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].enum_val = 136;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].entry.ee_code = EEC_BUOYTY_FOUL_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[971].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[972].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].enum_val = 137;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].entry.ee_code = EEC_BUOYTY_YACHTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[972].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[973].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].enum_val = 138;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].entry.ee_code = EEC_BUOYTY_HELIPORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[973].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[974].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].enum_val = 139;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].entry.ee_code = EEC_BUOYTY_GPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[974].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[975].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].enum_val = 140;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].entry.ee_code = EEC_BUOYTY_WORK_IN_PROGRESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[975].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[976].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[976].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[977].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[977].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[978].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[978].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[979].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[979].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[980].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[980].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[981].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].entry.information = "<= 5%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[981].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[982].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].entry.information = "> 5% and <= 15%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[982].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[983].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].entry.information = "> 15% and <= 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[983].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[984].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].entry.information = "> 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[984].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[985].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[985].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[986].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[986].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[987].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[987].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[988].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[988].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[989].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].entry.information = "<= 5%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[989].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[990].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].entry.information = "> 5% and <= 15%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[990].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[991].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].entry.information = "> 15% and <= 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[991].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[992].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].entry.information = "> 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[992].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[993].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[993].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[994].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[994].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[995].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[995].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[996].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].entry.ee_code = EEC_CABLETY_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[996].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[997].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[997].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[998].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].entry.ee_code = EEC_CABLETY_POWER_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[998].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[999].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].entry.ee_code = EEC_CABLETY_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[999].entry.entry_list = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt1 */

