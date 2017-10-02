/*
 * FILE: edcs_facc_enum_iso4.c
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
local_init_facc_attribute_enum_mapping_pt4( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].entry.ee_code = EEC_SECMATTY_GLOBIGERINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3000].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].entry.ee_code = EEC_SECMATTY_PLANT_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].entry.information = "Generalized from \"Grass or thatch\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3001].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].entry.ee_code = EEC_SECMATTY_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3002].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].entry.ee_code = EEC_SECMATTY_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3003].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].entry.ee_code = EEC_SECMATTY_LAVA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3004].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].entry.ee_code = EEC_SECMATTY_LOESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3005].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].entry.ee_code = EEC_SECMATTY_MADREPORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3006].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].entry.ee_code = EEC_SECMATTY_MANGANESE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3007].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].entry.ee_code = EEC_SECMATTY_MARL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3008].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].entry.ee_code = EEC_SECMATTY_MATTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3009].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].entry.ee_code = EEC_SECMATTY_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3010].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].entry.ee_code = EEC_SECMATTY_MUSSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3011].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].entry.ee_code = EEC_SECMATTY_OOZE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3012].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].entry.ee_code = EEC_SECMATTY_OYSTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3013].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].entry.ee_code = EEC_SECMATTY_PEBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3014].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].entry.ee_code = EEC_SECMATTY_POLYZOA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3015].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].entry.ee_code = EEC_SECMATTY_PTEROPOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3016].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].entry.ee_code = EEC_SECMATTY_PUMICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3017].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].entry.ee_code = EEC_SECMATTY_QUARTZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3018].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].entry.ee_code = EEC_SECMATTY_RADIOLARIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3019].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].entry.ee_code = EEC_SECMATTY_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3020].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].entry.ee_code = EEC_SECMATTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3021].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].entry.ee_code = EEC_SECMATTY_SCHIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3022].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].entry.ee_code = EEC_SECMATTY_SCORIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3023].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].entry.ee_code = EEC_SECMATTY_SEA_TANGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3024].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].entry.ee_code = EEC_SECMATTY_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3025].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].entry.ee_code = EEC_SECMATTY_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3026].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].entry.ee_code = EEC_SECMATTY_SHINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3027].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].entry.ee_code = EEC_SECMATTY_SILT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3028].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].entry.ee_code = EEC_SECMATTY_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3029].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].entry.ee_code = EEC_SECMATTY_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3030].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].entry.ee_code = EEC_SECMATTY_SPONGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3031].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].entry.ee_code = EEC_SECMATTY_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3032].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].entry.ee_code = EEC_SECMATTY_TUFA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3033].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].entry.ee_code = EEC_SECMATTY_URANIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3034].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].entry.ee_code = EEC_SECMATTY_VEGETATION_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3035].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].entry.ee_code = EEC_SECMATTY_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3036].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].entry.ee_code = EEC_SECMATTY_VOLCANIC_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3037].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].entry.ee_code = EEC_SECMATTY_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3038].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].entry.ee_code = EEC_SECMATTY_WOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3039].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].entry.ee_code = EEC_SECMATTY_ZINC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3040].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].entry.ee_code = EEC_SECMATTY_EVAPORITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3041].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].entry.ee_code = EEC_SECMATTY_GLASS_REINFORCED_PLASTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3042].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3043].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3044].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3045].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3046].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3047].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].entry.ee_code = EEC_MOORCONNTY_FLEXIBLE_RESTRAINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3048].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3049].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3050].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3051].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3052].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3053].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].entry.ee_code = EEC_UNDRMATTY_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3054].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].entry.ee_code = EEC_UNDRMATTY_BOULDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3055].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].entry.ee_code = EEC_UNDRMATTY_CHALK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3056].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].entry.ee_code = EEC_UNDRMATTY_CINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3057].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].entry.ee_code = EEC_UNDRMATTY_CIRRIPEDIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3058].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].entry.ee_code = EEC_UNDRMATTY_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3059].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].entry.ee_code = EEC_UNDRMATTY_COBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3060].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].entry.ee_code = EEC_UNDRMATTY_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3061].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].entry.ee_code = EEC_UNDRMATTY_CORAL_HEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3062].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].entry.ee_code = EEC_UNDRMATTY_DIATOMACEOUS_EARTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3063].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].entry.ee_code = EEC_UNDRMATTY_FORAMINIFERA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3064].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].entry.ee_code = EEC_UNDRMATTY_FUCUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3065].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].entry.ee_code = EEC_UNDRMATTY_GLOBIGERINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3066].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].entry.ee_code = EEC_UNDRMATTY_PLANT_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].entry.information = "Generalized from \"Grass or thatch\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3067].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].entry.ee_code = EEC_UNDRMATTY_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3068].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].entry.ee_code = EEC_UNDRMATTY_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3069].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].entry.ee_code = EEC_UNDRMATTY_LAVA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3070].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].entry.ee_code = EEC_UNDRMATTY_MADREPORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3071].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].entry.ee_code = EEC_UNDRMATTY_MANGANESE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3072].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].entry.ee_code = EEC_UNDRMATTY_MARL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3073].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].entry.ee_code = EEC_UNDRMATTY_MATTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3074].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].entry.ee_code = EEC_UNDRMATTY_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3075].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].entry.ee_code = EEC_UNDRMATTY_MUSSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3076].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].entry.ee_code = EEC_UNDRMATTY_OOZE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3077].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].entry.ee_code = EEC_UNDRMATTY_OYSTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3078].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].entry.ee_code = EEC_UNDRMATTY_PEBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3079].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].entry.ee_code = EEC_UNDRMATTY_POLYZOA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3080].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].entry.ee_code = EEC_UNDRMATTY_PTEROPOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3081].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].entry.ee_code = EEC_UNDRMATTY_PUMICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3082].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].entry.ee_code = EEC_UNDRMATTY_QUARTZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3083].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].entry.ee_code = EEC_UNDRMATTY_RADIOLARIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3084].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].entry.ee_code = EEC_UNDRMATTY_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3085].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].entry.ee_code = EEC_UNDRMATTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3086].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].entry.ee_code = EEC_UNDRMATTY_SCHIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3087].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].entry.ee_code = EEC_UNDRMATTY_SCORIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3088].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].entry.ee_code = EEC_UNDRMATTY_SEA_TANGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3089].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].entry.ee_code = EEC_UNDRMATTY_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3090].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].entry.ee_code = EEC_UNDRMATTY_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3091].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].entry.ee_code = EEC_UNDRMATTY_SHINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3092].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].entry.ee_code = EEC_UNDRMATTY_SILT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3093].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].entry.ee_code = EEC_UNDRMATTY_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3094].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].entry.ee_code = EEC_UNDRMATTY_SPONGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3095].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].entry.ee_code = EEC_UNDRMATTY_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3096].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].entry.ee_code = EEC_UNDRMATTY_TUFA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3097].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].entry.ee_code = EEC_UNDRMATTY_URANIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3098].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].entry.ee_code = EEC_UNDRMATTY_VEGETATION_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3099].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].entry.ee_code = EEC_UNDRMATTY_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3100].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].entry.ee_code = EEC_UNDRMATTY_VOLCANIC_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3101].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].entry.ee_code = EEC_UNDRMATTY_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3102].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].entry.ee_code = EEC_UNDRMATTY_WOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3103].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].entry.ee_code = EEC_UNDRMATTY_ZINC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3104].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].entry.ee_code = EEC_UNDRMATTY_EVAPORITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3105].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].entry.ee_code = EEC_UNDRMATTY_GLASS_REINFORCED_PLASTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3106].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3107].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3108].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3109].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3110].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3111].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3112].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3113].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].entry.information = "< 5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.lt_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3114].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].entry.information = ">= 5 metres and < 20 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GE_LT_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_lt_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_lt_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3115].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].entry.information = ">= 20 metres and < 35 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GE_LT_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_lt_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_lt_interval.upper_bound = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3116].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].entry.information = ">= 35 metres and < 80 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GE_LT_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_lt_interval.lower_bound = 35.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_lt_interval.upper_bound = 80.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3117].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].entry.information = ">= 80 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_semi_interval = 80.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3118].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3119].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3120].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3121].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].code.tag, "MED", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3122].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3123].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].entry.ee_code = EEC_VEHMAINTAVAIL_VESSEL_REPAIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3124].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].entry.ee_code = EEC_VEHMAINTAVAIL_VESSEL_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3125].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].entry.ee_code = EEC_VEHMAINTAVAIL_BARGE_REPAIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3126].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].entry.ee_code = EEC_VEHMAINTAVAIL_BARGE_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3127].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].entry.ee_code = EEC_VEHMAINTAVAIL_LOCOMOTIVE_REPAIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].entry.ee_code = EEC_VEHMAINTAVAIL_LOCOMOTIVE_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3129].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].entry.ee_code = EEC_VEHMAINTAVAIL_AIRCRAFT_REPAIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3130].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].entry.ee_code = EEC_VEHMAINTAVAIL_AIRCRAFT_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3131].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].entry.ee_code = EEC_VEHMAINTAVAIL_ROAD_VEH_REPAIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3132].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].entry.ee_code = EEC_VEHMAINTAVAIL_ROAD_VEH_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3133].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].entry.ee_code = EEC_VEHMAINTAVAIL_VESSEL_SALVAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3134].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].entry.ee_code = EEC_VEHMAINTAVAIL_SAIL_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3135].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].entry.ee_code = EEC_VEHMAINTAVAIL_INSPECTION_RAMP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].entry.ee_code = EEC_VEHMAINTAVAIL_BOAT_HOIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].entry.ee_code = EEC_VEHMAINTAVAIL_GENERAL_MECHANICAL_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].entry.ee_code = EEC_VEHMAINTAVAIL_GENERAL_ELECTRICAL_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].entry.ee_code = EEC_VEHMAINTAVAIL_GENERAL_FABRICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3140].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3141].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].enum_val = 995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].entry.ee_code = EEC_VEHMAINTAVAIL_NONE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3143].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3144].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3145].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3146].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].entry.ee_code = EEC_MATHANDFAC_BULK_GRAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3147].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].entry.ee_code = EEC_MATHANDFAC_BULK_ORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].entry.ee_code = EEC_MATHANDFAC_CONTAINER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].entry.ee_code = EEC_MATHANDFAC_CONTAINER_TRAILER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].entry.ee_code = EEC_MATHANDFAC_ROLLON_ROLLOFF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].entry.ee_code = EEC_MATHANDFAC_CRANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].entry.ee_code = EEC_MATHANDFAC_BULK_LIQUID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].entry.ee_code = EEC_MATHANDFAC_BULK_FUEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].entry.ee_code = EEC_MATHANDFAC_RAIL_TRANSFER_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].entry.ee_code = EEC_MATHANDFAC_CIVILIAN_LABOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3156].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].entry.ee_code = EEC_MATHANDFAC_FORKLIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].entry.ee_code = EEC_MATHANDFAC_DOCK_LEVELLING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3158].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].entry.ee_code = EEC_MATHANDFAC_SYNCROLIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].entry.ee_code = EEC_MATHANDFAC_STRADDLE_CARRIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3160].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3161].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].enum_val = 995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].entry.ee_code = EEC_MATHANDFAC_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3163].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3164].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3165].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3166].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].entry.ee_code = EEC_MINEACACT_LOW_FREQUENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3167].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].entry.ee_code = EEC_MINEACACT_AUDIO_FREQUENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3168].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].entry.ee_code = EEC_MINEACACT_HIGH_FREQUENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].entry.ee_code = EEC_MINEACACT_MULTIPLE_FREQUENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3170].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3171].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3172].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3173].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3174].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3175].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].entry.ee_code = EEC_MINECONACT_CONTACT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3176].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].entry.ee_code = EEC_MINECONACT_SNAGLINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3177].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].entry.ee_code = EEC_MINECONACT_ROD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3178].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3179].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3180].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3181].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3182].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3183].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].entry.ea_code = EAC_MINE_ALLEGIANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].entry.ee_code = EEC_MINEALEGN_FRIEND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].entry.ea_code = EAC_MINE_ALLEGIANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].entry.ee_code = EEC_MINEALEGN_HOSTILE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3185].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].entry.ea_code = EAC_MINE_ALLEGIANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].entry.ee_code = EEC_MINEALEGN_NEUTRAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3186].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3187].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3188].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3189].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].code.tag, "MID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ALLEGIANCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3190].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3191].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].entry.ee_code = EEC_MINEINFLACT_PRESSURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3192].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].entry.ee_code = EEC_MINEINFLACT_COMBINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3193].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].entry.ee_code = EEC_MINEINFLACT_MAGNETIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3194].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].entry.ee_code = EEC_MINEINFLACT_ACOUSTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3195].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3196].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3197].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3198].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].code.tag, "MII", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3199].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3200].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].entry.ee_code = EEC_MINEMAGSENS_SENSITIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3201].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].entry.ee_code = EEC_MINEMAGSENS_MIDSENSITIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3202].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].entry.ee_code = EEC_MINEMAGSENS_COARSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3203].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3204].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3205].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3206].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3207].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3208].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].entry.ee_code = EEC_EXTRCTMINETY_BORROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3209].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].entry.ee_code = EEC_EXTRCTMINETY_HORIZONTAL_SHAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3210].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].entry.ee_code = EEC_EXTRCTMINETY_OPEN_PIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].entry.ee_code = EEC_EXTRCTMINETY_PLACER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].entry.ee_code = EEC_EXTRCTMINETY_PROSPECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].entry.ee_code = EEC_EXTRCTMINETY_STRIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3214].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].entry.ee_code = EEC_EXTRCTMINETY_VERTICAL_SHAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3215].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].entry.ee_code = EEC_EXTRCTMINETY_PEAT_CUTTINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3216].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].entry.ee_code = EEC_EXTRCTMINETY_BELOW_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3217].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3218].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3219].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3220].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3221].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3222].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].entry.ee_code = EEC_MINEOTHACTUSE_ELECTRIC_FIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3223].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].entry.ee_code = EEC_MINEOTHACTUSE_LASER_SENSOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3224].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].entry.ee_code = EEC_MINEOTHACTUSE_SEISMIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3225].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].entry.ee_code = EEC_MINEOTHACTUSE_COSMIC_RAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3226].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].entry.ee_code = EEC_MINEOTHACTUSE_INFRARED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3227].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].entry.ee_code = EEC_MINEOTHACTUSE_REDISTRIBUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3228].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].entry.ee_code = EEC_MINEOTHACTUSE_VELOCITY_FIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3229].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3230].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3231].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3232].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3233].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3234].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_TACTICAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3235].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].entry.ee_code = EEC_MINETACTUSE_ANTISWEEPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3236].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].entry.ee_code = EEC_MINETACTUSE_ANTIHUNTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3237].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].entry.ee_code = EEC_MINETACTUSE_ANTIHOVERCRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3238].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].entry.ee_code = EEC_MINETACTUSE_DRILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3239].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].entry.ee_code = EEC_MINETACTUSE_EXPLOSIVE_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3240].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].entry.ee_code = EEC_MINETACTUSE_EXERCISE_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3241].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].entry.ee_code = EEC_MINETACTUSE_EXERCISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].entry.ee_code = EEC_MINETACTUSE_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3243].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].entry.ee_code = EEC_MINETACTUSE_DISPOSAL_CHARGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3244].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_TACTICAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3245].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_TACTICAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3246].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_TACTICAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3247].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_TACTICAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3248].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3249].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].entry.ea_code = EAC_MINE_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].entry.ee_code = EEC_MINEACT_CONTROLLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3250].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].entry.ea_code = EAC_MINE_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].entry.ee_code = EEC_MINEACT_INDEPENDENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3251].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3252].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3253].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3254].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3255].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3256].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTROL_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3257].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].entry.ea_code = EAC_MINE_CONTROL_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].entry.ee_code = EEC_MINECTRLMETH_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3258].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].entry.ea_code = EAC_MINE_CONTROL_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].entry.ee_code = EEC_MINECTRLMETH_CABLELESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3259].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTROL_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3260].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTROL_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3261].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTROL_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3262].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CONTROL_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3263].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3264].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].entry.ee_code = EEC_MINEINDEPACT_CONTACT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3265].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].entry.ee_code = EEC_MINEINDEPACT_INFLUENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3266].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3267].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3268].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3269].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3270].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3271].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3272].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].entry.ee_code = EEC_MINECABLSACT_FREQUENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].entry.ee_code = EEC_MINECABLSACT_EXPLICIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].entry.ee_code = EEC_MINECABLSACT_ALTERNATING_CURRENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3276].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3277].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3278].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3279].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3280].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].entry.ea_code = EAC_MINE_POSITION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].entry.ee_code = EEC_MINEPOSTY_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3281].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].entry.ea_code = EAC_MINE_POSITION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].entry.ee_code = EEC_MINEPOSTY_MOORED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3282].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3283].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3284].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3285].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3286].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3287].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3288].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3289].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].entry.information = "<= 500 kilograms.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_KILOGRAM;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 500.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3290].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].entry.information = "> 500 kilograms.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_KILOGRAM;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 500.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3291].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3292].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3293].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3294].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3295].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].entry.ee_code = EEC_MINEMOORPOS_DEEP_MOORED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3296].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].entry.ee_code = EEC_MINEMOORPOS_SHORT_TETHERED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3298].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3299].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3300].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3301].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3302].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].entry.ee_code = EEC_MINECPBLTY_DRIFTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3303].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].entry.ee_code = EEC_MINECPBLTY_OSCILLATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3304].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].entry.ee_code = EEC_MINECPBLTY_CREEPING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3305].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].entry.ee_code = EEC_MINECPBLTY_MOBILE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].entry.ee_code = EEC_MINECPBLTY_HOMING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].entry.ee_code = EEC_MINECPBLTY_RISING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3308].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].entry.ee_code = EEC_MINECPBLTY_BOUQUET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3309].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].entry.ee_code = EEC_MINECPBLTY_ACTIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3310].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3311].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3312].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3313].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3314].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3315].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].entry.ee_code = EEC_MINESTAT_AFLOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3316].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].entry.ee_code = EEC_MINESTAT_SUNK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3317].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].entry.ee_code = EEC_MINESTAT_DISPOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3318].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].entry.ee_code = EEC_MINESTAT_FOULED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3319].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].entry.ee_code = EEC_MINESTAT_EXPLODED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3320].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].entry.ee_code = EEC_MINESTAT_COUNTERMINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3321].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].entry.ee_code = EEC_MINESTAT_NEUTRALIZED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3322].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].entry.ee_code = EEC_MINESTAT_RENDERED_SAFE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3323].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].entry.ee_code = EEC_MINESTAT_RECOVERED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3324].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].entry.ee_code = EEC_MINESTAT_REMOVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3325].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3326].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3327].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3328].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_STATUS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3329].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3330].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].entry.ee_code = EEC_MINESPCLCPBLTY_ARMING_DELAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].entry.ee_code = EEC_MINESPCLCPBLTY_VESSEL_COUNT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].entry.ee_code = EEC_MINESPCLCPBLTY_INTERMITTENT_ARMING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].entry.ee_code = EEC_MINESPCLCPBLTY_DELAYED_RISING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3334].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].entry.ee_code = EEC_MINESPCLCPBLTY_OBSTRUCTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3335].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].entry.ee_code = EEC_MINESPCLCPBLTY_STERILIZER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3336].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].entry.ee_code = EEC_MINESPCLCPBLTY_FLOODER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3337].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].entry.ee_code = EEC_MINESPCLCPBLTY_ANTIWATCHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3338].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].entry.ee_code = EEC_MINESPCLCPBLTY_ANTISWEEP_WIRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].entry.ee_code = EEC_MINESPCLCPBLTY_ANTIRECOVERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].entry.ee_code = EEC_MINESPCLCPBLTY_ANTIHUNTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3342].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3343].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3344].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3345].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3346].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].entry.ee_code = EEC_MINEAHTY_ANECHOIC_COATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3347].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].entry.ee_code = EEC_MINEAHTY_AUTOMATIC_MINE_BURIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3348].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].entry.ee_code = EEC_MINEAHTY_IRREGULAR_SHAPING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3349].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].entry.ee_code = EEC_MINEAHTY_ACOUSTIC_IMPEDANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3350].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].entry.ee_code = EEC_MINEAHTY_ACOUSTIC_TRANSPARENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3351].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].entry.ee_code = EEC_MINEAHTY_NON_METALLIC_CASE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3352].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].entry.ee_code = EEC_MINEAHTY_SONAR_DECOYS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3353].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3354].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3355].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3356].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3357].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3358].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3359].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].entry.ee_code = EEC_MINEINFTY_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3360].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].entry.ee_code = EEC_MINEINFTY_SUBTYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3361].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].entry.ee_code = EEC_MINEINFTY_DEVICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3362].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3363].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3364].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3365].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3366].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3367].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].entry.ee_code = EEC_MINEARTY_SWITCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3368].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].entry.ee_code = EEC_MINEARTY_MOORING_LEVEL_SWITCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3369].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].entry.ee_code = EEC_MINEARTY_STRIPPING_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3370].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3371].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3372].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3373].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3374].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3375].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSILE_SITE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3376].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].entry.ee_code = EEC_MSSLSITETY_ANTIBALLISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3377].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].entry.ee_code = EEC_MSSLSITETY_INTERCONTINENTAL_BALLISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].entry.ee_code = EEC_MSSLSITETY_INTERMEDIATE_RANGE_BALLISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3379].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].entry.ee_code = EEC_MSSLSITETY_SA1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3380].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].entry.ee_code = EEC_MSSLSITETY_SA2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3381].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].entry.ee_code = EEC_MSSLSITETY_SA3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3382].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].entry.ee_code = EEC_MSSLSITETY_SA4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3383].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].entry.ee_code = EEC_MSSLSITETY_SA5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].entry.ee_code = EEC_MSSLSITETY_SA6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3385].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].entry.ee_code = EEC_MSSLSITETY_SA7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3386].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].entry.ee_code = EEC_MSSLSITETY_SA8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3387].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].entry.ee_code = EEC_MSSLSITETY_SA9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3388].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].entry.ee_code = EEC_MSSLSITETY_MEDIUM_RANGE_BALLISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3389].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].entry.ee_code = EEC_MSSLSITETY_SURFACE_TO_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3390].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].entry.ee_code = EEC_MSSLSITETY_SURFACE_TO_AIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3391].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSILE_SITE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3392].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSILE_SITE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3393].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSILE_SITE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3394].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].code.tag, "MST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSILE_SITE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3395].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3396].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].entry.ee_code = EEC_MINEOPUSE_GENERAL_PURPOSE_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3397].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].entry.ee_code = EEC_MINEOPUSE_DEEP_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3398].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].entry.ee_code = EEC_MINEOPUSE_MEDIUM_DEPTH_ANTISUBMARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3399].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].entry.ee_code = EEC_MINEOPUSE_CONTINENTAL_SHELF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3400].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].entry.ee_code = EEC_MINEOPUSE_MARINE_ANTIINVASION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3401].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].entry.ee_code = EEC_MINEOPUSE_ANTISURFACE_EFFECT_VEHICLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3402].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3403].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3404].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3405].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3406].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3407].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].entry.ee_code = EEC_MINEASWTY_CHAIN_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3408].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].entry.ee_code = EEC_MINEASWTY_SPROCKET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3409].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].entry.ee_code = EEC_MINEASWTY_GRAPNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3410].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].entry.ee_code = EEC_MINEASWTY_CUTTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3411].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].entry.ee_code = EEC_MINEASWTY_SENSITIVE_TUBING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3412].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3413].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3414].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3415].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3416].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3417].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3418].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].entry.ea_code = EAC_MAST_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].entry.ee_code = EEC_MASTTY_COMMUNICATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3419].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].entry.ea_code = EAC_MAST_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].entry.ee_code = EEC_MASTTY_TELEVISION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3420].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].entry.ea_code = EAC_MAST_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].entry.ee_code = EEC_MASTTY_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3421].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].entry.ea_code = EAC_MAST_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].entry.ee_code = EEC_MASTTY_ILLUMINATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3422].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].entry.ea_code = EAC_MAST_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].entry.ee_code = EEC_MASTTY_MICROWAVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3423].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3424].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3425].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3426].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3427].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRACK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3428].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].entry.ea_code = EAC_MARINE_TRACK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].entry.ee_code = EEC_MARTRKTY_BASED_ON_FIXED_MARKS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3429].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].entry.ea_code = EAC_MARINE_TRACK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].entry.ee_code = EEC_MARTRKTY_NOT_BASED_ON_FIXED_MARKS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3430].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].entry.ea_code = EAC_MARINE_TRACK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].entry.ee_code = EEC_MARTRKTY_MAXIMUM_AUTHORIZED_DRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3431].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].entry.ea_code = EAC_MARINE_TRACK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].entry.ee_code = EEC_MARTRKTY_MANDATORY_DIRECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3432].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].entry.ea_code = EAC_MARINE_TRACK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].entry.ee_code = EEC_MARTRKTY_RECOMMENDED_DIRECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3433].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRACK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3434].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRACK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3435].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRACK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3436].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRACK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3437].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3438].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].entry.ee_code = EEC_MOORFACTY_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3439].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].entry.ee_code = EEC_MOORFACTY_DOLPHIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3440].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].entry.ee_code = EEC_MOORFACTY_DEVIATION_DOLPHIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3441].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].entry.ee_code = EEC_MOORFACTY_BOLLARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3442].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].entry.ee_code = EEC_MOORFACTY_TIE_UP_WALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3443].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].entry.ee_code = EEC_MOORFACTY_STRUCTURAL_PILE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3444].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3445].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3446].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3447].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3448].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3449].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].entry.ee_code = EEC_NATSETTLTY_CENTRALIZED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3450].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].entry.ee_code = EEC_NATSETTLTY_CONTINUOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3451].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3452].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3453].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3454].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3455].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3456].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].entry.ee_code = EEC_MARNAVLNTY_UNDEFINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3457].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].entry.ee_code = EEC_MARNAVLNTY_CLEARING_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3458].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].entry.ee_code = EEC_MARNAVLNTY_TRANSIT_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3459].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3460].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3461].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3462].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3463].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3464].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].entry.ee_code = EEC_AIDNAVMKSYS_IALA_REGION_A;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3465].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].entry.ee_code = EEC_AIDNAVMKSYS_IALA_REGION_B;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3466].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].entry.ee_code = EEC_AIDNAVMKSYS_US_MODIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3467].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].entry.ee_code = EEC_AIDNAVMKSYS_US_OLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3468].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].entry.ee_code = EEC_AIDNAVMKSYS_US_INTRACOASTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3469].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].entry.ee_code = EEC_AIDNAVMKSYS_US_UNIFORM_STATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3470].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].entry.ee_code = EEC_AIDNAVMKSYS_US_WESTERN_RIVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3471].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].entry.ee_code = EEC_AIDNAVMKSYS_SIGNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3472].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].entry.ee_code = EEC_AIDNAVMKSYS_NO_SYSTEM_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3473].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3474].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3475].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3476].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3477].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3478].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3479].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].entry.ee_code = EEC_NAVSYSTY_CIRCULAR_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3480].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].entry.ee_code = EEC_NAVSYSTY_CONSOL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3481].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].entry.ee_code = EEC_NAVSYSTY_DECCA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3482].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].entry.ee_code = EEC_NAVSYSTY_RADIO_DIRECTION_FINDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3483].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].entry.ee_code = EEC_NAVSYSTY_DIRECTIONAL_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3484].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].entry.ee_code = EEC_NAVSYSTY_DISTANCE_FINDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3485].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].entry.ee_code = EEC_NAVSYSTY_LORAN_C;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3486].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].entry.ee_code = EEC_NAVSYSTY_OMEGA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3487].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3488].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].entry.ee_code = EEC_NAVSYSTY_RACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3489].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].entry.ee_code = EEC_NAVSYSTY_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3490].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].entry.ee_code = EEC_NAVSYSTY_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3491].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].entry.ee_code = EEC_NAVSYSTY_RADIO_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3492].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3493].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].entry.ee_code = EEC_NAVSYSTY_TELEVISION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3494].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].entry.ee_code = EEC_NAVSYSTY_MICROWAVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3495].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].entry.ee_code = EEC_NAVSYSTY_NDB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3496].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].entry.ee_code = EEC_NAVSYSTY_NDB_OR_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3497].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].entry.ee_code = EEC_NAVSYSTY_RADIO_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3498].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].entry.ee_code = EEC_NAVSYSTY_VOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3499].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].entry.ee_code = EEC_NAVSYSTY_VOR_AND_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3500].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].entry.ee_code = EEC_NAVSYSTY_VORTAC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3501].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].entry.ee_code = EEC_NAVSYSTY_TACTICAL_AIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3502].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].entry.ee_code = EEC_NAVSYSTY_ILS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].entry.ee_code = EEC_NAVSYSTY_ILS_OR_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].entry.ee_code = EEC_NAVSYSTY_LOCALIZER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].entry.ee_code = EEC_NAVSYSTY_LOCALIZER_WITH_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].entry.ee_code = EEC_NAVSYSTY_SIMPLIFIED_DIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3507].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].entry.ee_code = EEC_NAVSYSTY_LOCALIZER_DIRECTION_AID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3508].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].entry.ee_code = EEC_NAVSYSTY_MLS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3509].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].entry.ee_code = EEC_NAVSYSTY_FAN_MARKER_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3510].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].entry.ee_code = EEC_NAVSYSTY_BONE_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3511].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].entry.ee_code = EEC_NAVSYSTY_RADIO_TELEGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].entry.ee_code = EEC_NAVSYSTY_GCA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].entry.ee_code = EEC_NAVSYSTY_RADAR_AERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3514].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].entry.ee_code = EEC_NAVSYSTY_PAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3515].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].entry.ee_code = EEC_NAVSYSTY_AERO_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3516].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3517].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].entry.ee_code = EEC_NAVSYSTY_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3518].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].entry.ee_code = EEC_NAVSYSTY_ROTATING_LOOP_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3519].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].entry.ee_code = EEC_NAVSYSTY_VFR_TEST_SIGNAL_MAKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3520].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3521].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].entry.ee_code = EEC_NAVSYSTY_CONSOL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].entry.ee_code = EEC_NAVSYSTY_RADAR_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].entry.ee_code = EEC_NAVSYSTY_AERO_RADIO_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].entry.ee_code = EEC_NAVSYSTY_HIFIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].entry.ee_code = EEC_NAVSYSTY_HYPERFIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3526].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].entry.ee_code = EEC_NAVSYSTY_TRICOLOUR_PANEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3527].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].entry.ee_code = EEC_NAVSYSTY_RADIO_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].entry.ee_code = EEC_NAVSYSTY_RADIO_BEACON_TYPE_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].entry.ee_code = EEC_NAVSYSTY_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3530].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].entry.ee_code = EEC_NAVSYSTY_QTG_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3531].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].entry.ee_code = EEC_NAVSYSTY_RAMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3532].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].entry.ee_code = EEC_NAVSYSTY_RADAR_REFLECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3533].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].entry.ee_code = EEC_NAVSYSTY_LOCATOR_WITHOUT_DME_INNER_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3534].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].entry.ee_code = EEC_NAVSYSTY_LOCALIZER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3535].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].entry.ee_code = EEC_NAVSYSTY_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3536].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3537].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3538].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3539].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3540].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].entry.ee_code = EEC_NAVSYSTY_CIRCULAR_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3541].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].entry.ee_code = EEC_NAVSYSTY_CONSOL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3542].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].entry.ee_code = EEC_NAVSYSTY_DECCA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3543].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].entry.ee_code = EEC_NAVSYSTY_RADIO_DIRECTION_FINDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3544].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].entry.ee_code = EEC_NAVSYSTY_DIRECTIONAL_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3545].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].entry.ee_code = EEC_NAVSYSTY_DISTANCE_FINDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3546].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].entry.ee_code = EEC_NAVSYSTY_LORAN_C;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3547].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].entry.ee_code = EEC_NAVSYSTY_OMEGA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3548].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3549].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].entry.ee_code = EEC_NAVSYSTY_RACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3550].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].entry.ee_code = EEC_NAVSYSTY_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3551].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].entry.ee_code = EEC_NAVSYSTY_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3552].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].entry.ee_code = EEC_NAVSYSTY_RADIO_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3553].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3554].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].entry.ee_code = EEC_NAVSYSTY_TELEVISION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3555].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].entry.ee_code = EEC_NAVSYSTY_MICROWAVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3556].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].entry.ee_code = EEC_NAVSYSTY_NDB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3557].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].entry.ee_code = EEC_NAVSYSTY_NDB_OR_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3558].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].entry.ee_code = EEC_NAVSYSTY_RADIO_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3559].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].entry.ee_code = EEC_NAVSYSTY_VOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3560].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].entry.ee_code = EEC_NAVSYSTY_VOR_AND_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3561].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].entry.ee_code = EEC_NAVSYSTY_VORTAC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3562].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].entry.ee_code = EEC_NAVSYSTY_TACTICAL_AIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3563].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].entry.ee_code = EEC_NAVSYSTY_ILS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3564].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].entry.ee_code = EEC_NAVSYSTY_ILS_OR_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3565].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].entry.ee_code = EEC_NAVSYSTY_LOCALIZER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3566].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].entry.ee_code = EEC_NAVSYSTY_LOCALIZER_WITH_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3567].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].entry.ee_code = EEC_NAVSYSTY_SIMPLIFIED_DIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3568].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].entry.ee_code = EEC_NAVSYSTY_LOCALIZER_DIRECTION_AID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3569].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].entry.ee_code = EEC_NAVSYSTY_MLS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3570].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].entry.ee_code = EEC_NAVSYSTY_FAN_MARKER_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3571].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].entry.ee_code = EEC_NAVSYSTY_BONE_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3572].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].entry.ee_code = EEC_NAVSYSTY_RADIO_TELEGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3573].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].entry.ee_code = EEC_NAVSYSTY_GCA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3574].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].entry.ee_code = EEC_NAVSYSTY_RADAR_AERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3575].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].entry.ee_code = EEC_NAVSYSTY_PAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3576].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].entry.ee_code = EEC_NAVSYSTY_AERO_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3577].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3578].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].entry.ee_code = EEC_NAVSYSTY_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3579].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].entry.ee_code = EEC_NAVSYSTY_ROTATING_LOOP_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3580].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].entry.ee_code = EEC_NAVSYSTY_VFR_TEST_SIGNAL_MAKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3581].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3582].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].entry.ee_code = EEC_NAVSYSTY_CONSOL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3583].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].entry.ee_code = EEC_NAVSYSTY_RADAR_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3584].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].entry.ee_code = EEC_NAVSYSTY_AERO_RADIO_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3585].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].entry.ee_code = EEC_NAVSYSTY_HIFIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3586].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].entry.ee_code = EEC_NAVSYSTY_HYPERFIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3587].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].entry.ee_code = EEC_NAVSYSTY_TRICOLOUR_PANEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3588].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].entry.ee_code = EEC_NAVSYSTY_RADIO_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3589].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].entry.ee_code = EEC_NAVSYSTY_RADIO_BEACON_TYPE_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3590].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].entry.ee_code = EEC_NAVSYSTY_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3591].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].entry.ee_code = EEC_NAVSYSTY_QTG_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3592].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].entry.ee_code = EEC_NAVSYSTY_RAMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3593].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].entry.ee_code = EEC_NAVSYSTY_RADAR_REFLECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3594].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].entry.ee_code = EEC_NAVSYSTY_LOCATOR_WITHOUT_DME_INNER_MARKER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3595].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].entry.ee_code = EEC_NAVSYSTY_LOCALIZER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3596].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].entry.ee_code = EEC_NAVSYSTY_DME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3597].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].entry.ee_code = EEC_NAVSYSTY_DIFFERENTIAL_GPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3598].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].entry.ee_code = EEC_NAVSYSTY_TORAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3599].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].entry.ee_code = EEC_NAVSYSTY_SYLEDIS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3600].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].entry.ee_code = EEC_NAVSYSTY_CHAIKA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3601].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].entry.ee_code = EEC_NAVSYSTY_MLS_AZIMUTH_GUIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3602].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].entry.ee_code = EEC_NAVSYSTY_MLS_ELEVATION_GUIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3603].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].entry.ee_code = EEC_NAVSYSTY_PRECISION_APPROACH_PATH_INDICATOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3604].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].entry.ee_code = EEC_NAVSYSTY_VASI_PULSATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3605].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].entry.ee_code = EEC_NAVSYSTY_VASI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3606].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].entry.ee_code = EEC_NAVSYSTY_TRICOLOUR_VASI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3607].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].entry.ee_code = EEC_NAVSYSTY_TVASI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3608].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].entry.ee_code = EEC_NAVSYSTY_AERODROME_SURV_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3609].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].entry.ee_code = EEC_NAVSYSTY_PAR_TOUCHDOWN_REFLECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3610].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].entry.ee_code = EEC_NAVSYSTY_GLIDE_SLOPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3611].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].entry.ee_code = EEC_NAVSYSTY_AIR_ROUTE_SURV_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3612].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3613].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3614].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].code.tag, "NST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3615].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OIL_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3616].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].entry.ea_code = EAC_OIL_BARRIER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].entry.ee_code = EEC_OILBARTY_OIL_RETENTION_PIPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3617].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].entry.ea_code = EAC_OIL_BARRIER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].entry.ee_code = EEC_OILBARTY_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3618].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OIL_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3619].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OIL_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3620].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OIL_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3621].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OIL_BARRIER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3622].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3623].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3624].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3625].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3626].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3627].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3628].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3629].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3630].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].entry.information = "> 1,5 metres and <= 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3631].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].entry.information = "> 5,0 metres and <= 10,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3632].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].entry.information = "> 10,0 metres and <= 20,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3633].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].entry.information = "> 20,0 metres and <= 40,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3634].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].entry.information = "> 40,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3635].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3636].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3637].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3638].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3639].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3640].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3641].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3642].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3643].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3644].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3645].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3646].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].entry.ee_code = EEC_OVRHDOBSTNTY_VIADUCT_FRAME_CONSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3647].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].entry.ee_code = EEC_OVRHDOBSTNTY_VIADUCT_ARCH_CONSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3648].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].entry.ee_code = EEC_OVRHDOBSTNTY_ROOF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3649].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].entry.ee_code = EEC_OVRHDOBSTNTY_RAILWAY_POWERLINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3650].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].entry.ee_code = EEC_OVRHDOBSTNTY_HIGH_TENSION_POWERLINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3651].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].entry.ee_code = EEC_OVRHDOBSTNTY_BRIDGE_SUPERSTRUCTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3652].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3653].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3654].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3655].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3656].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3657].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].entry.ee_code = EEC_OFFSHPLATTY_OIL_DERRICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3658].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].entry.ee_code = EEC_OFFSHPLATTY_PRODUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3659].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].entry.ee_code = EEC_OFFSHPLATTY_OBSERVATION_RESEARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3660].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].entry.ee_code = EEC_OFFSHPLATTY_ARTICULATED_LOADING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3661].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].entry.ee_code = EEC_OFFSHPLATTY_SINGLE_ANCHOR_LEG_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3662].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].entry.ee_code = EEC_OFFSHPLATTY_MOORING_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3663].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].entry.ee_code = EEC_OFFSHPLATTY_ARTIFICIAL_ISLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3664].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].entry.ee_code = EEC_OFFSHPLATTY_FLOATING_PRODUCTION_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3665].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].entry.ee_code = EEC_OFFSHPLATTY_ACCOMMODATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3666].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].entry.ee_code = EEC_OFFSHPLATTY_NAVIGATION_AID_SUPPORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3667].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3668].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3669].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3670].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3671].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3672].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3673].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3674].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3675].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3676].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3677].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATIONAL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3678].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_TIME;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3679].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].entry.ea_code = EAC_OPERATING_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].entry.ee_code = EEC_OPERTIME_DAYTIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3680].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].entry.ea_code = EAC_OPERATING_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].entry.ee_code = EEC_OPERTIME_NIGHT_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3681].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].entry.ea_code = EAC_OPERATING_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].entry.ee_code = EEC_OPERTIME_CONTINUOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3682].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].entry.ea_code = EAC_OPERATING_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].entry.ee_code = EEC_OPERTIME_SUMMER_TIME_APRIL_OCTOBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3683].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].entry.ea_code = EAC_OPERATING_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].entry.ee_code = EEC_OPERTIME_WINTER_TIME_NOVEMBER_MARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3684].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_TIME;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3685].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_TIME;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3686].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_TIME;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3687].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_TIME;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3688].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3689].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].entry.ee_code = EEC_OBJORDRANK_FIRST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3690].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].entry.ee_code = EEC_OBJORDRANK_SECOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3691].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].entry.ee_code = EEC_OBJORDRANK_THIRD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3692].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].entry.ee_code = EEC_OBJORDRANK_FOURTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3693].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].entry.ee_code = EEC_OBJORDRANK_FIFTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3694].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3695].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3696].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3697].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3698].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3699].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].entry.ee_code = EEC_OPERRESTTY_DAYTIME_ONLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3700].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].entry.ee_code = EEC_OPERRESTTY_NIGHT_TIME_ONLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3701].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].entry.ee_code = EEC_OPERRESTTY_NO_RESTRICTIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3702].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].entry.ee_code = EEC_OPERRESTTY_PRONE_TO_SNOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3703].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].entry.ee_code = EEC_OPERRESTTY_PRONE_TO_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3704].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].entry.ee_code = EEC_OPERRESTTY_PRONE_TO_FLOODING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3705].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3706].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].enum_val = 996;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].entry.ee_code = EEC_OPERRESTTY_SPECIAL_RESTRICTIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3707].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3708].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3709].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3710].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3711].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3712].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3713].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3714].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3715].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3716].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3717].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3718].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].entry.ee_code = EEC_RNWYPTABEAMTY_GLIDE_SLOPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3719].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].entry.ee_code = EEC_RNWYPTABEAMTY_MLS_ELEVATION_GUIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3720].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].entry.ee_code = EEC_RNWYPTABEAMTY_LOCALIZER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3721].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].entry.ee_code = EEC_RNWYPTABEAMTY_OFFSET_LOCALIZER_DIRECTION_AID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3722].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].entry.ee_code = EEC_RNWYPTABEAMTY_OFFSET_SIMPLIFIED_DIRECTIONAL_FACILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3723].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].entry.ee_code = EEC_RNWYPTABEAMTY_MLS_AZIMUTH_GUIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3724].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].entry.ee_code = EEC_RNWYPTABEAMTY_PAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3725].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].entry.ee_code = EEC_RNWYPTABEAMTY_PAR_TOUCHDOWN_REFLECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3726].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3727].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3728].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3729].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3730].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3731].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].entry.ee_code = EEC_AIDNAVCOLRPAT_CHECKERED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3732].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].entry.ee_code = EEC_AIDNAVCOLRPAT_DIAGONAL_STRIPES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3733].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].entry.ee_code = EEC_AIDNAVCOLRPAT_SINGLE_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3734].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].entry.ee_code = EEC_AIDNAVCOLRPAT_HORIZ_STRIPES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3735].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3736].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].entry.ee_code = EEC_AIDNAVCOLRPAT_VERTICAL_STRIPES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3737].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].entry.ee_code = EEC_AIDNAVCOLRPAT_STRIPES_DIRECTION_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3738].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].entry.ee_code = EEC_AIDNAVCOLRPAT_BORDER_STRIPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3739].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].entry.ee_code = EEC_AIDNAVCOLRPAT_SQUARED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3740].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].entry.ee_code = EEC_AIDNAVCOLRPAT_HORIZ_BANDS_TOP_TO_BOTTOM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3741].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3742].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3743].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3744].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3745].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3746].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].entry.ee_code = EEC_MARPLTBRDMETH_PILOT_CRUISING_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3747].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].entry.ee_code = EEC_MARPLTBRDMETH_HELICOPTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3748].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].entry.ee_code = EEC_MARPLTBRDMETH_COMES_FROM_SHORE_ON_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3749].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3750].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3751].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3752].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3753].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3754].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].entry.ee_code = EEC_MARPLTBRDVEH_BOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3755].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].entry.ee_code = EEC_MARPLTBRDVEH_HELICOPTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3756].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3757].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3758].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3759].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3760].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CHANGE_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3761].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].entry.ea_code = EAC_CHANGE_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].entry.ee_code = EEC_CHGPTTY_ROAD_OR_RAILWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3762].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].entry.ea_code = EAC_CHANGE_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].entry.ee_code = EEC_CHGPTTY_HYDROGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3763].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].entry.ea_code = EAC_CHANGE_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].entry.ee_code = EEC_CHGPTTY_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3764].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].entry.ea_code = EAC_CHANGE_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].entry.ee_code = EEC_CHGPTTY_ROAD_WIDTH_CHANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3765].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].entry.ea_code = EAC_CHANGE_POINT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].entry.ee_code = EEC_CHGPTTY_OBSTACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3766].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CHANGE_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3767].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CHANGE_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3768].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CHANGE_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3769].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_CHANGE_POINT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3770].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3771].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].entry.information = "<= 1 nautical mile (1 852 metres).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_NAUTICAL_MILE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3772].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].entry.information = "> 1 nautical mile and <= 3 nautical miles (> 1 852 metres and <= 5 556 metres).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_NAUTICAL_MILE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 3.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3773].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].entry.information = "> 3 nautical miles and <= 5 nautical miles (> 5 556 metres and <= 9 260 metres).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_NAUTICAL_MILE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 3.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3774].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].entry.information = "> 5 nautical miles and <= 10 nautical miles (> 9 260 metres and <= 18 520 metres).";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_NAUTICAL_MILE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3775].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].entry.information = "Was: \"Accuracy Uncertain\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 10000.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_KILO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3776].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3777].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3778].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3779].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3780].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].entry.information = "<= 10 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3781].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].entry.information = "> 10 metres and <= 20 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3782].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].entry.information = "> 20 metres and <= 30 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3783].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].entry.information = "> 30 metres and <= 40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3784].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].entry.information = "> 40 metres and <= 50 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 40.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3785].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].entry.information = "> 50 metres and <= 60 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3786].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].entry.information = "> 60 metres and <= 70 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 60.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 70.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3787].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].entry.information = "> 70 metres and <= 80 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 70.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 80.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3788].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].entry.information = "> 80 metres and <= 90 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 80.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 90.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3789].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].entry.information = "> 90 metres and <= 100 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 90.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3790].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].entry.information = "> 100 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3791].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3792].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3793].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3794].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3795].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].entry.ee_code = EEC_STRPILETY_STAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3796].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].entry.ee_code = EEC_STRPILETY_SNAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3797].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].entry.ee_code = EEC_STRPILETY_POST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3798].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].entry.ee_code = EEC_STRPILETY_TRIPODAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3799].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3800].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3801].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3802].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3803].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PIPELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3804].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].entry.ee_code = EEC_PIPELNTY_TRANSPORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3805].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].entry.ee_code = EEC_PIPELNTY_OUTFALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3806].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].entry.ee_code = EEC_PIPELNTY_WATER_INTAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3807].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].entry.ee_code = EEC_PIPELNTY_SEWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3808].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].entry.ee_code = EEC_PIPELNTY_VALVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3809].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].entry.ee_code = EEC_PIPELNTY_GENERIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3810].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].entry.ee_code = EEC_PIPELNTY_BUBBLER_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3811].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].entry.ee_code = EEC_PIPELNTY_SUPPLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3812].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PIPELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3813].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PIPELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3814].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PIPELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3815].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PIPELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3816].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].code.tag, "POI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INTEREST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3817].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].code.tag, "POI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].entry.ea_code = EAC_INTEREST_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].entry.ee_code = EEC_INTRSTTY_HISTORIC_BATTLEFIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3818].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].code.tag, "POI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INTEREST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3819].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].code.tag, "POI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INTEREST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3820].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].code.tag, "POI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INTEREST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3821].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].code.tag, "POI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INTEREST_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3822].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POND_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3823].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].entry.ea_code = EAC_POND_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].entry.ee_code = EEC_PONDTY_FISH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3824].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].entry.ea_code = EAC_POND_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].entry.ee_code = EEC_PONDTY_RESERVOIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3825].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].entry.ea_code = EAC_POND_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].entry.ee_code = EEC_PONDTY_WASTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3826].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POND_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3827].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POND_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3828].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POND_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3829].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].code.tag, "POP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POND_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3830].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POWER_PLANT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3831].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].entry.ee_code = EEC_PWRPLNTTY_HYDRO_ELECTRIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3832].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].entry.ee_code = EEC_PWRPLNTTY_NUCLEAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3833].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].entry.ee_code = EEC_PWRPLNTTY_SOLAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3834].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].entry.ee_code = EEC_PWRPLNTTY_THERMAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3835].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].entry.ee_code = EEC_PWRPLNTTY_WIND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3836].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].entry.ee_code = EEC_PWRPLNTTY_TIDAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3837].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].entry.ee_code = EEC_PWRPLNTTY_INTERNAL_COMBUSTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3838].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POWER_PLANT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3839].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POWER_PLANT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3840].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POWER_PLANT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3841].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POWER_PLANT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3842].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3843].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].entry.ee_code = EEC_POPPLCTY_TRADITIONAL_SETTLEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3844].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].entry.ee_code = EEC_POPPLCTY_SHANTY_TOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3845].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].entry.ee_code = EEC_POPPLCTY_TENT_DWELLINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3846].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].entry.ee_code = EEC_POPPLCTY_INLAND_VILLAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3847].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3848].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3849].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3850].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3851].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3852].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].entry.ee_code = EEC_PERDCRESTSTRT_JANUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3853].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].entry.ee_code = EEC_PERDCRESTSTRT_FEBRUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3854].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].entry.ee_code = EEC_PERDCRESTSTRT_MARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3855].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].entry.ee_code = EEC_PERDCRESTSTRT_APRIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3856].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].entry.ee_code = EEC_PERDCRESTSTRT_MAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3857].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].entry.ee_code = EEC_PERDCRESTSTRT_JUNE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3858].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].entry.ee_code = EEC_PERDCRESTSTRT_JULY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3859].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].entry.ee_code = EEC_PERDCRESTSTRT_AUGUST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3860].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].entry.ee_code = EEC_PERDCRESTSTRT_SEPTEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3861].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].entry.ee_code = EEC_PERDCRESTSTRT_OCTOBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3862].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].entry.ee_code = EEC_PERDCRESTSTRT_NOVEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3863].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].entry.ee_code = EEC_PERDCRESTSTRT_DECEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3864].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3865].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3866].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3867].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3868].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3869].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].entry.ee_code = EEC_PERDCRESTEND_JANUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3870].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].entry.ee_code = EEC_PERDCRESTEND_FEBRUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3871].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].entry.ee_code = EEC_PERDCRESTEND_MARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3872].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].entry.ee_code = EEC_PERDCRESTEND_APRIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3873].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].entry.ee_code = EEC_PERDCRESTEND_MAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3874].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].entry.ee_code = EEC_PERDCRESTEND_JUNE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3875].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].entry.ee_code = EEC_PERDCRESTEND_JULY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3876].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].entry.ee_code = EEC_PERDCRESTEND_AUGUST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3877].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].entry.ee_code = EEC_PERDCRESTEND_SEPTEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3878].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].entry.ee_code = EEC_PERDCRESTEND_OCTOBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3879].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].entry.ee_code = EEC_PERDCRESTEND_NOVEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3880].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].entry.ee_code = EEC_PERDCRESTEND_DECEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3881].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3882].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3883].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3884].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3885].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3886].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].entry.ee_code = EEC_PERDCRESTTY_PERENNIALLY_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3887].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].entry.ee_code = EEC_PERDCRESTTY_SUBJECT_TO_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3888].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].entry.ee_code = EEC_PERDCRESTTY_PERMANENT_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3889].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].entry.ee_code = EEC_PERDCRESTTY_JANUARY_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3890].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].entry.ee_code = EEC_PERDCRESTTY_FEBRUARY_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3891].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].entry.ee_code = EEC_PERDCRESTTY_MARCH_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3892].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].entry.ee_code = EEC_PERDCRESTTY_APRIL_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3893].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].entry.ee_code = EEC_PERDCRESTTY_MAY_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3894].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].entry.ee_code = EEC_PERDCRESTTY_JUNE_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3895].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].entry.ee_code = EEC_PERDCRESTTY_JULY_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3896].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].entry.ee_code = EEC_PERDCRESTTY_AUGUST_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3897].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].entry.ee_code = EEC_PERDCRESTTY_SEPTEMBER_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3898].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].entry.ee_code = EEC_PERDCRESTTY_OCTOBER_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3899].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].entry.ee_code = EEC_PERDCRESTTY_NOVEMBER_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3900].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].entry.ee_code = EEC_PERDCRESTTY_DECEMBER_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3901].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].entry.ee_code = EEC_PERDCRESTTY_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3902].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3903].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3904].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3905].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3906].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERMANENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3907].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PERMANENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3908].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PERMANENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3909].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERMANENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3910].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERMANENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3911].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PERMANENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3912].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3913].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].entry.ee_code = EEC_PRIPROD_AIRCRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3914].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].entry.ee_code = EEC_PRIPROD_ALUMINUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3915].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].entry.ee_code = EEC_PRIPROD_AMMUNITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3916].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].entry.ee_code = EEC_PRIBYPROD_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3917].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].entry.ee_code = EEC_PRIPROD_ASPHALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3918].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].entry.ee_code = EEC_PRIPROD_BASALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3919].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].entry.ee_code = EEC_PRIPROD_BEDROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3920].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].entry.ee_code = EEC_PRIPROD_BOULDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3921].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].entry.ee_code = EEC_PRIPROD_BRICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3922].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].entry.ee_code = EEC_PRIPROD_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3923].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].entry.ee_code = EEC_PRIPROD_CEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3924].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].entry.ee_code = EEC_PRIPROD_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].entry.information = "Was: \"Chalk\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3925].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].entry.ee_code = EEC_PRIPROD_CHEMICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3926].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].entry.ee_code = EEC_PRIBYPROD_CINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3927].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].entry.ee_code = EEC_PRIPROD_GROUND_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].entry.information = "Was: \"Cirripedia\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3928].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].entry.ee_code = EEC_PRIPROD_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3929].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].entry.ee_code = EEC_PRIPROD_COAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3930].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].entry.ee_code = EEC_PRIPROD_COBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3931].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].entry.ee_code = EEC_PRIPROD_COKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3932].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].entry.ee_code = EEC_PRIPROD_COMPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3933].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].entry.ee_code = EEC_PRIPROD_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3934].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].entry.ee_code = EEC_PRIPROD_CONGLOMERATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3935].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].entry.ee_code = EEC_PRIPROD_COPPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3936].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].entry.ee_code = EEC_PRIPROD_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3937].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].entry.ee_code = EEC_PRIPROD_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].entry.information = "Was: \"Coral Head\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3938].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].entry.ee_code = EEC_PRIPROD_DESALINATED_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3939].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].entry.ee_code = EEC_PRIPROD_DIAMOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3940].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].entry.ee_code = EEC_PRIPROD_DIATOMACEOUS_EARTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3941].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].entry.ee_code = EEC_PRIPROD_DOLOMITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3942].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].entry.ee_code = EEC_PRIPROD_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].entry.information = "Was: \"Earthen\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3943].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].entry.ee_code = EEC_PRIPROD_ELECTRICITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3944].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].entry.ee_code = EEC_PRIBYPROD_ERODED_LAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3945].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].entry.ee_code = EEC_PRIPROD_EXPLOSIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3946].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].entry.ee_code = EEC_PRIPROD_FLYSCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3947].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].entry.ee_code = EEC_PRIPROD_FOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3948].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].entry.ee_code = EEC_PRIPROD_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].entry.information = "Was: \"Foraminifera\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3949].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].entry.ee_code = EEC_PRIPROD_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].entry.information = "Was: \"Fucus\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3950].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].entry.ee_code = EEC_PRIPROD_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3951].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].entry.ee_code = EEC_PRIPROD_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3952].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].entry.ee_code = EEC_PRIPROD_GLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3953].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].entry.ee_code = EEC_PRIPROD_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].entry.information = "Was: \"Globigerina\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3954].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].entry.ee_code = EEC_PRIPROD_GOLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3955].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].entry.ee_code = EEC_PRIPROD_GRANITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3956].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3957].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].entry.ee_code = EEC_PRIPROD_PLANT_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].entry.information = "Generalized from \"Grass or thatch\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3958].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].entry.ee_code = EEC_PRIPROD_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3959].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].entry.ee_code = EEC_PRIPROD_GREENSTONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3960].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].entry.ee_code = EEC_PRIPROD_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].entry.information = "Was: \"Ground\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3961].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].entry.ee_code = EEC_PRIPROD_GROUND_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3962].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].entry.ee_code = EEC_PRIPROD_HEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3963].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].entry.ee_code = EEC_PRIPROD_IRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3964].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].entry.information = "Deleted: \"Lava\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3965].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3966].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].entry.ee_code = EEC_PRIPROD_LEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3967].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].entry.ee_code = EEC_PRIPROD_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].entry.information = "Was: \"Loess\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3968].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].entry.ee_code = EEC_PRIPROD_LUMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3969].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].entry.ee_code = EEC_PRIPROD_MACADAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3970].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].entry.ee_code = EEC_PRIPROD_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].entry.information = "Was: \"Madrepores\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3971].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].entry.ee_code = EEC_PRIPROD_MANGANESE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3972].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].entry.ee_code = EEC_PRIPROD_MARBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3973].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].entry.ee_code = EEC_PRIPROD_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].entry.information = "Was: \"Marl\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3974].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].entry.ee_code = EEC_PRIPROD_MASONRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3975].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].entry.ee_code = EEC_PRIBYPROD_MATTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3976].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].entry.ee_code = EEC_PRIPROD_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3977].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].entry.ee_code = EEC_PRIBYPROD_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3978].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].entry.ee_code = EEC_PRIPROD_BIVALVE_MOLLUSC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].entry.information = "Was: \"Mussels\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3979].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].entry.ee_code = EEC_PRIPROD_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3980].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].entry.ee_code = EEC_PRIPROD_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].entry.information = "Was: \"Oil Blister\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3981].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].entry.information = "Deleted: \"Ooze\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3982].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].entry.ee_code = EEC_PRIPROD_BIVALVE_MOLLUSC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].entry.information = "Was: \"Oysters\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3983].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].entry.ee_code = EEC_PRIPROD_PAPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3984].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].entry.information = "Deleted: \"Part Metal\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3985].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].entry.ee_code = EEC_PRIPROD_PEBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3986].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].entry.ee_code = EEC_PRIPROD_PLASTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3987].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].entry.ea_code = EAC_PRIMARY_RAW_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].entry.ee_code = EEC_PRIRAWMAT_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].entry.information = "Was: \"Polyzoa\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3988].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].entry.ee_code = EEC_PRIPROD_PORPHYRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3989].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].entry.ee_code = EEC_PRIPROD_PRESTRESSED_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3990].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].entry.ee_code = EEC_PRIPROD_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].entry.information = "Was: \"Pteropods\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3991].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].entry.ee_code = EEC_PRIPROD_PUMICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3992].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].entry.ee_code = EEC_PRIPROD_QUARTZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3993].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].entry.ea_code = EAC_PRIMARY_RAW_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].entry.ee_code = EEC_PRIRAWMAT_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].entry.information = "Was: \"Radiolaria\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3994].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].entry.ee_code = EEC_PRIPROD_RADIOACTIVE_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3995].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].entry.ee_code = EEC_PRIPROD_REINFORCED_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3996].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].entry.ee_code = EEC_PRIPROD_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3997].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].entry.ee_code = EEC_PRIPROD_RUBBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3998].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].entry.ee_code = EEC_PRIBYPROD_RUBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[3999].entry.entry_list = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt4 */

