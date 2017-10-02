/*
 * FILE: edcs_facc_enum_iso2.c
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
local_init_facc_attribute_enum_mapping_pt2( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].entry.ee_code = EEC_CABLETY_TELEGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1000].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].entry.ee_code = EEC_CABLETY_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1001].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].entry.ee_code = EEC_CABLETY_POWER_TRANSMISSION_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1002].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1003].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1004].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1005].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1006].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1007].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].entry.ee_code = EEC_DATACOLLCRIT_NOT_REQUESTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1008].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].entry.ee_code = EEC_DATACOLLCRIT_TOO_ROUGH_TO_COLLECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1009].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].entry.ee_code = EEC_DATACOLLCRIT_NO_AVAILABLE_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1010].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].entry.ee_code = EEC_DATACOLLCRIT_DIFFERENT_HEIGHT_THRESHOLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1011].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].entry.ee_code = EEC_DATACOLLCRIT_LOW_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1012].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].entry.ee_code = EEC_DATACOLLCRIT_NO_AVAILABLE_MAP_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1013].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].entry.ee_code = EEC_DATACOLLCRIT_NO_SUITABLE_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1014].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].entry.ee_code = EEC_DATACOLLCRIT_NOT_REQUIRED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1015].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].entry.ee_code = EEC_DATACOLLCRIT_COLLECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1016].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].entry.ee_code = EEC_DATACOLLCRIT_DERIVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1017].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1018].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1019].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1020].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1021].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].entry.ee_code = EEC_RTECONSTY_GATEWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1022].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].entry.ee_code = EEC_RTECONSTY_NARROW_PASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1023].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].entry.ea_code = EAC_ROUTE_EXPANSION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].entry.ee_code = EEC_RTEEXPNTY_ROAD_SIDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].entry.information = "Split from \"Constriction / Expansion Type\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1024].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].entry.ee_code = EEC_RTECONSTY_BUILDING_PASSAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1025].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].entry.ee_code = EEC_RTECONSTY_UNDERPASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1026].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1027].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1028].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1029].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1030].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1031].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].entry.ee_code = EEC_COLOURATION_BLACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1032].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].entry.ee_code = EEC_COLOURATION_BLUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1033].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].entry.ee_code = EEC_COLOURATION_BROWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1034].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].entry.ee_code = EEC_COLOURATION_GREY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1035].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].entry.ee_code = EEC_COLOURATION_GREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1036].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].entry.ee_code = EEC_COLOURATION_CHOCOLATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1037].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1038].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].entry.ee_code = EEC_COLOURATION_ORANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1039].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1040].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1041].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].entry.ee_code = EEC_COLOURATION_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1042].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1043].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].entry.ee_code = EEC_COLOURATION_LIGHTPURPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1044].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].entry.ee_code = EEC_COLOURATION_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1045].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1046].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1047].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1048].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].entry.ee_code = EEC_COLOURATION_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1049].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].entry.ee_code = EEC_COLOURATION_RED_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1050].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].entry.ee_code = EEC_COLOURATION_GREEN_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].entry.information = "Was: \"Red & Green (RG)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1051].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].entry.ee_code = EEC_COLOURATION_BLACK_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].entry.information = "Was: \"Red & Black (RB)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1052].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].entry.ee_code = EEC_COLOURATION_GREEN_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].entry.information = "Was: \"Red-Green-Red (RGR)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1053].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].entry.ee_code = EEC_COLOURATION_GREEN_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1054].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].entry.ee_code = EEC_COLOURATION_GREEN_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1055].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].entry.ee_code = EEC_COLOURATION_BLACK_GREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].entry.information = "Was: \"Green & Black (GB)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1056].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].entry.ee_code = EEC_COLOURATION_GREEN_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].entry.information = "Was: \"Green-Red-Green (GRG)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1057].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].entry.ee_code = EEC_COLOURATION_BLACK_GREEN_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1058].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].entry.ee_code = EEC_COLOURATION_BLACK_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].entry.information = "Was: \"Yellow & Black (YB)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1059].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].entry.ee_code = EEC_COLOURATION_BLACK_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].entry.information = "Was: \"Yellow-Black-Yellow (YBY)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1060].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].entry.ee_code = EEC_COLOURATION_RED_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1061].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].entry.ee_code = EEC_COLOURATION_GREEN_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1062].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].entry.ee_code = EEC_COLOURATION_RED_WHITE_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1063].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].entry.ee_code = EEC_COLOURATION_BLACK_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1064].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].entry.ee_code = EEC_COLOURATION_BLACK_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].entry.information = "Was: \"Black-Yellow-Black (BYB)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1065].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].entry.ee_code = EEC_COLOURATION_BLACK_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].entry.information = "Was: \"Black-Red-Black (BRB)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1066].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].entry.ee_code = EEC_COLOURATION_BLACK_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1067].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].entry.ee_code = EEC_COLOURATION_BLACK_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1068].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].entry.ee_code = EEC_COLOURATION_BLACK_GREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1069].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].entry.ee_code = EEC_COLOURATION_RED_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].entry.information = "Was: \"White & Red (WR)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1070].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].entry.ee_code = EEC_COLOURATION_ORANGE_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1071].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].entry.ee_code = EEC_COLOURATION_GREEN_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].entry.information = "Was: \"White & Green (WG)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1072].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].entry.ee_code = EEC_COLOURATION_BLACK_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].entry.information = "Was: \"White & Black (WB)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1073].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].entry.ee_code = EEC_COLOURATION_WHITE_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1074].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].entry.ee_code = EEC_COLOURATION_GREEN_RED_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1075].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].entry.ee_code = EEC_COLOURATION_GREEN_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].entry.information = "Was: \"White-Green-White (WGW)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1076].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].entry.ee_code = EEC_COLOURATION_MAGENTA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1077].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].entry.ee_code = EEC_COLOURATION_AMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1078].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].entry.ee_code = EEC_COLOURATION_TAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1079].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].entry.ee_code = EEC_COLOURATION_DARKPURPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1080].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].entry.ee_code = EEC_COLOURATION_PINK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1081].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1082].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1083].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1084].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1085].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1086].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1087].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1088].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Not Applicable)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1089].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1090].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1091].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1092].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COVERED_DRAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1093].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECORDING_DATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1094].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].entry.ee_code = EEC_RCRDDATETY_AERIAL_PHOTOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1095].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].entry.ee_code = EEC_RCRDDATETY_AIR_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1096].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].entry.ee_code = EEC_RCRDDATETY_APPROXIMATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1097].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].entry.ee_code = EEC_RCRDDATETY_FIELD_CLASSIFICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1098].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].entry.ee_code = EEC_RCRDDATETY_COMPILATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1099].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].entry.ee_code = EEC_RCRDDATETY_COPYRIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1100].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].entry.ee_code = EEC_RCRDDATETY_CREATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1101].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].entry.ee_code = EEC_RCRDDATETY_DIGITIZING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1102].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].entry.ee_code = EEC_RCRDDATETY_DISTRIBUTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1103].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].entry.ee_code = EEC_RCRDDATETY_DOWNGRADING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1104].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].entry.ee_code = EEC_RCRDDATETY_DRAWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1105].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].entry.ee_code = EEC_RCRDDATETY_EDITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1106].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].entry.ee_code = EEC_RCRDDATETY_FIELD_EXAMINATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1107].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].entry.ee_code = EEC_RCRDDATETY_INTELLIGENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1108].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].entry.ee_code = EEC_RCRDDATETY_INTERPRETABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1109].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].entry.ee_code = EEC_RCRDDATETY_PROCESSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1110].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].entry.ee_code = EEC_RCRDDATETY_PUBLISHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1111].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].entry.ee_code = EEC_RCRDDATETY_RECEIPT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1112].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].entry.ee_code = EEC_RCRDDATETY_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1113].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].entry.ee_code = EEC_RCRDDATETY_EARLIEST_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1114].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].entry.ee_code = EEC_RCRDDATETY_LATEST_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1115].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].entry.ee_code = EEC_RCRDDATETY_SPECIFICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1116].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].entry.ee_code = EEC_RCRDDATETY_SURVEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1117].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].entry.ee_code = EEC_RCRDDATETY_REVISION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1118].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].entry.ee_code = EEC_RCRDDATETY_MAP_EDIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1119].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].entry.ee_code = EEC_RCRDDATETY_INFORMATION_AS_OF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].entry.ee_code = EEC_RCRDDATETY_PERISHABLE_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].entry.ee_code = EEC_RCRDDATETY_CYCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1122].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].entry.ee_code = EEC_RCRDDATETY_SIGNIFICANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1123].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].entry.ee_code = EEC_RCRDDATETY_MAGNETIC_INFO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1124].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].entry.ee_code = EEC_RCRDDATETY_NOTICE_TO_MARINERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1125].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECORDING_DATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1126].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECORDING_DATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1127].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECORDING_DATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1128].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECORDING_DATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1129].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GRADING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1130].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].entry.ea_code = EAC_GRADING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].entry.ee_code = EEC_GRDTY_ONE_SIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1131].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].entry.ea_code = EAC_GRADING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].entry.ee_code = EEC_GRDTY_TWO_SIDES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1132].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GRADING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1133].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GRADING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1134].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GRADING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1135].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].code.tag, "CET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GRADING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1136].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1137].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].entry.ee_code = EEC_LGTPAT_ALTERNATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].entry.ee_code = EEC_LGTPAT_COMPOSITE_GROUP_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].entry.ee_code = EEC_LGTPAT_COMPOSITE_GROUP_OCCULTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1140].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].entry.ee_code = EEC_LGTPAT_ULTRA_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1141].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].entry.ee_code = EEC_LGTPAT_FIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].entry.ee_code = EEC_LGTPAT_FIXED_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1143].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].entry.ee_code = EEC_LGTPAT_FIXED_GROUP_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].entry.ee_code = EEC_LGTPAT_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1145].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].entry.ee_code = EEC_LGTPAT_GROUP_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1146].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].entry.ee_code = EEC_LGTPAT_GROUP_OCCULTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1147].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].entry.ee_code = EEC_LGTPAT_INTERRUPTED_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].entry.ee_code = EEC_LGTPAT_INTERRUPTED_ULTRA_QUICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].entry.ee_code = EEC_LGTPAT_INTERRUPTED_VERY_QUICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].entry.ee_code = EEC_LGTPAT_ISOPHASE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].entry.ee_code = EEC_LGTPAT_LONG_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].entry.ee_code = EEC_LGTPAT_MORSE_CODE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].entry.ee_code = EEC_LGTPAT_OCCULTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1155].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1156].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].entry.ee_code = EEC_LGTPAT_LIGHTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1158].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].entry.ee_code = EEC_LGTPAT_UNLIGHTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1160].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1161].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1162].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1163].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].entry.ee_code = EEC_LGTPAT_GROUP_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1164].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].entry.ee_code = EEC_LGTPAT_GROUP_VERY_QUICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1165].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].entry.ee_code = EEC_LGTPAT_VERY_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].entry.information = "Was: \"Very quick\". Now deprecated by FACC.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1166].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].entry.ee_code = EEC_LGTPAT_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].entry.information = "Was: \"Quick\". Now deprecated by FACC.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1167].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1168].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].entry.ee_code = EEC_LGTPAT_INTENSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1170].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1171].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].entry.ee_code = EEC_LGTPAT_DIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1172].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1173].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1174].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1175].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1176].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1177].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1178].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].entry.ee_code = EEC_LGTPAT_DIRECTIONAL_MOIRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1179].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].entry.ee_code = EEC_LGTPAT_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1180].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].entry.ee_code = EEC_LGTPAT_VERY_QUICK_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1181].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].entry.ee_code = EEC_LGTPAT_FLASHING_LONG_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1182].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].entry.ee_code = EEC_LGTPAT_OCCULTING_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1183].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].entry.ee_code = EEC_LGTPAT_FIXED_LONG_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].entry.information = "Erroneously mapped to FLASHING_LONG_FLASH in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].entry.ee_code = EEC_LGTPAT_OCCULTING_ALTERNATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1185].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].entry.ee_code = EEC_LGTPAT_LONG_FLASHING_ALTERNATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1186].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].entry.ee_code = EEC_LGTPAT_FLASH_ALTERNATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1187].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].entry.ee_code = EEC_LGTPAT_GROUP_ALTERNATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1188].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].entry.ee_code = EEC_LGTPAT_TWO_FIXED_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1189].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].entry.ee_code = EEC_LGTPAT_TWO_FIXED_HORIZONTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1190].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].entry.ee_code = EEC_LGTPAT_THREE_FIXED_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1191].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].entry.ee_code = EEC_LGTPAT_THREE_FIXED_HORIZONTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1192].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].entry.ee_code = EEC_LGTPAT_QUICK_PLUS_LONG_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1193].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].entry.ee_code = EEC_LGTPAT_VERY_QUICK_PLUS_LONG_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1194].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].entry.ee_code = EEC_LGTPAT_ULTRA_PLUS_LONG_FLASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1195].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].entry.ee_code = EEC_LGTPAT_FIXED_ALTERNATING_FLASHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1196].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1197].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1198].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1199].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1200].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1201].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].entry.ee_code = EEC_WTRCHNLTY_LAGOONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1202].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1203].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1204].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1205].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1206].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOUR_INTENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1207].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].entry.ea_code = EAC_COLOUR_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].entry.ee_code = EEC_COLRINT_DARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1208].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].entry.ea_code = EAC_COLOUR_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].entry.ee_code = EEC_COLRINT_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1209].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOUR_INTENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1210].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOUR_INTENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1211].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOUR_INTENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1212].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_COLOUR_INTENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1213].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1214].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1215].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1216].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1217].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1218].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1219].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1220].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAPID_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1221].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].entry.ee_code = EEC_RAPIDCLS_I;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1222].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].entry.ee_code = EEC_RAPIDCLS_II;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1223].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].entry.ee_code = EEC_RAPIDCLS_III;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1224].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].entry.ee_code = EEC_RAPIDCLS_IV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1225].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].entry.ee_code = EEC_RAPIDCLS_V;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1226].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].entry.ee_code = EEC_RAPIDCLS_VI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1227].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAPID_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1228].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAPID_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1229].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAPID_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1230].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAPID_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1231].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONSPICUOUSNESS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1232].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].entry.ee_code = EEC_CONSPIC_FROM_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1233].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONSPICUOUSNESS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1234].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].entry.ee_code = EEC_CONSPIC_RADAR_FROM_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1235].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].entry.ee_code = EEC_CONSPIC_FROM_LAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1236].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].entry.ee_code = EEC_CONSPIC_FROM_AIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1237].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].entry.ee_code = EEC_CONSPIC_INCONSPICUOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1238].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].entry.ee_code = EEC_CONSPIC_GENERALLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1239].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].entry.ee_code = EEC_CONSPIC_NOT_VISIBLE_FROM_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1240].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].entry.ee_code = EEC_CONSPIC_VISIBLE_FROM_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1241].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].entry.ee_code = EEC_CONSPIC_NOT_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONSPICUOUSNESS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1243].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONSPICUOUSNESS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1244].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONSPICUOUSNESS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1245].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].code.tag, "COC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONSPICUOUSNESS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1246].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1247].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1248].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1249].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1250].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1251].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1252].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].code.tag, "COD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DELINEATION_CERTAIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1253].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1254].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].entry.ee_code = EEC_EXISTCERT_DEFINITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1255].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].entry.ee_code = EEC_EXISTCERT_DOUBTFUL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1256].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].entry.ee_code = EEC_EXISTCERT_REPORTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1257].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1258].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1259].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1260].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].code.tag, "COE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1261].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].code.tag, "COT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONTOUR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1262].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].code.tag, "COT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].entry.ea_code = EAC_CONTOUR_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].entry.ee_code = EEC_CNTURTY_DEPRESSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1263].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].code.tag, "COT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONTOUR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1264].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].code.tag, "COT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONTOUR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1265].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].code.tag, "COT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONTOUR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1266].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].code.tag, "COT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CONTOUR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1267].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1268].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].entry.ee_code = EEC_SURVCTRLPTTY_BENCHMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1269].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].entry.ee_code = EEC_SURVCTRLPTTY_HORIZ_POS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1270].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].entry.ee_code = EEC_SURVCTRLPTTY_HORIZ_POS_AND_BENCHMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1271].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].entry.ee_code = EEC_SURVCTRLPTTY_ASTRONOMIC_POS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1272].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].entry.ee_code = EEC_SURVCTRLPTTY_VERT_POS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].entry.ee_code = EEC_SURVCTRLPTTY_HORIZ_MAIN_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Main Station)\" -- \"Replaced with CPA 8 to map S-57 attributes CATPRN and CATCTR to FACC\"";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].entry.ee_code = EEC_SURVCTRLPTTY_HORIZ_SECONDARY_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Secondary Station)\" -- \"Replaced with CPA 9 to map S-57 attributes CATPRN and CATCTR to FACC\"";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].entry.ee_code = EEC_SURVCTRLPTTY_HORIZ_MAIN_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1276].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].entry.ee_code = EEC_SURVCTRLPTTY_HORIZ_SECONDARY_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1277].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].entry.ee_code = EEC_SURVCTRLPTTY_VERT_MAIN_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1278].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].entry.ee_code = EEC_SURVCTRLPTTY_VERT_SECONDARY_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1279].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1280].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1281].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1282].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1283].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1284].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1285].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].entry.ee_code = EEC_CRANETY_BRIDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1286].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].entry.ee_code = EEC_CRANETY_ROTATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1287].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].entry.ee_code = EEC_CRANETY_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1288].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].entry.ee_code = EEC_CRANETY_FIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1289].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].entry.ee_code = EEC_CRANETY_TRAVELING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1290].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].entry.ee_code = EEC_CRANETY_CONTAINER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1291].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1292].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1293].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1294].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1295].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1296].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].entry.ee_code = EEC_RTECROSSINGTY_T_JUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].entry.ee_code = EEC_RTECROSSINGTY_INTERSECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1298].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].entry.ee_code = EEC_RTECROSSINGTY_STAR_SHAPED_BRANCHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1299].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1300].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1301].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1302].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1303].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1304].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].entry.ee_code = EEC_CRANEMOBTY_FIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1305].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].entry.ee_code = EEC_CRANEMOBTY_TRAVELING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].entry.ee_code = EEC_CRANEMOBTY_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1308].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1309].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1310].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1311].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CROSSING_CONTROL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1312].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].entry.ea_code = EAC_CROSSING_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].entry.ee_code = EEC_CROSSINGCTRL_SIGNAL_DEVICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1313].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].entry.ea_code = EAC_CROSSING_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].entry.ee_code = EEC_CROSSINGCTRL_STOP_SIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1314].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].entry.ea_code = EAC_CROSSING_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].entry.ee_code = EEC_CROSSINGCTRL_NO_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1315].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CROSSING_CONTROL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1316].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CROSSING_CONTROL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1317].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CROSSING_CONTROL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1318].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CROSSING_CONTROL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1319].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1320].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].entry.ee_code = EEC_SECMATCHR_BROKEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1321].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].entry.ee_code = EEC_SECMATCHR_COARSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1322].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].entry.ee_code = EEC_SECMATCHR_DECAYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1323].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].entry.ee_code = EEC_SECMATCHR_FINE_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1324].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].entry.ee_code = EEC_SECMATCHR_GRITTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1325].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].entry.ee_code = EEC_SECMATCHR_HARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1326].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].entry.ee_code = EEC_SECMATCHR_ROTTEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1327].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].entry.ee_code = EEC_SECMATCHR_SOFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1328].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].entry.ee_code = EEC_SECMATCHR_STICKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1329].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].entry.ee_code = EEC_SECMATCHR_STIFF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1330].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].entry.ee_code = EEC_SECMATCHR_STREAKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].entry.ee_code = EEC_SECMATCHR_TENACIOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].entry.ee_code = EEC_SECMATCHR_UNEVEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].entry.ee_code = EEC_SECMATCHR_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1334].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].entry.ee_code = EEC_SECMATCHR_FLINTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1335].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].entry.ee_code = EEC_SECMATCHR_GLACIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1336].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].entry.ee_code = EEC_SECMATCHR_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1337].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].entry.ee_code = EEC_SECMATCHR_LARGE_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1338].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].entry.ee_code = EEC_SECMATCHR_ROCKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].entry.ee_code = EEC_SECMATCHR_SMALL_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].entry.ee_code = EEC_SECMATCHR_SPECKLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].entry.ee_code = EEC_SECMATCHR_VARIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1342].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].entry.ee_code = EEC_SECMATCHR_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1343].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].entry.ee_code = EEC_SECMATCHR_MEDIUM_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1344].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1345].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1346].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1347].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1348].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CULVERT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1349].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].entry.ea_code = EAC_CULVERT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].entry.ee_code = EEC_CULVTY_REG_SOIL_BACK_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1350].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].entry.ea_code = EAC_CULVERT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].entry.ee_code = EEC_CULVTY_BOX_SOIL_BACK_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1351].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].entry.ea_code = EAC_CULVERT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].entry.ee_code = EEC_CULVTY_BOX_LOAD_BEARING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1352].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CULVERT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1353].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CULVERT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1354].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CULVERT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1355].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CULVERT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1356].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1357].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].entry.ee_code = EEC_WTRCURTY_EBB_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1358].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].entry.ee_code = EEC_WTRCURTY_FLOOD_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1359].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].entry.ee_code = EEC_WTRCURTY_GENERAL_FLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1360].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].entry.ee_code = EEC_WTRCURTY_RIVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1361].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].entry.ee_code = EEC_WTRCURTY_OCEAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1362].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].entry.ee_code = EEC_WTRCURTY_RIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1363].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].entry.ee_code = EEC_WTRCURTY_LONGSHORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1364].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1365].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1366].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1367].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1368].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DAM_FACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1369].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].entry.ea_code = EAC_DAM_FACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].entry.ee_code = EEC_DAMFACETY_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1370].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].entry.ea_code = EAC_DAM_FACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].entry.ee_code = EEC_DAMFACETY_SLOPED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1371].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DAM_FACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1372].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DAM_FACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1373].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DAM_FACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1374].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DAM_FACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1375].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DROP_GATE_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1376].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].entry.ea_code = EAC_DROP_GATE_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].entry.ee_code = EEC_DROPGATEMETH_OVERHEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1377].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].entry.ea_code = EAC_DROP_GATE_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].entry.ee_code = EEC_DROPGATEMETH_SIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DROP_GATE_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1379].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DROP_GATE_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1380].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DROP_GATE_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1381].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DROP_GATE_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1382].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RF_DIRECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1383].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].entry.ea_code = EAC_RF_DIRECTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].entry.ee_code = EEC_RFDIRECTIVITY_UNIDIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].entry.ea_code = EAC_RF_DIRECTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].entry.ee_code = EEC_RFDIRECTIVITY_BIDIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1385].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].entry.ea_code = EAC_RF_DIRECTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].entry.ee_code = EEC_RFDIRECTIVITY_OMNIDIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1386].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RF_DIRECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1387].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RF_DIRECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1388].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RF_DIRECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1389].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RF_DIRECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1390].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1391].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].entry.information = "> 0% and <= 5%. (Note: included zero.)";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1392].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].entry.information = "> 5% and <= 15%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1393].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].entry.information = "> 15%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1394].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1395].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1396].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1397].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1398].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].entry.information = "<= 0,8 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1399].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].entry.information = "> 0,8 metre and <= 1,6 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.8;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1400].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].entry.information = "> 1,6 metres and <= 2,4 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.6;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1401].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].entry.information = "> 2,4 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1402].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1403].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1404].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1405].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1406].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].entry.information = "<= 1,6 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 1.6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1407].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].entry.information = "> 1,6 metres and <= 2,4 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.6;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1408].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].entry.information = "> 2,4 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1409].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1410].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1411].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1412].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1413].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].entry.ee_code = EEC_HYDRGBARTY_WEIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1414].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].entry.ee_code = EEC_HYDRGBARTY_DAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1415].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1416].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1417].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1418].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1419].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1420].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].entry.ee_code = EEC_EDUBLDGTY_ACADEMY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1421].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].entry.ee_code = EEC_EDUBLDGTY_COLLEGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1422].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].entry.ee_code = EEC_EDUBLDGTY_EDUCATIONAL_CENTRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1423].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].entry.ee_code = EEC_EDUBLDGTY_LYCEUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1424].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].entry.ee_code = EEC_EDUBLDGTY_UNIVERSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1425].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].entry.ee_code = EEC_EDUBLDGTY_SEMINARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1426].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1427].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1428].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1429].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1430].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1431].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].entry.ee_code = EEC_ELEVACCSTMT_ACCURATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1432].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].entry.ee_code = EEC_ELEVACCSTMT_APPROXIMATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1433].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1434].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1435].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1436].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1437].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1438].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].entry.ee_code = EEC_EXISTSTAT_DEFINITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1439].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].entry.ee_code = EEC_EXISTSTAT_DOUBTFUL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1440].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].entry.ee_code = EEC_EXISTSTAT_REPORTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1441].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1442].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].entry.ee_code = EEC_EXISTSTAT_UNDER_CONSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<UNDER_CONSTRUCTION>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1443].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].entry.ee_code = EEC_EXISTSTAT_ABANDONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<ABANDONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1444].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].entry.ee_code = EEC_EXISTSTAT_DESTROYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<DESTROYED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1445].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].entry.ee_code = EEC_EXISTSTAT_DISMANTLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<DISMANTLED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1446].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].entry.ee_code = EEC_EXISTSTAT_PROPOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<PROPOSED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1447].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].entry.ee_code = EEC_EXISTSTAT_TEMPORARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].entry.information = "Note that this can also be mapped as <<PERMANENT>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1448].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].entry.ee_code = EEC_EXISTSTAT_ALTERNATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1449].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1450].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1451].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1452].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].entry.ee_code = EEC_EXISTSTAT_PERMANENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].entry.information = "Note that this can also be mapped as <<PERMANENT>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1453].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1454].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].entry.ee_code = EEC_EXISTSTAT_CORRESPONDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].entry.information = "Note that this can also be mapped as <<RECOMMENDED_TRACK>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1455].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].entry.ee_code = EEC_EXISTSTAT_DOES_NOT_CORRESPOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].entry.information = "Note that this can also be mapped as <<RECOMMENDED_TRACK>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1456].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].entry.ee_code = EEC_EXISTSTAT_ONE_WAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1457].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].entry.ee_code = EEC_EXISTSTAT_TWO_WAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1458].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].entry.ee_code = EEC_EXISTSTAT_NOT_MAINTAINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].entry.information = "Note that this can also be mapped as <<MAINTAINED>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1459].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].entry.ee_code = EEC_EXISTSTAT_MAINTAINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].entry.information = "Note that this can also be mapped as <<MAINTAINED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1460].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].entry.ee_code = EEC_EXISTSTAT_NOT_ACCESSIBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1461].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].entry.ee_code = EEC_EXISTSTAT_OPERATIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<OPERATIONAL>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1462].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1463].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].entry.ee_code = EEC_EXISTSTAT_NOT_ISOLATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].entry.information = "Note that this can also be mapped as <<ISOLATED>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs. However, note also that <<ISOLATED>> is defined in terms of <FACILITY>, not <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1464].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].entry.ee_code = EEC_EXISTSTAT_ISOLATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].entry.information = "Note that this can also be mapped as <<ISOLATED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs. However, note also that <<ISOLATED>> is defined in terms of <FACILITY>, not <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1465].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].entry.ee_code = EEC_EXISTSTAT_NAVIGABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].entry.information = "Note that this can also be mapped as <<NAVIGABLE_STATUS>>*<<<NAVIGABLE>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1466].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].entry.ee_code = EEC_EXISTSTAT_RUINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<RUINED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1467].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1468].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1469].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].entry.ee_code = EEC_EXISTSTAT_OPERATIONAL_COMMISSIONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].entry.information = "Note that this can also be mapped as <<FACILITY_COMMISSIONED_STATUS>>*<<<OPERATIONAL_COMMISSIONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1470].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].entry.ee_code = EEC_EXISTSTAT_ON_TEST_COMMISSIONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].entry.information = "Note that this can also be mapped as <<FACILITY_COMMISSIONED_STATUS>>*<<<ON_TEST_COMMISSIONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1471].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].entry.ee_code = EEC_EXISTSTAT_OUT_OF_SERVICE_COMMISSIONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].entry.information = "Note that this can also be mapped as <<FACILITY_COMMISSIONED_STATUS>>*<<<OUT_SERVICE_COMMISSIONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1472].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].entry.ee_code = EEC_EXISTSTAT_OPERATIONAL_NOT_COMMISSIONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].entry.information = "Note that this can also be mapped as <<FACILITY_COMMISSIONED_STATUS>>*<<<OPERATIONAL_NOT_COMMISSIONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1473].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].entry.ee_code = EEC_EXISTSTAT_ON_TEST_NOT_COMMISSIONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].entry.information = "Note that this can also be mapped as <<FACILITY_COMMISSIONED_STATUS>>*<<<ON_TEST_NOT_COMMISSIONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1474].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].entry.ee_code = EEC_EXISTSTAT_OUT_OF_SERVICE_NOT_COMMISSIONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].entry.information = "Note that this can also be mapped as <<FACILITY_COMMISSIONED_STATUS>>*<<<OUT_SERVICE_NOT_COMMISSIONED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1475].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].entry.ee_code = EEC_EXISTSTAT_CONTINUOUS_OPERATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].entry.information = "Note that this can also be mapped as <<FACILITY_OPERATION_CONTINUITY>>*<<<CONTINUOUS>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1476].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].entry.ee_code = EEC_EXISTSTAT_INTERMITTENT_OPERATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].entry.information = "Note that this can also be mapped as <<FACILITY_OPERATION_CONTINUITY>>*<<<INTERMITTENT>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1477].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].entry.ee_code = EEC_EXISTSTAT_APPROXIMATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1478].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].entry.ee_code = EEC_EXISTSTAT_NATURAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].entry.information = "Note that this can also be mapped as <<MAN_MADE>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1479].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].entry.ee_code = EEC_EXISTSTAT_MAN_MADE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].entry.information = "Note that this can also be mapped as <<MAN_MADE>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1480].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].entry.ee_code = EEC_EXISTSTAT_SWEPT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].entry.information = "Note that this can also be mapped as <<MINE_SWEPT>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1481].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].entry.ee_code = EEC_EXISTSTAT_CONTROLLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].entry.information = "Note that this can also be mapped as <<CONTROLLED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs. However, note also that <<CONTROLLED>> is defined in terms of <FACILITY>, not <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1482].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].entry.ee_code = EEC_EXISTSTAT_NON_CONTROLLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].entry.information = "Note that this can also be mapped as <<CONTROLLED>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs. However, note also that <<CONTROLLED>> is defined in terms of <FACILITY>, not <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1483].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].entry.ee_code = EEC_EXISTSTAT_NON_TIDAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].entry.information = "Note that this can also be mapped as <<TIDE_INFLUENCED>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1484].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].entry.ee_code = EEC_EXISTSTAT_TIDAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].entry.information = "Note that this can also be mapped as <<TIDE_INFLUENCED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1485].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].entry.ee_code = EEC_EXISTSTAT_DISSIPATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<DISSIPATING>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1486].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].entry.ee_code = EEC_EXISTSTAT_INCOMPLETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<INCOMPLETE>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1487].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].entry.ee_code = EEC_EXISTSTAT_ANCIENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].entry.information = "Note that this can also be mapped as <<HISTORICAL_SIGNIFICANCE>>*<<<ANCIENT>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs. However, note also that <<HISTORICAL_SIGNIFICANCE>> is defined in terms of <STRUCTURE>, not <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1488].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].entry.ee_code = EEC_EXISTSTAT_INDETERMINATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1489].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].entry.ee_code = EEC_EXISTSTAT_UNWATCHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].entry.information = "Note that this can also be mapped as <<MONITORED>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1490].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].entry.ee_code = EEC_EXISTSTAT_SONAR_CONFIRMED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].entry.information = "Note that this can also be mapped as <<SONAR_CONFIRMATION>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1491].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].entry.ee_code = EEC_EXISTSTAT_SONAR_NOT_CONFIRMED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].entry.information = "Note that this can also be mapped as <<SONAR_CONFIRMATION>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1492].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].entry.ee_code = EEC_EXISTSTAT_NOT_USABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<NOT_USABLE>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1493].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].entry.ee_code = EEC_EXISTSTAT_INDEFINITE_SHORELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].entry.information = "Note that this can also be mapped as <<SHORELINE_DELINEATED>>*FALSE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1494].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].entry.ee_code = EEC_EXISTSTAT_DEFINITE_SHORELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].entry.information = "Note that this can also be mapped as <<SHORELINE_DELINEATED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1495].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].entry.ee_code = EEC_EXISTSTAT_PARTIALLY_DESTROYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<PARTIALLY_DESTROYED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1496].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].entry.ee_code = EEC_EXISTSTAT_INACTIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<INACTIVE>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1497].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].entry.ee_code = EEC_EXISTSTAT_DAMAGED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<DAMAGED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1498].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].entry.ee_code = EEC_EXISTSTAT_OCCASIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<OCCASIONAL>>> or <<FACILITY_OPERATION_CONTINUITY>>*<<<OCCASIONAL>>> (depending on context), since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1499].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].entry.ee_code = EEC_EXISTSTAT_RECOMMENDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_STATUS>>*<<<RECOMMENDED>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1500].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].entry.ee_code = EEC_EXISTSTAT_ILLUMINATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1501].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].entry.ee_code = EEC_EXISTSTAT_HISTORIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].entry.information = "Note that this can also be mapped as <<HISTORICAL_SIGNIFICANCE>>*<<<HISTORIC>>>, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs. However, note also that <<HISTORICAL_SIGNIFICANCE>> is defined in terms of <STRUCTURE>, not <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1502].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].entry.ee_code = EEC_EXISTSTAT_SYNCHRONIZED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].entry.information = "Note that this can also be mapped as <<SYNCHRONIZED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].entry.ee_code = EEC_EXISTSTAT_WATCHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].entry.information = "Note that this can also be mapped as <<MONITORED>>*TRUE, since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].enum_val = 723;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].entry.ee_code = EEC_EXISTSTAT_NAVIGABLE_ABANDONED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].entry.information = "Note that this can also be mapped as <<NAVIGABLE_STATUS>>*<<<NAVIGABLE_ABANDONED>>> (or as <<NAVIGABLE_STATUS>>*<<<NAVIGABLE>>>, <<FUNCTIONAL_STATUS>>*<<<ABANDONED>>>), since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].enum_val = 724;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].entry.ee_code = EEC_EXISTSTAT_NAVIGABLE_OPERATIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].entry.information = "Note that this can also be mapped as <<NAVIGABLE_STATUS>>*<<<NAVIGABLE_OPERATIONAL>>> (or as <<NAVIGABLE_STATUS>>*<<<NAVIGABLE>>>, <<FUNCTIONAL_STATUS>>*<<<OPERATIONAL>>>), since <<EXISTENCE_STATUS>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1507].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1508].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1509].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXISTENCE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1510].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1511].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].entry.ee_code = EEC_MARCNSTCTTY_OPEN_PILINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].entry.ee_code = EEC_MARCNSTCTTY_GENERAL_SOLID_FACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1514].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1515].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1516].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1517].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1518].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].entry.ee_code = EEC_OBJCFG_DISPERSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1519].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].entry.information = "Was \"multiple configurations.\"";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1520].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].entry.ee_code = EEC_OBJCFG_SINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1521].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].entry.ee_code = EEC_OBJCFG_INCLINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].entry.ee_code = EEC_OBJCFG_DIVIDED_SAME_WIDTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].entry.ee_code = EEC_OBJCFG_DIVIDED_DIFFERENT_WIDTHS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].entry.ee_code = EEC_OBJCFG_NON_DIVIDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].entry.information = "Was \"poorly defined\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OBJECT_CONFIGURATION_QUALITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1526].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].entry.information = "Was \"well defined\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OBJECT_CONFIGURATION_QUALITY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1527].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].entry.ee_code = EEC_OBJCFG_DOUBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].entry.ee_code = EEC_OBJCFG_JUXTAPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1530].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1531].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1532].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1533].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1534].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1535].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1536].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1537].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1538].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1539].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1540].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1541].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].entry.ee_code = EEC_FERRYRTETY_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1542].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].entry.ee_code = EEC_FERRYRTETY_FREE_MOVING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1543].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].entry.ee_code = EEC_FERRYRTETY_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1544].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1545].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1546].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1547].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].code.tag, "FER", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1548].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1549].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].entry.ee_code = EEC_FUELFACAVAIL_PETROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1550].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].entry.ee_code = EEC_FUELFACAVAIL_AVIATION_FUEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1551].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].entry.ee_code = EEC_FUELFACAVAIL_KEROSENE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1552].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].entry.ee_code = EEC_FUELFACAVAIL_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1553].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].entry.ee_code = EEC_FUELFACAVAIL_DIESEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1554].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].entry.ee_code = EEC_FUELFACAVAIL_COAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1555].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].entry.ee_code = EEC_FUELFACAVAIL_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1556].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].entry.ee_code = EEC_FUELFACAVAIL_LUBRICANTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1557].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].entry.ee_code = EEC_FUELFACAVAIL_METHANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1558].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].entry.ee_code = EEC_FUELFACAVAIL_SPECIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1559].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].entry.ee_code = EEC_FUELFACAVAIL_LIQUIFIED_PETROLEUM_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1560].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].entry.ee_code = EEC_FUELFACAVAIL_COMPRESSED_NATURAL_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1561].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].entry.ee_code = EEC_FUELFACAVAIL_BUTANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1562].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].entry.ee_code = EEC_FUELFACAVAIL_ETHANOL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1563].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1564].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].enum_val = 995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].entry.ee_code = EEC_FUELFACAVAIL_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1565].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1566].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1567].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1568].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1569].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].entry.ee_code = EEC_FISHFACTY_STAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1570].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].entry.ee_code = EEC_FISHFACTY_TRAP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1571].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].entry.ee_code = EEC_FISHFACTY_WEIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1572].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].entry.ee_code = EEC_FISHFACTY_TUNA_NET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1573].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1574].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1575].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1576].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1577].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1578].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].entry.ee_code = EEC_HARBRFACTY_ROLLON_ROLLOFF_FERRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1579].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].entry.ee_code = EEC_HARBRFACTY_TIMBER_YARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1580].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].entry.ee_code = EEC_HARBRFACTY_FERRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1581].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].entry.ee_code = EEC_HARBRFACTY_FISHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1582].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].entry.ee_code = EEC_HARBRFACTY_MARINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1583].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].entry.ee_code = EEC_HARBRFACTY_NAVAL_BASE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1584].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].entry.ee_code = EEC_HARBRFACTY_TANKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1585].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].entry.ee_code = EEC_HARBRFACTY_PASSENGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1586].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].entry.ee_code = EEC_HARBRFACTY_SHIPYARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1587].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].entry.ee_code = EEC_HARBRFACTY_CONTAINER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1588].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].entry.ee_code = EEC_HARBRFACTY_BULK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1589].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1590].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1591].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1592].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1593].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1594].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].entry.ee_code = EEC_STRLGTTY_FLOODLIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].entry.information = "Formerly mapped to a Boolean-valued FLOODLIT.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1595].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].entry.ee_code = EEC_STRLGTTY_NOT_FLOODLIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].entry.information = "Formerly mapped to a Boolean-valued FLOODLIT.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1596].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1597].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1598].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1599].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1600].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1601].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].entry.ee_code = EEC_WEAPRNGTY_SMALL_ARMS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1602].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].entry.ee_code = EEC_WEAPRNGTY_TANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1603].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].entry.ee_code = EEC_WEAPRNGTY_FIELD_ARTILLERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1604].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].entry.ee_code = EEC_WEAPRNGTY_GRENADE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1605].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].entry.ee_code = EEC_WEAPRNGTY_DEMOLITION_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1606].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].entry.ee_code = EEC_WEAPRNGTY_IMPACT_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1607].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1608].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1609].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1610].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1611].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FARMING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1612].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].entry.ea_code = EAC_FARMING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].entry.ee_code = EEC_FARMMETH_SLASH_AND_BURN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1613].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].entry.ea_code = EAC_FARMING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].entry.ee_code = EEC_FARMMETH_PERMACULTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1614].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].entry.ea_code = EAC_FIELD_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].entry.ee_code = EEC_FIELDPAT_TERRACED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1615].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].entry.ea_code = EAC_IRRIGATION_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].entry.ee_code = EEC_IRRIGMETH_DITCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1616].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].entry.ea_code = EAC_FARMING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].entry.ee_code = EEC_FARMMETH_GRAZING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1617].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].entry.ea_code = EAC_FIELD_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].entry.ee_code = EEC_FIELDPAT_REGULAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1618].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].entry.ea_code = EAC_FIELD_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].entry.ee_code = EEC_FIELDPAT_LINEAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1619].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].entry.ea_code = EAC_FARMING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].entry.ee_code = EEC_FARMMETH_CROP_ROTATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1620].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].entry.information = "Deleted: Unable to determine to which EA (<<FARMING_METHOD>>, <<FIELD_PATTERN>>, or <<IRRIGATION_METHOD>>) one would appropriately apply a \"Farming Type\" of EVC_NOT_APPLICABLE.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1621].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FIELD_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1622].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1623].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].entry.information = "Deleted: Unable to determine to which EA (<<FARMING_METHOD>>, <<FIELD_PATTERN>>, or <<IRRIGATION_METHOD>>) one would appropriately apply a \"Farming Type\" of EVC_VALUE_WITHHELD.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1624].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FARMING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1625].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FENCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1626].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].entry.ee_code = EEC_FENCETY_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1627].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].entry.ee_code = EEC_FENCETY_WOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1628].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].entry.ee_code = EEC_FENCETY_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1629].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].entry.ee_code = EEC_FENCETY_LOOSE_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1630].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].entry.ee_code = EEC_FENCETY_BARBED_WIRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1631].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].entry.ee_code = EEC_FENCETY_CHAIN_LINK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1632].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FENCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1633].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FENCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1634].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FENCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1635].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FENCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1636].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FABRICATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1637].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].entry.ea_code = EAC_FABRICATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].entry.ee_code = EEC_FABTY_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1638].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].entry.ea_code = EAC_FABRICATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].entry.ee_code = EEC_FABTY_HEAVY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1639].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FABRICATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1640].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FABRICATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1641].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FABRICATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1642].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FABRICATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1643].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1644].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].entry.ee_code = EEC_OBJORNTWRTVERT_UPRIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1645].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].entry.ee_code = EEC_OBJORNTWRTVERT_ON_SIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1646].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].entry.ee_code = EEC_OBJORNTWRTVERT_LEANING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1647].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].entry.ee_code = EEC_OBJORNTWRTVERT_INVERTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1648].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].entry.ee_code = EEC_OBJORNTWRTVERT_HORIZONTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1649].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1650].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1651].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1652].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1653].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1654].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].entry.ee_code = EEC_FOGSIGGENTY_AUTOMATIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1655].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].entry.ee_code = EEC_FOGSIGGENTY_WAVE_ACTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1656].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].entry.ee_code = EEC_FOGSIGGENTY_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1657].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].entry.ee_code = EEC_FOGSIGGENTY_WIND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1658].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1659].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1660].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1661].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1662].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEOGRAPHIC_REGION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1663].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].entry.ea_code = EAC_GEOGRAPHIC_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].entry.ee_code = EEC_GEOREGN_ARCTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1664].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEOGRAPHIC_REGION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1665].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEOGRAPHIC_REGION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1666].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEOGRAPHIC_REGION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1667].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEOGRAPHIC_REGION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1668].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].entry.information = "Deleted: \"Unknown\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1669].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].entry.information = "Deleted: \"Greater than or equal to contour interval\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1670].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].entry.information = "Deleted: \"Less than contour interval\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1671].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].entry.information = "Deleted: \"Unpopulated\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1672].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].entry.information = "Deleted: \"Not Applicable\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1673].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].entry.information = "Deleted: \"Other\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1674].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1675].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].entry.ee_code = EEC_NAUTGATETY_GENERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1676].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].entry.ee_code = EEC_NAUTGATETY_TIDAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1677].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].entry.ee_code = EEC_NAUTGATETY_CAISSON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1678].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].entry.ee_code = EEC_NAUTGATETY_LOCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1679].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].entry.ee_code = EEC_NAUTGATETY_DYKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1680].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1681].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1682].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1683].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1684].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1685].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].entry.information = "0% to > 45%: Culturally or naturally dissected land.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DISSECTED_TERRAIN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1686].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].entry.information = "<= 3%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 3.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1687].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].entry.information = "> 3% and <= 10%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 3.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1688].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].entry.information = "> 10% and <= 20%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1689].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].entry.information = "> 20% and <= 30%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1690].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].entry.information = "> 30% and <= 45%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 45.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1691].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].entry.information = "> 45%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 45.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1692].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].entry.information = "> 10% and <= 15%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1693].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].entry.information = "> 15% and <= 20%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1694].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].entry.information = "> 45% and <= 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 45.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1695].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].entry.information = "> 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1696].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].entry.information = "> 60% and <= 85%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 60.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 85.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1697].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].entry.information = "> 85%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 85.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1698].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1699].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1700].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1701].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1702].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1703].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].entry.ea_code = EAC_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].entry.ee_code = EEC_GATETY_TOLL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1704].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].entry.ea_code = EAC_GATE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].entry.ee_code = EEC_GATETY_CROSSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1705].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1706].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1707].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1708].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1709].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GATE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1710].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1711].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1712].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1713].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1714].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1715].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1716].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GUYED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1717].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1718].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].entry.information = "<= 3,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 3.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1719].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].entry.information = "> 3,0 metres and <= 18,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 3.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 18.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1720].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].entry.information = "> 18,0 metres and <= 25,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 18.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 25.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1721].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].entry.information = "> 25,0 metres and <= 50,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1722].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].entry.information = "> 50,0 metres and <= 75,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 75.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1723].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].entry.information = "> 75,0 metres and <= 100,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 75.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1724].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].entry.information = "> 100,0 metres and <= 142,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 100.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 142.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1725].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].entry.information = "> 142,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 142.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1726].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1727].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1728].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1729].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1730].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].entry.information = "> 18,0 metres and <= 142,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 18.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 142.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1731].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].entry.information = "> 142,0 metres and <= 1 000,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 142.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1000.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1732].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].entry.information = "> 1 000 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 1000.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1733].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1734].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1735].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1736].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1737].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].entry.information = "<= 1,5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1738].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].entry.information = "> 1,5 metres and <= 3,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 3.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1739].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].entry.information = "> 3,0 metres and <= 18,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 3.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 18.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1740].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].entry.information = "> 18,0 metres and <= 25,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 18.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 25.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1741].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].entry.information = "> 25,0 metres and <= 50,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1742].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].entry.information = "> 30,0 metres and <= 35,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1743].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].entry.information = "> 35,0 metres and <= 40,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 35.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1744].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].entry.information = "> 40,0 metres and <= 45,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 40.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 45.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1745].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].entry.information = "> 45,0 metres and <= 50,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 45.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1746].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].entry.information = "> 50,0 metres and <= 75,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 75.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1747].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].entry.information = "> 75,0 metres and <= 100,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 75.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1748].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].entry.information = "> 100,0 metres and <= 142,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 100.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 142.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1749].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].entry.information = "> 142,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 142.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1750].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1751].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1752].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1753].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1754].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1755].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1756].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1757].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1758].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1759].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1760].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1761].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].entry.ee_code = EEC_HYDRGDEPINF_KNOWN_OTHER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1762].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].entry.ee_code = EEC_HYDRGDEPINF_KNOWN_WIRE_DRAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1763].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].entry.ee_code = EEC_HYDRGDEPINF_UNKNOWN_BUT_SAFE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1764].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].entry.ee_code = EEC_HYDRGDEPINF_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1765].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].entry.information = "Split from \"Hydrographic Depth Information\", previous version of mapping.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_UNCOVERING_HEIGHT_KNOWN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1766].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].entry.information = "Split from \"Hydrographic Depth Information\", previous version of mapping.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_UNCOVERING_HEIGHT_KNOWN;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1767].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1768].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1769].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1770].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1771].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1772].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].entry.ee_code = EEC_WTRCRSCHNLTY_CHANNELIZED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1773].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].entry.ea_code = EAC_WATERCOURSE_SINK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].entry.ee_code = EEC_WTRCRSSINKTY_DISAPPEARING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1774].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TIDE_INFLUENCED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1775].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].entry.ee_code = EEC_WTRCRSCHNLTY_NON_MEANDERING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1776].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TIDE_INFLUENCED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1777].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].entry.ee_code = EEC_WTRCRSCHNLTY_BRAIDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1778].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].entry.ea_code = EAC_WATERCOURSE_SINK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].entry.ee_code = EEC_WTRCRSSINKTY_DISSIPATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1779].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].entry.ee_code = EEC_WTRCRSCHNLTY_GORGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1780].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].entry.ee_code = EEC_WTRCRSCHNLTY_WADI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1781].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].entry.ea_code = EAC_WATERCOURSE_SINK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].entry.ee_code = EEC_WTRCRSSINKTY_SINKHOLE_DISAPPEARING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1782].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].entry.ea_code = EAC_WATERCOURSE_SINK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].entry.ee_code = EEC_WTRCRSSINKTY_OTHER_DISAPPEARING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1783].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].entry.ee_code = EEC_WTRCRSCHNLTY_OXBOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1784].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].entry.ee_code = EEC_WTRCRSCHNLTY_BRAIDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].entry.information = "Was: \"Split stream\". Need to add new SPLIT_STREAM enumerant where \"an island is dividing a channel\" (much less complex than BRAIDED).";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1785].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1786].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1787].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1788].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1789].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1790].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].entry.information = "<= 0,5 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1791].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].entry.information = "> 0,5 metre and <= 1,0 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1792].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].entry.information = "> 1,0 metre and <= 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1793].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].entry.information = "> 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1794].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1795].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1796].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1797].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1798].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].entry.information = "<= 1,0 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1799].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].entry.information = "> 1,0 metre and <= 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1800].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].entry.information = "> 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1801].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1802].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1803].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1804].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1805].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].entry.information = "<= 0,2 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1806].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].entry.information = "> 0,2 metre and <= 0,5 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.2;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1807].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].entry.information = "> 0,5 metre and <= 1,0 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1808].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].entry.information = "> 1,0 metre and <= 1,5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1809].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].entry.information = "> 1,5 metres and <= 2,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1810].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].entry.information = "> 2,0 metres and <= 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 2.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1811].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].entry.information = "> 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1812].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1813].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1814].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1815].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HULK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1816].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].entry.ea_code = EAC_HULK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].entry.ee_code = EEC_HULKTY_RESTAURANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1817].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].entry.ea_code = EAC_HULK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].entry.ee_code = EEC_HULKTY_HISTORIC_SHIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1818].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].entry.ea_code = EAC_HULK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].entry.ee_code = EEC_HULKTY_MUSEUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1819].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].entry.ea_code = EAC_HULK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].entry.ee_code = EEC_HULKTY_ACCOMMODATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1820].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].entry.ea_code = EAC_HULK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].entry.ee_code = EEC_HULKTY_FLOATING_BREAKWATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1821].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HULK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1822].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HULK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1823].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HULK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1824].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HULK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1825].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1826].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].entry.ee_code = EEC_MARLGTTY_SECTORED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1827].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1828].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].entry.ee_code = EEC_MARLGTTY_MOIRE_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1829].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].entry.ee_code = EEC_MARLGTTY_STRIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1830].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].entry.ee_code = EEC_MARLGTTY_OCCASIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1831].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].entry.ee_code = EEC_MARLGTTY_LIGHTED_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1832].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].entry.ee_code = EEC_MARLGTTY_DIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1833].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].entry.ee_code = EEC_MARLGTTY_VERTICALLY_DISPOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1834].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1835].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1836].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1837].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1838].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1839].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].entry.ee_code = EEC_HYDRGOBJORIG_CONTROLLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1840].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].entry.ee_code = EEC_HYDRGOBJORIG_MAN_MADE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1841].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].entry.ee_code = EEC_HYDRGOBJORIG_NATURAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1842].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1843].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1844].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1845].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1846].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1847].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].entry.ee_code = EEC_GDDTMID_ADINDAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1848].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].entry.ee_code = EEC_GDDTMID_AFGOOYE_SOMALIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1849].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].entry.ee_code = EEC_GDDTMID_AIN_EL_ABD_1970;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1850].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].entry.ee_code = EEC_GDDTMID_ANNA_1_ASTRO_1965;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1851].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].entry.ee_code = EEC_GDDTMID_ANTIGUA_ISLAND_ASTRO_1943;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1852].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].entry.ee_code = EEC_GDDTMID_ARC_1950;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1853].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].entry.ee_code = EEC_GDDTMID_ARC_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1854].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].entry.ee_code = EEC_GDDTMID_ASCENSION_ISLAND_1958;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1855].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].entry.ee_code = EEC_GDDTMID_ASTRO_BEACON_E_1945;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1856].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].entry.ee_code = EEC_GDDTMID_ASTRO_DOS_71_4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1857].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].entry.ee_code = EEC_GDDTMID_ASTRO_TERN_IS_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1858].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].entry.ee_code = EEC_GDDTMID_ASTRO_STATION_1952;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1859].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].entry.ee_code = EEC_GDDTMID_AUSTRALIAN_GEOD_1966;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1860].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].entry.ee_code = EEC_GDDTMID_AUSTRALIAN_GEOD_1984;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1861].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].entry.ee_code = EEC_GDDTMID_AYABELLE_LIGHTHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1862].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].entry.ee_code = EEC_GDDTMID_BELLEVUE_IGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1863].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].entry.ee_code = EEC_GDDTMID_BERMUDA_1957;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1864].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].entry.ee_code = EEC_GDDTMID_BISSAU;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1865].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].entry.ee_code = EEC_GDDTMID_BOGOTA_OBS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1866].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].entry.ee_code = EEC_GDDTMID_BUKIT_RIMPAH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1867].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].entry.ee_code = EEC_GDDTMID_CAMP_AREA_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1868].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].entry.ee_code = EEC_GDDTMID_CAMPO_INCHAUSPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1869].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].entry.ee_code = EEC_GDDTMID_CANTON_ASTRO_1966;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1870].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].entry.ee_code = EEC_GDDTMID_CAPE_SOUTH_AFRICA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1871].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].entry.ee_code = EEC_GDDTMID_CAPE_CANAVERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1872].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].entry.ee_code = EEC_GDDTMID_CARTHAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1873].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].entry.ee_code = EEC_GDDTMID_CHATHAM_ASTRO_1971;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1874].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].entry.ee_code = EEC_GDDTMID_CHUA_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1875].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].entry.ee_code = EEC_GDDTMID_CORREGO_ALEGRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1876].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].entry.ee_code = EEC_GDDTMID_DABOLA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1877].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].entry.ee_code = EEC_GDDTMID_DJAKARTA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1878].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].entry.ee_code = EEC_GDDTMID_DOS_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1879].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].entry.ee_code = EEC_GDDTMID_EASTER_ISLAND_1967;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1880].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].entry.ee_code = EEC_GDDTMID_EUR_1950;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1881].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].entry.ee_code = EEC_GDDTMID_EUR_1979;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1882].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].entry.ee_code = EEC_GDDTMID_FORT_THOMAS_1955;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1883].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].entry.ee_code = EEC_GDDTMID_GAN_1970;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1884].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].entry.ee_code = EEC_GDDTMID_GEODETIC_DATUM_1949;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1885].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].entry.ee_code = EEC_GDDTMID_GRACIOSA_BASE_SW_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1886].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].entry.ee_code = EEC_GDDTMID_GUAM_1963;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1887].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].entry.ee_code = EEC_GDDTMID_GUNONG_SEGARA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1888].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].entry.ee_code = EEC_GDDTMID_GUX_1_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1889].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].entry.ee_code = EEC_GDDTMID_HERAT_NORTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1890].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].entry.ee_code = EEC_GDDTMID_HJORSEY_1955;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1891].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].entry.ee_code = EEC_GDDTMID_HONG_KONG_1963;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1892].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].entry.ee_code = EEC_GDDTMID_HU_TZU_SHAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1893].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].entry.ee_code = EEC_GDDTMID_INDIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1894].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].entry.ee_code = EEC_GDDTMID_INDIAN_1954;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1895].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].entry.ee_code = EEC_GDDTMID_INDIAN_1975;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1896].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].entry.ee_code = EEC_GDDTMID_IRELAND_1965;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1897].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].entry.ee_code = EEC_GDDTMID_ISTS_061_ASTRO_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1898].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].entry.ee_code = EEC_GDDTMID_ISTS_073_ASTRO_1969;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1899].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].entry.ee_code = EEC_GDDTMID_JOHNSTON_ISLAND_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1900].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].entry.ee_code = EEC_GDDTMID_KANDAWALA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1901].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].entry.ee_code = EEC_GDDTMID_KERGUELEN_ISLAND_1949;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1902].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].entry.ee_code = EEC_GDDTMID_KERTAU_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1903].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].entry.ee_code = EEC_GDDTMID_KUSAIE_ASTRO_1951;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1904].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].entry.ee_code = EEC_GDDTMID_LC5_ASTRO_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1905].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].entry.ee_code = EEC_GDDTMID_LEIGON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1906].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].entry.ee_code = EEC_GDDTMID_LIBERIA_1964;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1907].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].entry.ee_code = EEC_GDDTMID_LUZON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1908].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].entry.ee_code = EEC_GDDTMID_MAHE_1971;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1909].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].entry.ee_code = EEC_GDDTMID_MASSAWA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1910].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].entry.ee_code = EEC_GDDTMID_MERCHICH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1911].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].entry.ee_code = EEC_GDDTMID_MIDWAY_ASTRO_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1912].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].entry.ee_code = EEC_GDDTMID_MINNA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1913].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].entry.ee_code = EEC_GDDTMID_MONTSERRAT_ASTRO_1958;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1914].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].entry.ee_code = EEC_GDDTMID_M_PORALOKO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1915].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].entry.ee_code = EEC_GDDTMID_NAHRWAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1916].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].entry.ee_code = EEC_GDDTMID_NAPARIMA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1917].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].entry.ee_code = EEC_GDDTMID_N_AM_1927;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1918].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].entry.ee_code = EEC_GDDTMID_N_AM_1983;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1919].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].entry.ee_code = EEC_GDDTMID_OBSERV_METEORO_1939;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1920].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].entry.ee_code = EEC_GDDTMID_OLD_EGYPTIAN_1907;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1921].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1922].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].entry.ee_code = EEC_GDDTMID_FAHUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1923].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].entry.ee_code = EEC_GDDTMID_OSGB_1936;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1924].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].entry.ee_code = EEC_GDDTMID_PICO_DE_LAS_NIEVES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1925].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].entry.ee_code = EEC_GDDTMID_PITCAIRN_ASTRO_1967;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1926].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].entry.ee_code = EEC_GDDTMID_POINT_58_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1927].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].entry.ee_code = EEC_GDDTMID_POINTE_NOIRE_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1928].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].entry.ee_code = EEC_GDDTMID_PORTO_SANTO_1936;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1929].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1930].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].entry.ee_code = EEC_GDDTMID_PROV_S_CHILEAN_1963;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1931].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].entry.ee_code = EEC_GDDTMID_PUERTO_RICO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1932].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].entry.ee_code = EEC_GDDTMID_QATAR_NATIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1933].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].entry.ee_code = EEC_GDDTMID_QORNOQ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1934].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].entry.ee_code = EEC_GDDTMID_REUNION_1947;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1935].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].entry.ee_code = EEC_GDDTMID_ROME_1940;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1936].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].entry.ee_code = EEC_GDDTMID_SANTO_DOS_1965;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1937].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].entry.ee_code = EEC_GDDTMID_SAO_BRAZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1938].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].entry.ee_code = EEC_GDDTMID_SAPPER_HILL_1943;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1939].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].entry.ee_code = EEC_GDDTMID_SCHWARZECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1940].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].entry.ee_code = EEC_GDDTMID_SELVAGEM_GRANDE_1938;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1941].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].entry.ee_code = EEC_GDDTMID_S_AM_1969;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1942].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].entry.ee_code = EEC_GDDTMID_S_ASIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1943].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].entry.ee_code = EEC_GDDTMID_TANANARIVE_OBS_1925;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1944].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].entry.ee_code = EEC_GDDTMID_TIMBALAI_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1945].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].entry.ee_code = EEC_GDDTMID_TOKYO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1946].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].entry.ee_code = EEC_GDDTMID_TRISTAN_ASTRO_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1947].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].entry.ee_code = EEC_GDDTMID_VITI_LEVU_1916;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1948].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].entry.ee_code = EEC_GDDTMID_WAKE_ENIWETOK_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1949].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].entry.ee_code = EEC_GDDTMID_WAKE_ISLAND_ASTRO_1952;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1950].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].entry.ee_code = EEC_GDDTMID_WGS_1972;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1951].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].entry.ee_code = EEC_GDDTMID_WGS_1984;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1952].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].entry.ee_code = EEC_GDDTMID_YACARE_URUGUAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1953].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].entry.ee_code = EEC_GDDTMID_ZANDERIJ_SURINAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1954].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].entry.ee_code = EEC_GDDTMID_POTSDAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1955].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].entry.ee_code = EEC_GDDTMID_AMERICAN_SAMOA_1962;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1956].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].entry.ee_code = EEC_GDDTMID_DECEPTION_ISLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1957].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].entry.ee_code = EEC_GDDTMID_INDIAN_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1958].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].entry.ee_code = EEC_GDDTMID_INDONESIAN_1974;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1959].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].entry.ee_code = EEC_GDDTMID_N_SAHARA_1959;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1960].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].entry.ee_code = EEC_GDDTMID_PULKOVO_1942;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1961].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].entry.ee_code = EEC_GDDTMID_S42_PULKOVO_1958;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1962].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].entry.ee_code = EEC_GDDTMID_S_JTSK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1963].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].entry.ee_code = EEC_GDDTMID_VOIROL_1960_ALGERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1964].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1965].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1966].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1967].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1968].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].entry.ee_code = EEC_HYPSGPRTRYLTY_INDEX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1969].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].entry.ee_code = EEC_HYPSGPRTRYLTY_INTERM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1970].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP_ONE_HALF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1971].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].entry.ee_code = EEC_HYPSGPRTRYLTY_FORM_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1972].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].entry.ee_code = EEC_HYPSGPRTRYLTY_INDEX_DEPR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1973].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].entry.ee_code = EEC_HYPSGPRTRYLTY_INTERM_DEPR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1974].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].entry.ee_code = EEC_HYPSGPRTRYLTY_APPROX_INDEX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1975].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].entry.ee_code = EEC_HYPSGPRTRYLTY_INDEX_MOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1976].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].entry.ee_code = EEC_HYPSGPRTRYLTY_INTERM_MOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1977].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].entry.ee_code = EEC_HYPSGPRTRYLTY_INTERM_APPROX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1978].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP_APPROX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1979].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP_ONE_QUARTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1980].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].entry.ee_code = EEC_HYPSGPRTRYLTY_APPROX_DEPR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1981].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1982].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].entry.ee_code = EEC_HYPSGPRTRYLTY_APPROX_INTERM_DEPR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1983].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].entry.ee_code = EEC_HYPSGPRTRYLTY_CARRYING_CONTOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1984].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP_CARRYING_CONTOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1985].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].entry.ee_code = EEC_HYPSGPRTRYLTY_CARRYING_CONTOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1986].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP_DEPR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1987].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].entry.ee_code = EEC_HYPSGPRTRYLTY_SUPP_DEPR_APPROX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1988].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].entry.ee_code = EEC_HYPSGPRTRYLTY_TRANSITION_OR_ERRONEOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1989].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].entry.ee_code = EEC_HYPSGPRTRYLTY_CONNECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1990].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1991].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1992].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1993].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1994].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1995].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].entry.information = "<= 0,5 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1996].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].entry.information = "> 0,5 metre and <= 1,0 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1997].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].entry.information = "> 1,0 metre and <= 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1998].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].entry.information = "> 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[1999].entry.entry_list = temp_entries;

    temp_entries = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt2 */

