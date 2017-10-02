/*
 * FILE: edcs_facc_enum_iso5.c
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
local_init_facc_attribute_enum_mapping_pt5( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].entry.ee_code = EEC_PRIPROD_SALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4000].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].entry.ee_code = EEC_PRIPROD_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4001].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].entry.ee_code = EEC_PRIPROD_SANDSTONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4002].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].entry.ee_code = EEC_PRIPROD_SCHIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4003].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4004].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].entry.ee_code = EEC_PRIPROD_SCORIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4005].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].entry.ee_code = EEC_PRIPROD_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].entry.information = "Was: \"Sea Tangle\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4006].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].entry.ee_code = EEC_PRIPROD_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4007].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].entry.ee_code = EEC_PRIPROD_SEWAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4008].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].entry.ee_code = EEC_PRIPROD_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4009].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4010].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].entry.ee_code = EEC_PRIPROD_SHINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4011].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].entry.ee_code = EEC_PRIBYPROD_SILT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4012].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].entry.ee_code = EEC_PRIPROD_SILVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4013].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].entry.ee_code = EEC_PRIBYPROD_SLAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4014].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].entry.ee_code = EEC_PRIBYPROD_SLUDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4015].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].entry.ee_code = EEC_PRIPROD_FROZEN_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4016].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].entry.ee_code = EEC_PRIPROD_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4017].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].entry.ea_code = EAC_PRIMARY_RAW_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].entry.ee_code = EEC_PRIRAWMAT_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4018].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].entry.ee_code = EEC_PRIPROD_SPONGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4019].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].entry.ee_code = EEC_PRIPROD_STEEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4020].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].entry.ee_code = EEC_PRIPROD_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4021].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].entry.ee_code = EEC_PRIPROD_SUGAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4022].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].entry.ee_code = EEC_PRIPROD_TRAVERTINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4023].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].entry.ee_code = EEC_PRIPROD_TUFA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4024].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].entry.ee_code = EEC_PRIPROD_URANIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4025].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].entry.ee_code = EEC_PRIPROD_VEGETATION_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4026].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].entry.information = "Deleted: \"Volcanic\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4027].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].entry.ea_code = EAC_PRIMARY_RAW_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].entry.ee_code = EEC_PRIRAWMAT_VOLCANIC_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4028].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].entry.ee_code = EEC_PRIPROD_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4029].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].entry.ee_code = EEC_PRIPROD_WOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4030].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].entry.ee_code = EEC_PRIPROD_ZINC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4031].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].entry.ee_code = EEC_PRIPROD_BAUXITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4032].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].entry.ee_code = EEC_PRIPROD_BANANA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4033].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].entry.ee_code = EEC_PRIPROD_COTTON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4034].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].entry.ee_code = EEC_PRIPROD_BAMBOO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4035].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].entry.ee_code = EEC_PRIPROD_COFFEE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4036].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].entry.ee_code = EEC_PRIPROD_FRUIT_AND_NUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4037].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].entry.ee_code = EEC_PRIPROD_PALM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4038].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].entry.ee_code = EEC_PRIPROD_PALMETTO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4039].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].entry.ee_code = EEC_PRIBYPROD_TAILINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4040].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].entry.ee_code = EEC_PRIBYPROD_REFUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4041].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].entry.ee_code = EEC_PRIPROD_TOBACCO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4042].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].entry.ee_code = EEC_PRIPROD_NO_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4043].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].entry.ee_code = EEC_PRIPROD_PERSONNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4044].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Not Applicable)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4045].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].enum_val = 133;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].entry.ee_code = EEC_PRIPROD_TELECOMMUNICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4046].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].enum_val = 134;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].entry.ee_code = EEC_PRIPROD_FISH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4047].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].enum_val = 135;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].entry.ee_code = EEC_PRIPROD_TEXTILE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4048].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].enum_val = 137;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].entry.ee_code = EEC_PRIPROD_MOTOR_VEHICLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4049].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].enum_val = 138;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].entry.ee_code = EEC_PRIPROD_CRUSTACEAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4050].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].enum_val = 139;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].entry.ee_code = EEC_PRIPROD_CULTIVATED_SHELLFISH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4051].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].enum_val = 140;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].entry.ee_code = EEC_PRIPROD_ORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4052].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].enum_val = 141;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].entry.ee_code = EEC_PRIPROD_DRINKING_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4053].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].enum_val = 142;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].entry.ee_code = EEC_PRIPROD_MILK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4054].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].enum_val = 143;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].entry.ea_code = EAC_PRIMARY_RAW_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].entry.ee_code = EEC_PRIRAWMAT_SAWDUST_WOODCHIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4055].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].enum_val = 144;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].entry.ea_code = EAC_PRIMARY_RAW_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].entry.ee_code = EEC_PRIRAWMAT_SCRAP_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4056].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].enum_val = 145;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].entry.ee_code = EEC_PRIPROD_LIQUIFIED_NATURAL_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4057].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].enum_val = 146;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].entry.ee_code = EEC_PRIPROD_LIQUIFIED_PETROLEUM_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4058].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].enum_val = 147;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].entry.ee_code = EEC_PRIPROD_WINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4059].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].enum_val = 148;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].entry.ee_code = EEC_PRIPROD_GRAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4060].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].enum_val = 149;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].entry.ee_code = EEC_PRIPROD_MINERAL_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4061].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].enum_val = 150;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].entry.ea_code = EAC_PRIMARY_BYPRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].entry.ee_code = EEC_PRIBYPROD_WASTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4062].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].enum_val = 151;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].entry.ee_code = EEC_PRIPROD_CULTURED_PEARL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4063].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4064].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4065].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4066].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_PRODUCT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4067].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4068].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].entry.ee_code = EEC_SRFCHRTY_BROKEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4069].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].entry.ee_code = EEC_SRFCHRTY_COARSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4070].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].entry.ee_code = EEC_SRFCHRTY_DECAYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4071].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].entry.ee_code = EEC_SRFCHRTY_FINE_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4072].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].entry.ee_code = EEC_SRFCHRTY_GRITTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4073].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].entry.ee_code = EEC_SRFCHRTY_HARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4074].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].entry.ee_code = EEC_SRFCHRTY_ROTTEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4075].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].entry.ee_code = EEC_SRFCHRTY_SOFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4076].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].entry.ee_code = EEC_SRFCHRTY_STICKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4077].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].entry.ee_code = EEC_SRFCHRTY_STIFF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4078].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].entry.ee_code = EEC_SRFCHRTY_STREAKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4079].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].entry.ee_code = EEC_SRFCHRTY_TENACIOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4080].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].entry.ee_code = EEC_SRFCHRTY_UNEVEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4081].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].entry.ee_code = EEC_SRFCHRTY_BARE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4082].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].entry.ee_code = EEC_SRFCHRTY_KARST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4083].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].entry.ee_code = EEC_SRFCHRTY_MEMBRANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4084].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].entry.ee_code = EEC_SRFCHRTY_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4085].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].entry.ee_code = EEC_SRFCHRTY_FLINTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4086].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].entry.ee_code = EEC_SRFCHRTY_GLACIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4087].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].entry.ee_code = EEC_SRFCHRTY_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4088].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].entry.ee_code = EEC_SRFCHRTY_LARGE_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4089].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].entry.ee_code = EEC_SRFCHRTY_ROCKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4090].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].entry.ee_code = EEC_SRFCHRTY_SMALL_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4091].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].entry.ee_code = EEC_SRFCHRTY_SPECKLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4092].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].entry.ee_code = EEC_SRFCHRTY_VARIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4093].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].entry.ee_code = EEC_SRFCHRTY_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4094].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].entry.ee_code = EEC_SRFCHRTY_MEDIUM_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4095].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].entry.ee_code = EEC_SRFCHRTY_SPRINGS_IN_SEABED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4096].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].entry.ee_code = EEC_SRFCHRTY_UNSTABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4097].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].entry.ee_code = EEC_SRFCHRTY_MEDIUM_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Medium)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4098].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].entry.ee_code = EEC_SRFCHRTY_UNSURFACED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4099].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4100].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4101].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4102].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4103].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PHYSICAL_STATE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4104].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].entry.ea_code = EAC_PHYSICAL_STATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].entry.ee_code = EEC_PHYSSTATE_SOLID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4105].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].entry.ea_code = EAC_PHYSICAL_STATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].entry.ee_code = EEC_PHYSSTATE_LIQUID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4106].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PHYSICAL_STATE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4107].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PHYSICAL_STATE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4108].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PHYSICAL_STATE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4109].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].code.tag, "PST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PHYSICAL_STATE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4110].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BERTH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4111].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].entry.ea_code = EAC_BERTH_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].entry.ee_code = EEC_BERTHTY_PIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4112].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].entry.ea_code = EAC_BERTH_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].entry.ee_code = EEC_BERTHTY_WHARF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4113].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].entry.ea_code = EAC_BERTH_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].entry.ee_code = EEC_BERTHTY_QUAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4114].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BERTH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4115].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BERTH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4116].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BERTH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4117].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BERTH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4118].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4119].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].entry.ee_code = EEC_LOCACCMETH_SURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].entry.ee_code = EEC_LOCACCMETH_INADEQUATELY_SURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].entry.information = "Was: \"Unsurveyed\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].entry.ee_code = EEC_LOCACCMETH_INADEQUATELY_SURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4122].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].entry.ee_code = EEC_LOCACCMETH_APPROXIMATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4123].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].entry.ee_code = EEC_LOCACCMETH_REPORTED_BUT_UNRELIABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].entry.information = "Was: \"Doubtful\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4124].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].entry.ee_code = EEC_LOCACCMETH_REPORTED_BUT_UNRELIABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4125].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].entry.ee_code = EEC_LOCACCMETH_REPORTED_NOT_SURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4126].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].entry.ee_code = EEC_LOCACCMETH_REPORTED_NOT_CONFIRMED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4127].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].entry.ee_code = EEC_LOCACCMETH_ESTIMATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].entry.ee_code = EEC_LOCACCMETH_CALCULATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4129].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].entry.ee_code = EEC_LOCACCMETH_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4130].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4131].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4132].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4133].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4134].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4135].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].entry.ee_code = EEC_NSUBSRCTY_SURVIVOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].entry.ee_code = EEC_NSUBSRCTY_SALVAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].entry.ee_code = EEC_NSUBSRCTY_CASUALTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].entry.ee_code = EEC_NSUBSRCTY_ACTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].entry.ee_code = EEC_NSUBSRCTY_PHOTOGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4140].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].entry.ee_code = EEC_NSUBSRCTY_US_COAST_SURVEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4141].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].entry.ee_code = EEC_NSUBSRCTY_US_NAVY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].entry.ee_code = EEC_NSUBSRCTY_UK_HYDROGRAPHIC_RECORDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4143].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].entry.ee_code = EEC_NSUBSRCTY_US_WRECK_LIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].entry.ee_code = EEC_NSUBSRCTY_CHART_RECORDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4145].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].entry.ee_code = EEC_NSUBSRCTY_US_COAST_GUARD_RECORDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4146].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].entry.ee_code = EEC_NSUBSRCTY_NOTICE_TO_MARINERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4147].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].entry.ee_code = EEC_NSUBSRCTY_NORTH_SEA_FISHING_CHARTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].entry.ee_code = EEC_NSUBSRCTY_CHART;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].entry.ee_code = EEC_NSUBSRCTY_MINESWEEPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].entry.ee_code = EEC_NSUBSRCTY_SURVEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].entry.ee_code = EEC_NSUBSRCTY_POSITION_ACCURATE_FIELD_CHECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].entry.ee_code = EEC_NSUBSRCTY_SONAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].entry.ee_code = EEC_NSUBSRCTY_MAGNETIC_ANOMALY_DETECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].entry.ee_code = EEC_NSUBSRCTY_UNSPECIFIED_DETECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4156].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4157].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4158].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4159].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4160].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].entry.ea_code = EAC_RADAR_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].entry.ee_code = EEC_RADRSTATY_MARINE_TRAFFIC_SURVEILLANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4161].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].entry.ea_code = EAC_RADAR_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].entry.ee_code = EEC_RADRSTATY_COASTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4163].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4164].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4165].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4166].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4167].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].entry.ee_code = EEC_BRIDGEINFRELI_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4168].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].entry.ee_code = EEC_BRIDGEINFRELI_ESTIMATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4170].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4171].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4172].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4173].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4174].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].entry.ea_code = EAC_ROAD_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].entry.ee_code = EEC_RDTY_STREET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4175].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].entry.ea_code = EAC_ROAD_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].entry.ee_code = EEC_RDTY_RAPID_TRANSIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4176].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4177].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].entry.ea_code = EAC_ROAD_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].entry.ee_code = EEC_RDTY_SERVICE_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4178].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4179].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4180].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4181].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4182].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4183].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4184].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4185].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4186].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4187].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4188].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].code.tag, "REF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4189].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4190].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_BUDDHISM;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[1].u.characteristic_entry.ea_code = EAC_BUDDHISM_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4191].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_ISLAM;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[1].u.characteristic_entry.ea_code = EAC_ISLAMIC_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4192].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_CHRISTIANITY;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_CHRSDENOMFAM_CATHOLICISM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4193].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_CHRISTIANITY;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[1].u.characteristic_entry.ea_code = EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4194].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_JUDAISM;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[1].u.characteristic_entry.ea_code = EAC_JUDAISM_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4195].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_CHRISTIANITY;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_CHRSDENOMFAM_ORTHODOX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4196].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RELIGDESIG_CHRISTIANITY;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_CHRSDENOMFAM_PROTESTANTISM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4197].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].entry.ee_code = EEC_RELIGDESIG_SHINTO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4198].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4199].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4200].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4201].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].code.tag, "REL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4202].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4203].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].entry.ee_code = EEC_ACREFLNTY_FROM_WTR_BODY_FLOOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4204].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].entry.ee_code = EEC_ACREFLNTY_FROM_BELOW_WTR_BODY_FLOOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4205].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4206].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4207].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4208].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].code.tag, "RET", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4209].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4210].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].entry.ee_code = EEC_RAILGAUGECAT_BROAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].entry.ee_code = EEC_RAILGAUGECAT_NARROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].entry.ee_code = EEC_RAILGAUGECAT_NORMAL_COUNTRY_SPECIFIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].entry.ee_code = EEC_RAILGAUGECAT_ANY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4214].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].entry.ee_code = EEC_RAILGAUGECAT_STANDARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4215].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4216].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4217].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4218].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4219].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4220].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].entry.ee_code = EEC_LGTRELLOC_FRONT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4221].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].entry.ee_code = EEC_LGTRELLOC_MIDDLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4222].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].entry.ee_code = EEC_LGTRELLOC_REAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4223].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].entry.ee_code = EEC_LGTRELLOC_SHARED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4224].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4225].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4226].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4227].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4228].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4229].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].entry.ee_code = EEC_RDINTCHGTY_CLOVERLEAF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4230].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].entry.ee_code = EEC_RDINTCHGTY_DIAMOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4231].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].entry.ee_code = EEC_RDINTCHGTY_FORK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4232].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].entry.ee_code = EEC_RDINTCHGTY_ROUNDABOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4233].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].entry.ee_code = EEC_RDINTCHGTY_STAGGERED_RAMPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4234].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].entry.ee_code = EEC_RDINTCHGTY_STANDARD_RAMPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4235].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].entry.ee_code = EEC_RDINTCHGTY_SYMMETRICAL_RAMPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4236].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].entry.ee_code = EEC_RDINTCHGTY_TRUMPET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4237].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].entry.ee_code = EEC_RDINTCHGTY_TURBAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4238].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].entry.ee_code = EEC_RDINTCHGTY_WYE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4239].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4240].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4241].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4242].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4243].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4244].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].entry.ee_code = EEC_ROCKFORMSTR_COLUMNAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4245].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].entry.ee_code = EEC_ROCKFORMSTR_NEEDLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4246].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].entry.ee_code = EEC_ROCKFORMSTR_PINNACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4247].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4248].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4249].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4250].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4251].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4252].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4253].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4254].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].entry.ee_code = EEC_OBJORDRANK_FIRST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4255].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].entry.ee_code = EEC_OBJORDRANK_SECOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4256].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].entry.ee_code = EEC_OBJORDRANK_THIRD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4257].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4258].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4259].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4260].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADIO_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4261].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].entry.ee_code = EEC_RADIOSTATY_CIRCULAR_MARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4262].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].entry.ee_code = EEC_RADIOSTATY_DIRECTIONAL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4263].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].entry.ee_code = EEC_RADIOSTATY_ROTATING_PATTERN_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4264].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].entry.ee_code = EEC_RADIOSTATY_CONSOL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4265].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].entry.ee_code = EEC_RADIOSTATY_RADIO_DIRECTION_FINDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4266].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].entry.ee_code = EEC_RADIOSTATY_COASTAL_PROVIDING_QTG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4267].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].entry.ee_code = EEC_RADIOSTATY_AERONAUTICAL_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4268].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADIO_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4269].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADIO_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4270].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADIO_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4271].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADIO_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4272].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].entry.information = "Deleted: \"Unknown\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].entry.information = "Deleted: \"Access Required\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].entry.information = "Deleted: \"Access Not Required\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].entry.information = "Deleted: \"Unpopulated\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4276].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].entry.information = "Deleted: \"Not Applicable\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4277].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].entry.information = "Deleted: \"Other\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4278].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4279].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].entry.ee_code = EEC_RAILPWRSRC_ELECTRIFIED_TRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4280].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].entry.ee_code = EEC_RAILPWRSRC_OVERHEAD_ELECTRIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4281].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].entry.ee_code = EEC_RAILPWRSRC_NON_ELECTRIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4282].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4283].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4284].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4285].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4286].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4287].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].entry.ee_code = EEC_RAILTY_CAR_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4288].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].entry.ee_code = EEC_RAILTY_MONORAIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4289].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].entry.ee_code = EEC_RAILTY_SUBWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4290].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].entry.ee_code = EEC_RAILTY_LOGGING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4291].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].entry.ee_code = EEC_RAILTY_MINIATURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4292].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].entry.ee_code = EEC_RAILTY_RAPID_TRANSIT_ROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4293].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].entry.ee_code = EEC_RAILTY_MARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4294].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].entry.ee_code = EEC_RAILTY_TRAMWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4295].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].entry.ee_code = EEC_RAILTY_INCLINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4296].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].entry.ee_code = EEC_RAILTY_MAIN_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].entry.ee_code = EEC_RAILTY_BRANCH_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4298].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].entry.ee_code = EEC_RAILTY_IN_ROAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4299].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4300].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4301].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4302].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4303].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4304].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].entry.ee_code = EEC_BRRAILTY_SPUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4305].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].entry.ee_code = EEC_BRRAILTY_SIDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].entry.ee_code = EEC_BRRAILTY_PASSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4308].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4309].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4310].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4311].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4312].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].entry.ee_code = EEC_MARRESCUESTATY_LIFEBOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4313].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].entry.ee_code = EEC_MARRESCUESTATY_ROCKET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4314].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].entry.ee_code = EEC_MARRESCUESTATY_LIFEBOAT_AND_ROCKET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4315].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].entry.ee_code = EEC_MARRESCUESTATY_SHIPWRECK_REFUGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4316].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].entry.ee_code = EEC_MARRESCUESTATY_INTERTIDAL_REFUGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4317].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].entry.ee_code = EEC_MARRESCUESTATY_MOORED_LIFEBOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4318].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].entry.ee_code = EEC_MARRESCUESTATY_EMERGENCY_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4319].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].entry.ee_code = EEC_MARRESCUESTATY_FIRST_AID_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4320].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4321].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4322].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4323].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4324].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4325].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].entry.ee_code = EEC_LDTRNSPRTESRF_HARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4326].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].entry.ee_code = EEC_LDTRNSPRTESRF_UNPAVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4327].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].entry.ee_code = EEC_LDTRNSPRTESRF_LOOSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4328].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].entry.ee_code = EEC_LDTRNSPRTESRF_CORDUROY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4329].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].entry.ee_code = EEC_LDTRNSPRTESRF_SOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4330].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].entry.ee_code = EEC_LDTRNSPRTESRF_NATURAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].entry.ee_code = EEC_LDTRNSPRTESRF_PERMANENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].entry.ee_code = EEC_LDTRNSPRTESRF_TEMPORARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4334].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4335].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4336].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].code.tag, "RST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4337].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4338].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].entry.ee_code = EEC_RAILTRKARR_SINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].entry.ee_code = EEC_RAILTRKARR_DOUBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].entry.ee_code = EEC_RAILTRKARR_MULTIPLE_ARRANGEMENTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].entry.ee_code = EEC_RAILTRKARR_JUXTAPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4342].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4343].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4344].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4345].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4346].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4347].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].entry.ee_code = EEC_RADRTRNSPNDTY_RAMARK_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4348].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].entry.ee_code = EEC_RADRTRNSPNDTY_RACON_TRANSPONDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4349].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].entry.ee_code = EEC_RADRTRNSPNDTY_LEADING_LINE_RACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4350].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4351].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4352].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4353].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4354].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4355].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].entry.ee_code = EEC_RTEWXTY_ALL_WEATHER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4356].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].entry.ee_code = EEC_RTEWXTY_LIMITED_ALL_WEATHER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4357].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].entry.ee_code = EEC_RTEWXTY_FAIR_WEATHER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4358].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4359].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4360].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4361].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4362].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RESERVOIR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4363].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].entry.ea_code = EAC_RESERVOIR_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].entry.ee_code = EEC_RESRVRTY_CONSTRUCTED_BASIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4364].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].entry.ea_code = EAC_RESERVOIR_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].entry.ee_code = EEC_RESRVRTY_DAM_IMPOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4365].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RESERVOIR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4366].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RESERVOIR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4367].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RESERVOIR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4368].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RESERVOIR_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4369].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4370].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].entry.ee_code = EEC_MARRTETY_TRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4371].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].entry.ee_code = EEC_MARRTETY_TRACK_NOT_DEEP_DRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4372].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].entry.ee_code = EEC_MARRTETY_TRACK_DEEP_DRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4373].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].entry.ee_code = EEC_MARRTETY_DEEP_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4374].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].entry.ee_code = EEC_MARRTETY_TRANSIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4375].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].entry.ee_code = EEC_MARRTETY_RADAR_GUIDED_TRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4376].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].entry.ee_code = EEC_MARRTETY_MEASURED_DISTANCE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4377].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].entry.ee_code = EEC_MARRTETY_SAFETY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].entry.ee_code = EEC_MARRTETY_TSS_TRAFFIC_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4379].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].entry.ee_code = EEC_MARRTETY_TSS_ROUNDABOUT_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4380].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].entry.ee_code = EEC_MARRTETY_TWO_WAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4381].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].entry.ee_code = EEC_MARRTETY_TSS_TRACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4382].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].entry.ee_code = EEC_MARRTETY_TRAFFIC_DIRECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4383].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].entry.ee_code = EEC_MARRTETY_PRIMARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].entry.ee_code = EEC_MARRTETY_SECONDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4385].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].entry.ee_code = EEC_MARRTETY_LIMITED_ACCESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4386].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].entry.ee_code = EEC_MARRTETY_Q;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4387].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].entry.ee_code = EEC_MARRTETY_RECOMMENDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4388].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].entry.ee_code = EEC_MARRTETY_TRAFFIC_LANE_PART;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4389].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].entry.ee_code = EEC_MARRTETY_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4390].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].entry.ee_code = EEC_MARRTETY_DEEP_WATER_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4391].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].entry.ee_code = EEC_MARRTETY_DEEP_WATER_PART;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4392].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4393].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4394].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4395].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4396].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4397].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].entry.ea_code = EAC_RUNWAY_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].entry.ee_code = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4398].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].entry.ea_code = EAC_RUNWAY_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].entry.ee_code = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4399].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4400].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4401].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4402].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4403].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4404].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].entry.ee_code = EEC_MARWARNSIGTY_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4405].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].entry.ee_code = EEC_MARWARNSIGTY_MARINE_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4406].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].entry.ee_code = EEC_MARWARNSIGTY_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4407].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].entry.ee_code = EEC_MARWARNSIGTY_MILITARY_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4408].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].entry.ee_code = EEC_MARWARNSIGTY_DISTRESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4409].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].entry.ee_code = EEC_MARWARNSIGTY_WEATHER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4410].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].entry.ee_code = EEC_MARWARNSIGTY_STORM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4411].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].entry.ee_code = EEC_MARWARNSIGTY_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4412].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].entry.ee_code = EEC_MARWARNSIGTY_TIME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4413].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].entry.ee_code = EEC_MARWARNSIGTY_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4414].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].entry.ee_code = EEC_MARWARNSIGTY_TIDAL_STREAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4415].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].entry.ee_code = EEC_MARWARNSIGTY_TIDE_GAUGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4416].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].entry.ee_code = EEC_MARWARNSIGTY_TIDE_SCALE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4417].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].entry.ee_code = EEC_MARWARNSIGTY_DIVING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4418].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].entry.ee_code = EEC_MARWARNSIGTY_WATER_LEVEL_GAUGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4419].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4420].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4421].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4422].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4423].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4424].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4425].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4426].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4427].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4428].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4429].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHELTER_BELT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4430].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4431].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].entry.ea_code = EAC_WATER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].entry.ee_code = EEC_WTRTY_ALKALINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4432].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4433].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4434].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].entry.ea_code = EAC_WATER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].entry.ee_code = EEC_WTRTY_MINERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4435].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4436].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4437].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].entry.ea_code = EAC_WATER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].entry.ee_code = EEC_WTRTY_POTABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4438].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].entry.ea_code = EAC_WATER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].entry.ee_code = EEC_WTRTY_SALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4439].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].entry.ea_code = EAC_WATER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].entry.ee_code = EEC_WTRTY_FRESH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4440].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4441].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4442].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4443].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4444].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].entry.information = "> 0,0 centimetre and <= 5,0 centimetre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4445].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].entry.information = "> 5,0 centimetre and <= 10,0 centimetre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4446].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].entry.information = "> 10,0 centimetre and <= 20,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4447].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].entry.information = "> 20,0 centimetres and <= 30,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4448].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].entry.information = "> 30,0 centimetres and <= 40,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4449].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].entry.information = "> 40,0 centimetres and <= 60,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 40.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4450].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].entry.information = "> 60,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4451].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4452].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4453].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4454].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4455].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].entry.information = "> 0,0 centimetre and <= 10,0 centimetre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4456].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].entry.information = "> 10,0 centimetre and <= 30,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4457].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].entry.information = "> 30,0 centimetres and <= 60,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4458].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].entry.information = "> 60,0 centimetres and <= 100,0 centmetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 60.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4459].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].entry.information = "> 100,0 centimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_CENTI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4460].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4461].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4462].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4463].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4464].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].entry.information = "<= 0,25 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4465].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].entry.information = "> 0,25 metre and <= 0,50 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.25;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 0.50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4466].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].entry.information = "> 0,50 metre and <= 1,50 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4467].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].entry.information = "> 1,50 metres and <= 2,50 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4468].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].entry.information = "> 2,50 metres and <= 5,00 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 2.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4469].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].entry.information = "> 5,00 metres and <= 10,00 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4470].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].entry.information = "> 10,00 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4471].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4472].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4473].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4474].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4475].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].entry.ee_code = EEC_WTRBDFLRMRPH_NONE_IDENTIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4476].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].entry.ee_code = EEC_WTRBDFLRMRPH_GAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4477].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].entry.ee_code = EEC_WTRBDFLRMRPH_BANK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4478].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].entry.ee_code = EEC_WTRBDFLRMRPH_DEEP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4479].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].entry.ee_code = EEC_WTRBDFLRMRPH_MARINE_BAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4480].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].entry.ee_code = EEC_WTRBDFLRMRPH_BENCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4481].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].entry.ee_code = EEC_WTRBDFLRMRPH_BASIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4482].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].entry.information = "\"Watt\" is an undefined term.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4483].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].entry.ee_code = EEC_WTRBDFLRMRPH_TRENCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4484].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].entry.ee_code = EEC_WTRBDFLRMRPH_MUD_FLAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4485].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].entry.ee_code = EEC_WTRBDFLRMRPH_REEF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4486].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].entry.ee_code = EEC_WTRBDFLRMRPH_LEDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4487].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].entry.ee_code = EEC_WTRBDFLRMRPH_CANYON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4488].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].entry.ee_code = EEC_WTRBDFLRMRPH_NARROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4489].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].entry.ee_code = EEC_WTRBDFLRMRPH_SHOAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4490].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].entry.ee_code = EEC_WTRBDFLRMRPH_KNOLL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4491].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].entry.ee_code = EEC_WTRBDFLRMRPH_RIDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4492].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].entry.ee_code = EEC_WTRBDFLRMRPH_SEAMOUNT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4493].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].entry.ee_code = EEC_WTRBDFLRMRPH_PINNACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4494].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].entry.ee_code = EEC_WTRBDFLRMRPH_ABYSSAL_PLAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4495].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].entry.ee_code = EEC_WTRBDFLRMRPH_PLATEAU;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4496].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].entry.ee_code = EEC_WTRBDFLRMRPH_SPUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4497].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].entry.ee_code = EEC_WTRBDFLRMRPH_SHELF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4498].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].entry.ee_code = EEC_WTRBDFLRMRPH_TROUGH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4499].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].entry.ee_code = EEC_WTRBDFLRMRPH_SADDLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4500].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].entry.ee_code = EEC_WTRBDFLRMRPH_ABYSSAL_HILLS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4501].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].entry.ee_code = EEC_WTRBDFLRMRPH_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4502].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].entry.ee_code = EEC_WTRBDFLRMRPH_ARCHIPELAGIC_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].entry.ee_code = EEC_WTRBDFLRMRPH_BORDERLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].entry.ee_code = EEC_WTRBDFLRMRPH_CNTNTL_MARGIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].entry.ee_code = EEC_WTRBDFLRMRPH_CNTNTL_RISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].entry.ee_code = EEC_WTRBDFLRMRPH_ESCARPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4507].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].entry.ee_code = EEC_WTRBDFLRMRPH_FAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4508].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].entry.ee_code = EEC_WTRBDFLRMRPH_FRACTURE_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4509].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].entry.ee_code = EEC_WTRBDFLRMRPH_GAP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4510].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].entry.ee_code = EEC_WTRBDFLRMRPH_GUYOT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4511].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].entry.ee_code = EEC_WTRBDFLRMRPH_HILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].entry.ee_code = EEC_WTRBDFLRMRPH_HOLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].entry.ee_code = EEC_WTRBDFLRMRPH_LEVEE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4514].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].entry.ee_code = EEC_WTRBDFLRMRPH_MEDIAN_VALLEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4515].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].entry.ee_code = EEC_WTRBDFLRMRPH_MOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4516].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].entry.ee_code = EEC_WTRBDFLRMRPH_MOUNTAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4517].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].entry.ee_code = EEC_WTRBDFLRMRPH_PEAK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4518].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].entry.ee_code = EEC_WTRBDFLRMRPH_PROVINCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4519].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].entry.ee_code = EEC_WTRBDFLRMRPH_RISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4520].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].entry.ee_code = EEC_WTRBDFLRMRPH_SEA_CHANNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4521].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].entry.ee_code = EEC_WTRBDFLRMRPH_SEAMOUNT_CHAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].entry.ee_code = EEC_WTRBDFLRMRPH_SHELF_EDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].entry.ee_code = EEC_WTRBDFLRMRPH_SILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].entry.ee_code = EEC_WTRBDFLRMRPH_SLOPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].entry.ee_code = EEC_WTRBDFLRMRPH_TERRACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4526].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].entry.ee_code = EEC_WTRBDFLRMRPH_VALLEY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4527].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].entry.information = "Deleted: \"Canal\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].entry.information = "Deleted: \"River\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].entry.information = "Deleted: \"Lake\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4530].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].entry.information = "Deleted: \"Reach\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4531].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].entry.ee_code = EEC_WTRBDFLRMRPH_LOWLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4532].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].entry.ee_code = EEC_WTRBDFLRMRPH_CANYON_LAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4533].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].entry.ee_code = EEC_WTRBDFLRMRPH_CRATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4534].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4535].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4536].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4537].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4538].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECURITY_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4539].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].entry.ea_code = EAC_SECURITY_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].entry.ee_code = EEC_SECULEV_US_TOP_SECRET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4540].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].entry.ea_code = EAC_SECURITY_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].entry.ee_code = EEC_SECULEV_US_SECRET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4541].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].entry.ea_code = EAC_SECURITY_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].entry.ee_code = EEC_SECULEV_US_CONFIDENTIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4542].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].entry.ea_code = EAC_SECURITY_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].entry.ee_code = EEC_SECULEV_US_RESTRICTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4543].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].entry.ea_code = EAC_SECURITY_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].entry.ee_code = EEC_SECULEV_US_UNCLASSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4544].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECURITY_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4545].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECURITY_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4546].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECURITY_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4547].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECURITY_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4548].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4549].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].entry.ee_code = EEC_STORFACTY_SOFT_STANDING_ONLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4550].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].entry.ee_code = EEC_STORFACTY_HARD_STANDING_ONLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4551].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].entry.ee_code = EEC_STORFACTY_DUTCH_BARN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4552].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].entry.ee_code = EEC_STORFACTY_WAREHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4553].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].entry.ee_code = EEC_STORFACTY_SPECIALIZED_WAREHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4554].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].entry.ee_code = EEC_STORFACTY_GRAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4555].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].entry.ee_code = EEC_STORFACTY_ORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4556].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].entry.ee_code = EEC_STORFACTY_LIQUID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4557].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].entry.ee_code = EEC_STORFACTY_EXPLOSIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4558].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].entry.ee_code = EEC_STORFACTY_AMMUNITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4559].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].entry.ee_code = EEC_STORFACTY_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4560].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].entry.ee_code = EEC_STORFACTY_SALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4561].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].entry.ee_code = EEC_STORFACTY_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4562].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].entry.ee_code = EEC_STORFACTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4563].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].entry.ee_code = EEC_STORFACTY_EXPLOSIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Explosives)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4564].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].entry.ee_code = EEC_STORFACTY_FOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4565].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].entry.ee_code = EEC_STORFACTY_DIESEL_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4566].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].entry.ee_code = EEC_STORFACTY_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4567].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].entry.ee_code = EEC_STORFACTY_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4568].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].entry.ee_code = EEC_STORFACTY_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4569].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4570].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].enum_val = 995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].entry.ee_code = EEC_STORFACTY_NONE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4571].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4572].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4573].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4574].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].entry.ee_code = EEC_WTRBDFLROBJTY_UNKNOWN_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4575].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4576].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].entry.ee_code = EEC_WTRBDFLROBJTY_FISH_HAVEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4577].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].entry.ee_code = EEC_WTRBDFLROBJTY_WELL_HEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4578].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].entry.ee_code = EEC_WTRBDFLROBJTY_SUBMERGED_PRODUCTION_PLATFORM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4579].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].entry.ee_code = EEC_WTRBDFLROBJTY_WRECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4580].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].entry.ee_code = EEC_WTRBDFLROBJTY_SHOALING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4581].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].entry.ee_code = EEC_WTRBDFLROBJTY_REDUCED_DEPTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4582].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].entry.ee_code = EEC_WTRBDFLROBJTY_UNEXPLODED_MUNITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4583].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].entry.ee_code = EEC_WTRBDFLROBJTY_UNSPECIFIED_NON_SUB_CONTACT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4584].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].entry.ee_code = EEC_WTRBDFLROBJTY_PINNACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4585].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4586].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4587].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4588].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4589].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4590].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].entry.ee_code = EEC_SHORLNPHYSIOG_HILLOCKS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4591].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].entry.ee_code = EEC_SHORLNPHYSIOG_FLAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4592].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].entry.ee_code = EEC_SHORLNPHYSIOG_SANDY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4593].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].entry.ee_code = EEC_SHORLNPHYSIOG_STONY_SHINGLY_MIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4594].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].entry.ee_code = EEC_SHORLNPHYSIOG_ARTIFICIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4595].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].entry.ee_code = EEC_SHORLNPHYSIOG_STEEP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4596].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].entry.ee_code = EEC_SHORLNPHYSIOG_GLACIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4597].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].entry.ee_code = EEC_SHORLNPHYSIOG_ICE_COAST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4598].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].entry.ee_code = EEC_SHORLNPHYSIOG_STEEP_COAST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4599].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4600].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4601].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4602].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4603].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4604].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].entry.ee_code = EEC_MARBEACSHAP_POLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4605].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].entry.ee_code = EEC_MARBEACSHAP_WITHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4606].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].entry.ee_code = EEC_MARBEACSHAP_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4607].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].entry.ee_code = EEC_MARBEACSHAP_LATTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4608].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].entry.ee_code = EEC_MARBEACSHAP_STRUCTURAL_PILE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4609].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].entry.ee_code = EEC_MARBEACSHAP_CAIRN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4610].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].entry.ee_code = EEC_MARBEACSHAP_BUOYANT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4611].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].entry.ee_code = EEC_MARBEACSHAP_SQUARE_DAYMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4612].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].entry.ee_code = EEC_MARBEACSHAP_TRIANGLE_DAYMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4613].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].entry.ee_code = EEC_MARBEACSHAP_RECTANGLE_DAYMARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4614].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].entry.ee_code = EEC_MARBEACSHAP_ARTICULATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4615].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4616].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4617].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4618].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4619].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4620].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].entry.ee_code = EEC_FROZSRFCVRTY_SNOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4621].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].entry.ee_code = EEC_FROZSRFCVRTY_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4622].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4623].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4624].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4625].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4626].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4627].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].entry.ee_code = EEC_MARTRAFSIGTY_PORT_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4628].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].entry.ee_code = EEC_MARTRAFSIGTY_PORT_ENTER_DEPART;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4629].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].entry.ee_code = EEC_MARTRAFSIGTY_INTERNATIONAL_PORT_TRAFFIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4630].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].entry.ee_code = EEC_MARTRAFSIGTY_BERTHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4631].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].entry.ee_code = EEC_MARTRAFSIGTY_DOCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4632].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].entry.ee_code = EEC_MARTRAFSIGTY_LOCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4633].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].entry.ee_code = EEC_MARTRAFSIGTY_FLOOD_BARRAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4634].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].entry.ee_code = EEC_MARTRAFSIGTY_BRIDGE_PASSAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4635].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].entry.ee_code = EEC_MARTRAFSIGTY_DREDGING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4636].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].entry.ee_code = EEC_MARTRAFSIGTY_TRAFFIC_CONTROL_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4637].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4638].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4639].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4640].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4641].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4642].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].entry.information = "<= 30%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4643].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].entry.information = "> 30% and <= 45%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 45.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4644].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].entry.information = "> 45% and <= 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 45.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4645].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].entry.information = "> 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4646].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4647].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4648].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4649].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4650].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].entry.information = "<= 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4651].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].entry.information = "> 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4652].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4653].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4654].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4655].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4656].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].entry.ee_code = EEC_SHORLNTY_MANGROVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4657].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].entry.ee_code = EEC_SHORLNTY_MARSHY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4658].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].entry.ee_code = EEC_SHORLNTY_ROCKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4659].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].entry.ee_code = EEC_SHORLNTY_RUBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4660].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].entry.ee_code = EEC_SHORLNTY_SANDY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4661].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].entry.ee_code = EEC_SHORLNTY_STONY_SHINGLY_MIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4662].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4663].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].entry.ee_code = EEC_SHORLNTY_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4664].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].entry.ee_code = EEC_SHORLNTY_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4665].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4666].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4667].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4668].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SHORELINE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4669].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4670].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].entry.information = "< 0,5 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.lt_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4671].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].entry.information = ">= 0,5 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.ge_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4672].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4673].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4674].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4675].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFICIAL_DEPTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4676].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4677].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].entry.ee_code = EEC_SRFMATTY_AIRCRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4678].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].entry.ee_code = EEC_SRFMATTY_ALUMINUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4679].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].entry.ee_code = EEC_SRFMATTY_AMMUNITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4680].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].entry.ee_code = EEC_SRFMATTY_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4681].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].entry.ee_code = EEC_SRFMATTY_ASPHALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4682].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].entry.ee_code = EEC_SRFMATTY_BASALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4683].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].entry.ee_code = EEC_SRFMATTY_BEDROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4684].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].entry.ee_code = EEC_SRFMATTY_BOULDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4685].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].entry.ee_code = EEC_SRFMATTY_BRICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4686].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].entry.ee_code = EEC_SRFMATTY_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4687].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].entry.ee_code = EEC_SRFMATTY_CEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4688].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].entry.ee_code = EEC_SRFMATTY_CHALK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4689].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].entry.ee_code = EEC_SRFMATTY_CHEMICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4690].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].entry.ee_code = EEC_SRFMATTY_CINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4691].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].entry.ee_code = EEC_SRFMATTY_CIRRIPEDIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4692].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].entry.ee_code = EEC_SRFMATTY_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4693].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].entry.ee_code = EEC_SRFMATTY_COAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4694].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].entry.ee_code = EEC_SRFMATTY_COBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4695].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].entry.ee_code = EEC_SRFMATTY_COKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4696].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].entry.ee_code = EEC_SRFMATTY_COMPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4697].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].entry.ee_code = EEC_SRFMATTY_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4698].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].entry.ee_code = EEC_SRFMATTY_CONGLOMERATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4699].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].entry.ee_code = EEC_SRFMATTY_COPPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4700].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].entry.ee_code = EEC_SRFMATTY_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4701].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].entry.ee_code = EEC_SRFMATTY_CORAL_HEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4702].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].entry.ee_code = EEC_SRFMATTY_DESALINATED_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4703].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].entry.ee_code = EEC_SRFMATTY_DIAMOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4704].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].entry.ee_code = EEC_SRFMATTY_DIATOMACEOUS_EARTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4705].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].entry.ee_code = EEC_SRFMATTY_DOLOMITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4706].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].entry.ee_code = EEC_SRFMATTY_EARTHEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4707].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].entry.ee_code = EEC_SRFMATTY_ELECTRIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4708].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].entry.ee_code = EEC_SRFMATTY_ERODED_LAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4709].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].entry.ee_code = EEC_SRFMATTY_EXPLOSIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4710].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].entry.ee_code = EEC_SRFMATTY_FLYSCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4711].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].entry.ee_code = EEC_SRFMATTY_FOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4712].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].entry.ee_code = EEC_SRFMATTY_FORAMINIFERA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4713].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].entry.ee_code = EEC_SRFMATTY_FUCUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4714].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].entry.ee_code = EEC_SRFMATTY_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4715].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].entry.ee_code = EEC_SRFMATTY_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4716].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].entry.ee_code = EEC_SRFMATTY_GLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4717].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].entry.ee_code = EEC_SRFMATTY_GLOBIGERINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4718].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].entry.ee_code = EEC_SRFMATTY_GOLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4719].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].entry.ee_code = EEC_SRFMATTY_GRANITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4720].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4721].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].entry.ee_code = EEC_SRFMATTY_THATCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4722].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].entry.ee_code = EEC_SRFMATTY_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4723].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].entry.ee_code = EEC_SRFMATTY_GREENSTONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4724].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].entry.ee_code = EEC_SRFMATTY_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4725].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].entry.ee_code = EEC_SRFMATTY_GROUND_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4726].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].entry.ee_code = EEC_SRFMATTY_PEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4727].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].entry.ee_code = EEC_SRFMATTY_IRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4728].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].entry.ee_code = EEC_SRFMATTY_LAVA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4729].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4730].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].entry.ee_code = EEC_SRFMATTY_LEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4731].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].entry.ee_code = EEC_SRFMATTY_LOESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4732].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].entry.ee_code = EEC_SRFMATTY_LUMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4733].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].entry.ee_code = EEC_SRFMATTY_MACADAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4734].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].entry.ee_code = EEC_SRFMATTY_MADREPORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4735].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].entry.ee_code = EEC_SRFMATTY_MANGANESE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4736].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].entry.ee_code = EEC_SRFMATTY_MARBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4737].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].entry.ee_code = EEC_SRFMATTY_MARL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4738].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].entry.ee_code = EEC_SRFMATTY_MASONRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4739].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].entry.ee_code = EEC_SRFMATTY_MATTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4740].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].entry.ee_code = EEC_SRFMATTY_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4741].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].entry.ee_code = EEC_SRFMATTY_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4742].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].entry.ee_code = EEC_SRFMATTY_MUSSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4743].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].entry.ee_code = EEC_SRFMATTY_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4744].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].entry.ee_code = EEC_SRFMATTY_OIL_BLISTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4745].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].entry.ee_code = EEC_SRFMATTY_OOZE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4746].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].entry.ee_code = EEC_SRFMATTY_OYSTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4747].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].entry.ee_code = EEC_SRFMATTY_PAPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4748].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].entry.ee_code = EEC_SRFMATTY_PART_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4749].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].entry.ee_code = EEC_SRFMATTY_PEBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4750].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].entry.ee_code = EEC_SRFMATTY_PLASTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4751].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].entry.ee_code = EEC_SRFMATTY_POLYZOA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4752].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].entry.ee_code = EEC_SRFMATTY_PORPHYRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4753].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].entry.ee_code = EEC_SRFMATTY_PRESTRESSED_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4754].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].entry.ee_code = EEC_SRFMATTY_PTEROPOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4755].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].entry.ee_code = EEC_SRFMATTY_PUMICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4756].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].entry.ee_code = EEC_SRFMATTY_QUARTZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4757].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].entry.ee_code = EEC_SRFMATTY_RADIOLARIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4758].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].entry.ee_code = EEC_SRFMATTY_RADIOACTIVE_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4759].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].entry.ee_code = EEC_SRFMATTY_REINFORCED_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4760].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].entry.ee_code = EEC_SRFMATTY_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4761].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].entry.ee_code = EEC_SRFMATTY_RUBBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4762].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].entry.ee_code = EEC_SRFMATTY_RUBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4763].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].entry.ee_code = EEC_SRFMATTY_SALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4764].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].entry.ee_code = EEC_SRFMATTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4765].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].entry.ee_code = EEC_SRFMATTY_SANDSTONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4766].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].entry.ee_code = EEC_SRFMATTY_SCHIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4767].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].entry.ee_code = EEC_SRFMATTY_SPOIL_OR_TAILINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4768].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].entry.ee_code = EEC_SRFMATTY_SCORIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4769].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].entry.ee_code = EEC_SRFMATTY_SEA_TANGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4770].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].entry.ee_code = EEC_SRFMATTY_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4771].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].entry.ee_code = EEC_SRFMATTY_SEWAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4772].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].entry.ee_code = EEC_SRFMATTY_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4773].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4774].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].entry.ee_code = EEC_SRFMATTY_SHINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4775].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].entry.ee_code = EEC_SRFMATTY_SILT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4776].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].entry.ee_code = EEC_SRFMATTY_SILVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4777].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].entry.ee_code = EEC_SRFMATTY_SLAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4778].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].entry.ee_code = EEC_SRFMATTY_SLUDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4779].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].entry.ee_code = EEC_SRFMATTY_FROZEN_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4780].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].entry.ee_code = EEC_SRFMATTY_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4781].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].entry.ee_code = EEC_SRFMATTY_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4782].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].entry.ee_code = EEC_SRFMATTY_SPONGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4783].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].entry.ee_code = EEC_SRFMATTY_STEEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4784].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].entry.ee_code = EEC_SRFMATTY_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4785].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].entry.ee_code = EEC_SRFMATTY_SUGAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4786].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].entry.ee_code = EEC_SRFMATTY_TRAVERTINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4787].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].entry.ee_code = EEC_SRFMATTY_TUFA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4788].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].entry.ee_code = EEC_SRFMATTY_URANIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4789].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].entry.ee_code = EEC_SRFMATTY_VEGETATION_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4790].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].entry.ee_code = EEC_SRFMATTY_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4791].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].entry.ee_code = EEC_SRFMATTY_VOLCANIC_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4792].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].entry.ee_code = EEC_SRFMATTY_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4793].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].entry.ee_code = EEC_SRFMATTY_WOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4794].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].entry.ee_code = EEC_SRFMATTY_ZINC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4795].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].entry.ee_code = EEC_SRFMATTY_DISTORTED_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4796].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].entry.ee_code = EEC_SRFMATTY_SAND_AND_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4797].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].entry.ee_code = EEC_SRFMATTY_RIPRAP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4798].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].entry.ee_code = EEC_SRFMATTY_EVAPORITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4799].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].entry.ee_code = EEC_SRFMATTY_SAND_AND_BOULDERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4800].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].entry.ee_code = EEC_SRFMATTY_SAND_AND_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4801].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].entry.ee_code = EEC_SRFMATTY_KARST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4802].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].enum_val = 198;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].entry.ee_code = EEC_SRFMATTY_KELP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4803].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].enum_val = 199;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].entry.ee_code = EEC_SRFMATTY_SAND_WAVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4804].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].enum_val = 200;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].entry.ee_code = EEC_SRFMATTY_NON_TREED_VEGETATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4805].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].enum_val = 201;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].entry.ee_code = EEC_SRFMATTY_TREES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4806].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].enum_val = 202;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].entry.ee_code = EEC_SRFMATTY_VEGETATED_WETLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4807].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].enum_val = 203;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].entry.ee_code = EEC_SRFMATTY_HERBACEOUS_VEGETATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4808].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].enum_val = 204;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].entry.ee_code = EEC_SRFMATTY_TREED_VEGETATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4809].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].enum_val = 205;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].entry.ee_code = EEC_SRFMATTY_PAINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4810].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].enum_val = 250;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].entry.ee_code = EEC_SRFMATTY_COMPOSITE_ge_50_PCT_PERMANENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4811].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].enum_val = 251;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].entry.ee_code = EEC_SRFMATTY_PEM_MIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4812].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].enum_val = 252;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].entry.ee_code = EEC_SRFMATTY_PERMANENT_HARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4813].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].enum_val = 253;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].entry.ee_code = EEC_SRFMATTY_BITUMINOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4814].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].enum_val = 254;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].entry.ee_code = EEC_SRFMATTY_COMPOSITE_lt_50_PCT_PERMANENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4815].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].enum_val = 255;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].entry.ee_code = EEC_SRFMATTY_GRADED_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4816].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].enum_val = 256;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].entry.ee_code = EEC_SRFMATTY_GRASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4817].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].enum_val = 257;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].entry.ee_code = EEC_SRFMATTY_ICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4818].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].enum_val = 258;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].entry.ee_code = EEC_SRFMATTY_SNOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4819].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].enum_val = 259;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].entry.ee_code = EEC_SRFMATTY_MACADAM_CRUSHED_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4820].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].enum_val = 260;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].entry.ee_code = EEC_SRFMATTY_MEMBRANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4821].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].enum_val = 261;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].entry.ee_code = EEC_SRFMATTY_MIXED_IN_PLACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4822].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].enum_val = 262;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].entry.ee_code = EEC_SRFMATTY_LATERITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4823].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].enum_val = 263;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].entry.ee_code = EEC_SRFMATTY_SAND_GRADED_ROLLED_OILED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4824].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4825].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4826].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4827].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4828].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4829].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].entry.ee_code = EEC_SNDGINF_DRYING_HEIGHTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4830].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].entry.ee_code = EEC_SNDGINF_NO_BOTTOM_FOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4831].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4832].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4833].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4834].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4835].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].entry.ee_code = EEC_SNDGINF_OUT_OF_POSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4836].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].entry.ee_code = EEC_SNDGINF_UNRELIABLE_US;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4837].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].entry.ee_code = EEC_SNDGINF_IN_POSITION_US;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4838].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].entry.ee_code = EEC_SNDGINF_NOT_ROUTINELY_MAINTAINED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4839].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].entry.ee_code = EEC_SNDGINF_DEPTH_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4840].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].entry.ee_code = EEC_SNDGINF_IN_POSITION_IHO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4841].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].entry.ee_code = EEC_SNDGINF_UNRELIABLE_IHO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4842].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].entry.ee_code = EEC_SNDGINF_ADEQUATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4843].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].entry.ee_code = EEC_SNDGINF_NO_BOTTOM_FOUND_AT_DEPTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4844].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].entry.ee_code = EEC_SNDGINF_DEPTH_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4845].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].entry.ee_code = EEC_SNDGINF_DOUBTFUL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4846].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].entry.ee_code = EEC_SNDGINF_UNRELIABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4847].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].entry.ee_code = EEC_SNDGINF_LEAST_DEPTH_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4848].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].entry.ee_code = EEC_SNDGINF_LEAST_DEPTH_UNKNOWN_BUT_SAFE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4849].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].entry.ee_code = EEC_SNDGINF_REPORTED_NOT_SURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4850].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].entry.ee_code = EEC_SNDGINF_REPORTED_NOT_CONFIRMED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4851].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].entry.ee_code = EEC_SNDGINF_MAINTAINED_DEPTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4852].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4853].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4854].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4855].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].code.tag, "SND", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_INFORMATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4856].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HAZARD_SEVERITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4857].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].entry.ea_code = EAC_HAZARD_SEVERITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].entry.ee_code = EEC_HAZSEV_DANGEROUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4858].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].entry.ea_code = EAC_HAZARD_SEVERITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].entry.ee_code = EEC_HAZSEV_NON_DANGEROUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4859].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].entry.ea_code = EAC_HAZARD_SEVERITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].entry.ee_code = EEC_HAZSEV_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4860].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].entry.ea_code = EAC_HAZARD_SEVERITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].entry.ee_code = EEC_HAZSEV_NON_DANGEROUS_SURFACE_NAVIGATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4861].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HAZARD_SEVERITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4862].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HAZARD_SEVERITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4863].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HAZARD_SEVERITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4864].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HAZARD_SEVERITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4865].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_EXPOSITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4866].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].entry.ea_code = EAC_SOUNDING_EXPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].entry.ee_code = EEC_SNDGEXPOS_WITHIN_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4867].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].entry.ea_code = EAC_SOUNDING_EXPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].entry.ee_code = EEC_SNDGEXPOS_SHALLOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4868].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].entry.ea_code = EAC_SOUNDING_EXPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].entry.ee_code = EEC_SNDGEXPOS_DEEPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4869].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_EXPOSITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4870].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_EXPOSITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4871].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_EXPOSITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4872].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_EXPOSITION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4873].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4874].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].entry.ee_code = EEC_SPOTELEVTY_NON_TERRAIN_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4875].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].entry.ee_code = EEC_SPOTELEVTY_OUT_OF_POSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4876].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].entry.ee_code = EEC_SPOTELEVTY_SUMMIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4877].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4878].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4879].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4880].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4881].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4882].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].entry.information = "<= 3%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4883].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].entry.information = "> 3% and <= 10%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4884].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].entry.information = "> 10% and <= 15%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4885].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].entry.information = "> 15% and <= 20%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4886].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].entry.information = "> 20% and <= 30%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4887].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].entry.information = "> 30% and <= 45%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4888].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].entry.information = "> 45% and <= 60%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4889].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].entry.information = "> 60% and <= 85%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4890].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].entry.information = "> 85%.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4891].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].entry.information = "0% to > 85%: Culturally or naturally dissected land.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4892].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4893].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4894].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4895].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4896].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].entry.information = "<= 30%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4897].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].entry.information = "> 30% and <= 45%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 45.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4898].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].entry.information = "> 45% and <= 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 45.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4899].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].entry.information = "> 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4900].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4901].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4902].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4903].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4904].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].entry.information = "<= 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4905].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].entry.information = "> 60%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4906].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4907].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4908].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4909].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4910].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].entry.ee_code = EEC_TERMRPHTY_NO_SURFACE_ROUGHNESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4911].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].entry.ee_code = EEC_TERMRPHTY_HIGH_LANDSLIDE_POTENTIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4912].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].entry.ee_code = EEC_TERMRPHTY_UNCOHESIVE_SURFACE_FLAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4913].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].entry.ee_code = EEC_TERMRPHTY_ROUGH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4914].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].entry.ee_code = EEC_TERMRPHTY_ANGULAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4915].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].entry.ee_code = EEC_TERMRPHTY_ROUNDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4916].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].entry.ee_code = EEC_TERMRPHTY_MANY_COBBLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4917].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].entry.ee_code = EEC_TERMRPHTY_STONY_TRACTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4918].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].entry.ee_code = EEC_TERMRPHTY_STONY_ROCKS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4919].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].entry.ee_code = EEC_TERMRPHTY_STONY_SCATTERED_BOULDERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4920].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].entry.ee_code = EEC_TERMRPHTY_STONY_BOULDERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4921].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].entry.ee_code = EEC_TERMRPHTY_MANY_BOULDERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4922].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].entry.ee_code = EEC_TERMRPHTY_MANY_ROCK_OUTCROPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4923].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].entry.ee_code = EEC_TERMRPHTY_SCATTERED_BOULDERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4924].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].entry.ee_code = EEC_TERMRPHTY_TALUS_SLOPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4925].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].entry.ee_code = EEC_TERMRPHTY_BOULDER_FIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4926].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].entry.ee_code = EEC_TERMRPHTY_HIGHLY_FRACTURED_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4927].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].entry.ee_code = EEC_TERMRPHTY_WEATHERED_LAVA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4928].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].entry.ee_code = EEC_TERMRPHTY_UNWEATHERED_LAVA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4929].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].entry.ee_code = EEC_TERMRPHTY_STONY_ROCKCROPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4930].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].entry.ee_code = EEC_TERMRPHTY_IRREGULAR_SURFACE_DEEP_FRACTURES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4931].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].entry.ee_code = EEC_TERMRPHTY_RUGGED_ROCKY_OUTCROPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4932].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].entry.ee_code = EEC_TERMRPHTY_RUGGED_BEDROCK_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4933].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].entry.ee_code = EEC_TERMRPHTY_SAND_DUNES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4934].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].entry.ee_code = EEC_TERMRPHTY_SAND_DUNES_LOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4935].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].entry.ee_code = EEC_TERMRPHTY_SAND_DUNES_HIGH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4936].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].entry.ee_code = EEC_TERMRPHTY_ACTIVE_SAND_DUNES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4937].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].entry.ee_code = EEC_TERMRPHTY_STABILIZED_SAND_DUNES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4938].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].entry.ee_code = EEC_TERMRPHTY_HIGHLY_DISTORTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4939].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].entry.ee_code = EEC_TERMRPHTY_STONY_GULLIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4940].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].entry.ee_code = EEC_TERMRPHTY_MOD_DISSECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4941].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].entry.ee_code = EEC_TERMRPHTY_MOD_DISSECTED_ROCK_OUTCROPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4942].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].entry.ee_code = EEC_TERMRPHTY_DISSECTED_FLOODPLAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4943].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].entry.ee_code = EEC_TERMRPHTY_HIGHLY_DISSECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4944].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].entry.ee_code = EEC_TERMRPHTY_DEEP_EROSIONAL_GULLIES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4945].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].entry.ee_code = EEC_TERMRPHTY_STEEP_RUGGED_DISSECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4946].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].entry.ee_code = EEC_TERMRPHTY_KARST_SINKHOLES_SOLUTION_VALLEYS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4947].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].entry.ee_code = EEC_TERMRPHTY_KARST_NUMEROUS_SINKHOLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4948].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].entry.ee_code = EEC_TERMRPHTY_KARST_LARGE_HILLS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4949].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].entry.ee_code = EEC_TERMRPHTY_KARST_LOW_MOUNDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4950].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].entry.ee_code = EEC_TERMRPHTY_WADI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4951].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].entry.ee_code = EEC_TERMRPHTY_PLAYA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4952].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].entry.ee_code = EEC_TERMRPHTY_MANY_MEANDER_SCARS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4953].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].entry.ee_code = EEC_TERMRPHTY_SOLIFLUCTION_LOBES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4954].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].entry.ee_code = EEC_TERMRPHTY_HUMMOCKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4955].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].entry.ee_code = EEC_TERMRPHTY_FROST_POLYGONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4956].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].entry.ee_code = EEC_TERMRPHTY_CONTAINING_SABKHAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4957].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].entry.ee_code = EEC_TERMRPHTY_MANY_SMALL_LAKES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4958].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].entry.ee_code = EEC_TERMRPHTY_MANY_CREVASSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4959].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].entry.ee_code = EEC_TERMRPHTY_MANY_TERRACES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4960].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].entry.ee_code = EEC_TERMRPHTY_QUARRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4961].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].entry.ee_code = EEC_TERMRPHTY_STRIP_MINES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4962].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].entry.ee_code = EEC_TERMRPHTY_QUARRY_OR_GRAVEL_PIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4963].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].entry.ee_code = EEC_TERMRPHTY_QUARRY_OR_SAND_PIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4964].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].entry.ee_code = EEC_TERMRPHTY_WASTE_PILES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4965].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].entry.ee_code = EEC_TERMRPHTY_SALT_EVAPORATORS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4966].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].entry.ee_code = EEC_TERMRPHTY_MANY_DYKES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4967].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].entry.ee_code = EEC_TERMRPHTY_MANY_DYKED_FIELDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4968].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].entry.ee_code = EEC_TERMRPHTY_MANY_FENCES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4969].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].entry.ee_code = EEC_TERMRPHTY_MANY_STONE_WALLS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4970].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].entry.ee_code = EEC_TERMRPHTY_MANY_CANALS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4971].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].entry.ee_code = EEC_TERMRPHTY_MANY_TERRACED_FIELDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4972].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].entry.ee_code = EEC_TERMRPHTY_PARALLEL_SOIL_MOUNDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4973].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].entry.ee_code = EEC_TERMRPHTY_MANY_HEDGEROWS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4974].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4975].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4976].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4977].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4978].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4979].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].entry.ee_code = EEC_STRSHAP_BARREL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4980].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].entry.ee_code = EEC_STRSHAP_BLIMP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4981].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].entry.ee_code = EEC_STRSHAP_VESSEL_HULL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4982].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].entry.ee_code = EEC_STRSHAP_BULLET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4983].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4984].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].entry.ee_code = EEC_STRSHAP_PEAKED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4985].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].entry.ee_code = EEC_STRSHAP_CYLINDER_UPRIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4986].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4987].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].entry.ee_code = EEC_STRSHAP_PILLAR_OR_SPINDLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4988].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4989].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].entry.ee_code = EEC_STRSHAP_PYRAMID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4990].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4991].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4992].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].entry.ee_code = EEC_STRSHAP_SOLID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4993].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].entry.ee_code = EEC_STRSHAP_SPAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4994].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].entry.ee_code = EEC_STRSHAP_SPHERICAL_HEMISPHERICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4995].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].entry.ee_code = EEC_STRSHAP_TRUSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4996].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].entry.ee_code = EEC_STRSHAP_WITH_RADOME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4997].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4998].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].entry.ee_code = EEC_STRSHAP_ARTIFICIAL_MOUNTAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[4999].entry.entry_list = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt5 */

