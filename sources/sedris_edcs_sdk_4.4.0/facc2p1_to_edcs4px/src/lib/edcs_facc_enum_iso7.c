/*
 * FILE: edcs_facc_enum_iso7.c
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
local_init_facc_attribute_enum_mapping_pt7( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6000].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6001].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6002].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6003].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6004].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].entry.ee_code = EEC_HYDRGDEPCAT_ABOVE_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6005].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].entry.ee_code = EEC_HYDRGDEPCAT_AWASH_AT_SOUNDING_DATUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6006].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].entry.ee_code = EEC_HYDRGDEPCAT_SUBMERGED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6007].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].entry.ee_code = EEC_HYDRGDEPCAT_COVERS_AND_UNCOVERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6008].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6009].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6010].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6011].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6012].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WELL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6013].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].entry.ee_code = EEC_WELLTY_WATERING_HOLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6014].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].entry.ee_code = EEC_WELLTY_WALLED_IN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6015].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].entry.ee_code = EEC_WELLTY_ARTESIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6016].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].entry.ee_code = EEC_WELLTY_FOUNTAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6017].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].entry.ee_code = EEC_WELLTY_DUG_OR_DRILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6018].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].entry.ee_code = EEC_WELLTY_DUG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6019].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].entry.ee_code = EEC_WELLTY_DRILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6020].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WELL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6021].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WELL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6022].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WELL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6023].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WELL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6024].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6025].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].entry.ee_code = EEC_MARWRCKTY_ANOMALIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6026].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].entry.ee_code = EEC_MARWRCKTY_AIRCRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6027].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].entry.ee_code = EEC_MARWRCKTY_AUXILIARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6028].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].entry.ee_code = EEC_MARWRCKTY_BATTLESHIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6029].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].entry.ee_code = EEC_MARWRCKTY_BARGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6030].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].entry.ee_code = EEC_MARWRCKTY_BUOY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6031].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].entry.ee_code = EEC_MARWRCKTY_CAISSON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6032].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].entry.ee_code = EEC_MARWRCKTY_AIRCRAFT_CARRIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6033].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].entry.ee_code = EEC_MARWRCKTY_CARGO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6034].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].entry.ee_code = EEC_MARWRCKTY_SUBCHASER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6035].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].entry.ee_code = EEC_MARWRCKTY_COASTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6036].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].entry.ee_code = EEC_MARWRCKTY_CRUISER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6037].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].entry.ee_code = EEC_MARWRCKTY_VESSEL_DEBRIS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6038].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].entry.ee_code = EEC_MARWRCKTY_DESTROYER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6039].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].entry.ee_code = EEC_MARWRCKTY_DREDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6040].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].entry.ee_code = EEC_MARWRCKTY_DRILL_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6041].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].entry.ee_code = EEC_MARWRCKTY_EXPLOSIVES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6042].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].entry.ee_code = EEC_MARWRCKTY_FISHING_BOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6043].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].entry.ee_code = EEC_MARWRCKTY_FISHING_REEF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6044].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].entry.ee_code = EEC_MARWRCKTY_FERRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6045].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].entry.ee_code = EEC_MARWRCKTY_FRIGATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6046].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].entry.ee_code = EEC_MARWRCKTY_GUNBOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6047].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].entry.ee_code = EEC_MARWRCKTY_HOSPITAL_SHIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6048].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].entry.ee_code = EEC_MARWRCKTY_HYDRO_SURVEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6049].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].entry.ee_code = EEC_MARWRCKTY_JUNK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6050].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].entry.ee_code = EEC_MARWRCKTY_LASH_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6051].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].entry.ee_code = EEC_MARWRCKTY_LANDING_CRAFT_INFANTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6052].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].entry.ee_code = EEC_MARWRCKTY_GAS_CARRIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6053].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].entry.ee_code = EEC_MARWRCKTY_LANDING_SHIP_INFANTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6054].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].entry.ee_code = EEC_MARWRCKTY_LANDING_SHIP_TANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6055].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].entry.ee_code = EEC_MARWRCKTY_LIGHTSHIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6056].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].entry.ee_code = EEC_MARWRCKTY_MINE_HANDLING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6057].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].entry.ee_code = EEC_MARWRCKTY_NET_TENDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6058].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].entry.ee_code = EEC_MARWRCKTY_BULK_CARRIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6059].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].entry.ee_code = EEC_MARWRCKTY_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6060].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].entry.ee_code = EEC_MARWRCKTY_PASSENGER_CARGO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6061].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].entry.ee_code = EEC_MARWRCKTY_PATROL_CRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6062].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].entry.ee_code = EEC_MARWRCKTY_PINNACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6063].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].entry.ee_code = EEC_MARWRCKTY_ROLLON_ROLLOFF_CONTAINER_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6064].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].entry.ee_code = EEC_MARWRCKTY_SAILING_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6065].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].entry.ee_code = EEC_MARWRCKTY_SEA_BEE_LASH_BARGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6066].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].entry.ee_code = EEC_MARWRCKTY_SUBMARINE_FLOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6067].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].entry.ee_code = EEC_MARWRCKTY_SUBMARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6068].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].entry.ee_code = EEC_MARWRCKTY_SURVEY_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6069].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].entry.ee_code = EEC_MARWRCKTY_TANKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6070].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].entry.ee_code = EEC_MARWRCKTY_TENDER_SUB_PLANE_RIG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6071].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].entry.ee_code = EEC_MARWRCKTY_TARGET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6072].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].entry.ee_code = EEC_MARWRCKTY_TORPEDO_BOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6073].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].entry.ee_code = EEC_MARWRCKTY_TRANSPORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6074].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].entry.ee_code = EEC_MARWRCKTY_TUG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6075].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].entry.ee_code = EEC_MARWRCKTY_TRAWLER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6076].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].entry.ee_code = EEC_MARWRCKTY_VERY_LARGE_CONTAINER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6077].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].entry.ee_code = EEC_MARWRCKTY_WELL_HEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6078].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].entry.ee_code = EEC_MARWRCKTY_YACHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6079].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6080].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6081].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6082].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6083].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6084].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].entry.ee_code = EEC_WTRLEVEFF_PARTIALLY_SUBMERGED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6085].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].entry.ee_code = EEC_WTRLEVEFF_ALWAYS_DRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6086].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].entry.ee_code = EEC_WTRLEVEFF_ALWAYS_UNDER_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6087].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].entry.ee_code = EEC_WTRLEVEFF_COVERS_AND_UNCOVERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6088].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].entry.ee_code = EEC_WTRLEVEFF_AWASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6089].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].entry.ee_code = EEC_WTRLEVEFF_DRYING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6090].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].entry.ee_code = EEC_WTRLEVEFF_SUBJECT_TO_INUNDATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6091].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].entry.ee_code = EEC_WTRLEVEFF_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6092].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6093].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6094].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6095].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6096].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6097].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].entry.ee_code = EEC_WRKINPROGTY_LAND_RECLAMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6098].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].entry.ee_code = EEC_WRKINPROGTY_STRUCTURE_CONSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6099].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6100].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6101].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6102].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6103].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WAYPOINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6104].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].entry.ee_code = EEC_WAYPTTY_AERODROME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6105].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].entry.ee_code = EEC_WAYPTTY_ESSENTIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6106].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].entry.ee_code = EEC_WAYPTTY_OFF_AIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6107].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].entry.ee_code = EEC_WAYPTTY_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6108].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].entry.ee_code = EEC_WAYPTTY_NON_ESSENTIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6109].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].entry.ee_code = EEC_WAYPTTY_TRANSITION_ESSENTIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6110].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].entry.ee_code = EEC_WAYPTTY_VOR_VORDME_VORTAC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6111].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].entry.ee_code = EEC_WAYPTTY_END_CONTINUOUS_AIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6112].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].entry.ee_code = EEC_WAYPTTY_UNCHARTED_AIRWAY_INTERSECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6113].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].entry.ee_code = EEC_WAYPTTY_ATC_COMPULSORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6114].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].entry.ee_code = EEC_WAYPTTY_GATEWAY_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6115].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].entry.ee_code = EEC_WAYPTTY_FIRST_LEG_MISSED_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6116].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].entry.ee_code = EEC_WAYPTTY_FINAL_APPROACH_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6117].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].entry.ee_code = EEC_WAYPTTY_HOLDING_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6118].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].entry.ee_code = EEC_WAYPTTY_FINAL_APPROACH_COURSE_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6119].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].entry.ee_code = EEC_WAYPTTY_MISSED_APPROACH_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].entry.ee_code = EEC_WAYPTTY_RUNWAY_END_COORDINATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].entry.ee_code = EEC_WAYPTTY_INITIAL_APPROACH_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6122].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].entry.ee_code = EEC_WAYPTTY_INNER_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6123].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].entry.ee_code = EEC_WAYPTTY_MIDDLE_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6124].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].entry.ee_code = EEC_WAYPTTY_OUTER_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6125].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].entry.ee_code = EEC_WAYPTTY_DME_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6126].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].entry.ee_code = EEC_WAYPTTY_BACK_COURSE_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6127].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].entry.ee_code = EEC_WAYPTTY_FAN_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WAYPOINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6129].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WAYPOINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6130].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WAYPOINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6131].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WAYPOINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6132].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6133].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].entry.ea_code = EAC_MARINE_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].entry.ee_code = EEC_MARWRCKSTAT_NON_DANGEROUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6134].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].entry.ea_code = EAC_MARINE_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].entry.ee_code = EEC_MARWRCKSTAT_DANGEROUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6135].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].entry.ea_code = EAC_MARINE_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].entry.ee_code = EEC_MARWRCKSTAT_REMAINS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].entry.ea_code = EAC_MARINE_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].entry.ee_code = EEC_MARWRCKSTAT_SHOWING_MAST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].entry.ea_code = EAC_MARINE_WRECK_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].entry.ee_code = EEC_MARWRCKSTAT_SHOWING_HULL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6139].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6140].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6141].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WRECK_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6142].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SCRAP_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6143].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].entry.ea_code = EAC_SCRAP_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].entry.ee_code = EEC_SCRAPTY_MOTOR_VEHICLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SCRAP_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6145].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SCRAP_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6146].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SCRAP_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6147].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SCRAP_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6148].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6149].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].entry.ee_code = EEC_NSUBSRC_SONAR_VERIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].entry.ee_code = EEC_NSUBSRC_MAD_VERIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].entry.ee_code = EEC_NSUBSRC_JAPAN_NAVAL_LOST_WW_II;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].entry.ee_code = EEC_NSUBSRC_US_LOSSES_DIRECTOR_FLEET_OPERATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].entry.ee_code = EEC_NSUBSRC_BHO_FILES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].entry.ee_code = EEC_NSUBSRC_COMNAVPAC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].entry.ee_code = EEC_NSUBSRC_COMNAVFE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6156].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].entry.ee_code = EEC_NSUBSRC_BHO_CHART;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].entry.ee_code = EEC_NSUBSRC_BHO_NOTICE_TO_MARINERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6158].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].entry.ee_code = EEC_NSUBSRC_LLOYDS_UNDERWRITERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].entry.ee_code = EEC_NSUBSRC_JAPAN_NAVY_IN_WW_II;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6160].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].entry.ee_code = EEC_NSUBSRC_US_NAVY_AT_WAR_1941_45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6161].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].entry.ee_code = EEC_NSUBSRC_GERMAN_WW_II_SUBMARINE_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].entry.ee_code = EEC_NSUBSRC_SWEDISH_1914_20_MERCHANT_LOSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6163].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].entry.ee_code = EEC_NSUBSRC_BHO_WRECK_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6164].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].entry.ee_code = EEC_NSUBSRC_AMERICAN_SHIP_CASUALTIES_WW_I;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6165].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].entry.ee_code = EEC_NSUBSRC_US_COAST_GUARD_RECORDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6166].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].entry.ee_code = EEC_NSUBSRC_TENTH_FLEET_RECORDS_OP374;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6167].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].entry.ee_code = EEC_NSUBSRC_NAVAL_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6168].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].entry.ee_code = EEC_NSUBSRC_ITALIAN_WW_II_NAVAL_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].entry.ee_code = EEC_NSUBSRC_DANISH_1914_18_WAR_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6170].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].entry.ee_code = EEC_NSUBSRC_BRITISH_MERCHANT_VESSELS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6171].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].entry.ee_code = EEC_NSUBSRC_ABSTRACTS_1914_18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6172].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].entry.ee_code = EEC_NSUBSRC_BRITISH_SHIPS_LOST_WW_II;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6173].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].entry.ee_code = EEC_NSUBSRC_SHIPS_SUNK_BY_GERMANY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6174].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].entry.ee_code = EEC_NSUBSRC_GREEK_WW_II_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6175].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].entry.ee_code = EEC_NSUBSRC_ITALIAN_WW_I_NAVAL_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6176].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].entry.ee_code = EEC_NSUBSRC_SPANISH_WW_I_MERCHANT_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6177].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].entry.ee_code = EEC_NSUBSRC_DUTCH_WW_I_MERCHANT_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6178].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].entry.ee_code = EEC_NSUBSRC_ITALIAN_WW_I_MERCHANT_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6179].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].entry.ee_code = EEC_NSUBSRC_NORWEGIAN_1914_18_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6180].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].entry.ee_code = EEC_NSUBSRC_US_COAST_GUARD_DISTRICTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6181].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].entry.ee_code = EEC_NSUBSRC_FRENCH_WW_I_NAVAL_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6182].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].entry.ee_code = EEC_NSUBSRC_US_NAVY_SONAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6183].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].entry.ee_code = EEC_NSUBSRC_MARITIME_COMMISSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].entry.ee_code = EEC_NSUBSRC_DANISH_1914_18_SHIP_LOSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6185].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].entry.ee_code = EEC_NSUBSRC_MERCHANT_VESSELS_US_LOST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6186].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].entry.ee_code = EEC_NSUBSRC_NAVAL_CHRONOLOGY_WW_II;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6187].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].entry.ee_code = EEC_NSUBSRC_SHIP_VISIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6188].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].entry.ee_code = EEC_NSUBSRC_SPANISH_HYDROGRAPHIC_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6189].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].entry.ee_code = EEC_NSUBSRC_BRITISH_1921_WRECK_CHARTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6190].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].entry.ee_code = EEC_NSUBSRC_SWEDISH_BOARD_SHIPPING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6191].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].entry.ee_code = EEC_NSUBSRC_BRITISH_1961_WRECK_CHARTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6192].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].entry.ee_code = EEC_NSUBSRC_PORTUGAL_HYDROGRAPHIC_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6193].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].entry.ee_code = EEC_NSUBSRC_ITALIAN_NAVY_SURVEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6194].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].entry.ee_code = EEC_NSUBSRC_SHIPPING_CASUALTIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6195].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].entry.ee_code = EEC_NSUBSRC_ITALIAN_NAVAL_SURVEY_CHARTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6196].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].entry.ee_code = EEC_NSUBSRC_OFFICE_OF_NAVAL_INTELLIGENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6197].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6198].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].entry.ee_code = EEC_NSUBSRC_RCN_WRECK_PUB_272;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6199].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].entry.ee_code = EEC_NSUBSRC_DUTCH_WRECK_LIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6200].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].entry.ee_code = EEC_NSUBSRC_NORTH_SEA_FISHING_CHARTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6201].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].entry.ee_code = EEC_NSUBSRC_PHOTOGRAPHS_OF_PINNACLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6202].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].entry.ee_code = EEC_NSUBSRC_US_COAST_AND_GEODETIC_SURVEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6203].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].entry.ee_code = EEC_NSUBSRC_RADIO_NAVIGATION_WARNING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6204].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].entry.ee_code = EEC_NSUBSRC_OMAN_NATIONAL_HYDROGRAPHIC_OFFICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6205].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6206].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6207].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6208].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6209].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6210].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].entry.ee_code = EEC_LDRTEUSBLWXTY_ALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].entry.ee_code = EEC_LDRTEUSBLWXTY_FAIR_AND_DRY_ONLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].entry.ee_code = EEC_LDRTEUSBLWXTY_WINTER_ONLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].entry.ee_code = EEC_LDRTEUSBLWXTY_ALL_LIMITED_TRAFFIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6214].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6215].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6216].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6217].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6218].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WALL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6219].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].entry.ea_code = EAC_WALL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].entry.ee_code = EEC_WALLTY_STANDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6220].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].entry.ea_code = EAC_WALL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].entry.ee_code = EEC_WALLTY_RETAINING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6221].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WALL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6222].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WALL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6223].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WALL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6224].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WALL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6225].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WALL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6226].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6227].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].entry.information = "<= 25%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 25.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6228].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].entry.information = "> 25% and <= 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6229].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].entry.information = "> 50% and <= 75%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 75.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6230].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].entry.information = "> 75%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 75.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6231].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6232].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6233].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6234].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6235].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].entry.information = "<= 1,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6236].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].entry.information = "> 1,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6237].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6238].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6239].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6240].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].entry.information = "Deleted: \"Unknown\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6241].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].entry.information = "Deleted: \"Normal Display (On)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].entry.information = "Deleted: \"Partially Suppressed\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6243].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].entry.information = "Deleted: \"Fully Suppressed\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6244].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].entry.information = "Deleted: \"Unpopulated\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6245].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].entry.information = "Deleted: \"Not Applicable\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6246].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].entry.information = "Deleted: \"Other\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6247].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6248].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6249].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6250].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6251].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6252].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6253].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6254].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].entry.information = "XSA deprecated.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6255].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6256].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].entry.information = "<= 0,08 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6257].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].entry.information = "> 0,08 metre and <= 1,60 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.8;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6258].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].entry.information = "> 1,60 metres and <= 2,40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.6;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6259].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].entry.information = "> 2,40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6260].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6261].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6262].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6263].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6264].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].entry.information = "<= 0,08 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6265].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].entry.information = "> 0,08 metre and <= 1,60 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.8;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6266].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].entry.information = "> 1,60 metres and <= 2,40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.6;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6267].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].entry.information = "> 2,40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 2.4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6268].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6269].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6270].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6271].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SERVICE_BRANCH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6272].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].entry.ee_code = EEC_SVCBR_AIR_FORCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].entry.ee_code = EEC_SVCBR_ARMY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].entry.ee_code = EEC_SVCBR_COASTGUARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].entry.ee_code = EEC_SVCBR_MARINES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6276].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].entry.ee_code = EEC_SVCBR_NAVY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6277].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SERVICE_BRANCH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6278].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].entry.ee_code = EEC_SVCBR_JOINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6279].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SERVICE_BRANCH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6280].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SERVICE_BRANCH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6281].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SERVICE_BRANCH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6282].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SERVICE_BRANCH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6283].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6284].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].entry.information = "<= 0,5 metre per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6285].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].entry.information = "> 0,5 metre per second and <= 1,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6286].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].entry.information = "> 1,5 metres per second and <= 2,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6287].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].entry.information = "> 2,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 2.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6288].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6289].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6290].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6291].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6292].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].entry.information = "<= 0,5 metre per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6293].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].entry.information = "> 0,5 metre per second and <= 1,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6294].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].entry.information = "> 1,5 metres per second and <= 2,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6295].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].entry.information = "> 2,5 metres per second.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE_PER_SEC;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 2.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6296].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6297].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6298].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6299].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6300].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].entry.ea_code = EAC_WATER_QUALITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].entry.ee_code = EEC_WTRQUAL_POTABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6301].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].entry.ea_code = EAC_WATER_QUALITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].entry.ee_code = EEC_WTRQUAL_TREATABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6302].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].entry.ea_code = EAC_WATER_QUALITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].entry.ee_code = EEC_WTRQUAL_CONTAMINATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6303].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6304].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6305].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6306].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6307].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6308].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].entry.information = "> 0 metres and <= 0,3 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 0.3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6309].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].entry.information = "> 0,3 metres and <= 1,2 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.3;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6310].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].entry.information = "> 1,2 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 1.2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6311].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].entry.information = "At ground surface.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6312].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6313].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6314].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6315].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[6316].entry.entry_list = temp_entries;

    temp_entries = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt7 */

